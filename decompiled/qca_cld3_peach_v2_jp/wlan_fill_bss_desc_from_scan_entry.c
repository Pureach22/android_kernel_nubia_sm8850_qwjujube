__int64 __fastcall wlan_fill_bss_desc_from_scan_entry(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v3; // w23
  __int64 v7; // x20
  __int64 v8; // x24
  int v9; // w8
  char v10; // w8
  unsigned __int16 v11; // w23
  int v12; // w8
  bool v13; // w0
  int v14; // w8
  __int64 v15; // x0
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  _BYTE *v29; // x20
  unsigned int v30; // w0
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _BYTE *v40; // x23
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _BYTE *v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  _BYTE *v59; // x21
  unsigned int v60; // w8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v70; // w19

  v3 = *(_WORD *)(a3 + 1704);
  v7 = *(_QWORD *)(a3 + 1712);
  v8 = a1 + 0x4000;
  *(_WORD *)a2 = v3 + 66;
  qdf_mem_copy((void *)(a2 + 2), (const void *)(a3 + 1), 6u);
  qdf_mem_copy((void *)(a2 + 8), (const void *)(a3 + 72), 8u);
  *(_WORD *)(a2 + 16) = *(_WORD *)(a3 + 68);
  *(_WORD *)(a2 + 18) = *(_WORD *)(a3 + 70);
  if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a3 + 1064)) || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a3 + 1064)) )
  {
    *(_DWORD *)(a2 + 20) = 0;
  }
  else
  {
    if ( *(_DWORD *)(a3 + 52) == 2 )
      v9 = 1;
    else
      v9 = 2;
    *(_DWORD *)(a2 + 20) = v9;
  }
  v10 = *(_BYTE *)(a3 + 60);
  v11 = v3 - 36;
  *(_BYTE *)(a2 + 24) = v10;
  *(_BYTE *)(a2 + 25) = v10;
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a3 + 1064);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(v8 + 3756);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(v8 + 3760);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a3 + 1176);
  *(_BYTE *)(a2 + 48) = *(_BYTE *)a3 == 80;
  v12 = *(unsigned __int8 *)(a3 + 86);
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 88) = v12;
  *(_DWORD *)(a2 + 92) = *(_QWORD *)(a3 + 1616) != 0;
  v13 = util_scan_entry_single_pmk(*(_QWORD *)(a1 + 21552), a3);
  v14 = 0;
  if ( v13 )
    v14 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2360LL);
  *(_DWORD *)(a2 + 96) = v14;
  qdf_mem_copy((void *)(a2 + 49), (const void *)(a3 + 112), 0x12u);
  qdf_mem_copy((void *)(a2 + 104), (const void *)(v7 + 36), v11);
  if ( !a2 )
    return 4;
  v15 = _qdf_mem_malloc(0x1490u, "wlan_get_parsed_bss_description_ies", 13086);
  if ( !v15 )
    return 2;
  v29 = (_BYTE *)v15;
  v30 = wlan_parse_bss_description_ies(
          a1,
          (unsigned __int16 *)a2,
          v15,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( !v30 )
  {
    if ( v29[1208] )
    {
      *(_BYTE *)(a2 + 44) = 1;
      qdf_mem_copy((void *)(a2 + 45), v29 + 1210, 2u);
      *(_BYTE *)(a2 + 47) = v29[1212] & 3;
    }
    if ( *(_QWORD *)(a3 + 1600) )
    {
      v31 = _qdf_mem_malloc(0x104u, "wlan_update_bss_with_fils_data", 13572);
      if ( v31 )
      {
        v40 = (_BYTE *)v31;
        v41 = dot11f_unpack_ie_fils_indication(
                a1,
                *(_QWORD *)(a3 + 1600) + 2LL,
                *(_BYTE *)(*(_QWORD *)(a3 + 1600) + 1LL),
                v31);
        if ( (v41 & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: unpack failed ret: 0x%x",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "wlan_update_bss_with_fils_data",
            v41);
        }
        else
        {
          v50 = (_BYTE *)_qdf_mem_malloc(0x173u, "wlan_update_bss_with_fils_data", 13589);
          if ( v50 )
          {
            v59 = v50;
            update_fils_data(v50, v40, v51, v52, v53, v54, v55, v56, v57, v58);
            v60 = (unsigned __int8)v59[16];
            if ( v60 >= 8 )
            {
              v60 = 7;
              v59[16] = 7;
            }
            *(_WORD *)(a2 + 68) = v60;
            qdf_mem_copy((void *)(a2 + 70), v59 + 17, 2 * v60);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: FILS: bssid:%02x:%02x:%02x:**:**:%02xis_present:%d cache_id[0x%x%x]",
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              "wlan_update_bss_with_fils_data",
              *(unsigned __int8 *)(a2 + 2),
              *(unsigned __int8 *)(a2 + 3),
              *(unsigned __int8 *)(a2 + 4),
              *(unsigned __int8 *)(a2 + 7),
              (unsigned __int8)v59[5],
              (unsigned __int8)v59[6],
              (unsigned __int8)v59[7]);
            if ( v59[5] == 1 )
            {
              *(_BYTE *)(a2 + 85) = 1;
              qdf_mem_copy((void *)(a2 + 86), v59 + 6, 2u);
            }
            if ( v59[2] )
              *(_BYTE *)(a2 + 84) = 1;
            _qdf_mem_free((__int64)v59);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: malloc failed for fils_ind",
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              "wlan_update_bss_with_fils_data");
          }
        }
        _qdf_mem_free((__int64)v40);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: malloc failed for fils_indication",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_update_bss_with_fils_data");
      }
    }
    v30 = 0;
  }
  v70 = v30;
  _qdf_mem_free((__int64)v29);
  return v70;
}
