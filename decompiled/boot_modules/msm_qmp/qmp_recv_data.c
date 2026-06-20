__int64 __fastcall qmp_recv_data(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v3; // x23
  int v5; // w0
  unsigned int v6; // w9
  _DWORD *v7; // x24
  __int64 v8; // x25
  unsigned int *v9; // x21
  int v10; // w0
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 168);
  v3 = a2;
  v5 = readl((unsigned int *)(v2 + a2));
  *(_DWORD *)(a1 + 192) = v5;
  v6 = (v5 + 3) & 0xFFFFFFFC;
  if ( v6 <= *(_DWORD *)(a1 + 188) )
  {
    if ( v6 )
    {
      v7 = *(_DWORD **)(a1 + 200);
      v8 = (unsigned int)(v5 + 3) >> 2;
      v9 = (unsigned int *)(v3 + v2 + 4);
      do
      {
        --v8;
        v10 = readl(v9++);
        *v7++ = v10;
      }
      while ( v8 );
    }
    mbox_chan_received_data(*(_QWORD *)(a1 + 32) + 248LL * *(unsigned int *)(a1 + 180), a1 + 192);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&qmp_recv_data__rs, "qmp_recv_data") )
      printk("%s[%s]: Invalid mailbox packet\n", &unk_8479);
    ipc_log_string(
      *(_QWORD *)(*(_QWORD *)(a1 + 496) + 144LL),
      "%s[%s]: Invalid mailbox packet\n",
      (const char *)&unk_826D,
      "qmp_recv_data");
  }
  writel(0, (unsigned int *)(v2 + v3));
  ipc_log_string(
    *(_QWORD *)(*(_QWORD *)(a1 + 496) + 144LL),
    "[%s]: recv sz:%d\n",
    "qmp_recv_data",
    *(_DWORD *)(a1 + 192));
  v11 = *(_QWORD *)(a1 + 496);
  __dsb(0xEu);
  v12 = *(_QWORD *)(v11 + 128);
  if ( v12 )
  {
    mbox_send_message(v12, 0);
    result = mbox_client_txdone(*(_QWORD *)(v11 + 128), 0);
  }
  else
  {
    result = writel_relaxed(*(_DWORD *)(v11 + 56), *(unsigned int **)(v11 + 40));
  }
  ++*(_DWORD *)(v11 + 64);
  return result;
}
