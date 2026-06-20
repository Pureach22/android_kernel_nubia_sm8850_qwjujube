__int64 __fastcall cam_soc_util_clk_enable_default(_DWORD *a1, unsigned int a2, int a3)
{
  int v3; // w6
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x22
  unsigned __int64 v7; // x21
  __int64 v9; // x7
  __int64 v10; // x23
  int clk_level; // w0
  unsigned int v12; // w24
  int clk_level_to_apply; // w0
  unsigned int v14; // w19
  int v15; // w23
  int v16; // w8
  int v17; // w7
  unsigned int v18; // w22
  unsigned int v19; // w21
  const char *v20; // x22
  char *string_from_level; // x21
  char *v22; // x0
  unsigned int v23; // [xsp+20h] [xbp-10h] BYREF
  int v24; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_soc_util_clk_enable_default",
      2715,
      "Bypass clk enable default");
    result = 0;
    goto LABEL_19;
  }
  v3 = a1[217];
  v4 = (__int64)a1;
  if ( (unsigned int)(v3 - 32) <= 0xFFFFFFE0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_clk_enable_default",
      2722,
      "Invalid number of clock %d",
      v3);
    result = 4294967274LL;
    goto LABEL_19;
  }
  v6 = (unsigned int)a1[699];
  LODWORD(v7) = a3;
  if ( (v6 & 0x80000000) != 0 )
    goto LABEL_17;
  if ( (unsigned int)v6 > 0x1F )
    goto LABEL_17;
  v9 = (unsigned int)a1[820];
  if ( !(_DWORD)v9 )
    goto LABEL_17;
  if ( (unsigned int)v9 < 0xA )
  {
    v10 = (int)a1[32 * v9 + 346 + v6];
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_clk_enable_default",
        2734,
        "src_clk_idx: %d, override_high: %d, clk_rate_high: %lld",
        (unsigned int)v6);
    v23 = 0;
    clk_level = cam_soc_util_get_clk_level((_BYTE *)v4, v10, v6, (int *)&v23);
    v12 = v23;
    if ( clk_level || v23 >= 0xA )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_enable_default",
        2742,
        "set %s, rate %lld dev_name = %s apply level = %d",
        *(const char **)(v4 + 8 * v6 + 872),
        v10,
        *(const char **)(v4 + 24),
        v23);
    if ( v12 > (unsigned int)v7 )
      LODWORD(v7) = v12;
LABEL_17:
    v24 = 0;
    clk_level_to_apply = cam_soc_util_get_clk_level_to_apply(v4, v7, &v24);
    if ( clk_level_to_apply )
    {
      v14 = clk_level_to_apply;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_clk_enable_default",
        2753,
        "[%s] : failed to get level clk_level=%d, rc=%d",
        *(const char **)(v4 + 24),
        v7,
        clk_level_to_apply);
      result = v14;
      goto LABEL_19;
    }
    v15 = debug_mdl;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      v20 = *(const char **)(v4 + 24);
      string_from_level = cam_soc_util_get_string_from_level(v7);
      v22 = cam_soc_util_get_string_from_level(v24);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        *(_QWORD *)&v15 & 0x20000LL,
        4,
        "cam_soc_util_clk_enable_default",
        2763,
        "Dev[%s] : cesta client %d, request level %s, apply level %s",
        v20,
        a2,
        string_from_level,
        v22);
    }
    v16 = *(_DWORD *)(v4 + 868);
    *(_QWORD *)(v4 + 2848) = 0;
    *(_QWORD *)(v4 + 2840) = 0;
    *(_QWORD *)(v4 + 2832) = 0;
    *(_QWORD *)(v4 + 2824) = 0;
    *(_QWORD *)(v4 + 2816) = 0;
    *(_QWORD *)(v4 + 2808) = 0;
    *(_QWORD *)(v4 + 2800) = 0;
    if ( !v16 )
    {
      result = 0;
      goto LABEL_19;
    }
    LODWORD(v6) = v24;
    v7 = 0;
    while ( 1 )
    {
      LODWORD(a1) = cam_soc_util_clk_enable(v4, a2, 0, (unsigned int)v7, v6);
      if ( (_DWORD)a1 )
        goto LABEL_34;
      if ( *(_BYTE *)(v4 + 3289) == 1 && (debug_mdl & 0x20000) != 0 && !debug_priority )
      {
        if ( v7 > 0x1F )
          break;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_soc_util_clk_enable_default",
          2779,
          "dev name = %s clk name = %s idx = %d apply_level = %d clc idx = %d",
          *(const char **)(v4 + 24),
          *(const char **)(v4 + 8 * v7 + 872),
          v7,
          v6,
          v7);
      }
      ++v7;
      result = 0;
      if ( v7 >= *(unsigned int *)(v4 + 868) )
        goto LABEL_19;
    }
  }
  __break(0x5512u);
LABEL_34:
  v17 = v6;
  v18 = (unsigned int)a1;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x20000,
    1,
    "cam_soc_util_clk_enable_default",
    2772,
    "[%s] : failed to enable clk apply_level=%d, rc=%d, cesta_client_idx=%d",
    *(const char **)(v4 + 24),
    v17,
    (_DWORD)a1,
    a2);
  v19 = v7 - 1;
  if ( (v19 & 0x80000000) == 0 )
  {
    do
      cam_soc_util_clk_disable(v4, a2, 0, v19--);
    while ( v19 != -1 );
  }
  result = v18;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
