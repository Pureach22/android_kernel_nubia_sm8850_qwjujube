__int64 __fastcall ufs_qcom_parse_g4_workaround_flag(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL) + 744LL);
  if ( result )
  {
    result = of_find_property(result, "bypass-g4-cfgready", 0);
    *(_BYTE *)(a1 + 417) = result != 0;
  }
  return result;
}
