__int64 __fastcall set_type_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
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
  v7 = kstrtoull(a3, 0, v9);
  result = -22;
  if ( !v7 && v9[0] <= 1u )
  {
    raw_spin_lock(v6 + 24);
    *(_BYTE *)(*(_QWORD *)(v6 + 40) + 361LL) = v9[0] != 0;
    raw_spin_unlock(v6 + 24);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
