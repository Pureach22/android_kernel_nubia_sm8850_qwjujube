__int64 __fastcall kgsl_work_period_update(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w9

  raw_spin_lock(a1 + 14080);
  if ( (*(_QWORD *)(a2 + 48) & 1) != 0 )
  {
    v6 = *(_DWORD *)(a2 + 40) + 1;
    *(_QWORD *)(a2 + 32) += a3;
    *(_DWORD *)(a2 + 40) = v6;
  }
  return raw_spin_unlock(a1 + 14080);
}
