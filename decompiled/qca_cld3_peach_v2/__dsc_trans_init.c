_QWORD *__fastcall _dsc_trans_init(_QWORD *result)
{
  *result = 0;
  result[1] = result + 1;
  result[2] = result + 1;
  result[3] = 0;
  return result;
}
