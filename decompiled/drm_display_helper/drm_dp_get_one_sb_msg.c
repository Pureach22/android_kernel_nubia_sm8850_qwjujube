__int64 __fastcall drm_dp_get_one_sb_msg(__int64 a1, char a2, __int64 *a3)
{
  __int64 v3; // x8
  __int64 v7; // x22
  unsigned int v8; // w21
  int v9; // w8
  _QWORD *v10; // x0
  int v11; // w20
  unsigned __int64 v12; // x9
  int v13; // w11
  unsigned __int8 v14; // w10
  __int64 v15; // x22
  int v16; // w16
  int v17; // w0
  int v18; // w1
  unsigned int v19; // w2
  unsigned int v20; // w2
  char v22; // w10
  char v23; // w10
  char v24; // w10
  int v25; // w5
  unsigned __int8 v26; // w9
  unsigned int v27; // w25
  unsigned int v28; // w26
  __int64 v29; // x8
  __int64 v30; // x1
  __int64 v31; // x8
  __int64 v32; // x1
  int v33; // w8
  __int64 v34; // x8
  __int64 v35; // x1
  __int64 result; // x0
  unsigned __int8 *v37; // x8
  unsigned int v38; // w9
  unsigned int v39; // w28
  unsigned int v40; // w27
  __int64 mst_branch_device; // x0
  unsigned int v42; // w8
  char v43; // w9
  __int64 v44; // x11
  __int64 v45; // x2
  int v46; // w24
  int v47; // w8
  unsigned int v48; // w23
  __int64 v49; // x8
  __int64 v50; // x1
  __int64 v51; // x8
  __int64 v52; // x1
  __int64 v53; // x8
  __int64 v54; // x1
  __int64 v55; // [xsp+8h] [xbp-38h] BYREF
  __int64 v56; // [xsp+10h] [xbp-30h]
  _QWORD v57[5]; // [xsp+18h] [xbp-28h] BYREF

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v7 = 144;
  else
    v7 = 470;
  if ( (a2 & 1) != 0 )
    v8 = 5632;
  else
    v8 = 5120;
  v57[4] = v3;
  if ( (a2 & 1) == 0 )
    *a3 = 0;
  v9 = *(_DWORD *)(a1 + 120);
  v10 = *(_QWORD **)(a1 + 128);
  memset(v57, 0, 32);
  if ( v9 >= 16 )
    v11 = 16;
  else
    v11 = v9;
  v55 = 0;
  v56 = 0;
  if ( v11 != (unsigned int)drm_dp_dpcd_read(v10, v8, (__int64)v57, v11) )
  {
    v29 = *(_QWORD *)(a1 + 104);
    if ( v29 )
      v30 = *(_QWORD *)(v29 + 8);
    else
      v30 = 0;
    _drm_dev_dbg(0, v30, 2, "failed to read DPCD down rep %d %d\n", (unsigned int)v11);
    goto LABEL_51;
  }
  if ( !LOBYTE(v57[0]) )
    goto LABEL_47;
  v12 = ((unsigned __int64)LOBYTE(v57[0]) >> 5) + 3;
  if ( v11 < (int)v12 )
    goto LABEL_47;
  v13 = 0;
  v14 = 0;
  v15 = a1 + v7;
  v16 = -20 - ((LOBYTE(v57[0]) >> 2) & 0x38);
  v17 = 7;
  LOBYTE(v18) = 0x80;
  do
  {
    if ( v14 > 0x1Fu )
      __break(1u);
    v19 = (unsigned __int8)(v18 & *((_BYTE *)v57 + v14));
    v18 = (unsigned __int8)v18 >> 1;
    v20 = v19 >> v17--;
    if ( !v18 )
    {
      ++v14;
      LOBYTE(v18) = 0x80;
      v17 = 7;
    }
    v13 = v20 | (2 * v13);
    if ( (v13 & 0x10) != 0 )
      v13 ^= 0x13u;
  }
  while ( !__CFADD__(v16++, 1) );
  v22 = 2 * v13;
  if ( (v13 & 8) != 0 )
    v22 = (2 * v13) ^ 0x13;
  if ( (v22 & 8) != 0 )
    v23 = (2 * v22) ^ 0x13;
  else
    v23 = 2 * v22;
  if ( (v23 & 8) != 0 )
    v24 = (2 * v23) ^ 0x13;
  else
    v24 = 2 * v23;
  v25 = *((unsigned __int8 *)v57 + v12 - 1);
  if ( (v24 & 8) != 0 )
    v26 = (2 * v24) ^ 0x13;
  else
    v26 = 2 * v24;
  if ( (v26 & 0xF) != (v25 & 0xF) )
  {
    v31 = *(_QWORD *)(a1 + 104);
    if ( v31 )
      v32 = *(_QWORD *)(v31 + 8);
    else
      v32 = 0;
    _drm_dev_dbg(0, v32, 2, "crc4 mismatch 0x%x 0x%x\n", v26, v25);
LABEL_47:
    print_hex_dump(&unk_1C719, "failed hdr", 0, 16, 1, v57, v11, 0);
    v34 = *(_QWORD *)(a1 + 104);
    if ( v34 )
      v35 = *(_QWORD *)(v34 + 8);
    else
      v35 = 0;
    _drm_dev_dbg(0, v35, 2, "ERROR: failed header\n");
    goto LABEL_51;
  }
  v27 = LOBYTE(v57[0]) >> 4;
  BYTE1(v55) = v57[0] & 0xF;
  LOBYTE(v55) = LOBYTE(v57[0]) >> 4;
  if ( LOBYTE(v57[0]) >= 0x20u )
  {
    v33 = LOBYTE(v57[0]) >> 5;
    BYTE2(v55) = BYTE1(v57[0]);
    if ( v33 == 1 )
    {
      v28 = 2;
    }
    else
    {
      BYTE3(v55) = BYTE2(v57[0]);
      if ( v33 == 2 )
      {
        v28 = 3;
      }
      else
      {
        BYTE4(v55) = BYTE3(v57[0]);
        if ( v33 == 3 )
        {
          v28 = 4;
        }
        else
        {
          BYTE5(v55) = BYTE4(v57[0]);
          if ( v33 == 4 )
          {
            v28 = 5;
          }
          else
          {
            BYTE6(v55) = BYTE5(v57[0]);
            if ( v33 == 5 )
            {
              v28 = 6;
            }
            else
            {
              HIBYTE(v55) = BYTE6(v57[0]);
              if ( v33 == 6 )
              {
                v28 = 7;
              }
              else
              {
                v28 = 8;
                LOBYTE(v56) = HIBYTE(v57[0]);
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v28 = 1;
  }
  v37 = (unsigned __int8 *)v57 + v28;
  v38 = *v37;
  v39 = v37[1];
  v40 = v38 & 0x3F;
  BYTE4(v56) = v38 & 0x3F;
  BYTE2(v56) = v38 >> 7;
  BYTE3(v56) = (v38 & 0x40) != 0;
  BYTE5(v56) = v39 >> 7;
  BYTE6(v56) = (v39 & 0x40) != 0;
  HIBYTE(v56) = (v39 & 0x10) != 0;
  if ( (a2 & 1) == 0 )
  {
    mst_branch_device = drm_dp_get_mst_branch_device(a1, v27, (char *)&v55 + 2);
    *a3 = mst_branch_device;
    if ( !mst_branch_device )
    {
      v51 = *(_QWORD *)(a1 + 104);
      if ( v51 )
        v52 = *(_QWORD *)(v51 + 8);
      else
        v52 = 0;
      _drm_dev_dbg(0, v52, 2, "Got MST reply from unknown device %d\n", v27);
      goto LABEL_51;
    }
  }
  v42 = v28 + 2;
  if ( (v39 & 0x80) == 0 )
  {
    if ( *(_BYTE *)(v15 + 308) == 1 )
    {
      *(_BYTE *)(v15 + 305) = 0;
      *(_BYTE *)(v15 + 304) = v40;
      *(_BYTE *)(v15 + 306) = v42;
      goto LABEL_71;
    }
LABEL_85:
    v49 = *(_QWORD *)(a1 + 104);
    if ( v49 )
      v50 = *(_QWORD *)(v49 + 8);
    else
      v50 = 0;
    _drm_dev_dbg(0, v50, 2, "sideband msg set header failed %d\n", LOBYTE(v57[0]));
    goto LABEL_51;
  }
  v43 = *(_BYTE *)(v15 + 308);
  *(_BYTE *)(v15 + 305) = 0;
  *(_BYTE *)(v15 + 304) = v40;
  *(_BYTE *)(v15 + 306) = v42;
  if ( (v43 & 1) != 0 )
    goto LABEL_85;
  v44 = v56;
  *(_QWORD *)(v15 + 310) = v55;
  *(_QWORD *)(v15 + 318) = v44;
  *(_BYTE *)(v15 + 308) = 1;
LABEL_71:
  if ( (v39 & 0x40) != 0 )
    *(_BYTE *)(v15 + 309) = 1;
  if ( v40 >= (unsigned __int8)(v11 - v42) )
    v45 = (unsigned __int8)(v11 - v42);
  else
    v45 = v40;
  drm_dp_sideband_append_payload(v15, (char *)v57 + v42, v45);
  v46 = *(unsigned __int8 *)(v15 + 306) - v11 + *(unsigned __int8 *)(v15 + 304);
  if ( v46 < 1 )
  {
    result = 1;
    goto LABEL_52;
  }
  while ( 1 )
  {
    v47 = *(_DWORD *)(a1 + 120);
    if ( v47 >= v46 )
      v47 = v46;
    v48 = v47 >= 16 ? 16 : v47;
    if ( v48 != (unsigned int)drm_dp_dpcd_read(*(_QWORD **)(a1 + 128), v11 + v8, (__int64)v57, (int)v48) )
      break;
    drm_dp_sideband_append_payload(v15, v57, v48);
    v46 -= v48;
    v11 += v48;
    result = 1;
    if ( v46 <= 0 )
      goto LABEL_52;
  }
  v53 = *(_QWORD *)(a1 + 104);
  if ( v53 )
    v54 = *(_QWORD *)(v53 + 8);
  else
    v54 = 0;
  _drm_dev_dbg(0, v54, 2, "failed to read a chunk (len %d, ret %d)\n", v48);
LABEL_51:
  result = 0;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
