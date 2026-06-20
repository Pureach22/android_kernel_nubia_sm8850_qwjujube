__int64 __fastcall wlan_hdd_pre_cac_conditional_freq_switch_ind(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v13; // x0
  __int64 link_info_from_vdev; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0

  v10 = *(_QWORD *)(a1 + 152);
  if ( v10 )
    v13 = *(_QWORD *)(v10 + 80);
  else
    v13 = 0;
  link_info_from_vdev = wlan_hdd_get_link_info_from_vdev(a3, a4, a5, a6, a7, a8, a9, a10, v13, *(_BYTE *)(a1 + 104));
  if ( !link_info_from_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid vdev",
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             "wlan_hdd_pre_cac_conditional_freq_switch_ind");
  v23 = *(_QWORD *)link_info_from_vdev;
  if ( (a2 & 1) != 0 )
  {
    *(_BYTE *)(link_info_from_vdev + 256) = 0;
    v24 = link_info_from_vdev;
    ucfg_ipa_set_dfs_cac_tx(*(_QWORD *)(*(_QWORD *)(v23 + 24) + 8LL), 0);
    result = ucfg_dp_set_dfs_cac_tx(a1, *(_BYTE *)(v24 + 256), v25, v26, v27, v28, v29, v30, v31, v32);
    *(_BYTE *)(*(_QWORD *)(v23 + 24) + 912LL) = 2;
  }
  else
  {
    *(_BYTE *)(*(_QWORD *)(v23 + 24) + 912LL) = 0;
    return ucfg_pre_cac_get_freq(a1);
  }
  return result;
}
