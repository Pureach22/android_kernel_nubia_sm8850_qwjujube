__int64 __fastcall ipareg_parse_clkon_cfg_common(__int64 result, int a2)
{
  *(_QWORD *)result = 0;
  *(_QWORD *)(result + 6) = 0;
  *(_BYTE *)(result + 1) = (a2 & 0x20000000) != 0;
  *(_BYTE *)(result + 2) = (a2 & 0x10000000) != 0;
  *(_BYTE *)(result + 3) = (a2 & 0x8000000) != 0;
  *(_BYTE *)(result + 4) = (a2 & 0x4000000) != 0;
  *(_BYTE *)(result + 5) = (a2 & 0x2000000) != 0;
  *(_BYTE *)(result + 6) = HIBYTE(a2) & 1;
  *(_BYTE *)(result + 7) = (a2 & 0x800000) != 0;
  *(_BYTE *)(result + 8) = (a2 & 0x400000) != 0;
  *(_BYTE *)(result + 9) = (a2 & 0x200000) != 0;
  *(_BYTE *)(result + 10) = (a2 & 0x100000) != 0;
  *(_BYTE *)(result + 11) = (a2 & 0x80000) != 0;
  *(_BYTE *)(result + 12) = (a2 & 0x40000) != 0;
  *(_BYTE *)(result + 14) = BYTE2(a2) & 1;
  *(_BYTE *)(result + 15) = (a2 & 0x8000) != 0;
  *(_BYTE *)(result + 16) = (a2 & 0x4000) != 0;
  *(_BYTE *)(result + 17) = (a2 & 0x2000) != 0;
  *(_BYTE *)(result + 18) = (a2 & 0x1000) != 0;
  *(_BYTE *)(result + 19) = (a2 & 0x800) != 0;
  *(_BYTE *)(result + 20) = (a2 & 0x400) != 0;
  *(_BYTE *)(result + 21) = (a2 & 0x200) != 0;
  *(_BYTE *)(result + 22) = BYTE1(a2) & 1;
  *(_BYTE *)(result + 23) = (a2 & 0x80) != 0;
  *(_BYTE *)(result + 24) = (a2 & 0x40) != 0;
  *(_BYTE *)(result + 25) = (a2 & 0x20) != 0;
  *(_BYTE *)(result + 26) = (a2 & 0x10) != 0;
  *(_BYTE *)(result + 27) = (a2 & 8) != 0;
  *(_BYTE *)(result + 28) = (a2 & 4) != 0;
  *(_BYTE *)(result + 29) = (a2 & 2) != 0;
  *(_BYTE *)(result + 30) = a2 & 1;
  return result;
}
