__int64 __fastcall kgsl_event_pending(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  _QWORD *i; // x9
  unsigned int v10; // w20

  raw_spin_lock(a2 + 8);
  for ( i = *(_QWORD **)(a2 + 16); i != (_QWORD *)(a2 + 16); i = (_QWORD *)*i )
  {
    if ( *((_DWORD *)i - 6) == a3 && *(i - 2) == a4 && *(i - 1) == a5 )
    {
      v10 = 1;
      goto LABEL_9;
    }
  }
  v10 = 0;
LABEL_9:
  raw_spin_unlock(a2 + 8);
  return v10;
}
