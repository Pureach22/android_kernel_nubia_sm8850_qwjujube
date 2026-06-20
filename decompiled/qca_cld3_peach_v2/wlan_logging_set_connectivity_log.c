__int64 wlan_logging_set_connectivity_log()
{
  __int64 result; // x0
  unsigned __int64 v7; // x9

  if ( (_BYTE)word_826C80 )
  {
    _X8 = &qword_826C78;
    __asm { PRFM            #0x11, [X8] }
    do
      v7 = __ldxr((unsigned __int64 *)&qword_826C78);
    while ( __stxr(v7 | 0x10, (unsigned __int64 *)&qword_826C78) );
    return _wake_up(&unk_826C28, 1, 1, 0);
  }
  return result;
}
