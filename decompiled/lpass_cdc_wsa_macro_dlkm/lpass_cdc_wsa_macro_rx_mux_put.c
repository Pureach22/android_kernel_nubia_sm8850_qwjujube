__int64 __fastcall lpass_cdc_wsa_macro_rx_mux_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x23
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x19
  __int64 device_ptr; // x0
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x10
  unsigned __int64 v15; // x11
  __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x11
  __int64 v19; // x19
  __int64 v20; // x20
  __int64 v21; // x19
  __int64 v22; // x11
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x10
  __int64 v25; // x9
  _QWORD *v26; // x8
  unsigned __int64 v29; // x11
  unsigned __int64 v36; // x11

  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(_QWORD *)(a1 + 120);
  v8 = *(_QWORD *)(a2 + 72);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v5 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_rx_mux_put");
    return 4294967274LL;
  }
  v12 = *(_QWORD *)(device_ptr + 152);
  if ( !v12 || !*(_QWORD *)(v12 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v5 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_rx_mux_put");
    return 4294967274LL;
  }
  v13 = *(unsigned __int8 *)(v6 + 76);
  if ( v13 > 8 )
    goto LABEL_31;
  v14 = v12 + 520;
  if ( (_DWORD)v8 )
  {
    *(_DWORD *)(v14 + 4 * v13) = v8;
    if ( (unsigned int)v8 <= 7 )
    {
      v10 = 134;
      if ( ((1 << v8) & 0x86) != 0 )
      {
        v13 = (unsigned int)v8;
        if ( (unsigned int)v8 <= 8uLL )
        {
          v15 = *(unsigned __int8 *)(v6 + 76);
          v12 += 8LL * (unsigned int)v8;
          v10 = v15 >> 6;
          v13 = 1LL << v15;
          v11 = v12 + 376;
          goto LABEL_32;
        }
LABEL_31:
        __break(0x5512u);
LABEL_32:
        _X10 = (unsigned __int64 *)(v11 + 8 * v10);
        __asm { PRFM            #0x11, [X10] }
        do
          v29 = __ldxr(_X10);
        while ( __stxr(v29 | v13, _X10) );
        v26 = (_QWORD *)(v12 + 440);
        v16 = 1;
        goto LABEL_10;
      }
    }
    v20 = device_ptr;
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_rx_mux_put__rs_148, "lpass_cdc_wsa_macro_rx_mux_put") )
      dev_err(v20, "%s: Invalid AIF_ID for WSA RX MUX %d\n", "lpass_cdc_wsa_macro_rx_mux_put", v8);
    return 4294967274LL;
  }
  v18 = *(unsigned int *)(v14 + 4 * v13);
  if ( (_DWORD)v18 )
  {
    if ( (unsigned int)v18 <= 7 )
    {
      v22 = v12 + 8 * v18;
      *(_DWORD *)(v14 + 4 * v13) = 0;
      if ( !*(_QWORD *)(v22 + 440) )
        goto LABEL_11;
      v23 = *(unsigned __int8 *)(v6 + 76);
      v24 = v23 >> 6;
      v25 = 1LL << v23;
      v26 = (_QWORD *)(v22 + 440);
      _X10 = (unsigned __int64 *)(v22 + 376 + 8 * v24);
      __asm { PRFM            #0x11, [X10] }
      do
        v36 = __ldxr(_X10);
      while ( __stxr(v36 & ~v25, _X10) );
      v16 = -1;
LABEL_10:
      *v26 += v16;
LABEL_11:
      snd_soc_dapm_mux_update_power(*(_QWORD *)(v6 + 40), a1, (unsigned int)v8, v7, 0);
      return 0;
    }
    v19 = device_ptr;
    result = __ratelimit(&lpass_cdc_wsa_macro_rx_mux_put__rs_146, "lpass_cdc_wsa_macro_rx_mux_put");
    if ( (_DWORD)result )
    {
      dev_err(v19, "%s: Invalid AIF reset\n", "lpass_cdc_wsa_macro_rx_mux_put");
      return 0;
    }
  }
  else
  {
    v21 = device_ptr;
    result = __ratelimit(&lpass_cdc_wsa_macro_rx_mux_put__rs, "lpass_cdc_wsa_macro_rx_mux_put");
    if ( (_DWORD)result )
    {
      dev_err(v21, "%s: AIF reset already\n", "lpass_cdc_wsa_macro_rx_mux_put");
      return 0;
    }
  }
  return result;
}
