unsigned __int64 __fastcall kgsl_sharedmem_writel(unsigned __int64 result, unsigned __int64 a2, int a3)
{
  __int64 v3; // x8

  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = *(_QWORD *)(result + 8);
    if ( !v3 || (a2 & 3) != 0 || *(_QWORD *)(result + 40) - 4LL < a2 )
    {
      __break(0x800u);
    }
    else
    {
      *(_DWORD *)(v3 + a2) = a3;
      __dsb(0xEu);
    }
  }
  return result;
}
