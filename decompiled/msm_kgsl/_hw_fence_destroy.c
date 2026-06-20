__int64 __fastcall hw_fence_destroy(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v9; // x10

  result = synx_release(kgsl_synx, *(unsigned int *)(a1 + 104));
  _X8 = (unsigned __int64 *)(a1 + 48);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 & 0xFFFFFFFF7FFFFFFFLL, _X8) );
  return result;
}
