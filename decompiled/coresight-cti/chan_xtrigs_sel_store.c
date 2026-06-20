__int64 __fastcall chan_xtrigs_sel_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v8[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtoull(a3, 0, v8) || v8[0] > (unsigned __int64)(*(_DWORD *)(v6 + 64) - 1) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 56);
    *(_BYTE *)(v6 + 129) = v8[0];
    raw_spin_unlock(v6 + 56);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
