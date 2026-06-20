__int64 __fastcall ce_disable_polling(__int64 result)
{
  if ( result )
  {
    if ( (*(_BYTE *)(result + 12) & 0x10) != 0 )
      *(_BYTE *)(result + 212) = 0;
  }
  return result;
}
