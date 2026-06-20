_QWORD *__fastcall wlan_mgmt_txrx_desc_get(_QWORD *a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x22
  _QWORD *v13; // x20
  unsigned int v14; // w0
  __int64 v15; // x8
  __int64 v17; // x8
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  _QWORD *v28; // [xsp+0h] [xbp-10h] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 5);
  }
  else
  {
    raw_spin_lock_bh(a1 + 5);
    a1[6] |= 1uLL;
  }
  if ( (unsigned int)qdf_list_peek_front(a1 + 1, &v28) )
  {
    v3 = a1[6];
    if ( (v3 & 1) != 0 )
    {
      a1[6] = v3 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 5);
    }
    else
    {
      raw_spin_unlock(a1 + 5);
    }
    v12 = jiffies;
    if ( wlan_mgmt_txrx_desc_get___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Bu,
        2u,
        "%s: Descriptor freelist empty for mgmt_txrx_ctx %pK",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "wlan_mgmt_txrx_desc_get",
        a1);
      v13 = nullptr;
      wlan_mgmt_txrx_desc_get___last_ticks = v12;
    }
    else
    {
      v13 = nullptr;
    }
  }
  else
  {
    v14 = qdf_list_remove_node((__int64)(a1 + 1), v28);
    if ( v14 )
    {
      v17 = a1[6];
      v18 = v14;
      if ( (v17 & 1) != 0 )
      {
        a1[6] = v17 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 5);
      }
      else
      {
        raw_spin_unlock(a1 + 5);
      }
      qdf_trace_msg(
        0x4Bu,
        2u,
        "%s: Failed to get descriptor from list: status %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wlan_mgmt_txrx_desc_get",
        v18,
        v28,
        v29);
      v27 = printk(
              &unk_AAA255,
              "0",
              "wlan_mgmt_txrx_desc_get",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/umac/cmn_services/mgmt_txrx/core/src/wlan_mgmt_txrx_main.c");
      dump_stack(v27);
    }
    v13 = v28;
    *((_BYTE *)v28 + 65) = 1;
    v15 = a1[6];
    if ( (v15 & 1) != 0 )
    {
      a1[6] = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 5);
    }
    else
    {
      raw_spin_unlock(a1 + 5);
    }
    qdf_wake_lock_timeout_acquire((__int64)(a1 + 8), 300);
    qdf_runtime_pm_prevent_suspend(a1 + 33);
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
