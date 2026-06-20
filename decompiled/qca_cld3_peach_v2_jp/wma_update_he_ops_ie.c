__int64 __fastcall wma_update_he_ops_ie(
        __int64 *a1,
        unsigned __int8 a2,
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
  __int64 result; // x0
  unsigned int v23; // w21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w19

  if ( (unsigned int)_wma_validate_handle(
                       (__int64)a1,
                       (__int64)"wma_update_he_ops_ie",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11) )
    return 16;
  v23 = *(_DWORD *)(a3 + 1) & 0xF
      | ((*(_BYTE *)(a3 + 5) & 0x3F) << 24) & 0x3FFFFFFF
      | (*(_DWORD *)(a3 + 1) >> 4) & 0x3FF0
      | (((*(unsigned __int8 *)(a3 + 5) >> 6) & 1) << 30) & 0x7FFFFFFF
      | (*(_BYTE *)(a3 + 5) >> 7 << 31);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id: %d HE_OPs: 0x%x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wma_update_he_ops_ie",
    a2,
    v23);
  result = wma_vdev_set_param(*a1, a2, 0x8003u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
  if ( (_DWORD)result )
  {
    v40 = result;
    qdf_trace_msg(0x36u, 2u, "%s: Failed to set HE OPs", v32, v33, v34, v35, v36, v37, v38, v39, "wma_update_he_ops_ie");
    return v40;
  }
  return result;
}
