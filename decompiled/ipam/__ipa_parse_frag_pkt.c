__int64 __fastcall _ipa_parse_frag_pkt(__int64 result, __int64 a2)
{
  *(_BYTE *)(result + 63) = *(_BYTE *)(a2 + 1) & 0xF;
  *(_BYTE *)(result + 64) = (*(_DWORD *)a2 & 0x8000) != 0;
  *(_DWORD *)(result + 68) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(result + 72) = *(_QWORD *)(a2 + 8);
  *(_BYTE *)(result + 76) = (unsigned __int16)WORD2(*(_QWORD *)(a2 + 8)) >> 8;
  *(_WORD *)(result + 78) = *(_WORD *)(a2 + 14);
  *(_DWORD *)(result + 80) = *(_QWORD *)(a2 + 16);
  *(_WORD *)(result + 84) = *(_WORD *)(a2 + 22);
  *(_BYTE *)(result + 58) = *(_BYTE *)(a2 + 2) & 0x1F;
  *(_BYTE *)(result + 59) = (*(_QWORD *)(a2 + 16) >> 43) & 0x1F;
  *(_DWORD *)(result + 24) = *(_QWORD *)(a2 + 24);
  *(_BYTE *)(result + 61) = BYTE3(*(_QWORD *)a2);
  *(_BYTE *)(result + 48) = *(_BYTE *)(a2 + 20) & 1;
  *(_WORD *)(result + 56) = (*(_QWORD *)(a2 + 16) >> 33) & 0x3FF;
  *(_DWORD *)(result + 12) = (*(_DWORD *)a2 >> 21) & 1;
  *(_DWORD *)(result + 40) = (*(_QWORD *)(a2 + 8) >> 38) & 3;
  return result;
}
