__int64 __fastcall wma_update_thermal_mitigation_to_fw(__int64 *a1, unsigned __int8 a2)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a2 >= 6u )
    __break(0x5512u);
  result = wmi_unified_thermal_mitigation_param_cmd_send(*a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
