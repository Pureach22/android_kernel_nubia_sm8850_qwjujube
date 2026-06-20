__int64 __fastcall rpmh_mode_solver_set(__int64 a1, char a2)
{
  __int64 v3; // x20
  unsigned int v5; // w21

  if ( (rpmh_standalone & 1) != 0 )
    return 0;
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( (*(_BYTE *)(v3 + 1160) & 1) == 0 )
    return 4294967274LL;
  raw_spin_lock(v3 + 1152);
  v5 = rpmh_rsc_mode_solver_set(v3, a2 & 1);
  if ( !v5 )
    *(_BYTE *)(v3 + 1157) = a2 & 1;
  raw_spin_unlock(v3 + 1152);
  return v5;
}
