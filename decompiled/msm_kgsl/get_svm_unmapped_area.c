unsigned __int64 __fastcall get_svm_unmapped_area(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x3
  __int64 v7; // x20
  __int64 v8; // x25
  __int64 v9; // x23
  __int64 v10; // x21
  __int64 v11; // x22
  unsigned __int64 result; // x0
  unsigned __int64 svm_region; // x0
  unsigned __int64 v14; // x24
  unsigned __int64 StatusReg; // x26
  unsigned __int64 *vma_intersection; // x0
  __int64 v17; // x21
  __int64 v18; // x23
  __int64 v19; // x22
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 80);
  if ( BYTE2(v6) <= 0x14u )
  {
    if ( BYTE2(v6) == 20 )
    {
      v7 = 0x100000;
    }
    else if ( BYTE2(v6) <= 0xFu )
    {
      v7 = 4096;
    }
    else
    {
      v7 = 0x10000;
    }
  }
  else
  {
    v7 = 0x200000;
  }
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 8LL);
  v20 = 0;
  v21[0] = 0;
  if ( (a5 & 0x10) != 0 )
  {
    if ( ((v7 - 1) & a3) != 0 )
      result = -22;
    else
      result = ((__int64 (*)(void))set_svm_area)();
  }
  else
  {
    if ( a3 && ((v7 - 1) & a3) == 0 )
    {
      v17 = a1;
      v18 = a2;
      v19 = a5;
      result = ((__int64 (*)(void))set_svm_area)();
      if ( result < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_28;
      a2 = v18;
      a5 = v19;
      a1 = v17;
    }
    v9 = a1;
    v10 = a2;
    v11 = a5;
    if ( (unsigned int)kgsl_mmu_svm_range(*(_QWORD *)(v8 + 64), v21, &v20) )
    {
      result = -34;
    }
    else
    {
      svm_region = kgsl_mmu_find_svm_region(*(_QWORD *)(v8 + 64), v21[0], v20, a4, v7);
      if ( svm_region <= 0xFFFFFFFFFFFFF000LL )
      {
        v14 = svm_region;
        StatusReg = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          vma_intersection = (unsigned __int64 *)find_vma_intersection(*(_QWORD *)(StatusReg + 1672), v14, a4 - 1 + v14);
          if ( vma_intersection )
          {
            v14 = *vma_intersection;
          }
          else
          {
            result = set_svm_area(v9, v10, v14, a4, v11);
            if ( result < 0xFFFFFFFFFFFFF001LL || result == -16 )
              goto LABEL_28;
          }
          v14 = kgsl_mmu_find_svm_region(*(_QWORD *)(v8 + 64), v21[0], v14 - 1, a4, v7);
          result = -12;
          if ( v14 >= 0xFFFFFFFFFFFFF001LL )
            goto LABEL_28;
        }
      }
      result = -12;
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
