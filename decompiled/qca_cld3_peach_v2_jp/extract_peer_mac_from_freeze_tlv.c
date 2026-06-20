__int64 __fastcall extract_peer_mac_from_freeze_tlv(__int64 result, __int64 a2)
{
  *(_BYTE *)a2 = *(_WORD *)(result + 6);
  *(_BYTE *)(a2 + 1) = *(_BYTE *)(result + 7);
  *(_WORD *)(a2 + 2) = *(_QWORD *)(result + 8);
  *(_BYTE *)(a2 + 4) = BYTE2(*(_QWORD *)(result + 8));
  *(_BYTE *)(a2 + 5) = BYTE3(*(_QWORD *)(result + 8));
  return result;
}
