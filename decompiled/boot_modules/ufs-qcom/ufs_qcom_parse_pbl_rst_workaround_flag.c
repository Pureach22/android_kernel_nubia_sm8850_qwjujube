__int64 __fastcall ufs_qcom_parse_pbl_rst_workaround_flag(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL) + 744LL);
  if ( result )
  {
    result = of_find_property(result, "qcom,bypass-pbl-rst-wa", 0);
    *(_BYTE *)(a1 + 3141) = result != 0;
  }
  return result;
}
