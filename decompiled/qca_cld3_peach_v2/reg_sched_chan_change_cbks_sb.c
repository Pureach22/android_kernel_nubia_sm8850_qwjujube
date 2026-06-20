__int64 __fastcall reg_sched_chan_change_cbks_sb(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  double v4; // d0
  unsigned int *v5; // x8
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  v1 = *(_QWORD *)(a1 + 8);
  v2 = *(_QWORD *)v1;
  v3 = *(_QWORD *)(v1 + 8);
  v4 = reg_call_chan_change_cbks(*(_QWORD *)v1, v3, *(unsigned __int8 *)(v1 + 16), v1 + 20);
  wlan_objmgr_pdev_release_ref(v3, 0x15u, v5, v4, v6, v7, v8, v9, v10, v11, v12);
  wlan_objmgr_psoc_release_ref(v2, 0x15u, v13, v14, v15, v16, v17, v18, v19, v20);
  _qdf_mem_free(v1);
  return 0;
}
