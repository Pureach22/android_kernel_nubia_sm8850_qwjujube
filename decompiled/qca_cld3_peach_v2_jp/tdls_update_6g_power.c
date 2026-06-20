__int64 __fastcall tdls_update_6g_power(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x24
  __int64 v7; // x20
  unsigned int operation_chan_freq; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  unsigned int v27; // w1
  const char *v28; // x2
  __int64 result; // x0
  __int64 v30; // x21
  char v31; // w8
  char v32; // w8
  unsigned __int8 mlme_ch_power; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w8
  int v51; // w24
  __int64 _6g_pwr_for_power_type; // x0
  __int64 v53; // x8
  __int64 (__fastcall *v54)(__int64, __int64, __int64); // x8
  __int64 v55; // x1

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
    v7 = *(_QWORD *)(v3 + 80);
  else
    v7 = 0;
  operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a1);
  if ( !v3 || !v7 )
  {
    v28 = "%s: psoc or pdev is NULL";
    return qdf_trace_msg(0, 2u, v28, v9, v10, v11, v12, v13, v14, v15, v16, "tdls_update_6g_power");
  }
  v17 = operation_chan_freq;
  if ( (tdls_is_6g_freq_allowed(v3, operation_chan_freq) & 1) == 0 )
  {
    v26 = "%s: VLP not supported or non-psc freq %d";
    v27 = 2;
    return qdf_trace_msg(0, v27, v26, v18, v19, v20, v21, v22, v23, v24, v25, "tdls_update_6g_power");
  }
  if ( *(_WORD *)(a2 + 202) )
  {
    v26 = "%s: Number of connected peer %d";
    v27 = 8;
    return qdf_trace_msg(0, v27, v26, v18, v19, v20, v21, v22, v23, v24, v25, "tdls_update_6g_power");
  }
  result = wlan_vdev_mlme_get_cmpt_obj(a1, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( !result )
  {
    v28 = "%s: vdev component object is NULL";
    return qdf_trace_msg(0, 2u, v28, v9, v10, v11, v12, v13, v14, v15, v16, "tdls_update_6g_power");
  }
  v30 = result;
  if ( (a3 & 1) != 0 )
  {
    v31 = *(_BYTE *)(result + 532);
    *(_BYTE *)(a2 + 619) = v31;
    if ( (v31 & 0xFE) == 2 )
      return result;
    if ( (wlan_reg_is_indoor_ap_detected(v3, v9, v10, v11, v12, v13, v14, v15, v16) & 1) != 0 )
      v32 = 3;
    else
      v32 = 2;
    *(_BYTE *)(v30 + 532) = v32;
    mlme_ch_power = tdls_get_mlme_ch_power(v30, v17);
    *(_BYTE *)(a2 + 618) = mlme_ch_power;
    qdf_trace_msg(
      0,
      8u,
      "%s: Updated power_type from %d to %d bss link power %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "tdls_update_6g_power",
      *(unsigned __int8 *)(a2 + 619),
      *(unsigned __int8 *)(v30 + 532),
      mlme_ch_power);
    v50 = *(unsigned __int8 *)(v30 + 532);
  }
  else
  {
    if ( (*(_BYTE *)(a2 + 619) & 0xFE) == 2 )
      return result;
    qdf_trace_msg(
      0,
      8u,
      "%s: Updated power_type_6g from %d to %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "tdls_update_6g_power",
      *(unsigned __int8 *)(result + 532));
    v50 = *(unsigned __int8 *)(a2 + 619);
    *(_BYTE *)(v30 + 532) = v50;
  }
  v51 = *(unsigned __int8 *)(v30 + 533);
  if ( v50 == 3 )
  {
    _6g_pwr_for_power_type = tdls_get_6g_pwr_for_power_type(a1, v17, 11);
  }
  else if ( v50 == 2 )
  {
    _6g_pwr_for_power_type = tdls_get_6g_pwr_for_power_type(a1, v17, 6);
  }
  else
  {
    _6g_pwr_for_power_type = *(unsigned __int8 *)(a2 + 618);
  }
  if ( !v51 )
    goto LABEL_34;
  if ( *(_DWORD *)(v30 + 636) != v17 )
  {
    if ( v51 != 1 )
    {
      if ( *(_DWORD *)(v30 + 644) == v17 )
      {
        v53 = 1;
        goto LABEL_32;
      }
      if ( v51 != 2 )
      {
        if ( *(_DWORD *)(v30 + 652) == v17 )
        {
          v53 = 2;
          goto LABEL_32;
        }
        if ( v51 != 3 )
        {
          if ( *(_DWORD *)(v30 + 660) == v17 )
          {
            v53 = 3;
            goto LABEL_32;
          }
          if ( v51 != 4 )
          {
            if ( *(_DWORD *)(v30 + 668) == v17 )
            {
              v53 = 4;
              goto LABEL_32;
            }
            if ( v51 != 5 )
            {
              if ( *(_DWORD *)(v30 + 676) == v17 )
              {
                v53 = 5;
                goto LABEL_32;
              }
              if ( v51 != 6 )
              {
                if ( *(_DWORD *)(v30 + 684) == v17 )
                {
                  v53 = 6;
                  goto LABEL_32;
                }
                if ( v51 != 7 )
                {
                  if ( *(_DWORD *)(v30 + 692) == v17 )
                  {
                    v53 = 7;
                    goto LABEL_32;
                  }
                  if ( v51 != 8 )
                  {
                    if ( *(_DWORD *)(v30 + 700) == v17 )
                    {
                      v53 = 8;
                      goto LABEL_32;
                    }
                    if ( v51 != 9 )
                    {
                      if ( *(_DWORD *)(v30 + 708) == v17 )
                      {
                        v53 = 9;
                        goto LABEL_32;
                      }
                      if ( v51 != 10 )
                      {
                        if ( *(_DWORD *)(v30 + 716) == v17 )
                        {
                          v53 = 10;
                          goto LABEL_32;
                        }
                        if ( v51 != 11 )
                        {
                          if ( *(_DWORD *)(v30 + 724) == v17 )
                          {
                            v53 = 11;
                            goto LABEL_32;
                          }
                          if ( v51 != 12 )
                          {
                            if ( *(_DWORD *)(v30 + 732) == v17 )
                            {
                              v53 = 12;
                              goto LABEL_32;
                            }
                            if ( v51 != 13 )
                            {
                              if ( *(_DWORD *)(v30 + 740) == v17 )
                              {
                                v53 = 13;
                                goto LABEL_32;
                              }
                              if ( v51 != 14 )
                              {
                                if ( *(_DWORD *)(v30 + 748) == v17 )
                                {
                                  v53 = 14;
                                  goto LABEL_32;
                                }
                                if ( v51 != 15 )
                                {
                                  if ( *(_DWORD *)(v30 + 756) == v17 )
                                  {
                                    v53 = 15;
                                    goto LABEL_32;
                                  }
                                  if ( v51 != 16 )
                                  {
                                    __break(0x5512u);
                                    return tdls_release_serialization_command(_6g_pwr_for_power_type);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_34:
    qdf_trace_msg(
      0,
      8u,
      "%s: channel %d not present in reg power info",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "tdls_set_mlme_ch_power",
      v17);
    goto LABEL_35;
  }
  v53 = 0;
LABEL_32:
  *(_WORD *)(v30 + 636 + 8 * v53 + 4) = (unsigned __int8)_6g_pwr_for_power_type;
LABEL_35:
  result = wlan_reg_get_tx_ops(v7, v42, v43, v44, v45, v46, v47, v48, v49);
  if ( result )
  {
    v54 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(result + 144);
    if ( v54 )
    {
      v55 = *(unsigned __int8 *)(a1 + 104);
      if ( *((_DWORD *)v54 - 1) != 1094041931 )
        __break(0x8228u);
      return v54(v7, v55, v30 + 528);
    }
  }
  return result;
}
