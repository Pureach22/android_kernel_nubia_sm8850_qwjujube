__int64 __fastcall wma_set_vdev_mgmt_rate(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  _QWORD *v18; // x20
  unsigned int v19; // w9
  unsigned int v20; // w11
  int v21; // w10
  __int64 result; // x0
  int v23; // w21
  unsigned int v24; // w9
  unsigned int v25; // w11
  int v26; // w10
  int v27; // w20
  unsigned int v28; // w8
  _DWORD *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w10
  int v39; // w9
  _QWORD v40[3]; // [xsp+8h] [xbp-18h] BYREF

  v40[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_set_vdev_mgmt_rate", a1, a2, a3, a4, a5, a6, a7, a8);
  v40[0] = 0;
  v40[1] = 0;
  if ( !context )
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to get mac",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "wma_set_vdev_mgmt_rate");
    goto LABEL_29;
  }
  v17 = context[1];
  v18 = context;
  v19 = *(unsigned __int8 *)(v17 + 3409);
  if ( v19 == 255 )
    goto LABEL_10;
  v20 = v19 >> 6;
  v21 = (v19 >> 4) & 3;
  if ( v19 >> 6 > 1 )
  {
    if ( v20 != 2 )
    {
      if ( (v19 & 0xE) <= 9 && !v21 )
        goto LABEL_13;
      goto LABEL_10;
    }
  }
  else if ( v20 )
  {
    if ( !(v19 & 0xC | v21) )
      goto LABEL_13;
LABEL_10:
    qdf_trace_msg(0x36u, 8u, "default WNI_CFG_RATE_FOR_TX_MGMT, ignore", v9, v10, v11, v12, v13, v14, v15, v16);
    v17 = v18[1];
    v23 = 0;
    goto LABEL_14;
  }
  if ( v19 & 8 | v21 )
    goto LABEL_10;
LABEL_13:
  v23 = 1;
  LODWORD(v40[0]) = 6;
  HIDWORD(v40[0]) = v19;
LABEL_14:
  v24 = *(unsigned __int8 *)(v17 + 3410);
  if ( v24 == 255 )
    goto LABEL_21;
  v25 = v24 >> 6;
  v26 = (v24 >> 4) & 3;
  if ( v24 >> 6 > 1 )
  {
    if ( v25 != 2 )
    {
      if ( (v24 & 0xE) <= 9 && !v26 )
        goto LABEL_24;
      goto LABEL_21;
    }
  }
  else if ( v25 )
  {
    if ( !(v24 & 0xC | v26) )
      goto LABEL_24;
LABEL_21:
    qdf_trace_msg(0x36u, 8u, "use default 2G MGMT rate.", v9, v10, v11, v12, v13, v14, v15, v16);
    v17 = v18[1];
    v27 = 0;
    goto LABEL_25;
  }
  if ( v24 & 8 | v26 )
    goto LABEL_21;
LABEL_24:
  v27 = v24 | 0x40000000;
LABEL_25:
  v28 = *(unsigned __int8 *)(v17 + 3409);
  if ( v28 == 255 )
  {
LABEL_26:
    qdf_trace_msg(0x36u, 8u, "use default 5G MGMT rate.", v9, v10, v11, v12, v13, v14, v15, v16);
    goto LABEL_27;
  }
  v38 = v28 >> 6;
  v39 = (v28 >> 4) & 3;
  if ( v28 >> 6 > 1 )
  {
    if ( v38 != 2 )
    {
      if ( (v28 & 0xE) > 9 || v39 )
        goto LABEL_26;
      goto LABEL_38;
    }
  }
  else if ( v38 )
  {
    goto LABEL_26;
  }
  if ( v28 & 8 | v39 )
    goto LABEL_26;
LABEL_38:
  v27 |= (v28 << 12) | 0x80000000;
LABEL_27:
  v29 = &v40[v23];
  *v29 = 111;
  v29[1] = v27;
  result = wma_send_multi_pdev_vdev_set_params(1, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x36u,
               8u,
               "%s: failed to send MGMT_TX_RATE vdev set params stat:%d",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "wma_set_vdev_mgmt_rate",
               (unsigned int)result);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
