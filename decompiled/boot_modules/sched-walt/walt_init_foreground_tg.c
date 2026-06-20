__int64 __fastcall walt_init_foreground_tg(__int64 result)
{
  char v1; // w9

  *(_BYTE *)(result + 618) = 1;
  v1 = soc_flags;
  *(_BYTE *)(result + 622) = 1;
  *(_WORD *)(result + 616) = 0;
  *(_WORD *)(result + 620) = 256;
  *(_DWORD *)(result + 624) = 2;
  *(_BYTE *)(result + 619) = (v1 & 2) != 0;
  return result;
}
