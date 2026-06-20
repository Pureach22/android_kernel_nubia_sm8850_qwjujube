__int64 __fastcall cont_brk_time_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  int v6; // w0

  v4 = *(_QWORD *)(a1 + 152);
  v6 = kstrtou8(a3, 0, v4 + 1013);
  if ( v6 < 0 )
    return v6;
  mutex_lock(v4 + 584);
  i2c_w_bytes(v4 - 168, 33, v4 + 1013, 1);
  mutex_unlock(v4 + 584);
  return a4;
}
