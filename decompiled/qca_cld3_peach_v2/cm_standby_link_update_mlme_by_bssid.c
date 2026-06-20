__int64 __fastcall cm_standby_link_update_mlme_by_bssid(
        __int64 result,
        int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x19
  int v14; // w9
  __int16 v15; // w8
  __int64 v16; // x24
  size_t v17; // x2
  int v18; // w8
  size_t v19; // x2
  __int64 v20; // x24
  int v21; // w8
  int v22; // w8
  size_t v23; // x2
  int v24; // w8
  int v25; // w8
  _QWORD v26[2]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v27; // [xsp+10h] [xbp-50h]
  __int64 v28; // [xsp+18h] [xbp-48h]
  _QWORD v29[7]; // [xsp+28h] [xbp-38h] BYREF

  v29[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_DWORD *)(result + 16) )
  {
    v12 = result;
    v27 = 0;
    v28 = 0;
    v26[0] = 0;
    v26[1] = 0;
    memset(v29, 0, 44);
    result = wlan_vdev_mlme_is_mlo_vdev(result, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( (result & 1) != 0 && (*(_BYTE *)(v12 + 60) & 2) == 0 )
    {
      result = mlo_mgr_get_ap_link(v12);
      if ( result )
      {
        if ( *(_DWORD *)(result + 24) | *(unsigned __int16 *)(result + 28) )
        {
          if ( *(unsigned __int8 *)(result + 12) == 255 )
          {
            v14 = *(_DWORD *)(result + 24);
            v15 = *(_WORD *)(result + 28);
            v16 = result;
            HIDWORD(v27) = a2;
            v17 = *a3;
            *(_DWORD *)((char *)&v29[4] + 5) = v14;
            *(_WORD *)((char *)&v29[5] + 1) = v15;
            v18 = **(unsigned __int16 **)(result + 32);
            BYTE4(v29[0]) = v17;
            LODWORD(v29[0]) = v18;
            qdf_mem_copy((char *)v29 + 5, a3 + 1, v17);
            scm_scan_update_mlme_by_bssinfo(*(_QWORD *)(v12 + 216), v29, v26);
            result = v16;
          }
          if ( *(_DWORD *)(result + 72) | *(unsigned __int16 *)(result + 76) )
          {
            if ( *(unsigned __int8 *)(result + 60) == 255 )
            {
              HIDWORD(v27) = a2;
              v19 = *a3;
              v20 = result;
              v21 = *(_DWORD *)(result + 72);
              *(_WORD *)((char *)&v29[5] + 1) = *(_WORD *)(result + 76);
              *(_DWORD *)((char *)&v29[4] + 5) = v21;
              v22 = **(unsigned __int16 **)(result + 80);
              BYTE4(v29[0]) = v19;
              LODWORD(v29[0]) = v22;
              qdf_mem_copy((char *)v29 + 5, a3 + 1, v19);
              scm_scan_update_mlme_by_bssinfo(*(_QWORD *)(v12 + 216), v29, v26);
              result = v20;
            }
            if ( *(_DWORD *)(result + 120) | *(unsigned __int16 *)(result + 124)
              && *(unsigned __int8 *)(result + 108) == 255 )
            {
              HIDWORD(v27) = a2;
              v23 = *a3;
              v24 = *(_DWORD *)(result + 120);
              *(_WORD *)((char *)&v29[5] + 1) = *(_WORD *)(result + 124);
              *(_DWORD *)((char *)&v29[4] + 5) = v24;
              v25 = **(unsigned __int16 **)(result + 128);
              BYTE4(v29[0]) = v23;
              LODWORD(v29[0]) = v25;
              qdf_mem_copy((char *)v29 + 5, a3 + 1, v23);
              result = scm_scan_update_mlme_by_bssinfo(*(_QWORD *)(v12 + 216), v29, v26);
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
