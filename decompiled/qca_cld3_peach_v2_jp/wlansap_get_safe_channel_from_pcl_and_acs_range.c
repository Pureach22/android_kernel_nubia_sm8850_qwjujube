__int64 __fastcall wlansap_get_safe_channel_from_pcl_and_acs_range(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _QWORD *context; // x0
  _QWORD *v13; // x21
  const char *v14; // x2
  __int64 result; // x0
  const char *v16; // x2
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // [xsp+8h] [xbp-278h] BYREF
  _DWORD s[102]; // [xsp+10h] [xbp-270h] BYREF
  __int64 v37; // [xsp+1A8h] [xbp-D8h]
  __int64 v38; // [xsp+1B0h] [xbp-D0h]
  __int64 v39; // [xsp+1B8h] [xbp-C8h]
  __int64 v40; // [xsp+1C0h] [xbp-C0h]
  __int64 v41; // [xsp+1C8h] [xbp-B8h]
  __int64 v42; // [xsp+1D0h] [xbp-B0h]
  __int64 v43; // [xsp+1D8h] [xbp-A8h]
  __int64 v44; // [xsp+1E0h] [xbp-A0h]
  __int64 v45; // [xsp+1E8h] [xbp-98h]
  __int64 v46; // [xsp+1F0h] [xbp-90h]
  __int64 v47; // [xsp+1F8h] [xbp-88h]
  __int64 v48; // [xsp+200h] [xbp-80h]
  __int64 v49; // [xsp+208h] [xbp-78h]
  _QWORD v50[14]; // [xsp+210h] [xbp-70h] BYREF

  v50[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  memset(v50, 0, 104);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  memset(s, 0, sizeof(s));
  v35 = 0;
  if ( !a1 )
  {
    v16 = "%s: NULL parameter";
    goto LABEL_10;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v4, v5, v6, v7, v8, v9, v10, v11);
  if ( !context )
  {
    v16 = "%s: Invalid MAC context";
    goto LABEL_10;
  }
  v13 = context;
  if ( (unsigned int)policy_mgr_get_connection_count(context[2694]) != 1 )
  {
    v17 = policy_mgr_qdf_opmode_to_pm_con_mode(v13[2694], 1, *(_BYTE *)(a1 + 12), v4, v5, v6, v7, v8, v9, v10, v11);
    if ( !(unsigned int)policy_mgr_get_pcl_for_scc_in_same_mode(
                          v13[2694],
                          v17,
                          (__int64)s,
                          (__int64)&v35,
                          (__int64)v50 + 2,
                          0x66u,
                          *(unsigned __int8 *)(a1 + 12)) )
    {
      if ( !(_DWORD)v35 )
      {
        v14 = "%s: pcl length is zero!";
        goto LABEL_5;
      }
      hdd_remove_vlp_depriority_channels(v13[2695], (__int64)s, (unsigned int *)&v35, v4, v5, v6, v7, v8, v9, v10, v11);
      v26 = wlansap_filter_ch_based_acs(a1, (__int64)s, &v35, v18, v19, v20, v21, v22, v23, v24, v25);
      if ( !v26 )
      {
        if ( !(unsigned int)wlansap_select_chan_with_best_bandwidth(a1, s, (unsigned int)v35, (char *)&v35 + 4, a2) )
        {
          result = HIDWORD(v35);
          goto LABEL_12;
        }
        if ( (_DWORD)v35 )
        {
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: select %d from valid ch freq list",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            "wlansap_get_safe_channel_from_pcl_and_acs_range",
            s[0]);
          result = s[0];
          goto LABEL_12;
        }
        v14 = "%s: no safe channel from PCL found in ACS range";
        goto LABEL_5;
      }
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: failed to filter ch from acs %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wlansap_get_safe_channel_from_pcl_and_acs_range",
        v26);
LABEL_11:
      result = 0;
      goto LABEL_12;
    }
    v16 = "%s: Get PCL failed";
LABEL_10:
    qdf_trace_msg(0x39u, 2u, v16, v4, v5, v6, v7, v8, v9, v10, v11, "wlansap_get_safe_channel_from_pcl_and_acs_range");
    goto LABEL_11;
  }
  v14 = "%s: only SAP present return best channel from ACS list";
LABEL_5:
  qdf_trace_msg(0x39u, 8u, v14, v4, v5, v6, v7, v8, v9, v10, v11, "wlansap_get_safe_channel_from_pcl_and_acs_range");
  result = wlansap_get_safe_channel(a1, a2);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
