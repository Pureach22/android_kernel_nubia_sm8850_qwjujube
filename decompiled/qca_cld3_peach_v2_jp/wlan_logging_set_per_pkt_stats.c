__int64 wlan_logging_set_per_pkt_stats()
{
  __int64 result; // x0
  unsigned __int64 v7; // x9

  if ( (_BYTE)word_76E1D8 )
  {
    _X8 = &qword_76E1D0;
    __asm { PRFM            #0x11, [X8] }
    do
      v7 = __ldxr((unsigned __int64 *)&qword_76E1D0);
    while ( __stxr(v7 | 4, (unsigned __int64 *)&qword_76E1D0) );
    return _wake_up(&unk_76E180, 1, 1, 0);
  }
  return result;
}
