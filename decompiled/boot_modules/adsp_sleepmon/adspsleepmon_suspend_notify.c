__int64 __fastcall adspsleepmon_suspend_notify(__int64 a1, __int64 a2)
{
  if ( a2 != 4 )
    return 0;
  printk(&unk_933D);
  if ( !(_DWORD)qword_A760 || (_DWORD)qword_A760 == HIDWORD(qword_A760) )
  {
    byte_A62B = 1;
    _wake_up(&adspsleepmon_wq, 1, 1, 0);
  }
  return 0;
}
