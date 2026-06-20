__int64 __fastcall msm_venc_inst_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 (__fastcall *v12)(__int64, __int64); // x9
  int v13; // w0
  int v14; // w9
  int v15; // w8
  int v16; // w9
  unsigned int v17; // w0
  int v18; // w0
  int v19; // w8
  __int64 v20; // x8
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  int v22; // w0
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 (__fastcall *v25)(__int64, __int64); // x9
  int v26; // w0
  int v27; // w9
  int v28; // w0
  unsigned int v29; // w1

  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_venc_inst_init", a5);
  v6 = *(_QWORD *)(a1 + 320);
  if ( *(_QWORD *)(v6 + 4464) )
    *(_BYTE *)(a1 + 1932) = 1;
  *(_DWORD *)(a1 + 624) = 0;
  *(_DWORD *)(a1 + 592) = 9;
  *(_QWORD *)(a1 + 600) = 0xF000000140LL;
  *(_DWORD *)(a1 + 608) = 875967048;
  *(_BYTE *)(a1 + 780) = 1;
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 6560);
    if ( v7 && (v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v8 - 1) != 1958436756 )
        __break(0x8228u);
      v9 = v8(a1, 2);
    }
    else
    {
      v9 = 0;
    }
    *(_DWORD *)(a1 + 620) = v9;
    *(_QWORD *)(a1 + 612) = 1;
    *(_BYTE *)(a1 + 784) = 0;
    *(_WORD *)(a1 + 782) = 0;
    v10 = *(_QWORD *)(v6 + 6560);
    if ( v10 )
    {
      v10 = *(_QWORD *)(v10 + 56);
      if ( v10 )
      {
        if ( *(_DWORD *)(v10 - 4) != 1958436756 )
          __break(0x8228u);
        LODWORD(v10) = ((__int64 (__fastcall *)(__int64, __int64))v10)(a1, 2);
      }
    }
    *(_DWORD *)(a1 + 2560) = v10;
    v11 = *(_QWORD *)(v6 + 6560);
    if ( v11 && (v12 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 64)) != nullptr )
    {
      if ( *((_DWORD *)v12 - 1) != 1958436756 )
        __break(0x8229u);
      v13 = v12(a1, 2);
      LODWORD(v10) = *(_DWORD *)(a1 + 2560);
    }
    else
    {
      v13 = 0;
    }
  }
  else
  {
    LODWORD(v10) = 0;
    v13 = 0;
    *(_DWORD *)(a1 + 620) = 0;
    *(_QWORD *)(a1 + 612) = 1;
    *(_BYTE *)(a1 + 784) = 0;
    *(_WORD *)(a1 + 782) = 0;
    *(_DWORD *)(a1 + 2560) = 0;
  }
  v14 = *(_DWORD *)(a1 + 620);
  *(_DWORD *)(a1 + 2568) = v10 + v13;
  v15 = *(_DWORD *)(a1 + 600);
  *(_DWORD *)(a1 + 2572) = v14;
  v16 = *(_DWORD *)(a1 + 604);
  *(_DWORD *)(a1 + 2564) = v13;
  *(_DWORD *)(a1 + 1888) = v15;
  *(_DWORD *)(a1 + 1904) = v15;
  *(_QWORD *)(a1 + 1880) = 0;
  *(_DWORD *)(a1 + 1892) = v16;
  *(_QWORD *)(a1 + 1896) = 0;
  *(_DWORD *)(a1 + 1908) = v16;
  *(_DWORD *)(a1 + 1008) = 13;
  *(_DWORD *)(a1 + 1016) = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_venc_inst_init");
  *(_DWORD *)(a1 + 1020) = 0x4000;
  *(_QWORD *)(a1 + 2680) = 0;
  *(_QWORD *)(a1 + 2688) = 0;
  *(_DWORD *)(a1 + 384) = 10;
  v17 = v4l2_colorformat_from_driver(a1, 1, "msm_venc_inst_init");
  *(_DWORD *)(a1 + 400) = v17;
  *(_QWORD *)(a1 + 392) = 0xF000000140LL;
  *(_BYTE *)(a1 + 572) = 1;
  v18 = v4l2_colorformat_to_driver(a1, v17, "msm_venc_inst_init");
  v19 = 0;
  if ( v18 > 15 )
  {
    if ( v18 == 16 || v18 == 128 || v18 == 256 )
      v19 = 768;
    goto LABEL_35;
  }
  if ( (unsigned int)(v18 - 1) < 2 || v18 == 4 )
  {
    *(_DWORD *)(a1 + 416) = 384;
    if ( v6 )
      goto LABEL_36;
LABEL_54:
    LODWORD(v23) = 0;
    v26 = 0;
    *(_DWORD *)(a1 + 412) = 0;
    *(_QWORD *)(a1 + 404) = 1;
    *(_BYTE *)(a1 + 576) = 0;
    *(_WORD *)(a1 + 574) = 0;
    *(_DWORD *)(a1 + 2520) = 0;
    goto LABEL_55;
  }
  if ( v18 != 8 )
  {
LABEL_35:
    *(_DWORD *)(a1 + 416) = v19;
    if ( v6 )
      goto LABEL_36;
    goto LABEL_54;
  }
  *(_DWORD *)(a1 + 416) = 512;
  if ( !v6 )
    goto LABEL_54;
LABEL_36:
  v20 = *(_QWORD *)(v6 + 6560);
  if ( v20 && (v21 = *(__int64 (__fastcall **)(__int64, __int64))(v20 + 48)) != nullptr )
  {
    if ( *((_DWORD *)v21 - 1) != 1958436756 )
      __break(0x8228u);
    v22 = v21(a1, 1);
  }
  else
  {
    v22 = 0;
  }
  *(_DWORD *)(a1 + 412) = v22;
  *(_QWORD *)(a1 + 404) = 1;
  *(_BYTE *)(a1 + 576) = 0;
  *(_WORD *)(a1 + 574) = 0;
  v23 = *(_QWORD *)(v6 + 6560);
  if ( v23 )
  {
    v23 = *(_QWORD *)(v23 + 56);
    if ( v23 )
    {
      if ( *(_DWORD *)(v23 - 4) != 1958436756 )
        __break(0x8228u);
      LODWORD(v23) = ((__int64 (__fastcall *)(__int64, __int64))v23)(a1, 1);
    }
  }
  *(_DWORD *)(a1 + 2520) = v23;
  v24 = *(_QWORD *)(v6 + 6560);
  if ( v24 && (v25 = *(__int64 (__fastcall **)(__int64, __int64))(v24 + 64)) != nullptr )
  {
    if ( *((_DWORD *)v25 - 1) != 1958436756 )
      __break(0x8229u);
    v26 = v25(a1, 1);
    LODWORD(v23) = *(_DWORD *)(a1 + 2520);
  }
  else
  {
    v26 = 0;
  }
LABEL_55:
  v27 = *(_DWORD *)(a1 + 412);
  *(_DWORD *)(a1 + 2524) = v26;
  *(_DWORD *)(a1 + 2528) = v23 + v26;
  *(_DWORD *)(a1 + 2532) = v27;
  *(_DWORD *)(a1 + 800) = 14;
  v28 = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_venc_inst_init");
  v29 = *(_DWORD *)(a1 + 608);
  *(_DWORD *)(a1 + 808) = v28;
  *(_DWORD *)(a1 + 812) = 0x4000;
  *(_QWORD *)(a1 + 1828) = 0x100000000LL;
  *(_QWORD *)(a1 + 2640) = 0;
  *(_QWORD *)(a1 + 2648) = 0;
  return msm_venc_codec_change(a1, v29);
}
