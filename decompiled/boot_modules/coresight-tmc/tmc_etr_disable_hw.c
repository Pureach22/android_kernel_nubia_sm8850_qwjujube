__int64 __fastcall tmc_etr_disable_hw(__int64 a1)
{
  __int64 result; // x0

  _tmc_etr_disable_hw();
  result = coresight_disclaim_device(*(_QWORD *)(a1 + 16));
  *(_QWORD *)(a1 + 120) = 0;
  return result;
}
