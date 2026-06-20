__int64 __fastcall ipareg_parse_comp_cfg_common(__int64 result, int a2)
{
  *(_QWORD *)result = 0;
  *(_QWORD *)(result + 8) = 0;
  *(_QWORD *)(result + 16) = 0;
  *(_BYTE *)(result + 7) = BYTE2(a2) & 1;
  *(_BYTE *)(result + 8) = (a2 & 0x8000) != 0;
  *(_BYTE *)(result + 9) = (a2 & 0x4000) != 0;
  *(_BYTE *)(result + 10) = (a2 & 0x2000) != 0;
  *(_BYTE *)(result + 11) = (a2 & 0x1000) != 0;
  *(_BYTE *)(result + 12) = (a2 & 0x800) != 0;
  *(_BYTE *)(result + 13) = (a2 & 0x400) != 0;
  *(_BYTE *)(result + 14) = (a2 & 0x200) != 0;
  *(_BYTE *)(result + 15) = BYTE1(a2) & 1;
  *(_BYTE *)(result + 16) = (a2 & 0x80) != 0;
  *(_BYTE *)(result + 17) = (a2 & 0x40) != 0;
  *(_BYTE *)(result + 18) = (a2 & 0x20) != 0;
  *(_BYTE *)(result + 20) = (a2 & 8) != 0;
  *(_BYTE *)(result + 24) = 0;
  *(_BYTE *)(result + 21) = (a2 & 4) != 0;
  *(_BYTE *)(result + 22) = (a2 & 2) != 0;
  return result;
}
