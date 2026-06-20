__int64 __fastcall kgsl_hwunlock(__int64 result)
{
  __dsb(0xEu);
  *(_DWORD *)(result + 4) = 0;
  return result;
}
