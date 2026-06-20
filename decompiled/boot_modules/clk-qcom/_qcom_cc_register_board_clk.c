__int64 __fastcall qcom_cc_register_board_clk(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 node_opts_by_path; // x0
  __int64 v8; // x0
  __int64 v9; // x9
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // [xsp+8h] [xbp-48h] BYREF
  void *v13; // [xsp+10h] [xbp-40h]
  _QWORD *v14; // [xsp+18h] [xbp-38h]
  __int64 v15; // [xsp+20h] [xbp-30h]
  __int64 v16; // [xsp+28h] [xbp-28h]
  __int64 v17; // [xsp+30h] [xbp-20h]
  __int64 v18; // [xsp+38h] [xbp-18h]
  _QWORD v19[2]; // [xsp+40h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = a2;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = nullptr;
  v14 = nullptr;
  v12 = 0;
  node_opts_by_path = of_find_node_opts_by_path("/clocks", 0);
  if ( node_opts_by_path && of_get_child_by_name(node_opts_by_path, v19[0]) )
    goto LABEL_5;
  v8 = devm_kmalloc(a1, 48, 3520);
  if ( !v8 )
    goto LABEL_7;
  v9 = v19[0];
  *(_QWORD *)(v8 + 16) = &v12;
  *(_QWORD *)(v8 + 24) = a4;
  v12 = v9;
  v13 = &clk_fixed_rate_ops;
  result = devm_clk_hw_register(a1, v8);
  if ( !(_DWORD)result )
  {
LABEL_5:
    v11 = devm_kmalloc(a1, 48, 3520);
    if ( v11 )
    {
      *(_QWORD *)(v11 + 16) = &v12;
      *(_QWORD *)(v11 + 24) = 0x100000001LL;
      v14 = v19;
      LOBYTE(v17) = 1;
      v18 = 0;
      v12 = a3;
      v13 = &clk_fixed_factor_ops;
      result = devm_clk_hw_register(a1, v11);
      goto LABEL_8;
    }
LABEL_7:
    result = 4294967274LL;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
