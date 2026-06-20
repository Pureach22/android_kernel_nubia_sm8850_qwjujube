__int64 __fastcall qbt_release(__int64 a1, __int64 a2)
{
  void *v2; // x0
  __int64 v4; // x20
  int v5; // w19
  unsigned int v13; // w9
  unsigned int v15; // w9

  if ( !a2 || !a1 || (v4 = *(_QWORD *)(a2 + 32)) == 0 )
  {
    v2 = &unk_9A11;
    goto LABEL_3;
  }
  v5 = *(_DWORD *)(a1 + 76) & 0xFFFFF;
  printk(&unk_9B2A, "qbt_release");
  if ( v5 != 1 )
  {
    if ( !v5 )
    {
      _X8 = (unsigned int *)(v4 + 304);
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( __stxr(v13 + 1, _X8) );
      goto LABEL_11;
    }
    v2 = &unk_9C65;
LABEL_3:
    printk(v2, "qbt_release");
    return 4294967274LL;
  }
  _X8 = (unsigned int *)(v4 + 308);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 + 1, _X8) );
LABEL_11:
  if ( *(_DWORD *)(v4 + 6280) )
  {
    printk(&unk_95CF, "qbt_release");
    pm_relax(*(_QWORD *)(v4 + 288));
    *(_DWORD *)(v4 + 6280) = 0;
  }
  printk(&unk_93A9, "qbt_release");
  return 0;
}
