__int64 __fastcall wmi_set_wow_enable_ack_failed(__int64 result)
{
  *(_DWORD *)(result + 716) = 1;
  return result;
}
