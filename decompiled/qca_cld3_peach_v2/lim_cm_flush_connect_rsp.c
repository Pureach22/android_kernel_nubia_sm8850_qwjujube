__int64 __fastcall lim_cm_flush_connect_rsp(__int64 a1)
{
  __int64 v1; // x0

  if ( !a1 )
    return 4;
  v1 = *(_QWORD *)(a1 + 8);
  if ( !v1 )
    return 4;
  wlan_cm_free_connect_rsp(v1);
  return 0;
}
