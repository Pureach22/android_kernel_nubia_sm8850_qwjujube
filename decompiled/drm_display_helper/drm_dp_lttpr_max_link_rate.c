__int64 __fastcall drm_dp_lttpr_max_link_rate(__int64 a1)
{
  int v1; // w8

  v1 = *(unsigned __int8 *)(a1 + 1);
  switch ( v1 )
  {
    case 1:
      return 1000000;
    case 2:
      return 2000000;
    case 4:
      return 1350000;
  }
  return (unsigned int)(27000 * v1);
}
