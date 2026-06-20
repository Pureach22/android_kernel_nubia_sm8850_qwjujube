__int64 __fastcall synx_util_release_fence_entry(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x9
  _QWORD *v4; // x0
  bool v5; // zf
  __int64 v6; // x9
  _QWORD *v7; // x8
  __int64 v8; // x9
  _QWORD *v10; // x20

  raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
  v2 = *(_QWORD *)(synx_dev + 152);
  v3 = *(_QWORD *)(v2 + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * a1) >> 54) + 2064);
  v4 = (_QWORD *)(v3 - 16);
  if ( v3 )
    v5 = v3 == 16;
  else
    v5 = 1;
  if ( !v5 )
  {
    while ( v4[1] != a1 )
    {
      v6 = v4[2];
      if ( v6 )
      {
        v4 = (_QWORD *)(v6 - 16);
        if ( v6 != 16 )
          continue;
      }
      return raw_spin_unlock_bh(v2 + 2056);
    }
    v7 = (_QWORD *)v4[3];
    if ( v7 )
    {
      v8 = v4[2];
      *v7 = v8;
      if ( v8 )
        *(_QWORD *)(v8 + 8) = v7;
      v4[2] = 0;
      v4[3] = 0;
    }
    if ( (synx_debug & 0x80) != 0 )
    {
      v10 = v4;
      printk(&unk_295F8, &unk_25D36, "synx_util_release_fence_entry", 1555, v4, a1);
      v4 = v10;
    }
    kfree(v4);
    v2 = *(_QWORD *)(synx_dev + 152);
  }
  return raw_spin_unlock_bh(v2 + 2056);
}
