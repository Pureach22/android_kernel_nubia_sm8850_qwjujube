__int64 __fastcall msm_vidc_set_ir_period(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x4
  __int64 v3; // x2
  __int64 v5; // x1
  __int64 result; // x0
  __int64 v7; // x4
  char *v8; // x2
  unsigned int v9; // w19

  v2 = a1[3253];
  v3 = a2;
  v5 = 50331953;
  if ( v2 == 1 )
  {
    v5 = 50332030;
LABEL_8:
    result = venus_hfi_set_ir_period(a1, v5, v3);
    if ( (_DWORD)result && a1 && (msm_vidc_debug & 1) != 0 )
    {
      v7 = a1[1489];
      v8 = (char *)a1 + 340;
      v9 = result;
      printk(&unk_87024, "err ", v8, "msm_vidc_set_ir_period", v7);
      return v9;
    }
    return result;
  }
  if ( !v2 )
  {
    if ( (*(_WORD *)(a1[231] + 320LL) & 1) != 0 )
    {
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        return 0;
      printk(&unk_8BCA6, "high", (char *)a1 + 340, "msm_vidc_set_ir_period", 0);
      return 0;
    }
    goto LABEL_8;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_95225, "err ", (char *)a1 + 340, "msm_vidc_set_ir_period", v2);
  return 4294967274LL;
}
