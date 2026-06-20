__int64 __fastcall drv_stop(__int64 result)
{
  __int64 v1; // x19
  void (*v2)(void); // x8
  unsigned int v9; // w9
  unsigned int v12; // w10

  if ( (*(_BYTE *)(result + 1469) & 1) != 0 )
  {
    v1 = result;
    v2 = *(void (**)(void))(*(_QWORD *)(result + 464) + 16LL);
    if ( *((_DWORD *)v2 - 1) != 301796775 )
      __break(0x8228u);
    v2();
    _X8 = (unsigned int *)(v1 + 1528);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 + 1, _X8) );
    __dmb(0xBu);
    result = tasklet_unlock_wait(v1 + 1512);
    __dmb(0xBu);
    __dmb(0xBu);
    _X8 = (unsigned int *)(v1 + 1528);
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 - 1, _X8) );
    *(_BYTE *)(v1 + 1469) = 0;
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
