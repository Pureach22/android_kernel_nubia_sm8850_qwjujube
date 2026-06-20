__int64 __fastcall mlme_update_nss_vht_cap(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  int v2; // w8
  int v3; // w11
  int v4; // w9
  int v5; // w11
  int v6; // w8
  int *v7; // x9
  __int16 v9; // w10
  int v10; // w11
  int v11; // w12

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v2 = *(_DWORD *)(psoc_ext_obj_fl + 2860);
  if ( *(_BYTE *)(psoc_ext_obj_fl + 2871) )
  {
    v3 = 4 * *(unsigned __int8 *)(psoc_ext_obj_fl + 2868);
    v4 = v3 | *(_DWORD *)(psoc_ext_obj_fl + 2852) & 0xFFF0 | *(_DWORD *)(psoc_ext_obj_fl + 2860) & 0xFFF3;
    v5 = *(_DWORD *)(psoc_ext_obj_fl + 2836) & 0xFFF0 | *(_DWORD *)(psoc_ext_obj_fl + 2860) & 0xFFF3 | v3;
    v6 = *(_DWORD *)(psoc_ext_obj_fl + 2864) & 0xFFF3
       | *(_DWORD *)(psoc_ext_obj_fl + 2840) & 0xFFF0
       | (4 * *(unsigned __int8 *)(psoc_ext_obj_fl + 2869));
    *(_DWORD *)(psoc_ext_obj_fl + 2852) = v4;
    *(_DWORD *)(psoc_ext_obj_fl + 2836) = v5;
    v7 = (int *)(psoc_ext_obj_fl + 2840);
  }
  else
  {
    v9 = *(_DWORD *)(psoc_ext_obj_fl + 2836);
    v10 = *(_DWORD *)(psoc_ext_obj_fl + 2840);
    v11 = *(_DWORD *)(psoc_ext_obj_fl + 2864);
    *(_DWORD *)(psoc_ext_obj_fl + 2852) = *(_DWORD *)(psoc_ext_obj_fl + 2852) & 0xFFFC | v2 | 0xC;
    v7 = (int *)(psoc_ext_obj_fl + 2840);
    *(_DWORD *)(psoc_ext_obj_fl + 2836) = v2 | v9 & 0xFFF0 | 0xC;
    v6 = v11 | v10 & 0xFFF0 | 0xC;
  }
  *v7 = v6;
  return 0;
}
