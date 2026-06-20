__int64 __fastcall cm_update_link_channel_info(__int64 a1, int a2)
{
  int v2; // w19
  __int64 v4; // x24
  __int64 scan_entry_by_mac_freq; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w23
  __int64 v15; // x22
  int v16; // w21
  char v17; // w0
  int v18; // w25
  char v19; // w24
  int v20; // w26
  unsigned int v21; // w9
  __int64 result; // x0
  int v23; // w27
  __int64 v24; // x0
  int v25; // w28
  __int64 v26; // x0
  __int16 v27; // [xsp+0h] [xbp-30h] BYREF
  char v28; // [xsp+2h] [xbp-2Eh]
  _BYTE v29[13]; // [xsp+3h] [xbp-2Dh] BYREF
  int v30; // [xsp+10h] [xbp-20h]
  int v31; // [xsp+14h] [xbp-1Ch]
  int v32; // [xsp+18h] [xbp-18h]
  int v33; // [xsp+1Ch] [xbp-14h]
  __int64 v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v2 = a1;
  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 216);
  scan_entry_by_mac_freq = wlan_scan_get_scan_entry_by_mac_freq(v4);
  if ( !scan_entry_by_mac_freq )
  {
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: not found the mac_addr from scan entry",
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               "cm_update_link_channel_info");
    goto LABEL_29;
  }
  v14 = *(unsigned __int16 *)(scan_entry_by_mac_freq + 1192);
  v15 = scan_entry_by_mac_freq;
  v16 = *(unsigned __int8 *)(scan_entry_by_mac_freq + 1919);
  v17 = wlan_reg_freq_to_chan(v4, *(unsigned __int16 *)(scan_entry_by_mac_freq + 1192));
  v18 = *(_DWORD *)(v15 + 52);
  v19 = v17;
  v20 = 0;
  if ( v18 <= 22 )
  {
    if ( v18 > 16 )
    {
      if ( (unsigned int)(v18 - 17) >= 2 )
      {
        v21 = v18 - 19;
LABEL_16:
        v23 = v14;
        if ( v21 >= 2 )
          goto LABEL_24;
LABEL_21:
        v20 = 3;
        goto LABEL_23;
      }
LABEL_22:
      v20 = 2;
      goto LABEL_23;
    }
    if ( (unsigned int)(v18 - 7) >= 4 )
    {
      v23 = v14;
      if ( (unsigned int)(v18 - 13) >= 4 )
        goto LABEL_24;
    }
LABEL_13:
    v20 = 1;
LABEL_23:
    v23 = *(_DWORD *)(v15 + 1196);
    goto LABEL_24;
  }
  if ( v18 <= 32 )
  {
    if ( (unsigned int)(v18 - 23) >= 4 )
    {
      if ( (unsigned int)(v18 - 27) >= 2 )
      {
        v21 = v18 - 29;
        goto LABEL_16;
      }
      goto LABEL_22;
    }
    goto LABEL_13;
  }
  if ( v18 < 37 )
    goto LABEL_13;
  if ( v18 == 37 )
    goto LABEL_22;
  if ( v18 == 40 )
  {
    v20 = 7;
    goto LABEL_23;
  }
  v23 = v14;
  if ( v18 == 39 )
    goto LABEL_21;
LABEL_24:
  v24 = *(_QWORD *)(v15 + 1320);
  v25 = *(_DWORD *)(v15 + 1200);
  if ( v24 )
    _qdf_mem_free(v24);
  v26 = *(_QWORD *)(v15 + 1896);
  if ( v26 )
    _qdf_mem_free(v26);
  _qdf_mem_free(v15);
  v27 = v14;
  v28 = v19;
  memset(v29, 0, sizeof(v29));
  v30 = v23;
  v31 = v25;
  v32 = v20;
  v33 = v18;
  v34 = 0;
  result = mlo_mgr_update_ap_channel_info(v2, v16, a2, (int)&v27);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
