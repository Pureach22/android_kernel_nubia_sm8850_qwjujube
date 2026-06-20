__int64 __fastcall gpr_uevent(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = of_device_uevent_modalias();
  if ( (_DWORD)result == -19 )
    return add_uevent_var(a2, "MODALIAS=gpr:%s", (const char *)(a1 + 920));
  return result;
}
