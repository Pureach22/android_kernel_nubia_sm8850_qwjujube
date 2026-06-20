__int64 __fastcall cm_fill_connect_resp_from_req(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x21
  __int64 v14; // x8
  __int16 v15; // w9
  __int64 v16; // x22
  int v17; // w8
  int *v18; // x8
  int v19; // w8
  __int16 v20; // w8
  int v21; // w9
  __int64 v22; // x22
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x11

  _ReadStatusReg(SP_EL0);
  v13 = *(_QWORD *)(a3 + 1040);
  if ( v13 )
  {
    v14 = *(_QWORD *)(v13 + 24);
    v15 = *(_WORD *)(v14 + 5);
    LODWORD(v14) = *(_DWORD *)(v14 + 1);
    *(_WORD *)(a2 + 12) = v15;
    *(_DWORD *)(a2 + 8) = v14;
    if ( result )
    {
      v16 = *(_QWORD *)(v13 + 24);
      if ( v16 )
      {
        result = wlan_vdev_mlme_is_mlo_vdev(result, a4, a5, a6, a7, a8, a9, a10, a11);
        if ( (result & 1) != 0 )
        {
          if ( *(_DWORD *)(v16 + 1912) | *(unsigned __int16 *)(v16 + 1916) )
          {
            v17 = *(_DWORD *)(v16 + 1912);
            *(_WORD *)(a2 + 157) = *(_WORD *)(v16 + 1916);
            *(_DWORD *)(a2 + 153) = v17;
          }
        }
      }
    }
    v18 = (int *)(*(_QWORD *)(v13 + 24) + 1192LL);
    goto LABEL_8;
  }
  if ( *(_DWORD *)(a3 + 40) | *(unsigned __int16 *)(a3 + 44) )
  {
    v20 = *(_WORD *)(a3 + 44);
    v21 = *(_DWORD *)(a3 + 40);
  }
  else
  {
    v20 = *(_WORD *)(a3 + 89);
    v21 = *(_DWORD *)(a3 + 85);
  }
  *(_WORD *)(a2 + 12) = v20;
  v22 = result;
  *(_DWORD *)(a2 + 8) = v21;
  result = wlan_vdev_mlme_is_mlo_vdev(result, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( (result & 1) != 0 )
    result = wlan_scan_get_mld_addr_by_link_addr(*(_QWORD *)(v22 + 216), a3 + 40, a2 + 153);
  v19 = *(_DWORD *)(a3 + 92);
  if ( !v19 )
  {
    v18 = (int *)(a3 + 96);
LABEL_8:
    v19 = *v18;
  }
  *(_DWORD *)(a2 + 48) = v19;
  *(_QWORD *)(a2 + 14) = *(_QWORD *)(a3 + 52);
  v23 = *(_QWORD *)(a3 + 76);
  v24 = *(_QWORD *)(a3 + 60);
  v25 = *(_QWORD *)(a3 + 68);
  *(_BYTE *)(a2 + 46) = *(_BYTE *)(a3 + 84);
  *(_QWORD *)(a2 + 38) = v23;
  LOBYTE(v23) = *(_BYTE *)(a2 + 1);
  *(_QWORD *)(a2 + 30) = v25;
  *(_QWORD *)(a2 + 22) = v24;
  LOBYTE(v23) = v23 & 0xFE | ((*(_BYTE *)(a3 + 216) & 2) != 0);
  *(_BYTE *)(a2 + 1) = v23;
  *(_BYTE *)(a2 + 1) = (*(_BYTE *)(a3 + 216) >> 1) & 2 | v23 & 0xFD;
  *(_BYTE *)(a2 + 152) = *(_BYTE *)(a3 + 240);
  _ReadStatusReg(SP_EL0);
  return result;
}
