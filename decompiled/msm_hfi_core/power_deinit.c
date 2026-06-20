__int64 __fastcall power_deinit(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  _QWORD *v6; // x19
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  unsigned int v10; // w19
  __int64 v11; // x20
  __int64 v12; // x21

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a2 )
      goto LABEL_3;
LABEL_12:
    printk(&unk_1905C, "power_deinit", 965, v5, a5);
    return 4294967274LL;
  }
  v10 = a1;
  v11 = a2;
  v12 = v5;
  printk(&unk_1E83A, "power_deinit", 962, a4, a5);
  a1 = v10;
  v5 = v12;
  a2 = v11;
  if ( !v11 )
    goto LABEL_12;
LABEL_3:
  if ( a1 >= 4 )
  {
    __break(0x5512u);
    return power_notification();
  }
  else
  {
    v6 = (_QWORD *)(a2 + 176LL * a1);
    v7 = v6[23];
    if ( v7 )
    {
      kfree(v7);
      v6[23] = 0;
    }
    v8 = v6[22];
    if ( v8 )
    {
      kfree(v8);
      v6[22] = 0;
    }
    result = v6[21];
    if ( result )
    {
      kfree(result);
      result = 0;
      v6[21] = 0;
    }
  }
  return result;
}
