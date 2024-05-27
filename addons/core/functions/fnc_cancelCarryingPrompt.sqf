#include "..\script_component.hpp"
/*
 * Author: Blue
 * Give interactions to stop being carried
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Unit Carrier <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorTarget] call ACM_core_fnc_cancelCarryingPrompt;
 *
 * Public: No
 */

params ["_unit", "_carrier"];

["", "Cancel Carrying", ""] call ACEFUNC(interaction,showMouseHint);
GVAR(Carrier) = _carrier;

_unit setVariable [QGVAR(CancelCarryingActionID), [0xF1, [false, false, false], {
    [QGVAR(cancelCarryLocal), [GVAR(Carrier), (GVAR(Carrier) getVariable QACEGVAR(dragging,carriedObject))], GVAR(Carrier)] call CBA_fnc_targetEvent;
}, "keyup", "", false, 0] call CBA_fnc_addKeyHandler];

[{
    params ["_carrier", "_unit"];

    dialog || _carrier getVariable [QACEGVAR(dragging,carriedObject), objNull] isEqualTo objNull
}, {
    params ["_carrier", "_unit"];

    if (_carrier getVariable [QACEGVAR(dragging,carriedObject), objNull] isNotEqualTo objNull) then {
        [QGVAR(cancelCarryLocal), [_carrier, (_carrier getVariable QACEGVAR(dragging,carriedObject))], _carrier] call CBA_fnc_targetEvent;
    };

    [] call ACEFUNC(interaction,hideMouseHint);
    GVAR(Carrier) = nil;
    [_unit getVariable QGVAR(CancelCarryingActionID), "keyup"] call CBA_fnc_removeKeyHandler;
    _unit setVariable [QGVAR(CancelCarryingActionID), nil];
}, [_carrier, _unit], 3600, {}] call CBA_fnc_waitUntilAndExecute;
