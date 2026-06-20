__int64 __fastcall get_qptm_count(__int64 a1)
{
  __int64 next_child; // x0
  __int64 v3; // x20
  unsigned int v4; // w21

  next_child = of_get_next_child(a1, 0);
  if ( next_child )
  {
    v3 = next_child;
    v4 = 0;
    do
    {
      v4 += get_qptm_count(v3) + 1;
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
