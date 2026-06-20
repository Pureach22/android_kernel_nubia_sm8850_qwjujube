size_t __fastcall extract_roam_sync_frame_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned int *a12)
{
  _DWORD *v12; // x19
  unsigned int v13; // w8
  size_t result; // x0
  const char *v15; // x2
  unsigned int v16; // w4
  unsigned int v17; // w6
  unsigned int v18; // w9
  int v19; // w8
  const char *v22; // x5
  size_t v23; // x0
  void *v24; // x0
  const void *v25; // x1
  size_t v26; // x2
  __int64 v27; // x10
  size_t v28; // x0
  void *v29; // x0
  void *v30; // x0

  if ( !a10 )
  {
    v15 = "%s: Event param null";
LABEL_7:
    qdf_trace_msg(0x31u, 2u, v15, a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_sync_frame_event_tlv");
    return 29;
  }
  v12 = *(_DWORD **)a10;
  if ( !*(_QWORD *)a10 )
  {
    v15 = "%s: received null event data from target";
    goto LABEL_7;
  }
  v13 = v12[1];
  if ( v13 >= 6 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: received invalid vdev_id %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_sync_frame_event_tlv",
      v13);
    return 16;
  }
  v16 = v12[4];
  v17 = v12[6];
  if ( v16 > *(_DWORD *)(a10 + 24)
    || v17 > *(_DWORD *)(a10 + 56)
    || (v18 = v12[5], v18 - 1 < 0x17)
    || v17 - 1 < 0x17
    || v16 - 1 < 0x17
    || v18 > *(_DWORD *)(a10 + 40) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: fixed/actual len err: bcn:%d/%d req:%d/%d rsp:%d/%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_roam_sync_frame_event_tlv",
      v12[5],
      *(_DWORD *)(a10 + 40));
    return 16;
  }
  *((_BYTE *)a12 + 64) = v13;
  v19 = v12[7];
  if ( !(_BYTE)v19 )
    LOBYTE(v19) = -80;
  *((_BYTE *)a12 + 65) = v19;
  if ( v12[5] )
    v22 = "Assoc";
  else
    v22 = "Link";
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: synch frame payload: vdev %d LEN %s bcn:%d, req:%d, rsp:%d RSSI: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "extract_roam_sync_frame_event_tlv",
    (unsigned int)v12[1],
    v22,
    (unsigned int)v12[4],
    (unsigned int)v12[6],
    v12[5],
    v12[7]);
  v23 = (unsigned int)v12[4];
  if ( (_DWORD)v23 )
  {
    if ( v12[5] )
    {
      *a12 = v23;
      *((_BYTE *)a12 + 16) = v12[3];
      v24 = (void *)_qdf_mem_malloc(v23, "extract_roam_sync_frame_event_tlv", 2787);
      *((_QWORD *)a12 + 1) = v24;
      if ( !v24 )
        return 2;
      v25 = *(const void **)(a10 + 16);
      v26 = *a12;
    }
    else
    {
      a12[5] = v23;
      v27 = *((_QWORD *)a12 + 3);
      *((_BYTE *)a12 + 32) = v12[3];
      if ( v27 )
      {
        _qdf_mem_free(*((_QWORD *)a12 + 1));
        LODWORD(v23) = a12[5];
      }
      v24 = (void *)_qdf_mem_malloc((unsigned int)v23, "extract_roam_sync_frame_event_tlv", 2805);
      *((_QWORD *)a12 + 3) = v24;
      if ( !v24 )
        return 2;
      v25 = *(const void **)(a10 + 16);
      v26 = a12[5];
    }
    qdf_mem_copy(v24, v25, v26);
  }
  v28 = (unsigned int)v12[6];
  if ( !(_DWORD)v28 )
    goto LABEL_33;
  a12[9] = v28;
  v29 = (void *)_qdf_mem_malloc(v28, "extract_roam_sync_frame_event_tlv", 2819);
  *((_QWORD *)a12 + 5) = v29;
  if ( !v29 )
    return 2;
  qdf_mem_copy(v29, *(const void **)(a10 + 48), a12[9]);
LABEL_33:
  result = (unsigned int)v12[5];
  if ( (_DWORD)result )
  {
    a12[12] = result;
    v30 = (void *)_qdf_mem_malloc(result, "extract_roam_sync_frame_event_tlv", 2833);
    *((_QWORD *)a12 + 7) = v30;
    if ( v30 )
    {
      qdf_mem_copy(v30, *(const void **)(a10 + 32), a12[12]);
      return 0;
    }
    return 2;
  }
  return result;
}
