__int64 __fastcall wma_is_mlo_link_agnostic(
        __int64 a1,
        unsigned __int8 *a2,
        int a3,
        char a4,
        __int16 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  int v27; // w8
  int v28; // w8
  unsigned int v29; // w10
  int v30; // w24
  unsigned int v31; // w8

  if ( (wlan_vdev_mlme_is_mlo_vdev(a1, a6, a7, a8, a9, a10, a11, a12, a13) & 1) == 0
    || (unsigned int)wlan_vdev_mlme_is_active(a1) )
  {
    return 0;
  }
  v27 = *(_DWORD *)(a1 + 16);
  if ( v27 )
  {
    result = 0;
    if ( v27 != 1 )
      return result;
    goto LABEL_19;
  }
  v28 = (a3 == 3) & (unsigned __int8)wlan_get_mlo_link_agnostic_flag(a1, a2, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( a4 == 4 )
    v28 = 0;
  if ( a4 == 11 )
    v28 = 0;
  if ( a5 == 1038 )
    v29 = 0;
  else
    v29 = v28;
  if ( a5 == 769 )
    result = 0;
  else
    result = v29;
  if ( *(_DWORD *)(a1 + 16) == 1 )
  {
LABEL_19:
    v30 = result;
    v31 = (a3 == 3) & (unsigned int)wlan_get_mlo_link_agnostic_flag(a1, a2, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( a4 == 5 )
      v31 = 0;
    if ( a4 == 11 )
      v31 = 0;
    if ( (a4 & 0xFD) == 1 )
      v31 = 0;
    if ( a5 == 769 )
      v31 = 0;
    if ( a5 == 1028 )
      v31 = 0;
    return v31 | v30;
  }
  return result;
}
