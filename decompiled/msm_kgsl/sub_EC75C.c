__int64 __fastcall sub_EC75C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v12; // x7

  __asm { LDLARH          W7, [X27] }
  v12 = _OFF;
  __asm { LDLARH          W7, [X27] }
  return _traceiter_adreno_hw_fence_query(a1, a2, a3, a4, a5, a6, a7, v12);
}
