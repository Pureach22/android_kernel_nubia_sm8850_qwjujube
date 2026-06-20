__int64 __fastcall syna_dev_set_charger_mode(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  int v6; // w0

  printk(&unk_35F27, "syna_dev_set_charger_mode", a2);
  if ( !a1 )
    return 4294967274LL;
  v6 = syna_tcm_set_dynamic_config(*a1, 7, a2, a3);
  return v6 & (unsigned int)(v6 >> 31);
}
