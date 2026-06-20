bool __fastcall wcd9378_volatile_register(__int64 a1, unsigned int a2)
{
  _BOOL8 result; // x0

  if ( a2 >> 30 )
    return (wcd9378_reg_access[a2 & 0xFFF | ((unsigned __int8)(a2 >> 20) << 12)] & 3) == 1;
  result = 1;
  if ( (a2 - 88 > 6 || a2 == 91) && (a2 - 244 > 8 || ((1 << (a2 + 12)) & 0x111) == 0) )
    return 0;
  return result;
}
