__int64 __fastcall kgsl_trace_gpu_mem_total(__int64 result, __int64 a2)
{
  unsigned __int64 v8; // x3

  _X8 = (unsigned __int64 *)(result + 11136);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stlxr(v8 + a2, _X8) );
  __dmb(0xBu);
  return result;
}
