__int64 __fastcall target_if_ll_sap_twt_session_params(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (target_if_ll_sap_is_twt_event_type_query_rsp() & 1) == 0 )
    return 4;
  target_if_ll_sap_continue_csa_after_tsf_rsp(a1, a4);
  return 0;
}
