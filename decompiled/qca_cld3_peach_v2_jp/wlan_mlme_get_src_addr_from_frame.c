__int64 __fastcall wlan_mlme_get_src_addr_from_frame(__int64 result)
{
  if ( result )
  {
    if ( *(_DWORD *)result >= 0x18u )
      return *(_QWORD *)(result + 8) + 10LL;
    else
      return 0;
  }
  return result;
}
