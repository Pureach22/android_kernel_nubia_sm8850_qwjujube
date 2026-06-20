__int64 __fastcall of_get_child_count_0(__int64 a1)
{
  __int64 next_child; // x0
  __int64 v3; // x1
  unsigned int v4; // w20

  next_child = of_get_next_child(a1, 0);
  if ( next_child )
  {
    v3 = next_child;
    v4 = 0;
    do
    {
      ++v4;
      v3 = of_get_next_child(a1, v3);
    }
    while ( v3 );
  }
  else
  {
    return 0;
  }
  return v4;
}
