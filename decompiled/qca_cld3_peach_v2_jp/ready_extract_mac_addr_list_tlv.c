__int64 __fastcall ready_extract_mac_addr_list_tlv(__int64 a1, _QWORD *a2, _BYTE *a3)
{
  *a3 = *(_DWORD *)(*a2 + 44LL);
  return a2[2];
}
