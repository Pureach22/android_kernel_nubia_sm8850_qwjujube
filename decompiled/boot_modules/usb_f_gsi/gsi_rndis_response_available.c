unsigned __int64 __fastcall gsi_rndis_response_available(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  _QWORD *v5; // x8
  __int64 v6; // x2
  _QWORD *v7; // x1
  __int64 v8; // x9

  result = gsi_ctrl_pkt_alloc(0, 0x820u);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = result;
    *(_DWORD *)(result + 12) = 4;
    v4 = raw_spin_lock_irqsave(a1 + 1304);
    v5 = (_QWORD *)(v3 + 16);
    v6 = a1 + 1280;
    v7 = *(_QWORD **)(a1 + 1288);
    v8 = v4;
    if ( v3 + 16 == a1 + 1280 || v7 == v5 || *v7 != v6 )
    {
      _list_add_valid_or_report(v3 + 16);
    }
    else
    {
      *(_QWORD *)(a1 + 1288) = v5;
      *(_QWORD *)(v3 + 16) = v6;
      *(_QWORD *)(v3 + 24) = v7;
      *v7 = v5;
    }
    raw_spin_unlock_irqrestore(a1 + 1304, v8);
    return gsi_ctrl_send_notification(a1);
  }
  else if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: err allocating cpkt\n", "gsi_rndis_response_available");
    return printk(&unk_11EA6, "gsi_rndis_response_available");
  }
  return result;
}
