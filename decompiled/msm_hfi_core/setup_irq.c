__int64 __fastcall setup_irq(__int64 *a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x22
  __int64 v7; // x19
  __int64 v10; // x26
  __int64 v11; // x27
  const char *v12; // x21
  __int64 result; // x0
  unsigned int v14; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x30
  unsigned int v18; // w19

  v6 = *a1;
  v7 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "setup_irq", 288, a4, a5);
  v10 = (__int64)*(&off_1FB58 + (int)a3);
  v11 = (__int64)*(&off_1FB38 + (int)a3);
  v12 = off_1FB78[a3];
  result = of_irq_get(*(_QWORD *)(v6 + 744), a3);
  if ( (result & 0x80000000) == 0 )
  {
    *(_DWORD *)(a2 + v10) = result;
    snprintf((char *)(a2 + v11), 0x20u, "%s", v12);
    v14 = devm_request_threaded_irq(v6, *(unsigned int *)(a2 + v10), dcp_irq_handler, 0, 0, a2 + v11, a2);
    if ( v14 )
    {
      v17 = v7;
      v18 = v14;
      printk(&unk_1D62E, "setup_irq", 337, v17, v12);
      return v18;
    }
    else
    {
      irq_set_irq_wake(*(unsigned int *)(a2 + v10), 1);
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "setup_irq", 342, v15, v16);
      return 0;
    }
  }
  return result;
}
