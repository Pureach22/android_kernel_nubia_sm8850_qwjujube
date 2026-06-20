__int64 __fastcall csr_save_to_channel_power2_g_5_g(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x19
  unsigned int v9; // w20
  int v10; // w8
  unsigned int v11; // w26
  unsigned int v12; // w25
  int v13; // w28
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w8
  __int64 v24; // x27
  unsigned int v25; // w26
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w26
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x9
  int v38; // w10
  int v39; // w9
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x25
  int v44; // w0
  __int64 v45; // x9
  int v46; // w10
  int v47; // w9
  int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  char v58; // [xsp+Ch] [xbp-14h]
  unsigned int v59; // [xsp+10h] [xbp-10h]
  __int64 v60; // [xsp+10h] [xbp-10h]
  unsigned int v61; // [xsp+18h] [xbp-8h]
  char v62; // [xsp+1Ch] [xbp-4h]

  v6 = _qdf_mem_malloc(0x55u, "csr_save_to_channel_power2_g_5_g", 173);
  v7 = _qdf_mem_malloc(0xA9u, "csr_save_to_channel_power2_g_5_g", 174);
  v8 = v7;
  if ( v6 && v7 )
  {
    if ( a2 <= 7 )
    {
      _qdf_mem_free(v6);
LABEL_49:
      v9 = 0;
LABEL_50:
      _qdf_mem_free(v8);
      return v9;
    }
    v10 = a2 >> 3;
    v11 = 0;
    v12 = 0;
    v62 = 0;
    v58 = 0;
    while ( 2 )
    {
      while ( 2 )
      {
        v13 = 1 - v10;
        a3 += 8;
        while ( 1 )
        {
          v14 = _qdf_mem_malloc(0x18u, "csr_save_to_channel_power2_g_5_g", 187);
          if ( v14 )
            break;
          ++v13;
          a3 += 8;
          if ( v13 == 1 )
            goto LABEL_45;
        }
        v23 = *(_DWORD *)(a3 - 8);
        v24 = v14;
        v61 = v12;
        v59 = v11;
        *(_DWORD *)(v14 + 16) = v23;
        *(_BYTE *)(v14 + 20) = *(_BYTE *)(a3 - 4);
        if ( !wlan_reg_is_24ghz_ch_freq(v23)
          || (v25 = *(_DWORD *)(v24 + 16) + 5 * *(unsigned __int8 *)(v24 + 20) - 5,
              v25 > (unsigned int)wlan_reg_max_24ghz_chan_freq()) )
        {
          if ( !wlan_reg_is_5ghz_ch_freq(*(_DWORD *)(v24 + 16))
            || (v34 = *(_DWORD *)(v24 + 16) + 20 * *(unsigned __int8 *)(v24 + 20) - 20,
                v34 > (unsigned int)wlan_reg_max_5ghz_chan_freq()) )
          {
            qdf_trace_msg(
              0x34u,
              3u,
              "%s: Invalid Channel freq %d Present in Country IE",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "csr_save_to_channel_power2_g_5_g",
              *(unsigned int *)(v24 + 16));
            _qdf_mem_free(v24);
            _qdf_mem_free(v6);
            v9 = 16;
            goto LABEL_50;
          }
          *(_BYTE *)(v24 + 22) = 20;
          v35 = v24;
          *(_BYTE *)(v24 + 21) = *(_BYTE *)(a3 - 3);
          if ( (v62 & 1) == 0 )
          {
            csr_ll_lock(a1 + 17024);
            while ( 1 )
            {
              v36 = csr_ll_remove_head(a1 + 17024, 0);
              if ( !v36 )
                break;
              _qdf_mem_free(v36);
            }
            csr_ll_unlock(a1 + 17024);
            v35 = v24;
          }
          v37 = *(_QWORD *)(a1 + 8);
          v38 = *(_DWORD *)(v37 + 1032);
          if ( v38 )
          {
            v11 = v59;
            if ( v38 != 2 )
            {
              v39 = *(_DWORD *)(v37 + 1036);
              goto LABEL_31;
            }
          }
          else
          {
            v39 = *(_DWORD *)(v37 + 1036);
            v11 = v59;
            if ( v39 )
            {
LABEL_31:
              if ( v39 != 2 )
              {
                v43 = v35;
                scnprintf(v8 + v11, 169 - v11, "  %d", *(_DWORD *)(v35 + 16));
                v11 += v44;
                _qdf_mem_free(v43);
                v62 = 1;
                goto LABEL_42;
              }
            }
          }
          v42 = a1 + 17024;
          v62 = 1;
LABEL_41:
          csr_ll_insert_tail(v42);
LABEL_42:
          v12 = v61;
          v10 = -v13;
          if ( v13 )
            continue;
LABEL_45:
          if ( v12 )
            qdf_trace_msg(0x34u, 8u, "Adding 11B/G ch in 11A:%s", v15, v16, v17, v18, v19, v20, v21, v22, v6);
          _qdf_mem_free(v6);
          if ( v11 )
            qdf_trace_msg(0x34u, 8u, "Adding 11A ch in B/G:%s", v49, v50, v51, v52, v53, v54, v55, v56, v8);
          goto LABEL_49;
        }
        break;
      }
      v40 = v24;
      *(_BYTE *)(v24 + 22) = 5;
      *(_BYTE *)(v24 + 21) = *(_BYTE *)(a3 - 3);
      if ( (v58 & 1) == 0 )
      {
        csr_ll_lock(a1 + 16936);
        while ( 1 )
        {
          v41 = csr_ll_remove_head(a1 + 16936, 0);
          if ( !v41 )
            break;
          _qdf_mem_free(v41);
        }
        csr_ll_unlock(a1 + 16936);
        v40 = v24;
      }
      v45 = *(_QWORD *)(a1 + 8);
      v46 = *(_DWORD *)(v45 + 1032);
      if ( v46 )
      {
        v11 = v59;
        if ( v46 != 1 )
        {
          v47 = *(_DWORD *)(v45 + 1036);
          goto LABEL_39;
        }
      }
      else
      {
        v47 = *(_DWORD *)(v45 + 1036);
        v11 = v59;
        if ( v47 )
        {
LABEL_39:
          if ( v47 != 1 )
          {
            v60 = v40;
            scnprintf(v6 + v12, 85 - v12, "  %d", *(_DWORD *)(v40 + 16));
            v12 += v48;
            _qdf_mem_free(v60);
            v58 = 1;
            v10 = -v13;
            if ( v13 )
              continue;
            goto LABEL_45;
          }
        }
      }
      break;
    }
    v42 = a1 + 16936;
    v58 = 1;
    goto LABEL_41;
  }
  if ( v6 )
    _qdf_mem_free(v6);
  v9 = 2;
  if ( v8 )
    goto LABEL_50;
  return v9;
}
