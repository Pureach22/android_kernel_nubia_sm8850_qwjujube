__int64 __fastcall gsi_ctrl_set_ntb_cmd_complete(__int64 result, int **a2)
{
  int *v2; // x19
  __int64 v4; // x20
  int v5; // w8
  int v6; // w8
  unsigned int v7; // w21
  _DWORD *v8; // x8
  __int64 v9; // x1

  v2 = a2[7];
  v4 = result;
  if ( v2 )
    result = ipc_log_string(*((_QWORD *)v2 + 168), "dev:%pK", v2);
  v5 = *((_DWORD *)a2 + 21);
  a2[7] = nullptr;
  if ( v5 || (v6 = *((_DWORD *)a2 + 22), v6 != *((_DWORD *)a2 + 2)) )
  {
    if ( v2 )
    {
      ipc_log_string(*((_QWORD *)v2 + 168), "Bad control-OUT transfer");
      printk(&unk_12400, v9);
      v7 = 0;
LABEL_21:
      ipc_log_string(*((_QWORD *)v2 + 168), "Illegal NTB INPUT SIZE %d from host", v7);
      printk(&unk_11ACC, v7);
    }
    return usb_ep_set_halt(v4);
  }
  if ( v6 == 8 )
  {
    v8 = *a2;
    v7 = **a2;
    if ( v7 - 16385 < 0xFFFFC7FF )
      goto LABEL_18;
    *((_WORD *)v2 + 284) = *((_WORD *)v8 + 2);
  }
  else
  {
    if ( v6 != 4 )
    {
      v7 = 0;
      goto LABEL_18;
    }
    v7 = **a2;
    if ( v7 - 16385 < 0xFFFFC7FF )
    {
LABEL_18:
      if ( v2 )
        goto LABEL_21;
      return usb_ep_set_halt(v4);
    }
  }
  if ( v2 )
    result = ipc_log_string(*((_QWORD *)v2 + 168), "Set NTB INPUT SIZE %d", v7);
  v2[141] = v7;
  return result;
}
