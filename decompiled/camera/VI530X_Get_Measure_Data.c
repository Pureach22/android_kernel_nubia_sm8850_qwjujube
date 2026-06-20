__int64 __fastcall VI530X_Get_Measure_Data(__int64 a1)
{
  int v2; // w9
  unsigned int v3; // w8
  int v4; // w12
  unsigned int v5; // w10
  unsigned int v6; // w11
  unsigned __int64 v7; // x6
  unsigned int v8; // w5
  __int16 v9; // w13
  unsigned int v10; // w4
  __int16 *v11; // x14
  __int16 *v12; // x16
  unsigned int v13; // w17
  unsigned int v14; // w17
  unsigned int v15; // w17
  unsigned int v16; // w0
  __int64 v17; // x1
  __int16 v18; // w7
  __int64 v19; // x2
  int v20; // w2
  int v21; // w16
  int v22; // w14
  _DWORD *v23; // x17
  unsigned __int64 v24; // x16
  _DWORD *v25; // x15
  signed __int64 v26; // x14
  __int64 v27; // x0
  int v28; // w1
  __int64 v29; // x2
  __int64 v30; // x3
  int v31; // w21
  int v32; // w0
  int v33; // w15
  __int64 v34; // x16
  int v35; // w17
  int v36; // w1
  __int64 v37; // x16
  __int64 v38; // x17
  __int64 v39; // x16
  __int64 v40; // x15
  __int64 v41; // x16
  signed __int64 v42; // x17
  __int64 v43; // x14
  __int64 v44; // x15
  __int64 v45; // x17
  unsigned __int64 v46; // x16
  unsigned __int64 v47; // x15
  unsigned __int64 v48; // x16
  __int64 v49; // x17
  unsigned int v50; // w9
  int v51; // w15
  unsigned int v52; // w17
  __int64 result; // x0
  __int16 v54; // w13
  unsigned int v55; // w15
  bool v56; // cf
  char v60; // w3
  bool v61; // cc
  char v62; // w11
  int v63; // w9
  char v65; // w8
  int v66; // w14
  __int64 v67; // [xsp+8h] [xbp-28h] BYREF
  __int64 v68; // [xsp+10h] [xbp-20h]
  __int64 v69; // [xsp+18h] [xbp-18h]
  __int64 v70; // [xsp+20h] [xbp-10h]
  __int64 v71; // [xsp+28h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  if ( (unsigned int)vi530x_read_multibytes(a1, 12, &v67, 32) )
  {
    printk(&unk_4424DD);
    result = 4294967288LL;
    goto LABEL_76;
  }
  v2 = (char)(*(_BYTE *)(a1 + 46) + BYTE6(v67));
  v3 = (unsigned __int8)v67;
  v4 = SWORD2(v68);
  v5 = v2 + 2;
  v6 = HIDWORD(v70);
  v7 = ((unsigned __int8)v70 << 16) | (HIBYTE(v69) << 8) | (unsigned int)BYTE6(v69);
  v8 = (BYTE3(v70) << 16) | (BYTE2(v70) << 8) | BYTE1(v70);
  if ( v2 + 2 < BYTE1(v69) || HIDWORD(v70) >= 3000 * (unsigned int)*(unsigned __int8 *)(a1 + 256) )
  {
    v9 = WORD2(v68);
    v10 = HIDWORD(v70);
    v6 = v68;
  }
  else
  {
    v9 = *(_WORD *)((char *)&v67 + 1);
    v10 = v68;
    v3 = BYTE1(v69);
  }
  v11 = (__int16 *)&unk_457430;
  if ( v8 > 0x1F40 )
    v11 = (__int16 *)&unk_457448;
  v12 = (__int16 *)&unk_457454;
  if ( v8 <= 0x1F40 )
    v12 = (__int16 *)&unk_45743C;
  if ( !(_DWORD)v7 )
  {
    v18 = 0;
    goto LABEL_25;
  }
  v13 = (v8 >> 3) * *(unsigned __int8 *)(a1 + 256);
  v56 = v10 >= v13;
  v14 = v10 - v13;
  if ( v14 == 0 || !v56 )
  {
    v15 = 0;
    v17 = 0;
    if ( v8 <= 0x1F40 )
      v16 = 500;
    else
      v16 = 160;
    goto LABEL_22;
  }
  v15 = 16 * v14 / (unsigned int)v7;
  if ( v8 <= 0x1F40 )
    v16 = 500;
  else
    v16 = 160;
  if ( v15 < v16 )
  {
    v17 = 0;
LABEL_22:
    v19 = 1;
    goto LABEL_23;
  }
  if ( v8 <= 0x1F40 )
    v16 = 800;
  else
    v16 = 350;
  if ( v15 >= v16 )
  {
    if ( v8 <= 0x1F40 )
      v16 = 1128;
    else
      v16 = 700;
    if ( v15 >= v16 )
    {
      if ( v8 <= 0x1F40 )
        v16 = 1734;
      else
        v16 = 1200;
      if ( v15 >= v16 )
      {
        if ( v15 >= 0x7D0 )
        {
          if ( v8 <= 0x1F40 )
            v66 = 10;
          else
            v66 = 30;
          v22 = (int)((v15 - v16) * v66) / (int)(2000 - v16);
          if ( v8 <= 0x1F40 )
            LOWORD(v21) = 25;
          else
            LOWORD(v21) = 40;
          goto LABEL_24;
        }
        v19 = 5;
        v17 = 4;
        v16 = 2000;
      }
      else
      {
        v19 = 4;
        v17 = 3;
      }
    }
    else
    {
      v19 = 3;
      v17 = 2;
    }
  }
  else
  {
    v19 = 2;
    v17 = 1;
  }
LABEL_23:
  v20 = v12[v19];
  v21 = v12[v17];
  v22 = (int)((v15 - v11[v17]) * (v20 - v21)) / (int)(v16 - v11[v17]);
LABEL_24:
  v18 = v22 + v21;
LABEL_25:
  v23 = &unk_4574BC;
  v24 = ((unsigned __int64)((BYTE3(v70) << 16) | (BYTE2(v70) << 8) | (unsigned int)BYTE1(v70)) << 17) / v7;
  v25 = &unk_4575D0;
  if ( v8 <= 0x1F40 )
    v25 = &unk_457518;
  else
    v23 = &unk_457574;
  v26 = 102400 * (unsigned __int64)v10 / v7;
  if ( v24 > 0x1F )
  {
    if ( v24 > 0x13957 )
    {
      v44 = 81000;
      if ( v8 <= 0x1F40 )
        v44 = 201000;
      v45 = 212100;
      v46 = v24 - 56032;
      if ( v8 > 0x1F40 )
        v45 = 182100;
      v47 = (v46 * v44 * (unsigned __int128)0x2B5BB67E849D832DuLL) >> 64;
      v48 = (v46 * v45 * (unsigned __int128)0x2B5BB67E849D832DuLL) >> 64;
      v49 = 479600;
      if ( v8 > 0x1F40 )
        v49 = 489600;
      v40 = v49 + (v47 >> 12);
      v41 = (v48 >> 12) + 505000;
      v42 = v26 - v40;
      if ( v26 < v40 )
        goto LABEL_33;
      goto LABEL_42;
    }
    if ( v24 >= 0x72 )
    {
      if ( v24 >= 0xAF )
      {
        if ( v24 >= 0x139 )
        {
          if ( v24 >= 0x1E2 )
          {
            if ( v24 >= 0x21B )
            {
              if ( v24 >= 0x291 )
              {
                if ( v24 >= 0x5C0 )
                {
                  if ( v24 >= 0x975 )
                  {
                    if ( v24 >= 0xC97 )
                    {
                      v28 = 6777;
                      if ( v24 >= 0x1A79 )
                      {
                        v28 = 7217;
                        if ( v24 >= 0x1C31 )
                        {
                          v28 = 12326;
                          if ( v24 >= 0x3026 )
                          {
                            v28 = 14946;
                            if ( v24 >= 0x3A62 )
                            {
                              v28 = 20906;
                              if ( v24 >= 0x51AA )
                              {
                                if ( v24 >> 3 >= 0xCAF )
                                {
                                  v28 = 32287;
                                  if ( v24 >= 0x7E1F )
                                  {
                                    v28 = 41121;
                                    if ( v24 >= 0xA0A1 )
                                    {
                                      v28 = 44258;
                                      if ( v24 >= 0xACE2 )
                                      {
                                        v28 = 51439;
                                        if ( v24 >= 0xC8EF )
                                        {
                                          if ( v24 >> 5 >= 0x6D7 )
                                          {
                                            v27 = 21;
                                            v29 = 22;
                                            v28 = 80216;
                                          }
                                          else
                                          {
                                            v28 = 56032;
                                            v27 = 20;
                                            v29 = 21;
                                          }
                                        }
                                        else
                                        {
                                          v27 = 19;
                                          v29 = 20;
                                        }
                                      }
                                      else
                                      {
                                        v27 = 18;
                                        v29 = 19;
                                      }
                                    }
                                    else
                                    {
                                      v27 = 17;
                                      v29 = 18;
                                    }
                                  }
                                  else
                                  {
                                    v27 = 16;
                                    v29 = 17;
                                  }
                                }
                                else
                                {
                                  v28 = 25976;
                                  v27 = 15;
                                  v29 = 16;
                                }
                              }
                              else
                              {
                                v27 = 14;
                                v29 = 15;
                              }
                            }
                            else
                            {
                              v27 = 13;
                              v29 = 14;
                            }
                          }
                          else
                          {
                            v27 = 12;
                            v29 = 13;
                          }
                        }
                        else
                        {
                          v27 = 11;
                          v29 = 12;
                        }
                      }
                      else
                      {
                        v27 = 10;
                        v29 = 11;
                      }
                    }
                    else
                    {
                      v28 = 3223;
                      v27 = 9;
                      v29 = 10;
                    }
                  }
                  else
                  {
                    v28 = 2421;
                    v27 = 8;
                    v29 = 9;
                  }
                }
                else
                {
                  v28 = 1472;
                  v27 = 7;
                  v29 = 8;
                }
              }
              else
              {
                v28 = 657;
                v27 = 6;
                v29 = 7;
              }
            }
            else
            {
              v28 = 539;
              v27 = 5;
              v29 = 6;
            }
          }
          else
          {
            v28 = 482;
            v27 = 4;
            v29 = 5;
          }
        }
        else
        {
          v28 = 313;
          v27 = 3;
          v29 = 4;
        }
      }
      else
      {
        v28 = 175;
        v27 = 2;
        v29 = 3;
      }
    }
    else
    {
      v28 = 114;
      v27 = 1;
      v29 = 2;
    }
  }
  else
  {
    v27 = 0;
    v28 = 32;
    v29 = 1;
  }
  v30 = dword_457460[v27];
  v31 = v23[v27];
  v32 = v25[v27];
  v33 = v25[v29];
  v34 = v24 - v30;
  v35 = v23[v29] - v31;
  v36 = v28 - v30;
  if ( v34 < 0 )
    v34 = -v34;
  v37 = 100 * v34;
  v38 = v37 * v35 / v36;
  v39 = v37 * (v33 - v32) / v36;
  v40 = v38 + 100LL * v31;
  v41 = v39 + 100LL * v32;
  v42 = v26 - v40;
  if ( v26 < v40 )
  {
LABEL_33:
    LOBYTE(v43) = 0;
    goto LABEL_47;
  }
LABEL_42:
  if ( v26 <= v41 )
    v43 = 100 * v42 / (v41 - v40);
  else
    LOBYTE(v43) = 100;
LABEL_47:
  v50 = v2 - 2;
  v51 = v8 * *(unsigned __int8 *)(a1 + 256);
  v52 = BYTE3(v67);
  result = 0;
  *(_DWORD *)(a1 + 20) = v10;
  *(_DWORD *)(a1 + 24) = v8;
  *(_DWORD *)(a1 + 28) = v7;
  v54 = v9 + v18 - *(_WORD *)(a1 + 236);
  v55 = 100 * v51 / v10;
  *(_WORD *)(a1 + 16) = v54;
  v56 = v8 <= 0x15F90 || v55 >= 0x352;
  if ( (v56 || v52 >= 0x33) && v54 >= 0 && v4 <= 3500 )
    v60 = v43;
  else
    v60 = 0;
  v61 = v54 > 299 && v6 > 0x2710;
  *(_BYTE *)(a1 + 18) = v60;
  v62 = v61;
  v56 = v3 >= v50;
  v63 = *(_DWORD *)(a1 + 228);
  if ( !v56 || v3 > v5 )
    v65 = 0;
  else
    v65 = v62;
  *(_BYTE *)(a1 + 32) = v65;
  if ( v63 )
  {
    printk(&unk_40FC44);
    result = 0;
  }
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
