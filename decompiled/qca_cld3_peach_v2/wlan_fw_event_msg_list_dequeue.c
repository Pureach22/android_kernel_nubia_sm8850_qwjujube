__int64 __fastcall wlan_fw_event_msg_list_dequeue(__int64 a1)
{
  unsigned __int16 *v1; // x20
  unsigned __int64 StatusReg; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x8
  __int64 v13; // x19
  __int16 v14; // w10
  __int64 v15; // x8
  unsigned __int16 v16; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  v1 = *(unsigned __int16 **)(a1 + 72);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 12);
  }
  else
  {
    raw_spin_lock_bh(v1 + 12);
    *((_QWORD *)v1 + 4) |= 1uLL;
  }
  v11 = v1[1];
  if ( (_DWORD)v11 == *v1 )
  {
    v12 = *((_QWORD *)v1 + 4);
    if ( (v12 & 1) != 0 )
    {
      *((_QWORD *)v1 + 4) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v1 + 12);
    }
    else
    {
      raw_spin_unlock(v1 + 12);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: dequeue msg from the list",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_fw_event_msg_list_dequeue");
    v14 = v11 + 1;
    v15 = *((_QWORD *)v1 + 4);
    v13 = *((_QWORD *)v1 + 1) + 32 * v11;
    v16 = (v1[8] - 1) & v14;
    v1[1] = v16;
    if ( (v15 & 1) != 0 )
    {
      *((_QWORD *)v1 + 4) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v1 + 12);
    }
    else
    {
      raw_spin_unlock(v1 + 12);
    }
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: tp value %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_fw_event_msg_list_dequeue",
      v16);
  }
  return v13;
}
