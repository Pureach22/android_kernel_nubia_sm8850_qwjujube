__int64 __fastcall hdd_regulatory_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  void *v5; // x22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int updated; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v25; // w9
  unsigned int v26; // w21
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  v4 = _qdf_mem_malloc(0xE58u, "hdd_regulatory_init", 2150);
  if ( !v4 )
    return 4294967284LL;
  *(_QWORD *)(a1 + 6840) = hdd_country_change_work_handle;
  v5 = (void *)v4;
  *(_QWORD *)(a1 + 6808) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 6848) = a1;
  *(_QWORD *)(a1 + 6816) = a1 + 6816;
  *(_QWORD *)(a1 + 6824) = a1 + 6816;
  v6 = *(_QWORD *)a1;
  *(_QWORD *)(a1 + 6832) = _qdf_defer_func;
  ucfg_reg_register_chan_change_callback(v6, (__int64)hdd_regulatory_dyn_cbk, 0);
  updated = hdd_update_country_code((__int64 *)a1, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( updated )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to update country code; errno:%d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_regulatory_init",
      updated);
    return 4294967274LL;
  }
  else
  {
    v25 = *(_DWORD *)(a2 + 108) | 8;
    *(_DWORD *)(a2 + 104) |= 0x80u;
    *(_DWORD *)(a2 + 108) = v25;
    *(_QWORD *)(a2 + 376) = hdd_reg_notifier;
    v26 = ucfg_reg_is_regdb_offloaded(*(_QWORD *)a1, v16, v17, v18, v19, v20, v21, v22, v23) & 1;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: regulatory offload_enabled %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "hdd_regulatory_init",
      v26);
    v35 = *(_QWORD *)(a1 + 8);
    *(_BYTE *)(a1 + 1818) = v26;
    ucfg_reg_get_current_chan_list(v35, v5);
    hdd_regulatory_chanlist_dump(v5);
    fill_wiphy_band_channels(a2, v5, 0);
    fill_wiphy_band_channels(a2, v5, 1);
    v36 = fill_wiphy_band_channels(a2, v5, 3);
    ucfg_reg_get_current_country(*(_QWORD *)a1, (void *)(a1 + 618), v36, v37, v38, v39, v40, v41, v42, v43);
    _qdf_mem_free((__int64)v5);
    return 0;
  }
}
