__int64 __fastcall wma_mws_coex_tdm_event_handler(
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
  int v31; // w11
  __int64 v32; // x1
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 result; // x0
  const char *v50; // x2
  unsigned int v51; // w1
  _DWORD v52[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v53; // [xsp+18h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_mws_coex_tdm_event_handler", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v12, v13, v14, v15, v16, v17, v18, v19, "wma_mws_coex_tdm_event_handler");
  if ( !a10 )
  {
    v50 = "%s: Invalid MWS coex event";
    v51 = 2;
    goto LABEL_10;
  }
  v28 = (_DWORD *)*a10;
  if ( !v28 || !context || (v29 = (_DWORD *)context[1816]) == nullptr )
  {
    v50 = "%s: NULL mac ptr or HDD callback is null";
    v51 = 8;
LABEL_10:
    qdf_trace_msg(0x36u, v51, v50, v20, v21, v22, v23, v24, v25, v26, v27, "wma_mws_coex_tdm_event_handler");
    result = 4294967274LL;
    goto LABEL_11;
  }
  v30 = v28[2];
  v31 = v28[3];
  v32 = context[1815];
  v52[0] = v28[1];
  v52[1] = v30;
  v52[2] = v31;
  if ( *(v29 - 1) != -1691911006 )
    __break(0x8228u);
  ((void (__fastcall *)(_DWORD *, __int64, __int64))v29)(v52, v32, 3);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev_id = %u tdm_policy_bitmap = %u tdm_sf_bitmap = %u",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wma_mws_coex_tdm_event_handler",
    (unsigned int)v28[1],
    (unsigned int)v28[2],
    (unsigned int)v28[3]);
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v41, v42, v43, v44, v45, v46, v47, v48, "wma_mws_coex_tdm_event_handler");
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
