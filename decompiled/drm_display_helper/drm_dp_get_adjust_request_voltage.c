__int64 __fastcall drm_dp_get_adjust_request_voltage(__int64 a1, int a2)
{
  return (*(unsigned __int8 *)(a1 + (a2 >> 1) + 4) >> (4 * (a2 & 1))) & 3;
}
