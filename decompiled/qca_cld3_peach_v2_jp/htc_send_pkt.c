__int64 __fastcall htc_send_pkt(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w8
  __int64 v6; // x23
  __int64 v7; // x21
  __int64 v8; // x8
  __int64 v9; // x8
  int *v10; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  __int64 v13; // x1
  unsigned int v14; // w19
  __int64 *v15; // x1
  int v16; // w8
  __int64 v17; // x8
  _QWORD *v18; // x9
  const char *v19; // x3
  __int64 v20; // x2
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  __int64 *v22; // [xsp+8h] [xbp-18h]
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    if ( (dword_B0B4 & 1) == 0 )
    {
LABEL_8:
      result = 16;
      goto LABEL_57;
    }
    qdf_trace_msg(56, 2, "%s: %s: HTCHandle is NULL \n", "htc_send_pkt", "htc_send_pkt");
LABEL_31:
    result = 16;
    goto LABEL_57;
  }
  if ( !a2 )
  {
    if ( (dword_B0B4 & 1) == 0 )
      goto LABEL_8;
    qdf_trace_msg(56, 2, "%s: %s: pPacket is NULL \n", "htc_send_pkt", "htc_send_pkt");
    goto LABEL_31;
  }
  if ( (dword_B0B4 & 0x100) != 0 )
  {
    qdf_trace_msg(
      56,
      2,
      "%s: +-htc_send_pkt: Enter endPointId: %d, buffer: %pK, length: %d\n",
      "htc_send_pkt",
      *(_DWORD *)(a2 + 48),
      *(const void **)(a2 + 32),
      *(_DWORD *)(a2 + 44));
    v22 = nullptr;
    v23 = 0;
    v21 = 0;
    if ( (dword_B0B4 & 0x100) != 0 )
      qdf_trace_msg(56, 2, "%s: +__htc_send_pkt\n", "__htc_send_pkt");
  }
  else
  {
    v22 = nullptr;
    v23 = 0;
    v21 = 0;
  }
  v5 = *(_DWORD *)(a2 + 48);
  if ( v5 >= 9 )
  {
    if ( (dword_B0B4 & 0x100) != 0 )
      qdf_trace_msg(56, 2, "%s: %s endpoint is invalid\n", "__htc_send_pkt", "__htc_send_pkt");
    v19 = "0";
    v20 = 1922;
    goto LABEL_55;
  }
  v6 = a1 + 328LL * v5;
  if ( !*(_WORD *)(v6 + 12) )
  {
    if ( (dword_B0B4 & 0x100) != 0 )
      qdf_trace_msg(56, 2, "%s: %s service_id is invalid\n", "__htc_send_pkt", "__htc_send_pkt");
    goto LABEL_56;
  }
  v7 = *(_QWORD *)(a2 + 96);
  if ( !v7 )
  {
    v19 = "netbuf";
    v20 = 1941;
LABEL_55:
    printk(&unk_881311, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", v20, v19);
LABEL_56:
    result = 4;
    goto LABEL_57;
  }
  v8 = *(_QWORD *)(v7 + 40);
  if ( v8 )
    *(_QWORD *)(v7 + 40) = v8 - 8;
  skb_push(v7, 8);
  *(_DWORD *)(a2 + 72) |= 2u;
  v9 = 72;
  if ( (*(_BYTE *)(v7 + 68) & 4) == 0 )
    v9 = 224;
  v10 = *(int **)(v7 + v9);
  if ( !v10 )
  {
    v19 = "htc_hdr";
    v20 = 1950;
    goto LABEL_55;
  }
  *v10 = *(unsigned __int8 *)(a2 + 48) | (*(_DWORD *)(a2 + 44) << 16);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2992);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2992);
    *(_QWORD *)(a1 + 3000) |= 1uLL;
  }
  *(_DWORD *)(a2 + 68) = (unsigned __int8)(*(_BYTE *)(v6 + 280))++;
  v10[1] = (unsigned __int8)*(_DWORD *)(a2 + 68) << 8;
  v12 = *(_QWORD *)(a1 + 3000);
  if ( (v12 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3000) = v12 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2992);
    if ( (*(_BYTE *)(v6 + 308) & 1) != 0 )
      goto LABEL_33;
  }
  else
  {
    raw_spin_unlock(a1 + 2992);
    if ( (*(_BYTE *)(v6 + 308) & 1) != 0 )
      goto LABEL_33;
  }
  v13 = *(_QWORD *)(a2 + 96);
  *(_DWORD *)(a2 + 72) |= 1u;
  result = _qdf_nbuf_map(*(_QWORD *)(a1 + 3456), v13, 1);
  if ( (_DWORD)result )
  {
    if ( (dword_B0B4 & 1) != 0 )
    {
      v14 = result;
      qdf_trace_msg(
        56,
        2,
        "%s: %s: nbuf map failed, endpoint %pK, seq_no. %d\n",
        "__htc_send_pkt",
        "__htc_send_pkt",
        (const void *)(v6 + 8),
        *(unsigned __int8 *)(v6 + 280));
      result = v14;
    }
    goto LABEL_57;
  }
  ++*(_DWORD *)(a1 + 3572);
LABEL_33:
  v21 = a2;
  v22 = (__int64 *)a2;
  *(_QWORD *)a2 = &v21;
  *(_QWORD *)(a2 + 8) = &v21;
  LODWORD(v23) = 1;
  htc_try_send(a1, v6 + 8, &v21);
  while ( (_DWORD)v23 )
  {
    v15 = v22;
    if ( v22 == &v21 )
    {
      v15 = nullptr;
    }
    else
    {
      v17 = *v22;
      v18 = (_QWORD *)v22[1];
      if ( v18 )
        *v18 = v17;
      if ( v17 )
        *(_QWORD *)(v17 + 8) = v15[1];
      *v15 = (__int64)v15;
      v15[1] = (__int64)v15;
      if ( v15 )
        LODWORD(v23) = v23 - 1;
    }
    if ( (*(_DWORD *)(a1 + 3008) & 1) != 0 )
      v16 = 9;
    else
      v16 = 1;
    *((_DWORD *)v15 + 13) = v16;
    send_packet_completion(a1);
  }
  if ( (dword_B0B4 & 0x100) != 0 )
    qdf_trace_msg(56, 2, "%s: -__htc_send_pkt\n", "__htc_send_pkt");
  result = 0;
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
