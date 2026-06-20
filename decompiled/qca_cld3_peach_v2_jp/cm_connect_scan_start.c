__int64 __fastcall cm_connect_scan_start(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 v14; // x23
  __int64 v15; // x4
  __int64 v16; // x0
  unsigned int v17; // w22
  unsigned int inited; // w24
  unsigned int v19; // w8
  size_t v20; // x0
  void *v21; // x0
  __int64 v22; // x8
  unsigned int v23; // w25
  unsigned int v24; // w24
  int v25; // w9
  __int64 v26; // x5
  const char *v27; // x2
  const char *v28; // x3
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  unsigned int v39; // w1
  unsigned int v40; // w20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7

  _ReadStatusReg(SP_EL0);
  v4 = _qdf_mem_malloc(0x8F0u, "cm_connect_scan_start", 211);
  if ( !v4 )
  {
    inited = 2;
    goto LABEL_25;
  }
  v13 = v4;
  v14 = *(_QWORD *)(*a1 + 152);
  v15 = *(unsigned __int8 *)(*a1 + 104);
  if ( !v14 )
  {
    v26 = *a2;
    v27 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_19:
    v28 = "cm_fill_scan_req";
    goto LABEL_20;
  }
  v16 = *(_QWORD *)(v14 + 80);
  if ( !v16 )
  {
    v26 = *a2;
    v27 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_19;
  }
  v17 = *(unsigned __int8 *)(*a1 + 104);
  a2[1] = wlan_scan_get_scan_id(v16);
  inited = wlan_scan_init_default_params(*a1, v13);
  if ( inited )
    goto LABEL_22;
  *(_DWORD *)(v13 + 28) = 4;
  *(_DWORD *)(v13 + 8) = a2[1];
  v19 = *(_DWORD *)(v13 + 92) & 0xFFFFFFFC;
  *(_DWORD *)(v13 + 12) = *((unsigned __int16 *)a1 + 100);
  *(_DWORD *)(v13 + 92) = v19;
  v20 = a2[44];
  if ( (_DWORD)v20 )
  {
    v21 = (void *)_qdf_mem_malloc(v20, "cm_fill_scan_req", 160);
    *(_QWORD *)(v13 + 2032) = v21;
    if ( !v21 )
    {
      inited = 2;
      v29 = *(_QWORD *)(v13 + 2032);
      if ( !v29 )
        goto LABEL_24;
      goto LABEL_23;
    }
    qdf_mem_copy(v21, *((const void **)a2 + 23), a2[44]);
    *(_DWORD *)(v13 + 2024) = a2[44];
  }
  v22 = *a1;
  if ( *(_DWORD *)(*a1 + 16) == 2 )
  {
    *(_DWORD *)(v13 + 24) = 3;
    v22 = *a1;
  }
  v23 = a2[17];
  v24 = *(unsigned __int8 *)(v22 + 104);
  if ( !v23 )
  {
    v23 = a2[18];
    if ( !v23 )
      goto LABEL_14;
  }
  if ( (wlan_reg_get_channel_state_for_pwrmode(v14, v23, 0xFFFFFFFFLL) & 0xFFFFFFFB) != 0 )
  {
    *(_DWORD *)(v13 + 124) = v23;
    *(_BYTE *)(v13 + 120) = 1;
LABEL_14:
    *(_DWORD *)(v13 + 108) = 1;
    if ( a2[4] | *((unsigned __int16 *)a2 + 10) )
    {
      v25 = a2[4];
      *(_WORD *)(v13 + 1880) = *((_WORD *)a2 + 10);
    }
    else
    {
      v25 = -1;
      *(_WORD *)(v13 + 1880) = -1;
    }
    *(_DWORD *)(v13 + 1876) = v25;
    if ( *((unsigned __int8 *)a2 + 28) < 0x21u )
    {
      *(_DWORD *)(v13 + 112) = 1;
      qdf_mem_copy((void *)(v13 + 1349), (char *)a2 + 29, *((unsigned __int8 *)a2 + 28));
      *(_BYTE *)(v13 + 1348) = *((_BYTE *)a2 + 28);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: Connect scan for %.*s",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "cm_fill_scan_req",
        v17,
        *a2);
      *(_DWORD *)(v13 + 80) = 10000;
      result = wlan_scan_start(v13);
      inited = result;
      if ( !(_DWORD)result )
        goto LABEL_27;
      goto LABEL_25;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: Wrong ssid length %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_fill_scan_req",
      v17,
      *a2);
    goto LABEL_21;
  }
  v26 = *a2;
  v27 = "%s: vdev %d cm_id 0x%x: Invalid channel frequency";
  v28 = "cm_fill_scan_req_for_no_candidates";
  v15 = v24;
LABEL_20:
  qdf_trace_msg(0x68u, 2u, v27, v5, v6, v7, v8, v9, v10, v11, v12, v28, v15, v26);
LABEL_21:
  inited = 4;
LABEL_22:
  v29 = *(_QWORD *)(v13 + 2032);
  if ( v29 )
  {
LABEL_23:
    _qdf_mem_free(v29);
    *(_DWORD *)(v13 + 2024) = 0;
    *(_QWORD *)(v13 + 2032) = 0;
  }
LABEL_24:
  _qdf_mem_free(v13);
LABEL_25:
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev %d cm_id 0x%x: Failed to initiate scan with status: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "cm_connect_scan_start",
    *(unsigned __int8 *)(*a1 + 104),
    *a2,
    inited);
  result = wlan_sm_dispatch(a1[9], 3u, 4u, (__int64)(a2 + 1), v30, v31, v32, v33, v34, v35, v36, v37);
  if ( (_DWORD)result )
  {
    v39 = *a2;
    v40 = result;
    cm_connect_handle_event_post_fail((__int64)a1, v39);
    result = v40;
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
