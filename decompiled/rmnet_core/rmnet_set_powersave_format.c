__int64 __fastcall rmnet_set_powersave_format(__int64 result)
{
  if ( result )
    *(_DWORD *)(result + 8) |= 0x8000000u;
  return result;
}
