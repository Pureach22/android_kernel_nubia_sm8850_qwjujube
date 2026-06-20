__int64 __fastcall btfm_slim_read(__int64 a1, int a2, unsigned __int8 a3)
{
  __int64 v4; // x21
  int v7; // w23
  __int64 v8; // x0
  int v9; // w23
  __int64 v10; // x0

  v4 = a1 + 16;
  v7 = a3;
  mutex_lock(a1 + 1024);
  v8 = v4;
  if ( v7 )
    v8 = *(_QWORD *)(a1 + 8);
  v9 = slim_readb(v8, (unsigned int)(a2 + 2048));
  mutex_unlock(a1 + 1024);
  if ( v9 <= 0 )
  {
    usleep_range_state(5000, 5100, 2);
    mutex_lock(a1 + 1024);
    v10 = v4;
    if ( a3 )
      v10 = *(_QWORD *)(a1 + 8);
    v9 = slim_readb(v10, (unsigned int)(a2 + 2048));
    mutex_unlock(a1 + 1024);
    if ( v9 <= 0 )
    {
      usleep_range_state(5000, 5100, 2);
      mutex_lock(a1 + 1024);
      if ( a3 )
        v4 = *(_QWORD *)(a1 + 8);
      v9 = slim_readb(v4, (unsigned int)(a2 + 2048));
      mutex_unlock(a1 + 1024);
      if ( v9 <= 0 )
        usleep_range_state(5000, 5100, 2);
    }
  }
  return (unsigned int)v9;
}
