__int64 __fastcall wlan_hdd_validate_operation_channel(__int64 *a1, int a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  __int64 result; // x0
  void *v15; // x0
  __int64 v16; // x20
  __int64 v17; // x8
  unsigned int v18; // w19
  _BYTE v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v19[0] = 0;
  if ( (unsigned int)wlan_mlme_get_sap_allow_all_channels(v4, v19) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to fetch sap allow all channels",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_hdd_validate_operation_channel");
  if ( v19[0] == 1 )
  {
    v13 = 0;
    while ( (unsigned int)wlan_reg_ch_to_freq(v13) != a2 )
    {
      if ( ++v13 == 102 )
      {
        result = 4;
        goto LABEL_17;
      }
    }
    result = 0;
  }
  else
  {
    v15 = (void *)_qdf_mem_malloc(0xE58u, "wlan_hdd_validate_operation_channel", 27277);
    if ( v15 )
    {
      v16 = (__int64)v15;
      if ( (unsigned int)wlan_reg_get_secondary_current_chan_list(a1[1], v15) )
      {
LABEL_13:
        v18 = 4;
      }
      else
      {
        v17 = 0;
        while ( *(_DWORD *)(v16 + v17) != a2 )
        {
          v17 += 36;
          if ( v17 == 3672 )
            goto LABEL_13;
        }
        v18 = 4 * ((*(_DWORD *)(v16 + v17 + 8) & 0xFFFFFFFB) == 0);
      }
      _qdf_mem_free(v16);
      result = v18;
    }
    else
    {
      result = 2;
    }
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
