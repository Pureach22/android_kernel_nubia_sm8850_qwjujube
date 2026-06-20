__int64 __fastcall lpg_calc_freq(__int64 a1, unsigned __int64 a2)
{
  int v2; // w12
  __int64 v3; // x2
  __int64 v4; // x8
  int *v5; // x9
  unsigned __int64 v6; // x10
  _DWORD *v7; // x11
  bool v8; // zf
  unsigned __int64 v9; // x12
  __int64 v10; // x16
  __int64 v11; // x14
  int v12; // w21
  unsigned __int64 v13; // x13
  int v14; // w6
  int v15; // w15
  int v16; // w3
  unsigned __int64 v17; // x17
  __int64 v18; // x1
  unsigned int v19; // w2
  __int64 v20; // x27
  __int64 v21; // x28
  __int64 v22; // x12
  unsigned __int64 v23; // x22
  unsigned __int64 v24; // x23
  unsigned __int64 v25; // x24
  unsigned __int64 v26; // x25
  unsigned __int64 v27; // x29
  unsigned __int64 v28; // x12
  __int64 v29; // x30
  unsigned int v30; // w12
  unsigned int v31; // w8
  __int64 v33; // [xsp+8h] [xbp-68h]

  v2 = *(_DWORD *)(a1 + 20);
  if ( v2 == 12 )
    v3 = 20;
  else
    v3 = 16;
  if ( v2 == 12 )
    v4 = 5;
  else
    v4 = 4;
  v5 = lpg_clk_rates_hi_res;
  if ( v2 != 12 )
    v5 = lpg_clk_rates;
  v6 = 8;
  if ( v2 == 12 )
  {
    v6 = 32;
    v7 = &lpg_pwm_resolution_hi_res;
  }
  else
  {
    v7 = &lpg_pwm_resolution;
  }
  if ( v3 == 4 * v4 - 4 )
  {
LABEL_52:
    __break(1u);
    return lpg_apply(a1);
  }
  if ( 1000000000 * (unsigned __int64)(unsigned int)~(-1 << *v7) / (unsigned int)v5[v4 - 1] < a2 )
  {
    v8 = v2 == 12;
    v9 = 384000000000LL;
    v33 = a1;
    a1 = 8;
    if ( v8 )
    {
      v9 = 24576000000000LL;
      v10 = 8;
    }
    else
    {
      v10 = 2;
    }
    v11 = 0;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v16 = 0;
    if ( v9 >= a2 )
      v17 = a2;
    else
      v17 = v9;
    v18 = v3 - 4;
    v19 = -1;
LABEL_22:
    if ( v6 > 4 * v11 )
    {
      v20 = v18;
      v21 = 1;
      v22 = (unsigned int)~(-1 << v7[v11]);
      v23 = 5000000000LL * v22;
      v24 = 6000000000LL * v22;
      v25 = 1000000000LL * (unsigned int)v22;
      a1 = 3000000000LL;
      v26 = 3000000000LL * (unsigned int)v22;
      while ( v20 )
      {
        v27 = (unsigned int)v5[v21];
        v28 = v17 * v27;
        v29 = v27 - 1;
        if ( v17 * v27 >= v25 )
        {
          LODWORD(a1) = 63 - __clz(v28 / v25);
          a1 = (unsigned int)a1 >= 7 ? 7LL : (unsigned int)a1;
          if ( v19 > (unsigned int)v17 - (unsigned int)((v29 + (v25 << a1)) / v27) )
          {
            v15 = 0;
            v16 = v21;
            v14 = a1;
            v19 = v17 - (v29 + (v25 << a1)) / v27;
            v13 = (v29 + (v25 << a1)) / v27;
            v12 = v11;
          }
        }
        if ( v28 >= v26 )
        {
          LODWORD(a1) = 63 - __clz(v28 / v26);
          a1 = (unsigned int)a1 >= 7 ? 7LL : (unsigned int)a1;
          if ( v19 > (unsigned int)v17 - (unsigned int)((v29 + (v26 << a1)) / v27) )
          {
            v15 = 1;
            v16 = v21;
            v14 = a1;
            v19 = v17 - (v29 + (v26 << a1)) / v27;
            v13 = (v29 + (v26 << a1)) / v27;
            v12 = v11;
          }
        }
        if ( v28 >= v23 )
        {
          LODWORD(a1) = 63 - __clz(v28 / v23);
          a1 = (unsigned int)a1 >= 7 ? 7LL : (unsigned int)a1;
          if ( v19 > (unsigned int)v17 - (unsigned int)((v29 + (v23 << a1)) / v27) )
          {
            v15 = 2;
            v16 = v21;
            v14 = a1;
            v19 = v17 - (v29 + (v23 << a1)) / v27;
            v13 = (v29 + (v23 << a1)) / v27;
            v12 = v11;
          }
        }
        if ( v28 >= v24 )
        {
          v30 = 63 - __clz(v28 / v24);
          if ( v30 >= 7 )
            v30 = 7;
          a1 = (v29 + (v24 << v30)) / v27;
          if ( v19 > (int)v17 - (int)a1 )
          {
            v15 = 3;
            v16 = v21;
            v14 = v30;
            v19 = v17 - a1;
            v13 = (v29 + (v24 << v30)) / v27;
            v12 = v11;
          }
        }
        ++v21;
        v20 -= 4;
        if ( v4 == v21 )
        {
          if ( ++v11 != v10 )
            goto LABEL_22;
          v31 = 0;
          *(_DWORD *)(v33 + 56) = v16;
          *(_DWORD *)(v33 + 60) = v15;
          *(_QWORD *)(v33 + 48) = v13;
          *(_DWORD *)(v33 + 64) = v14;
          *(_DWORD *)(v33 + 68) = v12;
          return v31;
        }
      }
    }
    goto LABEL_52;
  }
  return (unsigned int)-22;
}
