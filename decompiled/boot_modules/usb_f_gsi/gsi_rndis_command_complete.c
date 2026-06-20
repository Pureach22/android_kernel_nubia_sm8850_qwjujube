void __fastcall gsi_rndis_command_complete(__int64 a1, int **a2)
{
  int *v3; // x1
  int *v4; // x20
  __int64 v5; // x8
  int v6; // w22
  int **v7; // x23
  __int64 v8; // x21
  int v9; // w0
  int *v10; // x19
  int v11; // w2
  __int64 v12; // x0
  unsigned int v13; // w19

  v3 = *a2;
  if ( !v3 )
    return;
  v4 = a2[7];
  v5 = *((_QWORD *)v4 + 33);
  if ( !v5 )
    return;
  v6 = *v3;
  if ( *v3 != 3 )
  {
    v7 = a2;
    v8 = *(_QWORD *)(*((_QWORD *)v4 + 6) + 48LL);
    v9 = rndis_msg_parser(*((_QWORD *)v4 + 33));
    if ( v4 && v9 < 0 )
    {
      v13 = v9;
      ipc_log_string(
        *((_QWORD *)v4 + 168),
        "RNDIS command error %d, %d/%d",
        v9,
        *((_DWORD *)v7 + 22),
        *((_DWORD *)v7 + 2));
      printk(&unk_10AEA, v13);
      if ( v6 != 5 )
      {
LABEL_12:
        if ( v6 == 2 )
        {
          v10 = *v7;
          if ( v4 )
          {
            ipc_log_string(*((_QWORD *)v4 + 168), "RNDIS host major:%d minor:%d version\n", v10[3], v10[4]);
            v11 = v10[5];
            v12 = *((_QWORD *)v4 + 168);
            v4[138] = v11;
            ipc_log_string(v12, "RNDIS host DL MaxTransferSize:%d\n", v11);
          }
          else
          {
            LODWORD(off_228) = v10[5];
          }
        }
LABEL_19:
        *(_BYTE *)(v8 + 488) &= ~1u;
        return;
      }
    }
    else if ( v6 != 5 )
    {
      goto LABEL_12;
    }
    if ( (*v7)[3] == 65806 )
      gsi_rndis_flow_ctrl_enable(**(_WORD **)(*((_QWORD *)v4 + 33) + 32LL) == 0);
    goto LABEL_19;
  }
  if ( v4 )
  {
    ipc_log_string(*((_QWORD *)v4 + 168), "RNDIS_MSG_HALT, state:%d\n", *(_DWORD *)(v5 + 8));
    v5 = *((_QWORD *)v4 + 33);
  }
  if ( *(_DWORD *)(v5 + 8) == 2 )
  {
    gsi_rndis_flow_ctrl_enable(1);
    v5 = *((_QWORD *)v4 + 33);
  }
  *(_DWORD *)(v5 + 8) = 0;
}
