__int64 __fastcall wma_process_update_beacon_params(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x19
  const char *v11; // x2
  const char *v12; // x3
  unsigned int v13; // w20
  __int64 v14; // x22
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  unsigned int v35; // w21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  if ( !a2 )
  {
    v11 = "%s: bcn_params NULL";
    v12 = "wma_process_update_beacon_params";
    return qdf_trace_msg(0x36u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, v12);
  }
  v10 = (__int64 *)result;
  if ( *(unsigned __int16 *)(result + 162) <= (unsigned int)*(unsigned __int8 *)(a2 + 16) )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid vdev id %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_process_update_beacon_params");
  if ( (*(_WORD *)(a2 + 14) & 1) != 0 )
  {
    v13 = *(unsigned __int16 *)(a2 + 4);
    v14 = a2;
    v15 = *(unsigned __int8 *)(a2 + 16);
    if ( (unsigned int)wma_vdev_set_param(*(_QWORD *)result, v15, 3u, v13, a3, a4, a5, a6, a7, a8, a9, a10) )
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: Failed to update beacon interval",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "wma_update_beacon_interval");
    else
      result = qdf_trace_msg(
                 0x36u,
                 4u,
                 "%s: Updated beacon interval %d for vdev %d",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "wma_update_beacon_interval",
                 v13,
                 v15);
    a2 = v14;
    if ( (*(_WORD *)(v14 + 14) & 0x10) == 0 )
    {
LABEL_5:
      if ( (*(_WORD *)(a2 + 14) & 0x800) == 0 )
        return result;
      goto LABEL_17;
    }
  }
  else if ( (*(_WORD *)(a2 + 14) & 0x10) == 0 )
  {
    goto LABEL_5;
  }
  v24 = a2;
  v25 = *(unsigned __int8 *)(a2 + 7) != 0;
  if ( (unsigned int)wma_vdev_set_param(
                       *v10,
                       *(unsigned __int8 *)(a2 + 16),
                       0x1Au,
                       v25,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10) )
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to send wmi protection mode cmd",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               "wma_update_protection_mode");
  else
    result = qdf_trace_msg(
               0x36u,
               8u,
               "Updated protection mode %d to target",
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v25);
  a2 = v24;
  if ( (*(_WORD *)(v24 + 14) & 0x800) != 0 )
  {
LABEL_17:
    v34 = *(unsigned __int8 *)(a2 + 16);
    v35 = ((*(_DWORD *)(a2 + 20) & 0x3F) << 24) | (*(unsigned __int8 *)(a2 + 24) << 31);
    qdf_trace_msg(
      0x36u,
      8u,
      "vdev: %d, update bss color, HE_OPS: 0x%x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      *(unsigned __int8 *)(a2 + 16),
      v35);
    result = wma_vdev_set_param(*v10, v34, 0x8001u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
    if ( !(_DWORD)result )
      return result;
    v11 = "%s: Failed to update HE operations";
    v12 = "wma_update_bss_color";
    return qdf_trace_msg(0x36u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, v12);
  }
  return result;
}
