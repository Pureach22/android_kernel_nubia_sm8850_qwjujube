__int64 __fastcall wma_mws_coex_state_dpwb_event_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10)
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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _DWORD *v28; // x20
  _DWORD *v29; // x8
  int v30; // w10
  __int64 v31; // x1
  int v32; // w11
  int v33; // w9
  int v34; // w9
  int v35; // w9
  int v36; // w10
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 result; // x0
  const char *v54; // x2
  unsigned int v55; // w1
  _DWORD v56[11]; // [xsp+3Ch] [xbp-34h] BYREF
  __int64 v57; // [xsp+68h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_mws_coex_state_dpwb_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v12, v13, v14, v15, v16, v17, v18, v19, "wma_mws_coex_state_dpwb_event_handler");
  if ( !a10 )
  {
    v54 = "%s: Invalid coex mws event";
    v55 = 2;
    goto LABEL_10;
  }
  v28 = (_DWORD *)*a10;
  if ( !v28 || !context || (v29 = (_DWORD *)context[1816]) == nullptr )
  {
    v54 = "%s: NULL mac ptr or HDD callback is null";
    v55 = 8;
LABEL_10:
    qdf_trace_msg(0x36u, v55, v54, v20, v21, v22, v23, v24, v25, v26, v27, "wma_mws_coex_state_dpwb_event_handler");
    result = 4294967274LL;
    goto LABEL_11;
  }
  v30 = v28[2];
  v31 = context[1815];
  v56[0] = v28[1];
  v56[1] = v30;
  v32 = v28[4];
  v56[2] = v28[3];
  v56[3] = v32;
  v33 = v28[6];
  v56[4] = v28[5];
  v56[5] = v33;
  v34 = v28[8];
  v56[6] = v28[7];
  v56[7] = v34;
  v36 = v28[9];
  v35 = v28[10];
  v56[10] = v28[11];
  v56[8] = v36;
  v56[9] = v35;
  if ( *(v29 - 1) != -1691911006 )
    __break(0x8228u);
  ((void (__fastcall *)(_DWORD *, __int64, __int64))v29)(v56, v31, 2);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id = %u current_dpwb_state = %d pnp1_value = %d lte_dutycycle = %d sinr_wlan_on = %d sinr_wlan_off = %d ble"
    "r_count = %u block_count = %u wlan_rssi_level = %u wlan_rssi = %d is_tdm_running = %u",
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    "wma_mws_coex_state_dpwb_event_handler",
    (unsigned int)v28[1],
    (unsigned int)v28[2],
    (unsigned int)v28[3],
    (unsigned int)v28[4],
    v28[5],
    v28[6],
    v28[7],
    v28[8],
    v28[9],
    v28[10],
    v28[11]);
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v45, v46, v47, v48, v49, v50, v51, v52, "wma_mws_coex_state_dpwb_event_handler");
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
