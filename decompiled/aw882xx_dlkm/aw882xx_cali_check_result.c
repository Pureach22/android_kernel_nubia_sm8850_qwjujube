bool __fastcall aw882xx_cali_check_result(__int64 a1)
{
  return !*(_BYTE *)(a1 + 17) || *(unsigned __int8 *)(a1 + 16) != 255;
}
