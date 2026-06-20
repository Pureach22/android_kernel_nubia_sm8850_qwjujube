__int64 __fastcall simple_amp_temperature_work(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 *v3; // x24
  int v4; // w22
  __int64 v5; // x25
  unsigned int v6; // w27
  int v7; // w0
  int v8; // w28
  int v9; // w0
  int v10; // w23
  int v11; // w3
  int v12; // w0
  int v13; // w4
  int v14; // w5
  int v15; // w6
  int v16; // w10
  int v17; // w9
  int v18; // w8
  int v19; // w23
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 result; // x0
  __int64 v23; // x3
  __int64 *v24; // [xsp+0h] [xbp-40h]
  __int64 *v25; // [xsp+8h] [xbp-38h]
  __int64 *v26; // [xsp+10h] [xbp-30h]
  _QWORD *v27; // [xsp+18h] [xbp-28h]
  __int64 v28; // [xsp+20h] [xbp-20h] BYREF
  __int64 v29; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v30[2]; // [xsp+30h] [xbp-10h] BYREF

  v2 = (_QWORD *)(a1 - 536);
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30[0] = 0;
  v27 = (_QWORD *)(a1 - 528);
  v28 = 0;
  if ( a1 != 536 )
  {
    v3 = (__int64 *)(a1 - 488);
    v25 = (__int64 *)(a1 - 472);
    v26 = (__int64 *)(a1 - 480);
    v4 = 3;
    v24 = (__int64 *)(a1 - 464);
    while ( 1 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        v6 = 0;
      }
      else
      {
        v5 = *v26;
        if ( *v26 )
        {
          v6 = 1;
        }
        else
        {
          v5 = *v25;
          if ( *v25 )
          {
            v6 = 2;
          }
          else
          {
            v5 = *v24;
            if ( !*v24 )
            {
              if ( (unsigned int)__ratelimit(&simple_amp_temp_reg_read__rs_179, "simple_amp_temp_reg_read") )
                printk(&unk_C37B, "simple_amp_temp_reg_read", 4, v23);
              goto LABEL_39;
            }
            v6 = 3;
          }
        }
      }
      regmap_write(
        *v2,
        (*(_DWORD *)(v5 + 288) << 15) & 0x200000 | ((*(_WORD *)(v5 + 288) & 0x3F) << 7) | ((v6 & 3) << 22) | 0x40000008);
      if ( (unsigned int)wait_for_pde_state(v2, *(unsigned int *)(v5 + 288), *(unsigned int *)(v5 + 96), 0, v6) )
      {
        dev_err(*v27, "PS0 request failed\n");
        goto LABEL_39;
      }
      v7 = regmap_read(*v2, 1079510098, v30);
      if ( v7 )
      {
        v10 = v7;
        v8 = 1079510098;
      }
      else
      {
        v8 = 1079510099;
        v9 = regmap_read(*v2, 1079510099, (char *)v30 + 4);
        if ( !v9 )
        {
          v8 = 1079511169;
          v9 = regmap_read(*v2, 1079511169, &v28);
          if ( !v9 )
          {
            v8 = 1079511170;
            v9 = regmap_read(*v2, 1079511170, (char *)&v28 + 4);
            if ( !v9 )
            {
              v8 = 1079511171;
              v9 = regmap_read(*v2, 1079511171, &v29);
              if ( !v9 )
              {
                v8 = 1079511172;
                v9 = regmap_read(*v2, 1079511172, (char *)&v29 + 4);
                if ( !v9 )
                {
                  v10 = 0;
                  goto LABEL_21;
                }
              }
            }
          }
        }
        v10 = v9;
      }
      dev_err(*v27, "%s: Regmap read failed for reg %u: %d\n", "simple_amp_temp_reg_read", v8, v10);
LABEL_21:
      regmap_write(
        *v2,
        (*(_DWORD *)(v5 + 288) << 15) & 0x200000 | ((*(_DWORD *)(v5 + 288) & 0x3F) << 7) | (v6 << 22) | 0x40000008);
      if ( (unsigned int)wait_for_pde_state(v2, *(unsigned int *)(v5 + 288), *(unsigned int *)(v5 + 96), 3, v6) )
      {
        dev_err(*v27, "PS3 request failed\n");
        goto LABEL_39;
      }
      if ( v10 )
        goto LABEL_40;
      v11 = v28;
      if ( (unsigned int)(v28 - 93) < 0xFFFFFFE7
        || (v13 = HIDWORD(v28), (v28 & 0xFFFFFF3F00000000LL) != 0)
        || (v14 = v29, (unsigned int)(v29 - 219) < 0xFFFFFFDE)
        || (v15 = HIDWORD(v29), (unsigned int)(__PAIR64__(HIDWORD(v29), HIDWORD(v29)) >> 6) >= 4) )
      {
        v12 = __ratelimit(&simple_amp_temperature_work__rs_175, "simple_amp_temperature_work");
        v11 = v28;
        v13 = HIDWORD(v28);
        v14 = v29;
        v15 = HIDWORD(v29);
        if ( v12 )
        {
          dev_err(
            *v27,
            "%s: Temperature registers[%d %d %d %d] are out of range\n",
            "simple_amp_temperature_work",
            v28,
            HIDWORD(v28),
            v29,
            HIDWORD(v29));
          v11 = v28;
          v13 = HIDWORD(v28);
          v14 = v29;
          v15 = HIDWORD(v29);
        }
      }
      v16 = v15 | (v14 << 8);
      v17 = (v13 | (v11 << 8)) >> 6;
      if ( v16 >> 6 == v17 )
      {
        v19 = 0xFFFF;
      }
      else
      {
        v18 = 160 * (((HIDWORD(v30[0]) | (LODWORD(v30[0]) << 8)) >> 6) - v17) / ((v16 >> 6) - v17);
        v19 = v18 - 10;
        if ( (unsigned int)(v18 - 55) > 0xFFFFFFD8 )
          goto LABEL_36;
      }
      dev_err(*v27, "%s: T0: %d is out of range[%d, %d]\n", "simple_amp_temperature_work", v19, 5, 45);
      --v4;
      msleep(10);
      if ( !(_BYTE)v4 )
      {
LABEL_36:
        *(_DWORD *)(a1 + 64) = v19;
        goto LABEL_42;
      }
    }
  }
  if ( (unsigned int)__ratelimit(&simple_amp_temp_reg_read__rs, "simple_amp_temp_reg_read") )
    printk(&unk_C254, "simple_amp_temp_reg_read", v20, v21);
LABEL_39:
  v10 = -22;
LABEL_40:
  if ( (unsigned int)__ratelimit(&simple_amp_temperature_work__rs, "simple_amp_temperature_work") )
    dev_err(
      *v27,
      "%s: temp read failed: %d, current temp: %d\n",
      "simple_amp_temperature_work",
      v10,
      *(_DWORD *)(a1 + 64));
LABEL_42:
  result = complete(a1 + 32);
  _ReadStatusReg(SP_EL0);
  return result;
}
