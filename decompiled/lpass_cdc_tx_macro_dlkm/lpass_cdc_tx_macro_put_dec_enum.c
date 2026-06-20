__int64 __fastcall lpass_cdc_tx_macro_put_dec_enum(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x23
  __int64 v6; // x22
  _DWORD *v7; // x24
  __int64 v8; // x21
  unsigned int v9; // w25
  unsigned int v10; // w8
  unsigned __int64 v11; // t2
  const char *v12; // x22
  unsigned int v13; // w23
  size_t v14; // x0
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 result; // x0
  __int64 v18; // x3
  __int64 v19; // [xsp+8h] [xbp-18h] BYREF
  __int64 v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(_DWORD **)(a1 + 120);
  v8 = v5 - 208;
  v19 = 0;
  if ( (lpass_cdc_tx_macro_get_data(v5 - 208, v20, &v19, (__int64)"lpass_cdc_tx_macro_put_dec_enum") & 1) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 72);
    if ( v9 <= v7[2] - 1 )
    {
      HIDWORD(v11) = *v7 - 256;
      LODWORD(v11) = HIDWORD(v11);
      v10 = v11 >> 3;
      if ( v10 < 8 )
      {
        v12 = *(const char **)(v6 + 8);
        v13 = (v10 << 7) | 0x404;
        v14 = strlen(v12);
        if ( strnstr(v12, "SMIC", v14) )
        {
          if ( v9 )
          {
            if ( (compoundliteral_103[v19] & 1) != 0 )
            {
              snd_soc_component_update_bits(v8, v13, 128, 128);
              v15 = v8;
              v16 = 12436;
            }
            else
            {
              v15 = v8;
              v16 = v13;
            }
            v18 = 0;
            goto LABEL_16;
          }
        }
        else if ( v9 )
        {
          v15 = v8;
          v16 = v13;
          v18 = 128;
LABEL_16:
          snd_soc_component_update_bits(v15, v16, 128, v18);
        }
        result = snd_soc_dapm_put_enum_double(a1, a2);
        goto LABEL_11;
      }
      if ( (unsigned int)__ratelimit(&lpass_cdc_tx_macro_put_dec_enum__rs, "lpass_cdc_tx_macro_put_dec_enum") )
        dev_err(*(_QWORD *)(v5 - 184), "%s: e->reg: 0x%x not expected\n", "lpass_cdc_tx_macro_put_dec_enum", *v7);
    }
  }
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
