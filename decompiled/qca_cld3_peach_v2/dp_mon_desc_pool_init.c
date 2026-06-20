__int64 __fastcall dp_mon_desc_pool_init(unsigned int *a1, int a2)
{
  int *v4; // x19
  unsigned __int64 StatusReg; // x8
  void *v6; // x0
  unsigned int v7; // w10
  unsigned int v8; // w8
  __int64 v9; // x11
  unsigned int v10; // w9
  __int64 v11; // x11
  unsigned int v12; // w9
  __int64 v13; // x10
  __int64 v14; // x8

  a1[6] = 0;
  v4 = (int *)(a1 + 6);
  *((_QWORD *)a1 + 4) = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 6);
  }
  else
  {
    raw_spin_lock_bh(a1 + 6);
    *((_QWORD *)a1 + 4) |= 1uLL;
  }
  v6 = *((void **)a1 + 1);
  *((_WORD *)a1 + 21) = 2048;
  *((_QWORD *)a1 + 2) = v6;
  *a1 = a2 - 1;
  qdf_mem_set(v6, (unsigned int)(32 * (a2 - 1)), 0);
  v7 = *a1;
  if ( *a1 )
  {
    v8 = 0;
    do
    {
      v12 = v7 - 1;
      v13 = *((_QWORD *)a1 + 1);
      if ( v8 == v12 )
      {
        v9 = (int)v8;
        *(_QWORD *)(v13 + 32LL * (int)v8) = 0;
        v10 = v8 + 1;
      }
      else
      {
        v10 = v8 + 1;
        v9 = (int)v8;
        *(_QWORD *)(v13 + 32LL * (int)v8) = v13 + 32LL * (int)(v8 + 1);
      }
      v11 = 32 * v9;
      *(_DWORD *)(*((_QWORD *)a1 + 1) + v11 + 16) &= ~1u;
      *(_DWORD *)(*((_QWORD *)a1 + 1) + v11 + 24) = v8;
      v8 = v10;
      v7 = *a1;
    }
    while ( v10 < *a1 );
  }
  v14 = *((_QWORD *)a1 + 4);
  if ( (v14 & 1) != 0 )
  {
    *((_QWORD *)a1 + 4) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4);
  }
  else
  {
    raw_spin_unlock(v4);
  }
  return 0;
}
