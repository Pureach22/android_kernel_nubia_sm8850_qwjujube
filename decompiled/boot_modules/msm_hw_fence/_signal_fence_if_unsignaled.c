bool __fastcall signal_fence_if_unsignaled(__int64 a1, __int64 a2, unsigned __int64 a3, unsigned int a4, char a5)
{
  __int64 v10; // x28
  __int64 v11; // x9
  unsigned int v12; // w25
  unsigned int v13; // w20
  unsigned int v14; // w8
  unsigned __int64 *v15; // x26
  __int64 v16; // x21
  __int64 v17; // x27
  unsigned __int64 v18; // x25
  unsigned __int64 v19; // t1
  unsigned __int64 v20; // x27
  _BOOL4 v21; // w24
  int v22; // w20
  unsigned int v24; // [xsp+Ch] [xbp-24h]
  __int64 v25; // [xsp+10h] [xbp-20h]
  char v26; // [xsp+1Ch] [xbp-14h]
  unsigned __int64 v27; // [xsp+20h] [xbp-10h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  global_atomic_store(a1, a2 + 40, 1);
  v10 = *(_QWORD *)(a2 + 48);
  if ( (v10 & 1) != 0 )
  {
    global_atomic_store(a1, a2 + 40, 0);
  }
  else
  {
    v11 = *(_QWORD *)(a2 + 24);
    v12 = *(_DWORD *)(a2 + 80);
    v13 = *(_DWORD *)(a2 + 116);
    *(_DWORD *)(a2 + 4) = a4;
    v25 = v11;
    *(_QWORD *)(a2 + 48) = v10 | 1;
    *(_DWORD *)(a2 + 80) = 0;
    global_atomic_store(a1, a2 + 40, 0);
    v26 = a5;
    if ( (a5 & 1) != 0 )
      v14 = v13;
    else
      v14 = 0;
    v27 = a3;
    v24 = v14;
    if ( v12 >= 4 )
    {
      printk(&unk_24044, "_signal_parent_fences", 2318, v28, a3);
      v12 = 3;
      goto LABEL_7;
    }
    if ( v12 )
    {
LABEL_7:
      v15 = (unsigned __int64 *)(a2 + 56);
      v16 = v12;
      while ( 1 )
      {
        v19 = *v15++;
        v18 = v19;
        if ( v19 >= *(unsigned int *)(a1 + 16) )
          break;
        v20 = *(_QWORD *)(a1 + 64) + (v18 << 7);
        if ( !v20 )
        {
          v17 = v28;
          goto LABEL_9;
        }
        v21 = 1;
        global_atomic_store(a1, v20 + 40, 1);
        v22 = *(_DWORD *)(v20 + 84);
        *(_DWORD *)(v20 + 4) |= a4;
        if ( v22 )
        {
          v21 = v22 == 1;
          *(_DWORD *)(v20 + 84) = v22 - 1;
        }
        global_atomic_store(a1, v20 + 40, 0);
        __dsb(0xEu);
        if ( !v22 )
        {
          printk(&unk_22D1A, "_update_and_get_join_fence_signal_status", 2003, v28, *(_QWORD *)(v20 + 8));
          if ( !v21 )
            goto LABEL_10;
LABEL_17:
          signal_all_wait_clients(
            a1,
            v20,
            *(_QWORD *)(v20 + 24),
            v18,
            *(unsigned int *)(v20 + 4),
            *(unsigned int *)(v20 + 116));
          hw_fence_destroy_refcount(a1, v18, 0x80000000);
          goto LABEL_10;
        }
        if ( v21 )
          goto LABEL_17;
LABEL_10:
        if ( !--v16 )
          goto LABEL_22;
      }
      v17 = v28;
      printk(&unk_23ADB, "_get_hw_fence", 1135, v28, v18);
LABEL_9:
      printk(&unk_28827, "_signal_parent_fences", 2327, v17, v18);
      goto LABEL_10;
    }
LABEL_22:
    signal_all_wait_clients(a1, a2, v25, v27, a4, v24);
    if ( (v26 & 1) != 0 )
      hw_fence_destroy_refcount(a1, v27, 0x80000000);
  }
  return (v10 & 1) == 0;
}
