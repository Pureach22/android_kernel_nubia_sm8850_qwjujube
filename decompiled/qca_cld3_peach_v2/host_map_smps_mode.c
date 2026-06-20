__int64 __fastcall host_map_smps_mode(int a1)
{
  unsigned int v1; // w8

  if ( a1 == 3 )
    v1 = 1;
  else
    v1 = 3;
  if ( a1 == 2 )
    return 0;
  else
    return v1;
}
