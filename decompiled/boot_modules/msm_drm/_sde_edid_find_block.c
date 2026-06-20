__int64 __fastcall sde_edid_find_block(__int64 a1, unsigned int a2, unsigned __int8 a3, _BYTE *a4)
{
  unsigned int v4; // w24
  unsigned int v9; // w8
  int v10; // w6
  unsigned int v11; // w8
  __int64 result; // x0

  v4 = *(unsigned __int8 *)(a1 + 2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "%s +", "_sde_edid_find_block");
  if ( (v4 & 0xFFFFFFFB) == 0 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "EDID: no DTD or non-DTD data present\n");
    return 0;
  }
  if ( v4 <= a2 )
    return 0;
  while ( 1 )
  {
    v9 = *(unsigned __int8 *)(a1 + a2);
    v10 = v9 & 0x1F;
    v11 = v9 >> 5;
    if ( a2 + v10 <= v4 && v11 == a3 )
      break;
    a2 += v10 + 1;
    if ( a2 >= v4 )
      return 0;
  }
  *a4 = v10;
  result = a1 + a2;
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "block=%d found @ 0x%x w/ len=%d\n", a3, a2, v10);
    return a1 + a2;
  }
  return result;
}
