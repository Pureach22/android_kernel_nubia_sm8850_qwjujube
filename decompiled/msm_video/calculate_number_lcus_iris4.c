__int64 __fastcall calculate_number_lcus_iris4(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v3; // w8
  int v4; // w9

  v3 = a1 / a3;
  v4 = a2 / a3;
  if ( a1 % a3 )
    ++v3;
  if ( a2 != v4 * a3 )
    ++v4;
  return (unsigned int)(v4 * v3);
}
