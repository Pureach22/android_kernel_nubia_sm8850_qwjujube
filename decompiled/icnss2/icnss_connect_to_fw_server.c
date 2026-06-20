__int64 __fastcall icnss_connect_to_fw_server(__int64 a1, int *a2)
{
  unsigned int v3; // w20
  int v5; // w9
  int v6; // w10
  __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+10h] [xbp-10h]
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v10 = 0;
  if ( a1 )
  {
    v5 = *a2;
    v6 = a2[1];
    v8 = *(_QWORD *)(a1 + 624);
    LOWORD(v10) = 42;
    HIDWORD(v10) = v5;
    v11 = v6;
    v9 = kernel_connect(v8, &v10, 12, 0);
    if ( (v9 & 0x80000000) != 0 )
    {
      v3 = v9;
      printk("%sicnss2_qmi: Fail to connect to remote service port\n", byte_130B32);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Fail to connect to remote service port\n",
        (const char *)&unk_12DBF3);
    }
    else
    {
      printk("%sicnss2_qmi: QMI Server Connected: state: 0x%lx\n", byte_13289B, *(_QWORD *)(a1 + 1832));
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: QMI Server Connected: state: 0x%lx\n",
        (const char *)&unk_12DBF3,
        *(_QWORD *)(a1 + 1832));
      v3 = 0;
    }
  }
  else
  {
    v3 = -19;
  }
  kfree(a2);
  _ReadStatusReg(SP_EL0);
  return v3;
}
