__int64 __fastcall wlan_cm_deinit(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x9
  int v5; // w8
  __int64 v6; // x22
  __int64 v7; // x21
  _QWORD *i; // x1
  _QWORD *v9; // x24
  unsigned int v10; // w25
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD *v28; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 504);
  v4 = *(_QWORD *)(v3 + 152);
  v5 = *(_DWORD *)(v3 + 16);
  if ( v4 )
  {
    v6 = *(_QWORD *)(v4 + 80);
    if ( (v5 & 0xFFFFFFFD) != 0 )
      goto LABEL_17;
  }
  else
  {
    v6 = 0;
    if ( (v5 & 0xFFFFFFFD) != 0 )
      goto LABEL_17;
  }
  v7 = *(_QWORD *)(a1 + 496);
  qdf_event_destroy(v7 + 208, a2);
  wlan_scan_unregister_requester(v6, *(unsigned __int16 *)(v7 + 200));
  v28 = nullptr;
  v29[0] = nullptr;
  cm_req_lock_acquire(v7);
  qdf_list_peek_front((_QWORD *)(v7 + 96), v29);
  for ( i = v29[0]; i; v29[0] = i )
  {
    qdf_list_peek_next((_QWORD *)(v7 + 96), i, &v28);
    v9 = v29[0];
    v10 = v29[0][2] & 0xF000000;
    qdf_list_remove_node(v7 + 96, v29[0]);
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: vdev %d cm_id 0x%x: flush prefix %x",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cm_deinit_req_list",
      *(unsigned __int8 *)(*(_QWORD *)v7 + 104LL),
      *((unsigned int *)v9 + 4),
      v10);
    switch ( v10 )
    {
      case 0xF000000u:
        cm_free_roam_req_mem(v9 + 3);
        break;
      case 0xD000000u:
        --*(_BYTE *)(v7 + 184);
        break;
      case 0xC000000u:
        --*(_BYTE *)(v7 + 185);
        cm_free_connect_req_mem(v9 + 3);
        break;
    }
    _qdf_mem_free((__int64)v9);
    i = v28;
    v28 = nullptr;
  }
  cm_req_lock_release(v7);
  qdf_mutex_destroy(v7 + 120);
  if ( *(_DWORD *)(v7 + 112) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: list length not equal to zero",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "qdf_list_destroy");
  cm_sm_destroy(v7);
  mlme_cm_ext_hdl_destroy(v3, *(_QWORD *)(v7 + 248));
  *(_QWORD *)(v7 + 248) = 0;
  _qdf_mem_free(v7);
  *(_QWORD *)(a1 + 496) = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return 0;
}
