__int64 __fastcall sde_encoder_helper_update_out_fence_txq(
        _QWORD *a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x20
  void *v13; // x0
  char v14; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return printk(&unk_2382D0, "sde_encoder_helper_update_out_fence_txq");
  v8 = a1[170];
  if ( !v8 )
    return printk(&unk_2382D0, "sde_encoder_helper_update_out_fence_txq");
  if ( !*a1 )
  {
    v13 = &unk_26FCAB;
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(*a1 + 56LL);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 8)) == 0 )
  {
    v13 = &unk_234896;
LABEL_11:
    printk(v13, "sde_encoder_get_kms");
    return printk(&unk_234896, "sde_encoder_helper_update_out_fence_txq");
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_helper_update_out_fence_txq",
    5396,
    -1,
    *(_DWORD *)(v8 + 112),
    a2 & 1,
    -1059143953,
    a8,
    v14);
  return sde_fence_update_hw_fences_txq(*(_QWORD *)(v8 + 3232), a2 & 1, 0, *(unsigned int *)(v10 + 6400));
}
