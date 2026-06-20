__int64 __fastcall gmu_core_get_attrs(unsigned int a1)
{
  int v1; // w8

  if ( (a1 & 0x10) != 0 )
    v1 = 33;
  else
    v1 = 1;
  return v1 | (a1 >> 4) & 2;
}
