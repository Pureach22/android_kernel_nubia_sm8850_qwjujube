__int64 __fastcall kgsl_iommu_set_svm_region(_QWORD *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x20
  __int64 v8; // x8
  _QWORD *v9; // x0
  unsigned __int64 v10; // x9
  unsigned int inserted; // w20

  v3 = a3 + a2;
  if ( a3 + a2 <= a2 || (a1[20] > a2 || v3 > a1[21]) && (a1[18] > a2 || v3 > a1[19]) )
    return 4294967284LL;
  raw_spin_lock(a1);
  v8 = a1[15];
  if ( v8 )
  {
    v9 = a1;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = *(_QWORD *)(v8 - 16);
        if ( v3 > v10 )
          break;
        v8 = *(_QWORD *)(v8 + 16);
        if ( !v8 )
          goto LABEL_13;
      }
      if ( *(_QWORD *)(v8 - 8) + v10 > a2 )
        break;
      v8 = *(_QWORD *)(v8 + 8);
      if ( !v8 )
        goto LABEL_13;
    }
    inserted = -12;
  }
  else
  {
LABEL_13:
    inserted = insert_gpuaddr((__int64)a1, a2, a3);
    v9 = a1;
  }
  raw_spin_unlock(v9);
  return inserted;
}
