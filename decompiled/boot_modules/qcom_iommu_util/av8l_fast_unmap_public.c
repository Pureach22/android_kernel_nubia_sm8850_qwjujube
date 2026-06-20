unsigned __int64 __fastcall av8l_fast_unmap_public(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x8
  char *v5; // x21
  unsigned __int64 v6; // x19
  size_t v7; // x22

  v3 = *(_QWORD *)(a1 + 136);
  if ( v3 > a2
    || (v5 = (char *)(*(_QWORD *)(a1 + 112) + 8 * ((a2 - (v3 & 0xFFFFFFFFFFE00000LL)) >> 12)),
        (unsigned __int64)v5 >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_11667);
    return 0;
  }
  else
  {
    v6 = a3;
    v7 = (a3 >> 9) & 0x7FFFFFFFFFFFF8LL;
    memset(v5, 0, v7);
    av8l_clean_range(a1 - 112, v5, &v5[v7]);
  }
  return v6;
}
