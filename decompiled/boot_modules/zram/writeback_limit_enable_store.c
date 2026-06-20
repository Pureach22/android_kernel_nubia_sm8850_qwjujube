__int64 __fastcall writeback_limit_enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 224);
  v8[0] = 0;
  v6 = *(_QWORD *)(v5 + 88);
  if ( (unsigned int)kstrtoull(a3, 10, v8) )
  {
    a4 = -22;
  }
  else
  {
    down_read(v6 + 32);
    raw_spin_lock(v6 + 248);
    *(_BYTE *)(v6 + 252) = v8[0] != 0;
    raw_spin_unlock(v6 + 248);
    up_read(v6 + 32);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
