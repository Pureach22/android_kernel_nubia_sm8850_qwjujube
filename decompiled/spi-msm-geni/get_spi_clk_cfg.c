__int64 __fastcall get_spi_clk_cfg(int a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  int v7; // w8
  int v8; // w0
  __int64 v9; // x3
  unsigned __int64 v10; // x8
  __int64 result; // x0
  __int64 v12; // x8
  unsigned int v13; // w19
  __int64 v14; // x8
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD *)(a2 + 296);
  v15[0] = 0;
  v8 = geni_se_clk_freq_match(a2, (unsigned int)(v7 * a1), a3, v15, 0);
  if ( v8 )
  {
    v12 = *(_QWORD *)(a2 + 200);
    v13 = v8;
    dev_err(v12, "%s: Failed(%d) to find src clk for 0x%x\n", "get_spi_clk_cfg", v8, a1);
LABEL_8:
    result = v13;
    goto LABEL_4;
  }
  v9 = v15[0];
  v10 = (v15[0] + (unsigned __int64)(unsigned int)(*(_DWORD *)(a2 + 296) * a1) - 1)
      / (unsigned int)(*(_DWORD *)(a2 + 296) * a1);
  *a4 = v10;
  if ( !(_DWORD)v10 )
  {
    dev_err(
      *(_QWORD *)(a2 + 200),
      "%s:Err:sclk:%lu oversampling:%d speed:%u\n",
      "get_spi_clk_cfg",
      v9,
      *(_DWORD *)(a2 + 296),
      a1);
    result = 4294967274LL;
    goto LABEL_4;
  }
  result = clk_set_rate(*(_QWORD *)(a2 + 24), v9);
  if ( (_DWORD)result )
  {
    v14 = *(_QWORD *)(a2 + 200);
    v13 = result;
    dev_err(v14, "%s: clk_set_rate failed %d\n", "get_spi_clk_cfg", result);
    goto LABEL_8;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
