__int64 __fastcall gsi_ctrl_send_notification(__int64 a1)
{
  _QWORD *v1; // x22
  __int64 v3; // x0
  _QWORD *v4; // x21
  __int64 v5; // x20
  __int64 result; // x0
  unsigned __int8 *v7; // x23
  int v8; // w8
  _QWORD *v9; // x24
  __int64 *v10; // x8
  __int64 v11; // x10
  _QWORD *v12; // x9
  unsigned int v13; // w11
  unsigned int v14; // w10
  int v15; // w10
  __int64 v16; // x8
  unsigned int v17; // w9
  unsigned int v18; // w8
  int v19; // w2
  _QWORD *v20; // x8
  __int64 v21; // x9
  unsigned int v22; // w20
  __int64 v23; // x0
  __int64 v24; // x8
  unsigned int v25; // w19

  v1 = *(_QWORD **)(a1 + 1216);
  if ( *(_DWORD *)(a1 + 272) )
  {
    v3 = raw_spin_lock_irqsave(a1 + 1304);
    v4 = *(_QWORD **)(a1 + 1280);
    v5 = v3;
    if ( v4 != (_QWORD *)(a1 + 1280) )
    {
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 1344),
          "%s: notify_req_queued:%d\n",
          "gsi_ctrl_send_notification",
          *(unsigned __int8 *)(a1 + 1224));
        if ( (*(_BYTE *)(a1 + 1224) & 1) != 0 )
        {
          raw_spin_unlock_irqrestore(a1 + 1304, v5);
          ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: notify_req is already queued.\n", "gsi_ctrl_send_notification");
          return 0;
        }
        v4 = *(_QWORD **)(a1 + 1280);
        v7 = (unsigned __int8 *)(a1 + 1224);
        ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: cpkt->type:%d\n", "gsi_ctrl_send_notification", *((_DWORD *)v4 - 1));
      }
      else
      {
        v7 = (unsigned __int8 *)&byte_4C8;
        if ( (byte_4C8 & 1) != 0 )
        {
          raw_spin_unlock_irqrestore(1304, v3);
          return 0;
        }
      }
      v8 = *((_DWORD *)v4 - 1);
      v9 = (_QWORD *)*v1;
      if ( v8 > 2 )
      {
        if ( v8 != 3 )
        {
          if ( v8 == 4 )
          {
            *((_WORD *)v9 + 1) = 0;
            *((_BYTE *)v9 + 1) = 1;
            *((_WORD *)v9 + 3) = 0;
            if ( *(_DWORD *)(a1 + 224) )
              goto LABEL_53;
            *(_QWORD *)*v1 = 1;
            goto LABEL_48;
          }
LABEL_27:
          raw_spin_unlock_irqrestore(a1 + 1304, v5);
          if ( a1 )
          {
            ipc_log_string(*(_QWORD *)(a1 + 1344), "%s:unknown notify state", "gsi_ctrl_send_notification");
            printk(&unk_10742, "gsi_ctrl_send_notification");
          }
          __break(0x800u);
          return 4294967274LL;
        }
        *((_BYTE *)v9 + 1) = 0;
        *((_WORD *)v9 + 1) = 0;
      }
      else
      {
        if ( v8 != 1 )
        {
          if ( v8 == 2 )
          {
            v10 = *(__int64 **)(*(_QWORD *)(a1 + 48) + 48LL);
            *((_BYTE *)v9 + 1) = 42;
            *((_WORD *)v9 + 1) = 0;
            *((_WORD *)v9 + 3) = 8;
            v11 = *v10;
            v12 = (_QWORD *)*v1;
            v13 = *(_DWORD *)(*v10 + 76);
            if ( v13 >= 5 )
            {
              v14 = *(_DWORD *)(v11 + 72);
              if ( v14 > 4 )
              {
                v15 = 851968000;
                goto LABEL_38;
              }
            }
            else
            {
              if ( v13 < 3 )
                goto LABEL_37;
              v14 = *(_DWORD *)(v11 + 72);
            }
            if ( v14 == 3 )
            {
              v15 = 425984000;
              goto LABEL_38;
            }
LABEL_37:
            v15 = 9728000;
LABEL_38:
            *((_DWORD *)v12 + 2) = v15;
            *((_DWORD *)v12 + 3) = v15;
            if ( a1 )
            {
              v16 = *v10;
              v17 = *(_DWORD *)(v16 + 76);
              if ( v17 >= 5 )
              {
                v18 = *(_DWORD *)(v16 + 72);
                if ( v18 > 4 )
                {
                  v19 = 851968000;
LABEL_47:
                  ipc_log_string(*(_QWORD *)(a1 + 1344), "notify speed %d", v19);
                  goto LABEL_48;
                }
              }
              else
              {
                if ( v17 < 3 )
                  goto LABEL_46;
                v18 = *(_DWORD *)(v16 + 72);
              }
              if ( v18 == 3 )
              {
                v19 = 425984000;
                goto LABEL_47;
              }
LABEL_46:
              v19 = 9728000;
              goto LABEL_47;
            }
LABEL_48:
            v20 = (_QWORD *)v4[1];
            if ( (_QWORD *)*v20 == v4 && (v21 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
            {
              *(_QWORD *)(v21 + 8) = v20;
              *v20 = v21;
            }
            else
            {
              _list_del_entry_valid_or_report(v4);
            }
            *v4 = 0xDEAD000000000100LL;
            v4[1] = 0xDEAD000000000122LL;
            if ( v4 != &qword_10 )
            {
              kfree(*(v4 - 2));
              kfree(v4 - 2);
            }
LABEL_53:
            *v7 = 1;
            raw_spin_unlock_irqrestore(a1 + 1304, v5);
            if ( a1 )
              ipc_log_string(*(_QWORD *)(a1 + 1344), "send Notify type %02x", *((unsigned __int8 *)v9 + 1));
            if ( (*(_BYTE *)(a1 + 284) & 1) != 0 )
            {
              LODWORD(result) = -95;
            }
            else
            {
              result = usb_ep_queue(*(_QWORD *)(a1 + 1208), *(_QWORD *)(a1 + 1216), 2080);
              if ( (result & 0x80000000) == 0 && *(_BYTE *)(a1 + 284) != 1 )
                goto LABEL_60;
            }
            v22 = result;
            v23 = raw_spin_lock_irqsave(a1 + 1304);
            *v7 = 0;
            raw_spin_unlock_irqrestore(a1 + 1304, v23);
            result = v22;
LABEL_60:
            if ( a1 )
            {
              v24 = *(_QWORD *)(a1 + 1344);
              v25 = result;
              ipc_log_string(v24, "%s: ret:%d req_queued:%d", "queue_notification_request", result, *v7);
              return v25;
            }
            return result;
          }
          goto LABEL_27;
        }
        *((_BYTE *)v9 + 1) = 0;
        *((_WORD *)v9 + 1) = 1;
      }
      *((_WORD *)v9 + 3) = 0;
      goto LABEL_48;
    }
    raw_spin_unlock_irqrestore(a1 + 1304, v3);
    if ( a1 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: cpkt_resp_q is empty\n", "gsi_ctrl_send_notification");
      return 0;
    }
    return 0;
  }
  else
  {
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: cable disconnect", "gsi_ctrl_send_notification");
    return 4294967277LL;
  }
}
