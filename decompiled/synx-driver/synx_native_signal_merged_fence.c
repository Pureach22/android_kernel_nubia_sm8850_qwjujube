__int64 __fastcall synx_native_signal_merged_fence(__int64 a1)
{
  __int64 v1; // x5
  unsigned int child_coredata; // w20
  __int64 v3; // x19
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  __int64 v6; // x21
  int object_status_locked; // w0
  __int64 v8; // x8
  unsigned int status; // w0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  int v16; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v15 = 0;
  child_coredata = synx_get_child_coredata(a1, &v15, &v16);
  if ( !child_coredata )
  {
    if ( v16 < 1 )
    {
      child_coredata = 0;
    }
    else
    {
      v3 = 0;
      child_coredata = 0;
      while ( 1 )
      {
        v4 = *(_QWORD *)(v15 + 8 * v3);
        if ( !v4 )
          break;
        if ( v4 > 0xFFFFFFFFFFFFF000LL )
          break;
        v5 = *(_QWORD *)(v4 + 64);
        if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
          break;
        mutex_lock(v4 + 72);
        v6 = raw_spin_lock_irqsave(**(_QWORD **)(*(_QWORD *)(v15 + 8 * v3) + 64LL));
        object_status_locked = synx_util_get_object_status_locked(*(_QWORD *)(v15 + 8 * v3));
        v8 = *(_QWORD *)(v15 + 8 * v3);
        if ( object_status_locked == 1 && v8 && (*(_BYTE *)(v8 + 124) & 2) != 0 )
        {
          raw_spin_unlock_irqrestore(**(_QWORD **)(v8 + 64), v6);
          status = synx_global_get_status(*(unsigned int *)(*(_QWORD *)(v15 + 8 * v3) + 344LL));
          child_coredata = synx_native_signal_fence(*(_QWORD *)(v15 + 8 * v3), status, v10, v11, v12, v13);
        }
        else
        {
          raw_spin_unlock_irqrestore(**(_QWORD **)(v8 + 64), v6);
        }
        mutex_unlock(*(_QWORD *)(v15 + 8 * v3++) + 72LL);
        if ( v3 >= v16 )
          goto LABEL_19;
      }
      if ( (synx_debug & 1) != 0 )
        printk(&unk_2B073, &unk_29207, "synx_native_signal_merged_fence", 615, (unsigned int)v3, v1);
      child_coredata = -2;
    }
LABEL_19:
    kfree(v15);
  }
  _ReadStatusReg(SP_EL0);
  return child_coredata;
}
