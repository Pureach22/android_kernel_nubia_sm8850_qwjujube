__int64 __fastcall lpass_cdc_va_macro_put_dec_enum(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x24
  __int64 v6; // x21
  _DWORD *v7; // x22
  __int64 device_ptr; // x0
  __int64 v9; // x25
  unsigned int v10; // w26
  unsigned int v11; // w8
  unsigned __int64 v12; // t2
  const char *v13; // x23
  unsigned int v14; // w22
  size_t v15; // x0
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v19; // x3

  v4 = snd_soc_dapm_kcontrol_widget();
  v5 = *(_QWORD *)(v4 + 40);
  v6 = v4;
  v7 = *(_DWORD **)(a1 + 120);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v5 - 184), 3);
  if ( device_ptr )
  {
    v9 = *(_QWORD *)(device_ptr + 152);
    if ( v9 && *(_QWORD *)(v9 + 168) )
    {
      v10 = *(_DWORD *)(a2 + 72);
      if ( v10 <= v7[2] - 1 )
      {
        HIDWORD(v12) = *v7 - 12544;
        LODWORD(v12) = HIDWORD(v12);
        v11 = v12 >> 3;
        if ( v11 < 4 )
        {
          v13 = *(const char **)(v6 + 8);
          v14 = (v11 << 7) | 0x3404;
          v15 = strlen(v13);
          if ( strnstr(v13, "SMIC", v15) )
          {
            if ( v10 )
            {
              if ( (*(_BYTE *)(v9 + 1580) & 1) != 0 )
              {
                snd_soc_component_update_bits(v5 - 208, v14, 128, 128);
                v16 = v5 - 208;
                v17 = 12436;
              }
              else
              {
                v16 = v5 - 208;
                v17 = v14;
              }
              v19 = 0;
              goto LABEL_23;
            }
          }
          else if ( v10 )
          {
            v16 = v5 - 208;
            v17 = v14;
            v19 = 128;
LABEL_23:
            snd_soc_component_update_bits(v16, v17, 128, v19);
          }
          return snd_soc_dapm_put_enum_double(a1, a2);
        }
        if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_put_dec_enum__rs, "lpass_cdc_va_macro_put_dec_enum") )
          dev_err(*(_QWORD *)(v5 - 184), "%s: e->reg: 0x%x not expected\n", "lpass_cdc_va_macro_put_dec_enum", *v7);
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v5 - 184), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_put_dec_enum");
    }
  }
  else if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
  {
    dev_err(*(_QWORD *)(v5 - 184), "%s: null device for macro!\n", "lpass_cdc_va_macro_put_dec_enum");
  }
  return 4294967274LL;
}
