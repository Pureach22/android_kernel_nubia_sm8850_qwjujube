__int64 __fastcall hw_fence_dbg_register_clients_wr(__int64 a1, int a2, size_t a3)
{
  __int64 v3; // x30
  __int64 v4; // x21
  __int64 v5; // x19
  unsigned int debugfs_input_client_with_min; // w0
  __int64 v7; // x22
  unsigned int v8; // w20
  _QWORD *v9; // x23
  __int64 v10; // x4
  __int64 v11; // x22
  unsigned __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x21
  _QWORD *v15; // x2
  _QWORD *v16; // x1
  _QWORD *v17; // x0
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = v3;
  v5 = a3;
  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  debugfs_input_client_with_min = get_debugfs_input_client_with_min(a1, a2, a3, v19, 1);
  if ( (debugfs_input_client_with_min & 0x80000000) != 0 )
  {
LABEL_7:
    v5 = -22;
  }
  else
  {
    v7 = v19[0];
    v8 = debugfs_input_client_with_min;
    mutex_lock(v19[0] + 544LL);
    v9 = (_QWORD *)(v7 + 528);
    do
    {
      v9 = (_QWORD *)*v9;
      if ( v9 == (_QWORD *)(v7 + 528) )
      {
        mutex_unlock(v7 + 544);
        goto LABEL_9;
      }
    }
    while ( *((_DWORD *)v9 - 16) != v8 );
    mutex_unlock(v7 + 544);
    if ( v9 != &qword_40 )
    {
      printk(&unk_24DD4, "hw_fence_dbg_register_clients_wr", 303, v4, v8);
      goto LABEL_7;
    }
LABEL_9:
    v11 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
    if ( v11 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
        printk(&unk_276E3, "hw_fence_dbg_register_clients_wr", 311, v8, v10);
      v12 = msm_hw_fence_register(v8, v11 + 32);
      *(_QWORD *)(v11 + 24) = v12;
      if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
      {
        v13 = dma_fence_context_alloc(1);
        v14 = v19[0];
        *(_QWORD *)(v11 + 8) = v13;
        *(_DWORD *)v11 = v8;
        mutex_lock(v14 + 544);
        v15 = *(_UNKNOWN **)((char *)&off_210 + v14);
        v16 = (_QWORD *)(v14 + 528);
        v17 = (_QWORD *)(v11 + 64);
        if ( v15[1] != v14 + 528 || v17 == v16 || v15 == v17 )
        {
          _list_add_valid_or_report(v17);
          v14 = v19[0];
        }
        else
        {
          v15[1] = v17;
          *(_QWORD *)(v11 + 64) = v15;
          *(_QWORD *)(v11 + 72) = v16;
          *v16 = v17;
        }
        mutex_unlock(v14 + 544);
      }
      else
      {
        printk(&unk_22B9E, "hw_fence_dbg_register_clients_wr", 315, v4, v8);
        *(_QWORD *)(v11 + 24) = 0;
        v5 = -14;
      }
    }
    else
    {
      v5 = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
