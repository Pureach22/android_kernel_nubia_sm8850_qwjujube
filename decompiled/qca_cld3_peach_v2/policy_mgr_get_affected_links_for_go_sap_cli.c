__int64 __fastcall policy_mgr_get_affected_links_for_go_sap_cli(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        unsigned int *a4,
        unsigned __int8 a5,
        unsigned __int8 *a6,
        unsigned int *a7)
{
  unsigned int v7; // w25
  __int64 v11; // x28
  __int64 v12; // x19
  unsigned __int8 *v13; // x26
  unsigned int *v14; // x27
  char v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x23
  double v35; // d0
  char v36; // w0
  char v37; // w20
  unsigned int *v38; // x8
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v55; // [xsp+8h] [xbp-28h]
  __int64 v56; // [xsp+10h] [xbp-20h]

  v7 = 0;
  if ( a2 >= 2u && a5 )
  {
    v11 = 0;
    v7 = 0;
    v55 = a5;
    v56 = a2;
    do
    {
      v12 = v55;
      v13 = a6;
      v14 = a7;
      do
      {
        if ( a4[v11] == *v14 )
          goto LABEL_7;
        v15 = policy_mgr_check_2ghz_only_sap_affected_link(a1, *v13, *v14, a2, a4);
        v24 = *v13;
        if ( (v15 & 1) != 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: 2G only SAP vdev %d ch freq %d is not SCC with any MLO STA link",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "policy_mgr_get_affected_links_for_go_sap_cli",
            *v13,
            *v14);
LABEL_11:
          ++v7;
          goto LABEL_7;
        }
        v25 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *v13, 24);
        if ( !v25 )
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: invalid vdev for id %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "policy_mgr_is_vdev_high_tput_or_low_latency",
            v24);
          goto LABEL_7;
        }
        v34 = v25;
        v35 = wlan_is_vdev_traffic_ll_ht();
        v37 = v36;
        wlan_objmgr_vdev_release_ref(v34, 0x18u, v38, v35, v39, v40, v41, v42, v43, v44, v45);
        if ( (v37 & 1) != 0 && (policy_mgr_are_2_freq_on_same_mac(a1, a4[v11], *v14) & 1) != 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: ml sta vdev %d (freq %d) and p2p/sap vdev %d (freq %d) are MCC",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "policy_mgr_get_affected_links_for_go_sap_cli",
            *(unsigned __int8 *)(a3 + v11),
            a4[v11],
            *v13,
            *v14);
          goto LABEL_11;
        }
LABEL_7:
        --v12;
        ++v14;
        ++v13;
      }
      while ( v12 );
      ++v11;
    }
    while ( v11 != v56 );
  }
  return v7;
}
