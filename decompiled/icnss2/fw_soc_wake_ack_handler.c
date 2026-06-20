__int64 __fastcall fw_soc_wake_ack_handler(__int64 a1, __int64 a2)
{
  unsigned __int64 v9; // x9

  if ( a2 )
  {
    _X8 = (unsigned __int64 *)(a2 + 1832);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 | 0x8000000, _X8) );
    complete(a2 + 5808);
  }
  return 1;
}
