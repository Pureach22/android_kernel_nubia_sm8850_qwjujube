__int64 __fastcall arm_smmu_qcom_tlb_sync(__int64 **a1)
{
  __int64 v2; // x1
  __int64 result; // x0
  __int64 v4; // x20
  __int64 v5; // x20
  void (__fastcall *v6)(_QWORD); // x8
  __int64 **v7; // x0
  __int64 *v8; // x19
  __int64 v9; // x20
  unsigned int v10; // w8
  unsigned int v17; // w10

  v2 = raw_spin_lock_irqsave(a1 + 20);
  if ( *((_BYTE *)a1 + 305) == 1 )
  {
    *((_BYTE *)a1 + 176) = 0;
    return raw_spin_unlock_irqrestore(a1 + 20, v2);
  }
  else
  {
    raw_spin_unlock_irqrestore(a1 + 20, v2);
    v4 = **a1;
    if ( (*(_WORD *)(v4 + 488) & 7) == 0 && (_pm_runtime_resume(**a1, 4) & 0x80000000) != 0 )
    {
      v10 = *(_DWORD *)(v4 + 480);
      do
      {
        if ( !v10 )
          break;
        _X12 = (unsigned int *)(v4 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v17 = __ldxr(_X12);
          if ( v17 != v10 )
            break;
          if ( !__stlxr(v10 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v17 == v10;
        v10 = v17;
      }
      while ( !_ZF );
    }
    v5 = raw_spin_lock_irqsave(a1 + 20);
    if ( (*((_BYTE *)a1 + 305) & 1) == 0 && *((_BYTE *)a1 + 176) == 1 )
    {
      v6 = (void (__fastcall *)(_QWORD))*a1[5];
      if ( *((_DWORD *)v6 - 1) != 251140989 )
        __break(0x8228u);
      v6(a1);
      v7 = (__int64 **)a1[21];
      for ( *((_BYTE *)a1 + 176) = 0; v7; v7 = (__int64 **)a1[21] )
      {
        a1[21] = *v7;
        qcom_io_pgtable_free_page(v7 - 1);
      }
      a1[21] = nullptr;
    }
    result = raw_spin_unlock_irqrestore(a1 + 20, v5);
    v8 = *a1;
    if ( (*(_WORD *)(*v8 + 488) & 7) == 0 )
    {
      v9 = *v8;
      *(_QWORD *)(v9 + 520) = ktime_get_mono_fast_ns(result);
      return _pm_runtime_suspend(*v8, 13);
    }
  }
  return result;
}
