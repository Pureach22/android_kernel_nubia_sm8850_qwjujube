__int64 __fastcall rtc6226_search(__int64 a1, char a2)
{
  if ( (a2 & 1) != 0 )
    return queue_delayed_work_on(32, *(_QWORD *)(a1 + 2040), a1 + 2416, 3);
  else
    return rtc6226_cancel_seek(a1);
}
