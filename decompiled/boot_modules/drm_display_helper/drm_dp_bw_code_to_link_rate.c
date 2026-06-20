__int64 __fastcall drm_dp_bw_code_to_link_rate(unsigned __int8 a1)
{
  switch ( a1 )
  {
    case 1u:
      return 1000000;
    case 2u:
      return 2000000;
    case 4u:
      return 1350000;
  }
  return 27000 * (unsigned int)a1;
}
