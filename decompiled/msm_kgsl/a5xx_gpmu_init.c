unsigned __int64 __fastcall a5xx_gpmu_init(_QWORD *a1)
{
  _DWORD *v1; // x21
  _QWORD *v3; // x22
  __int64 v4; // x23
  __int64 v5; // x24
  __int64 v6; // x8
  int *v7; // x26
  __int64 v8; // x8
  int v9; // w9
  __int64 v10; // x8
  int v11; // w21
  unsigned int v12; // w21
  int v13; // w8
  int v14; // w8
  int *v15; // x21
  int v16; // w8
  int *v17; // x21
  _QWORD *v18; // x0
  __int64 v19; // x1
  int v20; // w0
  int v21; // w8
  __int64 v22; // x21
  __int64 v23; // x20
  unsigned __int64 result; // x0
  int v25; // w8
  int v26; // w23
  int v27; // w0
  int v28; // w0
  __int64 v29; // x1
  __int64 v30; // x0
  __int64 v31; // x20
  __int64 v32; // x0
  unsigned __int64 v39; // x9

  v1 = (_DWORD *)a1[1783];
  v3 = a1 + 2554;
  if ( *v1 == 540 )
  {
    if ( *((_BYTE *)a1 + 20435) )
      v11 = 0x1000000;
    else
      v11 = 16777728;
    v12 = v11 & 0xFFF9FFFF | ((a1[1781] & 3) << 17);
    if ( *(_BYTE *)v3 == 1 )
    {
      if ( (kgsl_regmap_read(a1 + 1650) & 0xF) == 1 )
      {
        dev_err(*a1, "GPMU: ISENSE end point calibration failure\n");
        v13 = 49;
      }
      else
      {
        v13 = 17;
      }
      v12 |= v13;
    }
    kgsl_regmap_write(a1 + 1650, 2147483649LL);
    kgsl_regmap_write(a1 + 1650, 1);
    write_voltage_table(a1);
    kgsl_regmap_write(a1 + 1650, v12);
    kgsl_regmap_write(a1 + 1650, 4294770684LL);
    kgsl_regmap_write(a1 + 1650, 144);
    kgsl_regmap_write(a1 + 1650, 3133078222LL);
    kgsl_regmap_write(a1 + 1650, *((_DWORD *)a1 + 2510) | 0x80000000);
    v15 = (int *)v3 + 51;
    v14 = *((_DWORD *)v3 + 51);
    if ( !v14 )
    {
      if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1[1396] + 760LL), "qcom,lm-limit", (char *)v3 + 204, 1, 0)
          & 0x80000000) != 0 )
      {
        v14 = 6000;
        *v15 = 6000;
      }
      else
      {
        v14 = *v15;
      }
    }
    kgsl_regmap_write(a1 + 1650, v14 | 0x80000000);
    v18 = a1 + 1650;
    v19 = 1;
    goto LABEL_34;
  }
  if ( *v1 == 530 && *(_BYTE *)v3 == 1 )
  {
    v4 = a1[2559];
    if ( v4 )
    {
      v5 = *((unsigned int *)a1 + 5120);
      if ( (_DWORD)v5 )
      {
        v6 = 0;
        v7 = (int *)a1[2559];
        do
        {
          v9 = *v7;
          v10 = v5 - v6;
          if ( *v7 == 1 && v10 >= 4 )
          {
            kgsl_regmap_write(a1 + 1650, (unsigned int)v7[3]);
            v8 = 16;
          }
          else if ( v9 == 2 && v10 >= 5 )
          {
            kgsl_regmap_write(a1 + 1650, (unsigned int)v7[3]);
            v8 = 20;
          }
          else
          {
            if ( v9 != 3 || v10 < 2 )
            {
              v32 = *a1;
              a1[2559] = 0;
              dev_warn(v32, "Invalid LM sequence\n");
              goto LABEL_35;
            }
            _udelay((unsigned int)v7[1]);
            v8 = 8;
          }
          v7 = (int *)((char *)v7 + v8);
          v6 = ((__int64)v7 - v4) >> 2;
        }
        while ( v6 < v5 );
      }
      kgsl_regmap_write(a1 + 1650, (unsigned int)v1[22]);
      kgsl_regmap_write(a1 + 1650, 1);
      kgsl_regmap_write(a1 + 1650, 1);
      kgsl_regmap_write(a1 + 1650, *((_DWORD *)a1 + 2510) | 0x80000000);
      kgsl_regmap_write(a1 + 1650, *((unsigned int *)v3 + 50));
      v17 = (int *)v3 + 51;
      v16 = *((_DWORD *)v3 + 51);
      if ( !v16 )
      {
        if ( (of_property_read_variable_u32_array(
                *(_QWORD *)(a1[1396] + 760LL),
                "qcom,lm-limit",
                (char *)v3 + 204,
                1,
                0)
            & 0x80000000) != 0 )
        {
          v16 = 6000;
          *v17 = 6000;
        }
        else
        {
          v16 = *v17;
        }
      }
      kgsl_regmap_write(a1 + 1650, v16 | 0x80000000);
      kgsl_regmap_write(a1 + 1650, 268443647);
      kgsl_regmap_write(a1 + 1650, 2105329);
      kgsl_regmap_write(a1 + 1650, 1);
      kgsl_regmap_write(a1 + 1650, 1);
      v20 = write_voltage_table(a1);
      kgsl_regmap_write(a1 + 1650, (unsigned int)(4 * v20));
      v18 = a1 + 1650;
      v19 = 3133078222LL;
LABEL_34:
      kgsl_regmap_write(v18, v19);
    }
  }
LABEL_35:
  if ( *((_BYTE *)v3 + 4) == 1 )
  {
    kgsl_regmap_write(a1 + 1650, 127);
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 655488);
    kgsl_regmap_write(a1 + 1650, 6291520);
  }
  v21 = *(_DWORD *)a1[1783];
  if ( v21 != 540 && v21 != 530 )
  {
LABEL_54:
    if ( *(_DWORD *)a1[1783] != 530 || *(_BYTE *)v3 != 1 || !a1[2559] )
      return 0;
    kgsl_regmap_write(a1 + 1650, 0);
    kgsl_regmap_write(a1 + 1650, 10);
    kgsl_regmap_write(a1 + 1650, 1);
    kgsl_regmap_write(a1 + 1650, 327680);
    kgsl_regmap_write(a1 + 1650, 196608);
    result = 0;
    if ( *(_DWORD *)a1[1783] == 530 )
    {
      if ( (unsigned __int8)*((_DWORD *)a1 + 3562) == 1 )
        v29 = 393233;
      else
        v29 = 17;
      kgsl_regmap_write(a1 + 1650, v29);
      return 0;
    }
    return result;
  }
  v22 = a1[1792];
  if ( !(_DWORD)v22 || !a1[1793] )
    return 4294967274LL;
  v23 = a1[2455];
  result = adreno_ringbuffer_allocspace(v23, (unsigned int)v22);
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( !result )
      return 4294967268LL;
    memcpy((void *)result, (const void *)a1[1793], (unsigned int)(4 * v22));
    result = a5xx_ringbuffer_submit(v23, 0, 1);
    if ( !(_DWORD)result )
    {
      v30 = adreno_spin_idle((__int64)a1, 0x7D0u);
      if ( (_DWORD)v30 )
      {
        v31 = v30;
        a5xx_spin_idle_debug(a1, "gpmu initialization failed to idle\n");
        return v31;
      }
      if ( *(_DWORD *)a1[1783] == 530 )
        kgsl_regmap_write(a1 + 1650, 16404);
      kgsl_regmap_write(a1 + 1650, 0);
      v25 = -5000;
      do
      {
        v26 = v25;
        _const_udelay(4295);
        v27 = kgsl_regmap_read(a1 + 1650);
        if ( v27 == -1161889074 )
          break;
        v25 = v26 + 1;
      }
      while ( v26 );
      if ( v27 != -1161889074 )
      {
        dev_err(*a1, "GPMU firmware initialization timed out\n");
        return 4294967186LL;
      }
      if ( *(_DWORD *)a1[1783] != 530 )
      {
        v28 = kgsl_regmap_read(a1 + 1650);
        if ( v28 )
        {
          dev_err(*a1, "GPMU firmware initialization failed: %d\n", v28);
          return 4294967291LL;
        }
      }
      _X8 = a1 + 1780;
      __asm { PRFM            #0x11, [X8] }
      do
        v39 = __ldxr(_X8);
      while ( __stxr(v39 | 0x800, _X8) );
      if ( (unsigned int)kgsl_regmap_read(a1 + 1650) )
        kgsl_regmap_write(a1 + 1650, 0x20000000);
      goto LABEL_54;
    }
  }
  return result;
}
