_BYTE *__fastcall ipa_qmap_hdr_parse_v4_5(_BYTE *result, __int64 a2)
{
  *(_BYTE *)a2 = *result & 1;
  *(_BYTE *)(a2 + 1) = (*result & 2) != 0;
  *(_BYTE *)(a2 + 2) = *result >> 2;
  *(_BYTE *)(a2 + 3) = BYTE1(*(_QWORD *)result);
  *(_WORD *)(a2 + 4) = WORD1(*(_QWORD *)result);
  *(_BYTE *)(a2 + 6) = result[4] & 0x7F;
  *(_BYTE *)(a2 + 7) = (*(_QWORD *)result & 0x8000000000LL) != 0;
  *(_BYTE *)(a2 + 9) = (*(_QWORD *)result & 0x20000000000LL) != 0;
  return result;
}
