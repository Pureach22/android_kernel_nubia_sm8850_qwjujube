unsigned __int64 __fastcall qcom_ice_create(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v5; // x19
  __int64 v6; // x0
  __int64 property; // x0
  unsigned __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x21
  unsigned int v11; // w0
  unsigned int v12; // w2
  __int64 v13; // x20
  bool v14; // zf
  int v15; // w8
  char v16; // w8

  if ( (qcom_scm_is_available() & 1) == 0 )
    return -517;
  if ( (qcom_scm_ice_available() & 1) == 0 )
  {
    dev_warn(a1, "ICE SCM interface not found\n");
    return 0;
  }
  v4 = (_QWORD *)devm_kmalloc(a1, 40, 3520);
  if ( !v4 )
    return -12;
  v5 = v4;
  *v4 = a1;
  v4[1] = a2;
  v6 = *(_QWORD *)(a1 + 744);
  *((_BYTE *)v5 + 35) = 0;
  property = of_find_property(v6, "qcom,ice-handle-clks", 0);
  *((_BYTE *)v5 + 35) = property != 0;
  if ( property )
  {
    result = devm_clk_get_optional_enabled(a1, "core_clk_ice");
    v5[3] = result;
    if ( result || (result = devm_clk_get_optional_enabled(a1, "ice"), (v5[3] = result) != 0) )
    {
      if ( result > 0xFFFFFFFFFFFFF000LL )
        return result;
    }
    else
    {
      result = devm_clk_get_enabled(a1, 0);
      v5[3] = result;
      if ( result > 0xFFFFFFFFFFFFF000LL )
        return result;
    }
  }
  v9 = of_find_property(*(_QWORD *)(a1 + 744), "qcom,ice-use-hwkm", 0);
  v10 = v5[1];
  *((_BYTE *)v5 + 33) = v9 != 0;
  v11 = readl(v10 + 8);
  v12 = HIBYTE(v11);
  v13 = *v5;
  if ( HIBYTE(v11) - 5 <= 0xFFFFFFFD )
  {
    dev_warn(*v5, "Unsupported ICE version: v%d.%d.%d\n", v12, BYTE2(v11), (unsigned __int16)v11);
    return -95;
  }
  if ( v11 >> 26 || (v12 == 3 ? (v14 = BYTE2(v11) == 2) : (v14 = 0), !v14 ? (v15 = 0) : (v15 = 1), (_WORD)v11 && v15) )
  {
    v16 = 2;
LABEL_27:
    *((_BYTE *)v5 + 32) = v16;
    goto LABEL_28;
  }
  if ( v15 )
  {
    v16 = 1;
    goto LABEL_27;
  }
  *((_WORD *)v5 + 16) = 0;
LABEL_28:
  dev_info(v13, "Found QC Inline Crypto Engine (ICE) v%d.%d.%d\n", v12, BYTE2(v11), (unsigned __int16)v11);
  v14 = (readl(v10 + 16) & 7) == 0;
  result = (unsigned __int64)v5;
  if ( !v14 )
  {
    dev_warn(v13, "Fuses are blown; ICE is unusable!\n");
    return -95;
  }
  return result;
}
