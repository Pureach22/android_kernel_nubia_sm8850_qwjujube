__int64 __fastcall port_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _DWORD *v6; // x20
  int v7; // w0
  __int64 v8; // x9
  __int64 v9; // x9
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v11[0] = 0;
  v6 = *(_DWORD **)(v5 + 152);
  v7 = kstrtoull(a3, 16, v11);
  if ( v7 )
  {
    a4 = v7;
  }
  else
  {
    raw_spin_lock(v6 + 8);
    v8 = *((_QWORD *)v6 + 3);
    v6[38] = v11[0];
    if ( (unsigned int)*(_QWORD *)(v8 + 968) )
    {
      *(_DWORD *)(*(_QWORD *)v6 + 4016LL) = -978530731;
      __dsb(0xFu);
      *(_DWORD *)(*(_QWORD *)v6 + 3584LL) = v6[38];
      v9 = *(_QWORD *)v6;
      __dsb(0xFu);
      *(_DWORD *)(v9 + 4016) = 0;
    }
    raw_spin_unlock(v6 + 8);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
