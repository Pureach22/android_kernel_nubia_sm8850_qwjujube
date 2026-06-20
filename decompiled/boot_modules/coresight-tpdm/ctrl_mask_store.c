__int64 __fastcall ctrl_mask_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w8
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x9
  unsigned __int64 v11; // x8
  __int64 v12; // x9
  int v13; // w11
  int v14; // w8
  int v15; // w10
  int v16; // w8
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v17[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  v7 = kstrtoull(a3, 0, v17);
  result = -22;
  if ( !v7 && v17[0] <= 1u )
  {
    v9 = raw_spin_lock(v6 + 24);
    v10 = *(_QWORD *)(v6 + 40);
    v11 = *(unsigned int *)(v10 + 4);
    if ( (unsigned int)v11 >= 0x100 )
    {
      __break(0x5512u);
      MEMORY[0x711045C](v9);
      JUMPOUT(0x9A04);
    }
    v12 = v10 + ((v11 >> 3) & 0x1FFFFFFC);
    v13 = *(_DWORD *)(v12 + 72);
    v14 = 1 << v11;
    v15 = v13 | v14;
    v16 = v13 & ~v14;
    if ( v17[0] )
      v16 = v15;
    *(_DWORD *)(v12 + 72) = v16;
    raw_spin_unlock(v6 + 24);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
