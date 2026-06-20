__int64 __fastcall rtc6226_fops_poll(__int64 a1, void (__fastcall **a2)(_QWORD))
{
  __int64 v4; // x20
  void (__fastcall *v5)(_QWORD); // x8

  v4 = *(_QWORD *)(video_devdata() + 336);
  mutex_lock(v4 + 1872);
  if ( (*(_WORD *)(v4 + 1770) & 0x1000) == 0 )
  {
    *(_WORD *)(v4 + 1770) |= 0x1000u;
    if ( (rtc6226_set_register(v4, 4) & 0x80000000) != 0 )
      *(_WORD *)(v4 + 1770) &= ~0x1000u;
  }
  mutex_unlock(v4 + 1872);
  if ( a2 )
  {
    if ( v4 != -1832 )
    {
      v5 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v5 - 1) != -442429149 )
          __break(0x8228u);
        v5(a1);
        __dmb(0xBu);
      }
    }
  }
  if ( *(_DWORD *)(v4 + 3124) == *(_DWORD *)(v4 + 3128) )
    return 0;
  else
    return 65;
}
