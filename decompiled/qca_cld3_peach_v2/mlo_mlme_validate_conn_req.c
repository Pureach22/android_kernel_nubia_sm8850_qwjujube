__int64 __fastcall mlo_mlme_validate_conn_req(__int64 a1)
{
  __int64 mlo_ctx; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  _QWORD *v11; // x8
  __int64 v12; // x21
  __int64 (*v13)(void); // x8

  mlo_ctx = wlan_objmgr_get_mlo_ctx();
  if ( !mlo_ctx )
    return 16;
  v11 = *(_QWORD **)(mlo_ctx + 352);
  if ( !v11 )
    return 16;
  if ( !*v11 )
    return 16;
  v12 = mlo_ctx;
  if ( !wlan_vdev_mlme_get_cmpt_obj(a1, v3, v4, v5, v6, v7, v8, v9, v10) )
    return 16;
  v13 = **(__int64 (***)(void))(v12 + 352);
  if ( *((_DWORD *)v13 - 1) != -1542947251 )
    __break(0x8228u);
  return v13();
}
