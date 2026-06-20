__int64 __fastcall ucfg_mlme_get_channel_bonding_24ghz(__int64 a1, int *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  int v4; // w8
  __int64 result; // x0

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v4 = *(_DWORD *)(psoc_ext_obj_fl + 5620);
    result = 0;
  }
  else
  {
    result = 4;
    v4 = 1;
  }
  *a2 = v4;
  return result;
}
