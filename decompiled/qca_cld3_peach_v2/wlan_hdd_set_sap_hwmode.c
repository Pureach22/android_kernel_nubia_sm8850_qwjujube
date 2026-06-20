__int64 __fastcall wlan_hdd_set_sap_hwmode(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x20
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x4
  __int64 v13; // x20
  __int64 v14; // x19
  int v15; // w23
  unsigned __int8 *ie_ptr_from_eid; // x0
  __int64 v17; // x8
  int v18; // w22
  int v19; // w21
  char *v20; // x9
  int v21; // w15
  int v22; // w14
  int v23; // w15
  int v24; // w14
  unsigned __int8 *v25; // x0
  __int64 v26; // x8
  char *v27; // x9
  int v28; // w15
  int v29; // w14
  int v30; // w15
  int v31; // w14
  int v32; // w8
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v9 = *(__int64 **)(result + 2432);
  v10 = *v9;
  *(_DWORD *)(result + 320) = 4;
  v11 = *((int *)v9 + 8);
  v12 = v11 - 36;
  if ( (int)v11 > 36 )
  {
    v14 = result;
    v15 = 1;
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(1u, (unsigned __int8 *)(v10 + 36), v12);
    if ( ie_ptr_from_eid && (v17 = ie_ptr_from_eid[1]) != 0 )
    {
      v18 = 0;
      v19 = 0;
      v20 = (char *)(ie_ptr_from_eid + 2);
      do
      {
        v24 = (unsigned __int8)*v20;
        if ( v15
          && ((v21 = v24 & 0x7F, (unsigned int)(v21 - 12) <= 0x3C)
           && ((1LL << ((unsigned __int8)v21 - 12)) & 0x1000001001001041LL) != 0
           || v21 == 108
           || v21 == 96) )
        {
          *(_DWORD *)(v14 + 320) = 8;
          v22 = *v20;
          v15 &= ~(v22 >> 31);
          if ( v22 < 0 )
            v23 = 32;
          else
            v23 = 8;
          *(_DWORD *)(v14 + 320) = v23;
        }
        else if ( v24 == 254 )
        {
          v19 = 1;
        }
        else if ( v24 == 255 )
        {
          v18 = 1;
        }
        --v17;
        ++v20;
      }
      while ( v17 );
    }
    else
    {
      v18 = 0;
      v19 = 0;
    }
    v25 = wlan_get_ie_ptr_from_eid(0x32u, (unsigned __int8 *)v9[1], *((_DWORD *)v9 + 9));
    if ( v25 )
    {
      v26 = v25[1];
      if ( v25[1] )
      {
        v27 = (char *)(v25 + 2);
        do
        {
          v31 = (unsigned __int8)*v27;
          if ( v15
            && ((v28 = v31 & 0x7F, (unsigned int)(v28 - 12) <= 0x3C)
             && ((1LL << ((unsigned __int8)v28 - 12)) & 0x1000001001001041LL) != 0
             || v28 == 108
             || v28 == 96) )
          {
            *(_DWORD *)(v14 + 320) = 8;
            v29 = *v27;
            v15 &= ~(v29 >> 31);
            if ( v29 < 0 )
              v30 = 32;
            else
              v30 = 8;
            *(_DWORD *)(v14 + 320) = v30;
          }
          else if ( v31 == 254 )
          {
            v19 = 1;
          }
          else if ( v31 == 255 )
          {
            v18 = 1;
          }
          --v26;
          ++v27;
        }
        while ( v26 );
      }
    }
    if ( wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v14 + 720)) )
      *(_DWORD *)(v14 + 320) = 2;
    if ( wlan_get_ie_ptr_from_eid(0x2Du, (unsigned __int8 *)v9[1], *((_DWORD *)v9 + 9)) )
    {
      if ( v18 )
        v32 = 64;
      else
        v32 = 16;
      *(_DWORD *)(v14 + 320) = v32;
    }
    if ( wlan_get_ie_ptr_from_eid(0xBFu, (unsigned __int8 *)v9[1], *((_DWORD *)v9 + 9)) )
    {
      if ( v19 )
        v33 = 512;
      else
        v33 = 256;
      *(_DWORD *)(v14 + 320) = v33;
    }
    wlan_hdd_check_11ax_support(v9, v14 + 280);
    wlan_hdd_check_11be_support(v9, v14 + 280);
    return qdf_trace_msg(
             0x33u,
             8u,
             "%s: SAP hw_mode: %d",
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             "wlan_hdd_set_sap_hwmode",
             *(unsigned int *)(v14 + 320));
  }
  else
  {
    v13 = jiffies;
    if ( wlan_hdd_set_sap_hwmode___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Invalid length: %zu",
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 "wlan_hdd_set_sap_hwmode",
                 v12);
      wlan_hdd_set_sap_hwmode___last_ticks = v13;
    }
  }
  return result;
}
