__int64 __fastcall lpass_cdc_get_macro_id(__int64 a1, unsigned __int16 a2)
{
  if ( a2 < 0xBBDu )
    return 0;
  if ( (unsigned int)a2 - 4096 < 0xF8D )
    return 1;
  if ( (unsigned int)a2 - 0x2000 < 0xBE5 )
    return 2;
  if ( (unsigned int)a2 - 0x4000 < 0xBE5 )
    return 4;
  if ( (unsigned int)a2 - 12288 >= 0x5A9 )
    return 4294967274LL;
  return 3;
}
