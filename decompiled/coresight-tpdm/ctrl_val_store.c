__int64 __fastcall ctrl_val_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w8
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  unsigned int v11; // w9
  __int64 v12; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v13[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  v7 = kstrtoull(a3, 0, v13);
  result = -22;
  if ( v7 || v13[0] > 2u )
    goto LABEL_5;
  v9 = raw_spin_lock(v6 + 24);
  v10 = *(_QWORD *)(v6 + 40);
  v11 = *(_DWORD *)(v10 + 4);
  if ( v11 < 0x100 )
  {
    *(_DWORD *)(v10 + 4LL * (v11 >> 4) + 8) = *(_DWORD *)(v10 + 4LL * (v11 >> 4) + 8) & ~(3 << (2 * (v11 & 0xF)))
                                            | (LODWORD(v13[0]) << (2 * (v11 & 0xF)));
    raw_spin_unlock(v6 + 24);
    result = a4;
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  v12 = MEMORY[0x7110378](v9);
  return ctrl_mask_store(v12);
}
