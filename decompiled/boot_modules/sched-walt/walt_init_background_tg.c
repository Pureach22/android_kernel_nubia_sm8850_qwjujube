__int64 __fastcall walt_init_background_tg(__int64 result)
{
  *(_BYTE *)(result + 622) = 0;
  *(_DWORD *)(result + 616) = 0x10000;
  *(_WORD *)(result + 620) = 256;
  *(_DWORD *)(result + 624) = 3;
  return result;
}
