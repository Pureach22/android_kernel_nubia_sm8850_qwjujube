unsigned __int64 __fastcall clk_debug_alor_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 i; // x21
  __int64 v4; // x20
  unsigned __int64 v5; // x0
  _UNKNOWN **v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x20
  const char **v10; // x8
  unsigned __int64 v11; // x21
  const char *name; // x2
  const char **v13; // x8
  __int64 v14; // x21
  const char *v15; // x2

  result = devm_clk_get(a1 + 16, "xo_clk_src");
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( result == -517 )
      return result;
    v9 = result;
    dev_err(a1 + 16, "Unable to get xo clock\n");
    return v9;
  }
  debug_mux_priv = result;
  if ( qword_160 && (unsigned __int64)qword_160 < 0xFFFFFFFFFFFFF001LL
    || (result = map_debug_bases(a1, "qcom,mccc", &mc_cc_debug_mux), !(_DWORD)result)
    || (_DWORD)result == -53 )
  {
    if ( qword_220 && (unsigned __int64)qword_220 < 0xFFFFFFFFFFFFF001LL
      || (result = map_debug_bases(a1, "qcom,videocc", &video_cc_debug_mux), !(_DWORD)result)
      || (_DWORD)result == -53 )
    {
      if ( qword_2C0 && (unsigned __int64)qword_2C0 < 0xFFFFFFFFFFFFF001LL
        || (result = map_debug_bases(a1, "qcom,gxclkctl", &gx_clkctl_debug_mux), !(_DWORD)result)
        || (_DWORD)result == -53 )
      {
        if ( qword_388 && (unsigned __int64)qword_388 < 0xFFFFFFFFFFFFF001LL
          || (result = map_debug_bases(a1, "qcom,gpucc", &gpu_cc_debug_mux), !(_DWORD)result)
          || (_DWORD)result == -53 )
        {
          if ( qword_430 && (unsigned __int64)qword_430 < 0xFFFFFFFFFFFFF001LL
            || (result = map_debug_bases(a1, "qcom,evacc", &eva_cc_debug_mux), !(_DWORD)result)
            || (_DWORD)result == -53 )
          {
            if ( qword_588 && (unsigned __int64)qword_588 < 0xFFFFFFFFFFFFF001LL
              || (result = map_debug_bases(a1, "qcom,dispcc", &disp_cc_debug_mux), !(_DWORD)result)
              || (_DWORD)result == -53 )
            {
              if ( qword_720 && (unsigned __int64)qword_720 < 0xFFFFFFFFFFFFF001LL
                || (result = map_debug_bases(a1, "qcom,camcc", &cam_cc_debug_mux), !(_DWORD)result)
                || (_DWORD)result == -53 )
              {
                if ( qword_7C0 && (unsigned __int64)qword_7C0 < 0xFFFFFFFFFFFFF001LL
                  || (result = map_debug_bases(a1, "qcom,cambistmclkcc", &cam_bist_mclk_cc_debug_mux), !(_DWORD)result)
                  || (_DWORD)result == -53 )
                {
                  if ( qword_850 && (unsigned __int64)qword_850 < 0xFFFFFFFFFFFFF001LL
                    || (result = map_debug_bases(a1, "qcom,apsscc", &apss_cc_debug_mux), !(_DWORD)result)
                    || (_DWORD)result == -53 )
                  {
                    if ( qword_24C8 && (unsigned __int64)qword_24C8 < 0xFFFFFFFFFFFFF001LL
                      || (result = map_debug_bases(a1, "qcom,gcc", &gcc_debug_mux), !(_DWORD)result)
                      || (_DWORD)result == -53 )
                    {
                      for ( i = 0; i != 416; i += 8 )
                      {
                        v4 = *(__int64 *)((char *)&debugcc_alor_hws + i);
                        v5 = devm_clk_register(a1 + 16, v4);
                        if ( v5 >= 0xFFFFFFFFFFFFF001LL )
                        {
                          v10 = *(const char ***)(v4 + 16);
                          v11 = v5;
                          if ( v10 )
                            name = *v10;
                          else
                            name = (const char *)clk_hw_get_name(v4);
                          dev_err(a1 + 16, "Unable to register %s, err:(%ld)\n", name, v11);
                          return (unsigned int)v11;
                        }
                      }
                      v6 = (_UNKNOWN **)&mc_cc_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &mc_cc_debug_mux);
                      if ( (_DWORD)v7 )
                        goto LABEL_65;
                      v6 = &video_cc_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &video_cc_debug_mux);
                      if ( (_DWORD)v7 )
                        goto LABEL_65;
                      v6 = &gx_clkctl_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &gx_clkctl_debug_mux);
                      if ( (_DWORD)v7 )
                        goto LABEL_65;
                      v6 = &gpu_cc_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &gpu_cc_debug_mux);
                      if ( (_DWORD)v7 )
                        goto LABEL_65;
                      v6 = &eva_cc_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &eva_cc_debug_mux);
                      if ( (_DWORD)v7 )
                        goto LABEL_65;
                      v6 = &disp_cc_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &disp_cc_debug_mux);
                      if ( (_DWORD)v7 )
                        goto LABEL_65;
                      v6 = &cam_cc_debug_mux;
                      v7 = devm_clk_register_debug_mux(a1 + 16, &cam_cc_debug_mux);
                      if ( (_DWORD)v7
                        || (v6 = &cam_bist_mclk_cc_debug_mux,
                            v7 = devm_clk_register_debug_mux(a1 + 16, &cam_bist_mclk_cc_debug_mux),
                            (_DWORD)v7)
                        || (v6 = &apss_cc_debug_mux,
                            v7 = devm_clk_register_debug_mux(a1 + 16, &apss_cc_debug_mux),
                            (_DWORD)v7)
                        || (v6 = &gcc_debug_mux, v7 = devm_clk_register_debug_mux(a1 + 16, &gcc_debug_mux), (_DWORD)v7) )
                      {
LABEL_65:
                        v13 = (const char **)v6[13];
                        v14 = v7;
                        if ( v13 )
                          v15 = *v13;
                        else
                          v15 = (const char *)clk_hw_get_name(v6 + 11);
                        dev_err(a1 + 16, "Unable to register mux clk %s, err:(%d)\n", v15, v14);
                        return v14;
                      }
                      v8 = clk_debug_measure_register(&unk_2500);
                      if ( !(_DWORD)v8 )
                      {
                        dev_info(a1 + 16, "Registered debug measure clocks\n");
                        return 0;
                      }
                      v9 = v8;
                      dev_err(a1 + 16, "Could not register Measure clocks\n");
                      return v9;
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
  return result;
}
