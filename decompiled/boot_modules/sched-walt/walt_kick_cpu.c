__int64 __fastcall walt_kick_cpu(__int64 result)
{
  char *v1; // x10
  unsigned int v8; // w10

  if ( (_DWORD)result != -1 )
  {
    if ( (unsigned int)result >= 0x20 )
      __break(0x5512u);
    else
      v1 = (char *)&runqueues + *((_QWORD *)&_per_cpu_offset + (unsigned int)result);
    _X11 = (unsigned int *)(v1 + 68);
    __asm { PRFM            #0x11, [X11] }
    do
      v8 = __ldxr(_X11);
    while ( __stlxr(v8 | 0xB, _X11) );
    __dmb(0xBu);
    if ( (v8 & 0xB) == 0 )
      return smp_call_function_single_async();
  }
  return result;
}
