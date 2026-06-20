__int64 __fastcall syna_dev_get_frame_data(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x2
  int v7; // w0

  printk(&unk_35F27, "syna_dev_get_frame_data", a2);
  if ( !a1 )
    return 4294967274LL;
  if ( a2 )
    v6 = 6;
  else
    v6 = 0;
  v7 = syna_tcm_set_dynamic_config(*a1, 243, v6, a3);
  return v7 & (unsigned int)(v7 >> 31);
}
