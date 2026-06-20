__int64 __fastcall send_hw_fence_no_ack(__int64 a1, int *a2)
{
  __int64 result; // x0
  int v5; // w9
  unsigned int v12; // w8
  unsigned int v13; // w8
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned int v21; // w9

  _X9 = (unsigned int *)(a1 + 23208);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v12 = __ldxr(_X9);
    v13 = v12 + 1;
  }
  while ( __stlxr(v13, _X9) );
  __dmb(0xBu);
  *a2 |= (v13 << 20) | 0xC00;
  result = gen7_hfi_cmdq_write(a1, a2, 0x30u);
  if ( !(_DWORD)result )
  {
    _X8 = (unsigned int *)(a1 + 20412);
    v5 = *(_DWORD *)(a1 + 23156) + 1;
    *(_DWORD *)(a1 + 23156) = v5;
    if ( v5 == 20 )
    {
      _X9 = (unsigned __int64 *)(a1 + 23200);
      __asm { PRFM            #0x11, [X9] }
      do
        v16 = __ldxr(_X9);
      while ( __stxr(v16 | 1, _X9) );
      _X9 = (unsigned __int64 *)(a1 + 23200);
      __asm { PRFM            #0x11, [X9] }
      do
        v19 = __ldxr(_X9);
      while ( __stxr(v19 | 2, _X9) );
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 + 1, _X8) );
      mod_timer(a1 + 24688);
      return 0;
    }
  }
  return result;
}
