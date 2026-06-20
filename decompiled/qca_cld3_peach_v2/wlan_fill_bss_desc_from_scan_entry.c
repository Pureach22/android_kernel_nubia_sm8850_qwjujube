__int64 __fastcall wlan_fill_bss_desc_from_scan_entry(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v3; // w23
  __int64 v7; // x20
  __int64 v8; // x24
  int v9; // w8
  char v10; // w8
  unsigned __int16 v11; // w23
  int v12; // w8
  __int64 v13; // x0
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _BYTE *v27; // x20
  unsigned int v28; // w0
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _BYTE *v38; // x23
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _BYTE *v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _BYTE *v57; // x21
  unsigned int v58; // w8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v68; // w19

  v3 = *(_WORD *)(a3 + 1888);
  v7 = *(_QWORD *)(a3 + 1896);
  v8 = a1 + 0x4000;
  *(_WORD *)a2 = v3 + 66;
  qdf_mem_copy((void *)(a2 + 2), (const void *)(a3 + 1), 6u);
  qdf_mem_copy((void *)(a2 + 8), (const void *)(a3 + 72), 8u);
  *(_WORD *)(a2 + 16) = *(_WORD *)(a3 + 68);
  *(_WORD *)(a2 + 18) = *(_WORD *)(a3 + 70);
  if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(a3 + 1192)) || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a3 + 1192)) )
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
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(a3 + 1192);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(v8 + 3828);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(v8 + 3832);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(a3 + 1304);
  *(_BYTE *)(a2 + 48) = *(_BYTE *)a3 == 80;
  *(_DWORD *)(a2 + 88) = *(unsigned __int8 *)(a3 + 86);
  *(_DWORD *)(a2 + 100) = *(_QWORD *)(a3 + 1824) != 0;
  *(_DWORD *)(a2 + 92) = *(_QWORD *)(a3 + 1744) != 0;
  if ( util_scan_entry_single_pmk(*(_QWORD *)(a1 + 21624), a3) )
    v12 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 2564LL);
  else
    v12 = 0;
  *(_DWORD *)(a2 + 96) = v12;
  qdf_mem_copy((void *)(a2 + 49), (const void *)(a3 + 112), 0x12u);
  qdf_mem_copy((void *)(a2 + 104), (const void *)(v7 + 36), v11);
  if ( !a2 )
    return 4;
  v13 = _qdf_mem_malloc(0x1490u, "wlan_get_parsed_bss_description_ies", 13086);
  if ( !v13 )
    return 2;
  v27 = (_BYTE *)v13;
  v28 = (unsigned int)wlan_parse_bss_description_ies(
                        a1,
                        (unsigned __int16 *)a2,
                        v13,
                        v19,
                        v20,
                        v21,
                        v22,
                        v23,
                        v24,
                        v25,
                        v26,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18);
  if ( !v28 )
  {
    if ( v27[1208] )
    {
      *(_BYTE *)(a2 + 44) = 1;
      qdf_mem_copy((void *)(a2 + 45), v27 + 1210, 2u);
      *(_BYTE *)(a2 + 47) = v27[1212] & 3;
    }
    if ( *(_QWORD *)(a3 + 1728) )
    {
      v29 = _qdf_mem_malloc(0x104u, "wlan_update_bss_with_fils_data", 13572);
      if ( v29 )
      {
        v38 = (_BYTE *)v29;
        v39 = dot11f_unpack_ie_fils_indication(
                a1,
                *(_QWORD *)(a3 + 1728) + 2LL,
                *(_BYTE *)(*(_QWORD *)(a3 + 1728) + 1LL),
                v29);
        if ( (v39 & 0x10000000) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: unpack failed ret: 0x%x",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "wlan_update_bss_with_fils_data",
            v39);
        }
        else
        {
          v48 = (_BYTE *)_qdf_mem_malloc(0x173u, "wlan_update_bss_with_fils_data", 13589);
          if ( v48 )
          {
            v57 = v48;
            update_fils_data(v48, v38, v49, v50, v51, v52, v53, v54, v55, v56);
            v58 = (unsigned __int8)v57[16];
            if ( v58 >= 8 )
            {
              v58 = 7;
              v57[16] = 7;
            }
            *(_WORD *)(a2 + 68) = v58;
            qdf_mem_copy((void *)(a2 + 70), v57 + 17, 2 * v58);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: FILS: bssid:%02x:%02x:%02x:**:**:%02xis_present:%d cache_id[0x%x%x]",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "wlan_update_bss_with_fils_data",
              *(unsigned __int8 *)(a2 + 2),
              *(unsigned __int8 *)(a2 + 3),
              *(unsigned __int8 *)(a2 + 4),
              *(unsigned __int8 *)(a2 + 7),
              (unsigned __int8)v57[5],
              (unsigned __int8)v57[6],
              (unsigned __int8)v57[7]);
            if ( v57[5] == 1 )
            {
              *(_BYTE *)(a2 + 85) = 1;
              qdf_mem_copy((void *)(a2 + 86), v57 + 6, 2u);
            }
            if ( v57[2] )
              *(_BYTE *)(a2 + 84) = 1;
            _qdf_mem_free((__int64)v57);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: malloc failed for fils_ind",
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              "wlan_update_bss_with_fils_data");
          }
        }
        _qdf_mem_free((__int64)v38);
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: malloc failed for fils_indication",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wlan_update_bss_with_fils_data");
      }
    }
    v28 = 0;
  }
  v68 = v28;
  _qdf_mem_free((__int64)v27);
  return v68;
}
