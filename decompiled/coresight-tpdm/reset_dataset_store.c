__int64 __fastcall reset_dataset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w8
  __int64 result; // x0
  _QWORD *v9; // x8
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v10[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  v7 = kstrtoull(a3, 0, v10);
  result = -22;
  if ( !v7 && v10[0] == 1 )
  {
    raw_spin_lock(v6 + 24);
    if ( (*(_BYTE *)(v6 + 32) & 2) != 0 )
    {
      memset(*(void **)(v6 + 40), 0, 0x16Cu);
      *(_BYTE *)(*(_QWORD *)(v6 + 40) + 362LL) = 1;
      *(_BYTE *)(*(_QWORD *)(v6 + 40) + 363LL) = 0;
    }
    v9 = *(_QWORD **)(v6 + 48);
    if ( v9 )
    {
      v9[20] = 0;
      v9[21] = 0;
      v9[18] = 0;
      v9[19] = 0;
      v9[16] = 0;
      v9[17] = 0;
      v9[14] = 0;
      v9[15] = 0;
      v9[12] = 0;
      v9[13] = 0;
      v9[10] = 0;
      v9[11] = 0;
      v9[8] = 0;
      v9[9] = 0;
      v9[6] = 0;
      v9[7] = 0;
      v9[4] = 0;
      v9[5] = 0;
      v9[2] = 0;
      v9[3] = 0;
      *v9 = 0;
      v9[1] = 0;
      *(_BYTE *)(*(_QWORD *)(v6 + 48) + 165LL) = 1;
    }
    raw_spin_unlock(v6 + 24);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
