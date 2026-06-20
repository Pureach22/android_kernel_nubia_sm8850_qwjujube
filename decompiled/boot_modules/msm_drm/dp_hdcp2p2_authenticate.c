__int64 __fastcall dp_hdcp2p2_authenticate(__int64 a1)
{
  unsigned int *v2; // x21
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w22
  int v7; // w0
  unsigned int v8; // t1
  __int64 v9; // x8
  int *v10; // x9
  int v11; // w10
  __int64 ipc_log_context; // x0
  void *v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // [xsp+8h] [xbp-38h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  v16 = 7;
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v13 = &unk_275B6D;
LABEL_21:
    printk(v13, "dp_hdcp2p2_valid_handle");
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a1 + 344) )
  {
    v14 = get_ipc_log_context(a1);
    ipc_log_string(v14, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v13 = &unk_233A43;
    goto LABEL_21;
  }
  if ( !*(_QWORD *)(a1 + 352) )
  {
    v15 = get_ipc_log_context(a1);
    ipc_log_string(v15, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v13 = &unk_260BD9;
    goto LABEL_21;
  }
  v2 = *(unsigned int **)(a1 + 96);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 120) + 8LL);
  if ( !*(_DWORD *)(a1 + 84) && v2 )
  {
    do
    {
      v9 = *v2;
      if ( !(_DWORD)v9 )
        break;
      v10 = *((int **)v2 + 1);
      if ( v10 )
      {
        v6 = 0;
        do
        {
          v11 = *v10;
          if ( !*v10 )
            break;
          v10 += 6;
          v6 |= v11;
        }
        while ( v10 );
      }
      else
      {
        v6 = 0;
      }
      v7 = readl_relaxed(v3 + v9);
      v8 = *v2;
      v2 += 4;
      writel_relaxed(v7 | v6, v3 + v8);
    }
    while ( v2 );
  }
  *(_DWORD *)(a1 + 88) = 1;
  *(_DWORD *)(a1 + 80) = 1;
  if ( (kthread_should_park() & 1) != 0 )
    kthread_park(*(_QWORD *)(a1 + 360));
  v4 = *(_QWORD *)(a1 + 360);
  *(_QWORD *)a1 = 0;
  kthread_unpark(v4);
  v17 = a1;
  dp_hdcp2p2_wakeup(&v16);
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
