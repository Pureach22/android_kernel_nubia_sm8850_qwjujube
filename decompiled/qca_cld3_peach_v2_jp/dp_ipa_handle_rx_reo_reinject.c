__int64 __fastcall dp_ipa_handle_rx_reo_reinject(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w22
  int v6; // w23
  unsigned int v7; // w21
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  __int64 v26; // x20
  char *v27; // x22
  char *v28; // x21
  __int64 v29; // x24
  __int64 v30; // x12
  int v31; // w9
  int v32; // w20
  char *v33; // x21
  __int64 *v34; // x25
  char *v35; // x20
  int v36; // w8
  __int64 *v37; // x22
  __int64 v38; // x21

  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) == 0
    || !*(_DWORD *)(a1 + 18144)
    || (*(char *)(a2 + 84) & 0x80000000) == 0 )
  {
    return a2;
  }
  if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
    v5 = *(unsigned __int16 *)(a2 + 66);
  else
    v5 = 0;
  v6 = *(_DWORD *)(a2 + 112);
  v7 = (unsigned __int16)wlan_cfg_rx_buffer_size(*(_QWORD *)(a1 + 40));
  result = _qdf_nbuf_alloc(*(_QWORD *)(a1 + 24), v7, 0, 128, 0, "dp_ipa_frag_nbuf_linearize", 4800);
  if ( !result )
  {
    v26 = jiffies;
    if ( dp_ipa_frag_nbuf_linearize___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf allocate fail",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "dp_ipa_frag_nbuf_linearize");
      dp_ipa_frag_nbuf_linearize___last_ticks = v26;
      return 0;
    }
    return 0;
  }
  v16 = v6 + v5;
  if ( v16 + 2 > v7 )
  {
    _qdf_nbuf_free(result);
    v25 = jiffies;
    if ( dp_ipa_frag_nbuf_linearize___last_ticks_87 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf is jumbo data",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "dp_ipa_frag_nbuf_linearize");
      dp_ipa_frag_nbuf_linearize___last_ticks_87 = v25;
      return 0;
    }
    return 0;
  }
  if ( a2 )
  {
    v27 = *(char **)(a2 + 224);
    v28 = *(char **)(result + 224);
    v29 = result;
    qdf_mem_copy(v28, v27, *(unsigned __int16 *)(a1 + 1138));
    v30 = *(unsigned __int16 *)(a1 + 1138);
    v31 = *(_DWORD *)(a2 + 112) - *(_DWORD *)(a2 + 116);
    v32 = v31 - v30;
    v33 = &v28[v30 + 2];
    v34 = *(__int64 **)(*(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) + 8LL);
    qdf_mem_copy(v33, &v27[v30], (unsigned int)(v31 - v30));
    if ( v34 )
    {
      v35 = &v33[v32];
      do
      {
        if ( (*((_BYTE *)v34 + 68) & 4) != 0 )
          v36 = *((unsigned __int16 *)v34 + 33);
        else
          v36 = 0;
        v37 = (__int64 *)*v34;
        v38 = (unsigned int)(*((_DWORD *)v34 + 28) + v36);
        qdf_mem_copy(v35, (const void *)v34[28], (unsigned int)v38);
        v35 += v38;
        v34 = v37;
      }
      while ( v37 );
    }
    *(_DWORD *)(v29 + 112) = v16;
    _qdf_nbuf_free(a2);
    return v29;
  }
  else
  {
    *(_DWORD *)(result + 112) = v16;
  }
  return result;
}
