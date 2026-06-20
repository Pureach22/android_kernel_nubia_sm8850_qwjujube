__int64 __fastcall tmecom_process_request(const void *a1, size_t a2, void *a3, __int64 *a4)
{
  _QWORD *v4; // x19
  __int64 result; // x0
  __int64 v6; // x0
  const char *v7; // x1
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x0
  unsigned int v15; // w20
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x0
  _QWORD v19[6]; // [xsp+0h] [xbp-30h] BYREF

  v19[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (_QWORD *)tmedev;
  if ( !tmedev )
  {
    printk(&unk_67CA, "tmecom_process_request", 106, "tmecom_process_request");
    result = 4294967277LL;
    goto LABEL_11;
  }
  if ( !a1 || a2 - 1025 <= 0xFFFFFFFFFFFFFBFFLL )
  {
    v6 = *(_QWORD *)tmedev;
    v7 = "invalid reqbuf or reqsize\n";
    goto LABEL_10;
  }
  if ( !a3 || !a4 || (unsigned __int64)*a4 >= 0x401 )
  {
    v6 = *(_QWORD *)tmedev;
    v7 = "invalid respbuf or respsize\n";
LABEL_10:
    dev_err(v6, v7);
    result = 4294967274LL;
    goto LABEL_11;
  }
  mutex_lock(tmedev + 72);
  v12 = v4[20];
  *((_BYTE *)v4 + 168) = 0;
  memcpy((void *)(v12 + 8), a1, a2);
  v13 = v4[20];
  *((_DWORD *)v4 + 30) = ((_WORD)a2 + 11) & 0xFFC;
  v14 = v4[8];
  v4[16] = v13;
  if ( (mbox_send_message(v14, v4 + 15) & 0x80000000) != 0 )
  {
    dev_err(*v4, "failed to send qmp message\n");
    v15 = -11;
  }
  else
  {
    v16 = v4[3];
    if ( ((_BYTE)v4[21] & (v16 == 0)) != 0 )
      v17 = 1;
    else
      v17 = v4[3];
    if ( (v4[21] & 1) == 0 && v17 )
    {
      memset(v19, 0, 40);
      init_wait_entry(v19, 0);
      v17 = prepare_to_wait_event(v4 + 17, v19, 1);
      if ( ((_BYTE)v4[21] & (v16 == 0)) != 0 )
        v16 = 1;
      if ( (v4[21] & 1) != 0 || !v16 )
      {
LABEL_28:
        finish_wait(v4 + 17, v19);
        v17 = v16;
      }
      else
      {
        while ( !v17 )
        {
          v16 = schedule_timeout(v16);
          v17 = prepare_to_wait_event(v4 + 17, v19, 1);
          if ( ((_BYTE)v4[21] & (v16 == 0)) != 0 )
            v16 = 1;
          if ( (v4[21] & 1) != 0 || !v16 )
            goto LABEL_28;
        }
      }
    }
    if ( v17 )
    {
      dev_info(*v4, "response received\n");
      if ( *((_DWORD *)v4 + 30) <= 0xCu )
      {
        dev_err(*v4, "invalid pkt.size received\n");
        v15 = -71;
      }
      else
      {
        v18 = tmecom_decode((int)v4, a3);
        v15 = 0;
        *a4 = v18;
        *((_BYTE *)v4 + 168) = 0;
      }
    }
    else
    {
      dev_err(*v4, "request timed out\n");
      v15 = -110;
    }
  }
  mutex_unlock(v4 + 9);
  result = v15;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
