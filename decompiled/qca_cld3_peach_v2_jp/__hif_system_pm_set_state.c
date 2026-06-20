__int64 __fastcall _hif_system_pm_set_state(__int64 result, int a2)
{
  *(_DWORD *)(result + 4008) = a2;
  return result;
}
