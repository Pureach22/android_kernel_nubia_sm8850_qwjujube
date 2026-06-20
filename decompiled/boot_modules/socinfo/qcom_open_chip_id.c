__int64 __fastcall qcom_open_chip_id(__int64 a1, __int64 a2)
{
  return single_open(a2, qcom_show_chip_id, *(_QWORD *)(a1 + 696));
}
