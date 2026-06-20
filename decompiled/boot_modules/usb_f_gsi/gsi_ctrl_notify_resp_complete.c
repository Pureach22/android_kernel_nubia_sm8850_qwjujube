__int64 __fastcall gsi_ctrl_notify_resp_complete(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  int v5; // w22
  __int64 v6; // x0
  __int64 result; // x0

  v2 = a2[7];
  v3 = *a2;
  v5 = *((_DWORD *)a2 + 21);
  v6 = raw_spin_lock_irqsave(v2 + 1304);
  *(_BYTE *)(v2 + 1224) = 0;
  result = raw_spin_unlock_irqrestore(v2 + 1304, v6);
  switch ( v5 )
  {
    case -108:
      goto LABEL_4;
    case 0:
      return result;
    case -104:
LABEL_4:
      if ( v2 )
        ipc_log_string(*(_QWORD *)(v2 + 1344), "ESHUTDOWN/ECONNRESET, connection gone");
      gsi_ctrl_clear_cpkt_queues(v2, 0);
      return gsi_ctrl_send_cpkt_tomodem(v2, 0, 0);
    default:
      if ( v2 )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 1344),
          "Unknown event %02x --> %d",
          *(unsigned __int8 *)(v3 + 1),
          *((_DWORD *)a2 + 21));
        return printk(&unk_11328, *(unsigned __int8 *)(v3 + 1));
      }
      break;
  }
  return result;
}
