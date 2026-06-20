__int64 __fastcall msm_venc_s_fmt_output(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  int v6; // w0
  __int64 v7; // x9
  bool v8; // zf
  int v9; // w8
  int v10; // w10
  int v11; // w9
  int v12; // w10
  int v13; // w11
  int v14; // w8
  __int64 v15; // x8
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  int v17; // w0
  int v18; // w8
  __int64 v19; // x8
  __int64 v20; // x9
  __int64 (__fastcall *v21)(__int64, __int64); // x9
  int v22; // w0
  unsigned int v23; // w9
  unsigned int v24; // w8
  __int64 v25; // x0

  v2 = *(_QWORD *)(a1 + 320);
  msm_venc_try_fmt((_DWORD *)a1, (unsigned int *)a2);
  if ( *(_DWORD *)(a1 + 608) == *(_DWORD *)(a2 + 16) || (result = msm_venc_codec_change(a1), !(_DWORD)result) )
  {
    *(_DWORD *)(a1 + 592) = 9;
    v6 = v4l2_codec_to_driver(a1, *(unsigned int *)(a2 + 16), "msm_venc_s_fmt_output");
    v7 = *(_QWORD *)(a1 + 23168);
    v8 = v6 == 2 || v6 == 8;
    v9 = *(_DWORD *)(a1 + 1908);
    v10 = v8;
    if ( v7 == 270 || v7 == 90 )
    {
      v11 = *(_DWORD *)(a1 + 1904);
    }
    else
    {
      v11 = *(_DWORD *)(a1 + 1908);
      v9 = *(_DWORD *)(a1 + 1904);
    }
    if ( v10 )
      v12 = 31;
    else
      v12 = 15;
    v13 = *(_DWORD *)(a1 + 312);
    *(_DWORD *)(a1 + 600) = (v9 + v12) & ~v12;
    *(_DWORD *)(a1 + 604) = (v11 + v12) & ~v12;
    if ( v13 == 8 )
    {
      v14 = *(_DWORD *)(a1 + 26528);
      *(_DWORD *)(a1 + 604) = v14;
      *(_DWORD *)(a1 + 600) = v14;
    }
    *(_DWORD *)(a1 + 624) = 0;
    *(_BYTE *)(a1 + 780) = 1;
    if ( v2
      && (v15 = *(_QWORD *)(v2 + 6560)) != 0
      && (v16 = *(__int64 (__fastcall **)(__int64, __int64))(v15 + 48)) != nullptr )
    {
      if ( *((_DWORD *)v16 - 1) != 1958436756 )
        __break(0x8228u);
      v17 = v16(a1, 2);
    }
    else
    {
      v17 = 0;
    }
    *(_DWORD *)(a1 + 620) = v17;
    v18 = *(_DWORD *)(a2 + 24);
    if ( v18 && v18 != 3 )
    {
      v18 = 0;
      *(_DWORD *)(a2 + 24) = 0;
    }
    *(_DWORD *)(a1 + 616) = v18;
    *(_BYTE *)(a1 + 784) = *(_BYTE *)(a2 + 192);
    *(_BYTE *)(a1 + 782) = *(_BYTE *)(a2 + 190);
    *(_BYTE *)(a1 + 783) = *(_BYTE *)(a2 + 191);
    if ( v2 )
    {
      v19 = *(_QWORD *)(v2 + 6560);
      if ( v19 )
      {
        v19 = *(_QWORD *)(v19 + 56);
        if ( v19 )
        {
          if ( *(_DWORD *)(v19 - 4) != 1958436756 )
            __break(0x8228u);
          LODWORD(v19) = ((__int64 (__fastcall *)(__int64, __int64))v19)(a1, 2);
        }
      }
      *(_DWORD *)(a1 + 2560) = v19;
      v20 = *(_QWORD *)(v2 + 6560);
      if ( v20 && (v21 = *(__int64 (__fastcall **)(__int64, __int64))(v20 + 64)) != nullptr )
      {
        if ( *((_DWORD *)v21 - 1) != 1958436756 )
          __break(0x8229u);
        v22 = v21(a1, 2);
        LODWORD(v19) = *(_DWORD *)(a1 + 2560);
      }
      else
      {
        v22 = 0;
      }
    }
    else
    {
      LODWORD(v19) = 0;
      v22 = 0;
      *(_DWORD *)(a1 + 2560) = 0;
    }
    v23 = *(_DWORD *)(a1 + 2568);
    v24 = v19 + v22;
    *(_DWORD *)(a1 + 2564) = v22;
    if ( v23 < v24 )
      *(_DWORD *)(a1 + 2568) = v24;
    *(_DWORD *)(a1 + 2572) = *(_DWORD *)(a1 + 620);
    msm_vidc_update_meta_port_settings(a1);
    if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v25 = v4l2_pixelfmt_name(a1, *(unsigned int *)(a1 + 608));
        printk(&unk_9136E, "high", a1 + 340, "msm_venc_s_fmt_output", v25);
      }
    }
    memcpy((void *)a2, (const void *)(a1 + 592), 0xD0u);
    return 0;
  }
  return result;
}
