__int64 __fastcall ce_enable_polling(__int64 result)
{
  if ( result )
  {
    if ( (*(_BYTE *)(result + 12) & 0x10) != 0 )
      *(_BYTE *)(result + 212) = 1;
  }
  return result;
}
