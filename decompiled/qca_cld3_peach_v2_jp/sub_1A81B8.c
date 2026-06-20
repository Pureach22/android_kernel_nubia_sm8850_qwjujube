__int64 __fastcall sub_1A81B8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20

  if ( (v3 & 0x10000000000LL) == 0 )
    JUMPOUT(0x1A74AC);
  return wlan_objmgr_register_pdev_destroy_handler(a1, a2, a3);
}
