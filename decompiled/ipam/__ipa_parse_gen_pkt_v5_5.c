__int64 __fastcall _ipa_parse_gen_pkt_v5_5(__int64 a1, __int64 a2, long double a3)
{
  bool v4; // zf
  __int64 v5; // x0
  __int64 result; // x0

  v4 = (*(_QWORD *)a2 & 0x800000LL) == 0;
  *(_DWORD *)(a1 + 20) = (unsigned __int16)WORD2(*(_QWORD *)a2);
  *(_BYTE *)(a1 + 58) = *(_WORD *)(a2 + 6);
  *(_BYTE *)(a1 + 59) = *(_WORD *)(a2 + 30);
  *(_DWORD *)(a1 + 24) = *(_QWORD *)(a2 + 8);
  *(_BYTE *)(a1 + 28) = *(_BYTE *)(a2 + 12) & 1;
  *(_BYTE *)(a1 + 29) = (*(_QWORD *)(a2 + 8) & 0x200000000LL) != 0;
  *(_BYTE *)(a1 + 30) = (*(_QWORD *)(a2 + 8) & 0x200000000LL) != 0;
  *(_BYTE *)(a1 + 31) = (*(_QWORD *)(a2 + 8) & 0x800000000LL) != 0;
  v5 = v4;
  *(_BYTE *)(a1 + 32) = *(_QWORD *)(a2 + 8) >> 54 == 1023;
  *(_WORD *)(a1 + 50) = (*(_QWORD *)(a2 + 8) >> 36) & 0x3FF;
  *(_BYTE *)(a1 + 33) = (*(_QWORD *)a2 & 0x800000000000000LL) != 0;
  *(_BYTE *)(a1 + 34) = (*(_QWORD *)a2 & 0x1000000000000000LL) != 0;
  *(_BYTE *)(a1 + 35) = *(__int64 *)(a2 + 24) < 0;
  *(_BYTE *)(a1 + 60) = *(_QWORD *)(a2 + 8) >> 46;
  *(_BYTE *)(a1 + 36) = *(_QWORD *)(a2 + 8) >> 54 == 1023;
  *(_WORD *)(a1 + 52) = *(_QWORD *)(a2 + 8) >> 54;
  *(_BYTE *)(a1 + 37) = *(_BYTE *)(a2 + 16) & 1;
  *(_WORD *)(a1 + 54) = (*(_WORD *)(a2 + 16) >> 1) & 0x1FFF;
  *(_QWORD *)a1 = (*(_QWORD *)(a2 + 16) >> 16) & 0xFFFFFFFFFLL;
  *(_BYTE *)(a1 + 92) = (*(_QWORD *)(a2 + 16) >> 52) & 0x3F;
  *(_BYTE *)(a1 + 91) = *(_QWORD *)(a2 + 16) >> 58;
  *(_BYTE *)(a1 + 61) = *(_QWORD *)(a2 + 24);
  *(_DWORD *)(a1 + 44) = *(_DWORD *)(a2 + 24) >> 8;
  *(_BYTE *)(a1 + 48) = *(_BYTE *)(a2 + 28) & 1;
  *(_WORD *)(a1 + 56) = (*(_QWORD *)(a2 + 24) >> 33) & 0x3FF;
  *(_BYTE *)(a1 + 49) = (*(_QWORD *)(a2 + 24) & 0x80000000000LL) != 0;
  *(_BYTE *)(a1 + 62) = (*(_QWORD *)(a2 + 24) >> 44) & 0xF;
  *(_DWORD *)(a1 + 40) = (unsigned __int16)*(_DWORD *)(a2 + 16) >> 14;
  *(_BYTE *)(a1 + 90) = (*(_QWORD *)(a2 + 24) & 0x1000000000000000LL) != 0;
  *(_BYTE *)(a1 + 88) = (*(_QWORD *)(a2 + 24) & 0x2000000000000000LL) != 0;
  *(_BYTE *)(a1 + 89) = (*(_QWORD *)(a2 + 24) & 0x4000000000000000LL) != 0;
  result = pkt_status_parse_exception(v5, *(unsigned __int8 *)(a2 + 1), a3);
  *(_DWORD *)(a1 + 12) = result;
  return result;
}
