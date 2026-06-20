_DWORD *__fastcall cam_csiphy_query_cap(_DWORD *result, _DWORD *a2)
{
  *a2 = result[233];
  a2[1] = result[18];
  a2[2] = result[19];
  return result;
}
