__int64 __fastcall bcl_get_trend(__int64 a1, __int64 a2, int *a3)
{
  __int64 v3; // x20
  int v5; // w8

  v3 = *(_QWORD *)(a1 + 1048);
  mutex_lock(v3 + 24);
  if ( *(_DWORD *)(v3 + 16) )
    v5 = 1;
  else
    v5 = 2;
  *a3 = v5;
  mutex_unlock(v3 + 24);
  return 0;
}
