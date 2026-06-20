__int64 __fastcall free_htc_bundle_packet(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v4; // x8
  __int64 v6; // x1
  int v7; // w8
  int v8; // w8
  __int64 v9; // x9
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 96);
  if ( v2 )
  {
    v4 = *(_QWORD *)(v2 + 40);
    v6 = (unsigned int)(*(_DWORD *)(a2 + 76) + *(_DWORD *)(v2 + 216) - *(_DWORD *)(v2 + 224));
    if ( v4 )
      *(_QWORD *)(v2 + 40) = v4 + (unsigned int)v6;
    skb_pull(v2, v6);
    if ( (*(_BYTE *)(v2 + 68) & 4) != 0 )
      v7 = *(unsigned __int16 *)(v2 + 66);
    else
      v7 = 0;
    skb_trim(v2, (unsigned int)-v7);
    *(_QWORD *)(a2 + 32) = *(_QWORD *)(v2 + 224);
    v8 = 0;
    if ( (*(_BYTE *)(v2 + 68) & 4) != 0 )
      v8 = *(unsigned __int16 *)(v2 + 66);
    v9 = *(_QWORD *)(a2 + 88);
    *(_DWORD *)(a2 + 40) = *(_DWORD *)(v2 + 112) + v8;
    if ( v9 )
    {
      *(_QWORD *)v9 = v9;
      *(_QWORD *)(v9 + 8) = v9;
      *(_DWORD *)(v9 + 16) = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_13;
    }
    else
    {
      if ( (dword_B804 & 1) != 0 )
        qdf_trace_msg(
          56,
          2,
          "%s: \n%s: Invalid pQueueSave in HTC Packet\n",
          "free_htc_bundle_packet",
          "free_htc_bundle_packet");
      printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 307, "pQueueSave");
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_13;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 2992);
      *(_QWORD *)(a1 + 3000) |= 1uLL;
      v11 = *(_QWORD *)(a1 + 3480);
      if ( v11 )
      {
LABEL_14:
        *(_QWORD *)(a2 + 8) = v11;
        *(_QWORD *)(a1 + 3480) = a2;
        v12 = *(_QWORD *)(a1 + 3000);
        if ( (v12 & 1) == 0 )
          return raw_spin_unlock(a1 + 2992);
LABEL_25:
        *(_QWORD *)(a1 + 3000) = v12 & 0xFFFFFFFFFFFFFFFELL;
        return raw_spin_unlock_bh(a1 + 2992);
      }
LABEL_24:
      *(_QWORD *)(a1 + 3480) = a2;
      *(_QWORD *)(a2 + 8) = 0;
      v12 = *(_QWORD *)(a1 + 3000);
      if ( (v12 & 1) == 0 )
        return raw_spin_unlock(a1 + 2992);
      goto LABEL_25;
    }
LABEL_13:
    raw_spin_lock(a1 + 2992);
    v11 = *(_QWORD *)(a1 + 3480);
    if ( v11 )
      goto LABEL_14;
    goto LABEL_24;
  }
  result = printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 279, "netbuf");
  if ( (dword_B804 & 1) != 0 )
    return qdf_trace_msg(
             56,
             2,
             "%s: \n%s: Invalid netbuf in HTC Packet\n",
             "free_htc_bundle_packet",
             "free_htc_bundle_packet");
  return result;
}
