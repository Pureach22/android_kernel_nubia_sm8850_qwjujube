__int64 __fastcall ucfg_mlme_convert_power_cfg_chan_to_freq(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        void *a5)
{
  __int64 v5; // x25
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  char *v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w27
  __int64 v30; // x24
  __int64 v31; // x28
  unsigned int v32; // w0
  char *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  bool v42; // cf

  v5 = a2;
  v11 = _qdf_mem_malloc(a2, "ucfg_mlme_convert_power_cfg_chan_to_freq", 183);
  if ( v11 )
  {
    v20 = (char *)v11;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: max_length %d length %zu",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "ucfg_mlme_convert_power_cfg_chan_to_freq",
      a2,
      a3);
    v29 = a3 - 3;
    if ( (unsigned int)a3 < 3 )
    {
      LODWORD(v30) = 0;
    }
    else
    {
      v30 = 0;
      v31 = 0;
      do
      {
        v32 = wlan_reg_legacy_chan_to_freq(a1, *(unsigned __int8 *)(a4 + v31), v21, v22, v23, v24, v25, v26, v27, v28);
        v33 = &v20[v30];
        *(_DWORD *)v33 = v32;
        v30 += 8;
        v33[4] = *(_BYTE *)(a4 + (unsigned int)(v31 + 1));
        v33[5] = *(_BYTE *)(a4 + (unsigned int)(v31 + 2));
        qdf_trace_msg(
          0x1Fu,
          8u,
          "%s: First freq %d num channels %d max tx power %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "ucfg_mlme_convert_power_cfg_chan_to_freq",
          v32);
        v42 = v29 >= 3;
        v29 -= 3;
        if ( !v42 )
          break;
        v31 += 3;
      }
      while ( v5 - 8 >= (unsigned __int64)(unsigned int)v30 );
    }
    qdf_mem_set(a5, a2, 0);
    qdf_mem_copy(a5, v20, (unsigned int)v30);
    _qdf_mem_free((__int64)v20);
  }
  else
  {
    LODWORD(v30) = 0;
  }
  return (unsigned int)v30;
}
