bool __fastcall wmi_get_runtime_pm_inprogress(__int64 a1)
{
  return *(_DWORD *)(a1 + 708) != 0;
}
