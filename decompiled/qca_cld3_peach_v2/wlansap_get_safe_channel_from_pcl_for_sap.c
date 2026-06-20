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
  const char *v14; // x2
  __int64 result; // x0
  const char *v16; // x2
  int v17; // [xsp+Ch] [xbp-274h] BYREF
  _DWORD s[102]; // [xsp+10h] [xbp-270h] BYREF
  __int64 v19; // [xsp+1A8h] [xbp-D8h]
  __int64 v20; // [xsp+1B0h] [xbp-D0h]
  __int64 v21; // [xsp+1B8h] [xbp-C8h]
  __int64 v22; // [xsp+1C0h] [xbp-C0h]
  __int64 v23; // [xsp+1C8h] [xbp-B8h]
  __int64 v24; // [xsp+1D0h] [xbp-B0h]
  __int64 v25; // [xsp+1D8h] [xbp-A8h]
  __int64 v26; // [xsp+1E0h] [xbp-A0h]
  __int64 v27; // [xsp+1E8h] [xbp-98h]
  __int64 v28; // [xsp+1F0h] [xbp-90h]
  __int64 v29; // [xsp+1F8h] [xbp-88h]
  __int64 v30; // [xsp+200h] [xbp-80h]
  __int64 v31; // [xsp+208h] [xbp-78h]
  _BYTE v32[104]; // [xsp+210h] [xbp-70h] BYREF
  __int64 v33; // [xsp+278h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  memset(v32, 0, sizeof(v32));
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  memset(s, 0, sizeof(s));
  v17 = 0;
  if ( !a1 )
  {
    v14 = "%s: NULL parameter";
    goto LABEL_9;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", v2, v3, v4, v5, v6, v7, v8, v9);
  if ( !context )
  {
    v14 = "%s: Invalid MAC context";
    goto LABEL_9;
  }
  v11 = context;
  v12 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 216LL);
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
  v13 = policy_mgr_qdf_opmode_to_pm_con_mode(v11[2703], 1, *(_BYTE *)(a1 + 12), v2, v3, v4, v5, v6, v7, v8, v9);
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _DWORD *, int *, _BYTE *, __int64, _QWORD))policy_mgr_get_pcl_for_vdev_id)(
                       v11[2703],
                       v13,
                       s,
                       &v17,
                       &v32[2],
                       102,
                       *(unsigned __int8 *)(a1 + 12)) )
  {
    v14 = "%s: Get PCL failed";
LABEL_9:
    qdf_trace_msg(0x39u, 2u, v14, v2, v3, v4, v5, v6, v7, v8, v9, "wlansap_get_safe_channel_from_pcl_for_sap");
    goto LABEL_10;
  }
  if ( v17 )
  {
    if ( (unsigned int)policy_mgr_filter_passive_ch(v12, (__int64)s, &v17, v2, v3, v4, v5, v6, v7, v8, v9) )
    {
      v14 = "%s: failed to filter passive channels";
      goto LABEL_9;
    }
    if ( v17 )
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
    v16 = "%s: no active channels found in PCL";
  }
  else
  {
    v16 = "%s: pcl length is zero!";
  }
  qdf_trace_msg(0x39u, 8u, v16, v2, v3, v4, v5, v6, v7, v8, v9, "wlansap_get_safe_channel_from_pcl_for_sap");
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
