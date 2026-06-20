__int64 __fastcall sde_hw_sspp_setup_format(__int64 result, __int64 a2, char a3, unsigned int a4, unsigned int a5)
{
  int v6; // w9
  _QWORD *v8; // x19
  int v10; // w23
  int v12; // w21
  int v13; // w24
  int v14; // w0
  int v15; // w8
  int v16; // w10
  int v17; // w12
  int v18; // w8
  int v19; // w9
  int v20; // w12
  int v21; // w27
  unsigned int v22; // w10
  int v23; // w22
  int v24; // w26
  int v25; // w8
  unsigned int v26; // w1
  unsigned int v27; // w8
  int v28; // w28
  int v29; // w8
  unsigned int v30; // w2
  unsigned int v31; // w8
  int v32; // w9
  unsigned int v33; // w10
  __int64 v34; // x8
  int v35; // w25
  __int64 v36; // x26
  unsigned int v37; // w20
  int v38; // w9
  int v39; // w8
  const char *v40; // x3
  __int64 v41; // x26
  unsigned int v42; // w9
  int v43; // w10
  unsigned int v44; // [xsp+8h] [xbp-8h]
  int v45; // [xsp+Ch] [xbp-4h]

  if ( result && a2 )
  {
    if ( a5 >= 2 )
      v6 = 380;
    else
      v6 = 56;
    v8 = (_QWORD *)result;
    v10 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL);
    if ( a5 >= 2 )
      v12 = 376;
    else
      v12 = 52;
    if ( a5 >= 2 )
      v13 = 372;
    else
      v13 = 48;
    v45 = v6;
    v14 = sde_reg_read(result, v10 + v6);
    v15 = *(_DWORD *)(a2 + 16);
    if ( (a4 & 8) != 0 )
    {
      if ( v15 == 1 )
      {
        v15 = 2;
      }
      else if ( v15 == 2 )
      {
        v15 = 1;
      }
    }
    v16 = *(_DWORD *)(a2 + 4);
    v44 = *(_DWORD *)(a2 + 8);
    v17 = (v15 << 23) | (v16 << 19);
    v18 = a4 & 0x10;
    v19 = (16 * *(unsigned __int8 *)(a2 + 14))
        | (v18 << 7)
        | v17
        | (*(unsigned __int8 *)(a2 + 15) << 6)
        | (4 * *(unsigned __int8 *)(a2 + 13))
        | *(unsigned __int8 *)(a2 + 12);
    v20 = v19 | 0x100;
    if ( v16 )
      v20 = v19;
    if ( *(_BYTE *)(a2 + 24) )
      v19 = v20;
    v21 = ((*(unsigned __int8 *)(a2 + 22) << 12) - 4096)
        | ((a4 & 0x20 | *(unsigned __int8 *)(a2 + 21)) << 17)
        | v19
        | (*(unsigned __int8 *)(a2 + 20) << 18);
    if ( (*(_QWORD *)(a2 + 32) & 0x10) != 0 )
    {
      v21 |= 0x10600u;
    }
    else
    {
      v22 = *(unsigned __int8 *)(a2 + 23);
      if ( v22 > 4 )
      {
        if ( v22 <= 8 )
          v21 |= ((v22 << 9) - 2560) | 0x10000;
      }
      else
      {
        v21 |= (v22 << 9) - 512;
      }
    }
    v23 = v14 & 0x7FFF9FFE | (((a4 >> 1) & 3) << 13);
    v24 = 0x40000000;
    if ( v18 )
      v24 = ~(8 * *(_QWORD *)(v8[7] + 32LL)) & 0x40000000;
    v25 = *(_DWORD *)(a2 + 28);
    if ( !v25 )
    {
      v28 = v45;
      goto LABEL_64;
    }
    if ( v25 == 2 )
      v23 |= ((unsigned int)*(_QWORD *)(a2 + 32) >> 2) & 1;
    v21 |= v25 << 30;
    sde_reg_write((__int64)v8, 0x48u, (*(_DWORD *)(v8[5] + 48LL) << 18) | 0x87, "SSPP_FETCH_CONFIG");
    v26 = 68;
    if ( a5 >= 2 )
    {
      if ( (*(_QWORD *)(v8[7] + 32LL) & 0x100000000LL) != 0 )
        v26 = 448;
      else
        v26 = 68;
    }
    v27 = *(_DWORD *)(v8[4] + 4LL);
    if ( v27 >> 28 >= 5 )
    {
      if ( (*(_QWORD *)(a2 + 32) & 1) != 0 )
      {
        v28 = v45;
        v29 = 0;
      }
      else
      {
        v28 = v45;
        if ( (*(_QWORD *)(a2 + 32) & 2) != 0 )
        {
          v29 = 0x40000000;
        }
        else if ( (*(_QWORD *)(a2 + 32) & 0x10LL) != 0 )
        {
          v29 = 0x40000000;
        }
        else
        {
          v29 = -1073741824;
        }
      }
      if ( *(_DWORD *)(a2 + 28) == 2 )
      {
        if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
        {
          if ( (*(_QWORD *)(a2 + 32) & 0x40LL) != 0 )
            v32 = 196608;
          else
            v32 = 0;
          if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
          {
            v33 = ((unsigned int)*(_QWORD *)(a2 + 32) << 11) & 0x10000;
            goto LABEL_62;
          }
        }
        else
        {
          v32 = 0;
        }
      }
      else
      {
        v32 = 0;
      }
      v33 = 0;
LABEL_62:
      v30 = v32 | v29 | v33;
      goto LABEL_63;
    }
    if ( (v27 & 0x70000000) == 0x40000000 )
    {
      v30 = ~((unsigned int)*(_QWORD *)(a2 + 32) << 30) & 0x40000000;
    }
    else
    {
      v31 = HIWORD(v27);
      if ( v31 == 4096 )
      {
        if ( (a3 & 1) != 0 )
          v43 = -2147483392;
        else
          v43 = 256;
        v30 = v43 & 0xFFFFFFFE | *(_DWORD *)(v8[5] + 56LL) & 1 | (16 * *(_DWORD *)(v8[5] + 48LL));
      }
      else
      {
        if ( v31 != 0x2000 )
        {
          v28 = v45;
          if ( v31 != 12288 )
            goto LABEL_64;
          v30 = *(_DWORD *)(v8[5] + 56LL) | v24 | (16 * *(_DWORD *)(v8[5] + 48LL));
LABEL_63:
          sde_reg_write((__int64)v8, v26, v30, "ubwc_ctrl_off");
LABEL_64:
          v34 = v8[7];
          v35 = ((*(_QWORD *)(a2 + 32) & 1) << 15) | ((unsigned int)*(_QWORD *)(a2 + 32) << 13) & 0x4000;
          if ( (*(_QWORD *)(v34 + 32) & 0x10) != 0 )
          {
            v41 = *(_QWORD *)(a2 + 32);
            if ( (*(_QWORD *)(v34 + 32) & 4) == 0 )
              goto LABEL_77;
            v37 = *(_DWORD *)(*(_QWORD *)(v34 + 48) + 100LL);
            if ( (*(_QWORD *)(v34 + 32) & 0x10) == 0 )
              goto LABEL_77;
            v38 = sde_reg_read((__int64)v8, v37) & 0xFFF9FFFF;
            if ( (v41 & 1) != 0 )
              v39 = 393216;
            else
              v39 = 0;
            v40 = "SSPP_VIG_OP_MODE + idx";
          }
          else
          {
            if ( (*(_QWORD *)(v34 + 32) & 0x20) == 0 )
            {
LABEL_77:
              sde_reg_write((__int64)v8, v10 + v13, v21 | v35, "format_off + idx");
              sde_reg_write((__int64)v8, v10 + v12, v44, "unpack_pat_off + idx");
              sde_reg_write((__int64)v8, v10 + v28, v23 | 0x80000000, "op_mode_off + idx");
              return sde_reg_write((__int64)v8, v10 + 312, 0x80000000, "SSPP_UBWC_ERROR_STATUS + idx");
            }
            v36 = *(_QWORD *)(a2 + 32);
            v37 = *(_DWORD *)(*(_QWORD *)(v34 + 48) + 144LL);
            v38 = sde_reg_read((__int64)v8, v37) & 0xFFFFFFFC;
            if ( (v36 & 1) != 0 )
              v39 = 3;
            else
              v39 = 0;
            v40 = "SSPP_VIG_CSC_10_OP_MODE + idx";
          }
          sde_reg_write((__int64)v8, v37, v38 | v39, v40);
          goto LABEL_77;
        }
        if ( (a3 & 1) != 0 )
          v42 = 0x80000000;
        else
          v42 = 0;
        v30 = *(_DWORD *)(v8[5] + 56LL) | v42 | (16 * *(_DWORD *)(v8[5] + 48LL));
      }
    }
    v28 = v45;
    goto LABEL_63;
  }
  return result;
}
