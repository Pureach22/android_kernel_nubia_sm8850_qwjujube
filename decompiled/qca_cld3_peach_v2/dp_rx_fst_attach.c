__int64 __fastcall dp_rx_fst_attach(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 result; // x0
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x19
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 (*v24)(void); // x8
  int v25; // w0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 (*v28)(void); // x8
  int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  unsigned __int64 v39; // x9
  _BYTE *v40; // x10
  _QWORD *v41; // x8
  unsigned __int64 v42; // x3
  unsigned int v43; // w20
  const char *v44; // x2
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  char is_rx_hash_enabled; // w0
  char v55; // w8
  __int64 v56; // x3
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // [xsp+0h] [xbp-20h]
  __int64 v74; // [xsp+18h] [xbp-8h]

  v74 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 240);
  v73 = 0;
  if ( (*(_BYTE *)(a1 + 218) & 1) == 0 )
  {
    qdf_trace_msg(0x45u, 2u, "%s: RX FISA feature is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "dp_rx_fst_attach");
    result = 11;
    goto LABEL_5;
  }
  if ( !*(_QWORD *)(a1 + 1480) )
  {
    v12 = _qdf_mem_malloc(0x280u, "dp_rx_fst_attach", 452);
    if ( !v12 )
    {
      result = 2;
      goto LABEL_5;
    }
    *(_WORD *)(v12 + 632) = 0;
    v21 = (__int64 *)v12;
    v22 = *(_QWORD *)(a1 + 240);
    if ( v22 && *(_QWORD *)v22 )
    {
      v23 = *(_QWORD *)(*(_QWORD *)v22 + 8LL);
      if ( v23 )
      {
        v24 = *(__int64 (**)(void))(v23 + 192);
        if ( v24 )
        {
          if ( *((_DWORD *)v24 - 1) != 875927212 )
            __break(0x8228u);
          v25 = v24();
          if ( !v25 )
          {
            *((_WORD *)v21 + 316) = 0;
            v26 = *(_QWORD *)(a1 + 240);
            if ( v26 && *(_QWORD *)v26 )
            {
              v27 = *(_QWORD *)(*(_QWORD *)v26 + 8LL);
              if ( v27 )
              {
                v28 = *(__int64 (**)(void))(v27 + 192);
                if ( v28 )
                {
                  if ( *((_DWORD *)v28 - 1) != 875927212 )
                    __break(0x8228u);
                  v29 = v28();
                  if ( !v29 )
                  {
                    *((_WORD *)v21 + 18) = 0;
                    *((_WORD *)v21 + 16) = 0;
                    v21[78] = 0;
                    *((_DWORD *)v21 + 10) = -1;
                    *((_WORD *)v21 + 17) = 0;
                    qdf_trace_msg(
                      0x45u,
                      5u,
                      "%s: FST setup params FT size %d, hash_mask 0x%x, skid_length %d",
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      "dp_rx_fst_attach");
                    v38 = dp_context_alloc_mem(
                            v9,
                            6u,
                            336LL * *((unsigned __int16 *)v21 + 16),
                            v30,
                            v31,
                            v32,
                            v33,
                            v34,
                            v35,
                            v36,
                            v37);
                    *v21 = v38;
                    if ( v38 )
                    {
                      if ( *((_WORD *)v21 + 16) )
                      {
                        v39 = 0;
                        v40 = (_BYTE *)(v38 + 144);
                        v41 = (_QWORD *)a1;
                        do
                        {
                          *v40 = -1;
                          ++v39;
                          v40 += 336;
                          v42 = *((unsigned __int16 *)v21 + 16);
                        }
                        while ( v39 < v42 );
                      }
                      else
                      {
                        v42 = 0;
                        v41 = (_QWORD *)a1;
                      }
                      v45 = hal_rx_fst_attach(
                              v41[32],
                              v41[2],
                              v21 + 3,
                              v42,
                              *((unsigned __int16 *)v21 + 18),
                              v21[78],
                              v41[186]);
                      v21[2] = v45;
                      if ( v45 )
                      {
                        *((_DWORD *)v21 + 12) = 0;
                        v21[7] = 0;
                        v21[17] = (__int64)dp_fisa_fse_cache_flush_timer;
                        v21[18] = a1;
                        init_timer_key(v21 + 12, _os_timer_shim_14, 0, 0, 0);
                        *((_DWORD *)v21 + 22) = 0;
                        *((_BYTE *)v21 + 152) = 1;
                        is_rx_hash_enabled = wlan_cfg_is_rx_hash_enabled(*(_QWORD *)(v9 + 40));
                        v21[10] = v9;
                        v21[1] = a1;
                        *((_BYTE *)v21 + 617) = is_rx_hash_enabled & 1;
                        v55 = *(_BYTE *)(a1 + 219);
                        *(_QWORD *)(a1 + 1480) = v21;
                        *(_BYTE *)(a1 + 1497) = 1;
                        *(_BYTE *)(a1 + 1498) = v55;
                        *(_DWORD *)(a1 + 1500) = 0;
                        *((_DWORD *)v21 + 153) = 0;
                        v56 = *((unsigned __int16 *)v21 + 16);
                        *((_BYTE *)v21 + 634) = 1;
                        qdf_trace_msg(
                          0xA6u,
                          2u,
                          "Rx FST attach successful, #entries:%d\n",
                          v57,
                          v58,
                          v59,
                          v60,
                          v61,
                          v62,
                          v63,
                          v64,
                          v56);
                        ((void (__fastcall *)(const char *, __int64 *, __int64))qdf_ssr_driver_dump_register_region)(
                          "dp_fisa",
                          v21,
                          640);
                        ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(
                          "dp_fisa_sw_fse_table",
                          *v21,
                          336LL * *((unsigned __int16 *)v21 + 16));
                        result = 0;
                        goto LABEL_5;
                      }
                      qdf_trace_msg(
                        0xA6u,
                        2u,
                        "Rx Hal fst allocation failed, #entries:%d\n",
                        v46,
                        v47,
                        v48,
                        v49,
                        v50,
                        v51,
                        v52,
                        v53,
                        *((unsigned __int16 *)v21 + 16));
                      dp_context_free_mem(v9, 6u, *v21, v65, v66, v67, v68, v69, v70, v71, v72);
                      v43 = 0;
                    }
                    else
                    {
                      v43 = 2;
                    }
                    goto LABEL_30;
                  }
                  goto LABEL_34;
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x89u,
                8u,
                "%s: Invalid Instance:",
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                "cdp_txrx_get_psoc_param",
                0);
            }
            v29 = 16;
LABEL_34:
            v43 = v29;
            v44 = "%s: Unable to fetch fisa params";
            goto LABEL_29;
          }
LABEL_28:
          v43 = v25;
          v44 = "%s: Unable to fetch RX pkt tlv size";
LABEL_29:
          qdf_trace_msg(0x45u, 2u, v44, v13, v14, v15, v16, v17, v18, v19, v20, "dp_rx_fst_attach", v73);
LABEL_30:
          _qdf_mem_free((__int64)v21);
          result = v43;
          goto LABEL_5;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "cdp_txrx_get_psoc_param",
        0,
        0,
        0,
        v74);
    }
    v25 = 16;
    goto LABEL_28;
  }
  qdf_trace_msg(0xA6u, 2u, "RX FST already allocated\n", a2, a3, a4, a5, a6, a7, a8, a9);
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
