__int64 __fastcall qcom_ipcc_mbox_shutdown(__int64 result)
{
  *(_QWORD *)(result + 240) = 0;
  return result;
}
