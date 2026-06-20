__int64 __fastcall syna_dev_set_tp_report_rate(_QWORD *a1, int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x2
  void *v8; // x0

  printk(unk_3A85B, "syna_dev_set_tp_report_rate", "syna_dev_set_tp_report_rate");
  if ( !a1 )
    return 4294967274LL;
  if ( a2 <= 1 )
  {
    if ( !a2 )
    {
      result = syna_tcm_set_dynamic_config(*a1, 230, 0, a3);
      if ( (result & 0x80000000) != 0 )
        return result;
      v8 = unk_35446;
      goto LABEL_19;
    }
    if ( a2 == 1 )
    {
      result = syna_tcm_set_dynamic_config(*a1, 230, 5, a3);
      if ( (result & 0x80000000) != 0 )
        return result;
      v8 = unk_397FC;
      goto LABEL_19;
    }
LABEL_22:
    printk(unk_3BDBF, "syna_dev_set_tp_report_rate", "syna_dev_set_tp_report_rate");
    return 0;
  }
  if ( a2 == 2 )
  {
    result = syna_tcm_set_dynamic_config(*a1, 230, 4, a3);
    if ( (result & 0x80000000) != 0 )
      return result;
    v8 = unk_36F56;
    goto LABEL_19;
  }
  if ( a2 == 3 )
  {
    result = syna_tcm_set_dynamic_config(*a1, 230, 3, a3);
    if ( (result & 0x80000000) != 0 )
      return result;
    v8 = unk_33B9F;
    goto LABEL_19;
  }
  if ( a2 != 4 )
    goto LABEL_22;
  result = syna_tcm_set_dynamic_config(*a1, 230, 1, a3);
  if ( (result & 0x80000000) != 0 )
    return result;
  v8 = unk_38139;
LABEL_19:
  printk(v8, "syna_dev_set_tp_report_rate", v7);
  return 0;
}
