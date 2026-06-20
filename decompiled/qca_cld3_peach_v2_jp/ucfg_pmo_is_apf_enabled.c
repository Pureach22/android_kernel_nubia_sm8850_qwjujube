__int64 __fastcall ucfg_pmo_is_apf_enabled(__int64 a1)
{
  __int64 comp_private_obj; // x0
  char v2; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( *(_BYTE *)(comp_private_obj + 1) == 1 )
    v2 = *(_BYTE *)(comp_private_obj + 952);
  else
    v2 = 0;
  return v2 & 1;
}
