__int64 __fastcall synx_native_release_core(__int64 a1, int a2)
{
  __int64 v4; // x9
  __int64 v5; // x8
  bool v6; // zf
  __int64 v7; // x22
  unsigned int v8; // w21
  int v9; // w9
  __int64 v10; // x8

  raw_spin_lock_bh(a1 + 264920);
  v4 = *(_QWORD *)(a1 + 8LL * ((unsigned int)(1640531527 * a2) >> 24) + 262872);
  v5 = v4 - 72;
  if ( v4 )
    v6 = v4 == 72;
  else
    v6 = 1;
  if ( v6 )
  {
    v7 = 0;
    v8 = -22;
  }
  else
  {
    v8 = -22;
    while ( 1 )
    {
      if ( *(_DWORD *)(v5 + 28) == a2 )
      {
        v9 = *(_DWORD *)(v5 + 32);
        if ( v9 )
          break;
      }
      v10 = *(_QWORD *)(v5 + 72);
      v7 = 0;
      if ( v10 )
      {
        v5 = v10 - 72;
        if ( v5 )
          continue;
      }
      goto LABEL_13;
    }
    v8 = 0;
    v7 = v5;
    *(_DWORD *)(v5 + 32) = v9 - 1;
  }
LABEL_13:
  raw_spin_unlock_bh(a1 + 264920);
  synx_util_release_handle(v7);
  return v8;
}
