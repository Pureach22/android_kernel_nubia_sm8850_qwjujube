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
  __int64 v22; // x5
  const char *v23; // x2
  const char *v24; // x3
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  unsigned int v35; // w1
  unsigned int v36; // w20
  unsigned int v37; // w25
  unsigned int v38; // w24
  int v39; // w9
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  _ReadStatusReg(SP_EL0);
  v4 = _qdf_mem_malloc(0x8F0u, "cm_connect_scan_start", 211);
  if ( !v4 )
  {
    inited = 2;
    goto LABEL_21;
  }
  v13 = v4;
  v14 = *(_QWORD *)(*a1 + 216);
  v15 = *(unsigned __int8 *)(*a1 + 168);
  if ( !v14 )
  {
    v22 = *a2;
    v23 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_15:
    v24 = "cm_fill_scan_req";
    goto LABEL_16;
  }
  v16 = *(_QWORD *)(v14 + 80);
  if ( !v16 )
  {
    v22 = *a2;
    v23 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_15;
  }
  v17 = *(unsigned __int8 *)(*a1 + 168);
  a2[1] = wlan_scan_get_scan_id(v16);
  inited = wlan_scan_init_default_params(*a1, v13);
  if ( inited )
    goto LABEL_18;
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
      v25 = *(_QWORD *)(v13 + 2032);
      if ( !v25 )
        goto LABEL_20;
      goto LABEL_19;
    }
    qdf_mem_copy(v21, *((const void **)a2 + 23), a2[44]);
    *(_DWORD *)(v13 + 2024) = a2[44];
  }
  if ( *(_DWORD *)(*a1 + 16) == 2 )
    *(_DWORD *)(v13 + 24) = 3;
  if ( *((_BYTE *)a2 + 1048) == 1 )
  {
    qdf_mem_copy((void *)(v13 + 120), a2 + 263, 0x4CCu);
    qdf_mem_copy((void *)(v13 + 2084), a2 + 579, 0x50u);
    *(_DWORD *)(v13 + 2076) = a2[571];
    qdf_mem_copy((void *)(v13 + 2164), a2 + 599, 0x78u);
    *(_DWORD *)(v13 + 2080) = a2[572];
    qdf_mem_copy((void *)(v13 + 1876), a2 + 573, 0x18u);
    *(_DWORD *)(v13 + 108) = a2[570];
LABEL_35:
    if ( *((unsigned __int8 *)a2 + 28) < 0x21u )
    {
      *(_DWORD *)(v13 + 112) = 1;
      qdf_mem_copy((void *)(v13 + 1349), (char *)a2 + 29, *((unsigned __int8 *)a2 + 28));
      *(_BYTE *)(v13 + 1348) = *((_BYTE *)a2 + 28);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x: Connect scan for %.*s",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "cm_fill_scan_req",
        v17,
        *a2);
      *(_DWORD *)(v13 + 80) = 10000;
      result = wlan_scan_start(v13);
      inited = result;
      if ( !(_DWORD)result )
        goto LABEL_23;
      goto LABEL_21;
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
    goto LABEL_17;
  }
  v37 = a2[17];
  v38 = *(unsigned __int8 *)(*a1 + 168);
  if ( !v37 )
  {
    v37 = a2[18];
    if ( !v37 )
    {
LABEL_28:
      *(_DWORD *)(v13 + 108) = 1;
      if ( a2[4] | *((unsigned __int16 *)a2 + 10) )
      {
        v39 = a2[4];
        *(_WORD *)(v13 + 1880) = *((_WORD *)a2 + 10);
      }
      else
      {
        v39 = -1;
        *(_WORD *)(v13 + 1880) = -1;
      }
      *(_DWORD *)(v13 + 1876) = v39;
      goto LABEL_35;
    }
  }
  if ( (wlan_reg_get_channel_state_for_pwrmode(v14, v37, 0xFFFFFFFFLL) & 0xFFFFFFFB) != 0 )
  {
    *(_DWORD *)(v13 + 124) = v37;
    *(_BYTE *)(v13 + 120) = 1;
    goto LABEL_28;
  }
  v22 = *a2;
  v23 = "%s: vdev %d cm_id 0x%x: Invalid channel frequency";
  v24 = "cm_fill_scan_req_for_no_candidates";
  v15 = v38;
LABEL_16:
  qdf_trace_msg(0x68u, 2u, v23, v5, v6, v7, v8, v9, v10, v11, v12, v24, v15, v22);
LABEL_17:
  inited = 4;
LABEL_18:
  v25 = *(_QWORD *)(v13 + 2032);
  if ( v25 )
  {
LABEL_19:
    _qdf_mem_free(v25);
    *(_DWORD *)(v13 + 2024) = 0;
    *(_QWORD *)(v13 + 2032) = 0;
  }
LABEL_20:
  _qdf_mem_free(v13);
LABEL_21:
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
    *(unsigned __int8 *)(*a1 + 168),
    *a2,
    inited);
  result = wlan_sm_dispatch(a1[9], 3u, 4u, (__int64)(a2 + 1), v26, v27, v28, v29, v30, v31, v32, v33);
  if ( (_DWORD)result )
  {
    v35 = *a2;
    v36 = result;
    cm_connect_handle_event_post_fail((__int64)a1, v35);
    result = v36;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
