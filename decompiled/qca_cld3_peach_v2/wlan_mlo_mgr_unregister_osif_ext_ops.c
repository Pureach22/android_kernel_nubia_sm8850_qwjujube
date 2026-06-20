__int64 __fastcall wlan_mlo_mgr_unregister_osif_ext_ops(__int64 a1)
{
  if ( !a1 )
    return 16;
  *(_QWORD *)(a1 + 360) = 0;
  return 0;
}
