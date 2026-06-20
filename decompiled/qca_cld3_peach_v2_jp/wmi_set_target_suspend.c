__int64 __fastcall wmi_set_target_suspend(__int64 result, char a2)
{
  *(_DWORD *)(result + 696) = a2 & 1;
  return result;
}
