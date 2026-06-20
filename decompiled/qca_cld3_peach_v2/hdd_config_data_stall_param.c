__int64 __fastcall hdd_config_data_stall_param(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w20
  int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1
  _DWORD v25[4]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  result = 0;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a10 + 944);
  if ( v11 )
  {
    v12 = *(_QWORD *)(a10 + 952);
    if ( v12 )
    {
      v13 = *(unsigned __int16 *)(v11 + 4);
      v14 = *(unsigned __int16 *)(v12 + 4);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: tx_no_ack_duration %d, tx_no_ack_threshold %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "hdd_config_data_stall_param",
        *(unsigned __int16 *)(v11 + 4),
        *(unsigned __int16 *)(v12 + 4));
      if ( v13 > 0x2710 || v13 - 1 < 9 || (unsigned int)(v14 - 1) <= 8 )
      {
        v23 = "%s: param invalid";
        v24 = 8;
        goto LABEL_9;
      }
      v25[0] = 244;
      v25[1] = v13;
      v25[2] = 245;
      v25[3] = v14;
      result = wma_send_multi_pdev_vdev_set_params(0, 0, v25, 2);
      if ( (_DWORD)result )
      {
        v23 = "%s: failed to send tx no ack duration and threshold";
        v24 = 2;
LABEL_9:
        qdf_trace_msg(0x33u, v24, v23, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_config_data_stall_param");
        result = 4294967274LL;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
