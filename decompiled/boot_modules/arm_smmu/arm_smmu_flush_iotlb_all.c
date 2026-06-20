__int64 __fastcall arm_smmu_flush_iotlb_all(__int64 a1)
{
  __int64 v2; // x19
  _QWORD *v3; // x22
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v6; // x21
  __int64 v7; // x21
  void (__fastcall *v8)(_QWORD); // x8
  _QWORD *v9; // x0
  __int64 v10; // x19
  unsigned int v11; // w8
  unsigned int v18; // w10

  v2 = a1 - 184;
  v3 = *(_QWORD **)(a1 - 184);
  v4 = raw_spin_lock_irqsave(a1 - 24);
  if ( *(_BYTE *)(v2 + 305) == 1 )
  {
    *(_BYTE *)(a1 - 8) = 0;
    return raw_spin_unlock_irqrestore(v2 + 160, v4);
  }
  else
  {
    result = raw_spin_unlock_irqrestore(v2 + 160, v4);
    if ( *(_QWORD *)(a1 - 144) )
    {
      v6 = *v3;
      if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 && (_pm_runtime_resume(*v3, 4) & 0x80000000) != 0 )
      {
        v11 = *(_DWORD *)(v6 + 480);
        do
        {
          if ( !v11 )
            break;
          _X12 = (unsigned int *)(v6 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v18 = __ldxr(_X12);
            if ( v18 != v11 )
              break;
            if ( !__stlxr(v11 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v18 == v11;
          v11 = v18;
        }
        while ( !_ZF );
      }
      v7 = raw_spin_lock_irqsave(v2 + 160);
      if ( (*(_BYTE *)(a1 + 121) & 1) == 0 )
      {
        v8 = **(void (__fastcall ***)(_QWORD))(a1 - 144);
        if ( *((_DWORD *)v8 - 1) != 251140989 )
          __break(0x8228u);
        v8(v2);
        v9 = *(_QWORD **)(a1 - 16);
        for ( *(_BYTE *)(a1 - 8) = 0; v9; v9 = *(_QWORD **)(a1 - 16) )
        {
          *(_QWORD *)(a1 - 16) = *v9;
          qcom_io_pgtable_free_page(v9 - 1);
        }
        *(_QWORD *)(a1 - 16) = 0;
      }
      result = raw_spin_unlock_irqrestore(v2 + 160, v7);
      if ( (*(_WORD *)(*v3 + 488LL) & 7) == 0 )
      {
        v10 = *v3;
        *(_QWORD *)(v10 + 520) = ktime_get_mono_fast_ns(result);
        return _pm_runtime_suspend(*v3, 13);
      }
    }
  }
  return result;
}
