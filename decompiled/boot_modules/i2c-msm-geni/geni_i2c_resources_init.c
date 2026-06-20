__int64 __fastcall geni_i2c_resources_init(__int64 a1, _QWORD *a2)
{
  _BYTE *v2; // x23
  __int64 result; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  __int64 property; // x0
  int v9; // w8
  __int64 v10; // x0
  int v11; // w8
  int v12; // w21
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x19
  __int64 v16; // x8
  __int64 v17; // x2
  const char *v18; // x1
  const char *v19; // x1
  unsigned int v20; // w19
  unsigned __int64 v21; // x0
  unsigned int v22; // w21
  __int64 v23; // x0
  __int64 v24; // x0
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a2 + 1024;
  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2[1138] & 1) != 0 )
  {
    result = 0;
    goto LABEL_35;
  }
  v25[0] = 0;
  v6 = devm_clk_get(a1 + 16, "se-clk");
  a2[623] = v6;
  if ( v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v15 = v6;
    dev_err(a1 + 16, "Err getting SE Core clk %d\n", (unsigned int)v6);
    goto LABEL_34;
  }
  v7 = devm_clk_get(*(_QWORD *)(*a2 + 96LL), "m-ahb");
  a2[632] = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v19 = "Err getting M AHB clk %d\n";
LABEL_25:
    v20 = v7;
    dev_err(a1 + 16, v19, (unsigned int)v7);
    result = v20;
    goto LABEL_35;
  }
  v7 = devm_clk_get(*(_QWORD *)(*a2 + 96LL), "s-ahb");
  a2[633] = v7;
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v19 = "Err getting S AHB clk %d\n";
    goto LABEL_25;
  }
  v2[918] = of_find_property(*(_QWORD *)(a1 + 760), "qcom,i2c-hub", 0) != 0;
  property = of_find_property(*(_QWORD *)(a1 + 760), "qcom,high-perf", 0);
  v9 = (unsigned __int8)v2[918];
  v2[894] = property != 0;
  if ( v9 != 1 )
  {
    if ( property )
    {
      v10 = geni_icc_get(a2 + 620, "qup-memory");
      if ( !(_DWORD)v10 )
      {
        *((_DWORD *)a2 + 1254) = 50000;
        v11 = 76800;
        *((_DWORD *)a2 + 1258) = 1;
LABEL_12:
        *((_DWORD *)a2 + 1262) = v11;
        goto LABEL_13;
      }
    }
    else
    {
      v12 = *((_DWORD *)a2 + 2239);
      v10 = geni_icc_get(a2 + 620, "qup-memory");
      if ( !(_DWORD)v10 )
      {
        *((_DWORD *)a2 + 1254) = 1;
        *((_DWORD *)a2 + 1258) = 1;
        v11 = v12 / 1000;
        goto LABEL_12;
      }
    }
    v15 = v10;
    dev_err(a1 + 16, "%s: Error - resources_init ret:%d\n", "geni_i2c_resources_init", (unsigned int)v10);
    goto LABEL_34;
  }
  v21 = devm_clk_get(a1 + 16, "core-clk");
  a2[634] = v21;
  if ( v21 >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = v21;
    dev_err(a1 + 16, "Err getting core-clk %d\n", v21);
    result = v22;
    goto LABEL_35;
  }
  v23 = geni_icc_get(a2 + 620, 0);
  if ( (_DWORD)v23 )
  {
    v15 = v23;
    dev_err(a1 + 16, "%s: Error - geni_icc_get ret:%d\n", "geni_i2c_resources_init", (unsigned int)v23);
    goto LABEL_34;
  }
  v24 = *a2;
  *((_DWORD *)a2 + 1254) = 1;
  *((_DWORD *)a2 + 1258) = 1;
  v2[921] = 1;
  dev_info(v24, "%s: RTL based SE\n", "geni_i2c_resources_init");
LABEL_13:
  if ( *((_DWORD *)a2 + 2239) != 3400000 )
  {
    *((_DWORD *)a2 + 2240) = 0;
    goto LABEL_18;
  }
  result = geni_se_clk_freq_match(a2 + 620, 100000000, a2 + 1120, v25, 0);
  if ( (_DWORD)result )
  {
    v16 = *a2;
    v17 = *((unsigned int *)a2 + 2239);
    v18 = "se clk freq match failed freq:%d ret:%d\n";
    goto LABEL_32;
  }
  v13 = clk_set_rate(a2[623], v25[0]);
  if ( (_DWORD)v13 )
  {
    v14 = *a2;
    v15 = v13;
    dev_err(v14, "set clk rate failed ret:%d\n", (unsigned int)v13);
LABEL_34:
    result = v15;
    goto LABEL_35;
  }
LABEL_18:
  result = platform_get_irq(a1, 0);
  *((_DWORD *)a2 + 5) = result;
  if ( (result & 0x80000000) == 0 )
  {
    irq_modify_status();
    result = devm_request_threaded_irq(*a2, *((unsigned int *)a2 + 5), geni_i2c_irq, 0, 0, "i2c_geni", a2);
    if ( (_DWORD)result )
    {
      v16 = *a2;
      v17 = *((unsigned int *)a2 + 5);
      v18 = "Request_irq failed:%d: err:%d\n";
LABEL_32:
      v15 = result;
      dev_err(v16, v18, v17, (unsigned int)result);
      goto LABEL_34;
    }
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
