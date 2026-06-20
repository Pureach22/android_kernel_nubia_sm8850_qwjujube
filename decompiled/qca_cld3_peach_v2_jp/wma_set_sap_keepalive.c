__int64 __fastcall wma_set_sap_keepalive(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x20
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w9
  __int64 result; // x0
  __int64 v33; // x9
  unsigned int v34; // w8
  unsigned int v35; // w20
  unsigned int v36; // w21
  unsigned int v37; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // [xsp+Ch] [xbp-24h] BYREF
  _DWORD v47[6]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v48; // [xsp+28h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v46 = 0;
  context = _cds_get_context(53, (__int64)"wma_set_sap_keepalive", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 520) + 488LL * a2 + 168) == 3 )
    {
      v21 = context;
      v22 = context[2694];
      v47[0] = 0;
      if ( (unsigned int)cfg_p2p_get_go_link_monitor_period(v22, &v46) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to go monitor period",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wma_get_go_probe_timeout");
        v46 = 10;
      }
      if ( (unsigned int)cfg_p2p_get_go_keepalive_period(v21[2694], v47) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Failed to read go keep alive",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wma_get_go_probe_timeout");
        v31 = 5;
      }
      else
      {
        v31 = v47[0];
      }
      v34 = v46;
      v35 = v46 + v31;
    }
    else
    {
      v33 = context[1];
      v34 = *(_DWORD *)(v33 + 3516);
      v35 = *(_DWORD *)(v33 + 3512) + v34;
      v46 = v34;
    }
    v36 = v34 >> 1;
    v47[0] = 40;
    v47[1] = v34 >> 1;
    v47[2] = 41;
    v47[3] = v34;
    v47[4] = 42;
    v47[5] = v35;
    v37 = wma_send_multi_pdev_vdev_set_params(1, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( v37 )
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: Failed to Set AP MIN/MAX IDLE INACTIVE TIME, MAX UNRESPONSIVE TIME:%d",
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 "wma_set_sap_keepalive",
                 v37);
    else
      result = qdf_trace_msg(
                 0x36u,
                 8u,
                 "%s: vdev_id:%d min_inactive_time: %u max_inactive_time: %u max_unresponsive_time: %u",
                 v38,
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 "wma_set_sap_keepalive",
                 a2,
                 v36,
                 v46,
                 v35);
  }
  else
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: Failed to get mac",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "wma_set_sap_keepalive");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
