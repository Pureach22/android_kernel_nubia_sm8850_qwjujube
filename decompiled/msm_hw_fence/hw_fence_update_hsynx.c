__int64 __fastcall hw_fence_update_hsynx(__int64 a1, unsigned __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // x30
  __int64 v5; // x21
  unsigned __int64 v8; // x24
  __int64 v11; // x0
  int v12; // w8
  bool v13; // zf
  char v14; // w25
  __int64 (__fastcall *v15)(__int64); // x8
  unsigned int v16; // w23
  __int64 v18; // x20

  v5 = v4;
  if ( *(unsigned int *)(a1 + 16) <= a2 )
  {
    v18 = v4;
    printk(&unk_23ADB, "_get_hw_fence", 1135, v4, a2);
LABEL_21:
    printk(&unk_21E33, "hw_fence_update_hsynx", 2716, v18, a2);
    return (unsigned int)-22;
  }
  v8 = *(_QWORD *)(a1 + 64) + (a2 << 7);
  if ( !v8 )
  {
    v18 = v4;
    goto LABEL_21;
  }
  v11 = global_atomic_store(a1, v8 + 40, 1);
  v12 = *(_DWORD *)(v8 + 116);
  if ( v12 )
    v13 = v12 == a3;
  else
    v13 = 1;
  v14 = v13;
  if ( v13 )
  {
    *(_DWORD *)(v8 + 116) = a3;
    if ( (a4 & 1) != 0 )
    {
      v15 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v16 = 0;
      *(_QWORD *)(v8 + 104) = v15(v11);
    }
    else
    {
      v16 = 0;
    }
  }
  else
  {
    v16 = -22;
  }
  global_atomic_store(a1, v8 + 40, 0);
  __dsb(0xEu);
  if ( (v14 & 1) == 0 )
    printk(&unk_272B8, "hw_fence_update_hsynx", 2735, v5, a3);
  return v16;
}
