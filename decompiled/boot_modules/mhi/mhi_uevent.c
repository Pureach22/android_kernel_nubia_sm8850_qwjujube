__int64 __fastcall mhi_uevent(__int64 a1, __int64 a2)
{
  return add_uevent_var(a2, "MODALIAS=mhi:%s", *(const char **)(a1 - 32));
}
