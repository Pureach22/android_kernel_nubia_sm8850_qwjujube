__int64 __fastcall sde_dspp_copr_read_status(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x14
  unsigned int v5; // w19
  __int64 v6; // x8
  __int64 (*v7)(void); // x9
  unsigned int v8; // w0

  v5 = -22;
  if ( !a1 || !a2 )
    return v5;
  v6 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v6 < 3 )
  {
    v7 = *(__int64 (**)(void))(a1 + 8 * v6 + 1336);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != 102346528 )
        __break(0x8229u);
      v8 = v7();
      if ( v8 )
      {
        v5 = v8;
        printk(&unk_2403B3, v8);
      }
      else
      {
        return 0;
      }
    }
    else if ( (_DWORD)v6 == 1 )
    {
      return 0;
    }
    else
    {
      return (unsigned int)-22;
    }
    return v5;
  }
  __break(0x5512u);
  *(_QWORD *)(a4 + 32) = v4;
  *(_QWORD *)(a4 + 40) = 4294967274LL;
  return sde_set_mdnie_psr(a1);
}
