__int64 __fastcall tpd_set_play_game(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v6; // x9
  __int64 v7; // x2
  void *v9; // x0

  v4 = *(_QWORD *)(a1 + 3072);
  printk(&unk_34878, "tpd_set_play_game", a3);
  if ( v4 )
  {
    v6 = *(_QWORD *)(v4 + 624);
    if ( *(_DWORD *)(v6 + 184) && (*(_BYTE *)(v6 + 188) & 1) != 0 )
      v7 = 0;
    else
      v7 = *(unsigned int *)(*(_QWORD *)v4 + 524LL);
    if ( *(_DWORD *)(v4 + 1404) == 1 )
    {
      if ( *(_DWORD *)(v4 + 1500) == a2 )
      {
        v9 = &unk_32D58;
      }
      else
      {
        *(_DWORD *)(v4 + 1500) = a2;
        if ( (syna_dev_set_play_game((_QWORD *)v4, a2, v7) & 0x80000000) == 0 )
          return *(unsigned int *)(a1 + 16);
        v9 = &unk_34BC7;
      }
    }
    else
    {
      v9 = &unk_3B5E0;
    }
    printk(v9, "tpd_set_play_game", v7);
    return *(unsigned int *)(a1 + 16);
  }
  return 4294967274LL;
}
