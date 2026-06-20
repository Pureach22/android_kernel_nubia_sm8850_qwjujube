__int64 __fastcall cam_vfe_top_calc_hw_clk_rate(
        __int64 a1,
        __int64 a2,
        unsigned __int64 *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  int v6; // w9
  unsigned __int64 v7; // x8
  __int64 v8; // x9
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  unsigned int v16; // w9
  unsigned __int64 v17; // x10
  int v18; // w8
  __int64 v19; // x11
  __int64 v21; // x9

  v6 = *(_DWORD *)(a1 + 1064);
  if ( v6 )
  {
    if ( (unsigned int)(v6 - 8) < 0xFFFFFFF9 )
      goto LABEL_53;
    v7 = *(_QWORD *)(a1 + 10424);
    if ( v6 != 1 )
    {
      if ( *(_QWORD *)(a1 + 10432) > v7 )
        v7 = *(_QWORD *)(a1 + 10432);
      if ( v6 != 2 )
      {
        if ( *(_QWORD *)(a1 + 10440) > v7 )
          v7 = *(_QWORD *)(a1 + 10440);
        if ( v6 != 3 )
        {
          if ( *(_QWORD *)(a1 + 10448) > v7 )
            v7 = *(_QWORD *)(a1 + 10448);
          if ( v6 != 4 )
          {
            if ( *(_QWORD *)(a1 + 10456) > v7 )
              v7 = *(_QWORD *)(a1 + 10456);
            if ( v6 != 5 )
            {
              if ( *(_QWORD *)(a1 + 10464) > v7 )
                v7 = *(_QWORD *)(a1 + 10464);
              if ( v6 != 6 && *(_QWORD *)(a1 + 10472) > v7 )
                v7 = *(_QWORD *)(a1 + 10472);
            }
          }
        }
      }
    }
  }
  else
  {
    v7 = 0;
  }
  if ( (a2 & 1) != 0 && (*(_BYTE *)(a1 + 10480) & 1) == 0 )
  {
    *a3 = v7;
    *(_QWORD *)(a1 + 10336) = 0;
    *(_QWORD *)(a1 + 10328) = 0;
    *(_QWORD *)(a1 + 10320) = 0;
    *(_QWORD *)(a1 + 10312) = 0;
    *(_QWORD *)(a1 + 10304) = 0;
    *(_QWORD *)(a1 + 10296) = v7;
    *(_DWORD *)(a1 + 10344) = 1;
    v10 = *a3;
    goto LABEL_41;
  }
  v8 = *(unsigned int *)(a1 + 10344);
  if ( (unsigned int)v8 <= 5 )
  {
    *(_QWORD *)(a1 + 10296 + 8 * v8) = v7;
    v9 = *(_QWORD *)(a1 + 10296);
    *(_DWORD *)(a1 + 10344) = (*(_DWORD *)(a1 + 10344) + 1) % 6u;
    v10 = *a3;
    if ( v9 > *a3 )
    {
      v10 = v9;
      *a3 = v9;
    }
    v11 = *(_QWORD *)(a1 + 10304);
    if ( v11 > v10 )
    {
      v10 = *(_QWORD *)(a1 + 10304);
      *a3 = v11;
    }
    v12 = *(_QWORD *)(a1 + 10312);
    if ( v12 > v10 )
    {
      v10 = *(_QWORD *)(a1 + 10312);
      *a3 = v12;
    }
    v13 = *(_QWORD *)(a1 + 10320);
    if ( v13 > v10 )
    {
      v10 = *(_QWORD *)(a1 + 10320);
      *a3 = v13;
    }
    v14 = *(_QWORD *)(a1 + 10328);
    if ( v14 > v10 )
    {
      v10 = *(_QWORD *)(a1 + 10328);
      *a3 = v14;
    }
    v15 = *(_QWORD *)(a1 + 10336);
    if ( v15 <= v10 )
    {
      if ( !v10 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x2000000,
          1,
          "cam_vfe_top_calc_hw_clk_rate",
          187,
          "Final clock rate is zero");
        return (unsigned int)-22;
      }
    }
    else
    {
      *a3 = v15;
      v10 = v15;
    }
LABEL_41:
    v17 = *(_QWORD *)(a1 + 10416);
    if ( v10 == v17 )
    {
      v18 = 1;
      v19 = 0;
    }
    else if ( v10 > v17 )
    {
      v18 = 2;
      v19 = 1;
    }
    else
    {
      v18 = 3;
      v19 = 2;
    }
    *(_DWORD *)(a1 + 10368) = v18;
    v16 = 0;
    if ( (debug_mdl & 0x2000008) != 0 && !debug_priority )
    {
      if ( (a2 & 1) != 0 )
        v21 = -1;
      else
        v21 = a4;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, char *, unsigned __int64, __int64))cam_print_log)(
        3,
        debug_mdl & 0x2000008,
        4,
        "cam_vfe_top_calc_hw_clk_rate",
        201,
        "VFE:%d Clock state:%s applied_clk_rate:%llu req_id:%ld",
        *(unsigned int *)(a1 + 1068),
        off_44EBB0[v19],
        v17,
        v21);
      return 0;
    }
    return v16;
  }
LABEL_53:
  __break(0x5512u);
  return cam_vfe_top_calc_axi_bw_vote(a1, a2, a3, a4, a5, a6);
}
