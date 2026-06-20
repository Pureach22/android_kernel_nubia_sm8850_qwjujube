__int64 __fastcall setup_gx_arc_votes(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x4
  _DWORD *v11; // x19
  int v12; // w8
  int v13; // w8
  unsigned int v14; // w25
  _WORD *v15; // x27
  unsigned __int64 v16; // x26
  _DWORD *v17; // x20
  unsigned int v18; // w24
  unsigned int v19; // w0
  __int64 result; // x0
  int v21; // w8
  unsigned int v22; // w19
  __int64 v23; // [xsp+8h] [xbp-D8h]
  __int64 v24; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v25; // [xsp+18h] [xbp-C8h]
  __int64 v26; // [xsp+20h] [xbp-C0h]
  __int64 v27; // [xsp+28h] [xbp-B8h]
  __int64 v28; // [xsp+30h] [xbp-B0h]
  __int64 v29; // [xsp+38h] [xbp-A8h]
  __int64 v30; // [xsp+40h] [xbp-A0h]
  __int64 v31; // [xsp+48h] [xbp-98h]
  __int64 v32; // [xsp+50h] [xbp-90h]
  __int64 v33; // [xsp+58h] [xbp-88h]
  __int64 v34; // [xsp+60h] [xbp-80h]
  __int64 v35; // [xsp+68h] [xbp-78h]
  __int64 v36; // [xsp+70h] [xbp-70h]
  __int64 v37; // [xsp+78h] [xbp-68h]
  __int64 v38; // [xsp+80h] [xbp-60h]
  __int64 v39; // [xsp+88h] [xbp-58h]
  _QWORD v40[10]; // [xsp+90h] [xbp-50h] BYREF

  v40[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = to_a6xx_gmu(a1);
  v9 = *(_DWORD *)(a1 + 10068);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v10 = (unsigned int)(v9 + 1);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  *(_DWORD *)(v8 + 968) = v10;
  if ( (unsigned int)v10 > 0x20 || (unsigned int)v10 > *a2 )
  {
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Defined more GPU DCVS levels than RPMh can support\n");
    result = 4294967262LL;
  }
  else
  {
    v11 = (_DWORD *)v8;
    v40[6] = 0;
    v40[7] = 0;
    *(_QWORD *)(v8 + 980) = 0;
    v12 = *(_DWORD *)(a1 + 9164);
    memset(v40, 0, 48);
    if ( v12 == -1 )
      v13 = -1;
    else
      v13 = 0;
    *(_DWORD *)(v8 + 980) = v13;
    v14 = *(_DWORD *)(a1 + 10068) - 1;
    if ( (v14 & 0x80000000) != 0 )
    {
LABEL_13:
      result = adreno_rpmh_setup_volt_dependency_tbl(&v24, a2, a3, v40, v10);
      if ( !(_DWORD)result )
      {
        v21 = v11[242];
        if ( v21 )
        {
          v11[244] = v24;
          if ( v21 != 1 )
          {
            v11[247] = HIDWORD(v24);
            if ( v21 != 2 )
            {
              v11[250] = v25;
              if ( v21 != 3 )
              {
                v11[253] = HIDWORD(v25);
                if ( v21 != 4 )
                {
                  v11[256] = v26;
                  if ( v21 != 5 )
                  {
                    v11[259] = HIDWORD(v26);
                    if ( v21 != 6 )
                    {
                      v11[262] = v27;
                      if ( v21 != 7 )
                      {
                        v11[265] = HIDWORD(v27);
                        if ( v21 != 8 )
                        {
                          v11[268] = v28;
                          if ( v21 != 9 )
                          {
                            v11[271] = HIDWORD(v28);
                            if ( v21 != 10 )
                            {
                              v11[274] = v29;
                              if ( v21 != 11 )
                              {
                                v11[277] = HIDWORD(v29);
                                if ( v21 != 12 )
                                {
                                  v11[280] = v30;
                                  if ( v21 != 13 )
                                  {
                                    v11[283] = HIDWORD(v30);
                                    if ( v21 != 14 )
                                    {
                                      v11[286] = v31;
                                      if ( v21 != 15 )
                                      {
                                        v11[289] = HIDWORD(v31);
                                        if ( v21 != 16 )
LABEL_35:
                                          __break(0x5512u);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        result = 0;
      }
    }
    else
    {
      v23 = a3;
      v15 = (_WORD *)v40 + 1;
      v16 = 0;
      v17 = (_DWORD *)(a1 + 28LL * v14 + 9168);
      while ( 1 )
      {
        if ( v14 > 0x1F )
          goto LABEL_35;
        v18 = *(v17 - 1);
        *v15 = *v17;
        if ( v16 == 180 )
          goto LABEL_35;
        v11[v16 / 4 + 249] = *(v17 - 6) / 0x3E8u;
        v19 = adreno_rpmh_to_cx_hlvl(a4, v18, &v11[v16 / 4 + 248]);
        if ( v19 )
          break;
        v16 += 12LL;
        ++v15;
        v17 -= 7;
        if ( 12LL * v14 + 12 == v16 )
        {
          a3 = v23;
          v10 = (unsigned int)v11[242];
          goto LABEL_13;
        }
      }
      v22 = v19;
      dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unsupported cx corner: %u\n", v18);
      result = v22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
