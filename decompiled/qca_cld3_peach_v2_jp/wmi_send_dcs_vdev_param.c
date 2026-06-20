__int64 __fastcall wmi_send_dcs_vdev_param(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 result; // x0
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  int v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v7 = 0;
  qdf_mem_set(&v7, 0xCu, 0);
  v7 = a2 | 0xC200000000LL;
  v8 = a3;
  result = wmi_unified_vdev_set_param_send(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
