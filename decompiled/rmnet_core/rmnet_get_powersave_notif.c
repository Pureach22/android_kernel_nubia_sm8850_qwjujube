__int64 __fastcall rmnet_get_powersave_notif(__int64 result)
{
  if ( result )
    return *(_DWORD *)(result + 8) & 0x4000000;
  return result;
}
