__int64 __fastcall hfi_dbg_reg_base_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  _QWORD *v6; // x0
  __int64 v7; // x8
  void *v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w19

  result = 4294967274LL;
  if ( !a1 || !a2 )
    return result;
  v5 = hfi_dbg;
  if ( !hfi_dbg )
  {
    printk(&unk_256B06, "hfi_dbg_reg_base_open");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(hfi_dbg + 352) )
  {
    v6 = (_QWORD *)_kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    if ( v6 )
    {
      if ( *(_DWORD *)(v5 + 56) )
      {
        v7 = hfi_dbg;
        *v6 = 0;
        v6[1] = 0;
        v6[2] = v7 + 40;
        *(_QWORD *)(v5 + 352) = v6;
        v5 = v7;
        goto LABEL_8;
      }
      printk(&unk_23EF2A, "_hfi_dbg_reg_base_register");
      v10 = -22;
    }
    else
    {
      v10 = -12;
    }
    printk(&unk_21D270, "hfi_dbg_reg_base_open");
    return v10;
  }
LABEL_8:
  v8 = *(void **)(v5 + 368);
  *(_DWORD *)(v5 + 360) = 0;
  if ( v8 )
  {
LABEL_9:
    memset(v8, 0, 0x1000u);
    *(_DWORD *)(a2 + 12) &= 0xFFFFFFE3;
    *(_QWORD *)(a2 + 32) = *(_QWORD *)(v5 + 352);
    return 0;
  }
  v9 = _kvmalloc_node_noprof(4096, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(hfi_dbg + 368) = v9;
  if ( v9 )
  {
    printk(&unk_21D243, "hfi_dbg_reg_base_open");
    v5 = hfi_dbg;
    v8 = *(void **)(hfi_dbg + 368);
    goto LABEL_9;
  }
  return 4294967284LL;
}
