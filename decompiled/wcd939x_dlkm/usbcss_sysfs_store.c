__int64 __fastcall usbcss_sysfs_store(__int64 a1, const char **a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x19
  __int64 v5; // x20
  __int64 result; // x0
  const char *v9; // x21
  int v10; // w8
  _BOOL4 v11; // w21
  __int64 v12; // x3
  int v13; // w10
  int v14; // w9
  int v15; // w9
  unsigned int v16; // w9
  int v17; // w10
  int v18; // w9
  int v19; // w13
  int v20; // w14
  int v21; // w12
  int v22; // w11
  __int64 v23; // x3
  int v24; // w8
  int v25; // w8
  __int64 v26; // x8
  unsigned __int64 v27; // x9
  unsigned int v28; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(a2 - 1);
  v28 = 0;
  if ( !v4 || (v29[0] = 0, (v5 = *(_QWORD *)(*v4 + 144LL)) == 0) )
  {
    result = -22;
    goto LABEL_6;
  }
  LODWORD(result) = kstrtoll(a3, 0, v29);
  if ( !(_DWORD)result )
  {
    v9 = *a2;
    if ( !strcmp(v9, "rdson_3p6v") )
    {
      v12 = v29[0];
      if ( v29[0] < 20001LL )
      {
        v13 = *(_DWORD *)(v5 + 260);
        v10 = 0;
        v14 = LODWORD(v29[0]) - *(_DWORD *)(v5 + 224);
        *(_DWORD *)(v5 + 228) = v29[0];
        *(_DWORD *)(v5 + 232) = v14;
        v11 = v13 == 2;
        goto LABEL_37;
      }
      goto LABEL_81;
    }
    if ( !strcmp(v9, "rdson_6v") )
    {
      v12 = v29[0];
      if ( v29[0] < 20001LL )
      {
        v15 = *(_DWORD *)(v5 + 260);
        v10 = 0;
        *(_DWORD *)(v5 + 224) = v29[0];
        v11 = v15 == 2;
        goto LABEL_37;
      }
      goto LABEL_81;
    }
    if ( strcmp(v9, "r1_l") )
    {
      if ( !strcmp(v9, "r1_r") )
      {
        v12 = v29[0];
        if ( v29[0] >= 20001LL )
          goto LABEL_81;
        v11 = 0;
        *(_DWORD *)(v5 + 100) = v29[0];
        goto LABEL_36;
      }
      if ( !strcmp(v9, "r3_l") )
      {
        v12 = v29[0];
        if ( v29[0] < 20001LL )
        {
          v10 = 0;
          *(_DWORD *)(v5 + 76) = v29[0];
          v11 = 1;
          goto LABEL_37;
        }
        goto LABEL_81;
      }
      if ( !strcmp(v9, "r3_r") )
      {
        v12 = v29[0];
        if ( v29[0] < 20001LL )
        {
          v10 = 0;
          *(_DWORD *)(v5 + 104) = v29[0];
          v11 = 1;
          goto LABEL_37;
        }
        goto LABEL_81;
      }
      if ( !strcmp(v9, "r4_sbu1") )
      {
        v12 = v29[0];
        if ( v29[0] < 20001LL )
        {
          *(_DWORD *)(v5 + 148) = v29[0];
          goto LABEL_53;
        }
LABEL_81:
        dev_err(*v4, "%s: Value %ld out of HS impedance range %d\n", "usbcss_sysfs_store", v12, 20000);
        goto LABEL_82;
      }
      if ( !strcmp(v9, "r4_sbu2") )
      {
        v12 = v29[0];
        if ( v29[0] >= 20001LL )
          goto LABEL_81;
        result = a4;
        *(_DWORD *)(v5 + 184) = v29[0];
      }
      else
      {
        if ( !strcmp(v9, "r5_sbu1") )
        {
          v12 = v29[0];
          if ( v29[0] < 20001LL )
          {
            v24 = *(_DWORD *)(v5 + 260);
            *(_DWORD *)(v5 + 152) = v29[0];
            if ( v24 != 2 )
              goto LABEL_82;
            goto LABEL_53;
          }
          goto LABEL_81;
        }
        if ( strcmp(v9, "r5_sbu2") )
        {
          if ( !strcmp(v9, "r6_sbu1") )
          {
            v12 = v29[0];
            if ( v29[0] >= 20001LL )
              goto LABEL_81;
            v10 = *(_DWORD *)(v5 + 260);
            result = a4;
            *(_DWORD *)(v5 + 156) = v29[0];
            if ( v10 != 1 )
              goto LABEL_6;
          }
          else if ( !strcmp(v9, "r6_sbu2") )
          {
            v12 = v29[0];
            if ( v29[0] >= 20001LL )
              goto LABEL_81;
            v10 = *(_DWORD *)(v5 + 260);
            result = a4;
            *(_DWORD *)(v5 + 192) = v29[0];
            if ( v10 != 1 )
              goto LABEL_6;
          }
          else
          {
            if ( strcmp(v9, "r7_sbu1") )
            {
              if ( !strcmp(v9, "r7_sbu2") )
              {
                v12 = v29[0];
                if ( v29[0] < 20001LL )
                {
                  v10 = *(_DWORD *)(v5 + 260);
                  *(_DWORD *)(v5 + 196) = v29[0];
                  if ( v10 != 1 )
                    goto LABEL_82;
                  v11 = 1;
                  goto LABEL_37;
                }
                goto LABEL_81;
              }
              if ( strcmp(v9, "r_common_gnd_offset") )
              {
                if ( !strcmp(v9, "rcom_margin") )
                {
                  v12 = v29[0];
                  if ( v29[0] < 20001LL )
                  {
                    v10 = 0;
                    v11 = 0;
                    *(_DWORD *)(v5 + 252) = v29[0];
                    goto LABEL_37;
                  }
                }
                else
                {
                  if ( strcmp(v9, "se_slope_factor_times_1000") )
                  {
                    if ( !strcmp(v9, "diff_slope_factor_times_1000") )
                    {
                      if ( (unsigned __int64)(v29[0] - 10001LL) <= 0xFFFFFFFFFFFFFF36LL )
                      {
                        dev_err(
                          *v4,
                          "%s: Value %ld out of range of %d to %d\n",
                          "usbcss_sysfs_store",
                          v29[0],
                          9800,
                          10000);
                        goto LABEL_82;
                      }
                      v10 = 0;
                      v11 = 0;
                      *(_DWORD *)(v5 + 268) = v29[0];
                      goto LABEL_37;
                    }
                    if ( !strcmp(v9, "lin_k_aud") )
                    {
                      if ( (unsigned __int64)(v29[0] - 10001LL) <= 0xFFFFFFFFFFFFD894LL )
                      {
                        dev_err(
                          *v4,
                          "%s: Value %ld out of bounds. Min: %d, Max: %d\n",
                          "usbcss_sysfs_store",
                          v29[0],
                          4294967206LL,
                          10000);
                        goto LABEL_82;
                      }
                      v10 = 0;
                      *(_DWORD *)(v5 + 116) = v29[0];
                      v11 = 1;
                      goto LABEL_37;
                    }
                    if ( strcmp(v9, "xtalk_config") )
                    {
                      v10 = 0;
                      v11 = 0;
LABEL_37:
                      result = a4;
LABEL_38:
                      v16 = *(_DWORD *)(v5 + 260);
                      if ( v16 >= 2 )
                      {
                        if ( v16 != 2 )
                          goto LABEL_6;
                        v18 = *(_DWORD *)(v5 + 184) + *(_DWORD *)(v5 + 188);
                        v17 = *(_DWORD *)(v5 + 148) + *(_DWORD *)(v5 + 152);
                        v22 = 1;
                        v21 = 1;
                        *(_DWORD *)(v5 + 168) = v18;
                        *(_DWORD *)(v5 + 132) = v17;
                        *(_DWORD *)(v5 + 136) = 1;
                      }
                      else
                      {
                        v17 = *(_DWORD *)(v5 + 160);
                        v19 = *(_DWORD *)(v5 + 192);
                        v18 = *(_DWORD *)(v5 + 196);
                        v20 = *(_DWORD *)(v5 + 184);
                        v21 = *(_DWORD *)(v5 + 148) + *(_DWORD *)(v5 + 156);
                        *(_DWORD *)(v5 + 168) = v18;
                        v22 = v20 + v19;
                        *(_DWORD *)(v5 + 132) = v17;
                        *(_DWORD *)(v5 + 136) = v21;
                      }
                      *(_DWORD *)(v5 + 140) = v21 + v17;
                      *(_DWORD *)(v5 + 172) = v22;
                      *(_DWORD *)(v5 + 176) = v22 + v18;
                      if ( v10 )
                      {
                        *(_DWORD *)(v5 + 244) += *(_DWORD *)(v5 + 248);
                        update_xtalk_scale_and_alpha((__int64)v4);
                        v23 = *(unsigned __int8 *)(v5 + 256);
                        *(_DWORD *)(v5 + 244) -= *(_DWORD *)(v5 + 248);
                        regmap_update_bits_base(v4[4], 13601, 31, v23, 0, 0, 0);
                        regmap_update_bits_base(v4[4], 13602, 255, *(unsigned __int8 *)(v5 + 257), 0, 0, 0);
                        regmap_update_bits_base(v4[4], 13605, 31, *(unsigned __int8 *)(v5 + 258), 0, 0, 0);
                        regmap_update_bits_base(v4[4], 13606, 255, *(unsigned __int8 *)(v5 + 259), 0, 0, 0);
                        dev_err(*v4, "%s: Updated xtalk thru sysfs\n", "usbcss_sysfs_store");
                        result = a4;
                        if ( !v11 )
                          goto LABEL_6;
                      }
                      else if ( !v11 )
                      {
                        goto LABEL_6;
                      }
                      get_linearizer_taps(v5, &v28);
                      wcd_usbss_set_linearizer_sw_tap(v28, 0);
                      dev_err(*v4, "%s: Updated linearizer thru sysfs\n", "usbcss_sysfs_store");
LABEL_82:
                      result = a4;
                      goto LABEL_6;
                    }
                    v26 = v29[0];
                    v27 = v29[0] - 1LL;
                    *(_DWORD *)(v5 + 260) = v29[0];
                    if ( v27 >= 2 )
                    {
                      if ( v26 )
                        goto LABEL_82;
                      v11 = 0;
                      *(_DWORD *)(v5 + 256) = 2031647;
                      goto LABEL_36;
                    }
LABEL_53:
                    v10 = 1;
                    v11 = 1;
                    goto LABEL_37;
                  }
                  v12 = v29[0];
                  if ( v29[0] < 20001LL )
                  {
                    v10 = 0;
                    v11 = 0;
                    *(_DWORD *)(v5 + 272) = v29[0];
                    goto LABEL_37;
                  }
                }
                goto LABEL_81;
              }
              if ( (unsigned __int64)(v29[0] - 20001LL) <= 0xFFFFFFFFFFFF63BELL )
              {
                dev_err(
                  *v4,
                  "%s: Value %ld out of bounds. Min: %d, Max: %d\n",
                  "usbcss_sysfs_store",
                  v29[0],
                  -20000,
                  20000);
                goto LABEL_82;
              }
              v11 = 0;
              *(_DWORD *)(v5 + 248) = v29[0];
LABEL_36:
              v10 = 1;
              goto LABEL_37;
            }
            v12 = v29[0];
            if ( v29[0] >= 20001LL )
              goto LABEL_81;
            v10 = *(_DWORD *)(v5 + 260);
            result = a4;
            *(_DWORD *)(v5 + 160) = v29[0];
            if ( v10 != 1 )
              goto LABEL_6;
          }
          v11 = 1;
          goto LABEL_38;
        }
        v12 = v29[0];
        if ( v29[0] >= 20001LL )
          goto LABEL_81;
        v25 = *(_DWORD *)(v5 + 260);
        result = a4;
        *(_DWORD *)(v5 + 188) = v29[0];
        if ( v25 != 2 )
          goto LABEL_6;
      }
      v10 = 1;
      v11 = 1;
      goto LABEL_38;
    }
    v12 = v29[0];
    if ( v29[0] >= 20001LL )
      goto LABEL_81;
    v11 = 0;
    *(_DWORD *)(v5 + 72) = v29[0];
    goto LABEL_36;
  }
  result = (int)result;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
