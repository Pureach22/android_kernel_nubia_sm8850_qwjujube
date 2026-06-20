__int64 __fastcall cam_cpas_hw_enable_domain_id_clks(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x23
  __int64 v4; // x19
  int v5; // w8
  __int64 v6; // x22
  unsigned int v7; // w0
  unsigned int v8; // w20
  __int64 v9; // x24
  const char *v10; // x5
  __int64 v11; // x1
  __int64 v12; // x4
  __int64 v13; // x21
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w0

  v2 = *(_QWORD *)(a1 + 3392);
  if ( (*(_BYTE *)(v2 + 1644) & 1) == 0 )
  {
    v8 = -22;
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_hw_enable_domain_id_clks",
        4618,
        "Domain-id not supported on target");
    return v8;
  }
  v3 = *(_QWORD *)(v2 + 1648);
  v4 = a1;
  v5 = *(_DWORD *)(v3 + 84);
  if ( (a2 & 1) != 0 )
  {
    if ( v5 < 1 )
      goto LABEL_44;
    v6 = v3 + 56;
    v7 = cam_soc_util_clk_enable(a1 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 56), 0);
    if ( v7 )
    {
      v8 = v7;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_enable_domain_id_clks",
        4628,
        "Domain-id clk %s enable failed, rc: %d",
        *(const char **)v3,
        0);
      return v8;
    }
    if ( *(int *)(v3 + 84) < 2 )
      goto LABEL_44;
    v13 = 1;
    v14 = cam_soc_util_clk_enable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 60), 0);
    if ( v14 )
    {
      v8 = v14;
LABEL_22:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_hw_enable_domain_id_clks",
        4628,
        "Domain-id clk %s enable failed, rc: %d",
        *(const char **)(v3 + 8 * v13),
        v13);
      cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v6 + 4 * (v13 - 1)));
      if ( v13 != 1 )
      {
        cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v6 + 4 * (v13 - 2)));
        if ( v13 != 2 )
        {
          cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v6 + 4 * (v13 - 3)));
          if ( v13 != 3 )
          {
            cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v6 + 4 * (v13 - 4)));
            if ( v13 != 4 )
            {
              cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v6 + 4 * (v13 - 5)));
              if ( v13 != 5 )
                cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v6 + 4 * v13 - 24));
            }
          }
        }
      }
      return v8;
    }
    if ( *(int *)(v3 + 84) < 3 )
      goto LABEL_44;
    v15 = cam_soc_util_clk_enable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 64), 0);
    if ( v15 )
    {
      v8 = v15;
      v13 = 2;
      goto LABEL_22;
    }
    if ( *(int *)(v3 + 84) < 4 )
      goto LABEL_44;
    v16 = cam_soc_util_clk_enable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 68), 0);
    if ( v16 )
    {
      v8 = v16;
      v13 = 3;
      goto LABEL_22;
    }
    if ( *(int *)(v3 + 84) < 5 )
      goto LABEL_44;
    v17 = cam_soc_util_clk_enable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 72), 0);
    if ( v17 )
    {
      v8 = v17;
      v13 = 4;
      goto LABEL_22;
    }
    if ( *(int *)(v3 + 84) < 6 )
      goto LABEL_44;
    v18 = cam_soc_util_clk_enable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 76), 0);
    if ( v18 )
    {
      v8 = v18;
      v13 = 5;
      goto LABEL_22;
    }
    if ( *(int *)(v3 + 84) < 7 )
      goto LABEL_44;
    a1 = cam_soc_util_clk_enable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 80), 0);
    if ( (_DWORD)a1 )
    {
      v8 = a1;
      v13 = 6;
      goto LABEL_22;
    }
    if ( *(int *)(v3 + 84) <= 7 )
    {
LABEL_44:
      v8 = 0;
      if ( (debug_mdl & 4) == 0 || debug_priority )
        return v8;
      v10 = "Domain-id clks enable success";
      v11 = debug_mdl & 4;
      v12 = 4632;
      goto LABEL_48;
    }
  }
  else
  {
    if ( v5 < 1 )
    {
LABEL_16:
      v8 = 0;
      if ( (debug_mdl & 4) == 0 || debug_priority )
        return v8;
      v10 = "Domain-id clks disable success";
      v11 = debug_mdl & 4;
      v12 = 4642;
LABEL_48:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        v11,
        4,
        "cam_cpas_hw_enable_domain_id_clks",
        v12,
        v10);
      return 0;
    }
    v9 = 0;
    while ( v9 != 7 )
    {
      a1 = cam_soc_util_clk_disable(v4 + 96, 0xFFFFFFFF, 1, *(unsigned int *)(v3 + 4 * v9 + 56));
      v8 = a1;
      if ( (_DWORD)a1 )
        a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               4,
               2,
               "cam_cpas_hw_enable_domain_id_clks",
               4639,
               "Domain-id clk %s disable failed, rc: %d",
               *(const char **)(v3 + 8 * v9),
               a1);
      if ( ++v9 >= *(int *)(v3 + 84) )
      {
        if ( v8 )
          return v8;
        goto LABEL_16;
      }
    }
  }
  __break(0x5512u);
  return cam_cpas_dump_state_monitor_array_info(a1, a2);
}
