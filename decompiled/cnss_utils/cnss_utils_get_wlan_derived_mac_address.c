__int64 __fastcall cnss_utils_get_wlan_derived_mac_address(__int64 a1, _DWORD *a2)
{
  int v2; // w8
  __int64 result; // x0

  if ( cnss_utils_priv )
  {
    v2 = *(_DWORD *)(cnss_utils_priv + 444);
    if ( v2 )
    {
      result = cnss_utils_priv + 420;
      *a2 = v2;
    }
    else
    {
      printk(&unk_7305, 1);
      *a2 = 0;
      return 0;
    }
  }
  else
  {
    *a2 = 0;
    return 0;
  }
  return result;
}
