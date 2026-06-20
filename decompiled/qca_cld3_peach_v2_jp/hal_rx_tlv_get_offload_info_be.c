__int64 __fastcall hal_rx_tlv_get_offload_info_be(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  char v3; // w8

  *(_BYTE *)a2 = 0;
  *(_DWORD *)(a2 + 20) = *(_QWORD *)(a1 + 52);
  *(_BYTE *)(a2 + 3) = (*(_DWORD *)(a1 + 44) & 0x800) != 0;
  v2 = *(_DWORD *)(a1 + 44);
  *(_BYTE *)(a2 + 1) = (v2 & 0x1000) != 0;
  if ( ((v2 >> 12) & 1) != 0 )
  {
    *(_BYTE *)(a2 + 2) = (*(_DWORD *)(a1 + 44) & 0x8000) != 0;
    v3 = *(_BYTE *)(a1 + 43);
    *(_WORD *)(a2 + 8) = 0;
    *(_QWORD *)(a2 + 12) = 0;
    *(_BYTE *)(a2 + 4) = v3;
  }
  return 0;
}
