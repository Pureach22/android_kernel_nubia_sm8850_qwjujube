__int64 __fastcall msm_vidc_scale_buses(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  _QWORD *v5; // x22
  unsigned int v7; // w8
  int v8; // w8
  int v10; // w10
  int v11; // w11
  bool v12; // zf
  int v13; // w9
  _QWORD *v14; // x20
  int v15; // w9
  int v16; // w8
  int v17; // w9
  int v18; // w8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x10
  unsigned int frame_rate; // w0
  unsigned int v23; // w8
  int v24; // w1
  int v25; // w0
  __int64 v26; // x8
  int v27; // w1
  int v28; // w8
  int v29; // w0
  int v30; // w8
  int v31; // w9
  unsigned int v32; // w8
  unsigned int v33; // w21
  unsigned int v34; // w23
  int mbs_per_frame; // w0
  __int64 *v36; // x10
  unsigned int v37; // w8
  unsigned int v38; // w12
  unsigned int v39; // w11
  int v40; // w20
  unsigned int v41; // w10
  unsigned int v42; // w21
  __int64 v43; // x3
  __int64 v44; // x8
  void (__fastcall *v45)(__int64, __int64); // x8
  unsigned int v46; // w10
  int v47; // w9
  unsigned int v48; // w8
  unsigned int v49; // w11
  int v50; // w9
  unsigned int v51; // w11
  __int64 v52; // x22
  __int64 *v53; // x8
  __int64 v54; // x23
  __int64 v55; // x20
  __int64 v56; // x21
  int v57; // w4
  int v58; // w4
  int v59; // w8

  v5 = *(_QWORD **)(a1 + 320);
  if ( !v5[488] )
  {
    if ( !a1 || (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    printk(&unk_80740, "err ", a1 + 340, "msm_vidc_scale_buses", a5);
    return 4294967274LL;
  }
  v7 = *(_DWORD *)(a1 + 1916);
  *(_DWORD *)(a1 + 2024) = 0;
  if ( v7 >= 0x10 )
  {
    v8 = *(_DWORD *)(a1 + 312);
    if ( v8 != 8 )
    {
      v10 = *(_DWORD *)(a1 + 396);
      v11 = *(_DWORD *)(a1 + 600);
      v12 = v8 == 4 || v8 == 2;
      *(_DWORD *)(a1 + 2044) = *(_DWORD *)(a1 + 392);
      v13 = *(_DWORD *)(a1 + 604);
      *(_DWORD *)(a1 + 2040) = v10;
      *(_DWORD *)(a1 + 2056) = v11;
      *(_DWORD *)(a1 + 2052) = v13;
      v14 = (_QWORD *)(a1 + 34088);
      if ( v12 )
        v15 = 32;
      else
        v15 = 16;
      *(_DWORD *)(a1 + 2020) = v8;
      *(_DWORD *)(a1 + 2076) = v15;
      if ( v8 == 16 )
      {
        if ( *(_QWORD *)(a1 + 34256) )
          v16 = 128;
        else
          v16 = 64;
        *(_DWORD *)(a1 + 2076) = v16;
      }
      v17 = *(_DWORD *)(a1 + 308);
      v18 = *(_DWORD *)(a1 + 38700);
      *(_DWORD *)(a1 + 2080) = v18;
      if ( v17 == 2 )
      {
        v27 = *(_DWORD *)(a1 + 608);
        v28 = v18 * *(_DWORD *)(a1 + 38432);
        *(_DWORD *)(a1 + 2016) = 2;
        *(_DWORD *)(a1 + 2048) = 8 * v28;
        v29 = v4l2_colorformat_to_driver(a1, v27, (__int64)"msm_vidc_scale_buses");
        if ( (unsigned int)(v29 - 2) <= 0x3E && ((1LL << ((unsigned __int8)v29 - 2)) & 0x4000000000004005LL) != 0
          || v29 == 256 )
        {
          *(_DWORD *)(a1 + 2036) = 2;
          v30 = 8;
          if ( v29 <= 127 && v29 != 8 && v29 != 16 )
            v30 = 2;
          v31 = *(_DWORD *)(a1 + 312);
          *(_DWORD *)(a1 + 2028) = v30;
          if ( v31 == 64 )
            *(_DWORD *)(a1 + 2028) = 128;
          *(_DWORD *)(a1 + 2032) = v29;
        }
        else
        {
          if ( *(_DWORD *)(a1 + 312) == 16 && *v14 )
          {
            v59 = 2;
            *(_DWORD *)(a1 + 2032) = v29;
          }
          else
          {
            v59 = 1;
          }
          *(_DWORD *)(a1 + 2036) = v59;
          *(_DWORD *)(a1 + 2028) = v29;
        }
      }
      else if ( v17 == 1 )
      {
        v19 = *(_QWORD *)(a1 + 15944);
        v20 = *(_QWORD *)(a1 + 15440);
        v21 = *(_QWORD *)(a1 + 23168);
        *(_DWORD *)(a1 + 2016) = 1;
        *(_DWORD *)(a1 + 2048) = v20;
        *(_DWORD *)(a1 + 2060) = v21;
        *(_BYTE *)(a1 + 2089) = v19 > 0;
        frame_rate = msm_vidc_get_frame_rate(a1);
        if ( frame_rate )
        {
          v23 = *(_DWORD *)(a1 + 38700);
          if ( v23 > frame_rate )
            *(_DWORD *)(a1 + 2048) = *(_DWORD *)(a1 + 2048) / frame_rate * v23;
        }
        v24 = *(_DWORD *)(a1 + 400);
        *(_DWORD *)(a1 + 2036) = 1;
        v25 = v4l2_colorformat_to_driver(a1, v24, (__int64)"msm_vidc_scale_buses");
        v26 = *(_QWORD *)(a1 + 16784);
        *(_DWORD *)(a1 + 2028) = v25;
        *(_BYTE *)(a1 + 2116) = v26 != 0;
      }
      *(_DWORD *)(a1 + 2084) = *(_QWORD *)(a1 + 11576);
      if ( *(_BYTE *)(v5[488] + 108LL) == 1 )
        *(_BYTE *)(a1 + 2088) = 1;
      v32 = *(_DWORD *)(a1 + 1996);
      v33 = *(_DWORD *)(a1 + 2000);
      *(_DWORD *)(a1 + 2112) = v5[534];
      if ( v32 )
        v34 = v32;
      else
        v34 = 0x10000;
      if ( v33 )
      {
        mbs_per_frame = msm_vidc_get_mbs_per_frame((_DWORD *)a1);
        if ( (unsigned int)(3 * (mbs_per_frame / 256) + 1) >= 3 )
          v33 /= (unsigned int)(3 * (mbs_per_frame / 256) / 2);
      }
      else
      {
        v33 = 0x40000;
      }
      v36 = *(__int64 **)(a1 + 3976);
      v37 = 327680;
      while ( v36 != (__int64 *)(a1 + 3976) )
      {
        v38 = *((_DWORD *)v36 + 5);
        v36 = (__int64 *)*v36;
        if ( v37 >= v38 )
          v37 = v38;
      }
      if ( v33 <= 0x10000 )
        v39 = 0x10000;
      else
        v39 = v33;
      *(_DWORD *)(a1 + 2068) = v33;
      *(_DWORD *)(a1 + 2064) = v34;
      if ( v39 >= 0x40000 )
        v40 = 0x40000;
      else
        v40 = v39;
      *(_DWORD *)(a1 + 2072) = v37;
      if ( v34 <= 0x10000 )
        v41 = 0x10000;
      else
        v41 = v34;
      if ( v41 >= 0x50000 )
        v42 = 327680;
      else
        v42 = v41;
      if ( v37 > 0x10000 )
      {
        *(_DWORD *)(a1 + 2064) = v42;
        if ( v37 >= 0x50000 )
          v43 = 327680;
        else
          v43 = v37;
        *(_DWORD *)(a1 + 2068) = v40;
        *(_DWORD *)(a1 + 2072) = v43;
        if ( a1 )
        {
LABEL_69:
          if ( (msm_vidc_debug & 4) != 0 )
            printk(&unk_8B7A6, "low ", a1 + 340, v43, v42);
        }
      }
      else
      {
        if ( a1 )
        {
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_7FB59, "high", a1 + 340, "fill_dynamic_stats", 0x10000);
          v43 = 0;
          *(_DWORD *)(a1 + 2064) = v42;
          *(_DWORD *)(a1 + 2068) = v40;
          *(_DWORD *)(a1 + 2072) = 0;
          goto LABEL_69;
        }
        unk_810 = v42;
        unk_814 = v40;
        unk_818 = 0;
      }
      if ( v5 )
      {
        v44 = v5[820];
        if ( v44 )
        {
          v45 = *(void (__fastcall **)(__int64, __int64))(v44 + 8);
          if ( v45 )
          {
            if ( *((_DWORD *)v45 - 1) != 1211071205 )
              __break(0x8228u);
            v45(a1, a1 + 2016);
          }
        }
      }
      v46 = *(_DWORD *)(a1 + 2104);
      v47 = *(_DWORD *)(a1 + 4312);
      v48 = *(_DWORD *)(a1 + 2096);
      v49 = v47 + v46;
      v12 = v47 == 0;
      v50 = *(_DWORD *)(a1 + 4316);
      v51 = v49 >> 1;
      *(_DWORD *)(a1 + 1988) = v46;
      *(_DWORD *)(a1 + 1984) = v48;
      if ( !v12 )
        v46 = v51;
      *(_DWORD *)(a1 + 4312) = v46;
      if ( v50 )
        v48 = (v50 + v48) >> 1;
      *(_DWORD *)(a1 + 4316) = v48;
      goto LABEL_83;
    }
  }
  *(_DWORD *)(a1 + 2024) = 2;
LABEL_83:
  v52 = *(_QWORD *)(a1 + 320);
  *(_DWORD *)(a1 + 1912) = *(_DWORD *)(a1 + 2024);
  mutex_lock(v52 + 3856);
  v53 = *(__int64 **)(v52 + 3528);
  if ( v53 == (__int64 *)(v52 + 3528) )
  {
    v55 = 0;
    v56 = 1000;
LABEL_95:
    mutex_unlock(v52 + 3856);
  }
  else
  {
    v54 = 0;
    v55 = 0;
    v56 = 0x7FFFFFFF;
    do
    {
      if ( *((_DWORD *)v53 + 9608) && *((_BYTE *)v53 + 38408) == 1 )
      {
        if ( *((_DWORD *)v53 + 478) == 2 )
        {
          v55 = 0x7FFFFFFF;
          goto LABEL_95;
        }
        v54 += *((unsigned int *)v53 + 496);
        v55 += *((unsigned int *)v53 + 497);
      }
      v53 = (__int64 *)*v53;
    }
    while ( v53 != (__int64 *)(v52 + 3528) );
    mutex_unlock(v52 + 3856);
    if ( v54 )
      v56 = v54;
    else
      v56 = 1000;
  }
  v57 = msm_vidc_ddr_bw;
  if ( msm_vidc_ddr_bw )
  {
    if ( (msm_vidc_debug & 4) != 0 )
    {
      printk(&unk_82C9F, "low ", 0xFFFFFFFFLL, "codec", (unsigned int)msm_vidc_ddr_bw);
      v57 = msm_vidc_ddr_bw;
    }
    v56 = v57;
  }
  v58 = msm_vidc_llc_bw;
  if ( msm_vidc_llc_bw )
  {
    if ( (msm_vidc_debug & 4) != 0 )
    {
      printk(&unk_9003F, "low ", 0xFFFFFFFFLL, "codec", (unsigned int)msm_vidc_llc_bw);
      v58 = msm_vidc_llc_bw;
    }
    v55 = v58;
  }
  return venus_hfi_scale_buses(a1, v56, v55);
}
