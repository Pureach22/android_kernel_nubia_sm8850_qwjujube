__int64 __fastcall gen7_power_stats(__int64 a1, _QWORD *a2)
{
  unsigned int *v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w9
  unsigned int v7; // w8
  unsigned int v8; // w0
  unsigned int v9; // w9
  unsigned int v10; // w8
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 v13; // x25
  __int64 v14; // x26
  __int64 v15; // x27
  __int64 v16; // x8
  unsigned int v17; // w0
  unsigned int v18; // w9
  unsigned int v19; // w8
  unsigned int v20; // w0
  unsigned int v21; // w9
  unsigned int v22; // w8
  unsigned int v23; // w0
  unsigned int v24; // w9
  unsigned int v25; // w8
  unsigned int v26; // w0
  unsigned int v27; // w9
  unsigned int v28; // w8
  unsigned int v29; // w0
  unsigned int v30; // w9

  v4 = (unsigned int *)(a1 + 20336);
  v5 = kgsl_regmap_read(a1 + 13200);
  v6 = *v4;
  if ( *v4 )
  {
    v7 = v5 - v6;
    if ( v5 < v6 )
      v7 = v5 + ~v6;
  }
  else
  {
    v7 = 0;
  }
  *v4 = v5;
  *a2 = (10 * (unsigned __int64)v7 * (unsigned __int128)0x155555555555556uLL) >> 64;
  if ( *(_BYTE *)(a1 + 10368) == 1 )
  {
    if ( v4[13] )
    {
      v8 = kgsl_regmap_read(a1 + 13200);
      v9 = v4[1];
      if ( v9 )
      {
        v10 = v8 - v9;
        if ( v8 < v9 )
          v10 = v8 + ~v9;
      }
      else
      {
        v10 = 0;
      }
      v11 = v10;
      v4[1] = v8;
      if ( v4[17] )
      {
LABEL_18:
        v17 = kgsl_regmap_read(a1 + 13200);
        v18 = v4[5];
        if ( v18 )
        {
          v19 = v17 - v18;
          if ( v17 < v18 )
            v19 = v17 + ~v18;
        }
        else
        {
          v19 = 0;
        }
        v12 = v19;
        v4[5] = v17;
        if ( v4[14] )
        {
LABEL_23:
          v20 = kgsl_regmap_read(a1 + 13200);
          v21 = v4[2];
          if ( v21 )
          {
            v22 = v20 - v21;
            if ( v20 < v21 )
              v22 = v20 + ~v21;
          }
          else
          {
            v22 = 0;
          }
          v13 = v22;
          v4[2] = v20;
          if ( v4[15] )
          {
LABEL_28:
            v23 = kgsl_regmap_read(a1 + 13200);
            v24 = v4[3];
            if ( v24 )
            {
              v25 = v23 - v24;
              if ( v23 < v24 )
                v25 = v23 + ~v24;
            }
            else
            {
              v25 = 0;
            }
            v14 = v25;
            v4[3] = v23;
            if ( v4[16] )
            {
LABEL_33:
              v26 = kgsl_regmap_read(a1 + 13200);
              v27 = v4[4];
              if ( v27 )
              {
                v28 = v26 - v27;
                if ( v26 < v27 )
                  v28 = v26 + ~v27;
              }
              else
              {
                v28 = 0;
              }
              v15 = v28;
              v4[4] = v26;
              if ( v4[18] )
                goto LABEL_38;
              goto LABEL_15;
            }
LABEL_14:
            v15 = 0;
            if ( v4[18] )
            {
LABEL_38:
              v29 = kgsl_regmap_read(a1 + 13200);
              v30 = v4[6];
              if ( v30 )
              {
                LODWORD(v16) = v29 - v30;
                if ( v29 < v30 )
                  LODWORD(v16) = v29 + ~v30;
              }
              else
              {
                LODWORD(v16) = 0;
              }
              v16 = (unsigned int)v16;
              v4[6] = v29;
              goto LABEL_43;
            }
LABEL_15:
            v16 = 0;
LABEL_43:
            a2[1] = v13 + v11 + v14 + v15;
            a2[2] = v16 + v12;
            return gen7_power_feature_stats(a1);
          }
LABEL_13:
          v14 = 0;
          if ( v4[16] )
            goto LABEL_33;
          goto LABEL_14;
        }
LABEL_12:
        v13 = 0;
        if ( v4[15] )
          goto LABEL_28;
        goto LABEL_13;
      }
    }
    else
    {
      v11 = 0;
      if ( v4[17] )
        goto LABEL_18;
    }
    v12 = 0;
    if ( v4[14] )
      goto LABEL_23;
    goto LABEL_12;
  }
  return gen7_power_feature_stats(a1);
}
