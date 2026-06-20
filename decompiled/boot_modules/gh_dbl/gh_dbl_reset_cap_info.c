__int64 __fastcall gh_dbl_reset_cap_info(int a1, int a2, _DWORD *a3)
{
  __int64 v4; // x21
  _QWORD *v5; // x20
  char v7; // w22
  unsigned int v8; // w21
  int v10; // w8
  __int64 v11; // x0

  if ( gh_dbl_initialized != 1 )
    return 4294967285LL;
  if ( (unsigned int)(a1 - 266) <= 0xFFFFFFF5 )
  {
    printk(&unk_77C0, "gh_dbl_reset_cap_info");
    return 4294967274LL;
  }
  if ( !a3 )
    return 4294967274LL;
  v4 = a1 & 0xF;
  if ( (unsigned int)v4 >= 0xB )
  {
    __break(0x5512u);
    goto LABEL_24;
  }
  v5 = &gh_dbl_cap_table[12 * (a1 & 0xF)];
  raw_spin_lock(v5 + 1);
  if ( a2 == 1 )
  {
    if ( (_DWORD)v4 == 10 )
      goto LABEL_24;
    v10 = *((_DWORD *)v5 + 10);
    if ( v10 )
    {
      *a3 = v10;
      v7 = 0;
      v8 = 0;
      *((_DWORD *)v5 + 10) = 0;
      v5[4] = -1;
      goto LABEL_14;
    }
    printk(&unk_78C5, "gh_dbl_reset_cap_info");
    v8 = -6;
LABEL_22:
    v7 = 1;
    goto LABEL_14;
  }
  if ( a2 )
  {
    printk(&unk_787F, "gh_dbl_reset_cap_info");
    v8 = -22;
    goto LABEL_22;
  }
  *a3 = 0;
  if ( ((96 * v4) | 0x10uLL) > 0x3C0 )
  {
LABEL_24:
    __break(1u);
    return gh_dbl_cleanup();
  }
  v7 = 0;
  v8 = 0;
  v5[2] = -1;
LABEL_14:
  raw_spin_unlock(v5 + 1);
  if ( (v7 & 1) == 0 )
  {
    v11 = (unsigned int)*a3;
    if ( (_DWORD)v11 )
      free_irq(v11, v5);
  }
  return v8;
}
