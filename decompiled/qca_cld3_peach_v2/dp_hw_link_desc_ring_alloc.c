__int64 __fastcall dp_hw_link_desc_ring_alloc(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int (*v3)(void); // x8
  unsigned int v5; // w21
  unsigned int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w9
  __int64 v16; // x22
  const char *v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  __int64 v27; // x23
  __int64 v28; // x0
  __int64 i; // x20

  v2 = wlan_cfg_max_alloc_size(*(_QWORD *)(a1 + 40));
  v3 = *(unsigned int (**)(void))(*(_QWORD *)(a1 + 8) + 200LL);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 1696218653 )
      __break(0x8228u);
    if ( v3() == 5 )
      return 0;
  }
  v5 = *(_DWORD *)(a1 + 1952);
  v6 = hal_srng_get_entrysize(*(_QWORD *)(a1 + 1128), 11) * v5;
  if ( v6 <= v2 )
  {
    if ( !(unsigned int)dp_srng_alloc((_QWORD *)a1, a1 + 1960, 0xBu, v5, 0) )
    {
      wlan_minidump_log(
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        *(_QWORD *)(a1 + 1968),
        *(unsigned int *)(a1 + 2000),
        *(_QWORD *)(a1 + 16));
      return 0;
    }
    qdf_trace_msg(
      0x7Cu,
      2u,
      "%s: %pK: Link desc idle ring setup failed",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dp_hw_link_desc_ring_alloc",
      a1);
  }
  else
  {
    v15 = v6 / 0x7FB8;
    if ( v6 % 0x7FB8 )
      v16 = v15 + 1;
    else
      v16 = v15;
    *(_DWORD *)(a1 + 12952) = 32704;
    if ( (unsigned int)v16 <= 0x10 )
    {
      if ( !(_DWORD)v16 )
      {
LABEL_18:
        *(_DWORD *)(a1 + 2296) = v16;
        return 0;
      }
      v26 = a1 + 2040;
      v27 = v16;
      while ( 1 )
      {
        v28 = _qdf_mem_alloc_consistent(
                *(_QWORD *)(a1 + 24),
                *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL),
                *(unsigned int *)(a1 + 12952),
                v26,
                "dp_hw_link_desc_ring_alloc",
                1257);
        *(_QWORD *)(v26 + 128) = v28;
        if ( !v28 )
          break;
        --v27;
        v26 += 8;
        if ( !v27 )
          goto LABEL_18;
      }
      v17 = "%s: Scatter lst memory alloc fail";
    }
    else
    {
      v17 = "%s: scatter bufs size out of bounds";
    }
    qdf_trace_msg(0x45u, 2u, v17, v7, v8, v9, v10, v11, v12, v13, v14, "dp_hw_link_desc_ring_alloc");
  }
  for ( i = 0; i != 128; i += 8 )
  {
    if ( *(_QWORD *)(a1 + i + 2168) )
      _qdf_mem_free_consistent(*(_QWORD *)(a1 + 24), *(_QWORD *)(*(_QWORD *)(a1 + 24) + 40LL), *(_DWORD *)(a1 + 12952));
  }
  return 2;
}
