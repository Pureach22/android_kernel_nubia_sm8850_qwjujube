__int64 __fastcall pmo_core_apply_lphb(__int64 a1)
{
  __int64 comp_private_obj; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 result; // x0
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
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  result = qdf_trace_msg(0x4Du, 8u, "%s: checking LPHB cache", v3, v4, v5, v6, v7, v8, v9, v10, "pmo_core_apply_lphb");
  if ( !*(_BYTE *)(comp_private_obj + 788) )
  {
LABEL_4:
    if ( !*(_BYTE *)(comp_private_obj + 860) )
      return result;
    goto LABEL_5;
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: LPHB cache for item %d is marked as enable",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "pmo_core_apply_lphb",
    1);
  if ( comp_private_obj != -784 )
  {
    result = pmo_tgt_send_lphb_enable(a1, comp_private_obj + 788);
    goto LABEL_4;
  }
  qdf_trace_msg(
    0x4Du,
    2u,
    "%s: LPHB configuration is NULL",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "pmo_core_send_lphb_enable");
LABEL_5:
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: LPHB cache for item %d is marked as enable",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "pmo_core_apply_lphb",
    2);
  if ( comp_private_obj == -856 )
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: LPHB configuration is NULL",
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             "pmo_core_send_lphb_enable");
  else
    return pmo_tgt_send_lphb_enable(a1, comp_private_obj + 860);
}
