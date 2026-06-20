__int64 __fastcall qcrypto_ce_set_bus(_QWORD *a1, char a2)
{
  int v2; // w8
  int v4; // w10
  __int64 result; // x0
  void *v6; // x0

  if ( (a2 & 1) != 0 )
    v2 = 2;
  else
    v2 = 3;
  if ( (a2 & 1) != 0 )
    v4 = 1;
  else
    v4 = 4;
  if ( !*(_BYTE *)(a1[4] + 36LL) )
    v2 = v4;
  if ( v2 > 2 )
  {
    if ( v2 == 3 )
    {
      if ( (unsigned int)qce_disable_clk(a1[2]) )
      {
        v6 = &unk_125D2;
        return printk(v6, "qcrypto_ce_set_bus");
      }
      result = icc_set_bw(a1[5], 0, 0);
      if ( !(_DWORD)result )
        return result;
      printk(&unk_12B73, "qcrypto_ce_set_bus");
      result = qce_enable_clk(a1[2]);
      if ( !(_DWORD)result )
        return result;
LABEL_19:
      v6 = &unk_12048;
      return printk(v6, "qcrypto_ce_set_bus");
    }
    if ( (unsigned int)icc_set_bw(a1[5], 0, 0) )
    {
LABEL_28:
      v6 = &unk_12B73;
      return printk(v6, "qcrypto_ce_set_bus");
    }
    result = qce_disable_clk(a1[2]);
    if ( !(_DWORD)result )
      return result;
    printk(&unk_125D2, "qcrypto_ce_set_bus");
    result = icc_set_bw(a1[5], 384, 384);
    if ( !(_DWORD)result )
      return result;
LABEL_27:
    v6 = &unk_121DF;
    return printk(v6, "qcrypto_ce_set_bus");
  }
  if ( v2 != 1 )
  {
    if ( !(unsigned int)icc_set_bw(a1[5], 384, 384) )
    {
      result = qce_enable_clk(a1[2]);
      if ( !(_DWORD)result )
        return result;
      printk(&unk_12048, "qcrypto_ce_set_bus");
      result = icc_set_bw(a1[5], 0, 0);
      if ( !(_DWORD)result )
        return result;
      goto LABEL_28;
    }
    goto LABEL_27;
  }
  if ( (unsigned int)qce_enable_clk(a1[2]) )
    goto LABEL_19;
  result = icc_set_bw(a1[5], 384, 384);
  if ( (_DWORD)result )
  {
    printk(&unk_121DF, "qcrypto_ce_set_bus");
    result = qce_disable_clk(a1[2]);
    if ( (_DWORD)result )
    {
      v6 = &unk_129E6;
      return printk(v6, "qcrypto_ce_set_bus");
    }
  }
  return result;
}
