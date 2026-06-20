__int64 __fastcall cam_soc_util_set_src_clk_rate(__int64 a1, unsigned int a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  __int64 v6; // x25
  __int64 v7; // x8
  unsigned __int64 v8; // x20
  __int64 v9; // x23
  const char *v11; // x24
  size_t v12; // x0
  __int64 v13; // x24
  __int64 v14; // x8
  unsigned int v15; // w0
  unsigned int v16; // w19
  __int64 result; // x0
  __int64 v18; // x8
  __int64 v19; // x23
  unsigned int v20; // w0
  __int64 v21; // x8
  __int64 v22; // x24
  __int64 v23; // x21
  __int64 v24; // x27
  int v25; // w0
  __int64 v26; // [xsp+0h] [xbp-30h]
  unsigned int v27; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    LODWORD(v4) = -1;
    goto LABEL_22;
  }
  v4 = *(unsigned int *)(a1 + 2796);
  if ( (unsigned int)v4 >= 0x20 )
  {
LABEL_22:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_src_clk_rate",
      2172,
      "Invalid src_clk_idx: %d",
      v4);
LABEL_23:
    result = 4294967274LL;
    goto LABEL_24;
  }
  v6 = *(unsigned int *)(a1 + 3280);
  v7 = *(unsigned int *)(a1 + 3284);
  v8 = a3;
  if ( a3 && (_DWORD)v6 )
  {
    if ( (unsigned int)v6 >= 0xA )
      goto LABEL_53;
    v8 = *(int *)(a1 + (v6 << 7) + 4 * v4 + 1384);
  }
  if ( a4 && (_DWORD)v7 )
  {
    if ( (unsigned int)v7 > 9 )
      goto LABEL_53;
    a4 = *(int *)(a1 + (v7 << 7) + 4 * v4 + 1384);
  }
  v9 = a4;
  if ( !debug_disable_rt_clk_bw_limit )
  {
    v11 = *(const char **)(a1 + 24);
    v12 = strlen(v11);
    if ( !strnstr(v11, "cpas", v12) && !(_DWORD)v6 && (*(_BYTE *)(a1 + 32) & 1) == 0 )
    {
      v18 = *(unsigned int *)(a1 + 2876);
      if ( (unsigned int)v18 > 9 )
        goto LABEL_53;
      if ( v8 > *(int *)(a1 + (v18 << 7) + 4 * v4 + 1384) )
      {
        v26 = *(_QWORD *)(a1 + 8 * v4 + 872);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
          3,
          0x20000,
          2,
          "cam_soc_util_set_src_clk_rate",
          2194,
          "Requested clk rate: %llu greater than max supported rate: %llu for clk: %s",
          v8);
      }
    }
  }
  v13 = *(_QWORD *)(a1 + 1128 + 8 * v4);
  v27 = 0;
  if ( (unsigned int)cam_soc_util_get_clk_level((_BYTE *)a1, v8, v4, (int *)&v27) || v27 >= 0xA )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_src_clk_rate",
      2203,
      "set %s, rate %lld dev_name = %s apply level = %d",
      *(const char **)(a1 + 8 * v4 + 872),
      v8,
      *(const char **)(a1 + 24),
      v27);
    goto LABEL_23;
  }
  v14 = v9;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_soc_util_set_src_clk_rate",
      2210,
      "set %s, cesta_client_idx: %d rate [%ld %ld] dev_name = %s apply level = %d",
      *(const char **)(a1 + 8 * v4 + 872),
      a2,
      v8,
      v9,
      *(const char **)(a1 + 24),
      v27);
    v14 = v9;
    if ( a2 > 2 )
      goto LABEL_32;
  }
  else if ( a2 > 2 )
  {
    goto LABEL_32;
  }
  if ( (*(_BYTE *)(a1 + 3200) & 1) == 0 )
    goto LABEL_32;
  v15 = cam_soc_util_set_cesta_clk_rate(a1, a2, v8, v14, a1 + 16LL * a2 + 2808, a1 + 16LL * a2 + 2816);
  if ( v15 )
  {
    v16 = v15;
    LODWORD(v26) = a2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64, __int64, unsigned int))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_src_clk_rate",
      2225,
      "Failed in setting cesta clk rates[high low]:[%ld %ld] client_idx:%d rc:%d",
      v8,
      v9,
      v26,
      v15);
LABEL_34:
    result = v16;
    goto LABEL_24;
  }
  if ( clk_ops_profiling_hw_and_sw_voting == 1 )
  {
LABEL_32:
    v19 = a1 + 872;
    LODWORD(v26) = v4;
    v20 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, unsigned __int64, _QWORD, __int64, _QWORD, __int64, __int64))cam_soc_util_set_clk_rate)(
            a1,
            v13,
            *(_QWORD *)(a1 + 872 + 8 * v4),
            v8,
            (*(_DWORD *)(a1 + 2792) >> v4) & 1,
            1,
            *(unsigned int *)(a1 + 2664 + 4 * v4),
            a1 + 2800,
            v26);
    if ( v20 )
    {
      v21 = *(_QWORD *)(a1 + 24);
      v16 = v20;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, unsigned __int64, __int64, unsigned int))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_set_src_clk_rate",
        2251,
        "SET_RATE Failed: src clk: %s, rate %lld, dev_name = %s rc: %d",
        *(_QWORD *)(v19 + 8 * v4),
        v8,
        v21,
        v20);
      goto LABEL_34;
    }
    if ( *(int *)(a1 + 2880) >= 1 )
    {
      v22 = 0;
      v23 = a1 + 1384;
      while ( v22 != 32 )
      {
        v24 = *(unsigned int *)(a1 + 4 * v22 + 2884);
        if ( (v24 & 0x80000000) != 0 )
        {
          if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              debug_mdl & 0x20000,
              4,
              "cam_soc_util_set_src_clk_rate",
              2260,
              "Scl clk index invalid");
        }
        else
        {
          if ( (unsigned int)v24 > 0x1F || v27 > 9 )
            break;
          v25 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _DWORD))cam_soc_util_set_clk_rate)(
                  a1,
                  *(_QWORD *)(a1 + 1128 + 8 * v24),
                  *(_QWORD *)(v19 + 8 * v24),
                  *(int *)(v23 + ((unsigned __int64)v27 << 7) + 4 * v24),
                  (*(_DWORD *)(a1 + 2792) >> v24) & 1,
                  0,
                  *(unsigned int *)(a1 + 2664 + 4 * v24),
                  0,
                  v24);
          if ( v25 )
          {
            if ( v27 > 9 )
              break;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x20000,
              2,
              "cam_soc_util_set_src_clk_rate",
              2275,
              "SET_RATE Failed: scl clk: %s, rate %d dev_name = %s, rc: %d",
              *(const char **)(v19 + 8 * v24),
              *(_DWORD *)(v23 + ((unsigned __int64)v27 << 7) + 4 * v24),
              *(const char **)(a1 + 24),
              v25);
          }
        }
        if ( ++v22 >= *(int *)(a1 + 2880) )
          goto LABEL_48;
      }
LABEL_53:
      __break(0x5512u);
    }
  }
LABEL_48:
  result = 0;
  if ( *(_BYTE *)(a1 + 3309) == 1 )
    *(_DWORD *)(a1 + 2856) = v27;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
