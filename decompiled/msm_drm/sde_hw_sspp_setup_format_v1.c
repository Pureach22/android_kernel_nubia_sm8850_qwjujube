__int64 __fastcall sde_hw_sspp_setup_format_v1(_QWORD *a1, __int64 a2, char a3, unsigned int a4, unsigned int a5)
{
  __int64 result; // x0
  unsigned int v11; // w10
  int v12; // w8
  int v13; // w0
  int v14; // w10
  int v15; // w11
  unsigned int v16; // w20
  unsigned int v17; // w14
  unsigned int v18; // w25
  int v19; // w10
  bool v20; // zf
  int v21; // w10
  int v22; // w11
  int v23; // w10
  unsigned int v24; // w9
  int v25; // w8
  int v26; // w24
  unsigned int v27; // w1
  unsigned int v28; // w10
  int v29; // w9
  int v30; // w8
  unsigned int v31; // w10
  unsigned int v32; // w2
  unsigned int v33; // w8
  __int64 v34; // x8
  __int64 v35; // x8
  int v36; // w22
  __int64 v37; // x21
  int v38; // w0
  unsigned int v39; // w1
  int v40; // w8
  const char *v41; // x3
  unsigned int v42; // w2
  __int64 v43; // x21
  int v44; // w10
  int v45; // w8
  int v46; // w10
  unsigned int v47; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v48; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  result = sspp_subblk_offset(a1, 1, &v47);
  if ( a2 && !(_DWORD)result )
  {
    v11 = v47;
    if ( a5 >= 2 )
      v12 = 12288;
    else
      v12 = 4096;
    v47 += v12;
    v13 = sde_reg_read((__int64)a1, v11 + v12 + 8);
    v14 = *(_DWORD *)(a2 + 16);
    if ( (a4 & 8) != 0 )
    {
      if ( v14 == 1 )
      {
        v14 = 2;
      }
      else if ( v14 == 2 )
      {
        v14 = 1;
      }
    }
    v15 = *(_DWORD *)(a2 + 4);
    v16 = *(_DWORD *)(a2 + 8);
    v17 = *(unsigned __int8 *)(a2 + 23);
    v18 = v13 & 0x7FFF1FFE | (((a4 >> 1) & 3) << 13) & 0xFFFF7FFF | ((((unsigned __int8)(a4 & 0x10) >> 4) & 1) << 15);
    v19 = (v14 << 23) | (v15 << 19);
    if ( v15 )
      v20 = 1;
    else
      v20 = *(_BYTE *)(a2 + 24) == 0;
    v21 = v19
        | (*(unsigned __int8 *)(a2 + 15) << 6)
        | (16 * *(unsigned __int8 *)(a2 + 14))
        | (4 * *(unsigned __int8 *)(a2 + 13))
        | *(unsigned __int8 *)(a2 + 12);
    if ( !v20 )
      v21 |= 0x100u;
    v22 = (v17 << 9) - 512;
    v23 = v21
        | (a4 << 17) & 0x400000
        | (*(unsigned __int8 *)(a2 + 21) << 17)
        | ((*(unsigned __int8 *)(a2 + 22) << 12) - 4096)
        | (*(unsigned __int8 *)(a2 + 20) << 18);
    if ( v17 >= 9 )
      v22 = 0;
    v24 = 0x40000000;
    if ( (a4 & 0x10) != 0 )
      v24 = ~(8 * *(_QWORD *)(a1[7] + 32LL)) & 0x40000000;
    v25 = *(_DWORD *)(a2 + 28);
    v26 = v23 | v22;
    if ( !v25 )
    {
LABEL_54:
      v35 = a1[7];
      v36 = ((*(_QWORD *)(a2 + 32) & 1) << 15) | ((unsigned int)*(_QWORD *)(a2 + 32) << 13) & 0x4000;
      if ( (*(_QWORD *)(v35 + 32) & 0x10) != 0 )
      {
        v43 = *(_QWORD *)(a2 + 32);
        if ( (*(_QWORD *)(v35 + 32) & 4) == 0 )
          goto LABEL_69;
        v48 = 0;
        if ( (unsigned int)sspp_subblk_offset(a1, 2, &v48) || (*(_QWORD *)(a1[7] + 32LL) & 0x10) == 0 )
          goto LABEL_69;
        v44 = sde_reg_read((__int64)a1, v48 + 4) & 0xFFF9FFFF;
        if ( (v43 & 1) != 0 )
          v45 = 393216;
        else
          v45 = 0;
        v41 = "SSPP_VIG_OP_MODE + idx";
        v39 = v48 + 4;
        v42 = v44 | v45;
      }
      else
      {
        if ( (*(_QWORD *)(v35 + 32) & 0x20) == 0 )
          goto LABEL_69;
        v37 = *(_QWORD *)(a2 + 32);
        v48 = 0;
        if ( (unsigned int)sspp_subblk_offset(a1, 5, &v48) )
          goto LABEL_69;
        v38 = sde_reg_read((__int64)a1, v48);
        v39 = v48;
        if ( (v37 & 1) != 0 )
          v40 = 3;
        else
          v40 = 0;
        v41 = "SSPP_VIG_CSC_10_OP_MODE + idx";
        v42 = v38 & 0xFFFFFFFC | v40;
      }
      sde_reg_write((__int64)a1, v39, v42, v41);
LABEL_69:
      sde_reg_write((__int64)a1, v47, v26 | v36, "SSPP_REC_SRC_FORMAT + idx");
      sde_reg_write((__int64)a1, v47 + 4, v16, "SSPP_REC_SRC_UNPACK_PATTERN + idx");
      sde_reg_write((__int64)a1, v47 + 8, v18 | 0x80000000, "SSPP_REC_SRC_OP_MODE + idx");
      result = sde_reg_write((__int64)a1, v47 + 208, 0x80000000, "SSPP_REC_UBWC_ERROR_STATUS + idx");
      goto LABEL_70;
    }
    if ( v25 == 2 )
      v18 |= ((unsigned int)*(_QWORD *)(a2 + 32) >> 2) & 1;
    v26 |= v25 << 30;
    v27 = 4240;
    if ( a5 >= 2 )
    {
      if ( (*(_QWORD *)(a1[7] + 32LL) & 0x100000000LL) != 0 )
        v27 = 12432;
      else
        v27 = 4240;
    }
    v28 = *(_DWORD *)(a1[4] + 4LL);
    if ( v28 >> 28 < 5 )
    {
      if ( (v28 & 0x70000000) == 0x40000000 )
      {
        v32 = ~((unsigned int)*(_QWORD *)(a2 + 32) << 30) & 0x40000000;
      }
      else
      {
        v33 = HIWORD(v28);
        if ( HIWORD(v28) == 4096 )
        {
          if ( (a3 & 1) != 0 )
            v46 = -2147483392;
          else
            v46 = 256;
          v32 = v46 & 0xFFFFFFFE | *(_DWORD *)(a1[5] + 56LL) & 1 | (16 * *(_DWORD *)(a1[5] + 48LL));
        }
        else
        {
          if ( v33 == 0x2000 )
          {
            v34 = a1[5];
            if ( (a3 & 1) != 0 )
              v24 = 0x80000000;
            else
              v24 = 0;
          }
          else
          {
            if ( v33 != 12288 )
              goto LABEL_54;
            v34 = a1[5];
          }
          v32 = *(_DWORD *)(v34 + 56) | v24 | (16 * *(_DWORD *)(v34 + 48));
        }
      }
      goto LABEL_53;
    }
    if ( (*(_QWORD *)(a2 + 32) & 1) != 0 )
    {
      v29 = 0;
      if ( v25 == 2 )
        goto LABEL_39;
    }
    else
    {
      if ( (*(_QWORD *)(a2 + 32) & 2) == 0 )
      {
        if ( (*(_QWORD *)(a2 + 32) & 0x10LL) != 0 )
          v29 = 0x40000000;
        else
          v29 = -1073741824;
        if ( v25 != 2 )
          goto LABEL_34;
LABEL_39:
        if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
        {
          if ( (*(_QWORD *)(a2 + 32) & 0x40LL) != 0 )
            v30 = 196608;
          else
            v30 = 0;
          if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
          {
            v31 = ((unsigned int)*(_QWORD *)(a2 + 32) << 11) & 0x10000;
            goto LABEL_52;
          }
        }
        else
        {
          v30 = 0;
        }
LABEL_35:
        v31 = 0;
LABEL_52:
        v32 = v30 | v29 | v31;
LABEL_53:
        sde_reg_write((__int64)a1, v27, v32, "ubwc_ctrl_off");
        goto LABEL_54;
      }
      v29 = 0x40000000;
      if ( v25 == 2 )
        goto LABEL_39;
    }
LABEL_34:
    v30 = 0;
    goto LABEL_35;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
