__int64 __fastcall wma_mws_coex_antenna_sharing_event_handler(
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
  _DWORD *v29; // x0
  void (*v30)(void); // x8
  __int64 v31; // x19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v49; // x2
  unsigned int v50; // w1

  context = _cds_get_context(53, (__int64)"wma_mws_coex_antenna_sharing_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Enter",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_mws_coex_antenna_sharing_event_handler");
  if ( !a10 )
  {
    v49 = "%s: Invalid stats event";
    v50 = 2;
    goto LABEL_11;
  }
  v28 = (_DWORD *)*a10;
  if ( !v28 || !context || !context[1825] )
  {
    v49 = "%s: NULL mac ptr or HDD callback is null";
    v50 = 8;
LABEL_11:
    qdf_trace_msg(0x36u, v50, v49, v20, v21, v22, v23, v24, v25, v26, v27, "wma_mws_coex_antenna_sharing_event_handler");
    return 4294967274LL;
  }
  v29 = (_DWORD *)_qdf_mem_malloc(0x38u, "wma_mws_coex_antenna_sharing_event_handler", 293);
  if ( !v29 )
    return 4294967284LL;
  *v29 = v28[1];
  v29[1] = v28[2];
  v29[2] = v28[3];
  v29[3] = v28[4];
  v29[4] = v28[5];
  v29[5] = v28[6];
  v29[6] = v28[7];
  v29[7] = v28[8];
  v29[8] = v28[9];
  v29[9] = v28[10];
  v29[10] = v28[11];
  v29[11] = v28[12];
  v29[12] = v28[13];
  v29[13] = v28[14];
  v30 = (void (*)(void))context[1825];
  v31 = (__int64)v29;
  if ( *((_DWORD *)v30 - 1) != -1691911006 )
    __break(0x8228u);
  v30();
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id = %u coex_flags = %u coex_config = %u tx_chain_mask = %u rx_chain_mask = %u rx_nss = %u force_mrc = %u r"
    "ssi_type = %u chain0_rssi = %d chain1_rssi = %d chain0_rssi = %d imbalance = %u mrc_threshold = %d grant_duration = %u",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wma_mws_coex_antenna_sharing_event_handler",
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
    v28[11],
    v28[12],
    v28[13],
    v28[14]);
  _qdf_mem_free(v31);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: EXIT",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wma_mws_coex_antenna_sharing_event_handler");
  return 0;
}
