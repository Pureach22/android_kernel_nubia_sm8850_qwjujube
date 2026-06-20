__int64 __fastcall ready_extract_mac_addr_tlv(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *a2;
  *(_WORD *)a3 = *(_DWORD *)(*a2 + 28);
  *(_BYTE *)(a3 + 2) = *(_WORD *)(v3 + 30);
  *(_BYTE *)(a3 + 3) = *(_BYTE *)(v3 + 31);
  *(_WORD *)(a3 + 4) = *(_DWORD *)(v3 + 32);
  return 0;
}
