__int64 __fastcall regdom_intersect(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 v4; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x24
  unsigned int v8; // w23
  unsigned __int64 v9; // x28
  __int64 v10; // x22
  int v11; // w0
  unsigned __int64 v12; // x22
  __int64 v13; // x0
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x24
  unsigned __int64 v16; // x9
  __int64 v17; // x27
  unsigned __int64 v18; // x25
  unsigned __int64 v19; // x1
  __int64 v20; // x9
  int v21; // w8
  __int64 v22; // x16
  __int64 v23; // x2
  __int64 v24; // x17
  bool v25; // cf
  __int64 v26; // x8
  unsigned __int64 v28; // x0
  unsigned __int64 v29; // x0
  unsigned __int64 v30; // x17
  unsigned __int64 v31; // x17
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x9
  __int64 v34; // x10
  __int64 v35; // x11
  __int64 v36; // x9
  __int64 v37; // x9
  __int64 v38; // x9
  __int64 v39; // x9
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned int v42; // w8
  __int64 v43; // x10
  __int64 v44; // x11
  _QWORD *v45; // x9
  __int64 v46; // x12
  __int64 v47; // x11
  __int64 v48; // x10
  __int64 v49; // x10
  __int64 v50; // x10
  int v51; // w8
  int v52; // w9
  __int64 v54; // [xsp+8h] [xbp-68h] BYREF
  __int64 v55; // [xsp+10h] [xbp-60h]
  __int64 v56; // [xsp+18h] [xbp-58h]
  __int64 v57; // [xsp+20h] [xbp-50h]
  __int64 v58; // [xsp+28h] [xbp-48h]
  __int64 v59; // [xsp+30h] [xbp-40h]
  __int64 v60; // [xsp+38h] [xbp-38h]
  __int64 v61; // [xsp+40h] [xbp-30h]
  __int64 v62; // [xsp+48h] [xbp-28h]
  __int64 v63; // [xsp+50h] [xbp-20h]
  __int64 v64; // [xsp+58h] [xbp-18h]
  __int64 v65; // [xsp+60h] [xbp-10h]
  __int64 v66; // [xsp+68h] [xbp-8h]

  v2 = 0;
  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = *(unsigned int *)(a1 + 16);
    if ( !(_DWORD)v4 )
      goto LABEL_74;
    LODWORD(v6) = *(_DWORD *)(a2 + 16);
    v7 = 0;
    v8 = 0;
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v60 = 0;
    v61 = 0;
    v58 = 0;
    v59 = 0;
    v56 = 0;
    v57 = 0;
    v54 = 0;
    v55 = 0;
    do
    {
      if ( (_DWORD)v6 )
      {
        v9 = 0;
        v10 = a2 + 28;
        do
        {
          v11 = reg_rules_intersect(a1, a2, a1 + 28 + 96 * v7, v10, &v54);
          v6 = *(unsigned int *)(a2 + 16);
          ++v9;
          if ( !v11 )
            ++v8;
          v10 += 96;
        }
        while ( v9 < v6 );
        v4 = *(unsigned int *)(a1 + 16);
      }
      ++v7;
    }
    while ( v7 < v4 );
    if ( v8 )
    {
      v12 = 96LL * v8 + 32;
      v13 = _kmalloc_noprof(v12, 3520);
      v2 = v13;
      if ( v13 )
      {
        v14 = *(unsigned int *)(a1 + 16);
        if ( (_DWORD)v14 )
        {
          v15 = 0;
          LODWORD(v16) = *(_DWORD *)(a2 + 16);
          v17 = v13 + 28;
          do
          {
            if ( (_DWORD)v16 )
            {
              v18 = 0;
              do
              {
                if ( (unsigned int)reg_rules_intersect(a1, a2, a1 + 28 + 96 * v15, a2 + 28 + 96 * v18, &v54) )
                  goto LABEL_20;
                v20 = *(unsigned int *)(v2 + 16);
                if ( (_DWORD)v20 )
                {
                  v21 = 0;
                  while ( 1 )
                  {
                    v22 = v21;
                    v23 = 3LL * v21;
                    v24 = 96LL * v21;
                    v25 = v12 >= v24 + 112 && v12 - (v24 + 112) >= 4;
                    if ( !v25 )
                    {
LABEL_79:
                      __break(1u);
                      goto LABEL_80;
                    }
                    v26 = v17 + v24;
                    if ( *(_DWORD *)(v17 + v24 + 84) == HIDWORD(v64) )
                    {
                      if ( v12 < v24 + 40 || v12 - (v24 + 40) < 4 )
                        goto LABEL_79;
                      v19 = *(unsigned int *)(v26 + 12);
                      v28 = (32 * v23) | 0x1C;
                      if ( (unsigned int)v19 <= HIDWORD(v55) )
                      {
                        if ( v12 < v24 + 44 || v12 - (v24 + 44) < 4 )
                          goto LABEL_79;
                        if ( *(_DWORD *)(v26 + 16) <= (unsigned int)v56 )
                        {
                          if ( v12 < v28 || v12 - v28 < 4 )
                            goto LABEL_79;
                          if ( *(_DWORD *)v26 <= (unsigned int)v54 )
                          {
                            if ( v12 < v24 + 32 || 96 * (unsigned __int64)v8 - v24 < 4 )
                              goto LABEL_79;
                            if ( *(_DWORD *)(v26 + 4) >= HIDWORD(v54) )
                            {
                              if ( v12 < v24 + 36 || v12 - (v24 + 36) < 4 )
                                goto LABEL_79;
                              if ( *(_DWORD *)(v26 + 8) >= (unsigned int)v55 )
                                goto LABEL_20;
                            }
                          }
                        }
                      }
                      if ( HIDWORD(v55) <= (unsigned int)v19 )
                      {
                        v19 = v12 - (v24 + 44);
                        if ( v12 < v24 + 44 || v19 < 4 )
                          goto LABEL_79;
                        v19 = *(unsigned int *)(v26 + 16);
                        if ( (unsigned int)v56 <= (unsigned int)v19 )
                        {
                          v25 = v12 >= v28;
                          v29 = v12 - v28;
                          if ( !v25 || v29 < 4 )
                            goto LABEL_79;
                          if ( (unsigned int)v54 <= *(_DWORD *)v26 )
                          {
                            if ( v12 < v24 + 32 || 96 * (unsigned __int64)v8 - v24 < 4 )
                              goto LABEL_79;
                            if ( HIDWORD(v54) >= *(_DWORD *)(v26 + 4) )
                            {
                              v30 = v24 + 36;
                              v25 = v12 >= v30;
                              v31 = v12 - v30;
                              if ( !v25 || v31 < 4 )
                                goto LABEL_79;
                              if ( (unsigned int)v55 >= *(_DWORD *)(v26 + 8) )
                                break;
                            }
                          }
                        }
                      }
                    }
                    v21 = v22 + 1;
                    if ( (_DWORD)v20 == (_DWORD)v22 + 1 )
                      goto LABEL_69;
                  }
                  v32 = (96 * v22) | 0x1C;
                  v25 = v12 >= v32;
                  v33 = v12 - v32;
                  if ( v25 )
                    v19 = v33;
                  else
                    v19 = 0;
                  if ( v19 > 0x5F )
                  {
                    v34 = v63;
                    *(_QWORD *)(v26 + 64) = v62;
                    *(_QWORD *)(v26 + 72) = v34;
                    v35 = v65;
                    *(_QWORD *)(v26 + 80) = v64;
                    *(_QWORD *)(v26 + 88) = v35;
                    v36 = v59;
                    *(_QWORD *)(v26 + 32) = v58;
                    *(_QWORD *)(v26 + 40) = v36;
                    v37 = v61;
                    *(_QWORD *)(v26 + 48) = v60;
                    *(_QWORD *)(v26 + 56) = v37;
                    v38 = v55;
                    *(_QWORD *)v26 = v54;
                    *(_QWORD *)(v26 + 8) = v38;
                    v39 = v57;
                    *(_QWORD *)(v26 + 16) = v56;
                    *(_QWORD *)(v26 + 24) = v39;
                    goto LABEL_20;
                  }
LABEL_80:
                  _fortify_panic(17, v19);
                }
LABEL_69:
                v40 = (96 * v20) | 0x1C;
                v25 = v12 >= v40;
                v41 = v12 - v40;
                if ( v25 )
                  v19 = v41;
                else
                  v19 = 0;
                if ( v19 <= 0x5F )
                  goto LABEL_80;
                v42 = *(_DWORD *)(v2 + 16);
                v43 = v62;
                v44 = v63;
                v45 = (_QWORD *)(v17 + 96LL * v42);
                *(_DWORD *)(v2 + 16) = v42 + 1;
                v45[8] = v43;
                v45[9] = v44;
                v46 = v65;
                v45[10] = v64;
                v45[11] = v46;
                v47 = v59;
                v45[4] = v58;
                v45[5] = v47;
                v48 = v61;
                v45[6] = v60;
                v45[7] = v48;
                v49 = v55;
                *v45 = v54;
                v45[1] = v49;
                v50 = v57;
                v45[2] = v56;
                v45[3] = v50;
LABEL_20:
                v16 = *(unsigned int *)(a2 + 16);
                ++v18;
              }
              while ( v18 < v16 );
              v14 = *(unsigned int *)(a1 + 16);
            }
            ++v15;
          }
          while ( v15 < v14 );
        }
        v51 = *(_DWORD *)(a1 + 24);
        v52 = *(_DWORD *)(a2 + 24);
        *(_WORD *)(v2 + 20) = 14393;
        if ( v51 != v52 )
          v51 = 0;
        *(_DWORD *)(v2 + 24) = v51;
      }
    }
    else
    {
LABEL_74:
      v2 = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
