__int64 __fastcall lpass_cdc_tx_macro_hw_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x19
  int v6; // w8
  unsigned int v7; // w21
  __int64 result; // x0
  __int64 v9; // x8
  unsigned __int64 v10; // x9
  __int64 v11; // x22
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x24
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a3 + 96);
  v14 = 0;
  if ( (lpass_cdc_tx_macro_get_data(v5, v15, &v14, (__int64)"lpass_cdc_tx_macro_hw_params") & 1) == 0 )
  {
LABEL_17:
    result = 4294967274LL;
    goto LABEL_28;
  }
  v6 = *(_DWORD *)(a2 + 296);
  if ( v6 <= 47999 )
  {
    switch ( v6 )
    {
      case 8000:
        v7 = 0;
        goto LABEL_21;
      case 16000:
        v7 = 1;
        goto LABEL_21;
      case 32000:
        v7 = 3;
        goto LABEL_21;
    }
    goto LABEL_15;
  }
  if ( v6 > 191999 )
  {
    if ( v6 == 192000 )
    {
      v7 = 6;
      goto LABEL_21;
    }
    if ( v6 == 384000 )
    {
      v7 = 7;
      goto LABEL_21;
    }
    goto LABEL_15;
  }
  if ( v6 == 48000 )
  {
    v7 = 4;
    goto LABEL_21;
  }
  if ( v6 != 96000 )
  {
LABEL_15:
    if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_hw_params__rs, "lpass_cdc_tx_macro_hw_params") )
      dev_err(
        *(_QWORD *)(v5 + 24),
        "%s: Invalid TX sample rate: %d\n",
        "lpass_cdc_tx_macro_hw_params",
        *(_DWORD *)(a2 + 296));
    goto LABEL_17;
  }
  v7 = 5;
LABEL_21:
  v9 = *(unsigned int *)(a3 + 8);
  if ( (unsigned int)v9 > 4 )
  {
LABEL_26:
    __break(0x5512u);
  }
  else
  {
    v10 = 0;
    v11 = v14 + 2544;
    while ( v10 <= 7 )
    {
      v12 = (unsigned __int8)((-1LL << v10) & *(_QWORD *)(v11 + 8 * v9));
      if ( !v12 )
        break;
      v13 = __clz(__rbit64(v12));
      snd_soc_component_update_bits(v5, (unsigned int)(((_DWORD)v13 << 7) + 1024), 15, v7);
      snd_soc_component_update_bits(v5, (unsigned int)(((_DWORD)v13 << 7) + 1024), 16, 16);
      v9 = *(unsigned int *)(a3 + 8);
      v10 = v13 + 1;
      if ( (unsigned int)v9 >= 5 )
        goto LABEL_26;
    }
  }
  result = 0;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
