__int64 __fastcall sde_hw_sspp_setup_rects(__int64 result, __int64 a2, unsigned int a3)
{
  int v4; // w10
  int v5; // w22
  __int64 v7; // x19
  unsigned int v8; // w24
  unsigned int v9; // w27
  int v10; // w23
  int v11; // w8
  int v12; // w8
  int v13; // w25
  int v14; // w0
  int v15; // w9
  int v16; // w8
  unsigned int v17; // w25
  unsigned int v18; // w26
  unsigned int v19; // w28
  int v20; // w23
  int v21; // w25
  int v22; // w26
  int v23; // w27
  unsigned int v24; // w24
  unsigned int v25; // w21
  int v26; // w0
  int v27; // w8
  bool v28; // zf
  unsigned int v29; // w20
  int v30; // w25
  unsigned int v31; // w23
  int v32; // w26
  int v33; // w27
  int v34; // w28
  const char *v35; // x3
  unsigned int v36; // w1
  __int64 v37; // x0
  unsigned int v38; // w2
  int v39; // [xsp+Ch] [xbp-14h]
  int v40; // [xsp+10h] [xbp-10h]
  unsigned int v41; // [xsp+14h] [xbp-Ch]
  int v42; // [xsp+18h] [xbp-8h]
  unsigned int v43; // [xsp+1Ch] [xbp-4h]

  if ( result && a2 )
  {
    v4 = a3 >= 2 ? 360 : 8;
    v39 = v4;
    v5 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    v7 = result;
    v8 = *(_DWORD *)(a2 + 72);
    v9 = *(_DWORD *)(a2 + 76);
    v10 = a3 >= 2 ? 364 : 0;
    v41 = *(_DWORD *)(a2 + 84);
    v11 = a3 >= 2 ? 352 : 12;
    v40 = v11;
    v12 = a3 >= 2 ? 356 : 16;
    v43 = *(_DWORD *)(a2 + 80);
    v42 = v12;
    if ( a3 )
    {
      v13 = sde_reg_read(result, v5 + 36);
      v14 = sde_reg_read(v7, v5 + 40);
      v15 = *(unsigned __int16 *)(a2 + 56);
      v16 = *(unsigned __int16 *)(a2 + 64);
      if ( a3 == 1 )
      {
        v17 = v15 | v13 & 0xFFFF0000;
        v18 = v16 | v14 & 0xFFFF0000;
      }
      else
      {
        v17 = (unsigned __int16)v13 | ((unsigned __int16)v15 << 16);
        v18 = (unsigned __int16)v14 | ((unsigned __int16)v16 << 16);
      }
    }
    else
    {
      v17 = *(_DWORD *)(a2 + 56) | (*(_DWORD *)(a2 + 60) << 16);
      v18 = *(_DWORD *)(a2 + 64) | (*(_DWORD *)(a2 + 68) << 16);
    }
    v19 = (*(_DWORD *)(*(_QWORD *)(v7 + 56) + 32LL) & 0x40000C) != 0
        ? ~(-1 << *(_BYTE *)(a2 + 105)) | (~(-1 << *(_BYTE *)(a2 + 104)) << 8)
        : 0;
    sde_reg_write(v7, v5 + v10, v9, "src_size_off + idx");
    sde_reg_write(v7, v5 + v39, v8, "src_xy_off + idx");
    sde_reg_write(v7, v5 + v40, v41, "out_size_off + idx");
    sde_reg_write(v7, v5 + v42, v43, "out_xy_off + idx");
    sde_reg_write(v7, v5 + 36, v17, "SSPP_SRC_YSTRIDE0 + idx");
    sde_reg_write(v7, v5 + 40, v18, "SSPP_SRC_YSTRIDE1 + idx");
    result = sde_reg_write(v7, v5 + 180, v19, "SSPP_DECIMATION_CONFIG + idx");
    if ( a3 )
    {
      v20 = *(unsigned __int16 *)(a2 + 94);
      v21 = *(unsigned __int16 *)(a2 + 92);
      v22 = *(unsigned __int16 *)(a2 + 102);
      v23 = *(unsigned __int16 *)(a2 + 100);
      v24 = *(_DWORD *)(a2 + 88);
      v25 = *(_DWORD *)(a2 + 96);
      v26 = sde_reg_read(v7, v5 + 368);
      if ( a3 == 1 )
        v27 = 256;
      else
        v27 = 512;
      if ( v21 | v23 | v20 | v22 )
      {
        v28 = a3 == 1;
        v29 = v21 | (v20 << 16);
        if ( v28 )
          v30 = 772;
        else
          v30 = 788;
        v31 = v23 | (v22 << 16);
        if ( v28 )
          v32 = 768;
        else
          v32 = 784;
        if ( v28 )
          v33 = 776;
        else
          v33 = 792;
        if ( v28 )
          v34 = 780;
        else
          v34 = 796;
        sde_reg_write(v7, v5 + 368, v26 | v27, "SSPP_MULTIRECT_OPMODE + idx");
        sde_reg_write(v7, v5 + v34, v29, "src_size_ext_off + idx");
        sde_reg_write(v7, v5 + v33, v24, "src_xy_ext_off + idx");
        sde_reg_write(v7, v5 + v32, v31, "out_size_ext_off + idx");
        v35 = "out_xy_ext_off + idx";
        v36 = v5 + v30;
        v37 = v7;
        v38 = v25;
      }
      else
      {
        v35 = "SSPP_MULTIRECT_OPMODE + idx";
        v36 = v5 + 368;
        v38 = v26 & ~v27;
        v37 = v7;
      }
      return sde_reg_write(v37, v36, v38, v35);
    }
  }
  return result;
}
