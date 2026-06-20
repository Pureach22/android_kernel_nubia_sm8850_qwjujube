__int64 __fastcall scm_channel_list_db_deinit(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x22
  __int64 i; // x23
  __int64 v12; // x25
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *j; // x1
  _QWORD *v22; // x21
  __int64 result; // x0
  _QWORD *v24; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = nullptr;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( comp_private_obj )
  {
    v10 = comp_private_obj + 21032;
    qdf_mutex_destroy(comp_private_obj + 23920);
    for ( i = 0; i != 60; ++i )
    {
      v12 = v10 + 48 * i;
      *(_QWORD *)v12 = 0;
      *(_QWORD *)(v12 + 16) = 0;
      *(_DWORD *)(v12 + 8) = 0;
      v25[0] = nullptr;
      qdf_list_peek_front((_QWORD *)(v12 + 24), v25);
      for ( j = v25[0]; j; v25[0] = j )
      {
        v24 = nullptr;
        qdf_list_peek_next((_QWORD *)(v12 + 24), j, &v24);
        v22 = v25[0];
        qdf_list_remove_node(v12 + 24, v25[0]);
        _qdf_mem_free((__int64)v22);
        j = v24;
        v24 = nullptr;
      }
      if ( *(_DWORD *)(v12 + 40) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: list length not equal to zero",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "qdf_list_destroy");
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wlan_psoc_get_scan_obj_fl",
      "scm_get_rnr_channel_db",
      68);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
