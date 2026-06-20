__int64 __fastcall lpass_cdc_rx_macro_mux_put(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x23
  __int64 v6; // x22
  __int64 v7; // x21
  __int64 v8; // x19
  __int64 v9; // x9
  unsigned __int64 v10; // x10
  unsigned __int64 v11; // x11
  unsigned __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  unsigned __int64 v15; // x11
  __int64 v16; // x9
  __int64 result; // x0
  __int64 v18; // x11
  __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x11
  __int64 v22; // x10
  _QWORD *v23; // x8
  unsigned __int64 v26; // x11
  unsigned __int64 v33; // x11
  __int64 v34; // [xsp+8h] [xbp-18h] BYREF
  __int64 v35[2]; // [xsp+10h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(_QWORD *)(a1 + 120);
  v8 = *(_QWORD *)(a2 + 72);
  v34 = 0;
  v35[0] = 0;
  if ( (lpass_cdc_rx_macro_get_data(v5 - 208, v35, &v34, (__int64)"lpass_cdc_rx_macro_mux_put") & 1) == 0 )
    goto LABEL_14;
  v12 = *(unsigned __int8 *)(v6 + 76);
  if ( v12 > 5 )
  {
    __break(0x5512u);
LABEL_23:
    _X10 = (unsigned __int64 *)(v11 + 8 * v10);
    __asm { PRFM            #0x11, [X10] }
    do
      v26 = __ldxr(_X10);
    while ( __stxr(v26 | v9, _X10) );
    v23 = (_QWORD *)(v12 + 376);
    v16 = 1;
    goto LABEL_6;
  }
  v13 = v34;
  v14 = v34 + 32;
  if ( (_DWORD)v8 )
  {
    *(_DWORD *)(v14 + 4 * v12) = v8;
    if ( (unsigned int)v8 < 5 )
    {
      v15 = *(unsigned __int8 *)(v6 + 76);
      v12 = v13 + 8 * (v8 & 7);
      v10 = v15 >> 6;
      v9 = 1LL << v15;
      v11 = v12 + 312;
      goto LABEL_23;
    }
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_mux_put__rs_145, "lpass_cdc_rx_macro_mux_put") )
    {
      dev_err(
        *(_QWORD *)(v5 - 184),
        "%s:Invalid AIF_ID for LPASS_CDC_RX_MACRO MUX %d\n",
        "lpass_cdc_rx_macro_mux_put",
        v8);
      result = 4294967274LL;
      goto LABEL_15;
    }
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v18 = *(unsigned int *)(v14 + 4 * v12);
  if ( !(_DWORD)v18 )
  {
    result = __ratelimit(&lpass_cdc_rx_macro_mux_put__rs, "lpass_cdc_rx_macro_mux_put");
    if ( !(_DWORD)result )
      goto LABEL_15;
    dev_err(v35[0], "%s:AIF reset already\n", "lpass_cdc_rx_macro_mux_put");
    goto LABEL_8;
  }
  if ( (unsigned int)v18 <= 4 )
  {
    v19 = v34 + 8 * v18;
    *(_DWORD *)(v14 + 4 * v12) = 0;
    if ( !*(_QWORD *)(v19 + 376) )
      goto LABEL_7;
    v20 = *(unsigned __int8 *)(v6 + 76);
    v21 = v20 >> 6;
    v22 = 1LL << v20;
    v23 = (_QWORD *)(v19 + 376);
    _X9 = (unsigned __int64 *)(v19 + 312 + 8 * v21);
    __asm { PRFM            #0x11, [X9] }
    do
      v33 = __ldxr(_X9);
    while ( __stxr(v33 & ~v22, _X9) );
    v16 = -1;
LABEL_6:
    *v23 += v16;
LABEL_7:
    snd_soc_dapm_mux_update_power(*(_QWORD *)(v6 + 40), a1, (unsigned int)v8, v7, 0);
    goto LABEL_8;
  }
  result = __ratelimit(&lpass_cdc_rx_macro_mux_put__rs_143, "lpass_cdc_rx_macro_mux_put");
  if ( !(_DWORD)result )
    goto LABEL_15;
  dev_err(v35[0], "%s: Invalid AIF reset\n", "lpass_cdc_rx_macro_mux_put");
LABEL_8:
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
