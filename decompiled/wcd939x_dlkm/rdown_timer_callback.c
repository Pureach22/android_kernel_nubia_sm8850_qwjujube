__int64 __fastcall rdown_timer_callback(__int64 result)
{
  *(_BYTE *)(result + 44) = 1;
  return result;
}
