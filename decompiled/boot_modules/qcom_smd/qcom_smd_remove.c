__int64 __fastcall qcom_smd_remove(__int64 a1)
{
  return device_for_each_child(a1 + 16, 0, qcom_smd_remove_edge);
}
