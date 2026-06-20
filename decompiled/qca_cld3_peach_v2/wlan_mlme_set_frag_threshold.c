__int64 __fastcall wlan_mlme_set_frag_threshold(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  __int64 v5; // x20
  __int64 psoc_ext_obj_fl; // x0

  context = _cds_get_context(54, "wlan_mlme_set_frag_threshold");
  if ( !context )
    return 4;
  v5 = context;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  *(_DWORD *)(psoc_ext_obj_fl + 3676) = a2;
  wma_update_frag_params(v5, a2);
  return 0;
}
