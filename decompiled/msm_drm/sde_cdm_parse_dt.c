__int64 __fastcall sde_cdm_parse_dt(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x20
  unsigned int v5; // w22
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x22
  unsigned __int64 v9; // x3
  _DWORD *v10; // x23
  _DWORD *v11; // x26
  unsigned __int64 v19; // x9
  _DWORD *v20; // x28
  unsigned __int64 v21; // x27
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x9
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x9
  __int64 v29; // x9
  __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x9
  __int64 v33; // x9
  int v34; // w9
  unsigned int v35; // [xsp+0h] [xbp-20h] BYREF
  __int16 v36; // [xsp+4h] [xbp-1Ch] BYREF
  char v37; // [xsp+6h] [xbp-1Ah]
  __int64 v38; // [xsp+8h] [xbp-18h] BYREF
  int v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v38 = 0;
  v37 = 0;
  v36 = 0;
  v35 = 0;
  v4 = _kvmalloc_node_noprof(2304, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
  {
    v5 = -12;
LABEL_7:
    kvfree(v4);
    _ReadStatusReg(SP_EL0);
    return v5;
  }
  v5 = validate_dt_entry(a1, &cdm_prop, 2, &v38, &v35);
  if ( v5 )
    goto LABEL_7;
  a2[2962] = v35;
  v6 = read_dt_entry(a1, &cdm_prop, 2, &v38, &v36, v4);
  v5 = v6;
  if ( (_DWORD)v6 )
    goto LABEL_7;
  if ( !v35 )
  {
LABEL_26:
    v5 = 0;
    goto LABEL_7;
  }
  v8 = 0;
  v9 = 0;
  v10 = a2 + 2972;
  v11 = (_DWORD *)v4;
  while ( v8 != 208 )
  {
    v20 = &a2[v8];
    v21 = v9 + 1;
    v20[2969] = *v11;
    v20[2968] = v9 + 1;
    v6 = snprintf((char *)&v10[v8 - 8], 0x10u, "cdm_%u", v9);
    v20[2970] = *(_DWORD *)(v4 + 768);
    v22 = a2[3568];
    if ( v22 )
    {
      v23 = (1LL << a2[3574]) | *((_QWORD *)v20 + 1489);
      *((_QWORD *)v20 + 1489) = v23;
      if ( v22 != 1 )
      {
        v24 = (1LL << a2[3596]) | v23;
        *((_QWORD *)v20 + 1489) = v24;
        if ( v22 != 2 )
        {
          v25 = (1LL << a2[3618]) | v24;
          *((_QWORD *)v20 + 1489) = v25;
          if ( v22 != 3 )
          {
            v26 = (1LL << a2[3640]) | v25;
            *((_QWORD *)v20 + 1489) = v26;
            if ( v22 != 4 )
            {
              v27 = (1LL << a2[3662]) | v26;
              *((_QWORD *)v20 + 1489) = v27;
              if ( v22 != 5 )
              {
                v28 = (1LL << a2[3684]) | v27;
                *((_QWORD *)v20 + 1489) = v28;
                if ( v22 != 6 )
                {
                  v29 = (1LL << a2[3706]) | v28;
                  *((_QWORD *)v20 + 1489) = v29;
                  if ( v22 != 7 )
                  {
                    v30 = (1LL << a2[3728]) | v29;
                    *((_QWORD *)v20 + 1489) = v30;
                    if ( v22 != 8 )
                    {
                      v31 = (1LL << a2[3750]) | v30;
                      *((_QWORD *)v20 + 1489) = v31;
                      if ( v22 != 9 )
                      {
                        v32 = (1LL << a2[3772]) | v31;
                        *((_QWORD *)v20 + 1489) = v32;
                        if ( v22 != 10 )
                        {
                          v33 = (1LL << a2[3794]) | v32;
                          *((_QWORD *)v20 + 1489) = v33;
                          if ( v22 != 11 )
                          {
                            *((_QWORD *)v20 + 1489) = (1LL << a2[3816]) | v33;
                            if ( v22 != 12 )
                              break;
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
    v34 = a2[7];
    *((_QWORD *)v20 + 1488) = 16LL * (a2[3350] != 0);
    if ( v34 == 256 )
    {
      _X8 = (unsigned __int64 *)&v10[v8];
      __asm { PRFM            #0x11, [X8] }
      do
        v19 = __ldxr(_X8);
      while ( __stxr(v19 | 2, _X8) );
    }
    v8 += 16;
    ++v11;
    v9 = v21;
    if ( v21 >= v35 )
      goto LABEL_26;
  }
  __break(0x5512u);
  return sde_dnsc_blur_parse_dt(v6, v7);
}
