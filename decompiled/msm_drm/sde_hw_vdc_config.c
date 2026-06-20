__int64 __fastcall sde_hw_vdc_config(__int64 result, unsigned __int8 *a2, char a3)
{
  __int64 v5; // x19
  unsigned int v6; // w21
  int v7; // w8
  int v8; // w8
  int v9; // w9
  unsigned int v10; // w22
  __int64 v11; // x23
  unsigned __int16 *v12; // x23
  unsigned __int64 v13; // x24
  int v14; // w8
  int v15; // t1
  int v16; // w9
  unsigned int v17; // w2

  if ( result )
  {
    v5 = result;
    v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 40) + 48LL) + 20LL);
    sde_reg_write(result, v6, *((unsigned __int16 *)a2 + 304) | (*((_DWORD *)a2 + 153) << 16), "ENC_OUT_BF_CTRL + idx");
    sde_reg_write(
      v5,
      v6 + 28,
      *((unsigned __int16 *)a2 + 310) | (*((_DWORD *)a2 + 156) << 16),
      "ENC_R2B_BUF_CTRL + idx");
    sde_reg_write(v5, v6 + 64, *((_DWORD *)a2 + 154), "ENC_ORIG_SLICE + idx");
    if ( (a3 & 1) != 0 )
      v7 = 512;
    else
      v7 = 0;
    sde_reg_write(v5, v6 + 68, ((v7 | (a2[402] << 12)) - 4096) | *((_DWORD *)a2 + 144), "ENC_DF_CTRL + idx");
    sde_reg_write(v5, v6 + 128, (*a2 << 24) | (a2[1] << 16) | (*((_DWORD *)a2 + 161) << 8), "ENC_VDC_VERSION + idx");
    sde_reg_write(v5, v6 + 132, *((_DWORD *)a2 + 121) | (*((_DWORD *)a2 + 120) << 16), "ENC_VDC_FRAME_SIZE + idx");
    sde_reg_write(v5, v6 + 136, *((_DWORD *)a2 + 118) | (*((_DWORD *)a2 + 119) << 16), "ENC_VDC_SLICE_SIZE + idx");
    sde_reg_write(v5, v6 + 140, *((_DWORD *)a2 + 157), "ENC_VDC_SLICE_PX + idx");
    v8 = a2[403];
    if ( v8 == 10 )
      v9 = 16;
    else
      v9 = 32;
    if ( v8 == 8 )
      v9 = 0;
    sde_reg_write(
      v5,
      v6 + 144,
      a2[3] | (4 * a2[2]) | v9 | (*((unsigned __int16 *)a2 + 227) << 16),
      "ENC_VDC_MAIN_CONF + idx");
    sde_reg_write(v5, v6 + 148, *((unsigned __int16 *)a2 + 206), "ENC_VDC_CHUNK_SIZE + idx");
    sde_reg_write(v5, v6 + 152, *((unsigned __int16 *)a2 + 215), "ENC_VDC_RC_CONFIG_0 + idx");
    sde_reg_write(
      v5,
      v6 + 156,
      (*((unsigned __int16 *)a2 + 216) << 16)
    | (*((unsigned __int16 *)a2 + 211) << 24)
    | *((unsigned __int16 *)a2 + 218),
      "ENC_VDC_RC_CONFIG_1 + idx");
    sde_reg_write(v5, v6 + 160, *((_DWORD *)a2 + 158), "ENC_VDC_RC_CONFIG_2 + idx");
    sde_reg_write(
      v5,
      v6 + 164,
      (*((unsigned __int16 *)a2 + 224) << 16)
    | (*((unsigned __int16 *)a2 + 221) << 24)
    | *((unsigned __int16 *)a2 + 225),
      "ENC_VDC_RC_CONFIG_3 + idx");
    sde_reg_write(v5, v6 + 168, (*((_DWORD *)a2 + 159) << 8) | 2, "ENC_VDC_RC_CONFIG_4 + idx");
    sde_reg_write(v5, v6 + 172, bswap32(*(_DWORD *)(a2 + 10)), "ENC_VDC_FLAT_CONFIG + idx");
    sde_reg_write(
      v5,
      v6 + 176,
      (*((unsigned __int16 *)a2 + 10) << 16)
    | (*((unsigned __int16 *)a2 + 9) << 24)
    | (*((unsigned __int16 *)a2 + 11) << 8)
    | *((unsigned __int16 *)a2 + 12),
      "ENC_VDC_FLAT_LUT_3_0 + idx");
    sde_reg_write(
      v5,
      v6 + 180,
      (*((unsigned __int16 *)a2 + 14) << 16)
    | (*((unsigned __int16 *)a2 + 13) << 24)
    | (*((unsigned __int16 *)a2 + 15) << 8)
    | *((unsigned __int16 *)a2 + 16),
      "ENC_VDC_FLAT_LUT_7_4 + idx");
    sde_reg_write(
      v5,
      v6 + 184,
      (*((unsigned __int16 *)a2 + 18) << 16)
    | (*((unsigned __int16 *)a2 + 17) << 24)
    | (*((unsigned __int16 *)a2 + 19) << 8)
    | *((unsigned __int16 *)a2 + 20),
      "ENC_VDC_MAX_QP_LUT_3_0 + idx");
    sde_reg_write(
      v5,
      v6 + 188,
      (*((unsigned __int16 *)a2 + 22) << 16)
    | (*((unsigned __int16 *)a2 + 21) << 24)
    | (*((unsigned __int16 *)a2 + 23) << 8)
    | *((unsigned __int16 *)a2 + 24),
      "ENC_VDC_MAX_QP_LUT_7_4 + idx");
    sde_reg_write(
      v5,
      v6 + 192,
      (*((unsigned __int16 *)a2 + 26) << 16)
    | (*((unsigned __int16 *)a2 + 25) << 24)
    | (*((unsigned __int16 *)a2 + 27) << 8)
    | *((unsigned __int16 *)a2 + 28),
      "ENC_VDC_TAR_RATE_LUT_3_0 + idx");
    sde_reg_write(
      v5,
      v6 + 196,
      (*((unsigned __int16 *)a2 + 30) << 16)
    | (*((unsigned __int16 *)a2 + 29) << 24)
    | (*((unsigned __int16 *)a2 + 31) << 8)
    | *((unsigned __int16 *)a2 + 32),
      "ENC_VDC_TAR_RATE_LUT_7_4 + idx");
    sde_reg_write(
      v5,
      v6 + 200,
      (*((unsigned __int16 *)a2 + 34) << 16)
    | (*((unsigned __int16 *)a2 + 33) << 24)
    | (*((unsigned __int16 *)a2 + 35) << 8)
    | *((unsigned __int16 *)a2 + 36),
      "ENC_VDC_TAR_RATE_LUT_11_8 + idx");
    sde_reg_write(
      v5,
      v6 + 204,
      (*((unsigned __int16 *)a2 + 38) << 16)
    | (*((unsigned __int16 *)a2 + 37) << 24)
    | (*((unsigned __int16 *)a2 + 39) << 8)
    | *((unsigned __int16 *)a2 + 40),
      "ENC_VDC_TAR_RATE_LUT_15_12 + idx");
    sde_reg_write(
      v5,
      v6 + 208,
      (a2[5] << 16) | (a2[4] << 20) | (a2[6] << 12) | (a2[7] << 8) | (16 * a2[8]) | a2[9],
      "ENC_VDC_MPPF_CONFIG + idx");
    sde_reg_write(v5, v6 + 212, 0x80u, "ENC_VDC_SSM_CONFIG + idx");
    v10 = *((_DWORD *)a2 + 162);
    sde_reg_write(v5, v6 + 216, a2[652], "ENC_VDC_SLICE_NUM_BITS_0 + idx");
    sde_reg_write(v5, v6 + 220, v10, "ENC_VDC_SLICE_NUM_BITS_1 + idx");
    sde_reg_write(
      v5,
      v6 + 224,
      *((unsigned __int16 *)a2 + 230) | (*((unsigned __int16 *)a2 + 212) << 16),
      "ENC_VDC_RC_PRECOMPUTE + idx");
    v11 = 0;
    do
    {
      sde_reg_write(
        v5,
        v6 + 256 + v11,
        *(unsigned __int16 *)&a2[v11 + 148] | (*(unsigned __int16 *)&a2[v11 + 146] << 16),
        "ENC_VDC_LBDA_BRATE_LUT + idx + (addr_off * 4)");
      v11 += 4;
    }
    while ( (_DWORD)v11 != 128 );
    v12 = (unsigned __int16 *)(a2 + 280);
    v13 = -4;
    do
    {
      v14 = (*(v12 - 2) << 16) | (*(v12 - 3) << 24) | (*(v12 - 1) << 8);
      v15 = *v12;
      v12 += 4;
      sde_reg_write(v5, v6 + v13 + 388, v14 | v15, "ENC_VDC_LBDA_BF_LUT + idx + i");
      v13 += 4LL;
    }
    while ( v13 < 0x3C );
    sde_reg_write(
      v5,
      v6 + 448,
      *((unsigned __int16 *)a2 + 223) | (*((unsigned __int16 *)a2 + 234) << 16),
      "ENC_VDC_OTHER_RC + idx");
    if ( a2[403] == 8 )
      v16 = 2049;
    else
      v16 = 1;
    if ( a2[3] == 1 )
      v17 = v16 | 0x500;
    else
      v17 = v16;
    return sde_reg_write(v5, *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 40) + 48LL) + 48LL) + 4, v17, "VDC_CFG + idx");
  }
  return result;
}
