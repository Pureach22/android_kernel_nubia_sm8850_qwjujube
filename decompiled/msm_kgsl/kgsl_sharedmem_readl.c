__int64 __fastcall kgsl_sharedmem_readl(__int64 a1, _DWORD *a2, unsigned __int64 a3)
{
  if ( a1 && a2 && *(_QWORD *)(a1 + 8) && (a3 & 3) == 0 )
  {
    if ( *(_QWORD *)(a1 + 40) - 4LL < a3 && (__break(0x800u), *(_QWORD *)(a1 + 40) - 4LL < a3) )
    {
      return 4294967262LL;
    }
    else
    {
      __dsb(0xDu);
      *a2 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + a3);
      return 0;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
}
