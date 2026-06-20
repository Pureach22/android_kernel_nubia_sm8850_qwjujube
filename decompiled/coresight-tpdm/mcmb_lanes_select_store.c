__int64 __fastcall mcmb_lanes_select_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x21
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v8[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 0, v8) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 24);
    *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v6 + 48) + 168LL) + 1LL) = v8[0];
    if ( v6 != -24 )
      raw_spin_unlock(v6 + 24);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
