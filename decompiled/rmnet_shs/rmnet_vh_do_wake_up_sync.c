__int64 __fastcall rmnet_vh_do_wake_up_sync(__int64 a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  int v4; // w8
  __int64 result; // x0

  v4 = *(unsigned __int16 *)(a4 + 566);
  if ( (v4 == 17 || v4 == 6) && (*(_DWORD *)(a4 + 132) & 0xFFFFF) == 0x77777 )
  {
    *a3 = 1;
    return _wake_up(a2, 1, 1, 195);
  }
  return result;
}
