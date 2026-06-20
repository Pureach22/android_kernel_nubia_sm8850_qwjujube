__int64 __fastcall _wlan_ipa_set_msg_ifname(const char *a1, __int64 a2, __int64 a3)
{
  size_t v5; // x0
  unsigned __int64 v6; // x2
  __int64 v8; // x0

  v5 = strnlen(a1, 0x20u);
  if ( v5 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v5 == 32 )
      v6 = 32;
    else
      v6 = v5 + 1;
    if ( v6 < 0x21 )
      return sized_strscpy(a3, a1, v6);
  }
  v8 = _fortify_panic(7, 32, v6);
  return wlan_ipa_nbuf_cb(v8);
}
