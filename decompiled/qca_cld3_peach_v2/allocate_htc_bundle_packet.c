__int64 __fastcall allocate_htc_bundle_packet(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // x0
  int v9; // w8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2992);
    v3 = *(_QWORD *)(a1 + 3480);
    if ( v3 )
    {
LABEL_5:
      v4 = *(_QWORD *)(a1 + 3000);
      *(_QWORD *)(a1 + 3480) = *(_QWORD *)(v3 + 8);
      if ( (v4 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 3000) = v4 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2992);
      }
      else
      {
        raw_spin_unlock(a1 + 2992);
      }
      *(_QWORD *)(v3 + 8) = 0;
      return v3;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 2992);
    *(_QWORD *)(a1 + 3000) |= 1uLL;
    v3 = *(_QWORD *)(a1 + 3480);
    if ( v3 )
      goto LABEL_5;
  }
  v5 = *(_QWORD *)(a1 + 3000);
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3000) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2992);
  }
  else
  {
    raw_spin_unlock(a1 + 2992);
  }
  v6 = _qdf_nbuf_alloc(
         0,
         *(_DWORD *)(a1 + 3448) * *(unsigned __int8 *)(a1 + 3496),
         0,
         4,
         0,
         "allocate_htc_bundle_packet",
         228);
  if ( v6 )
  {
    v7 = v6;
    v3 = _qdf_mem_malloc(112, "allocate_htc_bundle_packet", 232);
    if ( v3 )
    {
      v8 = _qdf_mem_malloc(24, "allocate_htc_bundle_packet", 238);
      if ( v8 )
      {
        *(_QWORD *)v8 = v8;
        *(_QWORD *)(v8 + 8) = v8;
        *(_DWORD *)(v8 + 16) = 0;
        *(_QWORD *)(v3 + 88) = v8;
        *(_QWORD *)(v3 + 96) = v7;
        *(_QWORD *)(v3 + 32) = *(_QWORD *)(v7 + 224);
        v9 = 0;
        if ( (*(_BYTE *)(v7 + 68) & 4) != 0 )
          v9 = *(unsigned __int16 *)(v7 + 66);
        *(_DWORD *)(v3 + 40) = *(_DWORD *)(v7 + 112) + v9;
        *(_DWORD *)(v3 + 76) = *(_DWORD *)(v7 + 224) - *(_DWORD *)(v7 + 216);
      }
      else
      {
        printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 239, "pQueueSave");
        _qdf_nbuf_free(v7);
        _qdf_mem_free(v3);
        return 0;
      }
    }
    else
    {
      printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 233, "pPacket");
      _qdf_nbuf_free(v7);
    }
  }
  else
  {
    printk(&unk_94DB9D, "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/htc/htc_send.c", 229, "netbuf");
    return 0;
  }
  return v3;
}
