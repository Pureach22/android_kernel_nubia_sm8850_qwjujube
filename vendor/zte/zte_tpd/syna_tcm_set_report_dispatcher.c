__int64 __fastcall syna_tcm_set_report_dispatcher(__int64 a1, int a2, void *a3, __int64 a4)
{
  unsigned int v5; // w19
  __int64 v7; // x21
  void *v8; // x22
  __int64 v9; // x23
  __int64 v10; // x8

  if ( a1 )
  {
    v5 = (unsigned int)a2;
    if ( (unsigned int)a2 <= 0xFu )
    {
      v7 = a1;
      v8 = a3;
      v9 = a4;
      printk(unk_3C74A, "syna_tcm_set_report_dispatcher", (unsigned int)a2);
      a1 = v7;
      a3 = v8;
      a4 = v9;
    }
    v10 = a1 + 16LL * (unsigned int)a2;
    *(_QWORD *)(v10 + 992) = (_QWORD)a3;
    *(_QWORD *)(v10 + 984) = a4;
    printk(unk_338BD, "syna_tcm_set_report_dispatcher", v5);
    return 0;
  }
  else
  {
    printk(unk_3365A, "syna_tcm_set_report_dispatcher", a3);
    return 4294967055LL;
  }
}
