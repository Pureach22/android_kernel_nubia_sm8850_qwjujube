__int64 __fastcall hal_attach(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 dev_ba_pmm; // x0
  void *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  void *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  __int64 v34; // x9
  unsigned __int8 v35; // w10
  __int64 v36; // x0
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w9
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  v4 = _qdf_mem_malloc(0x12358u, "hal_attach", 1318);
  if ( !v4 )
  {
    qdf_trace_msg(0x3Fu, 2u, "%s: hal_soc allocation failed", v5, v6, v7, v8, v9, v10, v11, v12, "hal_attach");
    return v4;
  }
  *(_QWORD *)v4 = a1;
  *(_QWORD *)(v4 + 16) = hif_get_dev_ba(a1);
  *(_QWORD *)(v4 + 24) = hif_get_dev_ba_ce(a1);
  *(_QWORD *)(v4 + 32) = hif_get_dev_ba_cmem(a1);
  dev_ba_pmm = hif_get_dev_ba_pmm(a1);
  *(_QWORD *)(v4 + 8) = a2;
  *(_QWORD *)(v4 + 64) = dev_ba_pmm;
  v14 = (void *)_qdf_mem_alloc_consistent(a2, *(_QWORD *)(a2 + 40), 948, v4 + 74024, "hal_attach", 1333);
  v23 = *(_QWORD *)(v4 + 74024);
  *(_QWORD *)(v4 + 74016) = v14;
  if ( !v23 )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: hal->shadow_rdptr_mem_paddr allocation failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hal_attach");
LABEL_18:
    _qdf_mem_free(v4);
    return 0;
  }
  qdf_mem_set(v14, 0x3B4u, 0);
  v24 = (void *)_qdf_mem_alloc_consistent(a2, *(_QWORD *)(a2 + 40), 216, v4 + 74040, "hal_attach", 1346);
  *(_QWORD *)(v4 + 74032) = v24;
  if ( !v24 )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: hal->shadow_wrptr_mem_vaddr allocation failed",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hal_attach");
LABEL_17:
    _qdf_mem_free_consistent(a2, *(_QWORD *)(a2 + 40), 948);
    goto LABEL_18;
  }
  qdf_mem_set(v24, 0xD8u, 0);
  v33 = 0;
  v34 = v4;
  do
  {
    v35 = v33 | 1;
    *(_BYTE *)(v34 + 72) = v33;
    v33 += 2;
    *(_BYTE *)(v34 + 73) = 0;
    *(_WORD *)(v34 + 384) = v35;
    v34 += 624;
  }
  while ( v33 != 236 );
  v36 = *(_QWORD *)v4;
  *(_QWORD *)(v4 + 74240) = 0;
  *(_WORD *)(v4 + 73704) = 236;
  *(_QWORD *)(v4 + 74228) = 0;
  *(_DWORD *)(v4 + 74052) = *(_DWORD *)(hif_get_target_info_handle(v36) + 4);
  *(_DWORD *)(v4 + 74056) = hif_get_soc_version(a1);
  v37 = _qdf_mem_malloc(0x788u, "hal_attach", 1368);
  *(_QWORD *)(v4 + 74392) = v37;
  if ( !v37 )
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: unable to allocable memory for HAL ops",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "hal_attach");
LABEL_16:
    _qdf_mem_free_consistent(a2, *(_QWORD *)(a2 + 40), 216);
    goto LABEL_17;
  }
  v46 = *(_DWORD *)(v4 + 74052);
  *(_BYTE *)(v4 + 74400) = 1;
  if ( v46 == 37 )
  {
    *(_BYTE *)(v4 + 74224) = 1;
    hal_peach_attach(v4);
  }
  *(_QWORD *)(v4 + 74456) = &hal_reg_wr_hist;
  hal_reg_wr_hist = -1;
  _qdf_minidump_log(v4, 74584, (__int64)"hal_soc");
  ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)("hal_soc", v4, 74584);
  *(_DWORD *)(v4 + 74536) = 0;
  *(_QWORD *)(v4 + 74520) = alloc_workqueue("hal_register_write_wq", 131090, 1);
  *(_QWORD *)(v4 + 74504) = hal_reg_write_work;
  *(_QWORD *)(v4 + 74472) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 74512) = v4;
  *(_QWORD *)(v4 + 74480) = v4 + 74480;
  *(_QWORD *)(v4 + 74488) = v4 + 74480;
  *(_QWORD *)(v4 + 74496) = _qdf_defer_func;
  v47 = _qdf_mem_malloc(0x800u, "hal_delayed_reg_write_init", 1132);
  *(_QWORD *)(v4 + 74464) = v47;
  if ( !v47 )
  {
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: unable to allocate memory",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "hal_delayed_reg_write_init");
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: unable to initialize delayed reg write",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "hal_attach");
    qdf_ssr_driver_dump_unregister_region("hal_soc");
    _qdf_minidump_remove(v4, 74584, "hal_soc");
    _qdf_mem_free(*(_QWORD *)(v4 + 74392));
    goto LABEL_16;
  }
  *(_QWORD *)(v4 + 74528) = 0xFFFFFFFFLL;
  hif_rtpm_register(1u, 0);
  return v4;
}
