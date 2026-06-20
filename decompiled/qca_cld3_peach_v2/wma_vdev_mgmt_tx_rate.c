__int64 __fastcall wma_vdev_mgmt_tx_rate(
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
  unsigned int v19; // w8
  unsigned int v20; // w10
  int v21; // w9

  context = _cds_get_context(53, (__int64)"wma_vdev_mgmt_tx_rate", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    qdf_trace_msg(0x36u, 2u, "%s: Failed to get mac", v11, v12, v13, v14, v15, v16, v17, v18, "wma_vdev_mgmt_tx_rate");
    return 16;
  }
  v19 = *(unsigned __int8 *)(context[1] + 3409LL);
  if ( v19 == 255 )
    goto LABEL_10;
  v20 = v19 >> 6;
  v21 = (v19 >> 4) & 3;
  if ( v19 >> 6 > 1 )
  {
    if ( v20 != 2 )
    {
      if ( (v19 & 0xE) <= 9 && !v21 )
        goto LABEL_14;
      goto LABEL_10;
    }
  }
  else if ( v20 )
  {
    if ( !(v19 & 0xC | v21) )
      goto LABEL_14;
    goto LABEL_10;
  }
  if ( v19 & 8 | v21 )
  {
LABEL_10:
    qdf_trace_msg(0x36u, 8u, "default WNI_CFG_RATE_FOR_TX_MGMT, ignore", v11, v12, v13, v14, v15, v16, v17, v18);
    return 16;
  }
LABEL_14:
  *a1 = 6;
  a1[1] = v19;
  return 0;
}
