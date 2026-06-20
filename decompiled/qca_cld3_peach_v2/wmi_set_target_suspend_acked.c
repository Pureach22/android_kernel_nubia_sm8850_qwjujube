__int64 __fastcall wmi_set_target_suspend_acked(__int64 result, char a2)
{
  *(_DWORD *)(result + 700) = a2 & 1;
  *(_DWORD *)(result + 888) = 0;
  return result;
}
