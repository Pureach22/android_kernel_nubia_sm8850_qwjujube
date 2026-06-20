__int64 __fastcall geni_gsi_connect_doorbell(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x5
  __int64 v4; // x6
  unsigned int v5; // w20
  __int64 v6; // x0

  v1 = *(_QWORD *)(a1 + 280);
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))gpi_send_cmd)(v1, a1, 8);
  if ( v5 )
  {
    if ( *(_DWORD *)(v1 + 1068) >= 2u )
    {
      printk(&unk_140A1, v1 + 1076, *(unsigned int *)(a1 + 256), "geni_gsi_connect_doorbell", v5, v3, v4);
      v6 = *(_QWORD *)(v1 + 1056);
      if ( v6 )
      {
LABEL_4:
        if ( *(_DWORD *)(v1 + 1064) >= 2u )
          ipc_log_string(
            v6,
            "ch:%u %s: Error enable Chan:%d HID interrupt\n",
            *(_DWORD *)(a1 + 256),
            "geni_gsi_connect_doorbell",
            v5);
      }
    }
    else
    {
      v6 = *(_QWORD *)(v1 + 1056);
      if ( v6 )
        goto LABEL_4;
    }
    gpi_dump_debug_reg((unsigned int *)v1);
  }
  return v5;
}
