__int64 __fastcall lpass_cdc_rx_macro_enable_echo(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x19
  unsigned __int8 v4; // w0
  const char *v5; // x22
  unsigned __int8 v6; // w21
  unsigned int v7; // w21
  int v8; // w8
  char v9; // w0
  const char *v10; // x8
  char v11; // w20
  int v12; // w0
  unsigned int v13; // w8
  __int64 result; // x0
  unsigned int v15; // w20
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  __int64 v17[2]; // [xsp+10h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 40);
  v17[0] = 0;
  v3 = v2 - 208;
  if ( (lpass_cdc_rx_macro_get_data(v2 - 208, v17, &v16, (__int64)"lpass_cdc_rx_macro_enable_echo") & 1) == 0 )
    goto LABEL_12;
  v4 = snd_soc_component_read(v3, 4504);
  v5 = *(const char **)(a1 + 8);
  v6 = v4;
  if ( !strcmp(v5, "RX MIX TX0 MUX") )
  {
    v8 = v6 >> 4;
LABEL_7:
    v7 = v8 - 1;
    goto LABEL_8;
  }
  if ( !strcmp(v5, "RX MIX TX1 MUX") )
  {
    v8 = v6 & 0xF;
    goto LABEL_7;
  }
  v7 = 0;
LABEL_8:
  v9 = snd_soc_component_read(v3, 4508);
  v10 = *(const char **)(a1 + 8);
  v11 = v9;
  v12 = strcmp(v10, "RX MIX TX2 MUX");
  v13 = (v11 & 0xF) - 1;
  if ( v12 )
    v13 = v7;
  if ( v13 < 3 )
  {
    v15 = v13 << 6;
    snd_soc_component_update_bits(v3, (v13 << 6) | 0x1C00, 1, 1);
    snd_soc_component_update_bits(v3, v15 | 0x1C04, 30, 8);
    result = 0;
    goto LABEL_14;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_enable_echo__rs, "lpass_cdc_rx_macro_enable_echo") )
  {
    dev_err(v17[0], "%s: EC mix control not set correctly\n", "lpass_cdc_rx_macro_enable_echo");
    result = 4294967274LL;
    goto LABEL_14;
  }
LABEL_12:
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
