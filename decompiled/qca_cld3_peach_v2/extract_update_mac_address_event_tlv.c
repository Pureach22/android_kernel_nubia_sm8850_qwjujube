__int64 __fastcall extract_update_mac_address_event_tlv(__int64 a1, __int64 *a2, _BYTE *a3, _BYTE *a4)
{
  __int64 v4; // x8

  v4 = *a2;
  *a3 = *(_DWORD *)(*a2 + 4);
  *a4 = *(_DWORD *)(v4 + 8);
  return 0;
}
