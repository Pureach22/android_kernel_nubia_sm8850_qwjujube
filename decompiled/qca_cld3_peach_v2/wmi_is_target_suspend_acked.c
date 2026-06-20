bool __fastcall wmi_is_target_suspend_acked(__int64 a1)
{
  return *(_DWORD *)(a1 + 700) != 0;
}
