__int64 __fastcall sleepstate_pm_notifier(__int64 a1, __int64 a2)
{
  __int64 v2; // x2
  unsigned __int64 v3; // x9
  unsigned __int64 StatusReg; // x9

  if ( a2 == 4 )
  {
    if ( state_0 )
    {
      *(_DWORD *)(state_0 + 8) = 1;
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      *(_QWORD *)(state_0 + 16) = StatusReg;
      __dsb(0xFu);
    }
    v2 = 4096;
    goto LABEL_8;
  }
  if ( a2 == 3 )
  {
    v2 = 0;
    if ( state_0 )
    {
      *(_DWORD *)(state_0 + 8) = 2;
      __isb(0xFu);
      v3 = _ReadStatusReg(CNTVCT_EL0);
      *(_QWORD *)(state_0 + 24) = v3;
      __dsb(0xFu);
    }
LABEL_8:
    qcom_smem_state_update_bits(state_1, 4096, v2);
  }
  return 0;
}
