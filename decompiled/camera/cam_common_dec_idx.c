_DWORD *__fastcall cam_common_dec_idx(_DWORD *result, int a2, int a3)
{
  *result = (a3 & ((*result - a2) >> 31)) + *result - a2;
  return result;
}
