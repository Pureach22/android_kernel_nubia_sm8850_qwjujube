__int64 __fastcall sde_vbif_parse_dt(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  unsigned int dt_entry; // w22
  unsigned int v6; // w21
  unsigned int i; // w23
  unsigned int v9; // [xsp+4h] [xbp-5Ch] BYREF
  _QWORD v10[2]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v11[2]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v12; // [xsp+28h] [xbp-38h] BYREF
  __int64 v13; // [xsp+30h] [xbp-30h] BYREF
  __int64 v14; // [xsp+38h] [xbp-28h] BYREF
  __int64 v15; // [xsp+40h] [xbp-20h] BYREF
  __int64 v16; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v17[2]; // [xsp+50h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17[0] = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v11[0] = 0;
  v11[1] = 0;
  v10[0] = 0;
  v10[1] = 0;
  v9 = 0;
  v4 = _kvmalloc_node_noprof(12288, 0, 3520, 0xFFFFFFFFLL);
  if ( v4 )
  {
    dt_entry = validate_dt_entry(a1, &vbif_prop, 16, v11, &v9);
    if ( !dt_entry )
    {
      dt_entry = validate_dt_entry(a1, &unk_B3C8, 1, (char *)&v12 + 4, 0);
      if ( !dt_entry )
      {
        dt_entry = validate_dt_entry(a1, &unk_B3E0, 1, &v13, 0);
        if ( !dt_entry )
        {
          dt_entry = validate_dt_entry(a1, &unk_B3F8, 1, (char *)&v13 + 4, 0);
          if ( !dt_entry )
          {
            dt_entry = validate_dt_entry(a1, &unk_B410, 1, &v14, 0);
            if ( !dt_entry )
            {
              dt_entry = validate_dt_entry(a1, &unk_B428, 1, (char *)&v14 + 4, 0);
              if ( !dt_entry )
              {
                dt_entry = validate_dt_entry(a1, &unk_B440, 1, &v15, 0);
                if ( !dt_entry )
                {
                  dt_entry = validate_dt_entry(a1, &unk_B458, 1, (char *)&v15 + 4, 0);
                  if ( !dt_entry )
                  {
                    dt_entry = validate_dt_entry(a1, &unk_B470, 1, &v16, 0);
                    if ( !dt_entry )
                    {
                      dt_entry = validate_dt_entry(a1, &unk_B488, 1, (char *)&v16 + 4, 0);
                      if ( !dt_entry )
                      {
                        dt_entry = validate_dt_entry(a1, &unk_B4A0, 1, v17, 0);
                        if ( !dt_entry )
                        {
                          dt_entry = validate_dt_entry(a1, &unk_B4B8, 1, (char *)v17 + 4, 0);
                          if ( !dt_entry )
                          {
                            *(_DWORD *)(a2 + 15336) = v9;
                            dt_entry = read_dt_entry(a1, &vbif_prop, 16, v11, v10, v4);
                            if ( !dt_entry )
                            {
                              if ( BYTE1(v10[0]) )
                                v6 = *(_DWORD *)(v4 + 768);
                              else
                                v6 = 256;
                              if ( v9 )
                              {
                                for ( i = 0; i < v9; ++i )
                                {
                                  dt_entry = sde_vbif_populate(a2, v4, v11, v6, i);
                                  if ( dt_entry )
                                    break;
                                }
                              }
                              else
                              {
                                dt_entry = 0;
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
  else
  {
    dt_entry = -12;
  }
  kvfree(v4);
  _ReadStatusReg(SP_EL0);
  return dt_entry;
}
