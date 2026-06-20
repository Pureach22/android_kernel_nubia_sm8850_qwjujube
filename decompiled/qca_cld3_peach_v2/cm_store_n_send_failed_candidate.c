__int64 __fastcall cm_store_n_send_failed_candidate(_QWORD *a1, unsigned int a2)
{
  __int64 result; // x0
  _BYTE s[336]; // [xsp+8h] [xbp-158h] BYREF
  __int64 v6; // [xsp+158h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  cm_fill_failure_resp_from_cm_id((__int64)a1, (__int64)s, a2, 15);
  cm_store_first_candidate_rsp((__int64)a1, a2, (__int64)s);
  result = mlme_cm_osif_failed_candidate_ind(*a1, s);
  _ReadStatusReg(SP_EL0);
  return result;
}
