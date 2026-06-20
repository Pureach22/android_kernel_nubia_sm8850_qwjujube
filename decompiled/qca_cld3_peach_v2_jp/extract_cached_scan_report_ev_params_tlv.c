__int64 __fastcall extract_cached_scan_report_ev_params_tlv(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  int v13; // w8
  void *v14; // x0
  int v15; // w8
  int v16; // w8
  __int64 v17; // x0
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x24
  __int64 v20; // x27
  __int64 v21; // x26
  __int64 v22; // x23
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w12
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  int v36; // w8
  int v37; // w9
  int v38; // w10
  int v39; // w11
  int v40; // w13
  int v41; // w14
  int v42; // w15
  int v43; // w16
  __int64 v44; // x8
  __int64 v45; // x28
  __int64 v46; // x9
  unsigned int v47; // w9
  size_t v48; // x2
  __int64 v50; // [xsp+0h] [xbp-50h]
  __int64 v51; // [xsp+8h] [xbp-48h]
  __int64 v52; // [xsp+10h] [xbp-40h]
  __int64 v53; // [xsp+18h] [xbp-38h]
  __int64 v54; // [xsp+20h] [xbp-30h]
  __int64 v55; // [xsp+28h] [xbp-28h]
  __int64 v56; // [xsp+30h] [xbp-20h]
  __int64 v57; // [xsp+38h] [xbp-18h]
  __int64 v58; // [xsp+40h] [xbp-10h]

  v3 = _qdf_mem_malloc(0x20u, "extract_cached_scan_report_ev_params_tlv", 23330);
  v12 = v3;
  if ( !v3 )
    return v12;
  v13 = *(_DWORD *)(a2 + 24);
  if ( v13 )
  {
    v14 = (void *)_qdf_mem_malloc((unsigned int)(4 * v13), "extract_cached_scan_report_ev_params_tlv", 23336);
    *(_QWORD *)(v12 + 16) = v14;
    if ( !v14 )
    {
LABEL_22:
      _qdf_mem_free((__int64)v14);
      _qdf_mem_free(v12);
      return 0;
    }
    qdf_mem_copy(v14, *(const void **)(a2 + 16), (unsigned int)(4 * *(_DWORD *)(a2 + 24)));
  }
  else
  {
    *(_QWORD *)(v3 + 16) = 0;
  }
  v15 = *(_DWORD *)(a2 + 24);
  *(_WORD *)v12 = v15;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Freq list %d, bss list %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "extract_cached_scan_report_ev_params_tlv",
    (unsigned __int16)v15,
    *(unsigned int *)(a2 + 40));
  v16 = *(_DWORD *)(a2 + 40);
  if ( !v16 )
  {
    *(_QWORD *)(v12 + 24) = 0;
    *(_WORD *)(v12 + 2) = 0;
    return v12;
  }
  v17 = _qdf_mem_malloc((unsigned int)(68 * v16), "extract_cached_scan_report_ev_params_tlv", 23357);
  *(_QWORD *)(v12 + 24) = v17;
  if ( !v17 )
  {
    v14 = *(void **)(v12 + 16);
    goto LABEL_22;
  }
  LODWORD(v18) = *(_DWORD *)(a2 + 40);
  if ( (_DWORD)v18 )
  {
    v19 = 0;
    v20 = 35;
    v21 = *(_QWORD *)(a2 + 32) + 48LL;
    do
    {
      v44 = *(_QWORD *)(v12 + 24);
      v45 = v44 + v20;
      *(_DWORD *)(v45 - 31) = *(_DWORD *)(v21 - 44);
      *(_WORD *)(v45 - 33) = *(_DWORD *)(v21 - 40);
      *(_DWORD *)(v45 - 27) = *(_DWORD *)(v21 + 8);
      *(_BYTE *)(v45 - 35) = *(_DWORD *)(v21 + 12);
      *(_DWORD *)(v45 - 23) = *(_DWORD *)(v21 + 28);
      *(_DWORD *)(v45 - 19) = *(_DWORD *)(v21 + 20);
      *(_DWORD *)(v45 - 15) = *(_DWORD *)(v21 + 24);
      v46 = *(unsigned int *)(v21 + 16);
      if ( (unsigned int)v46 > 9 )
        v47 = 8;
      else
        v47 = dword_9E7138[v46];
      *(_DWORD *)(v45 - 11) = v47;
      *(_WORD *)(v45 - 7) = *(_DWORD *)v21;
      *(_BYTE *)(v45 - 5) = *(_WORD *)(v21 + 2);
      *(_BYTE *)(v45 - 4) = *(_BYTE *)(v21 + 3);
      *(_WORD *)(v45 - 3) = *(_DWORD *)(v21 + 4);
      v48 = *(unsigned int *)(v21 - 36);
      if ( (unsigned int)v48 >= 0x21 )
      {
        v48 = 32;
        *(_DWORD *)(v21 - 36) = 32;
      }
      v22 = v44 + v20;
      qdf_mem_copy((void *)(v44 + v20), (const void *)(v21 - 32), v48);
      v31 = *(_DWORD *)(v21 - 36);
      v32 = *(unsigned int *)(v45 - 31);
      v33 = *(unsigned __int16 *)(v45 - 33);
      v34 = *(unsigned int *)(v45 - 27);
      v35 = (unsigned int)*(char *)(v45 - 35);
      v36 = *(_DWORD *)(v45 - 23);
      v37 = *(_DWORD *)(v45 - 19);
      v38 = *(_DWORD *)(v45 - 15);
      v39 = *(_DWORD *)(v45 - 11);
      *(_BYTE *)(v22 - 1) = v31;
      if ( v45 == 7 )
      {
        v42 = 0;
        v40 = 0;
        v41 = 0;
        v43 = 0;
      }
      else
      {
        v40 = *(unsigned __int8 *)(v45 - 7);
        v41 = *(unsigned __int8 *)(v45 - 6);
        v42 = *(unsigned __int8 *)(v45 - 5);
        v43 = *(unsigned __int8 *)(v45 - 2);
      }
      LODWORD(v58) = (unsigned __int8)v31;
      LODWORD(v57) = v43;
      LODWORD(v56) = v42;
      LODWORD(v55) = v41;
      LODWORD(v54) = v40;
      LODWORD(v53) = v39;
      LODWORD(v52) = v38;
      LODWORD(v51) = v37;
      LODWORD(v50) = v36;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: age %d, cap 0x%x, flags 0x%x, rssi %d, freq %d, ccfs0 %d, ccfs1 %d, bw %d, BSSID: %02x:%02x:%02x:**:**:%02x, SSID: %.*s",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "extract_cached_scan_report_ev_params_tlv",
        v32,
        v33,
        v34,
        v35,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v22);
      v18 = *(unsigned int *)(a2 + 40);
      ++v19;
      v20 += 68;
      v21 += 80;
    }
    while ( v19 < v18 );
  }
  *(_WORD *)(v12 + 2) = v18;
  return v12;
}
