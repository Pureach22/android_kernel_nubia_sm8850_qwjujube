__int64 __fastcall dp_hdcp2p2_min_level_change(__int64 result, char a2)
{
  __int64 (__fastcall **v2)(_QWORD); // x8
  __int64 v3; // x9
  __int64 (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0
  __int64 ipc_log_context; // x0
  unsigned int v7; // w8
  int v8; // w19
  __int64 v9; // x20
  const char *v10; // x0
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h]
  __int64 v13; // [xsp+18h] [xbp-28h]
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  v12 = 0;
  v11 = 14;
  if ( result )
  {
    v3 = *(_QWORD *)(result + 344);
    v2 = *(__int64 (__fastcall ***)(_QWORD))(result + 352);
    LOBYTE(v14) = a2;
    v12 = v3;
    if ( v2 )
    {
      v4 = *v2;
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != -417196079 )
          __break(0x8228u);
        result = v4(&v11);
        if ( (_DWORD)result )
        {
          ipc_log_context = get_ipc_log_context(result);
          v7 = v11;
          v8 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
          v9 = ipc_log_context;
          v10 = (const char *)sde_hdcp_2x_cmd_to_str(v7);
          ipc_log_string(v9, "[e][%-4d]error sending %s to lib\n", v8, v10);
          sde_hdcp_2x_cmd_to_str((unsigned int)v11);
          result = printk(&unk_24E728, "dp_hdcp2p2_wakeup_lib");
        }
      }
    }
  }
  else
  {
    v5 = get_ipc_log_context(0);
    ipc_log_string(v5, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_275B6D, "dp_hdcp2p2_min_level_change");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
