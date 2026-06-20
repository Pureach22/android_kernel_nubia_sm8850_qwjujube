__int64 __fastcall dp_hdcp2p2_register(__int64 a1, char a2)
{
  __int64 (__fastcall **v2)(_DWORD *); // x9
  int v3; // w10
  __int64 (__fastcall *v4)(_DWORD *); // x8
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  _DWORD v10[2]; // [xsp+8h] [xbp-38h] BYREF
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
  v10[0] = 1;
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v7 = &unk_275B6D;
LABEL_14:
    printk(v7, "dp_hdcp2p2_valid_handle");
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( !*(_QWORD *)(a1 + 344) )
  {
    v8 = get_ipc_log_context(a1);
    ipc_log_string(v8, "[e][%-4d]HDCP library needs to be acquired\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v7 = &unk_233A43;
    goto LABEL_14;
  }
  v2 = *(__int64 (__fastcall ***)(_DWORD *))(a1 + 352);
  if ( !v2 )
  {
    v9 = get_ipc_log_context(a1);
    ipc_log_string(v9, "[e][%-4d]invalid lib ops data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v7 = &unk_260BD9;
    goto LABEL_14;
  }
  v11 = *(_QWORD *)(a1 + 344);
  if ( (a2 & 1) != 0 )
    v3 = 32771;
  else
    v3 = 32770;
  v10[1] = v3;
  v4 = *v2;
  if ( *((_DWORD *)*v2 - 1) != -417196079 )
    __break(0x8228u);
  result = v4(v10);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
