__int64 __fastcall ipa3_uc_mhi_response_hdlr(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d responseOp=%d\n", "ipa3_uc_mhi_response_hdlr", 490, *(unsigned __int8 *)(a1 + 12));
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d responseOp=%d\n", "ipa3_uc_mhi_response_hdlr", 490, *(unsigned __int8 *)(a1 + 12));
  }
  if ( *(unsigned __int8 *)(a1 + 12) != *(unsigned __int8 *)ipa3_uc_mhi_ctx
    || *(_DWORD *)(a1 + 16) != *(_DWORD *)(ipa3_uc_mhi_ctx + 4) )
  {
    return 4294967274LL;
  }
  *a2 = 0;
  return 0;
}
