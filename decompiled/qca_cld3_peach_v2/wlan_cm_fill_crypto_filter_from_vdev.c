__int64 __fastcall wlan_cm_fill_crypto_filter_from_vdev(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int16 v13; // w8
  int v14; // w8

  result = wlan_crypto_get_param(a1, 3u);
  a2[14] = result;
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
  {
    result = cm_get_ext_hdl_fl(
               a1,
               (__int64)"wlan_cm_fill_crypto_filter_from_vdev",
               0x89Eu,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12);
    if ( result )
    {
      v13 = *(_WORD *)(result + 84);
      if ( (v13 & 0x40) != 0 )
      {
        v14 = 2;
      }
      else
      {
        if ( (v13 & 0x80) == 0 )
        {
LABEL_8:
          a2[10] = *(_DWORD *)(result + 64);
          a2[13] = *(_DWORD *)(result + 76);
          a2[12] = *(_DWORD *)(result + 72);
          a2[11] = *(_DWORD *)(result + 68);
          return result;
        }
        v14 = 1;
      }
      a2[6] = v14;
      goto LABEL_8;
    }
  }
  return result;
}
