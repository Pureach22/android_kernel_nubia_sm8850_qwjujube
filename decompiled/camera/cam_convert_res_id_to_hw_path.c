__int64 __fastcall cam_convert_res_id_to_hw_path(int a1, int a2)
{
  unsigned int v3; // w8

  if ( a1 > 5 )
  {
    if ( a1 > 7 )
    {
      if ( a1 == 9 )
        return 4;
      if ( a1 == 8 )
        return 2;
      return 0;
    }
    if ( a1 == 6 )
      return 64;
    else
      return 128;
  }
  else if ( a1 > 3 )
  {
    if ( a1 == 4 )
      return 16;
    else
      return 32;
  }
  else
  {
    if ( a1 )
    {
      if ( a1 == 3 )
        return 8;
      return 0;
    }
    if ( a2 == 11 )
      v3 = 512;
    else
      v3 = 1;
    if ( a2 == 10 )
      return 256;
    else
      return v3;
  }
}
