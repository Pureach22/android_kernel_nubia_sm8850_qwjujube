__int64 __fastcall cfr_enh_deinit_pdev(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x8
  unsigned int (__fastcall *v24)(__int64, __int64); // x8
  const char *v25; // x2
  const char *v26; // x3
  __int64 v27; // x8
  _QWORD *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  unsigned int v38; // w20
  _QWORD *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a2, 0x1Eu);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: pcfr is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "cfr_enh_deinit_pdev");
    return 29;
  }
  v13 = comp_private_obj;
  if ( *(_BYTE *)(comp_private_obj + 1384) )
  {
    timer_delete((timer_t)(comp_private_obj + 1328));
    timer_delete_sync(v13 + 1328);
    *(_BYTE *)(v13 + 1384) = 0;
  }
  *(_QWORD *)(v13 + 1320) = 0;
  *(_QWORD *)(v13 + 1432) = 0;
  *(_QWORD *)(v13 + 96) = 0;
  *(_QWORD *)(v13 + 104) = 0;
  *(_QWORD *)(v13 + 112) = 0;
  *(_QWORD *)(v13 + 120) = 0;
  *(_QWORD *)(v13 + 128) = 0;
  *(_QWORD *)(v13 + 136) = 0;
  *(_QWORD *)(v13 + 144) = 0;
  *(_QWORD *)(v13 + 1392) = 0;
  *(_QWORD *)(v13 + 1400) = 0;
  *(_QWORD *)(v13 + 1408) = 0;
  *(_QWORD *)(v13 + 1416) = 0;
  qdf_mem_set((void *)(v13 + 152), 0x260u, 0);
  qdf_mem_set((void *)(v13 + 760), 0x230u, 0);
  *(_BYTE *)(v13 + 9) = 0;
  v22 = *(_QWORD *)(a2 + 80);
  if ( !v22 || (v23 = *(_QWORD *)(v22 + 2128)) == 0 )
  {
    v25 = "%s: tx_ops is NULL";
    v26 = "target_if_unregister_to_dbr_enh";
    goto LABEL_12;
  }
  v24 = *(unsigned int (__fastcall **)(__int64, __int64))(v23 + 1768);
  if ( v24 )
  {
    if ( *((_DWORD *)v24 - 1) != 1845289881 )
      __break(0x8228u);
    if ( v24(a2, 1) )
    {
      v25 = "%s: Failed to register with dbr";
      v26 = "cfr_enh_deinit_pdev";
LABEL_12:
      qdf_trace_msg(0x6Au, 2u, v25, v14, v15, v16, v17, v18, v19, v20, v21, v26);
    }
  }
  if ( !a1 )
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Unable to get wmi handle",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_unregister_tx_completion_enh_event_handler");
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Failed to register with dbr",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "cfr_enh_deinit_pdev");
    goto LABEL_26;
  }
  v27 = *(_QWORD *)(a1 + 2800);
  if ( v27 && (v28 = *(_QWORD **)(v27 + 16)) != nullptr )
  {
    if ( !(unsigned int)wmi_unified_unregister_event(v28, 0xD1u, v14, v15, v16, v17, v18, v19, v20, v21) )
    {
      v37 = *(_QWORD *)(a1 + 2800);
      if ( !v37 )
        goto LABEL_26;
      goto LABEL_22;
    }
  }
  else
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Unable to get wmi handle",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_unregister_tx_completion_enh_event_handler");
  }
  qdf_trace_msg(
    0x6Au,
    2u,
    "%s: Failed to register with dbr",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "cfr_enh_deinit_pdev");
  v37 = *(_QWORD *)(a1 + 2800);
  if ( !v37 )
  {
LABEL_26:
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Unable to get wmi handle",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "target_if_unregister_phase_delta_for_rcc_event_handler");
    v38 = 29;
    goto LABEL_27;
  }
LABEL_22:
  v39 = *(_QWORD **)(v37 + 16);
  if ( !v39 )
    goto LABEL_26;
  v38 = wmi_unified_unregister_event(v39, 0xF4u, v29, v30, v31, v32, v33, v34, v35, v36);
  if ( v38 )
LABEL_27:
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: Failed to unregister phase delta handler",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "cfr_enh_deinit_pdev");
  if ( *(_BYTE *)(v13 + 1720) == 1 )
    *(_BYTE *)(v13 + 1720) = 0;
  return v38;
}
