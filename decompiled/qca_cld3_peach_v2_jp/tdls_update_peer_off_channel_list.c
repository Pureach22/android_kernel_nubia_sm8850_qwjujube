__int64 __fastcall tdls_update_peer_off_channel_list(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  __int64 v28; // x1
  char opclass_from_bandwidth; // w0
  __int64 result; // x0
  char opclass; // w0
  int v32; // w8
  __int64 v33; // x2
  __int64 v34; // x0
  __int64 v35; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int64 v44; // x25
  unsigned int *v45; // x27
  unsigned int v46; // w24
  __int64 v47; // x4
  unsigned int v48; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 80);
  v48 = 0;
  if ( (*(_BYTE *)(v13 + 25) & 1) == 0 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: TDLS Concurrencies FW cap is not supported",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "tdls_update_peer_off_channel_list");
LABEL_34:
    result = 0;
    goto LABEL_35;
  }
  if ( (policy_mgr_get_allowed_tdls_offchannel_freq(v13, a3, &v48) & 1) == 0 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: off channel not allowed for current concurrency",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "tdls_update_peer_off_channel_list");
    result = 11;
    goto LABEL_35;
  }
  if ( v48 )
  {
    v27 = wlan_reg_freq_to_chan(a1, v48, v19, v20, v21, v22, v23, v24, v25, v26);
    v28 = v48;
    *(_BYTE *)(a5 + 11) = v27;
    *(_DWORD *)(a5 + 16) = v28;
    if ( !*(_BYTE *)(a2 + 204) || *(_WORD *)(a2 + 206) == 255 )
    {
      if ( !*(_BYTE *)(a4 + 51) || !*(_DWORD *)(a4 + 492) )
        goto LABEL_18;
      opclass_from_bandwidth = tdls_get_opclass_from_bandwidth(a3, v28, *(unsigned __int8 *)(a4 + 496), a5 + 10);
      goto LABEL_17;
    }
    opclass = tdls_find_opclass(v13, v27, *(unsigned __int8 *)(a5 + 10));
    *(_BYTE *)(a5 + 13) = opclass;
    if ( !opclass )
    {
      v32 = *(unsigned __int8 *)(a5 + 10);
      if ( v32 == 3 )
      {
        v33 = 1;
        goto LABEL_16;
      }
      if ( v32 == 1 )
      {
        v33 = 3;
LABEL_16:
        opclass_from_bandwidth = tdls_find_opclass(v13, *(unsigned __int8 *)(a5 + 11), v33);
LABEL_17:
        *(_BYTE *)(a5 + 13) = opclass_from_bandwidth;
      }
    }
  }
LABEL_18:
  v34 = _qdf_mem_malloc(0x444u, "tdls_update_peer_off_channel_list", 1281);
  if ( v34 )
  {
    v35 = v34;
    tdls_extract_peer_state_param(v34, a4);
    *(_WORD *)(a5 + 20) = 0;
    if ( *(_BYTE *)(v35 + 23) )
    {
      v44 = 0;
      v45 = (unsigned int *)(v35 + 24);
      do
      {
        if ( v44 == 128 )
          __break(0x5512u);
        v46 = *v45;
        if ( (!v48 || v48 == v46)
          && (!wlan_reg_is_24ghz_ch_freq(v46)
           || wlan_reg_is_6ghz_chan_freq(v46) && (tdls_is_6g_freq_allowed(a1, v46) & 1) != 0) )
        {
          *(_QWORD *)(a5 + 24 + 8LL * *(unsigned __int16 *)(a5 + 20)) = *(_QWORD *)v45;
          qdf_trace_msg(
            0,
            8u,
            "%s: allowd_chan:%d idx:%d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "tdls_update_peer_off_channel_list");
          ++*(_WORD *)(a5 + 20);
        }
        ++v44;
        v45 += 2;
      }
      while ( v44 < *(unsigned __int8 *)(v35 + 23) );
      v47 = *(unsigned __int16 *)(a5 + 20);
    }
    else
    {
      v47 = 0;
    }
    qdf_trace_msg(
      0,
      8u,
      "%s: Num allowed off channels:%d freq:%u",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "tdls_update_peer_off_channel_list",
      v47,
      v48);
    _qdf_mem_free(v35);
    goto LABEL_34;
  }
  result = 2;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
