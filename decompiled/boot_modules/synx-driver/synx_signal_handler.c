__int64 __fastcall synx_signal_handler(__int64 a1)
{
  __int64 v2; // x19
  unsigned int v3; // w20
  unsigned __int64 v4; // x21
  unsigned int v5; // w23
  int status; // w24
  unsigned int v7; // w24
  bool v8; // cc
  int v9; // w27
  unsigned int v10; // w25
  void *v11; // x0
  __int64 v12; // x3
  __int64 v13; // x5
  __int64 result; // x0
  unsigned int v15; // w0
  __int64 v16; // x5

  v2 = a1 - 56;
  v3 = *(_DWORD *)(a1 - 56);
  v4 = *(_QWORD *)(a1 - 40);
  v5 = *(_DWORD *)(a1 - 52);
  if ( (*(_BYTE *)(a1 - 32) & 2) == 0 )
    goto LABEL_13;
  if ( v4 )
  {
    if ( (*(_BYTE *)(v4 + 124) & 2) != 0 )
    {
      status = synx_global_get_status(*(unsigned int *)(v4 + 344));
      if ( v4 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_12;
    }
    else
    {
      status = 1;
      if ( v4 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_12;
    }
    mutex_lock(v4 + 72);
    if ( (*(_BYTE *)(v4 + 124) & 0x20) != 0 )
    {
      if ( status == 1 )
        status = synx_get_child_status(v4);
      v5 = status;
      *(_DWORD *)(v4 + 128) = status;
    }
    mutex_unlock(v4 + 72);
  }
LABEL_12:
  if ( (synx_debug & 0x10) != 0 )
  {
    printk(&unk_271F7, "verb", "synx_signal_handler", 729, v3, v5);
    if ( (*(_BYTE *)(a1 - 32) & 2) == 0 )
      goto LABEL_14;
    goto LABEL_16;
  }
LABEL_13:
  if ( (*(_BYTE *)(a1 - 32) & 2) == 0 )
  {
LABEL_14:
    v7 = 0;
    goto LABEL_35;
  }
LABEL_16:
  if ( (v3 & 0x100000) == 0 )
  {
    if ( !v4 )
      goto LABEL_41;
    if ( (*(_BYTE *)(v4 + 124) & 2) == 0 )
      goto LABEL_14;
  }
  if ( v4 )
    v8 = v4 > 0xFFFFFFFFFFFFF000LL;
  else
    v8 = 1;
  v9 = v8;
  if ( v9 == 1 )
    v10 = (unsigned __int16)v3;
  else
    v10 = *(_DWORD *)(v4 + 344);
  if ( (unsigned int)synx_global_get_status(v10) == 1 )
  {
    v7 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))synx_global_update_status_core)(v10, v5, 0);
    if ( v7 && (synx_debug & 1) != 0 )
      printk(&unk_25C4A, &unk_29207, "synx_signal_handler", 743, v3, v7);
  }
  else
  {
    v7 = 0;
  }
  if ( v9 )
    synx_global_put_ref(v10);
LABEL_35:
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_41:
    if ( (unsigned int)__ratelimit(&synx_ratelimit_state, "synx_signal_handler") && (synx_debug & 2) != 0 )
    {
      printk(&unk_2B3A4, "warn", "synx_signal_handler", 764, v3, v13);
      if ( (synx_debug & 0x80) == 0 )
        return kfree(v2);
    }
    else if ( (synx_debug & 0x80) == 0 )
    {
      return kfree(v2);
    }
    printk(&unk_25714, &unk_25D36, "synx_signal_handler", 767, v2, v13);
    return kfree(v2);
  }
  if ( !v7 )
  {
    mutex_lock(v4 + 72);
    if ( (*(_BYTE *)(a1 - 32) & 4) != 0
      && (unsigned int)synx_util_get_object_status(v4) == 1
      && ((*(_BYTE *)(v4 + 124) & 0x20) != 0
        ? (v15 = synx_native_signal_merged_fence(v4))
        : (v15 = synx_native_signal_fence(v4, v5)),
          (v7 = v15) != 0) )
    {
      mutex_unlock(v4 + 72);
      if ( (synx_debug & 1) == 0 )
        goto LABEL_59;
      v11 = &unk_28ACD;
      v12 = 792;
    }
    else
    {
      if ( (unsigned int)synx_util_get_object_status(v4) == 1 )
      {
        mutex_unlock(v4 + 72);
        v7 = 0;
        goto LABEL_59;
      }
      v7 = synx_native_signal_core(v4, v5, (*(_DWORD *)(a1 - 32) >> 3) & 1, *(_QWORD *)(a1 - 48));
      mutex_unlock(v4 + 72);
      if ( !v7 || (synx_debug & 1) == 0 )
        goto LABEL_59;
      v11 = &unk_28E2F;
      v12 = 806;
    }
    goto LABEL_40;
  }
  if ( (synx_debug & 1) != 0 )
  {
    v11 = &unk_25C85;
    v12 = 775;
LABEL_40:
    printk(v11, &unk_29207, "synx_signal_handler", v12, v3, v7);
  }
LABEL_59:
  synx_util_put_object(v4);
  if ( (synx_debug & 0x80) != 0 )
    printk(&unk_25714, &unk_25D36, "synx_signal_handler", 811, v2, v16);
  result = kfree(v2);
  if ( (synx_debug & 0x10) != 0 )
    return printk(&unk_29B8A, "verb", "synx_signal_handler", 814, v3, v7);
  return result;
}
