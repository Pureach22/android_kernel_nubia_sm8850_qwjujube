__int64 __fastcall hdd_thermal_register_callbacks(__int64 *a1)
{
  __int64 v1; // x0
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v3[0] = hdd_notify_thermal_throttle_handler;
  result = ucfg_fwol_thermal_register_callbacks(v1, v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
