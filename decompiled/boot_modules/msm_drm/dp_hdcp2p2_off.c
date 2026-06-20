__int64 __fastcall dp_hdcp2p2_off(__int64 a1)
{
  unsigned int *v2; // x21
  __int64 v3; // x20
  __int64 (__fastcall **v4)(__int64 *); // x9
  __int64 (__fastcall *v5)(__int64 *); // x8
  __int64 result; // x0
  int v7; // w22
  int v8; // w0
  unsigned int v9; // t1
  __int64 v10; // x8
  int *v11; // x9
  int v12; // w10
  __int64 ipc_log_context; // x0
  void *v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // [xsp+8h] [xbp-38h] BYREF
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  v17 = 2;
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_275B6D;
LABEL_21:
    result = printk(v14, "dp_hdcp2p2_valid_handle");
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(a1 + 344) )
  {
    v15 = get_ipc_log_context(a1);
    ipc_log_string(v15, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_233A43;
    goto LABEL_21;
  }
  if ( !*(_QWORD *)(a1 + 352) )
  {
    v16 = get_ipc_log_context(a1);
    ipc_log_string(v16, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_260BD9;
    goto LABEL_21;
  }
  v2 = *(unsigned int **)(a1 + 96);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 120) + 8LL);
  if ( !*(_DWORD *)(a1 + 84) && v2 )
  {
    do
    {
      v10 = *v2;
      if ( !(_DWORD)v10 )
        break;
      v11 = *((int **)v2 + 1);
      if ( v11 )
      {
        v7 = 0;
        do
        {
          v12 = *v11;
          if ( !*v11 )
            break;
          v11 += 6;
          v7 |= v12;
        }
        while ( v11 );
      }
      else
      {
        v7 = 0;
      }
      v8 = readl_relaxed(v3 + v10);
      v9 = *v2;
      v2 += 4;
      writel_relaxed(v8 & (unsigned int)~v7, v3 + v9);
    }
    while ( v2 );
  }
  *(_DWORD *)(a1 + 88) = 0;
  *(_DWORD *)(a1 + 80) = 0;
  kthread_park(*(_QWORD *)(a1 + 360));
  v4 = *(__int64 (__fastcall ***)(__int64 *))(a1 + 352);
  v18 = *(_QWORD *)(a1 + 344);
  v5 = *v4;
  if ( *((_DWORD *)*v4 - 1) != -417196079 )
    __break(0x8228u);
  result = v5(&v17);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
