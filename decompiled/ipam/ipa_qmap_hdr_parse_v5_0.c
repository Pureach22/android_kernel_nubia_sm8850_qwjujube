__int64 __fastcall ipa_qmap_hdr_parse_v5_0(__int64 result, __int64 a2)
{
  *(_BYTE *)a2 = *(_BYTE *)result & 1;
  *(_BYTE *)(a2 + 1) = (*(_BYTE *)result & 2) != 0;
  *(_BYTE *)(a2 + 2) = *(_BYTE *)result >> 2;
  *(_BYTE *)(a2 + 3) = BYTE1(*(_QWORD *)result);
  *(_WORD *)(a2 + 4) = WORD1(*(_QWORD *)result);
  *(_BYTE *)(a2 + 6) = *(_BYTE *)(result + 4) & 0x7F;
  *(_BYTE *)(a2 + 7) = (*(_QWORD *)result & 0x8000000000LL) != 0;
  *(_BYTE *)(a2 + 8) = *(_BYTE *)(result + 5) & 1;
  *(_BYTE *)(a2 + 9) = (*(_QWORD *)result & 0x20000000000LL) != 0;
  *(_BYTE *)(a2 + 10) = (*(_QWORD *)result >> 43) & 0x1F;
  *(_WORD *)(a2 + 12) = *(_WORD *)(result + 6);
  return result;
}
