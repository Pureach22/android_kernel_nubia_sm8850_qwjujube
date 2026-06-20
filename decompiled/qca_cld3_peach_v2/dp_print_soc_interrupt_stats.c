__int64 __fastcall dp_print_soc_interrupt_stats(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x23
  __int64 result; // x0
  int v5; // w0
  int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w28
  unsigned int v16; // w24
  _BYTE *v17; // x26
  int v18; // w4
  int v19; // w0
  int v20; // w27
  int v21; // w4
  int v22; // w0
  int v23; // w4
  int v24; // w0
  int v25; // w4
  int v26; // w0
  int v27; // w4
  int v28; // w0
  unsigned int v29; // w24
  _BYTE *v30; // x26
  int v31; // w4
  int v32; // w0
  int v33; // w27
  int v34; // w4
  int v35; // w0
  int v36; // w4
  int v37; // w0
  int v38; // w4
  int v39; // w0
  int v40; // w4
  int v41; // w0
  int v42; // w4
  int v43; // w0
  int v44; // w4
  int v45; // w0
  int v46; // w4
  int v47; // w0
  int v48; // w0
  int v49; // w0
  int v50; // w0
  int v51; // w0
  int v52; // w0
  _BYTE v53[512]; // [xsp+0h] [xbp-210h] BYREF
  __int64 v54; // [xsp+200h] [xbp-10h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v53, 0, sizeof(v53));
  v2 = 0;
  v3 = a1 + 7848;
  do
  {
    result = (__int64)qdf_mem_set(v53, 0x200u, 0);
    if ( !*(_DWORD *)(v3 + 184) && !*(_DWORD *)(v3 + 180) )
      goto LABEL_3;
    v5 = ((__int64 (__fastcall *)(_QWORD, _QWORD))hif_get_int_ctx_irq_num)(*(_QWORD *)(a1 + 64), (unsigned int)v2);
    v7 = scnprintf(v53, 512, "%2u[%3d] - Total:%u ", v2, v5, *(_DWORD *)(v3 + 184));
    v15 = v6;
    if ( *(_BYTE *)v3 )
    {
      v16 = 512 - v6;
      if ( 512 - v6 < 1 || (v17 = &v53[v6]) == nullptr )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: incorrect buf or buf_len(%d)!",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "dp_fill_tx_interrupt_ctx_stats",
          v16);
        v20 = 0;
LABEL_19:
        v15 += v20;
        goto LABEL_20;
      }
      v18 = *(_DWORD *)(v3 + 36);
      if ( v18 )
      {
        v7 = scnprintf(&v53[v6], (unsigned int)(512 - v6), "tx_comps[%u]:%u ", 0, v18);
        v20 = v19;
        v21 = *(_DWORD *)(v3 + 40);
        if ( !v21 )
        {
LABEL_12:
          v23 = *(_DWORD *)(v3 + 44);
          if ( v23 )
          {
            v7 = scnprintf(&v17[v20], (int)(v16 - v20), "tx_comps[%u]:%u ", 2, v23);
            v20 += v24;
          }
          v25 = *(_DWORD *)(v3 + 48);
          if ( v25 )
          {
            v7 = scnprintf(&v17[v20], (int)(v16 - v20), "tx_comps[%u]:%u ", 3, v25);
            v20 += v26;
          }
          v27 = *(_DWORD *)(v3 + 52);
          if ( v27 )
          {
            v7 = scnprintf(&v17[v20], (int)(v16 - v20), "tx_comps[%u]:%u ", 4, v27);
            v20 += v28;
          }
          goto LABEL_19;
        }
      }
      else
      {
        v20 = 0;
        v21 = *(_DWORD *)(v3 + 40);
        if ( !v21 )
          goto LABEL_12;
      }
      v7 = scnprintf(&v17[v20], (int)(v16 - v20), "tx_comps[%u]:%u ", 1, v21);
      v20 += v22;
      goto LABEL_12;
    }
LABEL_20:
    if ( *(_BYTE *)(v3 + 1) )
    {
      v29 = 512 - v15;
      if ( 512 - v15 < 1 || (v30 = &v53[v15]) == nullptr )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: incorrect buf or buf_len(%d)!",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "dp_fill_rx_interrupt_ctx_stats",
          v29);
        v33 = 0;
LABEL_39:
        v15 += v33;
        goto LABEL_40;
      }
      v31 = *(_DWORD *)(v3 + 56);
      if ( v31 )
      {
        v7 = scnprintf(&v53[v15], (unsigned int)(512 - v15), "reo[%u]:%u ", 0, v31);
        v33 = v32;
        v34 = *(_DWORD *)(v3 + 60);
        if ( !v34 )
        {
LABEL_26:
          v36 = *(_DWORD *)(v3 + 64);
          if ( v36 )
          {
            v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 2, v36);
            v33 += v37;
          }
          v38 = *(_DWORD *)(v3 + 68);
          if ( v38 )
          {
            v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 3, v38);
            v33 += v39;
          }
          v40 = *(_DWORD *)(v3 + 72);
          if ( v40 )
          {
            v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 4, v40);
            v33 += v41;
          }
          v42 = *(_DWORD *)(v3 + 76);
          if ( v42 )
          {
            v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 5, v42);
            v33 += v43;
          }
          v44 = *(_DWORD *)(v3 + 80);
          if ( v44 )
          {
            v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 6, v44);
            v33 += v45;
          }
          v46 = *(_DWORD *)(v3 + 84);
          if ( v46 )
          {
            v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 7, v46);
            v33 += v47;
          }
          goto LABEL_39;
        }
      }
      else
      {
        v33 = 0;
        v34 = *(_DWORD *)(v3 + 60);
        if ( !v34 )
          goto LABEL_26;
      }
      v7 = scnprintf(&v30[v33], (int)(v29 - v33), "reo[%u]:%u ", 1, v34);
      v33 += v35;
      goto LABEL_26;
    }
LABEL_40:
    if ( *(_BYTE *)(v3 + 3) )
    {
      v7 = scnprintf(&v53[v15], 512 - v15, "reo_err:%u ", *(_DWORD *)(v3 + 92));
      v15 += v48;
    }
    if ( *(_BYTE *)(v3 + 4) )
    {
      v7 = scnprintf(&v53[v15], 512 - v15, "wbm_rx_err:%u ", *(_DWORD *)(v3 + 96));
      v15 += v49;
    }
    if ( *(_BYTE *)(v3 + 6) )
    {
      v7 = scnprintf(&v53[v15], 512 - v15, "rxdma2_host_err:%u ", *(_DWORD *)(v3 + 104));
      v15 += v50;
    }
    if ( *(_BYTE *)(v3 + 9) )
    {
      v7 = scnprintf(&v53[v15], 512 - v15, "rx_near_full_grp_1:%u ", *(_DWORD *)(v3 + 180));
      v15 += v51;
    }
    if ( *(_BYTE *)(v3 + 10) )
    {
      v7 = scnprintf(&v53[v15], 512 - v15, "rx_near_full_grp_2:%u ", *(_DWORD *)(v3 + 180));
      v15 += v52;
    }
    if ( *(_BYTE *)(v3 + 11) )
      v7 = scnprintf(&v53[v15], 512 - v15, "tx_near_full:%u ", *(_DWORD *)(v3 + 180));
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: %s",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "dp_print_soc_interrupt_stats",
               v53);
LABEL_3:
    ++v2;
    v3 += 200;
  }
  while ( v2 != 18 );
  _ReadStatusReg(SP_EL0);
  return result;
}
