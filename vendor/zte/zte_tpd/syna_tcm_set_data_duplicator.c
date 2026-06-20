__int64 __fastcall syna_tcm_set_data_duplicator(__int64 a1, int a2, void *a3, __int64 a4)
{
  __int64 v6; // x8

  if ( a1 )
  {
    v6 = a1 + 16LL * (unsigned int)a2;
    *(_QWORD *)(v6 + 5088) = (_QWORD)a3;
    *(_QWORD *)(v6 + 5080) = a4;
    return 0;
  }
  else
  {
    printk(unk_3365A, "syna_tcm_set_data_duplicator", a3);
    return 4294967055LL;
  }
}
