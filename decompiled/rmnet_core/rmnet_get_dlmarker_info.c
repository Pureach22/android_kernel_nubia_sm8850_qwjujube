__int64 __fastcall rmnet_get_dlmarker_info(__int64 result)
{
  if ( result )
    return *(_DWORD *)(result + 8) & 0x60000000;
  return result;
}
