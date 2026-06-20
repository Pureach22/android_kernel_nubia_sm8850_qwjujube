__int64 __fastcall synx_internal_async_wait(unsigned __int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  unsigned __int64 v5; // x24
  unsigned __int64 client; // x0
  __int64 v7; // x4
  __int64 v8; // x5
  unsigned __int64 v9; // x19
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x20
  unsigned __int64 v12; // x22
  unsigned __int64 v13; // x0
  unsigned __int64 v14; // x21
  unsigned int v15; // w25
  __int64 v16; // x8
  __int64 v17; // x10
  unsigned int v18; // w0
  __int64 v19; // x5
  unsigned int v20; // w0
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  unsigned __int64 v25; // x20
  int object_status; // w0
  int v27; // w8
  __int64 v28; // x5
  unsigned __int64 v29; // x2
  __int64 v30; // x8
  unsigned int started; // w0
  __int64 v32; // [xsp+10h] [xbp-30h] BYREF
  __int64 v33; // [xsp+18h] [xbp-28h]
  __int64 v34; // [xsp+20h] [xbp-20h]
  __int64 v35; // [xsp+28h] [xbp-18h]
  int v36; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+38h] [xbp-8h]

  result = 4294967274LL;
  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a1 <= 0xFFFFFFFFFFFFF000LL && a2 && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v36 = 0;
    v32 = 0;
    v33 = 0;
    v5 = a1;
    v34 = 0;
    v35 = 0;
    client = synx_get_client(a1);
    if ( client )
    {
      v9 = client;
      if ( client < 0xFFFFFFFFFFFFF001LL )
      {
        v10 = synx_util_acquire_handle(client, *a2);
        if ( !v10 || v10 > 0xFFFFFFFFFFFFF000LL || (v11 = *(_QWORD *)(v10 + 8)) == 0 || v11 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (synx_debug & 1) != 0 )
          {
            v25 = v10;
            printk(&unk_29EEC, &unk_29207, "synx_internal_async_wait", 1111, *(_QWORD *)(v9 + 104), *a2);
            v10 = v25;
          }
          v15 = -22;
          goto LABEL_41;
        }
        v12 = v10;
        mutex_lock(v11 + 72);
        v13 = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 120);
        v14 = v13;
        v15 = -12;
        if ( v13 && v13 <= 0xFFFFFFFFFFFFF000LL )
        {
          v17 = *((_QWORD *)a2 + 1);
          v16 = *((_QWORD *)a2 + 2);
          LODWORD(v32) = *a2;
          v33 = v16;
          v34 = v17;
          v18 = synx_util_alloc_cb_entry(v9, &v32, &v36);
          if ( v18 )
          {
            v15 = v18;
            if ( (synx_debug & 1) != 0 )
              printk(&unk_265C5, &unk_29207, "synx_internal_async_wait", 1132, *(_QWORD *)(v9 + 104), v19);
            kfree(v14);
          }
          else
          {
            if ( (*a2 & 0x100000) != 0 || (*(_BYTE *)(v11 + 124) & 2) != 0 )
            {
              v20 = synx_global_test_status_set_wait((unsigned __int16)*a2, 0);
              if ( v20 != 1 )
              {
                if ( (*(_BYTE *)(v11 + 124) & 0x20) != 0 )
                  synx_native_signal_merged_fence(v11);
                else
                  synx_native_signal_fence(v11, v20, v21, v22, v23, v24);
              }
            }
            synx_util_activate(v11);
            object_status = synx_util_get_object_status(v11);
            v27 = v36;
            v28 = *a2;
            *(_QWORD *)v14 = v5;
            *(_DWORD *)(v14 + 8) = v27;
            *(_DWORD *)(v14 + 12) = v28;
            *(_QWORD *)(v14 + 72) = 0xFFFFFFFE00000LL;
            v29 = v14 + 72;
            *(_QWORD *)(v14 + 80) = v14 + 80;
            *(_QWORD *)(v14 + 88) = v14 + 80;
            *(_QWORD *)(v14 + 96) = synx_util_cb_dispatch;
            if ( object_status == 1 )
            {
              list_add(v14 + 104, v11 + 328, v29);
              if ( (synx_debug & 0x10) != 0 )
                printk(&unk_2B807, "verb", "synx_internal_async_wait", 1170, *(_QWORD *)(v9 + 104), *a2);
              v30 = *((_QWORD *)a2 + 4);
              *(_QWORD *)(v14 + 64) = v30;
              if ( v30 != -1 )
              {
                started = synx_start_timer(v14);
                if ( started )
                {
                  v15 = started;
                  if ( (synx_debug & 1) != 0 )
                    printk(&unk_27CE1, &unk_29207, "synx_internal_async_wait", 1178, *(_QWORD *)(v9 + 104), v14);
                  goto LABEL_40;
                }
              }
            }
            else
            {
              *(_DWORD *)(v14 + 16) = object_status;
              if ( (synx_debug & 0x10) != 0 )
              {
                printk(&unk_2A8F3, "verb", "synx_internal_async_wait", 1186, *(_QWORD *)(v9 + 104), v28);
                v29 = v14 + 72;
              }
              queue_work_on(32, *(_QWORD *)(synx_dev + 160), v29);
            }
            v15 = 0;
          }
        }
LABEL_40:
        mutex_unlock(v11 + 72);
        v10 = v12;
LABEL_41:
        synx_util_release_handle(v10);
        synx_put_client(v9);
        result = v15;
        goto LABEL_42;
      }
    }
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B010, &unk_29207, "synx_internal_async_wait", 1102, v7, v8);
    result = 4294967274LL;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
