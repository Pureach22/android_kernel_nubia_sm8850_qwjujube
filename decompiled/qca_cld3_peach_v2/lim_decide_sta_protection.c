__int64 __fastcall lim_decide_sta_protection(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _BYTE *v14; // x23
  int v15; // w8
  unsigned int v16; // w8
  __int64 v17; // x22
  __int64 v18; // x21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  char v28; // w1
  __int64 v29; // x22
  char v30; // w1
  __int64 v31; // x21
  int v32; // w22
  __int64 v33; // x24
  __int64 v34; // x21
  __int64 v35; // x24
  char v36; // w21
  __int64 v37; // x21
  __int64 v38; // x22
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w9
  unsigned int v48; // w8
  __int16 v49; // w11
  __int16 v50; // w11
  int v51; // w9
  __int16 v52; // w10
  int v53; // w8

  v14 = (_BYTE *)(a4 + 4096);
  if ( a4 )
  {
    v15 = *(_DWORD *)(a4 + 168);
    if ( v15 )
    {
      if ( v15 == 1 && *(_BYTE *)(a4 + 155) == 1 && *(_BYTE *)(a2 + 1260) )
      {
        v16 = (*(_DWORD *)(a2 + 1262) >> 8) & 3;
        if ( v16 > 1 )
        {
          if ( v16 == 2 )
          {
            v17 = a2;
            v37 = result;
            lim_update_11a_protection(result, 0, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
            v27 = v37;
            v28 = 1;
            goto LABEL_26;
          }
          v17 = a2;
        }
        else
        {
          v17 = a2;
          if ( !v16 )
          {
            v18 = result;
            lim_update_11a_protection(result, 0, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
            v27 = v18;
            v28 = 0;
LABEL_26:
            result = lim_enable_ht20_protection(v27, v28, 0, a3, a4, v19, v20, v21, v22, v23, v24, v25, v26);
            a2 = v17;
            goto LABEL_31;
          }
        }
        result = lim_update_11a_protection(result, 1, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
        a2 = v17;
      }
    }
    else
    {
      if ( *(_DWORD *)(a4 + 7232) != 1 )
      {
        if ( *(_BYTE *)(a2 + 2475) && (*(_BYTE *)(a2 + 1132) & 3) != 0 )
        {
          v29 = a2;
          v30 = 1;
        }
        else
        {
          v29 = a2;
          v30 = 0;
        }
        v31 = result;
        lim_enable11g_protection(result, v30, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
        result = v31;
        a2 = v29;
      }
      if ( *(_BYTE *)(a4 + 155) && *(_BYTE *)(a2 + 1260) )
      {
        v32 = (*(_DWORD *)(a2 + 1262) >> 8) & 3;
        if ( ((*(_DWORD *)(a2 + 1262) >> 8) & 1 | 2) == 3 && !v14[3066] )
        {
          v33 = a2;
          v34 = result;
          lim_enable_ht_protection_from11g(result, 1, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
          result = v34;
          a2 = v33;
        }
        if ( *(_DWORD *)(result + 12232) != v32 )
        {
          *(_DWORD *)(result + 12232) = v32;
          if ( v32 == 2 )
          {
            v35 = a2;
            v36 = 1;
          }
          else
          {
            if ( v32 )
              goto LABEL_31;
            v35 = a2;
            v36 = 0;
          }
          v38 = result;
          lim_enable_ht_protection_from11g(result, 0, 0, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
          result = lim_enable_ht20_protection(v38, v36, 0, a3, a4, v39, v40, v41, v42, v43, v44, v45, v46);
          a2 = v35;
        }
      }
    }
  }
LABEL_31:
  if ( *(_BYTE *)(a4 + 155) && *(_BYTE *)(a2 + 1260) )
  {
    v47 = *(unsigned __int16 *)(a2 + 1266);
    v48 = *(_DWORD *)(a2 + 1262);
    if ( v14[3070] != ((v48 >> 3) & 1) )
    {
      v14[3070] = (*(_DWORD *)(a2 + 1262) & 8) != 0;
      v49 = *(_WORD *)(a3 + 14);
      *(_BYTE *)(a3 + 12) = (v48 & 8) != 0;
      *(_WORD *)(a3 + 14) = v49 | 0x100;
    }
    if ( ((v48 >> 10) & 1) != v14[3069] )
    {
      v14[3069] = (v48 & 0x400) != 0;
      v50 = *(_WORD *)(a3 + 14);
      *(_BYTE *)(a3 + 10) = (v48 & 0x400) != 0;
      *(_WORD *)(a3 + 14) = v50 | 0x80;
    }
    v51 = (v47 >> 9) & 1;
    if ( (unsigned __int8)v14[3071] != v51 )
    {
      v14[3071] = v51;
      v52 = *(_WORD *)(a3 + 14);
      *(_BYTE *)(a3 + 11) = v51;
      *(_WORD *)(a3 + 14) = v52 | 0x200;
    }
    v53 = (v48 >> 12) & 1;
    if ( (unsigned __int8)v14[3072] != v53 )
      v14[3072] = v53;
  }
  return result;
}
