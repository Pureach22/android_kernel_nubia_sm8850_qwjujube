__int64 __fastcall msm_hfi_core_remove(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v8; // x21
  __int64 result; // x0
  __int64 v10; // x3
  __int64 v11; // x30
  void *v12; // x0
  __int64 v13; // x2

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_10:
    v11 = v6;
    v12 = &unk_1D58C;
    v13 = 96;
    goto LABEL_13;
  }
  printk(&unk_1E83A, "msm_hfi_core_remove", 93, a4);
  if ( !a1 )
    goto LABEL_10;
LABEL_3:
  v8 = *(_QWORD *)(a1 + 168);
  if ( v8 )
  {
    if ( !(unsigned int)hfi_core_deinit(*(__int64 **)(a1 + 168), a2, a3, a4, a5) )
    {
      *(_QWORD *)(a1 + 168) = 0;
      result = kfree(v8);
      goto LABEL_6;
    }
    v11 = v6;
    v12 = &unk_1BED0;
    v13 = 110;
  }
  else
  {
    v11 = v6;
    v12 = &unk_1F7FF;
    v13 = 103;
  }
LABEL_13:
  result = printk(v12, "msm_hfi_core_remove", v13, v11);
LABEL_6:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    return printk(&unk_1C28B, "msm_hfi_core_remove", 120, v10);
  return result;
}
