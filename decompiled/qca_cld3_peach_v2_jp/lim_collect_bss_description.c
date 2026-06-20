_BYTE *__fastcall lim_collect_bss_description(_BYTE *result, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  unsigned int v5; // w8
  unsigned int v6; // w22
  __int64 v7; // x27
  __int64 v8; // x28
  _BYTE *v11; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  unsigned int channel_from_beacon; // w25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w8
  int v37; // w9
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  int v54; // w8
  __int64 v55; // [xsp+0h] [xbp-30h]
  __int64 v56; // [xsp+8h] [xbp-28h]

  v5 = *(_DWORD *)(a4 + 40);
  v6 = v5 - 12;
  if ( v5 >= 0xC )
  {
    v8 = *(_QWORD *)(a4 + 16);
    v7 = *(_QWORD *)(a4 + 24);
    v11 = result;
    *(_WORD *)a2 = v5 + 90;
    qdf_mem_copy((void *)(a2 + 2), (const void *)(v8 + 16), 6u);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)a3;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(a3 + 4);
    v22 = *(unsigned __int16 *)(a3 + 8);
    *(_WORD *)(a2 + 16) = v22;
    *(_WORD *)(a2 + 18) = *(_WORD *)(a3 + 10);
    if ( !v22 )
    {
      if ( v8 == -16 )
      {
        v25 = 0;
        v23 = 0;
        v24 = 0;
        v26 = 0;
      }
      else
      {
        v23 = *(unsigned __int8 *)(v8 + 16);
        v24 = *(unsigned __int8 *)(v8 + 17);
        v25 = *(unsigned __int8 *)(v8 + 18);
        v26 = *(unsigned __int8 *)(v8 + 21);
      }
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Beacon Interval is ZERO, making it to default 100 %02x:%02x:%02x:**:**:%02x",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_collect_bss_description",
        v23,
        v24,
        v25,
        v26);
      *(_WORD *)(a2 + 16) = 100;
    }
    channel_from_beacon = lim_get_channel_from_beacon(v11, a3);
    *(_DWORD *)(a2 + 28) = channel_from_beacon;
    *(_DWORD *)(a2 + 20) = ((__int64 (__fastcall *)(_BYTE *, _QWORD, _QWORD, __int64))lim_get_nw_type)(
                             v11,
                             channel_from_beacon,
                             0,
                             a3);
    v36 = *(_DWORD *)(a4 + 8);
    *(_BYTE *)(a2 + 24) = v36;
    v37 = *(_DWORD *)(a4 + 52);
    *(_BYTE *)(a2 + 25) = v37;
    if ( v8 == -16 )
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
    }
    else
    {
      v38 = *(unsigned __int8 *)(v8 + 16);
      v39 = *(unsigned __int8 *)(v8 + 17);
      v40 = *(unsigned __int8 *)(v8 + 18);
      v41 = *(unsigned __int8 *)(v8 + 21);
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x rssi: normalized: %d, absolute: %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "lim_collect_bss_description",
      v38,
      v39,
      v40,
      v41,
      (char)v36,
      (char)v37);
    if ( *(_BYTE *)(a2 + 48) )
      v50 = "Probe Rsp";
    else
      v50 = "Beacon";
    if ( v8 == -16 )
    {
      v53 = 0;
      v51 = 0;
      v52 = 0;
      v54 = 0;
    }
    else
    {
      v51 = *(unsigned __int8 *)(v8 + 16);
      v52 = *(unsigned __int8 *)(v8 + 17);
      v53 = *(unsigned __int8 *)(v8 + 18);
      v54 = *(unsigned __int8 *)(v8 + 21);
    }
    LODWORD(v56) = *(unsigned __int16 *)(v8 + 22) >> 4;
    LODWORD(v55) = v54;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Received %s from BSSID: %02x:%02x:%02x:**:**:%02x Seq Num: %x ssid:%.*s, rssi: %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "lim_collect_bss_description",
      v50,
      v51,
      v52,
      v53,
      v55,
      v56,
      *(unsigned __int8 *)(a3 + 12),
      a3 + 13,
      *(char *)(a2 + 25));
    if ( a5 )
    {
      rrm_get_start_tsf(v11, a2 + 36);
      *(_DWORD *)(a2 + 32) = *(_DWORD *)(a4 + 12);
    }
    *(_DWORD *)(a2 + 44) = 0;
    if ( *(_BYTE *)(a3 + 2482) )
    {
      *(_BYTE *)(a2 + 44) = 1;
      *(_BYTE *)(a2 + 45) = *(_BYTE *)(a3 + 2446);
      *(_BYTE *)(a2 + 46) = *(_BYTE *)(a3 + 2447);
      *(_BYTE *)(a2 + 47) = *(_BYTE *)(a3 + 2448);
    }
    result = qdf_mem_copy((void *)(a2 + 104), (const void *)(v7 + 12), v6);
    *(_DWORD *)(a3 + 72) = channel_from_beacon;
    ++v11[12433];
  }
  return result;
}
