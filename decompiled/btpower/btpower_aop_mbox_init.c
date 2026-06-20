__int64 __fastcall btpower_aop_mbox_init(__int64 a1)
{
  unsigned __int64 v2; // x0
  void *v4; // x0
  __int64 v5; // x21
  __int64 v6; // x20
  unsigned int v7; // w0
  unsigned int v8; // w19

  v2 = qmp_get(*(_QWORD *)a1 + 16LL);
  *(_QWORD *)(a1 + 152) = v2;
  if ( v2 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (unsigned int)of_property_read_string(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,vreg_ipa", a1 + 168) )
      v4 = &unk_12721;
    else
      v4 = &unk_130D3;
    printk(v4, "btpower_aop_mbox_init");
    if ( *(int *)(a1 + 180) >= 1 && *(_QWORD *)(a1 + 184) )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = *(_QWORD *)(*(_QWORD *)(a1 + 184) + 8 * v5);
        v7 = qmp_send(*(_QWORD *)(a1 + 152), v6, 64);
        if ( (v7 & 0x80000000) != 0 )
          break;
        if ( ++v5 >= (unsigned __int64)*(unsigned int *)(a1 + 180) )
          return 0;
      }
      v8 = v7;
      printk(&unk_1358A, v6);
      printk(&unk_1177B, v8);
    }
    return 0;
  }
  else
  {
    printk(&unk_11227, "btpower_aop_mbox_init");
    return *(unsigned int *)(a1 + 152);
  }
}
