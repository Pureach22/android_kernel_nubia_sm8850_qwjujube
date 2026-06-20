__int64 __fastcall drm_dp_get_adjust_request_pre_emphasis(__int64 a1, int a2)
{
  char v2; // w8

  v2 = 6;
  if ( (a2 & 1) == 0 )
    v2 = 2;
  return 8 * ((*(unsigned __int8 *)(a1 + (a2 >> 1) + 4) >> v2) & 3u);
}
