__int64 __fastcall dp_hdcp2p2_on(__int64 a1)
{
  __int64 (__fastcall **v1)(__int64 *); // x9
  __int64 (__fastcall *v2)(__int64 *); // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w19
  __int64 v9; // x0
  __int64 v10; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+10h] [xbp-30h]
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v5 = &unk_275B6D;
LABEL_12:
    printk(v5, "dp_hdcp2p2_valid_handle");
    result = 4294967274LL;
    goto LABEL_8;
  }
  if ( !*(_QWORD *)(a1 + 344) )
  {
    v6 = get_ipc_log_context(a1);
    ipc_log_string(v6, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v5 = &unk_233A43;
    goto LABEL_12;
  }
  v1 = *(__int64 (__fastcall ***)(__int64 *))(a1 + 352);
  if ( !v1 )
  {
    v7 = get_ipc_log_context(a1);
    ipc_log_string(v7, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v5 = &unk_260BD9;
    goto LABEL_12;
  }
  v11 = *(_QWORD *)(a1 + 344);
  LODWORD(v10) = 3;
  v2 = *v1;
  if ( *((_DWORD *)*v1 - 1) != -417196079 )
    __break(0x8228u);
  result = v2(&v10);
  if ( (_DWORD)result )
  {
    v8 = result;
    v9 = get_ipc_log_context(result);
    ipc_log_string(
      v9,
      "[e][%-4d]Unable to start the HDCP 2.2 library (%d)\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v8);
    printk(&unk_233A82, "dp_hdcp2p2_on");
    result = v8;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
