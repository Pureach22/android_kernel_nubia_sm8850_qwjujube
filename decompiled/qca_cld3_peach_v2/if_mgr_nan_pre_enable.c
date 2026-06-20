__int64 __fastcall if_mgr_nan_pre_enable(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x8

  v1 = *(_QWORD *)(a1 + 216);
  if ( !v1 )
    return 16;
  v2 = *(_QWORD *)(v1 + 80);
  if ( !v2 )
    return 16;
  ml_nlink_conn_change_notify(v2, *(unsigned __int8 *)(a1 + 168), 21, 0);
  return 0;
}
