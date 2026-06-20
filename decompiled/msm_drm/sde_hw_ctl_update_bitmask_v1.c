__int64 __fastcall sde_hw_ctl_update_bitmask_v1(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  unsigned int v4; // w8
  char *v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x11
  int v9; // w9
  int v10; // w9

  v4 = -22;
  if ( !a1 || a2 >= 8 )
    return v4;
  v5 = (char *)&ctl_hw_flush_cfg_tbl_v1 + 24 * a2;
  if ( a3 && *(_DWORD *)v5 > a3 )
  {
    if ( (a4 & 1) != 0 )
    {
      v6 = *((unsigned int *)v5 + 3);
      if ( (unsigned int)v6 <= 7 )
      {
        v7 = (1LL << *(_DWORD *)(*((_QWORD *)v5 + 2) + 4LL * a3)) | *(unsigned int *)(a1 + 4 * v6 + 100);
LABEL_10:
        v8 = a1 + 4LL * (unsigned int)v6;
        v9 = *(_DWORD *)(a1 + 96);
        *(_DWORD *)(v8 + 100) = v7;
        if ( (_DWORD)v7 )
          v10 = v9 | (1LL << *((_DWORD *)v5 + 2));
        else
          v10 = v9 & ~(unsigned int)(1LL << *((_DWORD *)v5 + 2));
        v4 = 0;
        *(_DWORD *)(a1 + 96) = v10;
        return v4;
      }
    }
    else
    {
      v6 = *((unsigned int *)v5 + 3);
      if ( (unsigned int)v6 <= 7 )
      {
        LODWORD(v7) = ~(1 << *(_DWORD *)(*((_QWORD *)v5 + 2) + 4LL * a3)) & *(_DWORD *)(a1 + 4 * v6 + 100);
        goto LABEL_10;
      }
    }
    __break(0x5512u);
    JUMPOUT(0x182A20);
  }
  printk(&unk_23924D, "sde_hw_ctl_update_bitmask_v1");
  return 4294967274LL;
}
