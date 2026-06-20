__int64 __fastcall populate_dot11f_rnr_tbtt_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int16 a5)
{
  __int16 v5; // w8
  char v11; // w24
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char sap_psd_for_20mhz; // w0
  __int64 v21; // x8
  char v22; // w22
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  char v31; // w0
  char v32; // w8
  __int16 v33; // w8
  __int64 v35; // x20
  unsigned __int8 v36; // t1

  v5 = *(_WORD *)(a4 + 1);
  *(_BYTE *)a4 = 1;
  *(_WORD *)(a4 + 1) = v5 & 0xFFFC;
  v11 = lim_op_class_from_bandwidth(a1, *(_DWORD *)(a3 + 284), *(_DWORD *)(a3 + 7176));
  sap_psd_for_20mhz = wlan_mlme_get_sap_psd_for_20mhz(*(_QWORD *)(a3 + 16), v12, v13, v14, v15, v16, v17, v18, v19);
  *(_BYTE *)(a4 + 3) = v11;
  v21 = *(_QWORD *)(a1 + 21560);
  v22 = sap_psd_for_20mhz;
  v31 = wlan_reg_freq_to_chan(v21, *(_DWORD *)(a3 + 284), v23, v24, v25, v26, v27, v28, v29, v30);
  v32 = *(_WORD *)(a4 + 1);
  *(_BYTE *)(a4 + 4) = v31;
  v33 = v32 & 0xF;
  *(_WORD *)(a4 + 1) = v33 | (a5 << 8);
  switch ( (unsigned __int8)a5 )
  {
    case 0xDu:
      *(_BYTE *)(a4 + 8) = -1;
      qdf_mem_copy((void *)(a4 + 9), (const void *)(a3 + 30), 6u);
      v36 = *(_BYTE *)(a3 + 36);
      v35 = a3 + 36;
      *(_DWORD *)(a4 + 16) = wlan_construct_shortssid((char *)(v35 + 1), v36);
      *(_BYTE *)(a4 + 20) = 64;
      if ( (unsigned int)lim_cmp_ssid((unsigned __int8 *)v35, a2) )
      {
        if ( v22 )
        {
LABEL_10:
          *(_BYTE *)(a4 + 21) = v22;
          return 0;
        }
      }
      else
      {
        *(_BYTE *)(a4 + 20) |= 2u;
        if ( v22 )
          goto LABEL_10;
      }
      *(_BYTE *)(a4 + 21) = 127;
      return 0;
    case 9u:
      *(_BYTE *)(a4 + 8) = -1;
      qdf_mem_copy((void *)(a4 + 9), (const void *)(a3 + 30), 6u);
      *(_BYTE *)(a4 + 15) = 64;
      if ( (unsigned int)lim_cmp_ssid((unsigned __int8 *)(a3 + 36), a2) )
      {
        if ( v22 )
        {
LABEL_7:
          *(_BYTE *)(a4 + 16) = v22;
          return 0;
        }
      }
      else
      {
        *(_BYTE *)(a4 + 15) |= 2u;
        if ( v22 )
          goto LABEL_7;
      }
      *(_BYTE *)(a4 + 16) = 127;
      return 0;
    case 7u:
      *(_BYTE *)(a4 + 8) = -1;
      qdf_mem_copy((void *)(a4 + 9), (const void *)(a3 + 30), 6u);
      return 0;
    default:
      *(_WORD *)(a4 + 1) = v33;
      return 16;
  }
}
