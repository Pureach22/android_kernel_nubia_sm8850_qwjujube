_QWORD *__fastcall qcom_find_freq_floor(_QWORD *a1, unsigned __int64 a2)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x2
  __int64 v4; // t1

  v2 = nullptr;
  do
  {
    v3 = v2;
    v2 = a1;
    v4 = *a1;
    a1 += 3;
  }
  while ( v4 - 1 < a2 );
  return v3;
}
