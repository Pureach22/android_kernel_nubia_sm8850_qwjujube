__int64 __fastcall rmnet_aps_genl_data_report_hdlr(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  char v5; // w23
  char v6; // w24
  int v7; // w25
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v10; // x0
  __int64 v11; // x21
  char v12; // w8
  unsigned int txid; // w0
  unsigned int v14; // w23
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x9
  void *v24; // x2
  __int64 v25; // x19
  _QWORD v26[4]; // [xsp+0h] [xbp-30h] BYREF
  int v27; // [xsp+20h] [xbp-10h]
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2
    && (v2 = a2[4], v27 = 0, memset(v26, 0, sizeof(v26)), (v3 = *(_QWORD *)(v2 + 56)) != 0)
    && (int)nla_memcpy(v26, v3, 36) >= 1 )
  {
    raw_spin_lock_bh(&data_report_lock);
    if ( (data_report_enabled & 1) != 0 )
      goto LABEL_11;
    if ( (unsigned int)data_report_count > 4 )
      goto LABEL_11;
    v5 = BYTE1(v26[0]);
    v6 = v26[0];
    v7 = BYTE2(v26[0]);
    v8 = _alloc_skb(48, 2080, 0, 0xFFFFFFFFLL);
    if ( !v8 )
      goto LABEL_11;
    v9 = v8;
    *(_WORD *)(v8 + 180) = -1792;
    v10 = skb_put();
    v11 = v10;
    *(_BYTE *)v10 = 0x80;
    v12 = v7 ? -1 : v6;
    *(_BYTE *)(v10 + 1) = v12;
    *(_WORD *)(v10 + 2) = 11264;
    *(_QWORD *)(v10 + 4) = 0;
    *(_QWORD *)(v10 + 12) = 0;
    *(_QWORD *)(v10 + 20) = 0;
    *(_QWORD *)(v10 + 28) = 0;
    *(_QWORD *)(v10 + 36) = 0;
    *(_DWORD *)(v10 + 44) = 0;
    *(_BYTE *)(v10 + 4) = 34;
    txid = rmnet_qmap_next_txid();
    *(_BYTE *)(v11 + 13) = v5;
    v14 = bswap32(txid);
    *(_BYTE *)(v11 + 12) = 1;
    *(_DWORD *)(v11 + 8) = v14;
    *(_BYTE *)(v11 + 14) = v7 != 0;
    if ( (unsigned int)rmnet_qmap_send(v9, 255, 0) || (v16 = _kmalloc_cache_noprof(mod_timer, 2336, 104)) == 0 )
    {
LABEL_11:
      raw_spin_unlock_bh(&data_report_lock);
      BYTE3(v26[0]) = 0;
      result = rmnet_aps_send_msg((__int64)a2, 4u, 7u, 0x24u, (__int64)v26, 0xCC0u);
    }
    else
    {
      v17 = a2[6];
      v18 = a2[7];
      v19 = a2[8];
      *(_DWORD *)(v16 + 88) = v14;
      *(_QWORD *)(v16 + 80) = v19;
      *(_QWORD *)(v16 + 64) = v17;
      *(_QWORD *)(v16 + 72) = v18;
      v20 = a2[3];
      *(_QWORD *)(v16 + 32) = a2[2];
      *(_QWORD *)(v16 + 40) = v20;
      v21 = a2[5];
      *(_QWORD *)(v16 + 48) = a2[4];
      *(_QWORD *)(v16 + 56) = v21;
      v22 = a2[1];
      *(_QWORD *)(v16 + 16) = *a2;
      *(_QWORD *)(v16 + 24) = v22;
      v23 = jiffies + 250LL;
      *(_QWORD *)(v16 + 96) = jiffies + 250LL;
      v24 = data_report_req_list;
      if ( data_report_req_list == (_UNKNOWN *)&data_report_req_list )
        v25 = v23;
      else
        v25 = 0;
      if ( data_report_req_list == (_UNKNOWN *)v16
        || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)data_report_req_list) != &data_report_req_list )
      {
        _list_add_valid_or_report(v16, &data_report_req_list);
      }
      else
      {
        *(_QWORD *)((char *)&unk_8 + (_QWORD)data_report_req_list) = v16;
        *(_QWORD *)v16 = v24;
        *(_QWORD *)(v16 + 8) = &data_report_req_list;
        data_report_req_list = (_UNKNOWN *)v16;
      }
      ++data_report_count;
      raw_spin_unlock_bh(&data_report_lock);
      if ( v25 )
        mod_timer(&data_report_timer);
      result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
