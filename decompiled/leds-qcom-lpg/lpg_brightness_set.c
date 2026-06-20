__int64 __fastcall lpg_brightness_set(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  unsigned int v4; // w27
  unsigned int v5; // w20
  unsigned int v6; // w21
  __int64 v7; // x28
  int v8; // w8
  __int64 *v9; // x25
  __int64 v10; // x24
  int v11; // w19
  int v12; // w26
  __int64 v13; // x12
  __int64 v14; // x13
  char *v15; // x10
  unsigned __int64 v16; // x15
  int *v17; // x11
  unsigned __int64 v18; // x16
  __int64 v19; // x8
  __int64 v20; // x0
  int v21; // w9
  __int64 v22; // x14
  unsigned __int64 v23; // x12
  unsigned __int64 v24; // x9
  char v25; // w8
  __int64 v26; // x10
  bool v27; // cf
  int v28; // w8
  int v29; // w8
  __int64 v30; // x8
  __int64 v31; // [xsp+0h] [xbp-30h]
  unsigned int v33; // [xsp+14h] [xbp-1Ch]
  char v35[4]; // [xsp+20h] [xbp-10h] BYREF
  _BYTE v36[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(result + 920) )
  {
    v3 = result;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v7 = result + 928;
    v33 = 0;
    v31 = *(_QWORD *)result;
    do
    {
      v9 = *(__int64 **)(v7 + 8LL * (int)v4);
      v10 = *(unsigned int *)(a3 + 16LL * (int)v4 + 4);
      if ( (_DWORD)v10 )
      {
        v11 = *((_DWORD *)v9 + 24);
        v12 = *((_DWORD *)v9 + 25);
        lpg_calc_freq(*(_QWORD *)(v7 + 8LL * (int)v4), 1000000);
        if ( v11 == v12 )
        {
          v13 = *((unsigned int *)v9 + 17);
          if ( *((_DWORD *)v9 + 5) == 12 )
          {
            if ( (unsigned int)v13 >= 8 )
              goto LABEL_42;
            v14 = *((unsigned int *)v9 + 14);
            if ( (unsigned int)v14 > 4 )
              goto LABEL_42;
            v15 = (char *)&lpg_pwm_resolution_hi_res + 4 * v13;
            v16 = 20;
            v17 = &lpg_clk_rates_hi_res[v14];
            v18 = 32;
          }
          else
          {
            if ( (unsigned int)v13 > 1 )
              goto LABEL_42;
            v14 = *((unsigned int *)v9 + 14);
            if ( (unsigned int)v14 > 3 )
              goto LABEL_42;
            v15 = (char *)&lpg_pwm_resolution + 4 * v13;
            v16 = 16;
            v17 = &lpg_clk_rates[v14];
            v18 = 8;
          }
          v22 = *((unsigned int *)v9 + 15);
          if ( (unsigned int)v22 > 3 )
            goto LABEL_42;
          if ( v16 <= 4 * v14 || (v23 = 4 * v13, v18 <= v23) || v16 <= 4 * v14 || v18 <= v23 )
          {
            __break(1u);
LABEL_42:
            __break(0x5512u);
          }
          v24 = (unsigned int)(v9[6] * v10 / (unsigned __int64)*(unsigned int *)(a2 + 12))
              * (unsigned __int64)(unsigned int)*v17
              / (1000000000
               * (unsigned __int64)lpg_pre_divs[v22]
               * (1 << *((_DWORD *)v9 + 16)));
          v25 = *(_DWORD *)v15;
          *((_BYTE *)v9 + 46) = 1;
          v26 = -1LL << v25;
          *((_BYTE *)v9 + 72) = 0;
          v27 = (unsigned int)v24 >= ~(unsigned int)(-1LL << v25);
          v8 = *((_DWORD *)v9 + 3);
          if ( v27 )
            LOWORD(v24) = ~(_WORD)v26;
          *((_WORD *)v9 + 22) = v24;
        }
        else
        {
          v19 = *v9;
          v35[0] = 1;
          v20 = *(_QWORD *)(v19 + 104);
          if ( v20 )
            nvmem_device_write(v20, *((unsigned int *)v9 + 6), 1, v35);
          v8 = *((_DWORD *)v9 + 3);
          v21 = *((_DWORD *)v9 + 4);
          *((_BYTE *)v9 + 46) = 1;
          *((_BYTE *)v9 + 72) = 1;
          v33 |= v21;
        }
        v6 |= v8;
      }
      else
      {
        v8 = *((_DWORD *)v9 + 3);
        *((_BYTE *)v9 + 46) = 0;
        *((_BYTE *)v9 + 72) = 0;
      }
      v5 |= v8;
      result = lpg_apply(v9);
      ++v4;
    }
    while ( v4 < *(_DWORD *)(v3 + 920) );
    if ( v5 )
    {
      v28 = *(_DWORD *)(v31 + 128);
      if ( v28 )
        result = regmap_update_bits_base(*(_QWORD *)(v31 + 8), (unsigned int)(v28 + 70), v5, v6, 0, 0, 0);
    }
    if ( v33 )
    {
      v29 = *(_DWORD *)(v31 + 80);
      if ( v29 )
        regmap_write(*(_QWORD *)(v31 + 8), (unsigned int)(v29 + 200), v33);
      result = *(_QWORD *)(v31 + 104);
      v36[0] = 1;
      if ( result )
      {
        v30 = *(_QWORD *)(v31 + 120);
        if ( v30 )
        {
LABEL_35:
          *(_QWORD *)(v31 + 120) = v30 | v33;
          goto LABEL_36;
        }
        result = nvmem_device_write(result, 66, 1, v36);
        if ( (result & 0x80000000) == 0 )
        {
          if ( *(_QWORD *)(v31 + 112) )
          {
            result = nvmem_device_write(*(_QWORD *)(v31 + 104), 229, 1, v36);
            if ( (result & 0x80000000) == 0 )
            {
              v30 = *(_QWORD *)(v31 + 120);
              goto LABEL_35;
            }
          }
        }
      }
    }
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
