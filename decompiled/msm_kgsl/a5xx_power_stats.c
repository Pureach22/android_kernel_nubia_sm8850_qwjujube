__int64 __fastcall a5xx_power_stats(
        __int64 *a1,
        unsigned __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  unsigned __int64 *v9; // x19
  __int64 *v10; // x20
  unsigned int *v11; // x24
  __int64 v12; // x25
  __int64 v13; // x26
  unsigned int v14; // w27
  unsigned __int64 v15; // x28
  unsigned int v16; // w8
  unsigned __int64 v17; // x22
  unsigned int v18; // w21
  __int64 result; // x0
  unsigned int v20; // w3
  int v21; // w8
  unsigned int v22; // w8
  int v23; // w21
  unsigned int v24; // w1
  unsigned int v25; // w8
  int v26; // w22
  unsigned int v27; // w1
  unsigned int v28; // w8
  int v29; // w23
  unsigned int v30; // w1
  unsigned int v31; // w8
  int v32; // w9
  bool v33; // cf
  unsigned int v34; // w8
  unsigned int v35; // w9
  unsigned int v36; // w4
  __int64 v37; // x8
  int v38; // w9
  unsigned int v39; // w9
  unsigned __int64 v40; // x8
  unsigned int v41; // w9
  unsigned __int64 v42; // x8
  __int64 v43; // x0

  v16 = *((_DWORD *)a1 + 2510);
  if ( v16 >= 0x20 )
  {
    __break(0x5512u);
    result = preempt_schedule_notrace(a1);
    v37 = a9;
  }
  else
  {
    v12 = 1650;
    v10 = a1;
    v9 = a2;
    v17 = 1125899907LL * *((unsigned int *)a1 + 7 * v16 + 2286);
    v11 = (unsigned int *)(a1 + 2542);
    v18 = kgsl_regmap_read(a1 + 1650);
    result = kgsl_regmap_read(v10 + 1650);
    v20 = *v11;
    if ( *v11 )
    {
      v14 = v18 - v20;
      if ( v18 < v20 )
      {
        if ( (_DWORD)result == a5xx_power_stats_rbbm0_hi )
        {
          if ( (a5xx_power_stats___print_once & 1) == 0 )
          {
            v43 = *v10;
            a5xx_power_stats___print_once = 1;
            result = dev_warn(v43, "abmormal value from RBBM_0 perfcounter: %x %x\n", v18, v20);
          }
          v14 = 0;
        }
        else
        {
          a5xx_power_stats_rbbm0_hi = result;
          v14 = v18 + ~v20;
        }
      }
    }
    else
    {
      v14 = 0;
      a5xx_power_stats_rbbm0_hi = 0;
    }
    v21 = *((unsigned __int8 *)v11 + 99);
    v15 = v17 >> 50;
    v13 = 1296;
    *v11 = v18;
    if ( v21 != 1 || !v11[104] )
      goto LABEL_31;
    result = kgsl_regmap_read(v10 + 1650);
    v22 = v11[8];
    if ( v22 )
    {
      v23 = result - v22;
      if ( (unsigned int)result < v22 )
        v23 = result + ~v22;
    }
    else
    {
      v23 = 0;
    }
    v24 = v11[105];
    v11[8] = result;
    if ( !v24 )
      goto LABEL_31;
    result = kgsl_regmap_read(v10 + 1650);
    v25 = v11[9];
    if ( v25 )
    {
      v26 = result - v25;
      if ( (unsigned int)result < v25 )
        v26 = result + ~v25;
    }
    else
    {
      v26 = 0;
    }
    v27 = v11[106];
    v11[9] = result;
    if ( !v27 )
      goto LABEL_31;
    result = kgsl_regmap_read(v10 + 1650);
    v28 = v11[10];
    if ( v28 )
    {
      v29 = result - v28;
      if ( (unsigned int)result < v28 )
        v29 = result + ~v28;
    }
    else
    {
      v29 = 0;
    }
    v30 = v11[107];
    v11[10] = result;
    if ( v30 )
    {
      result = kgsl_regmap_read(v10 + 1650);
      v31 = v11[11];
      if ( v31 )
      {
        v32 = ~v31;
        v33 = (unsigned int)result >= v31;
        v34 = result - v31;
        v35 = result + v32;
        if ( v33 )
          v36 = v34;
        else
          v36 = v35;
      }
      else
      {
        v36 = 0;
      }
      v11[11] = result;
      v37 = 3LL * (unsigned int)(v29 - v23) + v36 / 3 + v26;
    }
    else
    {
LABEL_31:
      v37 = 0;
    }
  }
  *v9 = (v37 + (unsigned __int64)v14) / v15;
  v38 = *(_DWORD *)v10[1783];
  if ( v38 == 540 )
  {
    v11[77] = v37;
  }
  else if ( v38 == 530 && v11[76] )
  {
    result = kgsl_regmap_read(&v10[v12]);
    v11[77] = result;
  }
  if ( LOBYTE(v10[v13]) == 1 )
  {
    if ( v11[13] )
    {
      result = kgsl_regmap_read(&v10[v12]);
      v39 = v11[1];
      if ( v39 )
      {
        LODWORD(v40) = result - v39;
        if ( (unsigned int)result < v39 )
          LODWORD(v40) = result + ~v39;
      }
      else
      {
        LODWORD(v40) = 0;
      }
      v40 = (unsigned int)v40;
      v11[1] = result;
    }
    else
    {
      v40 = 0;
    }
    v9[1] = v40;
    if ( v11[17] )
    {
      result = kgsl_regmap_read(&v10[v12]);
      v41 = v11[5];
      if ( v41 )
      {
        LODWORD(v42) = result - v41;
        if ( (unsigned int)result < v41 )
          LODWORD(v42) = result + ~v41;
      }
      else
      {
        LODWORD(v42) = 0;
      }
      v42 = (unsigned int)v42;
      v11[5] = result;
    }
    else
    {
      v42 = 0;
    }
    v9[2] = v42;
  }
  return result;
}
