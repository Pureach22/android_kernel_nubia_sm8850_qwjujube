__int64 __fastcall qbt_open(__int64 a1, __int64 a2)
{
  void *v2; // x0
  __int64 v4; // x20
  unsigned int v6; // w8
  unsigned int v7; // w19
  unsigned int v14; // w8
  unsigned int v16; // w8
  unsigned int v19; // w9
  unsigned int v21; // w8

  if ( !a1 || !a2 || (v4 = *(_QWORD *)(a1 + 656)) == 0 )
  {
    v2 = &unk_9A11;
LABEL_3:
    printk(v2, "qbt_open");
    return 4294967274LL;
  }
  if ( (*(_DWORD *)(a1 + 76) & 0xFFFFF) == 0 )
  {
    *(_QWORD *)(a2 + 32) = v4 - 8;
    _X19 = (unsigned int *)(v4 + 296);
    printk(&unk_9B2A, "qbt_open");
    __asm { PRFM            #0x11, [X19] }
    do
    {
      v16 = __ldxr(_X19);
      v6 = v16 - 1;
    }
    while ( __stlxr(v6, _X19) );
    __dmb(0xBu);
    if ( !v6 )
      goto LABEL_13;
    __asm { PRFM            #0x11, [X19] }
    do
      v21 = __ldxr(_X19);
    while ( __stxr(v21 + 1, _X19) );
    goto LABEL_12;
  }
  if ( (*(_DWORD *)(a1 + 76) & 0xFFFFF) != 1 )
  {
    v2 = &unk_9C65;
    goto LABEL_3;
  }
  *(_QWORD *)(a2 + 32) = v4 - 144;
  printk(&unk_9B2A, "qbt_open");
  _X9 = (unsigned int *)(v4 + 164);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v14 = __ldxr(_X9);
    v6 = v14 - 1;
  }
  while ( __stlxr(v6, _X9) );
  __dmb(0xBu);
  if ( !v6 )
    goto LABEL_13;
  _X8 = (unsigned int *)(v4 + 164);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 + 1, _X8) );
LABEL_12:
  v6 = -16;
LABEL_13:
  v7 = v6;
  printk(&unk_943D, "qbt_open");
  return v7;
}
