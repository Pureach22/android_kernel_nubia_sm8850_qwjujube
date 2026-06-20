__int64 __fastcall cfg_on_psoc_create(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x19
  __int64 result; // x0
  unsigned int v11; // w9
  unsigned int v14; // w9
  unsigned int v15; // w9
  unsigned int v16; // w20

  qdf_trace_msg(80, 8, "%s: enter", "cfg_on_psoc_create");
  if ( !_cfg_global_store )
    return 16;
  v2 = (_QWORD *)_qdf_mem_malloc(8, "cfg_on_psoc_create", 817);
  if ( !v2 )
    return 2;
  v3 = v2;
  _X8 = (unsigned int *)(_cfg_global_store + 24);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 + 1, _X8) );
  *v2 = _cfg_global_store;
  result = wlan_objmgr_psoc_component_obj_attach(a1, 7, v2, 0);
  if ( (_DWORD)result )
  {
    _X10 = (unsigned int *)(_cfg_global_store + 24);
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v14 = __ldxr(_X10);
      v15 = v14 - 1;
    }
    while ( __stlxr(v15, _X10) );
    __dmb(0xBu);
    v16 = result;
    if ( !v15 )
      cfg_store_free();
    _qdf_mem_free(v3);
    return v16;
  }
  return result;
}
