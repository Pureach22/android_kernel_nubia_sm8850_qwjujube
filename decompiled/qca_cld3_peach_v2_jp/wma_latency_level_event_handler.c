__int64 __fastcall wma_latency_level_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  _QWORD *context; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x19
  unsigned int v21; // w21
  char wlm_multi_client_ll_caps; // w22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  __int64 v32; // x20
  int v33; // w4
  void (__fastcall *v34)(__int64 *, __int64); // x8
  __int64 v35; // x1
  const char *v36; // x2
  __int64 v37; // [xsp+0h] [xbp-10h] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_latency_level_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  v37 = 0;
  if ( !context )
  {
    v36 = "%s: NULL mac handle";
LABEL_14:
    qdf_trace_msg(0x36u, 2u, v36, v12, v13, v14, v15, v16, v17, v18, v19, "wma_latency_level_event_handler", v37);
    result = 4294967274LL;
    goto LABEL_15;
  }
  v20 = context;
  v21 = *(unsigned __int8 *)(context[1] + 5720LL);
  wlm_multi_client_ll_caps = wlan_mlme_get_wlm_multi_client_ll_caps(context[2694]);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: multi client ll INI:%d, caps:%d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wma_latency_level_event_handler",
    v21,
    wlm_multi_client_ll_caps & 1,
    v37,
    v38);
  result = 4294967274LL;
  if ( (wlm_multi_client_ll_caps & 1) == 0 || !v21 )
    goto LABEL_15;
  if ( !v20[1824] )
  {
    v36 = "%s: latency level data handler cb is not registered";
    goto LABEL_14;
  }
  if ( !a10 )
  {
    v36 = "%s: Invalid latency level data Event";
    goto LABEL_14;
  }
  v32 = *a10;
  if ( !v32 )
  {
    v36 = "%s: Invalid fixed param in latency data Event";
    goto LABEL_14;
  }
  v33 = *(_DWORD *)(v32 + 8);
  LOBYTE(v37) = *(_DWORD *)(v32 + 4);
  HIDWORD(v37) = v33;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: received event latency level :%d, vdev_id:%d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_latency_level_event_handler",
    v37);
  v34 = (void (__fastcall *)(__int64 *, __int64))v20[1824];
  v35 = *(unsigned int *)(v32 + 4);
  if ( *((_DWORD *)v34 - 1) != 413935413 )
    __break(0x8228u);
  v34(&v37, v35);
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
