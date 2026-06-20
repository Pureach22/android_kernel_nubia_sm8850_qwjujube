__int64 __fastcall hdd_tx_powerboost_deinit(
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
  _QWORD *v10; // x21
  _QWORD *v11; // x23
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  const char *v21; // x2
  unsigned int v22; // w1
  const char *v23; // x2
  unsigned int v24; // w1

  if ( (*(_BYTE *)(a1 + 8464) & 1) != 0 )
  {
    ucfg_reg_txpb_unregister_callback(*(_QWORD *)a1);
    qdf_mutex_acquire(a1 + 8816);
    v10 = *(_QWORD **)(a1 + 8792);
    if ( v10 != (_QWORD *)(a1 + 8792) )
    {
      do
      {
        v11 = (_QWORD *)*v10;
        qdf_list_remove_node(a1 + 8792, v10);
        _qdf_mem_free((__int64)v10);
        v10 = v11;
      }
      while ( v11 != (_QWORD *)(a1 + 8792) );
    }
    qdf_mutex_release(a1 + 8816);
    qdf_mutex_destroy(a1 + 8816);
    if ( *(_DWORD *)(a1 + 8808) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "qdf_list_destroy");
    qdf_runtime_lock_deinit((__int64 *)(a1 + 8784));
    _qdf_wake_lock_destroy(a1 + 8584);
    if ( *(_QWORD *)a1 && (v20 = *(_QWORD *)(*(_QWORD *)a1 + 2120LL)) != 0 )
    {
      if ( !*(_QWORD *)(a1 + 8552) )
      {
LABEL_13:
        v23 = "%s: TPB: deinit done";
        v24 = 8;
        return qdf_trace_msg(0x33u, v24, v23, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tx_powerboost_deinit");
      }
      _qdf_mem_free_consistent(v20, *(_QWORD *)(v20 + 40), *(_DWORD *)(a1 + 8576));
      v21 = "%s: TPB: DMA memory freed";
      v22 = 8;
      *(_DWORD *)(a1 + 8576) = 0;
      *(_QWORD *)(a1 + 8544) = 0;
      *(_QWORD *)(a1 + 8552) = 0;
    }
    else
    {
      v21 = "%s: TPB: Invalid qdf dev";
      v22 = 2;
    }
    qdf_trace_msg(0x33u, v22, v21, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tx_powerboost_deinit_dma");
    goto LABEL_13;
  }
  v23 = "%s: TPB: feature not enabled";
  v24 = 3;
  return qdf_trace_msg(0x33u, v24, v23, a2, a3, a4, a5, a6, a7, a8, a9, "hdd_tx_powerboost_deinit");
}
