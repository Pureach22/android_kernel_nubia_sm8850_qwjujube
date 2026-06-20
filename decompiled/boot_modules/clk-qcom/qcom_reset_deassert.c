__int64 __fastcall qcom_reset_deassert(__int64 a1, __int64 a2)
{
  return qcom_reset_set_assert(a1, a2, 0);
}
