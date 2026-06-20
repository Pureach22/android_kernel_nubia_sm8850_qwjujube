__int64 __fastcall htc_dec_return_htt_runtime_cnt(__int64 a1)
{
  unsigned int v7; // w0
  __int64 result; // x0

  _X8 = (unsigned int *)(a1 + 3564);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v7 = __ldxr(_X8);
    result = v7 - 1;
  }
  while ( __stlxr(result, _X8) );
  __dmb(0xBu);
  return result;
}
