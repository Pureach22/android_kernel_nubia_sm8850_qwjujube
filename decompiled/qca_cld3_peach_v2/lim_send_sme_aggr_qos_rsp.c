__int64 __fastcall lim_send_sme_aggr_qos_rsp(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 result; // x0
  _QWORD v5[7]; // [xsp+8h] [xbp-38h] BYREF

  v5[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[1] = a2;
  memset(&v5[2], 0, 32);
  v5[0] = 5173;
  qdf_trace(53, 6u, a3, 5173);
  result = sys_process_mmh_msg(a1, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
