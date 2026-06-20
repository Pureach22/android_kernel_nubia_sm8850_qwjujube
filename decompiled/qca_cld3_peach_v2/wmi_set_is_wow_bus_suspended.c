__int64 __fastcall wmi_set_is_wow_bus_suspended(__int64 result, char a2)
{
  *(_DWORD *)(result + 712) = a2 & 1;
  return result;
}
