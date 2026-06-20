__int64 __fastcall adreno_irq_callbacks(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 result; // x0
  unsigned int v7; // w25
  _DWORD *v8; // x8

  if ( !a3 )
    return 0;
  v3 = a3;
  do
  {
    v7 = __clz(v3) ^ 0x1F;
    v8 = *(_DWORD **)(a2 + 8LL * v7);
    if ( v8 )
    {
      if ( (((unsigned __int64)*(unsigned int *)(a1 + 20888) >> v7) & 1) != 0 )
      {
        if ( *(v8 - 1) != 649645069 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v8)(a1, v7);
      }
    }
    else if ( (unsigned int)__ratelimit(&adreno_irq_callbacks__rs, "adreno_irq_callbacks") )
    {
      dev_crit(*(_QWORD *)a1, "Unhandled interrupt bit %x\n", v7);
    }
    result = 1;
    v3 &= ~(1 << v7);
  }
  while ( v3 );
  return result;
}
