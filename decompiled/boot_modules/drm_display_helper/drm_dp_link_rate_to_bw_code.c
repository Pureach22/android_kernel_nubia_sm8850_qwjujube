__int64 __fastcall drm_dp_link_rate_to_bw_code(int a1)
{
  switch ( a1 )
  {
    case 1000000:
      return 1;
    case 2000000:
      return 2;
    case 1350000:
      return 4;
  }
  return (unsigned int)(a1 / 27000);
}
