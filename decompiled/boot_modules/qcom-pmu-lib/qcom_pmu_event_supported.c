unsigned __int64 qcom_pmu_event_supported()
{
  unsigned __int64 result; // x0

  result = ((__int64 (*)(void))get_event)();
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 0;
  else
    return (unsigned int)result;
}
