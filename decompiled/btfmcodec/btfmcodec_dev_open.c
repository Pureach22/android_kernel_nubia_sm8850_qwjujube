__int64 __fastcall btfmcodec_dev_open(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned int v5; // w23
  unsigned int v6; // t1
  __int64 v7; // x21
  void *v8; // x0
  void *v10; // x0
  __int64 v11; // x1
  unsigned int v17; // w8

  v2 = *(_QWORD *)(a1 + 656);
  _ReadStatusReg(SP_EL0);
  v6 = *(_DWORD *)(v2 + 136);
  _X19 = v2 + 136;
  v5 = v6;
  v7 = *(_QWORD *)(_X19 + 616);
  if ( (unsigned __int8)log_lvl <= 7u )
    v8 = &unk_D94F;
  else
    v8 = &unk_CE18;
  printk(v8, "btfmcodec_dev_open");
  if ( v5 >= 2 )
  {
    printk(&unk_D87D, "btfmcodec_dev_open");
    return 13;
  }
  *(_QWORD *)(a2 + 32) = v7;
  __asm { PRFM            #0x11, [X19] }
  do
    v17 = __ldxr((unsigned int *)_X19);
  while ( __stxr(v17 + 1, (unsigned int *)_X19) );
  if ( !v17 )
  {
    v11 = 2;
    goto LABEL_18;
  }
  if ( (((v17 + 1) | v17) & 0x80000000) != 0 )
  {
    v11 = 1;
LABEL_18:
    refcount_warn_saturate(_X19, v11);
  }
  if ( (unsigned __int8)log_lvl >= 8u )
    v10 = &unk_D69D;
  else
    v10 = &unk_C259;
  printk(v10, "btfmcodec_dev_open");
  if ( (unsigned int)(*(_DWORD *)(v7 + 964) - 3) <= 1 )
    *(_DWORD *)(v7 + 964) = 0;
  *(_DWORD *)(v7 + 960) = 0;
  return 0;
}
