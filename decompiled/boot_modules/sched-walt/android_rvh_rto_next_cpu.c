void __fastcall android_rvh_rto_next_cpu(__int64 a1, int a2, _DWORD *a3, int *a4)
{
  unsigned __int64 v4; // x8
  int v5; // w8

  if ( (walt_disabled & 1) == 0
    && ((*(unsigned __int64 *)((char *)&_cpu_halt_mask + (((unsigned __int64)(unsigned int)*a4 >> 3) & 0x1FFFFFF8)) >> *a4)
      & 1) != 0 )
  {
    if ( (unsigned int)(a2 + 1) <= 0x1F
      && (v4 = (unsigned int)(-1LL << ((unsigned __int8)a2 + 1)) & *a3 & (unsigned __int64)~_cpu_halt_mask) != 0 )
    {
      v5 = __clz(__rbit64(v4));
    }
    else
    {
      v5 = 32;
    }
    *a4 = v5;
  }
}
