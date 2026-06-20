__int64 __fastcall wma_mws_coex_state_host_event_handler(
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
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  const char *v52; // x2
  unsigned int v53; // w1
  _DWORD v54[8]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v55; // [xsp+48h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_mws_coex_state_host_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v12, v13, v14, v15, v16, v17, v18, v19, "wma_mws_coex_state_host_event_handler");
  if ( !a10 )
  {
    v52 = "%s: Invalid stats event";
    v53 = 2;
    goto LABEL_10;
  }
  v28 = (_DWORD *)*a10;
  if ( !v28 || !context || (v29 = (_DWORD *)context[1825]) == nullptr )
  {
    v52 = "%s: NULL mac ptr or HDD callback is null";
    v53 = 8;
LABEL_10:
    qdf_trace_msg(0x36u, v53, v52, v20, v21, v22, v23, v24, v25, v26, v27, "wma_mws_coex_state_host_event_handler");
    result = 4294967274LL;
    goto LABEL_11;
  }
  v30 = v28[2];
  v31 = context[1824];
  v54[0] = v28[1];
  v54[1] = v30;
  v32 = v28[4];
  v54[2] = v28[3];
  v54[3] = v32;
  v33 = v28[6];
  v54[4] = v28[5];
  v54[5] = v33;
  v34 = v28[8];
  v54[6] = v28[7];
  v54[7] = v34;
  if ( *(v29 - 1) != -1691911006 )
    __break(0x8228u);
  ((void (__fastcall *)(_DWORD *, __int64, __int64))v29)(v54, v31, 1);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id = %u coex_scheme_bitmap = %u active_conflict_count = %u potential_conflict_count = %u chavd_group0_bitma"
    "p = %u chavd_group1_bitmap = %u chavd_group2_bitmap = %u chavd_group3_bitmap = %u",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "wma_mws_coex_state_host_event_handler",
    (unsigned int)v28[1],
    (unsigned int)v28[2],
    (unsigned int)v28[3],
    (unsigned int)v28[4],
    v28[5],
    v28[6],
    v28[7],
    v28[8]);
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v43, v44, v45, v46, v47, v48, v49, v50, "wma_mws_coex_state_host_event_handler");
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
