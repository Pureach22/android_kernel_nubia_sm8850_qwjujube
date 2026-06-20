__int64 __fastcall scm_rnr_db_flush(__int64 a1)
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
  __int64 v10; // x20
  __int64 i; // x21
  __int64 v12; // x23
  _QWORD *j; // x1
  _QWORD *v14; // x19
  __int64 result; // x0
  _QWORD *v16; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v17[2]; // [xsp+10h] [xbp-10h] BYREF

  v17[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = nullptr;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( !comp_private_obj )
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
    goto LABEL_10;
  }
  v10 = comp_private_obj + 21032;
  if ( comp_private_obj == -21032 )
  {
LABEL_10:
    result = 4;
    goto LABEL_11;
  }
  for ( i = 0; i != 60; ++i )
  {
    v12 = v10 + 48 * i;
    v17[0] = nullptr;
    qdf_list_peek_front((_QWORD *)(v12 + 24), v17);
    for ( j = v17[0]; j; v17[0] = j )
    {
      v16 = nullptr;
      qdf_list_peek_next((_QWORD *)(v12 + 24), j, &v16);
      v14 = v17[0];
      qdf_list_remove_node(v12 + 24, v17[0]);
      _qdf_mem_free((__int64)v14);
      j = v16;
      v16 = nullptr;
    }
    *(_QWORD *)(v12 + 16) = 0;
    *(_DWORD *)(v12 + 4) = 0;
  }
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
