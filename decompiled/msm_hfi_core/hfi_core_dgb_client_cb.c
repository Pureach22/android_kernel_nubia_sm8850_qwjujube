__int64 __fastcall hfi_core_dgb_client_cb(_DWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x8
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 result; // x0
  _DWORD *v10; // x21
  __int64 v11; // x22
  __int64 v12; // x23
  unsigned int v19; // w10

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_9:
      printk(&unk_1905C, "hfi_core_dgb_client_cb", 1337, v5, a5);
      return 4294967274LL;
    }
  }
  else
  {
    v10 = a1;
    v11 = a2;
    v12 = v5;
    printk(&unk_1E83A, "hfi_core_dgb_client_cb", 1334, a4, a5);
    a1 = v10;
    v5 = v12;
    a2 = v11;
    if ( !v10 )
      goto LABEL_9;
  }
  if ( !a2 )
    goto LABEL_9;
  v6 = 1LL << *a1;
  _X9 = (unsigned int *)(a2 + 80);
  __asm { PRFM            #0x11, [X9] }
  do
    v19 = __ldxr(_X9);
  while ( __stxr(v19 | v6, _X9) );
  _wake_up(a2 + 88, 3, 0, 0);
  result = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "hfi_core_dgb_client_cb", 1347, v7, v8);
    return 0;
  }
  return result;
}
