__int64 __fastcall sde_enc_phys_wb_get_out_resolution(__int64 a1, __int64 a2, int *a3, _DWORD *a4)
{
  __int64 v4; // x19
  unsigned int v7; // w8
  int v8; // w25
  int v9; // w9
  _BOOL4 v10; // w24
  int v11; // w23
  int v12; // w27
  int v13; // w28
  int v14; // w26
  int v15; // w8
  int v18; // w20
  char v19; // w27
  int v20; // w26
  int v21; // w25
  __int64 v22; // x22
  __int64 result; // x0
  int *v26; // x11
  _DWORD *v27; // x10
  bool v28; // w8
  __int64 v29; // x9
  int v30; // w8
  int v31; // [xsp+0h] [xbp-10h]
  int v32; // [xsp+4h] [xbp-Ch]
  int v33; // [xsp+8h] [xbp-8h]
  int v34; // [xsp+Ch] [xbp-4h]

  v4 = *(_QWORD *)a1;
  if ( !a1 )
  {
    v10 = 0;
    v11 = 0;
    v13 = 0;
    v12 = 0;
    v14 = 0;
    v8 = 0;
    goto LABEL_18;
  }
  v7 = *(_DWORD *)(a1 + 2044);
  v8 = *(_DWORD *)(a1 + 1472);
  if ( !v7 )
  {
    v10 = 0;
    v11 = 0;
    v13 = 0;
    v12 = 0;
    v14 = 0;
    goto LABEL_18;
  }
  v9 = *(_DWORD *)(a1 + 2080);
  v10 = v9 != 0;
  if ( v9 )
  {
    v11 = *(_DWORD *)(a1 + 2064);
    v12 = *(_DWORD *)(a1 + 2224);
    v13 = *(_DWORD *)(a1 + 2068);
    v14 = *(_DWORD *)(a1 + 2228);
    if ( v7 == 1 )
      goto LABEL_18;
  }
  else
  {
    v11 = 0;
    v13 = 0;
    v12 = 0;
    v14 = 0;
    if ( v7 == 1 )
      goto LABEL_18;
  }
  if ( *(_DWORD *)(a1 + 2672) )
  {
    v10 = 1;
    v13 = *(_DWORD *)(a1 + 2660);
    v14 = *(_DWORD *)(a1 + 2820);
    v11 += *(_DWORD *)(a1 + 2656);
    v12 += *(_DWORD *)(a1 + 2816);
  }
  if ( v7 >= 3 )
  {
    if ( *(_DWORD *)(a1 + 3264) )
    {
      v10 = 1;
      v13 = *(_DWORD *)(a1 + 3252);
      v14 = *(_DWORD *)(a1 + 3412);
      v11 += *(_DWORD *)(a1 + 3248);
      v12 += *(_DWORD *)(a1 + 3408);
    }
    if ( v7 != 3 )
    {
      if ( *(_DWORD *)(a1 + 3856) )
      {
        v10 = 1;
        v13 = *(_DWORD *)(a1 + 3844);
        v14 = *(_DWORD *)(a1 + 4004);
        v11 += *(_DWORD *)(a1 + 3840);
        v12 += *(_DWORD *)(a1 + 4000);
      }
      if ( v7 > 4 )
        goto LABEL_43;
    }
  }
LABEL_18:
  if ( !a2 )
  {
    v22 = *(_QWORD *)a1;
    result = sde_cp_get_ai_scaler_io_res(a1, 0, (__int64)a3);
    v26 = a3;
    v27 = a4;
    v4 = v22;
    v28 = 1;
    if ( !v10 )
      goto LABEL_32;
    goto LABEL_23;
  }
  v15 = *(_DWORD *)(a2 + 3264);
  v32 = v13;
  v34 = v11;
  v33 = v8;
  v31 = v12;
  if ( !v15 || (*(_BYTE *)(a2 + 3272) & 1) == 0 )
  {
    v18 = v14;
    v19 = 0;
    v20 = 0;
    v21 = 0;
    goto LABEL_28;
  }
  if ( v15 != 1 )
  {
LABEL_43:
    __break(0x5512u);
    return sde_enc_phys_wb_validate_dnsc_blur_filter(a1, a2, a3);
  }
  v18 = v14;
  v20 = *(_DWORD *)(a2 + 3292);
  v21 = *(_DWORD *)(a2 + 3296);
  v19 = 1;
LABEL_28:
  result = sde_cp_get_ai_scaler_io_res(a1, a2, (__int64)a3);
  v29 = *(unsigned int *)(a2 + 1888);
  v28 = *(_DWORD *)(a2 + 1888) == 0;
  if ( (v19 & 1) != 0 )
  {
    v26 = a3;
    *a3 = v20;
    v14 = v21;
    v27 = a4;
    *a4 = v21;
    if ( !v29 )
      return result;
    goto LABEL_38;
  }
  v26 = a3;
  v27 = a4;
  v11 = v34;
  v13 = v32;
  v8 = v33;
  v12 = v31;
  v14 = v18;
  if ( !v10 )
  {
LABEL_32:
    if ( *(_BYTE *)(v4 + 7956) == 1 )
    {
      if ( !v8 )
      {
        *v26 = *(_DWORD *)(v4 + 7960);
        v14 = *(_DWORD *)(v4 + 7964);
LABEL_37:
        *v27 = v14;
        if ( v28 )
          return result;
        goto LABEL_38;
      }
      if ( v8 == 1 )
      {
        *v26 = *(_DWORD *)(v4 + 7968);
        v14 = *(_DWORD *)(v4 + 7972);
        goto LABEL_37;
      }
    }
LABEL_36:
    *v26 = *(unsigned __int16 *)(a1 + 148);
    v14 = *(unsigned __int16 *)(a1 + 158);
    goto LABEL_37;
  }
LABEL_23:
  if ( v8 )
  {
    if ( v8 == 1 )
    {
      *v26 = v12;
      goto LABEL_37;
    }
    goto LABEL_36;
  }
  v14 = v13;
  *v26 = v11;
  *v27 = v13;
  if ( !v28 )
  {
LABEL_38:
    v30 = *v26;
    *v26 = v14;
    *v27 = v30;
  }
  return result;
}
