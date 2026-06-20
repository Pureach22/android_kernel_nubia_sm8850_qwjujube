__int64 __fastcall wma_rssi_breached_event_handler(
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
  _QWORD *context; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  unsigned int v30; // w21
  char v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  char v40; // w8
  int v41; // w23
  int v42; // w24
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _DWORD *v51; // x8
  __int64 v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 result; // x0
  const char *v62; // x2
  _DWORD v63[2]; // [xsp+8h] [xbp-18h] BYREF
  char v64; // [xsp+10h] [xbp-10h]
  _BYTE v65[7]; // [xsp+11h] [xbp-Fh]
  __int64 v66; // [xsp+18h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)&v65[3] = 0;
  context = _cds_get_context(53, (__int64)"wma_rssi_breached_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  v20 = _cds_get_context(54, (__int64)"wma_rssi_breached_event_handler", v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !context || !v20 )
  {
    v62 = "%s: Invalid mac/wma context";
LABEL_13:
    qdf_trace_msg(0x36u, 2u, v62, v21, v22, v23, v24, v25, v26, v27, v28, "wma_rssi_breached_event_handler");
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( !context[1793] )
  {
    v62 = "%s: Callback not registered";
    goto LABEL_13;
  }
  if ( !a10 )
  {
    v62 = "%s: Invalid rssi breached event";
    goto LABEL_13;
  }
  v29 = *a10;
  v30 = *(_DWORD *)(*a10 + 4);
  v63[0] = *(_DWORD *)(*a10 + 8);
  v63[1] = v30;
  v31 = wmi_service_enabled(*v20, 0xACu, v21, v22, v23, v24, v25, v26, v27, v28);
  v40 = *(_BYTE *)(v29 + 16);
  if ( (v31 & 1) == 0 )
    v40 -= 96;
  v41 = *(_DWORD *)(v29 + 20);
  v42 = *(_DWORD *)(v29 + 24);
  v64 = v40;
  *(_DWORD *)v65 = v41;
  *(_WORD *)&v65[4] = v42;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: req_id: %u vdev_id: %d curr_rssi: %d",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wma_rssi_breached_event_handler",
    v63[0],
    v30,
    (unsigned int)v40);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: curr_bssid: %02x:%02x:%02x:**:**:%02x",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "wma_rssi_breached_event_handler",
    (unsigned __int8)v41,
    BYTE1(v41),
    BYTE2(v41),
    BYTE1(v42));
  v51 = (_DWORD *)context[1793];
  v52 = context[1604];
  if ( *(v51 - 1) != 2131341962 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _DWORD *))v51)(v52, v63);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Invoke HDD rssi breached callback",
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    "wma_rssi_breached_event_handler");
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
