__int64 __fastcall wlan_clear_mlo_sta_link_removed_flag(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v8; // x10
  unsigned __int64 v11; // x10
  unsigned __int64 v14; // x10

  if ( result )
  {
    v1 = result;
    result = mlo_is_mld_sta(result);
    if ( (result & 1) != 0 )
    {
      result = mlo_mgr_get_ap_link(v1);
      if ( result )
      {
        _X8 = (unsigned __int64 *)(result + 16);
        __asm { PRFM            #0x11, [X8] }
        do
          v8 = __ldxr(_X8);
        while ( __stxr(v8 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        _X8 = (unsigned __int64 *)(result + 64);
        __asm { PRFM            #0x11, [X8] }
        do
          v11 = __ldxr(_X8);
        while ( __stxr(v11 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        _X8 = (unsigned __int64 *)(result + 112);
        __asm { PRFM            #0x11, [X8] }
        do
          v14 = __ldxr(_X8);
        while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      }
    }
  }
  return result;
}
