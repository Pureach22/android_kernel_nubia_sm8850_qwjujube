__int64 __fastcall csiphy_qmargin_get(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v3; // w25
  _QWORD *v4; // x24
  _QWORD *v5; // x23
  __int64 v6; // x4
  __int64 v7; // x26
  int v8; // w28
  const char *v9; // x4
  int v10; // w28
  int v11; // w5
  int v12; // w0
  int v13; // w5
  int v14; // w0
  int v15; // w5
  int v16; // w23
  _DWORD *v17; // x26
  int v18; // w23
  int v19; // w23
  int v20; // w23
  int v21; // w23
  int v22; // w5
  int v23; // w23
  int v24; // w5
  int v25; // w23
  int v26; // w5
  int v27; // w23
  int v28; // w5
  int v29; // w23
  int v30; // w5
  int v31; // w23
  int v32; // w5
  int v33; // w23
  int v34; // w5
  int v35; // w23
  int v36; // w5
  int v37; // w23
  int v38; // w5
  int v39; // w23
  int v40; // w5
  int v41; // w23
  _QWORD *v42; // x8
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int16 v45; // [xsp+10h] [xbp-10h]
  __int64 v46; // [xsp+18h] [xbp-8h]

  v2 = 0;
  v3 = 0;
  v4 = &unk_3C44D0;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  *(_QWORD *)s = 0;
  do
  {
    if ( strstr(&csiphy_qmargin, "default") )
    {
      v5 = (_QWORD *)*v4;
      if ( *v4 )
      {
        v6 = v5[14];
        v7 = a1 + (int)v3;
        if ( v6 )
        {
          v8 = scnprintf(a1 + (int)v3, 4096, "PHY%d_BW: 0x%llx\n", v2, v6);
          if ( *((_BYTE *)v5 + 13) )
            v9 = "Y";
          else
            v9 = "N";
          v10 = scnprintf(v7 + v8, 4096LL - v8, "PHY%d_EPD_ENABLED: %s\n", (unsigned int)v2, v9) + v8;
          v11 = *((_DWORD *)v5 + 4);
          if ( !v11 )
            goto LABEL_16;
LABEL_13:
          v12 = scnprintf(
                  v7 + v10,
                  4096LL - v10,
                  "PHY%d_CDR_%d, ADDR: 0x%x, DEFAULT: 0x%x\n",
                  v2,
                  0,
                  v11,
                  *((_DWORD *)v5 + 5));
          v13 = *((_DWORD *)v5 + 8);
          v10 += v12;
          if ( v13 )
          {
            v14 = scnprintf(
                    v7 + v10,
                    4096LL - v10,
                    "PHY%d_CDR_%d, ADDR: 0x%x, DEFAULT: 0x%x\n",
                    v2,
                    1,
                    v13,
                    *((_DWORD *)v5 + 9));
            v15 = *((_DWORD *)v5 + 12);
            v10 += v14;
            if ( v15 )
            {
              v16 = scnprintf(
                      v7 + v10,
                      4096LL - v10,
                      "PHY%d_CDR_%d, ADDR: 0x%x, DEFAULT: 0x%x\n",
                      v2,
                      2,
                      v15,
                      *((_DWORD *)v5 + 13))
                  + v10;
              v10 = scnprintf(v7 + v16, 4096LL - v16, "\n") + v16;
            }
          }
          goto LABEL_16;
        }
        v10 = 0;
        v11 = *((_DWORD *)v5 + 4);
        if ( v11 )
          goto LABEL_13;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "csiphy_qmargin_get_defaults",
          205,
          "Invalid PHY idx: %u",
          v2);
        v10 = 0;
      }
LABEL_16:
      v3 += v10;
    }
    snprintf(s, 0xAu, "%d", v2);
    if ( strstr(&csiphy_qmargin, s) )
    {
      v17 = (_DWORD *)*v4;
      if ( *v4 )
      {
        v18 = scnprintf(a1 + (int)v3, 4096LL - (int)v3, "PHY%d_CSI2_RX: 0x%x\n", v2, *v17) + v3;
        v19 = scnprintf(a1 + v18, 4096LL - v18, "PHY%d_CSI2_CRC: 0x%x\n", v2, v17[1]) + v18;
        v20 = scnprintf(a1 + v19, 4096LL - v19, "PHY%d_CSI2_PKT: 0x%x\n", v2, v17[2]) + v19;
        v21 = scnprintf(a1 + v20, 4096LL - v20, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 0, v17[16]) + v20;
        v22 = v17[17];
        v17[16] = 0;
        v23 = scnprintf(a1 + v21, 4096LL - v21, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 1, v22) + v21;
        v24 = v17[18];
        v17[17] = 0;
        v25 = scnprintf(a1 + v23, 4096LL - v23, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 2, v24) + v23;
        v26 = v17[19];
        v17[18] = 0;
        v27 = scnprintf(a1 + v25, 4096LL - v25, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 3, v26) + v25;
        v28 = v17[20];
        v17[19] = 0;
        v29 = scnprintf(a1 + v27, 4096LL - v27, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 4, v28) + v27;
        v30 = v17[21];
        v17[20] = 0;
        v31 = scnprintf(a1 + v29, 4096LL - v29, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 5, v30) + v29;
        v32 = v17[22];
        v17[21] = 0;
        v33 = scnprintf(a1 + v31, 4096LL - v31, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 6, v32) + v31;
        v34 = v17[23];
        v17[22] = 0;
        v35 = scnprintf(a1 + v33, 4096LL - v33, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 7, v34) + v33;
        v36 = v17[24];
        v17[23] = 0;
        v37 = scnprintf(a1 + v35, 4096LL - v35, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 8, v36) + v35;
        v38 = v17[25];
        v17[24] = 0;
        v39 = scnprintf(a1 + v37, 4096LL - v37, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 9, v38) + v37;
        v40 = v17[26];
        v17[25] = 0;
        v41 = scnprintf(a1 + v39, 4096LL - v39, "PHY%d_COMMON_STATUS%u: 0x%x\n", v2, 10, v40) + v39;
        v17[26] = 0;
        v3 = scnprintf(a1 + v41, 4096LL - v41, "\n") + v41;
      }
    }
    v42 = (_QWORD *)*v4;
    if ( *v4 )
    {
      v42[13] = 0;
      v42[14] = 0;
      v42[11] = 0;
      v42[12] = 0;
      v42[9] = 0;
      v42[10] = 0;
      v42[7] = 0;
      v42[8] = 0;
      v42[5] = 0;
      v42[6] = 0;
      v42[3] = 0;
      v42[4] = 0;
      v42[1] = 0;
      v42[2] = 0;
      *v42 = 0;
    }
    ++v2;
    v4 += 7;
  }
  while ( v2 != 8 );
  csiphy_qmargin = 0;
  _ReadStatusReg(SP_EL0);
  return v3;
}
