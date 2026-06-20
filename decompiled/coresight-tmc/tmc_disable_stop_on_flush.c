__int64 __fastcall tmc_disable_stop_on_flush(__int64 result)
{
  *(_BYTE *)(result + 344) = 0;
  return result;
}
