__int64 __fastcall power_notification(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 result; // x0
  unsigned int v10; // w21
  __int64 v11; // x22
  __int64 v12; // x23
  unsigned int v18; // w9

  _X8 = (unsigned int *)(unsigned int)msm_hfi_core_debug_level;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v10 = a1;
    v11 = a2;
    v12 = v5;
    printk(&unk_1E83A, "power_notification", 992, a4, a5);
    a1 = v10;
    v5 = v12;
    a2 = v11;
    if ( v11 )
      goto LABEL_3;
LABEL_9:
    printk(&unk_1905C, "power_notification", 995, v5, a5);
    return 4294967274LL;
  }
  if ( !a2 )
    goto LABEL_9;
LABEL_3:
  if ( a1 >= 5 )
    __break(0x5512u);
  else
    _X8 = *(unsigned int **)(a2 + 176LL * a1 + 168);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 | 1, _X8) );
  _wake_up();
  result = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "power_notification", 1005, v7, v8);
    return 0;
  }
  return result;
}
