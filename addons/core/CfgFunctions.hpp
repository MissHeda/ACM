class CfgFunctions {
    class overwrite_medical_vitals {
        tag = "ace_medical_vitals";
        class ace_medical_vitals {
            class handleUnitVitals { // Core
                file = QPATHTOF(overrides\fnc_handleUnitVitals.sqf);
            };
            class updateHeartRate { // Circulation
                file = QPATHTOF(overrides\fnc_updateHeartRate.sqf);
            };
            class updateOxygen { // Breathing
                file = QPATHTOF(overrides\fnc_updateOxygen.sqf);
            };
        };
    };
    class overwrite_medical_status {
        tag = "ace_medical_status";
        class ace_medical_status {
            class getBloodPressure { // Circulation
                file = QPATHTOF(overrides\fnc_getBloodPressure.sqf);
            };
            class getBloodVolumeChange { // Circulation
                file = QPATHTOF(overrides\fnc_getBloodVolumeChange.sqf);
            };
            class hasStableVitals { // Add oxygen saturation as vital
                file = QPATHTOF(overrides\fnc_hasStableVitals.sqf);
            };
            class getBloodLoss { // Circulation
                file = QPATHTOF(overrides\fnc_getBloodLoss.sqf);
            };
        };
    };
    class overwrite_medical_treatment {
        tag = "ace_medical_treatment";
        class ace_medical_treatment {
            class treatment { // Add fixes and patient animations
                file = QPATHTOF(overrides\fnc_treatment.sqf);
            };
            class ivBagLocal { // Circulation
                file = QPATHTOF(overrides\fnc_ivBagLocal.sqf);
            };
            class ivBag { // Circulation
                file = QPATHTOF(overrides\fnc_ivBag.sqf);
            };
            class medication { // Fix magazine names in triage card
                file = QPATHTOF(overrides\fnc_medication.sqf);
            };
            class checkPulseLocal { // CPR rate
                file = QPATHTOF(overrides\fnc_checkPulseLocal.sqf);
            };
        };
    };
    class overwrite_medical_damage {
        tag = "ace_medical_damage";
        class ace_medical_damage {
            class woundsHandlerBase { // Modify wounds, coagulation functionality, chest injury
                file = QPATHTOF(overrides\fnc_woundsHandlerBase.sqf);
            };
        };
    };
    class overwrite_medical_feedback {
        tag = "ace_medical_feedback";
        class ace_medical_feedback {
            class handleEffects { // Oxygen Effect
                file = QPATHTOF(overrides\fnc_handleEffects.sqf);
            };
            class effectHeartBeat { // Lower high HR threshold
                file = QPATHTOF(overrides\fnc_effectHeartBeat.sqf);
            };
            class initEffects { // Oxygen Effect
                file = QPATHTOF(overrides\fnc_initEffects.sqf);
            };
        };
    };
    class overwrite_medical_statemachine {
        tag = "ace_medical_statemachine";
        class ace_medical_statemachine {
            /*class handleStateCardiacArrest {
                file = QPATHTOF(overrides\fnc_handleStateCardiacArrest.sqf);
            };*/
            class enteredStateCardiacArrest { // Disable cardiac arrest timer
                file = QPATHTOF(overrides\fnc_enteredStateCardiacArrest.sqf);
            };
            class conditionCardiacArrestTimer { // Disable cardiac arrest timer
                file = QPATHTOF(overrides\fnc_conditionCardiacArrestTimer.sqf);
            };
            class handleStateUnconscious { // KnockOut state
                file = QPATHTOF(overrides\fnc_handleStateUnconscious.sqf);
            };
            /*class leftStateCardiacArrest {
                file = QPATHTOF(overrides\fnc_leftStateCardiacArrest.sqf);
            };*/
            /*class enteredStateFatalInjury {
                file = QPATHTOF(overrides\fnc_enteredStateFatalInjury.sqf);
            };*/
            /*class handleStateInjured {
                file = QPATHTOF(overrides\fnc_handleStateInjured.sqf);
            };*/
        };
    };
    class overwrite_ace_dogtags {
        tag = "ace_dogtags";
        class ace_dogtags {
            class getDogtagData { // Blood type display
                file = QPATHTOF(overrides\fnc_getDogtagData.sqf);
            };
        };
    };
    /*class overwrite_CBA_statemachine { // TODO statemachine fuckery
        tag = "CBA_statemachine";
        class CBA_statemachine {
            class manualTransition {
                file = QPATHTOF(overrides\fnc_manualTransition.sqf);
            };
            class createFromConfig {
                file = QPATHTOF(overrides\fnc_createFromConfig.sqf);
            };
        };
    };*/
};