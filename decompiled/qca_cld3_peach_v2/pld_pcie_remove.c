__int64 __fastcall pld_pcie_remove(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  __int64 global_context; // x0
  __int64 v28; // x20
  _DWORD *v29; // x8
  __int64 v30[2]; // [xsp+0h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  cds_clear_driver_state(1, a2, a3, a4, a5, a6, a7, a8, a9);
  cds_set_driver_state(4, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( (cds_get_driver_state(v18, v19, v20, v21, v22, v23, v24, v25) & 0x200) != 0
    || (result = _osif_psoc_sync_trans_start_wait(a1 + 200, v30, (__int64)"pld_pcie_remove"), !(_DWORD)result) )
  {
    osif_psoc_sync_unregister((__int64 *)(a1 + 200));
    if ( v30[0] )
      osif_psoc_sync_wait_for_ops(v30[0]);
    global_context = pld_get_global_context();
    if ( global_context )
    {
      v28 = global_context;
      v29 = *(_DWORD **)(*(_QWORD *)global_context + 8LL);
      if ( *(v29 - 1) != 258479119 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v29)(a1 + 200, 0);
      pld_del_dev(v28, a1 + 200);
    }
    result = v30[0];
    if ( v30[0] )
    {
      osif_psoc_sync_trans_stop(v30[0]);
      result = osif_psoc_sync_destroy(v30[0]);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
