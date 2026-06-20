__int64 __fastcall adreno_profile_process_results(__int64 a1)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x22
  _DWORD *v3; // x20
  unsigned int v4; // w21
  __int64 v5; // x1
  __int64 result; // x0
  unsigned int v8; // w10
  unsigned int *v9; // x15
  unsigned int v10; // w14
  unsigned int v11; // w15
  unsigned int v12; // w15
  bool v13; // cf
  unsigned int v14; // w15
  char *v15; // x17
  unsigned int v16; // w2
  __int64 v17; // x9
  __int64 v18; // x10
  unsigned __int64 v19; // x12
  int v20; // w0
  int v21; // w4
  __int64 v22; // x22
  int v23; // w3
  int v24; // w5
  int v25; // w6
  int v26; // w7
  char *v27; // x24
  unsigned int v28; // w1
  unsigned __int64 v29; // x25
  __int64 v30; // x24
  _DWORD *v31; // x17
  __int64 v32; // x22
  _DWORD *v33; // x17
  _DWORD *v34; // x17
  __int64 v35; // x7
  _DWORD *v36; // x17
  _DWORD *v37; // x17
  __int64 v38; // x5
  _DWORD *v39; // x17
  _DWORD *v40; // x17
  __int64 v41; // x5
  _DWORD *v42; // x17
  _DWORD *v43; // x17
  __int64 v44; // x4
  _DWORD *v45; // x17
  _DWORD *v46; // x17
  __int64 v47; // x3
  int v48; // w3
  unsigned int v49; // w2
  __int64 v50; // x4
  _DWORD *v51; // x17
  __int64 v52; // x4
  _DWORD *v53; // x17
  _DWORD *v54; // x17
  __int64 v55; // x4
  _DWORD *v56; // x17
  _DWORD *v57; // x17
  __int64 v58; // x4
  int v59; // w5
  unsigned int v60; // w6
  _DWORD *v61; // x17
  _DWORD *v62; // x17
  __int64 v63; // x4
  _DWORD *v64; // x17
  _DWORD *v65; // x17
  __int64 v66; // x4
  unsigned int v67; // w0
  __int64 v68; // x1
  unsigned int v69; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v70; // [xsp+8h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 24024) & 1) == 0 )
  {
    v1 = *(_QWORD *)(a1 + 19736);
    if ( v1 <= 0xFFFFFFFFFFFFF000LL )
    {
      v2 = *(_QWORD *)(v1 + 8);
      if ( v2 )
      {
        if ( *(_QWORD *)(v1 + 40) )
        {
          v3 = (_DWORD *)(a1 + 19744);
          v4 = *(_DWORD *)(a1 + 19748);
          if ( *(_DWORD *)(a1 + 19744) != v4 )
          {
            v5 = *(_QWORD *)(a1 + 19640);
            v69 = 0;
            if ( !(unsigned int)adreno_rb_readtimestamp(a1, v5, 2, &v69) )
            {
              v8 = v69 ^ 0x80000000;
              while ( 1 )
              {
                v9 = (unsigned int *)(v2 + 4LL * v4);
                v10 = v9[1];
                if ( !v10 )
                  break;
                v11 = *v9;
                if ( v11 == v69
                  || v11 > v69 && ((v11 - v69) & 0x80000000) == 0
                  || (v12 = v11 ^ 0x80000000, v13 = v12 >= v8, v14 = v12 - v8, v14 != 0 && v13) && v14 < 0x80000001 )
                {
                  if ( v4 == v3[1] )
                    break;
LABEL_19:
                  v15 = *(char **)(a1 + 19712);
                  if ( v15 )
                  {
                    v16 = v3[1];
                    if ( v16 != v4 )
                    {
                      v17 = *(_QWORD *)(a1 + 19704);
                      v18 = *(_QWORD *)(*(_QWORD *)(a1 + 19736) + 8LL);
                      v19 = v17 + 942080;
                      do
                      {
                        v20 = *(_DWORD *)(v18 + 4LL * (v16 + 1));
                        v21 = *(_DWORD *)(v18 + 4LL * (v16 + 2));
                        v22 = *(_QWORD *)(a1 + 19704);
                        v23 = *(_DWORD *)(v18 + 4LL * v16);
                        v24 = *(_DWORD *)(v18 + 4LL * (v16 + 3));
                        v25 = *(_DWORD *)(v18 + 4LL * (v16 + 4));
                        v26 = *(_DWORD *)(v18 + 4LL * (v16 + 5));
                        v27 = *(char **)(a1 + 19720);
                        v28 = 5 * v20 + 6;
                        while ( 1 )
                        {
                          v29 = (unsigned __int64)(v27 - v15) >> 3;
                          if ( &v27[-v22] <= &v15[-v22] )
                            LODWORD(v29) = 235520 - ((unsigned __int64)(v15 - v27) >> 3);
                          if ( (unsigned int)v29 > v28 )
                            break;
                          v30 = 5LL * *(unsigned __int16 *)v27 + ((unsigned __int64)&v27[-v17] >> 3) + 6;
                          v27 = (char *)(v17
                                       + 4
                                       * (v30
                                        - 235520
                                        * ((unsigned __int64)(((unsigned __int64)v30
                                                             * (unsigned __int128)0x239E0D5B450239E1uLL) >> 64) >> 15)));
                          *(_QWORD *)(a1 + 19720) = v27;
                        }
                        *(_DWORD *)v15 = v20;
                        v31 = v15 + 4;
                        if ( (unsigned __int64)v31 >= v19 )
                          v32 = 0x3FFFFFFFFFFC6800LL;
                        else
                          v32 = 0;
                        v33 = &v31[v32];
                        *v33 = v26;
                        v34 = v33 + 1;
                        if ( (unsigned __int64)v34 >= v19 )
                          v35 = 0x3FFFFFFFFFFC6800LL;
                        else
                          v35 = 0;
                        v36 = &v34[v35];
                        *v36 = v24;
                        v37 = v36 + 1;
                        if ( (unsigned __int64)v37 >= v19 )
                          v38 = 0x3FFFFFFFFFFC6800LL;
                        else
                          v38 = 0;
                        v39 = &v37[v38];
                        *v39 = v25;
                        v40 = v39 + 1;
                        if ( (unsigned __int64)v40 >= v19 )
                          v41 = 0x3FFFFFFFFFFC6800LL;
                        else
                          v41 = 0;
                        v42 = &v40[v41];
                        *v42 = v21;
                        v43 = v42 + 1;
                        if ( (unsigned __int64)v43 >= v19 )
                          v44 = 0x3FFFFFFFFFFC6800LL;
                        else
                          v44 = 0;
                        v45 = &v43[v44];
                        *v45 = v23;
                        v46 = v45 + 1;
                        if ( (unsigned __int64)v46 >= v19 )
                          v47 = 0x3FFFFFFFFFFC6800LL;
                        else
                          v47 = 0;
                        v15 = (char *)&v46[v47];
                        if ( v20 )
                        {
                          v48 = 0;
                          v49 = v16 + 6;
                          do
                          {
                            v50 = a1 + 19680;
                            do
                            {
                              v50 = *(_QWORD *)v50;
                              if ( v50 == a1 + 19680 )
                                goto LABEL_71;
                            }
                            while ( *(_DWORD *)(v50 + 52) != *(_DWORD *)(v18 + 4LL * v49) );
                            if ( !v50 )
                            {
LABEL_71:
                              *(_DWORD *)v15 = -1;
                              v15 = *(char **)(a1 + 19720);
                              v3[1] = ((unsigned int)v3[1] + (unsigned __int64)(v28 + 20 * v20 + 32))
                                    % (unsigned int)v3[2];
                              goto LABEL_72;
                            }
                            ++v48;
                            *(_DWORD *)v15 = *(unsigned __int16 *)(v50 + 48) | (*(_DWORD *)(v50 + 44) << 16);
                            v51 = v15 + 4;
                            if ( (unsigned __int64)v51 >= v19 )
                              v52 = 0x3FFFFFFFFFFC6800LL;
                            else
                              v52 = 0;
                            v53 = &v51[v52];
                            *v53 = *(_DWORD *)(v18 + 4LL * (v49 + 1));
                            v54 = v53 + 1;
                            if ( (unsigned __int64)v54 >= v19 )
                              v55 = 0x3FFFFFFFFFFC6800LL;
                            else
                              v55 = 0;
                            v56 = &v54[v55];
                            *v56 = *(_DWORD *)(v18 + 4LL * (v49 + 2));
                            v57 = v56 + 1;
                            if ( (unsigned __int64)v57 >= v19 )
                              v58 = 0x3FFFFFFFFFFC6800LL;
                            else
                              v58 = 0;
                            v59 = *(_DWORD *)(v18 + 4LL * (v49 + 3));
                            v60 = v49 + 4;
                            v61 = &v57[v58];
                            v49 += 5;
                            *v61 = v59;
                            v62 = v61 + 1;
                            if ( (unsigned __int64)v62 >= v19 )
                              v63 = 0x3FFFFFFFFFFC6800LL;
                            else
                              v63 = 0;
                            v64 = &v62[v63];
                            *v64 = *(_DWORD *)(v18 + 4LL * v60);
                            v65 = v64 + 1;
                            if ( (unsigned __int64)v65 >= v19 )
                              v66 = 0x3FFFFFFFFFFC6800LL;
                            else
                              v66 = 0;
                            v15 = (char *)&v65[v66];
                          }
                          while ( v48 != v20 );
                        }
                        v67 = v28 + 20 * v20;
                        v68 = (unsigned int)v3[1];
                        v16 = (v68 + (unsigned __int64)(v67 + 32)) % (unsigned int)v3[2];
                        v3[1] = v16;
                        if ( (unsigned int)v68 > v16 )
                          v3[2] = 49152;
                      }
                      while ( v4 != v16 );
                    }
LABEL_72:
                    *(_QWORD *)(a1 + 19712) = v15;
                  }
                  result = 1;
                  goto LABEL_8;
                }
                v4 = (25 * v10 + 38 + (unsigned __int64)v4) % (unsigned int)v3[2];
                if ( *v3 == v4 )
                  goto LABEL_19;
              }
            }
          }
        }
      }
    }
  }
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
