__int64 __fastcall kgsl_pwrctrl_request_state(__int64 result, int a2)
{
  *(_DWORD *)(result + 11124) = a2;
  return result;
}
