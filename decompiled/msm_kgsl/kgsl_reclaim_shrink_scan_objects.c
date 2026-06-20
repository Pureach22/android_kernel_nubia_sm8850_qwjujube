__int64 __fastcall kgsl_reclaim_shrink_scan_objects(__int64 a1, __int64 a2)
{
  int v3; // w8

  if ( (*(_BYTE *)(_ReadStatusReg(SP_EL0) + 70) & 2) == 0 )
    return 0;
  v3 = kgsl_nr_to_scan;
  if ( !kgsl_nr_to_scan )
    v3 = *(_DWORD *)(a2 + 8);
  kgsl_nr_to_reclaim = v3;
  queue_work_on(32, qword_3A900, &reclaim_work);
  return kgsl_nr_to_reclaim;
}
