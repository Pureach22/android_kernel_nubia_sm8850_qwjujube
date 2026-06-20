__int64 __fastcall hdd_config_latency_level(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  __int64 *v5; // x20
  __int64 result; // x0
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w4
  unsigned int v17; // w21
  __int64 v18; // x20
  unsigned int v19; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int latency_host_flags; // w22
  unsigned int v29; // w23
  unsigned int sender; // w22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x5
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+0h] [xbp-10h] BYREF
  __int64 v58; // [xsp+8h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1;
  LODWORD(v57) = 0;
  v5 = *(__int64 **)(v4 + 24);
  if ( (unsigned int)_hdd_validate_adapter(v4, "hdd_config_latency_level") )
  {
    result = 4294967274LL;
    goto LABEL_13;
  }
  v7 = *v5;
  BYTE4(v57) = 0;
  if ( (unsigned int)ucfg_mlme_get_latency_enable(v7, (_BYTE *)&v57 + 4)
    || BYTE4(v57) != 1
    || (sme_is_feature_supported_by_fw(31) & 1) == 0 )
  {
    result = 4294966772LL;
    goto LABEL_13;
  }
  v16 = *(unsigned __int16 *)(a2 + 4);
  v17 = v16 - 1;
  if ( (unsigned __int16)(v16 - 1) >= 4u )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid value %u",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_config_latency_level",
      v57,
      v58);
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( *(_BYTE *)(v4 + 52102) != 1 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: set legacy latency level: %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_config_latency_level",
      v57,
      v58);
    v19 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD))sme_set_wlm_latency_level)(
            v5[2],
            *(unsigned __int8 *)(a1 + 8),
            v17,
            0,
            0);
    if ( v19 )
    {
      latency_host_flags = v19;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: set latency level failed, %u",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_config_latency_level",
        v19);
LABEL_45:
      result = qdf_status_to_os_return(latency_host_flags);
      goto LABEL_13;
    }
    *(_WORD *)(v4 + 52098) = v17;
LABEL_42:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: adapter->latency_level:%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_config_latency_level",
      (unsigned __int16)v17);
    latency_host_flags = ucfg_mlme_get_latency_host_flags(*v5, *(_BYTE *)(v4 + 52098), &v57);
    if ( latency_host_flags )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to get latency host flags",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "hdd_config_latency_level");
    else
      hdd_set_wlm_host_latency_level((__int64)v5, v4, v57, v49, v50, v51, v52, v53, v54, v55, v56);
    goto LABEL_45;
  }
  if ( *(_BYTE *)(v4 + 52192) != 1 )
  {
    v29 = v16;
    sender = cfg80211_vendor_cmd_get_sender(v5[3]);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: port_id: %u, latency_level: %d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "hdd_config_latency_level",
      sender,
      v29,
      v57,
      v58);
    if ( *(_BYTE *)(v4 + 52112) == 1 && *(_DWORD *)(v4 + 52108) == sender && (*(_BYTE *)(v4 + 52116) & 1) != 0 )
    {
      v47 = 0;
LABEL_38:
      *(_WORD *)(v4 + 52100) = v17;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Cache level: %d at [%d] for port_id: %u",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "hdd_update_cache_latency_level",
        (unsigned __int16)v17,
        v47,
        sender);
      result = 0;
      goto LABEL_13;
    }
    if ( *(_BYTE *)(v4 + 52128) == 1 && *(_DWORD *)(v4 + 52124) == sender && (*(_BYTE *)(v4 + 52132) & 1) != 0 )
    {
      v47 = 1;
      goto LABEL_38;
    }
    if ( *(_BYTE *)(v4 + 52144) == 1 && *(_DWORD *)(v4 + 52140) == sender && (*(_BYTE *)(v4 + 52148) & 1) != 0 )
    {
      v47 = 2;
      goto LABEL_38;
    }
    if ( *(_BYTE *)(v4 + 52160) == 1 && *(_DWORD *)(v4 + 52156) == sender && (*(_BYTE *)(v4 + 52164) & 1) != 0 )
    {
      v47 = 3;
      goto LABEL_38;
    }
    if ( *(_BYTE *)(v4 + 52176) == 1 && *(_DWORD *)(v4 + 52172) == sender && *(_BYTE *)(v4 + 52180) == 1 )
    {
      v47 = 4;
      goto LABEL_38;
    }
    v48 = wlan_hdd_set_wlm_client_latency_level(v4, sender, v17, v39, v40, v41, v42, v43, v44, v45, v46);
    if ( v48 )
    {
      latency_host_flags = v48;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Fail to set latency level",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_config_latency_level");
      goto LABEL_45;
    }
    LOWORD(v17) = *(_WORD *)(v4 + 52098);
    goto LABEL_42;
  }
  v18 = jiffies;
  if ( hdd_config_latency_level___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: multi ll request already in progress",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_config_latency_level",
      v57,
      v58);
    hdd_config_latency_level___last_ticks = v18;
  }
  result = 4294967280LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
