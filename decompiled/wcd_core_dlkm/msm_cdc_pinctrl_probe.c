__int64 __fastcall msm_cdc_pinctrl_probe(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  int v9; // w0
  int v10; // w0
  unsigned int v11; // w21
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x25
  int v15; // w0
  int v16; // w8
  int v17; // w10
  int v18; // w8
  unsigned int v19; // w0
  int v20; // w0
  int v21; // w21
  int v22; // w9
  int named_gpio; // w0
  unsigned int v24; // w0
  __int64 result; // x0
  unsigned int v26; // w21
  _QWORD v27[8]; // [xsp+8h] [xbp-C8h] BYREF
  _QWORD v28[8]; // [xsp+48h] [xbp-88h] BYREF
  __int64 v29; // [xsp+88h] [xbp-48h] BYREF
  __int64 v30; // [xsp+90h] [xbp-40h]
  __int64 v31; // [xsp+98h] [xbp-38h]
  __int64 v32; // [xsp+A0h] [xbp-30h]
  __int64 v33; // [xsp+A8h] [xbp-28h]
  __int64 v34; // [xsp+B0h] [xbp-20h]
  __int64 v35; // [xsp+B8h] [xbp-18h]
  __int64 v36; // [xsp+C0h] [xbp-10h]
  __int64 v37; // [xsp+C8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  memset(v28, 0, sizeof(v28));
  memset(v27, 0, sizeof(v27));
  v2 = devm_kmalloc(a1 + 16, 312, 3520);
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_54;
  }
  v3 = (_QWORD *)v2;
  v4 = devm_pinctrl_get(a1 + 16);
  *v3 = v4;
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "%s: Cannot get cdc gpio pinctrl:%ld\n", "msm_cdc_pinctrl_probe", v4);
    v26 = *(_DWORD *)v3;
LABEL_53:
    devm_kfree(a1 + 16, v3);
    result = v26;
    goto LABEL_54;
  }
  v5 = pinctrl_lookup_state(v4, "aud_active");
  v3[1] = v5;
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "%s: Cannot get aud_active pinctrl state:%ld\n", "msm_cdc_pinctrl_probe", v5);
    v26 = *((_DWORD *)v3 + 2);
LABEL_52:
    devm_pinctrl_put(*v3);
    goto LABEL_53;
  }
  v6 = pinctrl_lookup_state(*v3, "aud_sleep");
  v3[2] = v6;
  if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "%s: Cannot get aud_sleep pinctrl state:%ld\n", "msm_cdc_pinctrl_probe", v6);
    v26 = *((_DWORD *)v3 + 4);
    goto LABEL_52;
  }
  v7 = pinctrl_lookup_state(*v3, "aud_alt_active");
  v8 = *(_QWORD *)(a1 + 760);
  v3[3] = v7;
  if ( !of_find_property(v8, "qcom,lpi-gpios", 0) )
  {
    v9 = pinctrl_select_state(*v3);
    if ( v9 )
      dev_err(a1 + 16, "%s: set cdc gpio sleep state fail: %d\n", "msm_cdc_pinctrl_probe", v9);
  }
  v10 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "qcom,chip-wakeup-reg", 4);
  if ( v10 >= 1 )
  {
    v11 = v10;
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,chip-wakeup-reg", v28, (unsigned int)v10, 0)
        & 0x80000000) == 0 )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,chip-wakeup-maskbit", v3 + 29, v11, 0)
          & 0x80000000) != 0 )
      {
        dev_err(a1 + 16, "chip-wakeup-maskbit needed if chip-wakeup-reg is defined!\n");
      }
      else
      {
        v12 = 0;
        *((_BYTE *)v3 + 305) = 1;
        do
        {
          if ( v12 == 16 )
            goto LABEL_56;
          v3[v12 + 13] = devm_ioremap(a1 + 16, *((unsigned int *)v28 + v12), 4);
          ++v12;
        }
        while ( v11 != v12 );
        if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,chip-wakeup-default-val", v27, v11, 0)
            & 0x80000000) == 0 )
        {
          v13 = 0;
          v14 = 232;
          while ( v13 != 16 )
          {
            v15 = readl((unsigned int *)v3[v13 + 13]);
            v16 = 1 << *(_DWORD *)((char *)v3 + v14);
            v17 = v16 | v15;
            v18 = v15 & ~v16;
            if ( *(_DWORD *)((char *)&v27[-29] + v14) )
              v19 = v17;
            else
              v19 = v18;
            writel(v19, (unsigned int *)v3[v13 + 13]);
            ++v13;
            v14 += 4;
            if ( v11 == v13 )
              goto LABEL_24;
          }
LABEL_56:
          __break(0x5512u);
          __break(1u);
        }
LABEL_24:
        *((_DWORD *)v3 + 75) = v11;
      }
    }
  }
  v20 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), "qcom,tlmm-pins", 4);
  if ( v20 >= 1 )
  {
    v21 = v20;
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,tlmm-pins", &v29, (unsigned int)v20, 0)
        & 0x80000000) == 0 )
    {
      v22 = v29;
      *((_BYTE *)v3 + 304) = 1;
      *((_DWORD *)v3 + 10) = v22;
      if ( v21 != 1 )
      {
        *((_DWORD *)v3 + 11) = HIDWORD(v29);
        if ( v21 != 2 )
        {
          *((_DWORD *)v3 + 12) = v30;
          if ( v21 != 3 )
          {
            *((_DWORD *)v3 + 13) = HIDWORD(v30);
            if ( v21 != 4 )
            {
              *((_DWORD *)v3 + 14) = v31;
              if ( v21 != 5 )
              {
                *((_DWORD *)v3 + 15) = HIDWORD(v31);
                if ( v21 != 6 )
                {
                  *((_DWORD *)v3 + 16) = v32;
                  if ( v21 != 7 )
                  {
                    *((_DWORD *)v3 + 17) = HIDWORD(v32);
                    if ( v21 != 8 )
                    {
                      *((_DWORD *)v3 + 18) = v33;
                      if ( v21 != 9 )
                      {
                        *((_DWORD *)v3 + 19) = HIDWORD(v33);
                        if ( v21 != 10 )
                        {
                          *((_DWORD *)v3 + 20) = v34;
                          if ( v21 != 11 )
                          {
                            *((_DWORD *)v3 + 21) = HIDWORD(v34);
                            if ( v21 != 12 )
                            {
                              *((_DWORD *)v3 + 22) = v35;
                              if ( v21 != 13 )
                              {
                                *((_DWORD *)v3 + 23) = HIDWORD(v35);
                                if ( v21 != 14 )
                                {
                                  *((_DWORD *)v3 + 24) = v36;
                                  if ( v21 != 15 )
                                  {
                                    *((_DWORD *)v3 + 25) = HIDWORD(v36);
                                    if ( v21 != 16 )
                                      goto LABEL_56;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      *((_DWORD *)v3 + 74) = v21;
    }
  }
  named_gpio = of_get_named_gpio(*(_QWORD *)(a1 + 760), "qcom,cdc-rst-n-gpio", 0);
  *((_DWORD *)v3 + 8) = named_gpio;
  if ( (named_gpio & 0x80000000) == 0 )
  {
    v24 = gpio_request();
    if ( v24 )
    {
      v26 = v24;
      dev_err(a1 + 16, "%s: Failed to request gpio %d\n", "msm_cdc_pinctrl_probe", *((_DWORD *)v3 + 8));
      goto LABEL_52;
    }
  }
  result = 0;
  *(_QWORD *)(a1 + 168) = v3;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
