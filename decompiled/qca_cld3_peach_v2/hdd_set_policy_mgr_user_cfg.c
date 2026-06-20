__int64 __fastcall hdd_set_policy_mgr_user_cfg(__int64 *a1)
{
  unsigned int v2; // w21
  _BYTE *v3; // x0
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v2 = 2;
  v3 = (_BYTE *)_qdf_mem_malloc(2u, "hdd_set_policy_mgr_user_cfg", 781);
  if ( v3 )
  {
    v4 = (__int64)v3;
    if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*a1, v3) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to get vht_enable_mimo",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_set_policy_mgr_user_cfg");
    *(_BYTE *)(v4 + 1) = cds_is_sub_20_mhz_enabled(v5, v6, v7, v8, v9, v10, v11, v12);
    v2 = policy_mgr_set_user_cfg(*a1, (_WORD *)v4);
    _qdf_mem_free(v4);
  }
  return v2;
}
