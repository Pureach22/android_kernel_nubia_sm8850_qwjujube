__int64 __fastcall hw_fence_dbg_release(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  unsigned __int64 v7; // x4
  unsigned __int64 v8; // x5
  __int64 v9; // x20
  int v10; // w0
  __int64 v11; // x4
  __int64 v12; // x20

  if ( result )
  {
    v6 = result;
    if ( (~msm_hw_fence_debug_level & 0x10001) != 0 )
    {
      if ( (*(_QWORD *)(result + 48) & 0x80000000) == 0 )
        goto LABEL_13;
    }
    else
    {
      v12 = v5;
      printk(&unk_25352, "hw_fence_dbg_release", 87, result, a5);
      v5 = v12;
      if ( (*(_QWORD *)(v6 + 48) & 0x80000000) == 0 )
        goto LABEL_13;
    }
    v7 = *(_QWORD *)(v6 + 128);
    if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( *(_BYTE *)(v6 + 140) != 1 )
      {
        v9 = v5;
        v10 = msm_hw_fence_destroy(*(_QWORD *)(v6 + 128), v6);
LABEL_11:
        if ( v10 )
          printk(&unk_29C4C, "_hw_fence_release", 77, v9, v11);
        goto LABEL_13;
      }
      v8 = *(_QWORD *)(v6 + 168);
      if ( v8 && v8 < 0xFFFFFFFFFFFFF001LL )
      {
        v9 = v5;
        v10 = hw_fence_destroy_refcount(*(_QWORD *)(v6 + 168), *(_QWORD *)(v6 + 176), 0x40000000);
        goto LABEL_11;
      }
    }
    printk(&unk_2484B, "_hw_fence_release", 65, v5, v7);
LABEL_13:
    kfree(*(_QWORD *)v6);
    return kfree(v6);
  }
  return result;
}
