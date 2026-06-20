__int64 __fastcall pdr_notifier_new_server(__int64 a1, _DWORD *a2)
{
  _QWORD *i; // x21

  mutex_lock(a1 + 352);
  for ( i = *(_QWORD **)(a1 + 320); i != (_QWORD *)(a1 + 320); i = (_QWORD *)*i )
  {
    if ( *((_DWORD *)i - 5) == *a2 && *((_DWORD *)i - 6) == a2[2] )
    {
      *((_BYTE *)i - 1) = 1;
      *((_BYTE *)i - 4) = 1;
      *((_WORD *)i - 18) = 42;
      *((_DWORD *)i - 8) = a2[3];
      *((_DWORD *)i - 7) = a2[4];
      queue_work_on(32, *(_QWORD *)(a1 + 600), a1 + 536);
    }
  }
  mutex_unlock(a1 + 352);
  return 0;
}
