__int64 __fastcall wlan_scan_process_bcn_probe_rx_sync(
        __int64 a1,
        __int64 a2,
        const void *a3,
        int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v14; // w21
  void *v19; // x0
  __int64 v20; // x20
  void *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w8
  unsigned int ref; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  void *v42; // x0

  if ( (unsigned int)(a4 - 7) <= 0xFFFFFFFD )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: frame is not beacon or probe resp",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_scan_process_bcn_probe_rx_sync");
    v14 = 4;
    if ( !a2 )
      return v14;
    goto LABEL_16;
  }
  v19 = qdf_mem_malloc_atomic_fl(0x28u, (__int64)"wlan_scan_process_bcn_probe_rx_sync", 0x157u);
  if ( !v19 )
  {
    v14 = 2;
    if ( !a2 )
      return v14;
LABEL_16:
    _qdf_nbuf_free(a2);
    return v14;
  }
  v20 = (__int64)v19;
  v21 = qdf_mem_malloc_atomic_fl(0x60u, (__int64)"wlan_scan_process_bcn_probe_rx_sync", 0x15Du);
  *(_QWORD *)(v20 + 8) = v21;
  if ( v21 )
  {
    if ( a4 == 5 )
      v30 = 80;
    else
      v30 = 128;
    *(_DWORD *)v20 = v30;
    ref = wlan_objmgr_psoc_try_get_ref(a1, 0xCu, v22, v23, v24, v25, v26, v27, v28, v29);
    if ( !ref )
    {
      v42 = *(void **)(v20 + 8);
      *(_QWORD *)(v20 + 16) = a1;
      *(_QWORD *)(v20 + 32) = a2;
      *(_BYTE *)(v20 + 24) = 1;
      *(_BYTE *)(v20 + 25) = a5 & 1;
      qdf_mem_copy(v42, a3, 0x60u);
      return (unsigned int)_scm_handle_bcn_probe((unsigned int *)v20);
    }
    v14 = ref;
    qdf_trace_msg(
      0x15u,
      4u,
      "%s: unable to get reference",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "wlan_scan_process_bcn_probe_rx_sync");
    v40 = *(_QWORD *)(v20 + 8);
    if ( v40 )
      _qdf_mem_free(v40);
  }
  else
  {
    v14 = 2;
  }
  _qdf_mem_free(v20);
  if ( a2 )
    goto LABEL_16;
  return v14;
}
