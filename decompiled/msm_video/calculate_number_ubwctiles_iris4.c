__int64 __fastcall calculate_number_ubwctiles_iris4(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // w8
  int v5; // w9

  v4 = a1 / a3;
  v5 = a2 / a4;
  if ( a1 % a3 )
    ++v4;
  if ( a2 != v5 * a4 )
    ++v5;
  return (unsigned int)(v5 * v4);
}
