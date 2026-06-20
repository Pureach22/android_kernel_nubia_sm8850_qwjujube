__int64 __fastcall hal_rx_fst_attach(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        unsigned __int16 a4,
        __int16 a5,
        __int64 a6,
        __int64 a7)
{
  void *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  void *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 (__fastcall *v33)(_QWORD); // x8
  unsigned int v34; // w0
  unsigned int v35; // w22
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7

  v14 = (void *)_qdf_mem_malloc(0x30u, "hal_rx_fst_attach", 420);
  v23 = (__int64)v14;
  if ( v14 )
  {
    v24 = qdf_mem_set(v14, 0x30u, 0);
    *(_QWORD *)(v23 + 16) = a6;
    *(_WORD *)(v23 + 26) = a5;
    *(_WORD *)(v23 + 24) = a4;
    *(_WORD *)(v23 + 28) = a4 - 1;
    v33 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 74392) + 1056LL);
    if ( v33 )
    {
      if ( *((_DWORD *)v33 - 1) != -605791253 )
        __break(0x8228u);
      v34 = v33(v24);
      a4 = *(_WORD *)(v23 + 24);
      v35 = v34;
    }
    else
    {
      v35 = 0;
    }
    *(_DWORD *)(v23 + 40) = v35;
    qdf_trace_msg(0x3Fu, 8u, "HAL FST allocation %pK %d * %d\n", v25, v26, v27, v28, v29, v30, v31, v32, v23, a4, v35);
    ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)("hal_rx_fst", v23, 48);
    if ( a7 )
    {
      *a3 = a7;
    }
    else
    {
      v36 = _qdf_mem_alloc_consistent(
              a2,
              *(_QWORD *)(a2 + 40),
              v35 * *(unsigned __int16 *)(v23 + 24),
              v23 + 8,
              "hal_rx_fst_attach",
              449);
      *(_QWORD *)v23 = v36;
      if ( v36 )
      {
        ((void (__fastcall *)(const char *, __int64, _QWORD))qdf_ssr_driver_dump_register_region)(
          "dp_fisa_hw_fse_table",
          v36,
          v35 * *(unsigned __int16 *)(v23 + 24));
        *a3 = *(_QWORD *)(v23 + 8);
        qdf_trace_msg(0x3Fu, 4u, "hal_rx_fst base address 0x%pK", v45, v46, v47, v48, v49, v50, v51, v52);
        ((void (__fastcall *)(__int64, __int64, _QWORD, __int64))qdf_trace_hex_dump)(166, 8, *(_QWORD *)(v23 + 16), 40);
        qdf_mem_set(*(void **)v23, v35 * *(unsigned __int16 *)(v23 + 24), 0);
      }
      else
      {
        qdf_trace_msg(
          0x3Fu,
          2u,
          "%s: hal fst->base_vaddr allocation failed",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "hal_rx_fst_attach");
        _qdf_mem_free(v23);
        return 0;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s: hal fst allocation failed",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hal_rx_fst_attach");
  }
  return v23;
}
