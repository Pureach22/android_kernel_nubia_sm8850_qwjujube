__int64 __fastcall hdd_update_phymode(_QWORD *a1, int a2, unsigned __int8 a3, unsigned int a4)
{
  __int64 v8; // x19
  __int64 v9; // x21
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w26
  unsigned int phy_mode; // w25
  __int64 v21; // x0
  __int64 v22; // x21
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  unsigned int v33; // w20
  __int64 v34; // x0
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a1[3];
  v9 = a1[4];
  result = _wlan_hdd_validate_context(v8, "hdd_update_phymode");
  if ( (result & 0x80000000) == 0 )
  {
    if ( a2 > 255 )
    {
      v19 = 0;
      if ( a2 > 2047 )
      {
        if ( a2 == 2048 )
        {
          v19 = 12;
          goto LABEL_21;
        }
        if ( a2 == 0x2000 )
          goto LABEL_21;
      }
      else
      {
        if ( a2 == 256 )
        {
          v19 = 9;
          goto LABEL_21;
        }
        if ( a2 == 1024 )
          goto LABEL_21;
      }
    }
    else
    {
      if ( a2 <= 7 )
      {
        if ( a2 != 2 )
        {
          if ( a2 == 4 )
          {
            v19 = 2;
            goto LABEL_21;
          }
          goto LABEL_16;
        }
        v19 = 10;
LABEL_21:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: phymode=%d bonding_mode=%d supported_band=%d",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "hdd_update_phymode",
          (unsigned int)a2,
          a4,
          a3);
        phy_mode = sme_get_phy_mode(*(_QWORD *)(v8 + 16));
        sme_set_phy_mode(*(_QWORD *)(v8 + 16), (unsigned int)a2);
        if ( (unsigned int)hdd_reg_set_band(v9, a3) )
        {
          sme_set_phy_mode(*(_QWORD *)(v8 + 16), phy_mode);
          result = 4294967291LL;
          goto LABEL_32;
        }
        v21 = _qdf_mem_malloc(0x4E4u, "hdd_update_phymode", 2198);
        if ( !v21 )
        {
          result = 4294967284LL;
          goto LABEL_32;
        }
        v22 = v21;
        sme_get_config_param(*(_QWORD *)(v8 + 16), v21);
        *(_DWORD *)(v22 + 8) = a2;
        if ( a2 == 16 )
        {
          v23 = a1[3];
          *(_BYTE *)(v22 + 1235) = a4 == 1;
          if ( (unsigned int)sme_set_ht2040_mode(*(_QWORD *)(v23 + 16), *(unsigned __int8 *)(a1[6603] + 8LL), 1) )
          {
            v32 = "%s: Failed to set ht2040 mode";
            goto LABEL_29;
          }
        }
        if ( (unsigned int)wlan_mlme_set_band_capability(*(_QWORD *)v8, a3) )
        {
          v32 = "%s: failed to set MLME band capability";
          goto LABEL_29;
        }
        if ( a3 == 1 )
        {
          if ( (unsigned int)wlan_mlme_set_11h_enabled(*(_QWORD *)v8, 0) )
          {
            v32 = "%s: Failed to set 11h_enable flag";
            goto LABEL_29;
          }
        }
        else if ( (a3 & 1) == 0 )
        {
LABEL_38:
          if ( (a3 & 2) != 0 )
            *(_DWORD *)(v22 + 4) = a4;
          sme_update_config(*(_QWORD *)(v8 + 16), v22);
          **(_DWORD **)(v8 + 104) = v19;
          ucfg_mlme_set_channel_bonding_24ghz(*(_QWORD *)v8, *(_DWORD *)v22);
          ucfg_mlme_set_channel_bonding_5ghz(*(_QWORD *)v8, *(_DWORD *)(v22 + 4));
          if ( hdd_update_config_cfg() )
          {
            if ( (a3 & 2) != 0 )
            {
              v34 = *(_QWORD *)v8;
              v35 = 0;
              ucfg_mlme_get_channel_bonding_5ghz(v34, &v35);
              v33 = 0;
              *(_WORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 24) + 336LL) + 28LL) = *(_WORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 24)
                                                                                                  + 336LL)
                                                                                      + 28LL)
                                                                           & 0xFFFD
                                                                           | (2 * (v35 != 0));
            }
            else
            {
              v33 = 0;
            }
            goto LABEL_30;
          }
          v32 = "%s: could not update config_dat";
LABEL_29:
          qdf_trace_msg(0x33u, 2u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "hdd_update_phymode");
          v33 = -5;
LABEL_30:
          _qdf_mem_free(v22);
          result = v33;
          goto LABEL_32;
        }
        *(_DWORD *)v22 = a4;
        goto LABEL_38;
      }
      if ( a2 == 8 )
      {
        v19 = 3;
        goto LABEL_21;
      }
      if ( a2 == 16 )
      {
        v19 = 4;
        goto LABEL_21;
      }
    }
LABEL_16:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Not supported mode %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_phymode_to_dot11_mode",
      (unsigned int)a2);
    result = 4294967274LL;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
