__int64 __fastcall wmi_clear_wow_enable_ack_failed(__int64 result)
{
  *(_DWORD *)(result + 716) = 0;
  return result;
}
