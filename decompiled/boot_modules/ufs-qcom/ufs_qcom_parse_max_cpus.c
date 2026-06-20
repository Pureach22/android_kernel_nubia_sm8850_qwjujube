__int64 __fastcall ufs_qcom_parse_max_cpus(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL) + 744LL);
  if ( result )
  {
    result = of_property_read_variable_u32_array(result, "qcom,max-cpus", a1 + 3192, 1, 0);
    if ( !*(_DWORD *)(a1 + 3192) )
    {
      result = dev_err(
                 *(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL),
                 "%s: missing max-cpus DT.\n",
                 "ufs_qcom_parse_max_cpus");
      *(_DWORD *)(a1 + 3192) = 8;
    }
  }
  return result;
}
