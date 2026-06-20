__int64 __fastcall wlan_hdd_ll_lt_sap_get_csa_timestamp(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v6; // x0

  v3 = *(_QWORD *)(a2 + 152);
  if ( v3 )
    v6 = *(_QWORD *)(v3 + 80);
  else
    v6 = 0;
  if ( !policy_mgr_is_vdev_ll_lt_sap(v6, *(unsigned __int8 *)(a2 + 104)) )
    return 4294967274LL;
  ucfg_ll_lt_sap_get_target_tsf(a2, a3);
  return 0;
}
