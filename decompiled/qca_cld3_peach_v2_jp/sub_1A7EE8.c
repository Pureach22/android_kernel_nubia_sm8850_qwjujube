__int64 __fastcall sub_1A7EE8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20

  if ( (v3 & 0x10000000000LL) == 0 )
    JUMPOUT(0x1A71DC);
  return wlan_objmgr_register_pdev_create_handler(a1, a2, a3);
}
