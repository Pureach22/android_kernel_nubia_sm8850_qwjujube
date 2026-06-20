__int64 __fastcall wlansap_get_safe_channel_from_pcl_for_sap(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _QWORD *context; // x0
  _QWORD *v11; // x22
  __int64 v12; // x21
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  __int64 result; // x0
  const char *v24; // x2
  int v25; // [xsp+Ch] [xbp-274h] BYREF
  _DWORD s[102]; // [xsp+10h] [xbp-270h] BYREF
  __int64 v27; // [xsp+1A8h] [xbp-D8h]
  __int64 v28; // [xsp+1B0h] [xbp-D0h]
  __int64 v29; // [xsp+1B8h] [xbp-C8h]
  __int64 v30; // [xsp+1C0h] [xbp-C0h]
  __int64 v31; // [xsp+1C8h] [xbp-B8h]
  __int64 v32; // [xsp+1D0h] [xbp-B0h]
  __int64 v33; // [xsp+1D8h] [xbp-A8h]
  __int64 v34; // [xsp+1E0h] [xbp-A0h]
  __int64 v35; // [xsp+1E8h] [xbp-98h]
  __int64 v36; // [xsp+1F0h] [xbp-90h]
  __int64 v37; // [xsp+1F8h] [xbp-88h]
  __int64 v38; // [xsp+200h] [xbp-80h]
  __int64 v39; // [xsp+208h] [xbp-78h]
  _BYTE v40[104]; // [xsp+210h] [xbp-70h] BYREF
  __int64 v41; // [xsp+278h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  memset(v40, 0, sizeof(v40));
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  memset(s, 0, sizeof(s));
  v25 = 0;
  if ( !a1 )
  {
    v22 = "%s: NULL parameter";
    goto LABEL_9;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v2, v3, v4, v5, v6, v7, v8, v9);
  if ( !context )
  {
    v22 = "%s: Invalid MAC context";
    goto LABEL_9;
  }
  v11 = context;
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 152LL);
  if ( !v12 )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: NULL pdev",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlansap_get_safe_channel_from_pcl_for_sap");
  v13 = policy_mgr_qdf_opmode_to_pm_con_mode(v11[2694], 1, *(_BYTE *)(a1 + 12), v2, v3, v4, v5, v6, v7, v8, v9);
  if ( (unsigned int)policy_mgr_get_pcl_for_vdev_id(
                       v11[2694],
                       v13,
                       (__int64)s,
                       &v25,
                       (__int64)&v40[2],
                       0x66u,
                       *(unsigned __int8 *)(a1 + 12),
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19,
                       v20,
                       v21) )
  {
    v22 = "%s: Get PCL failed";
LABEL_9:
    qdf_trace_msg(0x39u, 2u, v22, v2, v3, v4, v5, v6, v7, v8, v9, "wlansap_get_safe_channel_from_pcl_for_sap");
    goto LABEL_10;
  }
  if ( v25 )
  {
    if ( (unsigned int)policy_mgr_filter_passive_ch(v12, (__int64)s, &v25, v2, v3, v4, v5, v6, v7, v8, v9) )
    {
      v22 = "%s: failed to filter passive channels";
      goto LABEL_9;
    }
    if ( v25 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: select %d from valid ch freq list",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "wlansap_get_safe_channel_from_pcl_for_sap",
        s[0]);
      result = s[0];
      goto LABEL_11;
    }
    v24 = "%s: no active channels found in PCL";
  }
  else
  {
    v24 = "%s: pcl length is zero!";
  }
  qdf_trace_msg(0x39u, 8u, v24, v2, v3, v4, v5, v6, v7, v8, v9, "wlansap_get_safe_channel_from_pcl_for_sap");
  if ( v13 != 6 )
  {
    result = wlansap_get_2g_first_safe_chan_freq(a1);
    goto LABEL_11;
  }
LABEL_10:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
