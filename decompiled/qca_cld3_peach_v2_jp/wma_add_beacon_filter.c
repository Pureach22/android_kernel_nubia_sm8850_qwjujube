__int64 __fastcall wma_add_beacon_filter(__int64 *a1, unsigned int *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 result; // x0
  __int64 v14; // x21
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x22
  unsigned int v25; // w8
  __int64 v26; // x21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_add_beacon_filter") )
    return 4;
  v12 = *a1;
  if ( (unsigned int)_wmi_validate_handle(*a1, (__int64)"wma_add_beacon_filter", v4, v5, v6, v7, v8, v9, v10, v11) )
    return 4;
  v14 = a1[65] + 488LL * *a2;
  qdf_mem_copy((void *)(v14 + 284), a2, 0x44u);
  *(_BYTE *)(v14 + 352) = 1;
  v15 = wmi_buf_alloc_fl(v12, 0x50u, "wma_add_beacon_filter", 0x441u);
  if ( !v15 )
    return 2;
  v24 = *(_DWORD **)(v15 + 224);
  v25 = *a2;
  *v24 = 7667716;
  v24[1] = v25;
  v24[2] = 1048608;
  v26 = v15;
  v24[3] = a2[1];
  v24[4] = a2[2];
  v24[5] = a2[3];
  v24[6] = a2[4];
  v24[7] = a2[5];
  v24[8] = a2[6];
  v24[9] = a2[7];
  v24[10] = a2[8];
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id %d, Beacon filter ie map:",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wma_add_beacon_filter",
    *a2);
  ((void (__fastcall *)(__int64, __int64, _DWORD *, __int64))qdf_trace_hex_dump)(54, 8, v24 + 3, 32);
  v24[11] = 1048608;
  v24[12] = a2[9];
  v24 += 12;
  v24[1] = a2[10];
  v24[2] = a2[11];
  v24[3] = a2[12];
  v24[4] = a2[13];
  v24[5] = a2[14];
  v24[6] = a2[15];
  v24[7] = a2[16];
  qdf_trace_msg(0x36u, 8u, "%s: ext ie map:", v27, v28, v29, v30, v31, v32, v33, v34, "wma_add_beacon_filter");
  v35 = ((double (__fastcall *)(__int64, __int64, _DWORD *, __int64))qdf_trace_hex_dump)(54, 8, v24, 32);
  result = wmi_unified_cmd_send_fl(
             v12,
             v26,
             0x50u,
             0x12001u,
             "wma_add_beacon_filter",
             0x46Du,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42);
  if ( (_DWORD)result )
  {
    wmi_buf_free();
    return 16;
  }
  return result;
}
