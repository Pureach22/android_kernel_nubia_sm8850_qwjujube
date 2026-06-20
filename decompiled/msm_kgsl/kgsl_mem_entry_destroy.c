_QWORD *__fastcall kgsl_mem_entry_destroy(_QWORD *result)
{
  __int64 v1; // x8
  _QWORD *v2; // x19
  int v3; // w20
  __int64 v4; // x9
  __int64 v6; // x8
  unsigned __int64 v9; // x10
  unsigned __int64 v15; // x10

  if ( result )
  {
    v1 = result[10];
    v2 = result;
    v3 = (unsigned __int8)v1 >> 5;
    if ( (v1 & 0x400000000LL) == 0 )
    {
      v4 = result[6];
      _X8 = (unsigned __int64 *)(result[32] + 16LL * ((unsigned __int8)v1 >> 5) + 208);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 - v4, _X8) );
    }
    kgsl_mem_entry_detach_process(result);
    if ( v3 )
    {
      v6 = v2[6];
      _X9 = &qword_3A8E8;
      __asm { PRFM            #0x11, [X9] }
      do
        v9 = __ldxr((unsigned __int64 *)&qword_3A8E8);
      while ( __stxr(v9 - v6, (unsigned __int64 *)&qword_3A8E8) );
    }
    kgsl_sharedmem_free(v2 + 1);
    return (_QWORD *)kfree(v2);
  }
  return result;
}
