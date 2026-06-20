__int64 __fastcall qmp_combo_register_clocks(const char ***a1, const char *a2, __int64 a3)
{
  const char **v6; // x8
  const char *v7; // x3
  const char **v8; // x0
  __int64 result; // x0
  const char **v10; // x8
  const char *v11; // x3
  const char **v12; // x0
  const char *v13; // x3
  const char **v14; // x0
  unsigned int v15; // w0
  unsigned int v16; // w19
  unsigned int v17; // w20
  char *v18; // [xsp+0h] [xbp-80h] BYREF
  void *v19; // [xsp+8h] [xbp-78h]
  __int64 v20; // [xsp+10h] [xbp-70h]
  __int64 v21; // [xsp+18h] [xbp-68h]
  __int64 v22; // [xsp+20h] [xbp-60h]
  __int64 v23; // [xsp+28h] [xbp-58h]
  __int64 v24; // [xsp+30h] [xbp-50h]
  char s[8]; // [xsp+38h] [xbp-48h] BYREF
  __int64 v26; // [xsp+40h] [xbp-40h]
  __int64 v27; // [xsp+48h] [xbp-38h]
  __int64 v28; // [xsp+50h] [xbp-30h]
  __int64 v29; // [xsp+58h] [xbp-28h]
  __int64 v30; // [xsp+60h] [xbp-20h]
  __int64 v31; // [xsp+68h] [xbp-18h]
  __int64 v32; // [xsp+70h] [xbp-10h]
  __int64 v33; // [xsp+78h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v7 = v6[14];
  v20 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  *(_QWORD *)s = 0;
  v26 = 0;
  if ( !v7 )
    v7 = *v6;
  snprintf(s, 0x40u, "%s::pipe_clk", v7);
  v8 = *a1;
  v18 = s;
  v19 = &clk_fixed_rate_ops;
  a1[46] = (const char **)&v18;
  a1[47] = (const char **)125000000;
  result = devm_clk_hw_register(v8, a1 + 44);
  if ( !(_DWORD)result )
  {
    v10 = *a1;
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    v11 = v10[14];
    v20 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    *(_QWORD *)s = 0;
    v26 = 0;
    if ( !v11 )
      v11 = *v10;
    snprintf(s, 0x40u, "%s::link_clk", v11);
    v12 = *a1;
    v18 = s;
    v19 = &qmp_dp_link_clk_ops;
    a1[52] = (const char **)&v18;
    result = devm_clk_hw_register(v12, a1 + 50);
    if ( !(_DWORD)result )
    {
      v13 = (*a1)[14];
      if ( !v13 )
        v13 = **a1;
      snprintf(s, 0x40u, "%s::vco_div_clk", v13);
      v14 = *a1;
      v18 = s;
      v19 = &qmp_dp_pixel_clk_ops;
      a1[55] = (const char **)&v18;
      result = devm_clk_hw_register(v14, a1 + 53);
      if ( !(_DWORD)result )
      {
        if ( (*a1)[93] == a2 )
        {
          result = devm_of_clk_add_hw_provider();
        }
        else
        {
          result = of_clk_add_hw_provider(a2, &of_clk_hw_simple_get, a1 + 44);
          if ( !(_DWORD)result )
          {
            v15 = _devm_add_action(*a1, phy_clk_release_provider, a2, "phy_clk_release_provider");
            if ( v15 )
            {
              v16 = v15;
              of_clk_del_provider(a2);
              result = v16;
            }
            else
            {
              result = of_clk_add_hw_provider(a3, qmp_dp_clks_hw_get, a1);
              if ( !(_DWORD)result )
              {
                result = _devm_add_action(*a1, phy_clk_release_provider, a3, "phy_clk_release_provider");
                if ( (_DWORD)result )
                {
                  v17 = result;
                  of_clk_del_provider(a3);
                  result = v17;
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
