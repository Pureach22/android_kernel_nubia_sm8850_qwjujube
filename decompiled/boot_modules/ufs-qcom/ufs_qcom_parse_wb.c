__int64 __fastcall ufs_qcom_parse_wb(__int64 a1)
{
  __int64 result; // x0

  result = of_find_property(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL) + 744LL), "qcom,disable-wb-support", 0);
  *(_BYTE *)(a1 + 761) = result != 0;
  if ( result )
    return printk(&unk_1A44A, "ufs_qcom_parse_wb");
  return result;
}
