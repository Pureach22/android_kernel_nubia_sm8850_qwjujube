__int64 __fastcall drm_dp_read_lttpr_common_caps(_QWORD *a1, unsigned __int8 *a2, __int64 a3)
{
  __int64 v5; // x22
  __int64 v6; // x21
  __int64 result; // x0

  v5 = 0;
  if ( *a2 < 0x14u )
    v6 = 1;
  else
    v6 = 8;
  while ( 1 )
  {
    result = drm_dp_dpcd_read(a1, (int)v5 + 983040, a3 + v5, v6);
    if ( (result & 0x80000000) != 0 )
      break;
    if ( (_DWORD)v6 != (_DWORD)result )
      __break(0x800u);
    v5 += v6;
    if ( (int)v5 >= 8 )
      return 0;
  }
  return result;
}
