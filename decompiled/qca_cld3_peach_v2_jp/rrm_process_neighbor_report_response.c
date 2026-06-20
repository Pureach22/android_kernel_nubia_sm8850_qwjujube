__int64 __fastcall rrm_process_neighbor_report_response(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w8
  unsigned __int16 v23; // w22
  __int64 v24; // x0
  unsigned __int16 *v25; // x21
  __int64 v26; // x24
  unsigned __int16 *v27; // x25
  __int64 v28; // x26
  unsigned __int16 *v29; // x9
  char v30; // w8
  unsigned __int16 *v32; // x28
  unsigned int v33; // w9
  unsigned int v34; // w9
  unsigned int v35; // w9
  unsigned int v36; // w9
  unsigned int v37; // w9
  unsigned int v38; // w9
  unsigned int v39; // w9
  unsigned int v40; // w9
  unsigned int v41; // w9
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 result; // x0
  const char *v59; // x2
  int v60; // w3
  __int16 v61; // w2
  __int64 v62; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int16 *v63; // [xsp+10h] [xbp-30h]
  __int64 v64; // [xsp+18h] [xbp-28h]
  __int64 v65; // [xsp+20h] [xbp-20h]
  __int64 v66; // [xsp+28h] [xbp-18h]
  __int64 v67; // [xsp+30h] [xbp-10h]
  __int64 v68; // [xsp+38h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = nullptr;
  if ( !a2 || !a3 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid parameters",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "rrm_process_neighbor_report_response");
    goto LABEL_17;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Neighbor report response received",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "rrm_process_neighbor_report_response");
  if ( *(unsigned __int8 *)(a1 + 20154) != *(unsigned __int8 *)(a2 + 2) )
  {
    v59 = "%s: Dialog token mismatch in the received Neighbor report";
LABEL_20:
    qdf_trace_msg(0x35u, 2u, v59, v14, v15, v16, v17, v18, v19, v20, v21, "rrm_process_neighbor_report_response");
LABEL_21:
    result = 16;
    goto LABEL_22;
  }
  if ( !*(_WORD *)(a2 + 4) )
  {
    v59 = "%s: No neighbor report in the frame...Dropping it";
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: RRM:received num neighbor reports: %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "rrm_process_neighbor_report_response");
  v22 = *(unsigned __int16 *)(a2 + 4);
  if ( v22 >= 0x10 )
  {
    v22 = 15;
    *(_WORD *)(a2 + 4) = 15;
  }
  v23 = 24 * v22 + 16;
  v24 = _qdf_mem_malloc(24 * v22 + 16, "rrm_process_neighbor_report_response", 379);
  if ( !v24 )
  {
    result = 2;
    goto LABEL_22;
  }
  v25 = (unsigned __int16 *)v24;
  if ( *(_WORD *)(a2 + 4) )
  {
    v26 = 0;
    v27 = (unsigned __int16 *)(a2 + 13);
    v28 = 1;
    while ( 1 )
    {
      v32 = &v25[v26];
      v25[v26 + 8] = 24;
      if ( v26 == 180 )
        __break(0x5512u);
      qdf_mem_copy(v32 + 9, v27 - 3, 6u);
      v33 = *((_DWORD *)v32 + 7) & 0xFFFFFFFC | *v27 & 3;
      *((_DWORD *)v32 + 7) = v33;
      v34 = v33 & 0xFFFFFFFB | (4 * ((*v27 >> 2) & 1));
      *((_DWORD *)v32 + 7) = v34;
      v35 = v34 & 0xFFFFFFF7 | (8 * ((*v27 >> 3) & 1));
      *((_DWORD *)v32 + 7) = v35;
      v36 = v35 & 0xFFFFFFEF | (16 * ((*v27 >> 4) & 1));
      *((_DWORD *)v32 + 7) = v36;
      v37 = v36 & 0xFFFFFFDF | (32 * ((*v27 >> 5) & 1));
      *((_DWORD *)v32 + 7) = v37;
      v38 = v37 & 0xFFFFFFBF | (((*v27 >> 6) & 1) << 6);
      *((_DWORD *)v32 + 7) = v38;
      v39 = v38 & 0xFFFFFF7F | (((*v27 >> 7) & 1) << 7);
      *((_DWORD *)v32 + 7) = v39;
      v40 = v39 & 0xFFFFFEFF | ((HIBYTE(*v27) & 1) << 8);
      *((_DWORD *)v32 + 7) = v40;
      v41 = v40 & 0xFFFFFDFF | (((*v27 >> 9) & 1) << 9);
      *((_DWORD *)v32 + 7) = v41;
      *((_DWORD *)v32 + 7) = v41 & 0xFFFFFBFF | (((*v27 >> 10) & 1) << 10);
      if ( (wlan_reg_is_6ghz_supported(*(_QWORD *)(a1 + 21552), v42, v43, v44, v45, v46, v47, v48, v49) & 1) == 0
        && wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21560), *((_BYTE *)v27 + 5)) )
      {
        break;
      }
      v29 = &v25[v26];
      v26 += 12;
      *((_BYTE *)v29 + 24) = *((_BYTE *)v27 + 5);
      *((_BYTE *)v29 + 25) = *((_BYTE *)v27 + 6);
      v30 = *((_BYTE *)v27 + 7);
      v27 += 274;
      *((_BYTE *)v29 + 26) = v30;
      if ( *(unsigned __int16 *)(a2 + 4) <= (unsigned int)(unsigned __int16)v28++ )
        goto LABEL_23;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: channel belongs to 6 ghz spectrum, abort",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "rrm_process_neighbor_report_response");
    _qdf_mem_free((__int64)v25);
    goto LABEL_21;
  }
LABEL_23:
  v25[1] = v23;
  *v25 = 5164;
  *((_BYTE *)v25 + 5) = 0;
  *((_BYTE *)v25 + 4) = *(_BYTE *)(a3 + 10);
  v25[3] = *(_WORD *)(a2 + 4);
  qdf_mem_copy(v25 + 4, (const void *)(a3 + 24), 6u);
  v60 = *v25;
  v61 = *(_WORD *)(a3 + 8);
  v63 = v25;
  LOWORD(v62) = v60;
  qdf_trace(53, 6u, v61, v60);
  sys_process_mmh_msg(a1, &v62);
LABEL_17:
  result = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
