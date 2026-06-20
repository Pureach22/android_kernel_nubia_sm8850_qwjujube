__int64 __fastcall wlan_pmo_get_go_mode_bus_suspend(__int64 a1)
{
  __int64 comp_private_obj; // x0
  char v2; // w8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( comp_private_obj )
    v2 = *(_BYTE *)(comp_private_obj + 84);
  else
    v2 = 0;
  return v2 & 1;
}
