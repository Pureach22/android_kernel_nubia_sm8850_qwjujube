__int64 __fastcall lim_detect_change_in_ap_capabilities(
        __int64 result,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v12; // w26
  __int16 v13; // w25
  int v15; // w24
  __int64 v18; // x20
  __int64 v19; // x23
  int v20; // w27
  unsigned int v21; // w8
  __int64 v22; // x4
  int v23; // w8
  unsigned int v24; // w8
  bool v25; // zf
  int v26; // w8
  __int64 v27; // x21
  __int64 v28; // x20
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x4
  __int64 v44; // x7
  unsigned int v45; // w8
  __int64 v46; // [xsp+0h] [xbp-20h]
  __int64 v47; // [xsp+8h] [xbp-18h]

  v12 = *(unsigned __int8 *)(a2 + 11);
  v13 = *(unsigned __int8 *)(a2 + 10);
  v15 = *(_DWORD *)(a2 + 72);
  v18 = result;
  v19 = a3 + 4096;
  v20 = 1;
  if ( !a2 || !a3 )
  {
LABEL_19:
    if ( *(_BYTE *)(a3 + 179) )
      goto LABEL_20;
    goto LABEL_24;
  }
  v21 = *(unsigned __int16 *)(a2 + 10);
  v22 = (v21 >> 4) & 1;
  if ( (_DWORD)v22 != ((*(unsigned __int16 *)(a3 + 176) >> 4) & 1) )
  {
    result = qdf_trace_msg(
               0x35u,
               3u,
               "%s: Privacy bit miss match bcn %d session Bss Caps privacy %d",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "lim_enc_type_matched");
    v20 = 0;
    if ( *(_BYTE *)(a3 + 179) )
      goto LABEL_20;
    goto LABEL_24;
  }
  if ( !(_DWORD)v22 && !*(_DWORD *)(a3 + 424) )
  {
LABEL_18:
    v20 = 0;
    goto LABEL_19;
  }
  if ( (v21 & 0x10) != 0 )
  {
    if ( *(_BYTE *)(a2 + 2473) )
    {
      if ( *(_BYTE *)(a2 + 2473) == 1 )
      {
LABEL_14:
        v24 = *(_DWORD *)(a3 + 424) - 3;
        if ( v24 < 6 && ((0x3Bu >> v24) & 1) != 0 )
          goto LABEL_18;
        goto LABEL_16;
      }
      v23 = *(unsigned __int8 *)(a2 + 2474);
    }
    else
    {
      v23 = *(unsigned __int8 *)(a2 + 2474);
      if ( !*(_BYTE *)(a2 + 2474) )
      {
        v45 = *(_DWORD *)(a3 + 424);
        if ( v45 <= 5 && ((1 << v45) & 0x26) != 0 )
          goto LABEL_18;
        goto LABEL_16;
      }
    }
    if ( v23 != 1 )
      goto LABEL_16;
    goto LABEL_14;
  }
LABEL_16:
  if ( (*(_BYTE *)(a3 + 7364) & 1) != 0 || (*(_BYTE *)(a3 + 7023) & 1) != 0 )
    goto LABEL_18;
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: AP:: Privacy %d WPA %d RSN %d, SELF:: Privacy %d Enc %d OSEN %d WPS %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "lim_enc_type_matched",
             v22,
             *(unsigned __int8 *)(a2 + 2473),
             *(unsigned __int8 *)(a2 + 2474),
             (unsigned int)v22,
             *(_DWORD *)(a3 + 424),
             0,
             0);
  if ( *(_BYTE *)(a3 + 179) )
  {
LABEL_20:
    if ( *(_BYTE *)(v19 + 3165) == 1 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: %02x:%02x:%02x:**:**:%02x: capabilities in probe rsp are matching, so ignoring capability mismatch",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "lim_detect_change_in_ap_capabilities",
                 *(unsigned __int8 *)(a3 + 24),
                 *(unsigned __int8 *)(a3 + 25),
                 *(unsigned __int8 *)(a3 + 26),
                 *(unsigned __int8 *)(a3 + 29));
      *(_WORD *)(v19 + 3165) = 256;
    }
    return result;
  }
LABEL_24:
  result = lim_is_null_ssid(a2 + 12);
  if ( (_BYTE)result || (result = lim_cmp_ssid(a2 + 12, a3), !(_DWORD)result) )
  {
    if ( ((*(_WORD *)(a3 + 176) ^ (unsigned __int16)(v13 | (v12 << 8))) & 0x211) == 0 )
    {
      v25 = !v15 || v15 == *(_DWORD *)(a3 + 284);
      v26 = v25 ? v20 : 1;
      if ( v26 != 1 )
        goto LABEL_20;
    }
  }
  if ( *(_BYTE *)(v19 + 3165) != 1 || (a4 & 1) != 0 )
  {
    if ( *(_BYTE *)(v19 + 3166) == 1 )
    {
      v28 = jiffies;
      if ( lim_detect_change_in_ap_capabilities___last_ticks - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: Ignore the Capability change as probe rsp Capability matched",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "lim_detect_change_in_ap_capabilities");
        lim_detect_change_in_ap_capabilities___last_ticks = v28;
      }
    }
    else
    {
      v29 = *(unsigned __int8 *)(a3 + 24);
      v30 = *(unsigned __int8 *)(a3 + 25);
      v31 = *(unsigned __int8 *)(a3 + 26);
      v32 = *(unsigned __int8 *)(a3 + 29);
      *(_BYTE *)(v19 + 3165) = 1;
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: %02x:%02x:%02x:**:**:%02x: capabilities are not matching, sending directed probe request",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "lim_detect_change_in_ap_capabilities",
        v29,
        v30,
        v31,
        v32);
      result = lim_send_probe_req_mgmt_frame(v18, a3, 0, 0);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: send ProbeReq failed",
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   "lim_detect_change_in_ap_capabilities");
        *(_BYTE *)(v19 + 3165) = 0;
      }
    }
  }
  else if ( v15 == *(_DWORD *)(a3 + 284) )
  {
    if ( (v13 & 0x10) == 0 && (*(_BYTE *)(a2 + 2474) || *(_BYTE *)(a2 + 2473)) )
    {
      v27 = jiffies;
      if ( lim_detect_change_in_ap_capabilities___last_ticks_21 - jiffies + 125 < 0 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   4u,
                   "%s: %02x:%02x:%02x:**:**:%02x: BSS Caps (Privacy) bit 0 in beacon, but WPA or RSN IE present, Ignore Beacon!",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "lim_detect_change_in_ap_capabilities",
                   *(unsigned __int8 *)(a3 + 24),
                   *(unsigned __int8 *)(a3 + 25),
                   *(unsigned __int8 *)(a3 + 26),
                   *(unsigned __int8 *)(a3 + 29));
        lim_detect_change_in_ap_capabilities___last_ticks_21 = v27;
      }
    }
    else
    {
      v41 = *(unsigned __int8 *)(a3 + 25);
      v42 = *(unsigned __int8 *)(a3 + 26);
      v43 = *(unsigned __int8 *)(a3 + 24);
      v44 = *(unsigned __int8 *)(a3 + 29);
      *(_WORD *)(v19 + 3165) = 0;
      *(_BYTE *)(a3 + 179) = 1;
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: %02x:%02x:%02x:**:**:%02x: initiate Disconnect due to cap mismatch!",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "lim_detect_change_in_ap_capabilities",
        v43,
        v41,
        v42,
        v44);
      lim_send_deauth_mgmt_frame(v18, 1, a3 + 24, a3, 0);
      return ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD))lim_tear_down_link_with_ap)(
               v18,
               *(unsigned __int8 *)(a3 + 8),
               1,
               0);
    }
  }
  else
  {
    LODWORD(v47) = v15;
    LODWORD(v46) = *(_DWORD *)(a3 + 284);
    return qdf_trace_msg(
             0x35u,
             4u,
             "%s: %02x:%02x:%02x:**:**:%02x: Channel freq Change from %d --> %d Ignoring beacon!",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "lim_detect_change_in_ap_capabilities",
             *(unsigned __int8 *)(a3 + 24),
             *(unsigned __int8 *)(a3 + 25),
             *(unsigned __int8 *)(a3 + 26),
             *(unsigned __int8 *)(a3 + 29),
             v46,
             v47);
  }
  return result;
}
