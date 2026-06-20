__int64 __fastcall sde_dnsc_blur_parse_dt(unsigned __int64 a1, _DWORD *a2)
{
  int *v4; // x22
  unsigned int dt_entry; // w25
  __int64 v6; // x26
  __int64 v7; // x24
  int *v8; // x20
  __int64 v9; // x25
  int v10; // w8
  int v11; // w9
  _DWORD *v12; // x23
  int v13; // w9
  int v14; // w10
  int v15; // w3
  int v16; // w9
  int v17; // w3
  int v18; // w8
  __int64 v19; // x9
  __int64 v20; // x9
  __int64 v21; // x9
  __int64 v22; // x9
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x9
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x9
  __int64 v29; // x9
  unsigned __int64 StatusReg; // x20
  __int64 v31; // x23
  unsigned int v33; // [xsp+Ch] [xbp-34h] BYREF
  _BYTE v34[8]; // [xsp+10h] [xbp-30h] BYREF
  _QWORD v35[3]; // [xsp+18h] [xbp-28h] BYREF
  int v36; // [xsp+30h] [xbp-10h]
  __int64 v37; // [xsp+38h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  memset(v35, 0, sizeof(v35));
  v33 = 0;
  memset(v34, 0, 7);
  v4 = (int *)_kvmalloc_node_noprof(5376, 0, 3520, 0xFFFFFFFFLL);
  if ( v4 )
  {
    while ( 1 )
    {
      dt_entry = validate_dt_entry(a1, &dnsc_blur_prop, 7, v35, &v33);
      if ( dt_entry )
        break;
      if ( v33 >= 2 )
      {
        printk(&unk_23C956, "sde_dnsc_blur_parse_dt");
        dt_entry = -22;
        break;
      }
      a2[3156] = v33;
      dt_entry = read_dt_entry(a1, &dnsc_blur_prop, 7, v35, v34, v4);
      if ( dt_entry )
        break;
      if ( !a2[3156] )
      {
        dt_entry = 0;
        break;
      }
      v6 = 0;
      v7 = 0;
      _ReadStatusReg(SP_EL0);
      v8 = v4;
      while ( v6 != 208 )
      {
        v9 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
        if ( !v9 )
          goto LABEL_27;
        v10 = *v8;
        v11 = v4[192];
        v12 = &a2[v6];
        a1 = v7 + 1;
        *((_QWORD *)v12 + 1585) = v9;
        v12[3162] = v7 + 1;
        v12[3163] = v10;
        v12[3164] = v11;
        snprintf((char *)&a2[v6 + 3158], 0x10u, "dnsc_blur_%u", v7);
        v13 = v8[576];
        v14 = v4[768];
        v15 = a2[v6 + 3162] - 1;
        a2[12] = v4[384];
        *(_DWORD *)(v9 + 20) = v13;
        *(_DWORD *)(v9 + 24) = v14;
        snprintf((char *)v9, 0x10u, "dnsc_blur_lut_%u", v15);
        v16 = v4[1152];
        v17 = a2[v6 + 3162] - 1;
        *(_DWORD *)(v9 + 48) = v8[960];
        *(_DWORD *)(v9 + 52) = v16;
        snprintf((char *)(v9 + 28), 0x10u, "dnsc_blur_dit_%u", v17);
        v18 = a2[3568];
        if ( v18 )
        {
          v19 = (1LL << a2[3574]) | *((_QWORD *)v12 + 1586);
          *((_QWORD *)v12 + 1586) = v19;
          if ( v18 != 1 )
          {
            v20 = (1LL << a2[3596]) | v19;
            *((_QWORD *)v12 + 1586) = v20;
            if ( v18 != 2 )
            {
              v21 = (1LL << a2[3618]) | v20;
              *((_QWORD *)v12 + 1586) = v21;
              if ( v18 != 3 )
              {
                v22 = (1LL << a2[3640]) | v21;
                *((_QWORD *)v12 + 1586) = v22;
                if ( v18 != 4 )
                {
                  v23 = (1LL << a2[3662]) | v22;
                  *((_QWORD *)v12 + 1586) = v23;
                  if ( v18 != 5 )
                  {
                    v24 = (1LL << a2[3684]) | v23;
                    *((_QWORD *)v12 + 1586) = v24;
                    if ( v18 != 6 )
                    {
                      v25 = (1LL << a2[3706]) | v24;
                      *((_QWORD *)v12 + 1586) = v25;
                      if ( v18 != 7 )
                      {
                        v26 = (1LL << a2[3728]) | v25;
                        *((_QWORD *)v12 + 1586) = v26;
                        if ( v18 != 8 )
                        {
                          v27 = (1LL << a2[3750]) | v26;
                          *((_QWORD *)v12 + 1586) = v27;
                          if ( v18 != 9 )
                          {
                            v28 = (1LL << a2[3772]) | v27;
                            *((_QWORD *)v12 + 1586) = v28;
                            if ( v18 != 10 )
                            {
                              v29 = (1LL << a2[3794]) | v28;
                              *((_QWORD *)v12 + 1586) = v29;
                              if ( v18 != 11 )
                              {
                                *((_QWORD *)v12 + 1586) = (1LL << a2[3816]) | v29;
                                if ( v18 != 12 )
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
        dt_entry = 0;
        v6 += 16;
        ++v8;
        ++v7;
        if ( a1 >= (unsigned int)a2[3156] )
          goto LABEL_28;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v31 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_dnsc_blur_parse_dt__alloc_tag;
      v4 = (int *)_kvmalloc_node_noprof(5376, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(StatusReg + 80) = v31;
      if ( !v4 )
        goto LABEL_27;
    }
  }
  else
  {
LABEL_27:
    dt_entry = -12;
  }
LABEL_28:
  kvfree(v4);
  _ReadStatusReg(SP_EL0);
  return dt_entry;
}
