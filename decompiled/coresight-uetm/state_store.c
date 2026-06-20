__int64 __fastcall state_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  int v7; // w8
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v9[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  v7 = kstrtoull(a3, 16, v9);
  result = -22;
  if ( !v7 && v9[0] <= 3u )
  {
    raw_spin_lock(v6 + 16);
    *(_BYTE *)(v6 + 54) = v9[0];
    raw_spin_unlock(v6 + 16);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
