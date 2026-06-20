__int64 __fastcall cfg_on_psoc_destroy(__int64 a1)
{
  _QWORD *comp_private_obj; // x19
  unsigned int v3; // w0
  __int64 v4; // x8
  unsigned int v5; // w20
  unsigned int v13; // w9
  unsigned int v14; // w9

  qdf_trace_msg(80, 8, "%s: enter", "cfg_on_psoc_destroy");
  comp_private_obj = (_QWORD *)wlan_objmgr_psoc_get_comp_private_obj(a1, 7);
  v3 = wlan_objmgr_psoc_component_obj_detach(a1, 7, comp_private_obj);
  v4 = *comp_private_obj;
  v5 = v3;
  _X10 = (unsigned int *)(*comp_private_obj + 24LL);
  __asm { PRFM            #0x11, [X10] }
  do
  {
    v13 = __ldxr(_X10);
    v14 = v13 - 1;
  }
  while ( __stlxr(v14, _X10) );
  __dmb(0xBu);
  if ( !v14 )
    cfg_store_free(v4);
  _qdf_mem_free(comp_private_obj);
  return v5;
}
