__int64 __fastcall msm_vdec_inst_init(__int64 a1)
{
  _QWORD *v1; // x21
  __int64 v3; // x8
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 (__fastcall *v8)(__int64, __int64); // x9
  int v9; // w0
  int v10; // w9
  int v11; // w8
  int v12; // w9
  unsigned int v13; // w0
  int v14; // w0
  int v15; // w8
  int v16; // w8
  int v17; // w9
  int v18; // w8
  __int64 v19; // x8
  __int64 (__fastcall *v20)(__int64, __int64); // x8
  int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 (__fastcall *v24)(__int64, __int64); // x9
  int v25; // w0
  int v26; // w9
  int v27; // w0
  unsigned int v28; // w1

  v1 = *(_QWORD **)(a1 + 320);
  *(_QWORD *)(a1 + 3688) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 3696) = a1 + 3696;
  *(_QWORD *)(a1 + 3704) = a1 + 3696;
  *(_QWORD *)(a1 + 3712) = msm_vidc_batch_handler;
  init_timer_key(a1 + 3720, &delayed_work_timer_fn, 0x200000, 0, 0);
  if ( v1[560] )
  {
    *(_BYTE *)(a1 + 3680) = 1;
    *(_DWORD *)(a1 + 3684) = 6;
  }
  if ( v1[558] )
    *(_BYTE *)(a1 + 1932) = 1;
  *(_DWORD *)(a1 + 416) = 0;
  *(_DWORD *)(a1 + 384) = 10;
  *(_QWORD *)(a1 + 392) = 0xF000000140LL;
  *(_DWORD *)(a1 + 400) = 875967048;
  *(_BYTE *)(a1 + 572) = 1;
  if ( v1 )
  {
    v3 = v1[820];
    if ( v3 && (v4 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v4 - 1) != 1958436756 )
        __break(0x8228u);
      v5 = v4(a1, 1);
    }
    else
    {
      v5 = 0;
    }
    *(_DWORD *)(a1 + 412) = v5;
    *(_DWORD *)(a1 + 404) = 1;
    v6 = v1[820];
    if ( v6 )
    {
      v6 = *(_QWORD *)(v6 + 56);
      if ( v6 )
      {
        if ( *(_DWORD *)(v6 - 4) != 1958436756 )
          __break(0x8228u);
        LODWORD(v6) = ((__int64 (__fastcall *)(__int64, __int64))v6)(a1, 1);
      }
    }
    *(_DWORD *)(a1 + 2520) = v6;
    v7 = v1[820];
    if ( v7 && (v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 64)) != nullptr )
    {
      if ( *((_DWORD *)v8 - 1) != 1958436756 )
        __break(0x8229u);
      v9 = v8(a1, 1);
      LODWORD(v6) = *(_DWORD *)(a1 + 2520);
    }
    else
    {
      v9 = 0;
    }
  }
  else
  {
    LODWORD(v6) = 0;
    v9 = 0;
    *(_DWORD *)(a1 + 412) = 0;
    *(_DWORD *)(a1 + 404) = 1;
    *(_DWORD *)(a1 + 2520) = 0;
  }
  v10 = *(_DWORD *)(a1 + 412);
  *(_DWORD *)(a1 + 2528) = v6 + v9;
  v11 = *(_DWORD *)(a1 + 392);
  *(_DWORD *)(a1 + 2532) = v10;
  v12 = *(_DWORD *)(a1 + 396);
  *(_DWORD *)(a1 + 2524) = v9;
  *(_DWORD *)(a1 + 1888) = v11;
  *(_QWORD *)(a1 + 1880) = 0;
  *(_DWORD *)(a1 + 1892) = v12;
  *(_DWORD *)(a1 + 800) = 14;
  *(_DWORD *)(a1 + 808) = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_vdec_inst_init");
  *(_DWORD *)(a1 + 812) = 0x4000;
  *(_QWORD *)(a1 + 2640) = 0;
  *(_QWORD *)(a1 + 2648) = 0;
  *(_DWORD *)(a1 + 592) = 9;
  v13 = v4l2_colorformat_from_driver(a1, 1, "msm_vdec_inst_init");
  *(_DWORD *)(a1 + 608) = v13;
  v14 = v4l2_colorformat_to_driver(a1, v13, "msm_vdec_inst_init");
  if ( (unsigned int)v14 <= 0x10 )
  {
    if ( ((1 << v14) & 0x10016) != 0 )
    {
LABEL_26:
      v15 = 384;
      goto LABEL_27;
    }
    if ( v14 == 8 )
    {
      *(_DWORD *)(a1 + 600) = 384;
      goto LABEL_38;
    }
  }
  if ( v14 == 256 || v14 == 128 )
    goto LABEL_26;
  v15 = 0;
LABEL_27:
  *(_DWORD *)(a1 + 600) = v15;
  if ( (unsigned int)v14 <= 0x10 )
  {
    if ( ((1 << v14) & 0x10016) != 0 )
    {
      v16 = 32;
LABEL_39:
      v17 = (v16 + 239) & -v16;
      goto LABEL_40;
    }
    if ( v14 == 8 )
      goto LABEL_38;
  }
  if ( v14 == 256 || v14 == 128 )
  {
LABEL_38:
    v16 = 16;
    goto LABEL_39;
  }
  v17 = 0;
LABEL_40:
  v18 = 0;
  *(_DWORD *)(a1 + 604) = v17;
  *(_BYTE *)(a1 + 780) = 1;
  if ( v14 > 15 )
  {
    if ( v14 == 16 || v14 == 128 || v14 == 256 )
      v18 = 768;
  }
  else if ( (unsigned int)(v14 - 1) < 2 || v14 == 4 )
  {
    v18 = 384;
  }
  else if ( v14 == 8 )
  {
    v18 = 512;
  }
  *(_DWORD *)(a1 + 624) = v18;
  if ( v1 )
  {
    v19 = v1[820];
    if ( v19 && (v20 = *(__int64 (__fastcall **)(__int64, __int64))(v19 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v20 - 1) != 1958436756 )
        __break(0x8228u);
      v21 = v20(a1, 2);
    }
    else
    {
      v21 = 0;
    }
    *(_DWORD *)(a1 + 620) = v21;
    *(_QWORD *)(a1 + 612) = 1;
    *(_BYTE *)(a1 + 784) = 0;
    *(_WORD *)(a1 + 782) = 0;
    v22 = v1[820];
    if ( v22 )
    {
      v22 = *(_QWORD *)(v22 + 56);
      if ( v22 )
      {
        if ( *(_DWORD *)(v22 - 4) != 1958436756 )
          __break(0x8228u);
        LODWORD(v22) = ((__int64 (__fastcall *)(__int64, __int64))v22)(a1, 2);
      }
    }
    *(_DWORD *)(a1 + 2560) = v22;
    v23 = v1[820];
    if ( v23 && (v24 = *(__int64 (__fastcall **)(__int64, __int64))(v23 + 64)) != nullptr )
    {
      if ( *((_DWORD *)v24 - 1) != 1958436756 )
        __break(0x8229u);
      v25 = v24(a1, 2);
      LODWORD(v22) = *(_DWORD *)(a1 + 2560);
    }
    else
    {
      v25 = 0;
    }
  }
  else
  {
    LODWORD(v22) = 0;
    v25 = 0;
    *(_DWORD *)(a1 + 620) = 0;
    *(_QWORD *)(a1 + 612) = 1;
    *(_BYTE *)(a1 + 784) = 0;
    *(_WORD *)(a1 + 782) = 0;
    *(_DWORD *)(a1 + 2560) = 0;
  }
  v26 = *(_DWORD *)(a1 + 620);
  *(_DWORD *)(a1 + 2564) = v25;
  *(_DWORD *)(a1 + 2568) = v22 + v25;
  *(_DWORD *)(a1 + 2572) = v26;
  *(_DWORD *)(a1 + 38716) = 0;
  *(_DWORD *)(a1 + 1008) = 13;
  v27 = v4l2_colorformat_from_driver(a1, 0x80000000LL, "msm_vdec_inst_init");
  v28 = *(_DWORD *)(a1 + 400);
  *(_DWORD *)(a1 + 1016) = v27;
  *(_DWORD *)(a1 + 1020) = 0x4000;
  *(_WORD *)(a1 + 38692) = 0;
  *(_QWORD *)(a1 + 2680) = 0;
  *(_QWORD *)(a1 + 2688) = 0;
  return msm_vdec_codec_change(a1, v28);
}
