__int64 __fastcall osif_twt_setup_conc_allowed(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  char v4; // w8

  v2 = *(unsigned __int8 *)(a2 + 168);
  if ( (policy_mgr_current_concurrency_is_mcc(a1) & 1) != 0 )
    v4 = 0;
  else
    v4 = policy_mgr_is_scc_with_this_vdev_id(a1, v2) ^ 1;
  return v4 & 1;
}
