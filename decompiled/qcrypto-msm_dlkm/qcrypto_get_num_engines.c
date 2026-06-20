__int64 qcrypto_get_num_engines()
{
  __int64 result; // x0
  __int64 *v1; // x9

  LODWORD(result) = -1;
  v1 = &qword_10870;
  do
  {
    v1 = (__int64 *)*v1;
    result = (unsigned int)(result + 1);
  }
  while ( v1 != &qword_10870 );
  return result;
}
