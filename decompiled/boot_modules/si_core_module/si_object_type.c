__int64 __fastcall si_object_type(int a1)
{
  unsigned int v1; // w8

  if ( a1 >= 0 )
    v1 = 1;
  else
    v1 = 2;
  if ( a1 )
    return v1;
  else
    return 16;
}
