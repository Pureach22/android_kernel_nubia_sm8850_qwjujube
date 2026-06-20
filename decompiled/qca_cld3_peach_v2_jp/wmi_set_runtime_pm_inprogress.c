__int64 __fastcall wmi_set_runtime_pm_inprogress(__int64 result, char a2)
{
  *(_DWORD *)(result + 708) = a2 & 1;
  return result;
}
