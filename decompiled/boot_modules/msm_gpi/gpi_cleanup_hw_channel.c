__int64 __fastcall gpi_cleanup_hw_channel(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x4
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x8
  __int64 v8; // x2
  const char *v9; // x1
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  unsigned int v16; // w19
  unsigned int v17; // w21
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  unsigned int v21; // w21
  unsigned int v22; // w21
  unsigned int v23; // w21

  v1 = *(_QWORD *)(a1 + 280);
  *(_DWORD *)(v1 + 944) = 3;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v1, a1, 2);
  if ( (_DWORD)result )
  {
    if ( *(_DWORD *)(v1 + 1068) < 2u )
    {
      v7 = *(_QWORD *)(v1 + 1056);
      if ( !v7 )
        return result;
      goto LABEL_4;
    }
    v17 = result;
    printk(&unk_1407D, v1 + 1076, *(unsigned int *)(a1 + 256), "gpi_cleanup_hw_channel", v4, v5, v6);
    result = v17;
    v7 = *(_QWORD *)(v1 + 1056);
    if ( v7 )
    {
LABEL_4:
      if ( *(_DWORD *)(v1 + 1064) < 2u )
        return result;
      v8 = *(unsigned int *)(a1 + 256);
      v9 = "ch:%u %s: GPI_CH_CMD_STOP failed\n";
      goto LABEL_16;
    }
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v1, a1, 3);
    if ( (_DWORD)result )
    {
      if ( *(_DWORD *)(v1 + 1068) >= 2u )
      {
        v21 = result;
        printk(&unk_13585, v1 + 1076, *(unsigned int *)(a1 + 256), "gpi_cleanup_hw_channel", v10, v11, v12);
        result = v21;
        v7 = *(_QWORD *)(v1 + 1056);
        if ( !v7 )
          return result;
      }
      else
      {
        v7 = *(_QWORD *)(v1 + 1056);
        if ( !v7 )
          return result;
      }
      if ( *(_DWORD *)(v1 + 1064) < 2u )
        return result;
      v8 = *(unsigned int *)(a1 + 256);
      v9 = "ch:%u %s: GPI_CH_CMD_RESET failed\n";
      goto LABEL_16;
    }
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v1, a1, 4);
    if ( (_DWORD)result )
    {
      if ( *(_DWORD *)(v1 + 1068) >= 2u )
      {
        v22 = result;
        printk(&unk_148B3, v1 + 1076, *(unsigned int *)(a1 + 256), "gpi_cleanup_hw_channel", v13, v14, v15);
        result = v22;
        v7 = *(_QWORD *)(v1 + 1056);
        if ( !v7 )
          return result;
      }
      else
      {
        v7 = *(_QWORD *)(v1 + 1056);
        if ( !v7 )
          return result;
      }
      if ( *(_DWORD *)(v1 + 1064) < 2u )
        return result;
      v8 = *(unsigned int *)(a1 + 256);
      v9 = "ch:%u %s: GPI_CH_CMD_DE_ALLOC failed\n";
      goto LABEL_16;
    }
    if ( *(_DWORD *)(a1 + 256)
      || (result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))gpi_send_cmd)(v1, 0, 12), !(_DWORD)result) )
    {
      *(_DWORD *)(v1 + 944) = 0;
      return 0;
    }
    if ( *(_DWORD *)(v1 + 1068) >= 2u )
    {
      v23 = result;
      printk(&unk_13337, v1 + 1076, *(unsigned int *)(a1 + 256), "gpi_cleanup_hw_channel", v18, v19, v20);
      result = v23;
      v7 = *(_QWORD *)(v1 + 1056);
      if ( !v7 )
        return result;
    }
    else
    {
      v7 = *(_QWORD *)(v1 + 1056);
      if ( !v7 )
        return result;
    }
    if ( *(_DWORD *)(v1 + 1064) >= 2u )
    {
      v8 = *(unsigned int *)(a1 + 256);
      v9 = "ch:%u %s: GPI_EV_CMD_DEALLOC failed\n";
LABEL_16:
      v16 = result;
      ipc_log_string(v7, v9, v8, "gpi_cleanup_hw_channel");
      return v16;
    }
  }
  return result;
}
