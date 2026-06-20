__int64 __fastcall qcom_cc_really_probe(__int64 a1, _QWORD *a2, __int64 a3)
{
  unsigned __int64 v6; // x26
  __int64 v7; // x27
  unsigned __int64 v8; // x25
  __int64 v9; // x28
  __int64 v10; // x0
  __int64 v11; // x8
  _QWORD *v12; // x21
  __int64 v13; // x23
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 result; // x0
  unsigned int v18; // w24
  int v19; // w0
  __int64 *v20; // x0
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 *v23; // x24
  __int64 v24; // x0
  __int64 property; // x22
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x0
  __int64 v29; // x22
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x8
  __int64 v33; // x22
  __int64 v34; // x0
  __int64 v35; // x23
  __int64 node_by_phandle; // x0
  __int64 parent; // x26
  unsigned int v38; // w0
  unsigned int v39; // w27
  __int64 v40; // x4
  __int64 v41; // x8
  unsigned __int64 v42; // x8
  int v43; // w22
  __int64 v44; // x1
  unsigned __int64 v45; // x23
  int v46; // w22
  __int64 v47; // x1
  __int64 v48; // [xsp+8h] [xbp-78h]
  unsigned __int64 v49; // [xsp+10h] [xbp-70h]
  unsigned int v50; // [xsp+24h] [xbp-5Ch] BYREF
  __int64 v51; // [xsp+28h] [xbp-58h] BYREF
  __int64 v52; // [xsp+30h] [xbp-50h]
  __int64 v53; // [xsp+38h] [xbp-48h]
  __int64 v54; // [xsp+40h] [xbp-40h]
  __int64 v55; // [xsp+48h] [xbp-38h]
  __int64 v56; // [xsp+50h] [xbp-30h]
  __int64 v57; // [xsp+58h] [xbp-28h]
  __int64 v58; // [xsp+60h] [xbp-20h]
  __int64 v59; // [xsp+68h] [xbp-18h]
  __int64 v60; // [xsp+70h] [xbp-10h]
  __int64 v61; // [xsp+78h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = a2[9];
  v6 = a2[10];
  v8 = a2[4];
  v9 = a2[1];
  v10 = devm_kmalloc(a1, 152, 3520);
  if ( v10 )
  {
    v11 = *(_QWORD *)(a1 + 744);
    *(_QWORD *)(v10 + 112) = a1;
    v12 = (_QWORD *)v10;
    *(_QWORD *)(v10 + 16) = qcom_reset_ops;
    v13 = v10 + 16;
    v14 = *(_QWORD *)(a1 + 136);
    *(_QWORD *)(v10 + 72) = v11;
    v15 = a2[5];
    v16 = *(_QWORD *)(v14 + 16);
    *(_DWORD *)(v10 + 104) = a2[6];
    *(_QWORD *)(v10 + 24) = v16;
    *(_QWORD *)v10 = v15;
    *(_QWORD *)(v10 + 8) = a3;
    result = clk_regulator_init(a1, a2);
    if ( !(_DWORD)result )
    {
      v18 = clk_vdd_proxy_vote(a1, a2);
      if ( v18 )
      {
LABEL_54:
        clk_regulator_deinit(a2);
        result = v18;
        goto LABEL_55;
      }
      if ( !a2[6] || (v19 = devm_reset_controller_register(a1, v13)) == 0 )
      {
        if ( a2[7] && a2[8] )
        {
          v20 = (__int64 *)devm_kmalloc(a1, 24, 3520);
          if ( !v20 )
          {
            v19 = -12;
            goto LABEL_53;
          }
          v21 = a2[7];
          v22 = a2[8];
          v23 = v20;
          *v20 = a1;
          v20[1] = v21;
          v20[2] = v22;
          v19 = gdsc_register();
          if ( v19 )
            goto LABEL_53;
          v19 = _devm_add_action_or_reset(a1, v23);
          if ( v19 )
            goto LABEL_53;
        }
        v24 = *(_QWORD *)(a1 + 744);
        v12[15] = v9;
        v12[16] = v8;
        v12[17] = v7;
        v12[18] = v6;
        LODWORD(v51) = 0;
        property = of_find_property(v24, "protected-clocks", 0);
        v26 = of_prop_next_u32(property, 0, &v51);
        if ( v26 )
        {
          v27 = v26;
          do
          {
            if ( v12[16] > (unsigned __int64)(unsigned int)v51 )
              *(_QWORD *)(v12[15] + 8LL * (unsigned int)v51) = 0;
            v27 = of_prop_next_u32(property, v27, &v51);
          }
          while ( v27 );
        }
        v28 = *(_QWORD *)(a1 + 744);
        v49 = v6;
        v59 = 0;
        v60 = 0;
        v57 = 0;
        v58 = 0;
        v55 = 0;
        v56 = 0;
        v53 = 0;
        v54 = 0;
        v51 = 0;
        v52 = 0;
        v50 = 0;
        v29 = of_find_property(v28, "qcom,critical-clocks", 0);
        v30 = of_prop_next_u32(v29, 0, &v50);
        if ( v30 )
        {
          v31 = v30;
          do
          {
            if ( v12[16] > (unsigned __int64)v50 )
            {
              v32 = *(_QWORD *)(v12[15] + 8LL * v50);
              if ( v32 )
                *(_QWORD *)(v32 + 136) |= 1uLL;
            }
            v31 = of_prop_next_u32(v29, v31, &v50);
          }
          while ( v31 );
        }
        v48 = v7;
        v33 = of_find_property(*(_QWORD *)(a1 + 744), "qcom,critical-devices", 0);
        v34 = of_prop_next_u32(v33, 0, &v50);
        if ( v34 )
        {
          v35 = v34;
          do
          {
            node_by_phandle = of_find_node_by_phandle(v50);
            if ( node_by_phandle )
            {
              parent = node_by_phandle;
              do
              {
                if ( of_find_property(parent, "clocks", 0) )
                {
                  v38 = of_count_phandle_with_args(parent, "clocks", "#clock-cells");
                  v50 = 0;
                  if ( v38 )
                  {
                    v39 = v38;
                    v40 = 0;
                    do
                    {
                      _of_parse_phandle_with_args(parent, "clocks", "#clock-cells", 0xFFFFFFFFLL, v40, &v51);
                      if ( v51 == *(_QWORD *)(a1 + 744) && v12[16] > (unsigned __int64)HIDWORD(v52) )
                      {
                        v41 = *(_QWORD *)(v12[15] + 8LL * HIDWORD(v52));
                        if ( v41 )
                          *(_QWORD *)(v41 + 136) |= 1uLL;
                      }
                      v40 = ++v50;
                    }
                    while ( v50 < v39 );
                  }
                }
                parent = of_get_parent(parent);
              }
              while ( parent );
            }
            v35 = of_prop_next_u32(v33, v35, &v50);
          }
          while ( v35 );
        }
        if ( v49 )
        {
          v42 = 0;
          v43 = 1;
          do
          {
            v44 = *(_QWORD *)(v48 + 8 * v42);
            if ( v44 )
            {
              v19 = devm_clk_hw_register(a1, v44);
              if ( v19 )
                goto LABEL_53;
            }
            v42 = v43++;
          }
          while ( v49 > v42 );
        }
        if ( v8 )
        {
          v45 = 0;
          v46 = 1;
          do
          {
            v47 = *(_QWORD *)(v9 + 8 * v45);
            if ( v47 )
            {
              v19 = devm_clk_register_regmap(a1, v47);
              if ( v19 )
                goto LABEL_53;
              clk_hw_populate_clock_opp_table(*(_QWORD *)(a1 + 744), *(_QWORD *)(v9 + 8 * v45));
              if ( (*(_BYTE *)(*(_QWORD *)(v9 + 8 * v45) + 136LL) & 1) != 0 )
                *(_QWORD *)(v9 + 8 * v45) = 0;
            }
            v45 = v46++;
          }
          while ( v8 > v45 );
        }
        v19 = devm_of_clk_add_hw_provider(a1, qcom_cc_clk_hw_get, v12);
        if ( !v19 )
        {
          result = qcom_cc_icc_register(a1, a2);
          goto LABEL_55;
        }
      }
LABEL_53:
      v18 = v19;
      clk_vdd_proxy_unvote(a1, a2);
      goto LABEL_54;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return result;
}
