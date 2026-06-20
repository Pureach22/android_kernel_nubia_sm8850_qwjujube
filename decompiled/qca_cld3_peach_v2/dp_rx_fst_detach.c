__int64 __fastcall dp_rx_fst_detach(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned __int64 StatusReg; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  __int64 v30; // x8
  __int64 v31; // x1
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  __int64 v41; // [xsp+0h] [xbp-10h] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[185];
  if ( v10 )
  {
    v11 = a1[30];
    qdf_ssr_driver_dump_unregister_region("dp_fisa_sw_fse_table", a2, a3, a4, a5, a6, a7, a8, a9);
    qdf_ssr_driver_dump_unregister_region("dp_fisa", v12, v13, v14, v15, v16, v17, v18, v19);
    timer_delete_sync(v10 + 96);
    if ( *(_BYTE *)(v10 + 609) != 1 )
    {
      hal_rx_fst_detach(*(_QWORD *)(v11 + 1128), *(_QWORD *)(v10 + 16), *(_QWORD *)(v11 + 24), a1[186]);
LABEL_15:
      dp_context_free_mem(v11, 6u, *(_QWORD *)v10, v21, v22, v23, v24, v25, v26, v27, v28);
      _qdf_mem_free(v10);
      goto LABEL_16;
    }
    v41 = 0;
    cancel_work_sync(v10 + 352);
    flush_work(v10 + 352);
    _flush_workqueue(*(_QWORD *)(v10 + 400));
    destroy_workqueue(*(_QWORD *)(v10 + 400));
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 48);
    }
    else
    {
      raw_spin_lock_bh(v10 + 48);
      *(_QWORD *)(v10 + 56) |= 1uLL;
    }
    while ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v10 + 408), &v41) )
    {
      v29 = v41;
      qdf_list_remove_front((_DWORD *)(v10 + 408), &v41);
      _qdf_mem_free(v29);
    }
    v30 = *(_QWORD *)(v10 + 56);
    if ( (v30 & 1) != 0 )
    {
      *(_QWORD *)(v10 + 56) = v30 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 48);
      if ( !*(_DWORD *)(v10 + 424) )
        goto LABEL_14;
    }
    else
    {
      raw_spin_unlock(v10 + 48);
      if ( !*(_DWORD *)(v10 + 424) )
      {
LABEL_14:
        qdf_event_destroy(v10 + 568, v31);
        goto LABEL_15;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "qdf_list_destroy",
      v41,
      v42);
    goto LABEL_14;
  }
LABEL_16:
  a1[185] = 0;
  result = qdf_trace_msg(0x45u, 8u, "Rx FST detached\n", a2, a3, a4, a5, a6, a7, a8, a9, v41);
  _ReadStatusReg(SP_EL0);
  return result;
}
