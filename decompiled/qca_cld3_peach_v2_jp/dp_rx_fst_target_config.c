__int64 __fastcall dp_rx_fst_target_config(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x21
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x1
  __int64 v21; // x20
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 (*v24)(void); // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w19
  __int64 context; // x0
  __int64 v35; // x1
  __int64 v36; // x8

  _ReadStatusReg(SP_EL0);
  if ( !*(_BYTE *)(a1 + 1497) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: RX FISA feature is disabled",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_fst_target_config");
    LODWORD(v21) = 11;
    goto LABEL_29;
  }
  v9 = *(_QWORD *)(a1 + 1480);
  if ( (*(_BYTE *)(a1 + 1496) & 1) != 0 || *(_QWORD *)(a1 + 1488) )
  {
    v11 = alloc_workqueue("dp_rx_fst_update_wq", 131090, 1);
    *(_QWORD *)(v9 + 400) = v11;
    if ( v11 )
    {
      *(_QWORD *)(v9 + 384) = dp_fisa_rx_fst_update_work;
      *(_QWORD *)(v9 + 392) = v9;
      *(_QWORD *)(v9 + 352) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v9 + 360) = v9 + 360;
      *(_QWORD *)(v9 + 368) = v9 + 360;
      *(_QWORD *)(v9 + 376) = _qdf_defer_func;
      *(_QWORD *)(v9 + 408) = v9 + 408;
      *(_QWORD *)(v9 + 416) = v9 + 408;
      *(_QWORD *)(v9 + 424) = 0x8000000000LL;
      qdf_event_create((_DWORD *)(v9 + 568));
      *(_DWORD *)(v9 + 440) = 0;
      v20 = *(_QWORD *)(v9 + 16);
      *(_QWORD *)(v9 + 448) = 0;
      *(_DWORD *)(v9 + 456) = 0;
      *(_QWORD *)(v9 + 464) = 0;
      *(_DWORD *)(v9 + 472) = 0;
      *(_QWORD *)(v9 + 480) = 0;
      *(_DWORD *)(v9 + 488) = 0;
      *(_QWORD *)(v9 + 496) = 0;
      *(_DWORD *)(v9 + 504) = 0;
      *(_QWORD *)(v9 + 512) = 0;
      *(_DWORD *)(v9 + 520) = 0;
      *(_QWORD *)(v9 + 528) = 0;
      *(_DWORD *)(v9 + 536) = 0;
      *(_QWORD *)(v9 + 544) = 0;
      *(_DWORD *)(v9 + 552) = 0;
      *(_QWORD *)(v9 + 560) = 0;
      hal_rx_fst_detach(*(_QWORD *)(a1 + 256), v20, *(_QWORD *)(a1 + 16), *(_QWORD *)(a1 + 1488));
      *(_QWORD *)(v9 + 16) = 0;
      *(_QWORD *)(v9 + 24) = 0;
      *(_WORD *)(v9 + 608) = 257;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: failed to allocate fst update wq",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_rx_fst_cmem_init");
    }
  }
  if ( *(_QWORD *)(a1 + 1488) )
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: cmem base address 0x%llx",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_flow_send_fst_fw_setup");
  v22 = *(_QWORD *)(a1 + 240);
  if ( v22 && *(_QWORD *)v22 )
  {
    v23 = *(_QWORD *)(*(_QWORD *)v22 + 8LL);
    if ( v23 )
    {
      v24 = *(__int64 (**)(void))(v23 + 240);
      if ( v24 )
      {
        if ( *((_DWORD *)v24 - 1) != -1978174150 )
          __break(0x8228u);
        LODWORD(v21) = v24();
        goto LABEL_19;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_txrx_fisa_config");
  }
  LODWORD(v21) = 16;
LABEL_19:
  if ( *(_BYTE *)(v9 + 609) == 1 && !*(_QWORD *)(a1 + 1488) )
  {
    LODWORD(v21) = qdf_wait_single_event(v9 + 568, 0x7D0u);
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: FST params after CMEM update FT size %d, hash_mask 0x%x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "dp_rx_flow_send_fst_fw_setup",
      *(unsigned __int16 *)(v9 + 32),
      *(unsigned int *)(v9 + 40));
    if ( (_DWORD)v21 )
      goto LABEL_22;
  }
  else if ( (_DWORD)v21 )
  {
LABEL_22:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: dp_rx_flow_send_fst_fw_setup failed %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_fst_target_config",
      (unsigned int)v21);
    goto LABEL_29;
  }
  v21 = *(_QWORD *)(a1 + 1488);
  if ( v21 )
  {
    *(_BYTE *)(a1 + 1496) = 1;
    v33 = *(unsigned __int16 *)(v9 + 32);
    context = dp_get_context();
    v36 = *(_QWORD *)(context + 1480);
    *(_WORD *)(v36 + 32) = v33;
    *(_DWORD *)(v36 + 40) = v33 - 1;
    *(_DWORD *)(v36 + 436) = v21;
    if ( *(_BYTE *)(context + 1496) == 1 && !*(_QWORD *)(context + 1488) )
      qdf_event_set(v36 + 568, v35);
    LODWORD(v21) = 0;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v21;
}
