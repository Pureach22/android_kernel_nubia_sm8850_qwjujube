__int64 __fastcall wma_vdev_mgmt_perband_tx_rate(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  _QWORD *v20; // x20
  unsigned int v21; // w9
  unsigned int v22; // w11
  int v23; // w10
  int v25; // w20
  unsigned int v26; // w8
  unsigned int v27; // w10
  int v28; // w9

  context = _cds_get_context(53, (__int64)"wma_vdev_mgmt_perband_tx_rate", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: failed to get mac",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_vdev_mgmt_perband_tx_rate");
    return 16;
  }
  v19 = context[1];
  v20 = context;
  v21 = *(unsigned __int8 *)(v19 + 3210);
  if ( v21 == 255 )
    goto LABEL_10;
  v22 = v21 >> 6;
  v23 = (v21 >> 4) & 3;
  if ( v21 >> 6 > 1 )
  {
    if ( v22 != 2 )
    {
      if ( (v21 & 0xE) <= 9 && !v23 )
        goto LABEL_13;
      goto LABEL_10;
    }
  }
  else if ( v22 )
  {
    if ( !(v21 & 0xC | v23) )
      goto LABEL_13;
LABEL_10:
    qdf_trace_msg(0x36u, 8u, "use default 2G MGMT rate.", v11, v12, v13, v14, v15, v16, v17, v18);
    v19 = v20[1];
    v25 = 0;
    goto LABEL_14;
  }
  if ( v21 & 8 | v23 )
    goto LABEL_10;
LABEL_13:
  v25 = v21 | 0x40000000;
LABEL_14:
  v26 = *(unsigned __int8 *)(v19 + 3209);
  if ( v26 != 255 )
  {
    v27 = v26 >> 6;
    v28 = (v26 >> 4) & 3;
    if ( v26 >> 6 > 1 )
    {
      if ( v27 != 2 )
      {
        if ( (v26 & 0xE) > 9 || v28 )
          goto LABEL_15;
        goto LABEL_25;
      }
    }
    else if ( v27 )
    {
      goto LABEL_15;
    }
    if ( v26 & 8 | v28 )
      goto LABEL_15;
LABEL_25:
    v25 |= (v26 << 12) | 0x80000000;
    goto LABEL_16;
  }
LABEL_15:
  qdf_trace_msg(0x36u, 8u, "use default 5G MGMT rate.", v11, v12, v13, v14, v15, v16, v17, v18);
LABEL_16:
  *a1 = 111;
  a1[1] = v25;
  return 0;
}
