__int64 __fastcall qcom_cc_icc_register(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x8
  int v9; // w23
  unsigned __int64 v10; // x28
  __int64 v11; // x9
  unsigned __int64 v12; // x27
  __int64 v13; // x8
  __int64 v14; // x25
  __int64 clk; // x0
  __int64 name; // x0
  unsigned __int64 v17; // x2

  if ( !*(_QWORD *)(a2 + 112) )
    return 0;
  v2 = *(_QWORD *)(a2 + 120);
  if ( !is_mul_ok(v2, 0x18u) )
    return 4294967284LL;
  v5 = 24 * v2;
  v6 = devm_kmalloc(a1, 24 * v2, 3520);
  if ( !v6 )
    return 4294967284LL;
  v7 = v6;
  if ( *(_QWORD *)(a2 + 120) )
  {
    v8 = 0;
    v9 = 0;
    while ( (v8 & 0x8000000000000000LL) == 0 )
    {
      v10 = 24 * v8;
      if ( v5 <= 24 * v8 + 16 )
        break;
      v11 = *(_QWORD *)(a2 + 112);
      v12 = v7 + v10;
      *(_DWORD *)(v7 + v10 + 16) = *(_DWORD *)(v11 + 12 * v8);
      if ( v5 < v10 + 20 )
        break;
      v13 = v11 + 12 * v8;
      *(_DWORD *)(v12 + 20) = *(_DWORD *)(v13 + 4);
      v14 = *(_QWORD *)(*(_QWORD *)(a2 + 8) + 8LL * *(int *)(v13 + 8));
      clk = devm_clk_hw_get_clk(a1, v14, "icc");
      if ( v5 <= v10 )
        break;
      *(_QWORD *)v12 = clk;
      if ( !clk )
        return dev_err_probe(a1, 4294967294LL, "(%d) clock entry is null\n", v9);
      name = clk_hw_get_name(v14);
      if ( v5 <= v10 + 8 )
        break;
      ++v9;
      v17 = *(_QWORD *)(a2 + 120);
      *(_QWORD *)(v12 + 8) = name;
      v8 = v9;
      if ( v17 <= v9 )
        return devm_icc_clk_register(a1, *(unsigned int *)(a2 + 128), v17, v7);
    }
    __break(1u);
    return qcom_cc_probe();
  }
  else
  {
    v17 = 0;
    return devm_icc_clk_register(a1, *(unsigned int *)(a2 + 128), v17, v7);
  }
}
