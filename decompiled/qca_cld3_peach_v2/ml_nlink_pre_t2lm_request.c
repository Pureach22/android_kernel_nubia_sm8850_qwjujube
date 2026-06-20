__int64 __fastcall ml_nlink_pre_t2lm_request(__int64 a1, unsigned int a2, unsigned __int16 a3)
{
  __int64 result; // x0
  _QWORD v7[4]; // [xsp+0h] [xbp-20h] BYREF

  v7[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v7, 0, 24);
  qdf_mem_set(v7, 0x18u, 0);
  LODWORD(v7[0]) = a3;
  result = ml_nlink_conn_change_notify(a1, a2, 0x1Bu, (__int64)v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
