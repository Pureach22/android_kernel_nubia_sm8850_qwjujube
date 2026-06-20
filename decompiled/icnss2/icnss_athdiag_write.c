__int64 __fastcall icnss_athdiag_write(_QWORD *a1, __int64 a2, __int64 a3, int a4, const void *a5)
{
  _QWORD *v6; // x0
  __int64 v7; // x8
  _QWORD *v9; // x20
  _DWORD *v10; // x21

  v6 = (_QWORD *)a1[19];
  if ( *(_DWORD *)v6 == 1522293436 )
  {
    if ( a5 && (unsigned int)(a4 - 6145) > 0xFFFFE7FF )
    {
      v7 = v6[229];
      if ( (v7 & 4) != 0 && (v7 = v6[229], (v7 & 2) != 0) )
      {
        return wlfw_athdiag_write_send_sync_msg();
      }
      else
      {
        v9 = v6;
        printk("%sicnss2: Invalid state for diag write: 0x%lx\n", byte_130B32, v7);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: Invalid state for diag write: 0x%lx\n",
          (const char *)&unk_12DBF3,
          v9[229]);
        return 4294967274LL;
      }
    }
    else
    {
      printk("%sicnss2: Invalid parameters for diag write: input %pK, data_len %u\n", byte_130B32, a5, a4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Invalid parameters for diag write: input %pK, data_len %u\n",
        (const char *)&unk_12DBF3,
        a5,
        a4);
      return 4294967274LL;
    }
  }
  else
  {
    v10 = v6;
    printk(
      "%sicnss2: Invalid drvdata for diag write: dev %pK, data %pK, magic 0x%x\n",
      byte_130B32,
      a1,
      v6,
      *(_DWORD *)v6);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: Invalid drvdata for diag write: dev %pK, data %pK, magic 0x%x\n",
      (const char *)&unk_12DBF3,
      a1,
      v10,
      *v10);
    return 4294967274LL;
  }
}
