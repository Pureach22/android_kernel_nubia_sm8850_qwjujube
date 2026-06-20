__int64 __fastcall drv_cmd_set_ccx_roam_scan_channels(__int64 a1, __int64 a2, const char *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  size_t v14; // x0
  const char *v15; // x0
  int v16; // w8
  char v17; // t1
  const char *v18; // x2
  const char *v19; // x22
  __int64 v20; // x21
  __int64 v21; // x23
  char *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 result; // x0
  unsigned int v49; // [xsp+4h] [xbp-1BCh] BYREF
  unsigned int s[100]; // [xsp+8h] [xbp-1B8h] BYREF
  _BYTE v51[32]; // [xsp+198h] [xbp-28h] BYREF
  __int64 v52; // [xsp+1B8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( a2 )
  {
    v49 = 0;
    memset(v51, 0, sizeof(v51));
    v14 = strlen(a3);
    v15 = (const char *)strnchr(a3, v14, 32);
    if ( !v15 )
      goto LABEL_23;
    v16 = *(unsigned __int8 *)v15;
    if ( v16 != 32 )
      goto LABEL_23;
    while ( (unsigned __int8)v16 == 32 )
    {
      v17 = *++v15;
      LOBYTE(v16) = v17;
    }
    if ( (_BYTE)v16
      && (v19 = v15, sscanf(v15, "%31s ", v51) == 1)
      && (kstrtoint(v51, 10, &v49) & 0x80000000) == 0
      && (v20 = v49, v49 - 101 >= 0xFFFFFF9C) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Number of channels are: %d",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "hdd_parse_channellist",
        v49);
      v21 = 0;
      do
      {
        v22 = strchr(v19, 32);
        if ( !v22 )
          goto LABEL_22;
        while ( *v22 == 32 )
          ++v22;
        if ( !*v22 )
        {
LABEL_22:
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Mismatch in ch cnt: %d and num of ch: %d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "hdd_parse_channellist",
            (unsigned int)v20,
            (unsigned int)v21);
          goto LABEL_23;
        }
        v19 = v22;
        if ( sscanf(v22, "%31s ", v51) != 1 || (kstrtoint(v51, 10, &v49) & 0x80000000) != 0 || v49 - 174 < 0xFFFFFF53 )
          goto LABEL_23;
        v31 = wlan_reg_legacy_chan_to_freq(*(_QWORD *)(a2 + 8), v49, v6, v7, v8, v9, v10, v11, v12, v13);
        s[v21] = v31;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Channel %d added to preferred channel list",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "hdd_parse_channellist",
          v31);
        ++v21;
      }
      while ( v21 != v20 );
      if ( (unsigned __int8)v20 >= 0x65u )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: number of channels (%d) supported exceeded max (%d)",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "drv_cmd_set_ccx_roam_scan_channels",
          (unsigned int)v20,
          100);
        goto LABEL_25;
      }
      if ( (((__int64 (__fastcall *)(_QWORD, unsigned int *, _QWORD))sme_validate_channel_list)(
              *(_QWORD *)(a2 + 16),
              s,
              (unsigned int)v20)
          & 1) != 0 )
      {
        result = ucfg_cm_set_ese_roam_scan_channel_list(*(_QWORD *)(a2 + 8), *(unsigned __int8 *)(a1 + 8), s, v20);
        if ( !(_DWORD)result )
          goto LABEL_26;
        v18 = "%s: Failed to update channel list information";
      }
      else
      {
        v18 = "%s: List contains invalid channel(s)";
      }
    }
    else
    {
LABEL_23:
      v18 = "%s: Failed to parse channel list information";
    }
  }
  else
  {
    v18 = "%s: invalid hdd ctx";
  }
  qdf_trace_msg(0x33u, 2u, v18, v6, v7, v8, v9, v10, v11, v12, v13, "drv_cmd_set_ccx_roam_scan_channels");
LABEL_25:
  result = 4294967274LL;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
