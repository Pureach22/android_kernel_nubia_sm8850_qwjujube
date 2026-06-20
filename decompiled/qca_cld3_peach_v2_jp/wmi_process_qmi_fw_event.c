__int64 __fastcall wmi_process_qmi_fw_event(__int64 a1, const void *a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  __int64 v15; // x0
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  const char *v26; // x8
  const char *v27; // x4
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)_qdf_op_protect() )
  {
    v14 = -22;
  }
  else
  {
    if ( a1 && a2 && a3 )
    {
      v15 = wmi_buf_alloc_fl(a1, a3, "__wmi_process_qmi_fw_event", 0xB30u);
      if ( v15 )
      {
        v16 = v15;
        qdf_mem_copy(*(void **)(v15 + 224), a2, a3);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Received WMI_EVT_ID: 0x%x over qmi",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "__wmi_process_qmi_fw_event",
          **(_DWORD **)(v16 + 224) & 0xFFFFFF,
          0,
          v29);
        wmi_process_control_rx(a1, v16);
        v14 = 0;
      }
      else
      {
        v14 = -12;
      }
    }
    else
    {
      v25 = jiffies;
      if ( _wmi_process_qmi_fw_event___last_ticks - jiffies + 125 < 0 )
      {
        v26 = "buf";
        if ( a2 )
          v26 = "length";
        if ( a1 )
          v27 = v26;
        else
          v27 = "wmi_buf";
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: %s is invalid",
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          "__wmi_process_qmi_fw_event",
          v27,
          0,
          v29);
        _wmi_process_qmi_fw_event___last_ticks = v25;
      }
      v14 = -22;
    }
    _qdf_op_unprotect();
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
