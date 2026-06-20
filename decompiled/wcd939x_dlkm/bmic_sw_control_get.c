__int64 __fastcall bmic_sw_control_get(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 72) = bmic_sw_control;
  return 0;
}
