__int64 __fastcall wlan_hdd_send_svc_nlink_msg(unsigned int a1, unsigned int a2, const void *a3, int a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x1
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x24
  __int64 v20; // x20
  __int64 v21; // x22
  __int64 v22; // x8
  __int64 v23; // x4
  int v24; // w21

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 16) )
  {
    v9 = 2080;
  }
  else
  {
    v9 = 3264;
  }
  result = _alloc_skb(5136, v9, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v19 = *(_QWORD *)(result + 224);
    v20 = result;
    *(_QWORD *)(v19 + 8) = 0;
    *(_DWORD *)(v19 + 4) = 26;
    *(_WORD *)(v19 + 16) = a2;
    if ( a2 - 256 <= 0xF )
    {
      if ( ((1 << a2) & 0x8FF8) != 0 )
      {
        v21 = a4;
        *(_WORD *)(v19 + 18) = a4;
        *(_DWORD *)v19 = a4 + 20;
        memcpy((void *)(v19 + 20), a3, a4);
LABEL_11:
        if ( (unsigned __int64)(v21 + 12) >> 10 > 4 )
        {
          v24 = 0;
        }
        else
        {
          v22 = v19 + v21;
          v23 = a1;
          *(_DWORD *)(v22 + 20) = 262413;
          *(_DWORD *)(v22 + 24) = a1;
          v24 = 8;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Added radio index tlv - radio index %d",
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            "wlan_hdd_send_svc_nlink_msg",
            v23);
        }
        *(_DWORD *)v19 += v24;
        skb_put(v20, (a4 + v24 + 23) & 0xFFFFFFFC);
        return nl_srv_bcast(v20, 0, 26);
      }
      if ( ((1 << a2) & 0x5007) != 0 )
      {
        *(_WORD *)(v19 + 18) = 0;
        v21 = a4;
        *(_DWORD *)v19 = 20;
        goto LABEL_11;
      }
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: WLAN SVC: Attempt to send unknown nlink message %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_hdd_send_svc_nlink_msg",
      a2);
    return sk_skb_reason_drop(0, v20, 2);
  }
  return result;
}
