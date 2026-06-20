__int64 __fastcall sde_dp_hdcp2p2_deinit(__int64 a1)
{
  __int64 (__fastcall **v1)(_QWORD); // x8
  __int64 v2; // x10
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x21
  int v5; // w8
  __int64 v6; // x19
  __int64 result; // x0
  __int64 v8; // x0
  __int64 ipc_log_context; // x0
  unsigned int v10; // w8
  int v11; // w19
  __int64 v12; // x20
  const char *v13; // x0
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 80) != 3 )
    {
      v2 = *(_QWORD *)(a1 + 344);
      v1 = *(__int64 (__fastcall ***)(_QWORD))(a1 + 352);
      LODWORD(v14) = 5;
      v15 = v2;
      if ( v1 )
      {
        v3 = *v1;
        if ( v3 )
        {
          v4 = a1;
          if ( *((_DWORD *)v3 - 1) != -417196079 )
            __break(0x8228u);
          v5 = v3(&v14);
          a1 = v4;
          if ( v5 )
          {
            ipc_log_context = get_ipc_log_context(v4);
            v10 = v14;
            v11 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
            v12 = ipc_log_context;
            v13 = (const char *)sde_hdcp_2x_cmd_to_str(v10);
            ipc_log_string(v12, "[e][%-4d]error sending %s to lib\n", v11, v13);
            sde_hdcp_2x_cmd_to_str((unsigned int)v14);
            printk(&unk_24E728, "dp_hdcp2p2_wakeup_lib");
            a1 = v4;
          }
        }
      }
    }
    v6 = a1;
    sde_hdcp_2x_deregister(*(_QWORD *)(a1 + 344));
    kthread_stop(*(_QWORD *)(v6 + 360));
    result = kfree(v6);
  }
  else
  {
    v8 = ((__int64 (*)(void))get_ipc_log_context)();
    ipc_log_string(v8, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_275B6D, "sde_dp_hdcp2p2_deinit");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
