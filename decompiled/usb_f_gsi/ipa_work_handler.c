__int64 __fastcall ipa_work_handler(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x24
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x20
  int v7; // w22
  __int64 v8; // x8
  __int64 result; // x0
  int v10; // w23
  __int64 v11; // x24
  int v12; // w8
  _QWORD *v13; // x20
  __int64 v14; // x8
  __int64 v15; // x0
  void *v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x0
  int v33; // w0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w8
  __int64 v45; // x20
  int v46; // w21
  unsigned int v53; // w9
  char v54[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+8h] [xbp-8h]

  v2 = a1 - 576;
  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 80);
  v54[0] = 0;
  v4 = raw_spin_lock_irqsave(a1 + 248);
  v5 = *(unsigned __int8 *)(a1 + 244);
  v6 = v4;
  if ( v5 == *(unsigned __int8 *)(a1 + 245) )
  {
    if ( v2 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 768), "%s: event queue empty", "read_event");
      raw_spin_unlock_irqrestore(a1 + 248, v6);
      v7 = 0;
      goto LABEL_5;
    }
    result = raw_spin_unlock_irqrestore(a1 + 248, v4);
    if ( !v3 )
      goto LABEL_151;
    v7 = 0;
LABEL_11:
    v10 = 1;
    if ( v3 == -104 )
      goto LABEL_24;
    goto LABEL_12;
  }
  v8 = ((_BYTE)v5 + 1) & 0x7F;
  *(_BYTE *)(a1 + 244) = v8;
  v7 = *(unsigned __int8 *)(a1 + v8 + 116);
  result = raw_spin_unlock_irqrestore(a1 + 248, v4);
  if ( !v2 )
  {
    if ( !v3 )
      goto LABEL_151;
    goto LABEL_11;
  }
LABEL_5:
  result = ipc_log_string(
             *(_QWORD *)(a1 + 768),
             "%s: event = %x sm_state %x",
             "ipa_work_handler",
             v7,
             *(_DWORD *)(a1 + 112));
  if ( !v3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 768), "%s(): gadget is NULL.\n", "ipa_work_handler");
    v16 = &unk_11421;
    goto LABEL_67;
  }
  v10 = 0;
  if ( v3 == -104 )
    goto LABEL_24;
LABEL_12:
  v11 = *(_QWORD *)(v3 + 200);
  if ( v11 )
  {
    v12 = *(_DWORD *)(a1 + 112);
    v13 = (_QWORD *)(a1 - 272);
    if ( v12 > 2 )
    {
      if ( v12 > 5 )
      {
        if ( v12 != 6 )
        {
          if ( v12 == 7 )
          {
            if ( v7 != 7 )
            {
              if ( v7 != 10 )
                goto LABEL_143;
              usb_gadget_autopm_get(*(_QWORD *)(a1 - 80));
              if ( (v10 & 1) == 0 )
              {
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_SUS_EVT_RES", "ipa_work_handler");
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: get = %d", "ipa_work_handler", *(_DWORD *)(v11 + 480));
              }
              ipa_resume_work_handler(a1 - 272);
              goto LABEL_42;
            }
            usb_gadget_autopm_get(*(_QWORD *)(a1 - 80));
            ipa_data_path_disable(a1 - 272);
            ipa_disconnect_channel(a1 - 272);
            *(_DWORD *)(a1 + 112) = 1;
            if ( (v10 & 1) == 0 )
            {
              ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_SUS_EVT_DIS", "ipa_work_handler");
              v19 = *(_QWORD *)(a1 - 80);
              if ( v19 )
                goto LABEL_126;
              goto LABEL_143;
            }
            goto LABEL_125;
          }
          goto LABEL_43;
        }
        if ( v7 == 7 )
        {
          ipa_data_path_disable(a1 - 272);
          ipa_disconnect_channel(a1 - 272);
          v24 = *(_QWORD *)(a1 - 80);
          *(_DWORD *)(a1 + 112) = 1;
          if ( v24 )
          {
            v25 = *(_QWORD *)(v24 + 200);
            if ( v25 )
              _pm_runtime_idle(v25, 5);
          }
          if ( (v10 & 1) == 0 )
          {
            ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_SUS_IN_PROG_EVT_DIS", "ipa_work_handler");
            ipc_log_string(
              *(_QWORD *)(a1 + 768),
              "%s: put_async7 = %d",
              "ipa_work_handler",
              *(unsigned int *)(v11 + 480));
          }
          goto LABEL_143;
        }
        if ( v7 == 10 )
        {
          ipa_resume_work_handler(a1 - 272);
          v22 = *(_QWORD *)(a1 - 80);
          *(_DWORD *)(a1 + 112) = 3;
          if ( v22 && (v23 = *(_QWORD *)(v22 + 200)) != 0 )
          {
            _X8 = (unsigned int *)(v23 + 480);
            __asm { PRFM            #0x11, [X8] }
            do
              v53 = __ldxr(_X8);
            while ( __stxr(v53 + 1, _X8) );
            if ( (v10 & 1) != 0 )
              goto LABEL_143;
          }
          else if ( (v10 & 1) != 0 )
          {
            goto LABEL_143;
          }
          ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_SUS_IN_PROG_EVT_RES", "ipa_work_handler");
          ipc_log_string(*(_QWORD *)(a1 + 768), "%s: get_nores1 = %d", "ipa_work_handler", *(unsigned int *)(v11 + 480));
          goto LABEL_143;
        }
        if ( v7 != 9 )
          goto LABEL_143;
        v17 = *(_QWORD *)(a1 - 80);
        *(_DWORD *)(a1 + 112) = 7;
        if ( v17 )
        {
          v18 = *(_QWORD *)(v17 + 200);
          if ( v18 )
            _pm_runtime_idle(v18, 5);
        }
        if ( (v10 & 1) != 0 )
          goto LABEL_143;
        ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_SUS_IN_PROG_EVT_IPA_SUS", "ipa_work_handler");
      }
      else
      {
        if ( v12 != 3 )
        {
          if ( v12 == 4 )
          {
            if ( v7 != 6 )
            {
              if ( v7 == 7 )
              {
                usb_gadget_autopm_get(*(_QWORD *)(a1 - 80));
                ipa_data_path_disable(a1 - 272);
                v14 = *(_QWORD *)(a1 - 80);
                *(_DWORD *)(a1 + 112) = 1;
                if ( v14 )
                {
                  v15 = *(_QWORD *)(v14 + 200);
                  if ( v15 )
                    _pm_runtime_idle(v15, 5);
                }
                if ( (v10 & 1) == 0 )
                {
                  ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_HOST_NRDY_EVT_DIS", "ipa_work_handler");
                  ipc_log_string(
                    *(_QWORD *)(a1 + 768),
                    "%s: put_async = %d",
                    "ipa_work_handler",
                    *(unsigned int *)(v11 + 480));
                }
              }
              goto LABEL_143;
            }
            usb_gadget_autopm_get(*(_QWORD *)(a1 - 80));
            if ( !v10 )
            {
              ipc_log_string(*(_QWORD *)(a1 + 768), "%s: get = %d", "ipa_work_handler", *(_DWORD *)(v11 + 480));
              if ( (unsigned int)ipa_connect_channels(a1 - 272) )
              {
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ipa_connect_channels failed\n", "ipa_work_handler");
                printk(&unk_1143A, "ipa_work_handler");
                v19 = *(_QWORD *)(a1 - 80);
                if ( v19 )
                {
LABEL_126:
                  v38 = *(_QWORD *)(v19 + 200);
                  if ( v38 )
                    _pm_runtime_idle(v38, 5);
                }
              }
              else
              {
                ipa_data_path_enable(a1 - 272);
                v32 = *(_QWORD *)(a1 + 768);
                *(_DWORD *)(a1 + 112) = 3;
                ipc_log_string(v32, "%s: ST_HOST_NRDY_EVT_HRDY_", "ipa_work_handler");
              }
LABEL_143:
              v43 = raw_spin_lock_irqsave(a1 + 248);
              v44 = *(unsigned __int8 *)(a1 + 244);
              v45 = v43;
              if ( v44 == *(unsigned __int8 *)(a1 + 245) )
              {
                if ( (v10 & 1) == 0 )
                  ipc_log_string(*(_QWORD *)(a1 + 768), "%s: event queue empty", "peek_event");
                result = raw_spin_unlock_irqrestore(a1 + 248, v45);
              }
              else
              {
                v46 = *(unsigned __int8 *)(a1 + (((_BYTE)v44 + 1) & 0x7F) + 116);
                result = raw_spin_unlock_irqrestore(a1 + 248, v43);
                if ( v46 )
                {
                  if ( (v10 & 1) == 0 )
                    ipc_log_string(*(_QWORD *)(a1 + 768), "%s: New events to process", "ipa_work_handler");
                  result = queue_delayed_work_on(32, *(_QWORD *)(a1 + 104), a1, 0);
                }
              }
              goto LABEL_151;
            }
            if ( !(unsigned int)ipa_connect_channels(a1 - 272) )
            {
              ipa_data_path_enable(a1 - 272);
LABEL_42:
              *(_DWORD *)(a1 + 112) = 3;
              goto LABEL_143;
            }
LABEL_125:
            v19 = *(_QWORD *)(a1 - 80);
            if ( v19 )
              goto LABEL_126;
            goto LABEL_143;
          }
LABEL_43:
          if ( (v10 & 1) == 0 )
            ipc_log_string(*(_QWORD *)(a1 + 768), "%s: Invalid state to SM", "ipa_work_handler");
          goto LABEL_143;
        }
        if ( v7 == 5 )
        {
LABEL_48:
          if ( (unsigned __int8)peek_event(a1 - 272) == 6 )
          {
            read_event(a1 - 272);
            if ( (v10 & 1) == 0 )
              ipc_log_string(*(_QWORD *)(a1 + 768), "%s: NO_OP NRDY_RDY", "ipa_work_handler");
            goto LABEL_143;
          }
          if ( v7 == 5 )
          {
            if ( (v10 & 1) == 0 )
              ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_CON_HOST_NRDY\n", "ipa_work_handler");
            v28 = *v13;
            v54[0] = 1;
            usb_gsi_ep_op(v28, v54, 11);
            gsi_rndis_ipa_reset_trigger(a1 - 272);
            usb_gsi_ep_op(*v13, 0, 6);
            usb_gsi_ep_op(*(_QWORD *)(a1 - 264), 0, 6);
            ipa_disconnect_channel(a1 - 272);
            *(_DWORD *)(a1 + 112) = 4;
            if ( (v10 & 1) != 0 )
              goto LABEL_125;
            ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_CON_EVT_HNRDY", "ipa_work_handler");
          }
          else
          {
            ipa_data_path_disable(a1 - 272);
            ipa_disconnect_channel(a1 - 272);
            *(_DWORD *)(a1 + 112) = 1;
            if ( (v10 & 1) != 0 )
              goto LABEL_125;
            ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_CON_EVT_DIS", "ipa_work_handler");
          }
          v41 = *(_QWORD *)(a1 - 80);
          if ( v41 )
          {
            v42 = *(_QWORD *)(v41 + 200);
            if ( v42 )
              _pm_runtime_idle(v42, 5);
          }
          ipc_log_string(*(_QWORD *)(a1 + 768), "%s: put_async4 = %d", "ipa_work_handler", *(unsigned int *)(v11 + 480));
          goto LABEL_143;
        }
        if ( v7 != 8 )
        {
          if ( v7 != 7 )
            goto LABEL_143;
          goto LABEL_48;
        }
        if ( (unsigned __int8)peek_event(a1 - 272) == 7 )
        {
          read_event(a1 - 272);
          ipa_data_path_disable(a1 - 272);
          ipa_disconnect_channel(a1 - 272);
          v20 = *(_QWORD *)(a1 - 80);
          *(_DWORD *)(a1 + 112) = 1;
          if ( v20 )
          {
            v21 = *(_QWORD *)(v20 + 200);
            if ( v21 )
              _pm_runtime_idle(v21, 5);
          }
          if ( (v10 & 1) == 0 )
          {
            ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_CON_EVT_SUS_DIS", "ipa_work_handler");
            ipc_log_string(
              *(_QWORD *)(a1 + 768),
              "%s: put_async5 = %d",
              "ipa_work_handler",
              *(unsigned int *)(v11 + 480));
          }
          goto LABEL_143;
        }
        if ( (unsigned int)ipa_suspend_work_handler(a1 - 272) )
          goto LABEL_143;
        v36 = *(_QWORD *)(a1 - 80);
        if ( v36 )
        {
          v37 = *(_QWORD *)(v36 + 200);
          if ( v37 )
            _pm_runtime_idle(v37, 5);
        }
        if ( (v10 & 1) != 0 )
          goto LABEL_143;
        ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_CON_EVT_SUS", "ipa_work_handler");
      }
      ipc_log_string(*(_QWORD *)(a1 + 768), "%s: put_async6 = %d", "ipa_work_handler", *(unsigned int *)(v11 + 480));
      goto LABEL_143;
    }
    if ( !v12 )
      goto LABEL_143;
    if ( v12 != 1 )
    {
      if ( v12 == 2 )
      {
        switch ( v7 )
        {
          case 8:
            if ( (unsigned __int8)peek_event(a1 - 272) == 7 )
            {
              read_event(a1 - 272);
              ipa_data_path_disable(a1 - 272);
              ipa_disconnect_channel(a1 - 272);
              v29 = *(_QWORD *)(a1 - 80);
              *(_DWORD *)(a1 + 112) = 1;
              if ( v29 )
              {
                v30 = *(_QWORD *)(v29 + 200);
                if ( v30 )
                  _pm_runtime_idle(v30, 5);
              }
              if ( (v10 & 1) == 0 )
              {
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_WAIT_IPARDY_EVT_SUS_DIS", "ipa_work_handler");
                ipc_log_string(
                  *(_QWORD *)(a1 + 768),
                  "%s: put_async1 = %d",
                  "ipa_work_handler",
                  *(unsigned int *)(v11 + 480));
              }
            }
            else if ( !(unsigned int)ipa_suspend_work_handler(a1 - 272) )
            {
              v39 = *(_QWORD *)(a1 - 80);
              if ( v39 )
              {
                v40 = *(_QWORD *)(v39 + 200);
                if ( v40 )
                  _pm_runtime_idle(v40, 5);
              }
              if ( (v10 & 1) == 0 )
              {
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_WAIT_IPARDY_EVT_SUS", "ipa_work_handler");
                ipc_log_string(
                  *(_QWORD *)(a1 + 768),
                  "%s: put_async2 = %d",
                  "ipa_work_handler",
                  *(unsigned int *)(v11 + 480));
              }
            }
            break;
          case 7:
            ipa_data_path_disable(a1 - 272);
            ipa_disconnect_channel(a1 - 272);
            v26 = *(_QWORD *)(a1 - 80);
            *(_DWORD *)(a1 + 112) = 1;
            if ( v26 )
            {
              v27 = *(_QWORD *)(v26 + 200);
              if ( v27 )
                _pm_runtime_idle(v27, 5);
            }
            if ( (v10 & 1) == 0 )
            {
              ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_WAIT_IPARDY_EVT_DIS", "ipa_work_handler");
              ipc_log_string(
                *(_QWORD *)(a1 + 768),
                "%s: put_async3 = %d",
                "ipa_work_handler",
                *(unsigned int *)(v11 + 480));
            }
            break;
          case 4:
            if ( (unsigned __int8)peek_event(a1 - 272) == 8 )
            {
              if ( (v10 & 1) == 0 )
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_WAIT_IPARDY_EVT_SUSPEND", "ipa_work_handler");
            }
            else
            {
              ipa_data_path_enable(a1 - 272);
              *(_DWORD *)(a1 + 112) = 3;
              if ( (v10 & 1) == 0 )
                ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_WAIT_IPARDY_EVT_IPARDY %d", "ipa_work_handler", 986);
            }
            break;
        }
        goto LABEL_143;
      }
      goto LABEL_43;
    }
    if ( v7 != 3 )
      goto LABEL_143;
    if ( !*(_DWORD *)(a1 - 304) )
    {
      if ( (v10 & 1) == 0 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 768), "USB cable not connected\n");
        printk(&unk_11883, v31);
      }
      goto LABEL_143;
    }
    usb_gadget_autopm_get(*(_QWORD *)(a1 - 80));
    if ( v10 )
    {
      if ( (unsigned int)gsi_ep_enable(v2) )
        goto LABEL_64;
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 768), "%s: get = %d", "ipa_work_handler", *(_DWORD *)(v11 + 480));
      v33 = gsi_ep_enable(v2);
      if ( v33 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 768), "%s:ep enable err %d", "ipa_work_handler", v33);
        printk(&unk_10D5E, "ipa_work_handler");
LABEL_64:
        usb_composite_setup_continue(*(_QWORD *)(a1 - 72));
        v19 = *(_QWORD *)(a1 - 80);
        if ( v19 )
          goto LABEL_126;
        goto LABEL_143;
      }
    }
    usb_composite_setup_continue(*(_QWORD *)(a1 - 72));
    if ( *(_DWORD *)(a1 - 352) )
    {
      if ( (unsigned int)ipa_connect_channels(a1 - 272) )
      {
        if ( (v10 & 1) == 0 )
        {
          ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ipa_connect_channels failed\n", "ipa_work_handler");
          printk(&unk_1143A, "ipa_work_handler");
        }
        ipa_data_path_disable(a1 - 272);
        v34 = *(_QWORD *)(a1 - 80);
        if ( v34 )
        {
          v35 = *(_QWORD *)(v34 + 200);
          if ( v35 )
            _pm_runtime_idle(v35, 5);
        }
        *(_DWORD *)(a1 + 112) = 1;
      }
      else
      {
        *(_DWORD *)(a1 + 112) = 2;
        if ( (v10 & 1) == 0 )
          ipc_log_string(*(_QWORD *)(a1 + 768), "%s: ST_INIT_EVT_SET_ALT", "ipa_work_handler");
      }
      goto LABEL_143;
    }
    v19 = *(_QWORD *)(a1 - 80);
    *(_DWORD *)(a1 + 112) = 4;
    if ( v19 )
      goto LABEL_126;
    goto LABEL_143;
  }
LABEL_24:
  if ( (v10 & 1) == 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 768), "%s(): dev or dev->parent is NULL.\n", "ipa_work_handler");
    v16 = &unk_106CD;
LABEL_67:
    result = printk(v16, "ipa_work_handler");
  }
LABEL_151:
  _ReadStatusReg(SP_EL0);
  return result;
}
