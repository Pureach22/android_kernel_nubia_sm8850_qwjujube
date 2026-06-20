__int64 __fastcall set_svm_area(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, char a5)
{
  __int64 v5; // x10
  __int64 v7; // x0
  __int64 v9; // x22
  __int64 v11; // x19
  unsigned __int64 unmapped_area; // x0
  int v13; // w0
  int v14; // w21
  __int64 v15; // x0
  int v16; // w0
  __int64 v17; // x8
  int v18; // w21
  __int64 v19; // x8
  void (__fastcall *v20)(_QWORD); // x8
  int v21; // w21
  unsigned __int64 v22; // x22
  __int64 v23; // x20
  __int64 v24; // x9
  __int64 v25; // x8
  unsigned __int64 v26; // x10
  __int64 v27; // x11
  __int64 v28; // x12
  unsigned __int64 v29; // x13
  unsigned __int64 v30; // x12

  v5 = *(_QWORD *)(a1 + 32);
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1672);
  v9 = *(_QWORD *)(v5 + 8);
  v11 = a3;
  unmapped_area = mm_get_unmapped_area(v7, a1, a3, a4, 0, a5 & 0x10);
  if ( unmapped_area > 0xFFFFFFFFFFFFF000LL )
    return unmapped_area;
  raw_spin_lock((char *)a2 + 116);
  if ( a2[4] )
  {
    raw_spin_unlock((char *)a2 + 116);
    return -16;
  }
  else
  {
    v13 = kgsl_mmu_set_svm_region(*(_QWORD *)(v9 + 64), v11, a4);
    if ( v13 )
    {
      v14 = v13;
      raw_spin_unlock((char *)a2 + 116);
      return v14;
    }
    else
    {
      a2[4] = v11;
      raw_spin_unlock((char *)a2 + 116);
      v15 = *(_QWORD *)(v9 + 64);
      a2[1] = v15;
      v16 = kgsl_mmu_map(v15, a2 + 1);
      v17 = *(_QWORD *)(v9 + 64);
      if ( v16 )
      {
        v18 = v16;
        if ( v17 )
        {
          v19 = *(_QWORD *)(v17 + 96);
          if ( v19 )
          {
            v20 = *(void (__fastcall **)(_QWORD))(v19 + 80);
            if ( v20 )
            {
              if ( *((_DWORD *)v20 - 1) != 1555154090 )
                __break(0x8228u);
              v20(a2 + 1);
            }
          }
        }
        return v18;
      }
      else
      {
        if ( v17 )
          v21 = *(_DWORD *)(v17 + 24);
        else
          v21 = 0;
        if ( memfree )
        {
          v22 = a2[4];
          v23 = a2[6];
          raw_spin_lock(&memfree_lock);
          v24 = memfree;
          v25 = 0;
          v26 = v23 + v22;
          do
          {
            if ( *(_DWORD *)(v24 + v25) == v21 )
            {
              v27 = v24 + v25;
              v28 = *(_QWORD *)(v24 + v25 + 16);
              if ( v28 )
              {
                v29 = *(_QWORD *)(v27 + 8);
                v30 = v29 + v28;
                if ( v22 > v29 && v30 > v22 )
                {
                  *(_QWORD *)(v27 + 16) = v22 - v29;
                }
                else if ( v22 <= v29 )
                {
                  if ( v26 <= v29 || v26 >= v30 )
                  {
                    if ( v26 >= v30 )
                      *(_QWORD *)(v27 + 16) = 0;
                  }
                  else
                  {
                    *(_QWORD *)(v27 + 8) = v26;
                  }
                }
              }
            }
            v25 += 40;
          }
          while ( v25 != 20480 );
          raw_spin_unlock(&memfree_lock);
        }
      }
    }
  }
  return v11;
}
