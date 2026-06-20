__int64 __fastcall lpass_cdc_wsa2_macro_set_rx_mute_status(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  int v5; // w21
  __int64 v6; // x19
  __int64 device_ptr; // x0
  _QWORD *v8; // x22
  __int64 v9; // x3
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 updated; // x0
  unsigned int v14; // w20
  __int64 v15; // x23
  __int64 v16; // x0

  v4 = *(_QWORD *)(a1 + 128);
  v5 = *(_DWORD *)(a2 + 72);
  v6 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v4 + 24), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v4 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_set_rx_mute_status");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v8 = *(_QWORD **)(device_ptr + 152);
  if ( !v8 || !v8[31] )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v4 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_set_rx_mute_status");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  _pm_runtime_resume(*v8, 4);
  if ( (int)v6 > 1 )
  {
    if ( (_DWORD)v6 == 2 )
    {
      v9 = (unsigned int)(16 * v5);
      v10 = v4;
      v11 = 17432;
      goto LABEL_20;
    }
    if ( (_DWORD)v6 == 3 )
    {
      v9 = (unsigned int)(16 * v5);
      v10 = v4;
      v11 = 17560;
      goto LABEL_20;
    }
LABEL_15:
    updated = __ratelimit(&lpass_cdc_wsa2_macro_set_rx_mute_status__rs, "lpass_cdc_wsa2_macro_set_rx_mute_status");
    if ( (_DWORD)updated )
      updated = printk(&unk_FC71, "lpass_cdc_wsa2_macro_set_rx_mute_status");
    v14 = -22;
    goto LABEL_21;
  }
  if ( !(_DWORD)v6 )
  {
    v9 = (unsigned int)(16 * v5);
    v10 = v4;
    v11 = 17408;
    goto LABEL_20;
  }
  if ( (_DWORD)v6 != 1 )
    goto LABEL_15;
  v9 = (unsigned int)(16 * v5);
  v10 = v4;
  v11 = 17536;
LABEL_20:
  updated = snd_soc_component_update_bits(v10, v11, 16, v9);
  v14 = 0;
LABEL_21:
  v15 = *v8;
  *(_QWORD *)(v15 + 520) = ktime_get_mono_fast_ns(updated);
  v16 = _pm_runtime_suspend(*v8, 13);
  if ( (unsigned int)v6 > 8 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return lpass_cdc_wsa2_macro_get_compander(v16);
  }
  else
  {
    *((_DWORD *)v8 + v6 + 128) = v5;
    return v14;
  }
}
