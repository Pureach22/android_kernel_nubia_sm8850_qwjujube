__int64 __fastcall gen8_hwsched_check_context_inflight_hw_fences(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x8
  __int64 v5; // x9
  _QWORD *v6; // x23
  unsigned int v7; // w3
  unsigned int v8; // w10
  unsigned int v9; // w10
  bool v10; // cf
  unsigned int v11; // w10
  unsigned int v12; // w20

  raw_spin_lock(a2 + 404);
  v4 = *(_QWORD **)(a2 + 2072);
  if ( v4 == (_QWORD *)(a2 + 2072) )
  {
LABEL_11:
    v12 = 0;
  }
  else
  {
    while ( 1 )
    {
      v5 = *(_QWORD *)(a2 + 1648);
      v6 = (_QWORD *)*v4;
      v7 = *((_DWORD *)v4 - 10);
      v8 = *(_DWORD *)(v5 + 12);
      if ( v7 != v8 )
      {
        if ( v7 > v8 && ((v7 - v8) & 0x80000000) == 0 )
          break;
        v9 = v8 ^ 0x80000000;
        v10 = (v7 ^ 0x80000000) >= v9;
        v11 = (v7 ^ 0x80000000) - v9;
        if ( v11 != 0 && v10 && v11 <= 0x80000000 )
          break;
      }
      adreno_hwsched_remove_hw_fence_entry(a1, v4 - 8);
      v4 = v6;
      if ( v6 == (_QWORD *)(a2 + 2072) )
        goto LABEL_11;
    }
    dev_err(
      *(_QWORD *)(a1 + 1544) + 16LL,
      "ctx:%d has unsignaled fence ts:%d retired:%d\n",
      *(_DWORD *)(a2 + 4),
      v7,
      *(_DWORD *)(v5 + 12));
    v12 = -22;
  }
  raw_spin_unlock(a2 + 404);
  return v12;
}
