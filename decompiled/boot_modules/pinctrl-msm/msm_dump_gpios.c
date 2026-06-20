__int64 __fastcall msm_dump_gpios(__int64 a1, int a2, __int64 a3)
{
  unsigned __int64 v4; // x22
  __int64 v5; // x25
  unsigned int v6; // w27
  __int64 data; // x0
  __int64 v8; // x20
  unsigned int v9; // w0
  unsigned int v10; // w28
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x20
  unsigned int v14; // w27
  unsigned int v15; // w0
  unsigned __int64 v16; // x21
  unsigned int v17; // w20
  __int64 v18; // x0
  __int64 v19; // x23
  unsigned int v20; // w0
  const char *v21; // x2
  char v22; // w8
  const char *v23; // x3
  unsigned int v24; // w27
  __int64 v25; // x20
  __int64 v26; // x21
  signed int v27; // w8
  bool v28; // cf
  const char *v29; // x2
  unsigned int v30; // w20
  __int64 v31; // x0
  __int64 v32; // x21
  unsigned int v33; // w0
  _BYTE v37[12]; // [xsp+14h] [xbp-7Ch]
  char s[8]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v39; // [xsp+28h] [xbp-68h]
  __int64 v40; // [xsp+30h] [xbp-60h]
  __int64 v41; // [xsp+38h] [xbp-58h]
  __int64 v42; // [xsp+40h] [xbp-50h]
  __int64 v43; // [xsp+48h] [xbp-48h]
  __int64 v44; // [xsp+50h] [xbp-40h]
  __int64 v45; // [xsp+58h] [xbp-38h]
  __int64 v46; // [xsp+60h] [xbp-30h]
  __int64 v47; // [xsp+68h] [xbp-28h]
  __int64 v48; // [xsp+70h] [xbp-20h]
  __int64 v49; // [xsp+78h] [xbp-18h]
  int v50; // [xsp+80h] [xbp-10h]
  __int64 v51; // [xsp+88h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    *(_DWORD *)v37 = a2;
    seq_printf(a1, "%s\n", "------------ MSM GPIO -------------");
  }
  else
  {
    printk(&unk_D6FC, "------------ MSM GPIO -------------");
    *(_DWORD *)v37 = snprintf((char *)(a3 + a2), 0x64u, "%s\n", "------------ MSM GPIO -------------") + a2;
  }
  if ( *(_WORD *)(chip_debug + 172) )
  {
    v4 = 0;
    v5 = -8288;
    *(_QWORD *)&v37[4] = a1;
    do
    {
      v50 = 0;
      v48 = 0;
      v49 = 0;
      v46 = 0;
      v47 = 0;
      v44 = 0;
      v45 = 0;
      v42 = 0;
      v43 = 0;
      v40 = 0;
      v41 = 0;
      *(_QWORD *)s = 0;
      v39 = 0;
      if ( (unsigned int)(v4 - 36) <= 0x26 && ((1LL << ((unsigned __int8)v4 - 36)) & 0x40000000FFLL) != 0
        || (unsigned int)v4 < 4 )
      {
        printk(&unk_D634, (unsigned int)v4);
        if ( v5 )
        {
LABEL_13:
          if ( (v4 & 0x7FFFFFFC) != 0x28 && v4 >= 4 && (v4 & 0x7FFFFFFC) != 0x24 )
          {
            v6 = snprintf(s, 0x64u, "GPIO[%3d]: ", v4);
            data = gpiochip_get_data(chip_debug);
            v8 = *(_QWORD *)(*(_QWORD *)(data + 968) + 32LL) + v5;
            v9 = readl(*(_QWORD *)(data + 8 * ((*(_QWORD *)(v8 + 8372) >> 5) & 3LL) + 976) + *(unsigned int *)(v8 + 8348));
            if ( v6 > 0x64 )
              goto LABEL_41;
            v10 = snprintf(&s[v6], 100 - v6, "[FS]0x%x, ", (v9 >> (*(_DWORD *)(v8 + 8372) >> 7)) & 7) + v6;
            v11 = gpiochip_get_data(chip_debug);
            v12 = v11 + 976;
            v13 = *(_QWORD *)(*(_QWORD *)(v11 + 968) + 32LL) + v5;
            v14 = readl(*(_QWORD *)(v11 + 976 + 8 * ((*(_QWORD *)(v13 + 8372) >> 5) & 3LL)) + *(unsigned int *)(v13 + 8348));
            v15 = readl(*(_QWORD *)(v12 + 8 * ((*(_QWORD *)(v13 + 8372) >> 5) & 3LL)) + *(unsigned int *)(v13 + 8352));
            v16 = *(_QWORD *)(v13 + 8372);
            v17 = v15;
            v18 = gpiochip_get_data(chip_debug);
            v19 = *(_QWORD *)(*(_QWORD *)(v18 + 968) + 32LL) + v5;
            v20 = readl(*(_QWORD *)(v18 + 8 * ((*(_QWORD *)(v19 + 8372) >> 5) & 3LL) + 976) + *(unsigned int *)(v19 + 8348));
            if ( v10 > 0x64 )
              goto LABEL_41;
            if ( (((unsigned __int64)v20 >> ((*(_QWORD *)(v19 + 8372) >> 42) & 0x1F)) & 1) != 0 )
              v21 = "[DIR]OUT, [VAL]%s ";
            else
              v21 = "[DIR] IN, [VAL]%s ";
            v22 = 52;
            if ( ((v14 >> ((v16 >> 42) & 0x1F)) & 1LL) == 0 )
              v22 = 47;
            if ( ((v17 >> ((v16 >> v22) & 0x1F)) & 1LL) != 0 )
              v23 = "HIGH";
            else
              v23 = " LOW";
            v24 = snprintf(&s[v10], 100 - v10, v21, v23) + v10;
            v25 = gpiochip_get_data(chip_debug);
            v26 = *(_QWORD *)(*(_QWORD *)(v25 + 968) + 32LL) + v5;
            v27 = ((unsigned int)readl(
                                   *(_QWORD *)(v25 + 8 * ((*(_QWORD *)(v26 + 8372) >> 5) & 3LL) + 976)
                                 + *(unsigned int *)(v26 + 8348)) >> (*(_DWORD *)(v26 + 8372) >> 12))
                & 3;
            if ( (*(_BYTE *)(*(_QWORD *)(v25 + 968) + 48LL) & (v27 == 2)) != 0 )
              v27 = 3;
            if ( v27 > 1 )
            {
              v28 = v24 >= 0x65;
              v29 = v27 == 2 ? "[PULL]KP, " : "[PULL]PU, ";
            }
            else
            {
              v28 = v24 >= 0x65;
              v29 = v27 ? "[PULL]PD, " : "[PULL]NO, ";
            }
            if ( v28
              || (v30 = snprintf(&s[v24], 100 - v24, v29) + v24,
                  v31 = gpiochip_get_data(chip_debug),
                  v32 = *(_QWORD *)(*(_QWORD *)(v31 + 968) + 32LL) + v5,
                  v33 = readl(
                          *(_QWORD *)(v31 + 8 * ((*(_QWORD *)(v32 + 8372) >> 5) & 3LL) + 976)
                        + *(unsigned int *)(v32 + 8348)),
                  v30 > 0x64) )
            {
LABEL_41:
              __break(0x5512u);
            }
            snprintf(&s[v30], 100 - v30, "[DRV]%2dmA, ", 2 * ((v33 >> (*(_DWORD *)(v32 + 8372) >> 17)) & 7) + 2);
            HIBYTE(v50) = 0;
            if ( *(_QWORD *)&v37[4] )
            {
              seq_printf(*(_QWORD *)&v37[4], "%s\n", s);
            }
            else
            {
              printk(&unk_D6FC, s);
              *(_QWORD *)v37 = (unsigned int)(snprintf((char *)(a3 + *(int *)v37), 0x64u, "%s\n", s) + *(_DWORD *)v37);
            }
          }
        }
      }
      else if ( v5 )
      {
        goto LABEL_13;
      }
      ++v4;
      v5 += 112;
    }
    while ( v4 < *(unsigned __int16 *)(chip_debug + 172) );
  }
  _ReadStatusReg(SP_EL0);
  return *(unsigned int *)v37;
}
