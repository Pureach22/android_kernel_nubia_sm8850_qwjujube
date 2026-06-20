__int64 __fastcall syna_dev_set_screen_on_fp_mode(_QWORD *a1, unsigned int a2, __int64 a3)
{
  unsigned int v5; // w0
  __int64 v6; // x2
  unsigned int v8; // w19

  printk(&unk_36A84, "syna_dev_set_screen_on_fp_mode", a3);
  if ( !a1 )
    return 4294967274LL;
  v5 = syna_tcm_set_dynamic_config(*a1, 212, 3, a2);
  if ( (v5 & 0x80000000) == 0 )
    return 0;
  v8 = v5;
  printk(&unk_3B058, "syna_dev_set_screen_on_fp_mode", v6);
  return v8;
}
