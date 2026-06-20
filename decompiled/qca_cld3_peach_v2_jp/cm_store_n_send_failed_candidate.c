__int64 __fastcall cm_store_n_send_failed_candidate(_QWORD *a1, unsigned int a2)
{
  __int64 result; // x0
  _QWORD v5[21]; // [xsp+8h] [xbp-A8h] BYREF

  v5[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v5, 0, 160);
  cm_fill_failure_resp_from_cm_id((__int64)a1, (__int64)v5, a2, 15);
  cm_store_first_candidate_rsp((__int64)a1, a2, (__int64)v5);
  result = mlme_cm_osif_failed_candidate_ind(*a1, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
