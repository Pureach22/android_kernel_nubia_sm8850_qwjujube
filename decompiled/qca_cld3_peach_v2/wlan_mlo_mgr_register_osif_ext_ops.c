__int64 __fastcall wlan_mlo_mgr_register_osif_ext_ops(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 16;
  if ( a1 )
  {
    if ( a2 )
    {
      *(_QWORD *)(a1 + 360) = a2;
      return 0;
    }
  }
  return result;
}
