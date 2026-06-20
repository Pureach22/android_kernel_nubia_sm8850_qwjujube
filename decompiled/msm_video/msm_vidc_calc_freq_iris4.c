unsigned __int64 __fastcall msm_vidc_calc_freq_iris4(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x20
  __int64 v5; // x27
  __int64 v6; // x1
  unsigned __int64 result; // x0
  unsigned int v8; // w1
  unsigned int v9; // w8
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x22
  unsigned __int64 v12; // x23
  unsigned __int64 v13; // x26
  unsigned __int64 clock_freq; // x0
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x0
  _BYTE dest[136]; // [xsp+40h] [xbp-140h] BYREF
  __int64 v18; // [xsp+C8h] [xbp-B8h] BYREF
  __int64 v19; // [xsp+D0h] [xbp-B0h]
  __int64 v20; // [xsp+D8h] [xbp-A8h]
  __int64 v21; // [xsp+E0h] [xbp-A0h]
  _QWORD src[19]; // [xsp+E8h] [xbp-98h] BYREF

  src[17] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 320);
  v5 = a1 + 38700;
  msm_vidc_get_mbs_per_frame(a1, a2);
  v6 = *(unsigned int *)a2;
  memset(src, 0, 136);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  result = msm_vidc_init_codec_input_freq(a1, v6, src);
  if ( !(_DWORD)result )
  {
    memcpy(dest, src, sizeof(dest));
    result = ((__int64 (__fastcall *)(_BYTE *, __int64 *))msm_vidc_calculate_frequency)(dest, &v18);
    if ( !(_DWORD)result )
    {
      if ( *(_DWORD *)(a1 + 308) == 1 )
      {
        v8 = v18;
        if ( !*(_QWORD *)(a1 + 21488) )
        {
          result = is_vpp_cycles_close_to_freq_corner(v4, (unsigned int)v18);
          v8 = v18;
          if ( (result & 1) != 0 )
          {
            v8 = 5 * (int)v18 / 0x64u + v18;
            LODWORD(v18) = v8;
            if ( (unsigned int)v20 <= v8 )
              v9 = v8;
            else
              v9 = v20;
            LODWORD(v20) = v9;
          }
        }
      }
      else
      {
        v8 = v18;
      }
      v10 = 1000000LL * v8;
      v11 = 1000000LL * HIDWORD(v18);
      v12 = 1000000LL * (unsigned int)v19;
      v13 = 1000000LL * HIDWORD(v19);
      if ( a1 && (msm_vidc_debug & 8) != 0 )
      {
        result = printk(&unk_8D464, "perf", a1 + 340, "msm_vidc_calc_freq_iris4", *(unsigned int *)a2);
        if ( !*(_QWORD *)(a1 + 33416) )
          goto LABEL_14;
      }
      else if ( !*(_QWORD *)(a1 + 33416) )
      {
LABEL_14:
        if ( *(_DWORD *)(a1 + 312) != 16 && !*(_QWORD *)(a1 + 15608) )
        {
          if ( *(_BYTE *)(v5 + 12) != 1 || (result = is_hevc_10bit_decode_session(a1), (result & 1) == 0) )
          {
            if ( (unsigned __int64)get_clock_freq_count(v4, "video_cc_mvs0_clk_src") >= 2 )
            {
              clock_freq = get_clock_freq(v4, "video_cc_mvs0_clk_src");
              if ( v10 >= clock_freq )
                v10 = clock_freq;
            }
            if ( (unsigned __int64)get_clock_freq_count(v4, "video_cc_mvs0a_clk_src") >= 2 )
            {
              v15 = get_clock_freq(v4, "video_cc_mvs0a_clk_src");
              if ( v11 >= v15 )
                v11 = v15;
            }
            if ( (unsigned __int64)get_clock_freq_count(v4, "video_cc_mvs0b_clk_src") >= 2 )
            {
              v16 = get_clock_freq(v4, "video_cc_mvs0b_clk_src");
              if ( v12 >= v16 )
                v12 = v16;
            }
            result = get_clock_freq_count(v4, "video_cc_mvs0c_clk_src");
            if ( result >= 2 )
            {
              result = get_clock_freq(v4, "video_cc_mvs0c_clk_src");
              if ( v13 >= result )
                v13 = result;
            }
          }
        }
      }
      a2[2] = v10;
      a2[3] = v11;
      a2[4] = v12;
      a2[5] = v13;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
