bool __fastcall wmi_has_wow_enable_ack_failed(__int64 a1)
{
  return *(_DWORD *)(a1 + 716) != 0;
}
