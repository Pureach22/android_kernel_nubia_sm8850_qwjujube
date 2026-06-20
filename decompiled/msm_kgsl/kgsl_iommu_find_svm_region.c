__int64 __fastcall kgsl_iommu_find_svm_region(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        __int64 a5)
{
  unsigned __int64 v5; // x21
  __int64 v10; // x24
  __int64 v11; // x23
  unsigned __int64 v12; // x22
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x9
  __int64 v17; // x21
  unsigned __int64 v18; // x25
  unsigned __int64 v19; // x9

  v5 = a3;
  if ( a3 <= a2 )
  {
    _warn_printk("Bad search range: 0x%llx-0x%llx", a2, a3);
    __break(0x800u);
    return -22;
  }
  raw_spin_lock(a1);
  rb_last(a1 + 120);
  v10 = a5 - 1;
  v11 = -a5;
  v12 = (v10 + a2) & v11;
  if ( v5 - v12 < a4 )
    goto LABEL_17;
  v13 = rb_last(a1 + 120);
  if ( v13 )
  {
    while ( *(_QWORD *)(v13 - 16) >= v5 )
    {
      v13 = rb_prev(v13);
      if ( !v13 )
        goto LABEL_6;
    }
    while ( 1 )
    {
      v18 = *(_QWORD *)(v13 - 16);
      v19 = *(_QWORD *)(v13 - 8) + v18;
      if ( v19 < v12 )
        break;
      v15 = v5 - a4;
      if ( v5 > a4 )
      {
        v16 = (v19 + v10) & v11;
        if ( v16 < v5 )
        {
          v17 = v15 & v11;
          if ( (v15 & v11) >= v16 )
            goto LABEL_18;
        }
      }
      if ( v18 < v12 )
        goto LABEL_17;
      v13 = rb_prev(v13);
      v5 = v18;
      if ( !v13 )
        goto LABEL_15;
    }
    v18 = v5;
LABEL_15:
    v14 = v18 - a4;
    if ( v18 <= a4 )
      goto LABEL_17;
  }
  else
  {
LABEL_6:
    v14 = v5 - a4;
    if ( v5 <= a4 )
      goto LABEL_17;
  }
  v17 = v14 & v11;
  if ( (v14 & v11) < v12 )
LABEL_17:
    v17 = -12;
LABEL_18:
  raw_spin_unlock(a1);
  return v17;
}
