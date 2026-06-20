__int64 __fastcall ufs_qcom_vdd_hba_reg_notifier(__int64 a1, __int64 a2)
{
  if ( a2 == 128
    && *(_DWORD *)(*(_QWORD *)(a1 - 352) + 84LL) == 2
    && *(_DWORD *)(a1 + 312)
    && (unsigned int)*(unsigned __int8 *)(a1 - 194) - 5 <= 1
    && !*(_WORD *)(a1 - 196) )
  {
    *(_BYTE *)(a1 - 7) = 1;
  }
  return 1;
}
