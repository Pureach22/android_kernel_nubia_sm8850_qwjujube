__int64 __fastcall mhi_uci_open(__int64 a1, __int64 a2)
{
  __int64 *v4; // x27
  __int64 v5; // x0
  int v6; // w4
  unsigned int v7; // w0
  __int64 v8; // x22
  int free_desc_count; // w0
  unsigned __int64 v10; // x24
  __int64 v11; // x25
  int v12; // w23
  int v13; // w21
  unsigned __int64 v14; // x28
  bool v17; // w19
  __int64 v18; // x0
  __int64 v19; // x26
  unsigned int v20; // w0
  unsigned int v21; // w20
  __int64 *v23; // x9
  __int64 **v24; // x8
  __int64 *v25; // x22
  __int64 v26; // x0
  __int64 v27; // [xsp+18h] [xbp-8h]

  mutex_lock(&unk_86D0);
  v4 = &mhi_uci_drv;
  do
  {
    v4 = (__int64 *)*v4;
    if ( v4 == &mhi_uci_drv )
      goto LABEL_34;
  }
  while ( *((_DWORD *)v4 + 4) != *(_DWORD *)(a1 + 76) );
  if ( !v4 )
  {
LABEL_34:
    v21 = -5;
    goto LABEL_37;
  }
  mutex_lock(v4 + 6);
  if ( (*((_BYTE *)v4 + 340) & 1) != 0 )
  {
    v5 = v4[44];
    v27 = a2;
    v6 = *((_DWORD *)v4 + 84) + 1;
    *((_DWORD *)v4 + 84) = v6;
    if ( v5 && *((_DWORD *)v4 + 90) <= 1u )
    {
      ipc_log_string();
      v6 = *((_DWORD *)v4 + 84);
    }
    if ( v6 == 1 )
    {
      if ( v4[44] && *((_DWORD *)v4 + 90) <= 1u )
        ipc_log_string();
      v7 = mhi_prepare_for_transfer(v4[4]);
      if ( v7 )
      {
        v21 = v7;
        printk(&unk_7DBC, "mhi_uci_open");
        if ( v4[44] && *((_DWORD *)v4 + 90) <= 2u )
          ipc_log_string();
        --*((_DWORD *)v4 + 84);
      }
      else
      {
        v8 = v4[4];
        free_desc_count = mhi_get_free_desc_count(v8, 2);
        if ( free_desc_count < 1 )
        {
          v21 = -5;
        }
        else
        {
          v10 = v4[40];
          v11 = v4[41];
          v12 = free_desc_count;
          v13 = 0;
          _ReadStatusReg(SP_EL0);
          v14 = v10 - v11;
          v17 = v10 < v11 || v14 < 8 || v11 < 0;
          while ( 1 )
          {
            v18 = _kmalloc_noprof(v10, 3264);
            v19 = v18;
            if ( !v18 )
            {
              v21 = -12;
              goto LABEL_39;
            }
            if ( v17 || v14 < 8 )
            {
              __break(1u);
              return mhi_uci_release();
            }
            *(_QWORD *)(v18 + v11) = v18;
            if ( v4[44] && !*((_DWORD *)v4 + 90) )
              ipc_log_string();
            v20 = mhi_queue_buf(v8, 2, v19, v11, 2);
            if ( v20 )
              break;
            if ( v12 == ++v13 )
              goto LABEL_35;
          }
          v21 = v20;
          kfree(v19);
          printk(&unk_7D40, "mhi_queue_inbound");
          if ( v4[44] && *((_DWORD *)v4 + 90) <= 2u )
            ipc_log_string();
        }
LABEL_39:
        mhi_unprepare_from_transfer(v4[4]);
        v23 = (__int64 *)v4[30];
        if ( v23 != v4 + 30 )
        {
          do
          {
            v25 = (__int64 *)*v23;
            v24 = (__int64 **)v23[1];
            if ( *v24 == v23 && (__int64 *)v25[1] == v23 )
            {
              v25[1] = (__int64)v24;
              *v24 = v25;
            }
            else
            {
              _list_del_entry_valid_or_report(v23);
            }
            v26 = *(v23 - 2);
            *v23 = 0xDEAD000000000100LL;
            v23[1] = 0xDEAD000000000122LL;
            kfree(v26);
            v23 = v25;
          }
          while ( v25 != v4 + 30 );
        }
      }
    }
    else
    {
LABEL_35:
      v21 = 0;
      *(_QWORD *)(v27 + 32) = v4;
    }
  }
  else
  {
    printk(&unk_816D, "mhi_uci_open");
    if ( v4[44] && *((_DWORD *)v4 + 90) <= 2u )
      ipc_log_string();
    v21 = -5;
  }
  mutex_unlock(v4 + 6);
LABEL_37:
  mutex_unlock(&unk_86D0);
  return v21;
}
