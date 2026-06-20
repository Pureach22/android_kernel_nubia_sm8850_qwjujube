__int64 __fastcall hfi_dbg_recovery_reg_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  void *v6; // x0
  int v7; // w8
  __int64 v8; // x0

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = hfi_dbg;
    if ( hfi_dbg )
    {
      v6 = *(void **)(hfi_dbg + 384);
      *(_DWORD *)(hfi_dbg + 376) = 0;
      if ( v6 )
      {
LABEL_5:
        memset(v6, 0, 0x1000u);
        v7 = *(_DWORD *)(a2 + 12);
        *(_QWORD *)(a2 + 32) = v5;
        *(_DWORD *)(a2 + 12) = v7 & 0xFFFFFFE3;
        return 0;
      }
      v8 = _kvmalloc_node_noprof(4096, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(hfi_dbg + 384) = v8;
      if ( v8 )
      {
        printk(&unk_21D243, "hfi_dbg_recovery_reg_open");
        v5 = hfi_dbg;
        v6 = *(void **)(hfi_dbg + 384);
        goto LABEL_5;
      }
      return 4294967284LL;
    }
    else
    {
      printk(&unk_256B06, "hfi_dbg_recovery_reg_open");
      return 4294967274LL;
    }
  }
  return result;
}
