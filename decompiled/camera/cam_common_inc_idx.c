int *__fastcall cam_common_inc_idx(int *result, int a2, int a3)
{
  *result = (*result + a2) % a3;
  return result;
}
