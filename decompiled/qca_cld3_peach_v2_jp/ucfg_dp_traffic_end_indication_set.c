__int64 __fastcall ucfg_dp_traffic_end_indication_set(
        __int64 a1,
        unsigned __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  unsigned __int64 v21; // x9
  __int64 v22; // x5
  __int64 v23; // x6
  unsigned int v24; // w19
  __int64 v25; // x21
  __int64 context; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  _DWORD *v36; // x8
  __int64 v37; // x1
  unsigned int v38; // w19
  const char *v39; // x2
  _BYTE v41[24]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v42; // [xsp+18h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_vdev_priv_obj");
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
LABEL_12:
    v38 = 4;
    v39 = "%s: Unable to get DP link";
LABEL_17:
    qdf_trace_msg(
      0x45u,
      2u,
      v39,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_dp_traffic_end_indication_set",
      *(_OWORD *)v41,
      *(_QWORD *)&v41[16],
      v42);
    goto LABEL_18;
  }
  v20 = *(_QWORD *)(comp_private_obj + 32);
  v21 = a2 >> 8;
  v22 = BYTE1(a2);
  v23 = BYTE2(a2);
  *(_BYTE *)(v20 + 3656) = a2;
  v24 = a2 & 1;
  v25 = comp_private_obj;
  *(_WORD *)(v20 + 3657) = v21;
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: enabled:%u default dscp:%u special dscp:%u",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "ucfg_dp_traffic_end_indication_set",
    v24,
    v22,
    v23);
  context = _cds_get_context(71, "ucfg_dp_traffic_end_indication_set");
  if ( !context || !*(_QWORD *)context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v27, v28, v29, v30, v31, v32, v33, v34, "cdp_txrx_set_vdev_param");
LABEL_15:
    v38 = 0;
LABEL_16:
    v39 = "%s: Failed to set traffic end indication param on DP vdev";
    goto LABEL_17;
  }
  v35 = *(_QWORD *)(*(_QWORD *)context + 8LL);
  if ( !v35 || (v36 = *(_DWORD **)(v35 + 40)) == nullptr )
  {
    qdf_trace_msg(0x89u, 8u, "NULL vdev params callback", v27, v28, v29, v30, v31, v32, v33, v34);
    goto LABEL_15;
  }
  v37 = *(unsigned __int8 *)(v25 + 24);
  v41[0] = v24;
  *(_QWORD *)&v41[1] = 0;
  *(_QWORD *)&v41[9] = 0;
  *(_QWORD *)&v41[16] = 0;
  if ( *(v36 - 1) != -96731432 )
    __break(0x8228u);
  v38 = 0;
  if ( ((unsigned int (__fastcall *)(__int64, __int64, __int64, _BYTE *))v36)(context, v37, 28, v41) )
    goto LABEL_16;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v38;
}
