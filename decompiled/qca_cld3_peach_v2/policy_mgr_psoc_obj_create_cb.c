__int64 __fastcall policy_mgr_psoc_obj_create_cb(__int64 a1)
{
  _QWORD *v2; // x0

  v2 = (_QWORD *)_qdf_mem_malloc(0xB50u, "policy_mgr_psoc_obj_create_cb", 52);
  if ( !v2 )
    return 16;
  *v2 = a1;
  v2[187] = 0xFFFF0000FFFFLL;
  wlan_objmgr_psoc_component_obj_attach(a1, 6u, (__int64)v2, 0);
  return 0;
}
