__int64 __fastcall av8l_fast_iova_coherent_public(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x2
  unsigned __int64 *v3; // x8
  unsigned __int64 v4; // x8

  v2 = *(_QWORD *)(a1 + 136);
  if ( v2 > a2
    || (v3 = (unsigned __int64 *)(*(_QWORD *)(a1 + 112) + 8 * ((a2 - (v2 & 0xFFFFFFFFFFE00000LL)) >> 12)),
        (unsigned __int64)v3 >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_11667);
    return 0;
  }
  else
  {
    v4 = *v3;
    if ( (v4 & 0x1C) == 4 )
      return (v4 >> 9) & 1;
    else
      return 0;
  }
}
