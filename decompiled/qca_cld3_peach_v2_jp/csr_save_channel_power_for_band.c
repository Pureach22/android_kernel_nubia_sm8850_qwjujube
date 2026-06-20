__int64 __fastcall csr_save_channel_power_for_band(__int64 a1, char a2)
{
  unsigned int v4; // w22
  unsigned int v5; // w24
  __int64 result; // x0
  __int64 v7; // x20
  __int64 v8; // x23
  unsigned int v9; // w22
  __int64 v10; // x24
  __int64 v11; // x26
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8

  v4 = *(unsigned __int8 *)(a1 + 16532);
  if ( v4 >= 0x64 )
    v5 = 100;
  else
    v5 = *(unsigned __int8 *)(a1 + 16532);
  result = _qdf_mem_malloc(0x320u, "csr_save_channel_power_for_band", 383);
  if ( !result )
    return result;
  v7 = result;
  if ( !v4 )
    return _qdf_mem_free(v7);
  v8 = 0;
  v9 = 0;
  v10 = 12LL * v5;
  v11 = result;
  do
  {
    v12 = *(_DWORD *)(a1 + v8 + 15332);
    if ( (a2 & 1) != 0 )
    {
      if ( !wlan_reg_is_5ghz_ch_freq(v12) )
        goto LABEL_7;
    }
    else if ( !wlan_reg_is_24ghz_ch_freq(v12) )
    {
      goto LABEL_7;
    }
    if ( v9 >= 0x64 )
    {
      qdf_trace_msg(
        0x34u,
        3u,
        "%s: count: %d exceeded",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "csr_save_channel_power_for_band",
        v9);
      goto LABEL_17;
    }
    v21 = *(_DWORD *)(a1 + v8 + 15332);
    *(_BYTE *)(v11 + 4) = 1;
    ++v9;
    *(_DWORD *)v11 = v21;
    *(_BYTE *)(v11 + 5) = *(_DWORD *)(a1 + v8 + 15340);
    v11 += 8;
LABEL_7:
    v8 += 12;
  }
  while ( v10 != v8 );
  if ( !v9 )
    return _qdf_mem_free(v7);
LABEL_17:
  csr_save_to_channel_power2_g_5_g(a1, 8 * v9, v7);
  return _qdf_mem_free(v7);
}
