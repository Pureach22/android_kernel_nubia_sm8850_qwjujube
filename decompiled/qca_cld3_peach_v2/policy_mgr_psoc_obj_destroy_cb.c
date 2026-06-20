__int64 __fastcall policy_mgr_psoc_obj_destroy_cb(__int64 a1)
{
  __int64 context; // x20

  context = policy_mgr_get_context(a1);
  wlan_objmgr_psoc_component_obj_detach(a1, 6u, context);
  _qdf_mem_free(context);
  return 0;
}
