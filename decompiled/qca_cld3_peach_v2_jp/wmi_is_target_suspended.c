bool __fastcall wmi_is_target_suspended(__int64 a1)
{
  return *(_DWORD *)(a1 + 696) != 0;
}
