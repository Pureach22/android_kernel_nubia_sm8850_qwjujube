__int64 __fastcall if_mgr_connect_active(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 16;
  if ( (policy_mgr_validate_sta_start() & 1) == 0 )
    return 4;
  if_mgr_disable_roaming(v1, a1, 4);
  return 0;
}
