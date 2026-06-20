__int64 __fastcall qcom_llcc_event_stop(__int64 a1)
{
  __int64 result; // x0

  result = qcom_llcc_event_read();
  *(_DWORD *)(a1 + 480) |= 3u;
  return result;
}
