__int64 __fastcall ufs_qcom_parse_lpm(__int64 a1)
{
  __int64 result; // x0

  result = of_find_property(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL) + 744LL), "qcom,disable-lpm", 0);
  *(_BYTE *)(a1 + 360) = result != 0;
  if ( result )
    return dev_info(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL), "(%s) All LPM is disabled\n", "ufs_qcom_parse_lpm");
  return result;
}
