__int64 __fastcall extract_scan_radio_cap_service_ready_ext2_tlv(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4)
{
  __int64 v4; // x8

  if ( !a2 || *(_DWORD *)(a2 + 104) <= (unsigned int)a3 )
    return 4;
  v4 = *(_QWORD *)(a2 + 96) + 12LL * a3;
  *(_DWORD *)a4 = *(_DWORD *)(v4 + 4);
  *(_BYTE *)(a4 + 4) = *(_BYTE *)(v4 + 8) & 1;
  *(_BYTE *)(a4 + 5) = (*(_BYTE *)(v4 + 8) & 2) != 0;
  *(_BYTE *)(a4 + 6) = (*(_BYTE *)(v4 + 8) & 4) != 0;
  return 0;
}
