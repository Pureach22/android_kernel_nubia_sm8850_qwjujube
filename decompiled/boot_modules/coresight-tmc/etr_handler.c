__int64 __fastcall etr_handler(__int64 a1, __int64 a2)
{
  int v3; // w8
  unsigned int v11; // w9
  __int64 v12; // x8
  unsigned int v15; // w9

  v3 = *(_DWORD *)(*(_QWORD *)(a2 + 368) + 332LL);
  if ( v3 == 1 )
  {
    _X8 = (unsigned int *)(a2 + 160);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 + 1, _X8) );
    v12 = 168;
    goto LABEL_5;
  }
  if ( v3 == 2 )
  {
    _X8 = (unsigned int *)(a2 + 160);
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 + 1, _X8) );
    v12 = 192;
LABEL_5:
    _wake_up(a2 + v12, 3, 1, 0);
  }
  ++*(_QWORD *)(a2 + 424);
  return 1;
}
