__int64 __fastcall events_show(__int64 a1)
{
  __int64 v2; // x23
  const char *i; // x25
  __int64 *j; // x24
  int v5; // w2
  __int64 v6; // x1
  void (__fastcall *v7)(__int64, __int64, __int64, int *); // x8
  __int64 v8; // x0
  __int64 v9; // x8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  ((void (*)(void))seq_write)();
  seq_write(a1, "--------------\n", 15);
  raw_read_lock(v2 + 13168);
  for ( i = *(const char **)(v2 + 13152); i != (const char *)(v2 + 13152); i = *(const char **)i )
  {
    v11 = 0;
    raw_spin_lock(i - 24);
    seq_printf(a1, "%s: last=%d\n", i + 20, *((_DWORD *)i + 4));
    for ( j = *((__int64 **)i - 2); j != (__int64 *)(i - 16); j = (__int64 *)*j )
    {
      v7 = *((void (__fastcall **)(__int64, __int64, __int64, int *))i + 11);
      v6 = *((_QWORD *)i + 12);
      v8 = *(j - 5);
      if ( *((_DWORD *)v7 - 1) != -362688460 )
        __break(0x8228u);
      v7(v8, v6, 2, &v11);
      v9 = *((_QWORD *)i - 4);
      if ( v9 )
        v5 = *(_DWORD *)(v9 + 4);
      else
        v5 = 0;
      seq_printf(
        a1,
        "\t%u:%u age=%lu func=%ps [retired=%u]\n",
        v5,
        *((_DWORD *)j - 6),
        jiffies - *((unsigned int *)j + 4),
        (const void *)*(j - 2),
        v11);
    }
    raw_spin_unlock(i - 24);
    seq_putc(a1, 10);
  }
  raw_read_unlock(v2 + 13168);
  _ReadStatusReg(SP_EL0);
  return 0;
}
