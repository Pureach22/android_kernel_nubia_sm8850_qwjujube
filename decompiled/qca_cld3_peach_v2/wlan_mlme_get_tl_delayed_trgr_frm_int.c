__int64 __fastcall wlan_mlme_get_tl_delayed_trgr_frm_int(__int64 a1, int *a2)
{
  __int64 result; // x0
  int v4; // w8

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    v4 = *(_DWORD *)(result + 5792);
  else
    v4 = 3000;
  *a2 = v4;
  return result;
}
