__int64 __fastcall synx_util_get_fence_entry(__int64 a1, int a2)
{
  __int64 v4; // x8
  __int64 v5; // x10
  int *v6; // x9
  bool v7; // zf
  unsigned int v8; // w21
  __int64 v9; // x9

  raw_spin_lock_bh(*(_QWORD *)(synx_dev + 152) + 2056LL);
  v4 = *(_QWORD *)(synx_dev + 152);
  v5 = *(_QWORD *)(v4 + 8 * ((unsigned __int64)(0x61C8864680B583EBLL * a1) >> 54) + 2064);
  v6 = (int *)(v5 - 16);
  if ( v5 )
    v7 = v5 == 16;
  else
    v7 = 1;
  if ( v7 )
  {
    v8 = 0;
  }
  else
  {
    while ( *((_QWORD *)v6 + 1) != a1 )
    {
      v9 = *((_QWORD *)v6 + 2);
      v8 = 0;
      if ( v9 )
      {
        v6 = (int *)(v9 - 16);
        if ( v6 )
          continue;
      }
      goto LABEL_14;
    }
    if ( !a2 || (v8 = *v6) == 0 )
      v8 = v6[1];
  }
LABEL_14:
  raw_spin_unlock_bh(v4 + 2056);
  return v8;
}
