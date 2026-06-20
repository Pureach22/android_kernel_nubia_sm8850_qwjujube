__int64 __fastcall wifi_pos_populate_caps(__int64 a1, __int64 a2)
{
  __int64 psoc; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 psoc_priv_obj; // x0
  __int64 v22; // x22
  __int64 v23; // x0
  unsigned __int16 *v24; // x20
  __int16 v25; // w8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 is_6ghz_chan_freq; // x0
  __int64 v36; // x1
  unsigned __int64 v37; // x22
  unsigned int v38; // w21
  _BYTE *v39; // x24

  psoc = wifi_pos_get_psoc(a1);
  qdf_trace_msg(0x25u, 8u, "%s: Enter", v5, v6, v7, v8, v9, v10, v11, v12, "wifi_pos_populate_caps");
  if ( psoc && (psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc)) != 0 )
  {
    v22 = psoc_priv_obj;
    v23 = _qdf_mem_malloc(0x992u, "wifi_pos_populate_caps", 1316);
    if ( v23 )
    {
      v24 = (unsigned __int16 *)v23;
      sized_strscpy(a2, "QUALCOMM", 8);
      *(_DWORD *)(a2 + 8) = *(_DWORD *)(v22 + 16);
      *(_DWORD *)(a2 + 12) = *(_DWORD *)(v22 + 20);
      *(_BYTE *)(a2 + 16) = *(_BYTE *)(v22 + 24);
      *(_BYTE *)(a2 + 17) = *(_BYTE *)(v22 + 25);
      *(_BYTE *)(a2 + 18) = *(_BYTE *)(v22 + 26);
      *(_BYTE *)(a2 + 19) = *(_BYTE *)(v22 + 27);
      *(_WORD *)(a2 + 20) = *(_WORD *)(v22 + 28);
      *(_WORD *)(a2 + 22) = *(_WORD *)(v22 + 30);
      *(_WORD *)(a2 + 24) = *(_WORD *)(v22 + 32);
      *(_WORD *)(a2 + 26) = *(_WORD *)(v22 + 34);
      if ( a1 )
        v25 = *(unsigned __int8 *)(a1 + 45);
      else
        v25 = 0;
      *(_WORD *)(a2 + 28) = v25;
      wlan_objmgr_iterate_obj_list(a1, 1, wifi_pos_pdev_iterator, (__int64)v24, 1, 0xDu);
      is_6ghz_chan_freq = qdf_trace_msg(
                            0x25u,
                            8u,
                            "%s: num channels: %d",
                            v27,
                            v28,
                            v29,
                            v30,
                            v31,
                            v32,
                            v33,
                            v34,
                            "wifi_pos_get_ch_info",
                            *v24);
      if ( *v24 )
      {
        v37 = 0;
        v38 = 0;
        v39 = v24 + 3;
        while ( v37 != 102 )
        {
          is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*((_DWORD *)v39 - 1));
          if ( (is_6ghz_chan_freq & 1) == 0 )
          {
            if ( v38 > 0x7F )
              break;
            *(_BYTE *)(a2 + 32 + v38++) = *v39;
          }
          ++v37;
          v39 += 24;
          if ( v37 >= *v24 )
            goto LABEL_17;
        }
        __break(0x5512u);
        return wifi_pos_get_ch_info(is_6ghz_chan_freq, v36);
      }
      else
      {
        LOWORD(v38) = 0;
LABEL_17:
        *(_WORD *)(a2 + 30) = v38;
        _qdf_mem_free((__int64)v24);
        return 0;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: wifi_pos_obj is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wifi_pos_populate_caps");
    return 29;
  }
}
