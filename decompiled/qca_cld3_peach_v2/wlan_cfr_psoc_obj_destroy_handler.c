__int64 __fastcall wlan_cfr_psoc_obj_destroy_handler(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v3; // x19

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
  {
    v3 = comp_private_obj;
    wlan_objmgr_psoc_component_obj_detach(a1, 0x1Eu, comp_private_obj);
    _qdf_mem_free(v3);
  }
  return 0;
}
