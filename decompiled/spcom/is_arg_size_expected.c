__int64 __fastcall is_arg_size_expected(int a1, int a2)
{
  unsigned __int16 v2; // w8
  int v3; // w19

  if ( a1 > 1076384748 )
  {
    if ( (unsigned int)(a1 - 1076384753) < 2 || a1 == 1076384749 )
      goto LABEL_16;
    if ( a1 == 1078481902 )
    {
      v3 = 72;
      goto LABEL_17;
    }
LABEL_22:
    printk(&unk_EE54, "is_arg_size_expected", (unsigned int)a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: No userspace data for ioctl cmd[%d]\n",
      "is_arg_size_expected",
      (const char *)&unk_F80E,
      a1);
    return 0;
  }
  if ( a1 > -1071098897 )
  {
    if ( (unsigned int)(a1 - 1075860457) < 4 )
    {
      v3 = 32;
      goto LABEL_17;
    }
    v2 = 21488;
  }
  else
  {
    if ( a1 == -1073130751 )
    {
      v3 = 9;
      goto LABEL_17;
    }
    if ( a1 == -1072671768 )
    {
      v3 = 16;
      goto LABEL_17;
    }
    v2 = 21487;
  }
  if ( a1 != (v2 | 0xC0280000) )
    goto LABEL_22;
LABEL_16:
  v3 = 40;
LABEL_17:
  if ( v3 != a2 )
  {
    printk(&unk_100C5, "is_arg_size_expected", (unsigned int)a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: Invalid cmd size: cmd[%d], arg size[%u], expected[%u]\n",
      "is_arg_size_expected",
      (const char *)&unk_F80E,
      a1,
      a2,
      v3);
    return 0;
  }
  return 1;
}
