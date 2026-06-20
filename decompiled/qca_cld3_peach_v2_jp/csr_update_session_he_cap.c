__int64 __fastcall csr_update_session_he_cap(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 ext_hdl; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  int v26; // w8
  unsigned __int64 *v27; // x8
  __int64 v28; // x9
  char v29; // w22
  unsigned __int16 sap_he_rx_mcs_map_160; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 21552);
  v4 = *a2;
  sap_he_rx_mcs_map_160 = 0;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v3, v4, 11);
  if ( result )
  {
    v14 = result;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(result, v6, v7, v8, v9, v10, v11, v12, v13);
    if ( !ext_hdl )
    {
LABEL_61:
      result = wlan_objmgr_vdev_release_ref(v14, 0xBu, v16, v17, v18, v19, v20, v21, v22, v23, v24);
      goto LABEL_62;
    }
    v25 = ext_hdl + 20480;
    qdf_mem_copy((void *)(ext_hdl + 23896), (const void *)(*(_QWORD *)(a1 + 8) + 1288LL), 0x3Cu);
    *(_BYTE *)(v25 + 3416) = 1;
    v26 = *(_DWORD *)(v14 + 16);
    if ( v26 != 3 )
    {
      if ( v26 != 1 )
      {
        if ( (v26 & 0xFFFFFFFD) != 0 )
          goto LABEL_10;
        v27 = (unsigned __int64 *)(v25 + 3417);
        v28 = *(_QWORD *)(v25 + 3417);
        *(_QWORD *)(v25 + 3417) = v28 & 0xFFFFFFFFFFFFFFFBLL;
        if ( (v28 & 2) != 0 )
          goto LABEL_10;
        goto LABEL_7;
      }
      sap_he_rx_mcs_map_160 = wlan_mlme_get_sap_he_rx_mcs_map_160(*(_QWORD *)(a1 + 21552));
      sap_he_rx_mcs_map_160 = wlan_mlme_get_min_he_mcs_map(sap_he_rx_mcs_map_160, *(_WORD *)(v25 + 3440));
      qdf_mem_copy((void *)(v25 + 3440), &sap_he_rx_mcs_map_160, 2u);
    }
    v27 = (unsigned __int64 *)(v25 + 3417);
    v28 = *(_QWORD *)(v25 + 3417);
    *(_QWORD *)(v25 + 3417) = v28 & 0xFFFFFFFFFFFFFFFDLL;
    if ( (v28 & 4) != 0 )
    {
LABEL_10:
      if ( (*(_BYTE *)(v25 + 3430) & 4) != 0 )
      {
        v29 = 25;
        qdf_mem_copy((void *)(v25 + 3449), (const void *)(*(_QWORD *)(a1 + 8) + 1433LL), 0x19u);
        if ( !*(_BYTE *)(v25 + 3473) )
        {
          if ( *(_BYTE *)(v25 + 3472) )
          {
            v29 = 24;
          }
          else if ( *(_BYTE *)(v25 + 3471) )
          {
            v29 = 23;
          }
          else if ( *(_BYTE *)(v25 + 3470) )
          {
            v29 = 22;
          }
          else if ( *(_BYTE *)(v25 + 3469) )
          {
            v29 = 21;
          }
          else if ( *(_BYTE *)(v25 + 3468) )
          {
            v29 = 20;
          }
          else if ( *(_BYTE *)(v25 + 3467) )
          {
            v29 = 19;
          }
          else if ( *(_BYTE *)(v25 + 3466) )
          {
            v29 = 18;
          }
          else if ( *(_BYTE *)(v25 + 3465) )
          {
            v29 = 17;
          }
          else if ( *(_BYTE *)(v25 + 3464) )
          {
            v29 = 16;
          }
          else if ( *(_BYTE *)(v25 + 3463) )
          {
            v29 = 15;
          }
          else if ( *(_BYTE *)(v25 + 3462) )
          {
            v29 = 14;
          }
          else if ( *(_BYTE *)(v25 + 3461) )
          {
            v29 = 13;
          }
          else if ( *(_BYTE *)(v25 + 3460) )
          {
            v29 = 12;
          }
          else if ( *(_BYTE *)(v25 + 3459) )
          {
            v29 = 11;
          }
          else if ( *(_BYTE *)(v25 + 3458) )
          {
            v29 = 10;
          }
          else if ( *(_BYTE *)(v25 + 3457) )
          {
            v29 = 9;
          }
          else if ( *(_BYTE *)(v25 + 3456) )
          {
            v29 = 8;
          }
          else if ( *(_BYTE *)(v25 + 3455) )
          {
            v29 = 7;
          }
          else if ( *(_BYTE *)(v25 + 3454) )
          {
            v29 = 6;
          }
          else if ( *(_BYTE *)(v25 + 3453) )
          {
            v29 = 5;
          }
          else if ( *(_BYTE *)(v25 + 3452) )
          {
            v29 = 4;
          }
          else if ( *(_BYTE *)(v25 + 3451) )
          {
            v29 = 3;
          }
          else if ( *(_BYTE *)(v25 + 3450) )
          {
            v29 = 2;
          }
          else
          {
            v29 = *(_BYTE *)(v25 + 3449) != 0;
          }
        }
      }
      else
      {
        v29 = 0;
      }
      *(_BYTE *)(v25 + 3448) = v29;
      v16 = (unsigned int *)*(unsigned int *)(*(_QWORD *)(a1 + 8) + 1468LL);
      *(_DWORD *)(v25 + 3476) = (_DWORD)v16;
      goto LABEL_61;
    }
LABEL_7:
    *v27 = v28 & 0xFFFFFFFFBFFFFFF9LL;
    goto LABEL_10;
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return result;
}
