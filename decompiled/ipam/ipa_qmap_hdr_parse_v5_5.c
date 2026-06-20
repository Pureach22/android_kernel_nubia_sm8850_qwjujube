__int64 __fastcall ipa_qmap_hdr_parse_v5_5(__int64 result, __int64 a2)
{
  *(_BYTE *)a2 = *(_BYTE *)result >> 7;
  *(_BYTE *)(a2 + 1) = (*(_BYTE *)result & 0x40) != 0;
  *(_BYTE *)(a2 + 2) = *(_BYTE *)result & 0x3F;
  *(_BYTE *)(a2 + 3) = *(_BYTE *)(result + 1);
  *(_WORD *)(a2 + 4) = bswap32(*(unsigned __int16 *)(result + 2)) >> 16;
  *(_BYTE *)(a2 + 6) = *(_BYTE *)(result + 4) >> 1;
  *(_BYTE *)(a2 + 7) = *(_BYTE *)(result + 4) & 1;
  *(_BYTE *)(a2 + 14) = (*(_DWORD *)(result + 4) & 0x8000) != 0;
  *(_BYTE *)(a2 + 15) = (*(_DWORD *)(result + 4) >> 12) & 7;
  *(_BYTE *)(a2 + 16) = (*(_DWORD *)(result + 4) & 0x800) != 0;
  *(_BYTE *)(a2 + 17) = (*(_DWORD *)(result + 4) & 0x400) != 0;
  *(_BYTE *)(a2 + 18) = (*(_DWORD *)(result + 4) >> 20) & 0xF;
  *(_BYTE *)(a2 + 19) = *(_BYTE *)(result + 6) & 0xF;
  *(_BYTE *)(a2 + 20) = *(_DWORD *)(result + 4) >> 28;
  return result;
}
