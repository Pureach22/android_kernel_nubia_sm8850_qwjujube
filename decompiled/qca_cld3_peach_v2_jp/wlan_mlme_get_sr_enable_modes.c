__int64 __fastcall wlan_mlme_get_sr_enable_modes(__int64 a1, _BYTE *a2)
{
  __int64 result; // x0
  int v4; // w8

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    v4 = *(_DWORD *)(result + 1128);
  else
    LOBYTE(v4) = 1;
  *a2 = v4;
  return result;
}
