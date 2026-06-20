__int64 __fastcall _qmp_rx_worker(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x22
  __int64 result; // x0
  int v5; // w8
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x1
  unsigned int v9; // w21
  unsigned int v10; // w20
  int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x23
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x20
  unsigned int v22; // w21
  __int64 v23; // x0
  __int64 v24; // [xsp+8h] [xbp-48h] BYREF
  __int64 v25; // [xsp+10h] [xbp-40h]
  __int64 v26; // [xsp+18h] [xbp-38h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  _QWORD v28[3]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v29; // [xsp+40h] [xbp-10h]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 168);
  v3 = *(_QWORD *)(a1 + 496);
  v29 = 0;
  memset(v28, 0, sizeof(v28));
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  result = _memcpy_fromio(&v24, v2, 64);
  if ( (_DWORD)v24 == 1296124236 )
  {
    mutex_lock(a1 + 272);
    v5 = *(_DWORD *)(a1 + 264);
    if ( v5 <= 2 )
    {
      switch ( v5 )
      {
        case 0:
          v6 = v25;
          v7 = HIDWORD(v25);
          v8 = *(_QWORD *)(a1 + 168) + 16LL;
          *(_DWORD *)(a1 + 256) = HIDWORD(v24);
          *(_DWORD *)(a1 + 260) = v6;
          writel(v7, v8);
          v9 = HIDWORD(v28[2]);
          if ( HIDWORD(v28[2]) )
          {
            v10 = v29;
            *(_DWORD *)(a1 + 184) = v29;
            *(_DWORD *)(a1 + 188) = v9;
          }
          else
          {
            v10 = *(_DWORD *)(a1 + 184);
            v9 = *(_DWORD *)(a1 + 188);
          }
          v17 = *(_QWORD *)(a1 + 168);
          writel(0xFFFF, v17 + 36);
          writel(4294901760LL, v17 + 40);
          writel(4294901760LL, v17 + 44);
          writel(4294901760LL, v17 + 48);
          writel(v9, v17 + 52);
          writel(v10, v17 + 56);
          *(_DWORD *)(a1 + 264) = 1;
          v18 = _kmalloc_noprof(HIDWORD(v27), 3520);
          *(_QWORD *)(a1 + 200) = v18;
          if ( v18 )
          {
            ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: Set to link negotiation\n", "__qmp_rx_worker");
            __dsb(0xEu);
            v19 = *(_QWORD *)(v3 + 128);
            if ( v19 )
            {
              mbox_send_message(v19, 0);
              mbox_client_txdone(*(_QWORD *)(v3 + 128), 0);
            }
            else
            {
              writel_relaxed(*(unsigned int *)(v3 + 56));
            }
            ++*(_DWORD *)(v3 + 64);
          }
          else
          {
            if ( (unsigned int)__ratelimit(&_qmp_rx_worker__rs, "__qmp_rx_worker") )
              printk("%s[%s]: Failed to allocate rx pkt\n", &unk_8479);
            ipc_log_string(*(_QWORD *)(v3 + 144), "%s[%s]: Failed to allocate rx pkt\n", &unk_826D, "__qmp_rx_worker");
          }
          goto LABEL_72;
        case 1:
          if ( *(_QWORD *)((char *)v28 + 4) == 0xFFFF0000FFFFLL )
          {
            *(_DWORD *)(a1 + 264) = 2;
            complete_all(a1 + 328);
            ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: Set to link connected\n", "__qmp_rx_worker");
            if ( *(_BYTE *)(a1 + 504) == 1 )
            {
              writel(0xFFFF, *(_QWORD *)(a1 + 168) + 44LL);
              v14 = *(_QWORD *)(a1 + 496);
              *(_DWORD *)(a1 + 264) = 3;
              send_irq(v14);
            }
          }
          else
          {
            if ( (unsigned int)__ratelimit(&_qmp_rx_worker__rs_44, "__qmp_rx_worker") )
              printk("%s[%s]: RX int without negotiation ack\n", &unk_8479);
            ipc_log_string(
              *(_QWORD *)(v3 + 144),
              "%s[%s]: RX int without negotiation ack\n",
              &unk_826D,
              "__qmp_rx_worker");
          }
          goto LABEL_72;
        case 2:
          if ( HIDWORD(v26) == (_DWORD)v27 )
          {
            if ( (unsigned int)__ratelimit(&_qmp_rx_worker__rs_47, "__qmp_rx_worker") )
              printk("%s[%s]: RX int without ch open\n", &unk_8479);
            ipc_log_string(*(_QWORD *)(v3 + 144), "%s[%s]: RX int without ch open\n", &unk_826D, "__qmp_rx_worker");
          }
          else
          {
            writel(HIDWORD(v26), *(_QWORD *)(a1 + 168) + 24LL);
            __dsb(0xEu);
            v16 = *(_QWORD *)(v3 + 128);
            if ( v16 )
            {
              mbox_send_message(v16, 0);
              mbox_client_txdone(*(_QWORD *)(v3 + 128), 0);
            }
            else
            {
              writel_relaxed(*(unsigned int *)(v3 + 56));
            }
            v23 = *(_QWORD *)(v3 + 144);
            ++*(_DWORD *)(v3 + 64);
            ipc_log_string(v23, "[%s]: Received remote ch open\n", "__qmp_rx_worker");
          }
          goto LABEL_72;
      }
    }
    else
    {
      if ( v5 <= 4 )
      {
        if ( v5 == 3 )
        {
          if ( *(_QWORD *)((char *)&v28[1] + 4) == 0xFFFF0000FFFFLL )
          {
            *(_DWORD *)(a1 + 264) = 4;
            ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: Received local ch open ack\n", "__qmp_rx_worker");
          }
          v11 = HIDWORD(v26);
          if ( HIDWORD(v26) != (_DWORD)v27 )
          {
            writel(HIDWORD(v26), *(_QWORD *)(a1 + 168) + 24LL);
            __dsb(0xEu);
            v12 = *(_QWORD *)(v3 + 128);
            if ( v12 )
            {
              mbox_send_message(v12, 0);
              mbox_client_txdone(*(_QWORD *)(v3 + 128), 0);
            }
            else
            {
              writel_relaxed(*(unsigned int *)(v3 + 56));
            }
            v20 = *(_QWORD *)(v3 + 144);
            ++*(_DWORD *)(v3 + 64);
            ipc_log_string(v20, "[%s]: Received remote channel open\n", "__qmp_rx_worker");
            v11 = HIDWORD(v26);
          }
          if ( *(_DWORD *)(a1 + 264) != 4 || HIDWORD(v28[1]) != 0xFFFF || v11 != 0xFFFF )
            goto LABEL_72;
          *(_DWORD *)(a1 + 264) = 5;
        }
        else
        {
          if ( HIDWORD(v26) == (_DWORD)v27 )
          {
            if ( (unsigned int)__ratelimit(&_qmp_rx_worker__rs_53, "__qmp_rx_worker") )
              printk("%s[%s]: RX int without remote ch open\n", &unk_8479);
            ipc_log_string(
              *(_QWORD *)(v3 + 144),
              "%s[%s]: RX int without remote ch open\n",
              &unk_826D,
              "__qmp_rx_worker");
            goto LABEL_72;
          }
          writel(HIDWORD(v26), *(_QWORD *)(a1 + 168) + 24LL);
          *(_DWORD *)(a1 + 264) = 5;
          __dsb(0xEu);
          v15 = *(_QWORD *)(v3 + 128);
          if ( v15 )
          {
            mbox_send_message(v15, 0);
            mbox_client_txdone(*(_QWORD *)(v3 + 128), 0);
          }
          else
          {
            writel_relaxed(*(unsigned int *)(v3 + 56));
          }
          ++*(_DWORD *)(v3 + 64);
        }
        complete_all(a1 + 360);
        ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: Set to channel connected\n", "__qmp_rx_worker");
LABEL_72:
        result = mutex_unlock(a1 + 272);
        goto LABEL_73;
      }
      if ( v5 == 5 )
      {
        if ( HIDWORD(v26) == -65536 )
        {
          writel(4294901760LL, *(_QWORD *)(a1 + 168) + 24LL);
          *(_DWORD *)(a1 + 264) = 4;
          ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: REMOTE DISCONNECT\n", "__qmp_rx_worker");
          __dsb(0xEu);
          v13 = *(_QWORD *)(v3 + 128);
          if ( v13 )
          {
            mbox_send_message(v13, 0);
            mbox_client_txdone(*(_QWORD *)(v3 + 128), 0);
          }
          else
          {
            writel_relaxed(*(unsigned int *)(v3 + 56));
          }
          ++*(_DWORD *)(v3 + 64);
        }
        if ( (unsigned int)readl(*(_QWORD *)(a1 + 168) + LODWORD(v28[0])) && (*(_BYTE *)(a1 + 176) & 1) == 0 )
          qmp_recv_data(a1, LODWORD(v28[0]));
        v21 = raw_spin_lock_irqsave(a1 + 320);
        if ( *(_BYTE *)(a1 + 177) == 1 )
        {
          v22 = *(_DWORD *)(a1 + 180);
          if ( !(unsigned int)readl(*(_QWORD *)(a1 + 168) + *(unsigned int *)(a1 + 184)) )
          {
            *(_BYTE *)(a1 + 177) = 0;
            cancel_delayed_work(a1 + 392);
            ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: TX flag cleared, idx%d\n", "__qmp_rx_worker", v22);
            raw_spin_unlock_irqrestore(a1 + 320, v21);
            mbox_chan_txdone(*(_QWORD *)(a1 + 32) + 248LL * v22, 0);
            v21 = raw_spin_lock_irqsave(a1 + 320);
          }
        }
        raw_spin_unlock_irqrestore(a1 + 320, v21);
        goto LABEL_72;
      }
      if ( v5 == 6 )
      {
        if ( *(_QWORD *)((char *)&v28[1] + 4) == 0xFFFF0000FFFF0000LL )
        {
          *(_DWORD *)(a1 + 264) = 2;
          ipc_log_string(*(_QWORD *)(v3 + 144), "[%s]: Channel closed\n", "__qmp_rx_worker");
          *(_DWORD *)(a1 + 360) = 0;
        }
        goto LABEL_72;
      }
    }
    if ( (unsigned int)__ratelimit(&_qmp_rx_worker__rs_58, "__qmp_rx_worker") )
      printk("%s[%s]: Local Channel State corrupted\n", &unk_8479);
    ipc_log_string(*(_QWORD *)(v3 + 144), "%s[%s]: Local Channel State corrupted\n", &unk_826D, "__qmp_rx_worker");
    goto LABEL_72;
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
