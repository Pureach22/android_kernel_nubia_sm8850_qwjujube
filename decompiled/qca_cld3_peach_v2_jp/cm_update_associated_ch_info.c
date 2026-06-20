__int64 __fastcall cm_update_associated_ch_info(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 result; // x0
  _DWORD *v14; // x22
  unsigned __int16 *v15; // x21
  int sta_ch_width; // w0
  unsigned int *v17; // x8
  bool is_24ghz_ch_freq; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  int v28; // w8
  int v29; // w9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int8 v38; // w2
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 152);
  v48 = 0;
  if ( v10 )
  {
    result = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( result )
    {
      v14 = (_DWORD *)(result + 20480);
      if ( (a2 & 1) != 0 )
      {
        v15 = *(unsigned __int16 **)(a1 + 40);
        if ( v15 )
        {
          sta_ch_width = wlan_mlme_get_sta_ch_width(a1, &v48, nullptr);
          v17 = (unsigned int *)(v15 + 12);
          if ( !sta_ch_width )
            v17 = &v48;
          v14[942] = *v17;
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*v15);
          v27 = *((_DWORD *)v15 + 6);
          if ( is_24ghz_ch_freq && v27 == 1 )
          {
            v28 = *v15;
            v29 = *((_DWORD *)v15 + 4);
            if ( v29 == v28 + 10 )
            {
              v14[945] = v28 + 20;
              v29 = *((_DWORD *)v15 + 4);
              v28 = *v15;
            }
            if ( v29 == v28 - 10 )
              v14[945] = v28 - 20;
          }
          else if ( v27 == 7 )
          {
            if ( wlan_reg_is_6ghz_chan_freq(*v15) )
              v38 = 4;
            else
              v38 = 2;
            v39 = wlan_reg_chan_band_to_freq(
                    v10,
                    *((unsigned __int8 *)v15 + 4),
                    v38,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37);
            v14[946] = v39;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: ch_freq_seg2: %d, cen320_freq: %d",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "cm_update_associated_ch_info",
              *((unsigned __int8 *)v15 + 4),
              v39);
          }
          result = qdf_trace_msg(
                     0x68u,
                     8u,
                     "%s: ch width :%d, ch_freq:%d, ch_cfreq1:%d, sec_2g_freq:%d",
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     "cm_update_associated_ch_info",
                     (unsigned int)v14[942],
                     *v15,
                     *((unsigned int *)v15 + 4),
                     (unsigned int)v14[945]);
        }
      }
      else
      {
        *(_DWORD *)(result + 24248) = 8;
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: invalid pdev",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "cm_update_associated_ch_info");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
