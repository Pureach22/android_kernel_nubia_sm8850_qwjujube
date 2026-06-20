__int64 __fastcall process_cpu_index(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 property; // x0
  __int64 result; // x0
  void *v6; // x0
  _QWORD v7[11]; // [xsp+8h] [xbp-58h] BYREF

  v7[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v7, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(a1, "qcom,gic-cpulist", 0, 0, a2, v7) || !v7[0] )
  {
    v6 = &unk_8259;
LABEL_8:
    printk(v6, "process_cpu_index");
LABEL_10:
    result = 4294967274LL;
    goto LABEL_5;
  }
  property = of_get_property(v7[0], &unk_809F, 0);
  if ( !property )
  {
    v6 = &unk_8352;
    goto LABEL_8;
  }
  result = qcom_scm_set_gic_cpuclass(bswap32(*(_DWORD *)(property + 4)), a3);
  if ( (_DWORD)result )
  {
    printk(&unk_8282, "process_cpu_index");
    goto LABEL_10;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
