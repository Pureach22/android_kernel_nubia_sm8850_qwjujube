__int64 __fastcall dp_connector_detect(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int info; // w0
  __int64 (__fastcall *v7)(_QWORD); // x8
  int v8; // w0
  int v9; // w9
  int v10; // w19
  __int64 ipc_log_context; // x0
  int v12; // w19
  __int64 v13; // x0
  _QWORD v14[3]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v15; // [xsp+20h] [xbp-90h]
  __int64 v16; // [xsp+28h] [xbp-88h]
  __int64 v17; // [xsp+30h] [xbp-80h]
  __int64 v18; // [xsp+38h] [xbp-78h]
  __int64 v19; // [xsp+40h] [xbp-70h]
  __int64 v20; // [xsp+48h] [xbp-68h]
  __int64 v21; // [xsp+50h] [xbp-60h]
  __int64 v22; // [xsp+58h] [xbp-58h]
  __int64 v23; // [xsp+60h] [xbp-50h]
  __int64 v24; // [xsp+68h] [xbp-48h]
  __int64 v25; // [xsp+70h] [xbp-40h]
  __int64 v26; // [xsp+78h] [xbp-38h]
  __int64 v27; // [xsp+80h] [xbp-30h]
  __int64 v28; // [xsp+88h] [xbp-28h]
  __int64 v29; // [xsp+90h] [xbp-20h]
  __int64 v30; // [xsp+98h] [xbp-18h]
  __int64 v31; // [xsp+A0h] [xbp-10h]
  __int64 v32; // [xsp+A8h] [xbp-8h]

  result = 3;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a3 )
  {
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
    v15 = 0;
    memset(v14, 0, sizeof(v14));
    info = dp_connector_get_info(3, (__int64)v14, a3);
    if ( info )
    {
      v10 = info;
      ipc_log_context = get_ipc_log_context();
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]failed to get display info, rc=%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v10);
      printk(&unk_26F7B8, "dp_connector_detect");
      result = 2;
    }
    else
    {
      if ( (v14[0] & 0x400000000LL) != 0 )
      {
        if ( (_BYTE)v15 )
          result = 1;
        else
          result = 2;
      }
      else
      {
        v7 = *(__int64 (__fastcall **)(_QWORD))(a3 + 336);
        if ( *((_DWORD *)v7 - 1) != 1970643636 )
          __break(0x8228u);
        v8 = v7(a3);
        if ( v8 )
        {
          v12 = v8;
          v13 = get_ipc_log_context();
          ipc_log_string(
            v13,
            "[e][%-4d]error in turning on panel power sequence rc:%d\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            v12);
          printk(&unk_24F2BE, "dp_connector_detect");
          result = 3;
          goto LABEL_13;
        }
        result = 1;
      }
      v9 = v16;
      *(_DWORD *)(a1 + 216) = HIDWORD(v15);
      *(_DWORD *)(a1 + 220) = v9;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
