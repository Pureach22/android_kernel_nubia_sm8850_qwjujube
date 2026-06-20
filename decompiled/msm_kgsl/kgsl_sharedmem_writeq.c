unsigned __int64 __fastcall kgsl_sharedmem_writeq(unsigned __int64 result, unsigned __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = *(_QWORD *)(result + 8);
    if ( !v3 || (a2 & 7) != 0 || *(_QWORD *)(result + 40) - 8LL < a2 )
    {
      __break(0x800u);
    }
    else
    {
      *(_QWORD *)(v3 + a2) = a3;
      __dsb(0xEu);
    }
  }
  return result;
}
