#include "..\script_component.hpp"
/*
 * Author: Blue
 * Handle coagulation
 *
 * Arguments:
 * 0: Target <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call AMS_damage_fnc_handleCoagulationPFH;
 *
 * Public: No
 */

params ["_patient"];

if (_patient getVariable [QGVAR(Coagulation_PFH), -1] != -1 || !(IS_BLEEDING(_patient))) exitWith {}; // TODO add setting

_patient setVariable [QGVAR(Coagulation_InitTime), CBA_missionTime];

private _id = [{
    params ["_args", "_idPFH"];
    _args params ["_patient"];

    private _plateletCount = _patient getVariable [QEGVAR(circulation,Platelet_Count), 3];

    if (!(alive _patient) || ((_patient setVariable [QGVAR(Coagulation_InitTime), -1]) + 120 < CBA_missionTime && _plateletCount < 0.5)) exitWith {
        _patient setVariable [QGVAR(Coagulation_PFH), -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
    
    private _exit = true;

    if (GET_HEART_RATE(_patient) < 30 || _plateletCount < 0.5) exitWith {};

    private _maximumWoundSeverity = ceil (_plateletCount / 2);

    //private _txaCount = [_patient, "TXA"] call ACEFUNC(medical_status,getMedicationCount);

    {
        private _openWounds = GET_OPEN_WOUNDS(_patient);
        private _openWoundsOnPart = _openWounds getOrDefault [_x, []];

        if (_openWoundsOnPart isEqualTo [] || [_patient, _x] call ACEFUNC(medical_treatment,hasTourniquetAppliedTo)) then {
            continue;
        };
        
        private _woundIndex = _openWoundsOnPart findIf {(_x select 1) > 0 && (_x select 2) > 0 && (((_x select 0) % 10) + 1) <= _maximumWoundSeverity};

        if (_woundIndex != -1) exitWith {
            [_patient, _x, 1, _maximumWoundSeverity] call FUNC(clotWoundsOnBodyPart);
            _exit = false;
        };
    } forEach ALL_BODY_PARTS_PRIORITY;

    if (_exit) exitWith {
        _patient setVariable [QGVAR(Coagulation_PFH), -1];
        [_idPFH] call CBA_fnc_removePerFrameHandler;
    };
}, 6, [_patient]] call CBA_fnc_addPerFrameHandler;

_patient setVariable [QGVAR(Coagulation_PFH), _id];