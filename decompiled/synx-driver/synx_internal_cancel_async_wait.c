__int64 __fastcall synx_internal_cancel_async_wait(unsigned __int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  unsigned __int64 v5; // x21
  unsigned __int64 client; // x0
  __int64 v7; // x4
  __int64 v8; // x5
  unsigned __int64 v9; // x19
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x20
  __int64 v12; // x4
  __int64 v13; // x5
  unsigned int v14; // w21
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x8
  __int64 v18; // x4
  __int64 v19; // x5
  _QWORD *v20; // x26
  unsigned __int64 v21; // x9
  unsigned int *v22; // x8
  _QWORD *v23; // x23
  __int64 v24; // x10
  __int64 v25; // x25
  int v26; // w27
  _QWORD *v27; // x8
  __int64 v28; // x9
  _QWORD *v29; // x8
  _QWORD *v30; // x9
  unsigned __int64 v31; // x20
  char v32; // w9
  char v33; // [xsp+4h] [xbp-3Ch]
  unsigned __int64 v34; // [xsp+10h] [xbp-30h]
  __int64 v35; // [xsp+18h] [xbp-28h] BYREF
  __int64 v36; // [xsp+20h] [xbp-20h]
  __int64 v37; // [xsp+28h] [xbp-18h]
  __int64 v38; // [xsp+30h] [xbp-10h]
  __int64 v39; // [xsp+38h] [xbp-8h]

  result = 4294967274LL;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL || !a2 || (unsigned __int64)a2 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_74;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v5 = a1;
  client = synx_get_client(a1);
  if ( !client || (v9 = client, client >= 0xFFFFFFFFFFFFF001LL) )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_2B010, &unk_29207, "synx_internal_cancel_async_wait", 1218, v7, v8);
    result = 4294967274LL;
    goto LABEL_74;
  }
  v10 = synx_util_acquire_handle(client, *a2);
  if ( !v10 || v10 > 0xFFFFFFFFFFFFF000LL || (v11 = *(_QWORD *)(v10 + 8)) == 0 || v11 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v31 = v10;
      printk(&unk_29EEC, &unk_29207, "synx_internal_cancel_async_wait", 1227, *(_QWORD *)(v9 + 104), *a2);
      v10 = v31;
    }
    v14 = -22;
    goto LABEL_73;
  }
  v34 = v10;
  mutex_lock(v11 + 72);
  if ( (*(_DWORD *)(v11 + 124) & 0x24) == 4 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_25ABF, &unk_29207, "synx_internal_cancel_async_wait", 1235, v12, v13);
    goto LABEL_14;
  }
  v15 = *((_QWORD *)a2 + 1);
  v16 = *((_QWORD *)a2 + 2);
  v17 = *((_QWORD *)a2 + 3);
  LODWORD(v35) = *a2;
  v36 = v16;
  v37 = v15;
  v38 = v17;
  if ( (unsigned int)synx_util_get_object_status(v11) != 1 )
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_28412, &unk_29207, "synx_internal_cancel_async_wait", 1248, *a2, v19);
    goto LABEL_71;
  }
  v20 = *(_QWORD **)(v11 + 328);
  if ( v20 == (_QWORD *)(v11 + 328) )
  {
    v32 = synx_debug;
    v22 = a2;
LABEL_69:
    if ( (v32 & 1) != 0 )
      printk(&unk_25F6A, &unk_29207, "synx_internal_cancel_async_wait", 1308, *(_QWORD *)(v9 + 104), *v22);
LABEL_71:
    v14 = -22;
    goto LABEL_72;
  }
  v21 = v5;
  v33 = 0;
  v22 = a2;
  do
  {
    v23 = (_QWORD *)*v20;
    if ( *(v20 - 13) != v21 )
      goto LABEL_26;
    v24 = *((unsigned int *)v20 - 24);
    if ( (unsigned int)(v24 - 4096) <= 0xFFFFF000 )
    {
      if ( (synx_debug & 1) != 0 )
      {
        printk(&unk_25284, &unk_29207, "synx_internal_cancel_async_wait", 1269, *(_QWORD *)(v9 + 104), v19);
        v21 = v5;
        v22 = a2;
      }
    }
    else
    {
      v25 = v9 + 728 + (v24 << 6);
      if ( &STACK[0x1018] != nullptr && (unsigned __int64)&v35 >= 0xFFFFFFFFFFFFF000LL
        || v25 == -16
        || (unsigned __int64)(v25 + 16) >= 0xFFFFFFFFFFFFF001LL )
      {
        if ( (synx_debug & 1) != 0 )
        {
          printk(&unk_26EFE, &unk_29207, "synx_match_payload", 972, v18, v19);
          v21 = v5;
          v22 = a2;
        }
        v26 = -22;
      }
      else if ( *(_QWORD *)(v25 + 32) == v37 && *(_QWORD *)(v25 + 24) == v36 )
      {
        if ( v38 )
        {
          *(_QWORD *)(v25 + 32) = v38;
          v26 = 1;
        }
        else
        {
          if ( (synx_debug & 0x10) != 0 )
          {
            printk(&unk_27DD6, "verb", "synx_match_payload", 985, v18, v19);
            v21 = v5;
            v22 = a2;
          }
          v26 = 2;
        }
      }
      else
      {
        v26 = 0;
      }
      v19 = *(v20 - 5);
      if ( v19 != -1 )
      {
        if ( (synx_debug & 0x10) != 0 )
          printk(&unk_27236, "verb", "synx_internal_cancel_async_wait", 1278, v20 - 13, v19);
        timer_delete_sync(v20 - 10);
        v22 = a2;
        v21 = v5;
      }
      if ( v26 == 2 )
      {
        if ( (unsigned int)synx_util_clear_cb_entry(v9, v25) && (synx_debug & 1) != 0 )
          printk(&unk_28099, &unk_29207, "synx_internal_cancel_async_wait", 1295, *(_QWORD *)(v9 + 104), *a2);
        v29 = (_QWORD *)v20[1];
        if ( (_QWORD *)*v29 == v20 && (v30 = (_QWORD *)*v20, *(_QWORD **)(*v20 + 8LL) == v20) )
        {
          v30[1] = v29;
          *v29 = v30;
        }
        else
        {
          _list_del_entry_valid_or_report(v20);
        }
        *v20 = v20;
        v20[1] = v20;
        kfree(v20 - 13);
      }
      else
      {
        if ( v26 != 1 )
          goto LABEL_26;
        v27 = (_QWORD *)v20[1];
        if ( (_QWORD *)*v27 == v20 && (v28 = *v20, *(_QWORD **)(*v20 + 8LL) == v20) )
        {
          *(_QWORD *)(v28 + 8) = v27;
          *v27 = v28;
        }
        else
        {
          _list_del_entry_valid_or_report(v20);
        }
        *v20 = v20;
        v20[1] = v20;
        *((_DWORD *)v20 - 22) = 4;
        queue_work_on(32, *(_QWORD *)(synx_dev + 160), v20 - 4);
      }
      v21 = v5;
      v33 = 1;
      v22 = a2;
    }
LABEL_26:
    v20 = v23;
  }
  while ( v23 != (_QWORD *)(v11 + 328) );
  v32 = synx_debug;
  if ( (v33 & 1) == 0 )
    goto LABEL_69;
  if ( (synx_debug & 0x10) != 0 )
    printk(&unk_25CC1, "verb", "synx_internal_cancel_async_wait", 1314, *(_QWORD *)(v9 + 104), *v22);
LABEL_14:
  v14 = 0;
LABEL_72:
  mutex_unlock(v11 + 72);
  v10 = v34;
LABEL_73:
  synx_util_release_handle(v10);
  synx_put_client(v9);
  result = v14;
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return result;
}
