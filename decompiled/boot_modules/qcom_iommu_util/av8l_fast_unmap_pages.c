__int64 __fastcall av8l_fast_unmap_pages(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v4; // x8
  unsigned __int64 v6; // x21
  __int64 v7; // x20
  size_t v8; // x22
  void (__fastcall **v9)(_QWORD); // x8
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x0

  v4 = *(_QWORD *)(a1 + 136);
  if ( v4 > a2
    || (v6 = *(_QWORD *)(a1 + 112) + 8 * ((a2 - (v4 & 0xFFFFFFFFFFE00000LL)) >> 12), v6 >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_11667);
    return 0;
  }
  else
  {
    v7 = a4 * a3;
    v8 = ((unsigned __int64)(a4 * a3) >> 9) & 0x7FFFFFFFFFFFF8LL;
    memset((void *)(*(_QWORD *)(a1 + 112) + 8 * ((a2 - (v4 & 0xFFFFFFFFFFE00000LL)) >> 12)), 0, v8);
    av8l_clean_range(a1 - 112, v6, v6 + v8);
    v9 = *(void (__fastcall ***)(_QWORD))(a1 - 72);
    if ( v9 )
    {
      v10 = *v9;
      if ( v10 )
      {
        v11 = *(_QWORD *)(a1 - 120);
        if ( *((_DWORD *)v10 - 1) != 251140989 )
          __break(0x8228u);
        v10(v11);
      }
    }
  }
  return v7;
}
