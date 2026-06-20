__int64 __fastcall wcd9378_writeable_register(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  if ( a2 >> 30 || a2 - 88 <= 6 && a2 != 91 )
    return ((unsigned __int8)wcd9378_reg_access[a2 & 0xFFF | ((unsigned __int8)(a2 >> 20) << 12)] >> 1) & 1;
  result = 0;
  if ( a2 - 244 <= 8 && ((1 << (a2 + 12)) & 0x111) != 0 )
    return ((unsigned __int8)wcd9378_reg_access[a2 & 0xFFF | ((unsigned __int8)(a2 >> 20) << 12)] >> 1) & 1;
  return result;
}
