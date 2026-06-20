__int64 __fastcall qcom_glink_rx_thread(__int64 should_stop)
{
  __int64 v1; // x19
  _QWORD *v2; // x26
  _QWORD *v3; // x28
  __int64 v4; // x24
  __int64 v5; // x9
  __int64 v6; // x21
  __int64 v7; // x0
  _QWORD *v8; // x27
  _QWORD *v9; // x8
  __int64 v10; // x10
  __int64 *v11; // x21
  __int64 v12; // x5
  __int64 v13; // x0
  _QWORD *v14; // x1
  __int64 v15; // x9
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x22
  int v19; // w20
  int v20; // w3
  __int64 v21; // x8
  __int64 (__fastcall *v22)(__int64, __int64, __int64, __int64, __int64); // x8
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  int v27; // w27
  __int64 v28; // x8
  __int64 v29; // x8
  int v30; // w8
  __int64 v31; // x0
  _QWORD *v32; // x2
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x1
  _QWORD v37[6]; // [xsp+10h] [xbp-30h] BYREF

  v1 = should_stop;
  v2 = (_QWORD *)(should_stop + 224);
  v3 = (_QWORD *)(should_stop + 200);
  v37[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(should_stop + 112);
  while ( 1 )
  {
    if ( (_QWORD *)*v2 == v2 && (should_stop = kthread_should_stop(should_stop), (should_stop & 1) == 0) )
    {
      memset(v37, 0, 40);
      init_wait_entry(v37, 0);
      v16 = prepare_to_wait_event(v1 + 240, v37, 1);
      if ( (_QWORD *)*v2 == v2 )
      {
        v6 = v16;
        do
        {
          should_stop = kthread_should_stop(v16);
          if ( (should_stop & 1) != 0 )
            break;
          if ( v6 )
            goto LABEL_7;
          schedule();
          v16 = prepare_to_wait_event(v1 + 240, v37, 1);
          v6 = v16;
        }
        while ( (_QWORD *)*v2 == v2 );
      }
      should_stop = finish_wait(v1 + 240, v37);
      LODWORD(v6) = 0;
    }
    else
    {
      LODWORD(v6) = 0;
    }
LABEL_7:
    should_stop = kthread_should_stop(should_stop);
    if ( (should_stop & 1) != 0 )
      break;
    if ( !(_DWORD)v6 )
    {
      v7 = raw_spin_lock_irqsave(v1 + 124);
      v8 = (_QWORD *)*v2;
      v5 = v7;
      if ( (_QWORD *)*v2 == v2 )
        goto LABEL_3;
      v9 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v9 == v8 && (v10 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
      {
        *(_QWORD *)(v10 + 8) = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(*v2);
      }
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      v11 = v8 - 5;
      should_stop = raw_spin_unlock_irqrestore(v1 + 124, v5);
      if ( *(v8 - 5) )
      {
        if ( (*(_BYTE *)(v4 + 216) & 1) == 0 )
        {
          v13 = raw_spin_lock_irqsave(v1 + 144);
          v14 = *(_QWORD **)(v1 + 208);
          v15 = v13;
          if ( v8 == v3 || v14 == v8 || (_QWORD *)*v14 != v3 )
          {
            _list_add_valid_or_report(v8);
          }
          else
          {
            *(_QWORD *)(v1 + 208) = v8;
            *v8 = v3;
            v8[1] = v14;
            *v14 = v8;
          }
          should_stop = raw_spin_unlock_irqrestore(v1 + 144, v15);
        }
        if ( *((_BYTE *)v8 - 8) == 1 )
        {
          *((_BYTE *)v8 - 8) = 0;
          goto LABEL_22;
        }
        v22 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(v1 + 16);
        if ( v22 )
        {
          v23 = *(_QWORD *)v1;
          v24 = *(v8 - 5);
          v25 = *((unsigned int *)v8 - 3);
          v26 = *(_QWORD *)(v1 + 88);
          if ( *((_DWORD *)v22 - 1) != -384116476 )
            __break(0x8228u);
          should_stop = v22(v23, v24, v25, v26, 0xFFFFFFFFLL);
          v27 = should_stop;
          if ( (should_stop & 0x80000000) != 0 && (_DWORD)should_stop != -19 )
          {
            v28 = *(_QWORD *)(v1 + 112);
            if ( v28 )
            {
              ipc_log_string(
                *(_QWORD *)(v28 + 256),
                "%s[%d:%d] %s: callback error ret = %d\n",
                *(const char **)(v1 + 128),
                *(_DWORD *)(v1 + 136),
                *(_DWORD *)(v1 + 140),
                "qcom_glink_rx_thread",
                should_stop);
              should_stop = __ratelimit(&qcom_glink_rx_thread__rs, "qcom_glink_rx_thread");
              if ( (_DWORD)should_stop )
                should_stop = dev_err(
                                **(_QWORD **)(v1 + 112),
                                "[%s]: callback error ret = %d\n",
                                "qcom_glink_rx_thread",
                                v27);
            }
          }
        }
        else
        {
          v29 = *(_QWORD *)(v1 + 112);
          if ( v29 )
          {
            ipc_log_string(
              *(_QWORD *)(v29 + 256),
              "%s[%d:%d] %s: callback not present\n",
              *(const char **)(v1 + 128),
              *(_DWORD *)(v1 + 136),
              *(_DWORD *)(v1 + 140),
              "qcom_glink_rx_thread");
            should_stop = __ratelimit(&qcom_glink_rx_thread__rs_85, "qcom_glink_rx_thread");
            if ( (_DWORD)should_stop )
              should_stop = dev_err(**(_QWORD **)(v1 + 112), "[%s]: callback not present\n", "qcom_glink_rx_thread");
          }
          v27 = 0;
        }
        if ( glink_resume_pkt == 1 )
        {
          v33 = *(unsigned int *)(v1 + 136);
          v34 = *(unsigned int *)(v1 + 140);
          v35 = *(_QWORD *)(v1 + 128);
          glink_resume_pkt = 0;
          should_stop = printk(&unk_C80B, v35, v33, v34, "qcom_glink_rx_thread", v12);
          if ( v1 )
          {
LABEL_52:
            v30 = (*(unsigned __int8 *)(*(_QWORD *)(v1 + 112) + 208LL) >> 3) & 1;
            if ( v27 != 1 )
              goto LABEL_22;
            goto LABEL_53;
          }
        }
        else if ( v1 )
        {
          goto LABEL_52;
        }
        __break(0x800u);
        LOBYTE(v30) = 1;
        if ( v27 == 1 )
        {
LABEL_53:
          if ( (v30 & 1) == 0 )
            goto LABEL_22;
        }
        else
        {
LABEL_22:
          should_stop = _qcom_glink_rx_done(v4, v1, (__int64)v11, 1);
        }
      }
      else
      {
        v17 = _kmalloc_noprof(*(v8 - 3), 3520);
        *v11 = v17;
        if ( v17 )
        {
          v18 = raw_spin_lock_irqsave(v1 + 144);
          v19 = idr_alloc_cyclic(v1 + 152, v8 - 5, 1, 0xFFFFFFFFLL, 2080);
          should_stop = raw_spin_unlock_irqrestore(v1 + 144, v18);
          if ( v19 < 0 )
          {
            kfree(*v11);
            *v11 = 0;
            goto LABEL_56;
          }
          *((_DWORD *)v8 - 8) = v19;
          if ( *(_BYTE *)(v1 + 424) == 1 )
            should_stop = qcom_glink_advertise_intent(v4, v1, (__int64)(v8 - 5));
          if ( *((_BYTE *)v8 - 13) == 1 )
          {
            v20 = *(_DWORD *)(v1 + 136);
            v21 = *(_QWORD *)(v1 + 112);
            v37[0] = 0x100000008LL;
            WORD1(v37[0]) = v20;
            if ( v21 )
              ipc_log_string(
                *(_QWORD *)(v21 + 256),
                "%s[%d:%d] %s: \n",
                *(const char **)(v1 + 128),
                v20,
                *(_DWORD *)(v1 + 140),
                "qcom_glink_send_intent_req_ack");
            should_stop = qcom_glink_tx(v4, (__int64)v37, 8, 0, 0, 1);
            *((_BYTE *)v8 - 13) = 0;
          }
        }
        else
        {
LABEL_56:
          v31 = raw_spin_lock_irqsave(v1 + 124);
          v32 = (_QWORD *)*v2;
          v5 = v31;
          if ( *(_QWORD **)(*v2 + 8LL) != v2 || v32 == v8 )
          {
            _list_add_valid_or_report(v8);
          }
          else
          {
            v32[1] = v8;
            *v8 = v32;
            v8[1] = v2;
            *v2 = v8;
          }
LABEL_3:
          should_stop = raw_spin_unlock_irqrestore(v1 + 124, v5);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
