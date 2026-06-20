__int64 __fastcall qmp_open(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w0
  unsigned int *v4; // x8
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x0
  __int64 v8; // x20
  int v9; // w0
  int v10; // w8
  bool v11; // zf
  int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x20
  int v15; // w0
  int v16; // w8
  bool v17; // zf
  int v18; // w20
  __int64 v19; // x0
  __int64 v20; // x20
  int v21; // w0
  int v22; // w8
  bool v23; // zf
  int v24; // w20
  __int64 result; // x0
  __int64 v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  __int64 v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)readl(*(unsigned int **)a1) != 1296124236 )
  {
    dev_err(*(_QWORD *)(a1 + 8), "QMP magic doesn't match\n");
LABEL_48:
    result = 4294967274LL;
    goto LABEL_44;
  }
  v2 = readl((unsigned int *)(*(_QWORD *)a1 + 4LL));
  if ( v2 != 1 )
  {
    dev_err(*(_QWORD *)(a1 + 8), "unsupported QMP version %d\n", v2);
    result = 4294967274LL;
    goto LABEL_44;
  }
  v3 = readl((unsigned int *)(*(_QWORD *)a1 + 56LL));
  v4 = *(unsigned int **)a1;
  *(_QWORD *)(a1 + 80) = v3;
  v5 = readl(v4 + 13);
  *(_QWORD *)(a1 + 88) = v5;
  if ( !v5 )
  {
    dev_err(*(_QWORD *)(a1 + 8), "invalid mailbox size\n");
    goto LABEL_48;
  }
  v6 = readl((unsigned int *)(*(_QWORD *)a1 + 12LL));
  writel(v6, (unsigned int *)(*(_QWORD *)a1 + 16LL));
  writel(0xFFFFu, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  mbox_send_message(*(_QWORD *)(a1 + 72), 0);
  mbox_client_txdone(*(_QWORD *)(a1 + 72), 0);
  if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)a1 + 40LL)) != 0xFFFF )
  {
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v26 = 0;
    init_wait_entry(&v26, 0);
    prepare_to_wait_event(a1 + 96, &v26, 2);
    if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)a1 + 40LL)) == 0xFFFF )
    {
      finish_wait(a1 + 96, &v26);
    }
    else
    {
      v7 = 250;
      do
      {
        v8 = schedule_timeout(v7);
        prepare_to_wait_event(a1 + 96, &v26, 2);
        v9 = readl((unsigned int *)(*(_QWORD *)a1 + 40LL));
        v10 = v9;
        if ( v8 )
          v11 = 0;
        else
          v11 = v9 == 0xFFFF;
        if ( v11 )
          v7 = 1;
        else
          v7 = v8;
      }
      while ( v10 != 0xFFFF && v7 );
      v12 = v7;
      finish_wait(a1 + 96, &v26);
      if ( !v12 )
      {
        dev_err(*(_QWORD *)(a1 + 8), "ucore didn't ack link\n");
LABEL_53:
        writel(0xFFFF0000, (unsigned int *)(*(_QWORD *)a1 + 36LL));
        mbox_send_message(*(_QWORD *)(a1 + 72), 0);
        mbox_client_txdone(*(_QWORD *)(a1 + 72), 0);
        result = 4294967186LL;
        goto LABEL_44;
      }
    }
  }
  writel(0xFFFFu, (unsigned int *)(*(_QWORD *)a1 + 44LL));
  mbox_send_message(*(_QWORD *)(a1 + 72), 0);
  mbox_client_txdone(*(_QWORD *)(a1 + 72), 0);
  if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)a1 + 20LL)) != 0xFFFF )
  {
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v26 = 0;
    init_wait_entry(&v26, 0);
    prepare_to_wait_event(a1 + 96, &v26, 2);
    if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)a1 + 20LL)) == 0xFFFF )
    {
      finish_wait(a1 + 96, &v26);
    }
    else
    {
      v13 = 250;
      do
      {
        v14 = schedule_timeout(v13);
        prepare_to_wait_event(a1 + 96, &v26, 2);
        v15 = readl((unsigned int *)(*(_QWORD *)a1 + 20LL));
        v16 = v15;
        if ( v14 )
          v17 = 0;
        else
          v17 = v15 == 0xFFFF;
        if ( v17 )
          v13 = 1;
        else
          v13 = v14;
      }
      while ( v16 != 0xFFFF && v13 );
      v18 = v13;
      finish_wait(a1 + 96, &v26);
      if ( !v18 )
      {
        dev_err(*(_QWORD *)(a1 + 8), "ucore didn't open channel\n");
LABEL_52:
        writel(0xFFFF0000, (unsigned int *)(*(_QWORD *)a1 + 44LL));
        goto LABEL_53;
      }
    }
  }
  writel(0xFFFFu, (unsigned int *)(*(_QWORD *)a1 + 24LL));
  mbox_send_message(*(_QWORD *)(a1 + 72), 0);
  mbox_client_txdone(*(_QWORD *)(a1 + 72), 0);
  if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)a1 + 48LL)) != 0xFFFF )
  {
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v26 = 0;
    init_wait_entry(&v26, 0);
    prepare_to_wait_event(a1 + 96, &v26, 2);
    if ( (unsigned int)readl((unsigned int *)(*(_QWORD *)a1 + 48LL)) == 0xFFFF )
    {
      finish_wait(a1 + 96, &v26);
      goto LABEL_43;
    }
    v19 = 250;
    do
    {
      v20 = schedule_timeout(v19);
      prepare_to_wait_event(a1 + 96, &v26, 2);
      v21 = readl((unsigned int *)(*(_QWORD *)a1 + 48LL));
      v22 = v21;
      if ( v20 )
        v23 = 0;
      else
        v23 = v21 == 0xFFFF;
      if ( v23 )
        v19 = 1;
      else
        v19 = v20;
    }
    while ( v22 != 0xFFFF && v19 );
    v24 = v19;
    finish_wait(a1 + 96, &v26);
    if ( v24 )
      goto LABEL_43;
    dev_err(*(_QWORD *)(a1 + 8), "ucore didn't ack channel\n");
    goto LABEL_52;
  }
LABEL_43:
  result = 0;
  *(_BYTE *)(a1 + 248) = 0;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
