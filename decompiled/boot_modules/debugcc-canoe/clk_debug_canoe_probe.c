unsigned __int64 __fastcall clk_debug_canoe_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned __int64 v5; // x0
  _UNKNOWN **v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x20
  const char **v10; // x8
  unsigned __int64 v11; // x21
  const char *v12; // x2
  const char **v13; // x8
  __int64 v14; // x21
  const char *name; // x2
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x19

  result = devm_clk_get(a1 + 16, "xo_clk_src");
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    debug_mux_priv = result;
    if ( qword_160 && (unsigned __int64)qword_160 < 0xFFFFFFFFFFFFF001LL
      || (result = map_debug_bases(a1, "qcom,mccc", &mc_cc_debug_mux), !(_DWORD)result)
      || (_DWORD)result == -53 )
    {
      if ( qword_228 && (unsigned __int64)qword_228 < 0xFFFFFFFFFFFFF001LL
        || (result = map_debug_bases(a1, "qcom,videocc", &video_cc_debug_mux), !(_DWORD)result)
        || (_DWORD)result == -53 )
      {
        if ( qword_2C8 && (unsigned __int64)qword_2C8 < 0xFFFFFFFFFFFFF001LL
          || (result = map_debug_bases(a1, "qcom,gxclkctl", &gx_clkctl_debug_mux), !(_DWORD)result)
          || (_DWORD)result == -53 )
        {
          if ( qword_398 && (unsigned __int64)qword_398 < 0xFFFFFFFFFFFFF001LL
            || (result = map_debug_bases(a1, "qcom,gpucc", &gpu_cc_debug_mux), !(_DWORD)result)
            || (_DWORD)result == -53 )
          {
            if ( qword_440 && (unsigned __int64)qword_440 < 0xFFFFFFFFFFFFF001LL
              || (result = map_debug_bases(a1, "qcom,evacc", &eva_cc_debug_mux), !(_DWORD)result)
              || (_DWORD)result == -53 )
            {
              if ( qword_598 && (unsigned __int64)qword_598 < 0xFFFFFFFFFFFFF001LL
                || (result = map_debug_bases(a1, "qcom,dispcc", &disp_cc_debug_mux), !(_DWORD)result)
                || (_DWORD)result == -53 )
              {
                if ( qword_740 && (unsigned __int64)qword_740 < 0xFFFFFFFFFFFFF001LL
                  || (result = map_debug_bases(a1, "qcom,camcc", &cam_cc_debug_mux), !(_DWORD)result)
                  || (_DWORD)result == -53 )
                {
                  if ( qword_7E8 && (unsigned __int64)qword_7E8 < 0xFFFFFFFFFFFFF001LL
                    || (result = map_debug_bases(a1, "qcom,cambistmclkcc", &cam_bist_mclk_cc_debug_mux), !(_DWORD)result)
                    || (_DWORD)result == -53 )
                  {
                    if ( qword_878 && (unsigned __int64)qword_878 < 0xFFFFFFFFFFFFF001LL
                      || (result = map_debug_bases(a1, "qcom,apsscc", &apss_cc_debug_mux), !(_DWORD)result)
                      || (_DWORD)result == -53 )
                    {
                      if ( qword_2508 && (unsigned __int64)qword_2508 < 0xFFFFFFFFFFFFF001LL
                        || (result = map_debug_bases(a1, "qcom,gcc", &gcc_debug_mux), !(_DWORD)result)
                        || (_DWORD)result == -53 )
                      {
                        v3 = 0;
                        while ( 1 )
                        {
                          v4 = *(__int64 *)((char *)&debugcc_canoe_hws + v3);
                          v5 = devm_clk_register(a1 + 16, v4);
                          if ( v5 >= 0xFFFFFFFFFFFFF001LL )
                            break;
                          v3 += 8;
                          if ( v3 == 416 )
                          {
                            v6 = (_UNKNOWN **)&mc_cc_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &mc_cc_debug_mux);
                            if ( (_DWORD)v7 )
                              goto LABEL_64;
                            v6 = &video_cc_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &video_cc_debug_mux);
                            if ( (_DWORD)v7 )
                              goto LABEL_64;
                            v6 = &gx_clkctl_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &gx_clkctl_debug_mux);
                            if ( (_DWORD)v7 )
                              goto LABEL_64;
                            v6 = &gpu_cc_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &gpu_cc_debug_mux);
                            if ( (_DWORD)v7 )
                              goto LABEL_64;
                            v6 = &eva_cc_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &eva_cc_debug_mux);
                            if ( (_DWORD)v7 )
                              goto LABEL_64;
                            v6 = &disp_cc_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &disp_cc_debug_mux);
                            if ( (_DWORD)v7 )
                              goto LABEL_64;
                            v6 = &cam_cc_debug_mux;
                            v7 = devm_clk_register_debug_mux(a1 + 16, &cam_cc_debug_mux);
                            if ( (_DWORD)v7
                              || (v6 = &cam_bist_mclk_cc_debug_mux,
                                  v7 = devm_clk_register_debug_mux(a1 + 16, &cam_bist_mclk_cc_debug_mux),
                                  (_DWORD)v7)
                              || (v6 = &apss_cc_debug_mux,
                                  v7 = devm_clk_register_debug_mux(a1 + 16, &apss_cc_debug_mux),
                                  (_DWORD)v7)
                              || (v6 = &gcc_debug_mux,
                                  v7 = devm_clk_register_debug_mux(a1 + 16, &gcc_debug_mux),
                                  (_DWORD)v7) )
                            {
LABEL_64:
                              v13 = (const char **)v6[13];
                              v14 = v7;
                              if ( v13 )
                                name = *v13;
                              else
                                name = (const char *)clk_hw_get_name(v6 + 11);
                              dev_err(a1 + 16, "Unable to register mux clk %s, err:(%d)\n", name, v14);
                              return v14;
                            }
                            else
                            {
                              v8 = clk_debug_measure_register(&unk_2540);
                              if ( (_DWORD)v8 )
                              {
                                v16 = v8;
                                v17 = a1 + 16;
                                v18 = v16;
                                dev_err(v17, "Could not register Measure clocks ret=%d\n", v16);
                                return v18;
                              }
                              else
                              {
                                dev_info(a1 + 16, "Registered debug measure clocks\n");
                                return 0;
                              }
                            }
                          }
                        }
                        v10 = *(const char ***)(v4 + 16);
                        v11 = v5;
                        if ( v10 )
                          v12 = *v10;
                        else
                          v12 = (const char *)clk_hw_get_name(v4);
                        dev_err(a1 + 16, "Unable to register %s, err:(%ld)\n", v12, v11);
                        return (unsigned int)v11;
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
  else if ( result != -517 )
  {
    v9 = result;
    dev_err(a1 + 16, "Unable to get xo clock\n");
    return v9;
  }
  return result;
}
