__int64 __fastcall cam_cdm_get_arbitration_type(unsigned int a1, int a2)
{
  unsigned int v2; // w8

  if ( a2 == 2 )
    v2 = 1;
  else
    v2 = 2;
  if ( a1 >> 29 )
    return v2;
  else
    return 0;
}
