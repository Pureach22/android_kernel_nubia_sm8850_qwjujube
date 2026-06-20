__int64 __fastcall wlan_mgmt_txrx_register_rx_cb(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v13; // x2
  __int64 v14; // x4
  const char *v15; // x2
  __int64 v16; // x26
  __int64 result; // x0
  __int64 comp_private_obj; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x25
  __int64 v29; // x28
  __int64 *v30; // x27
  __int64 v31; // x22
  __int64 v32; // x23
  __int64 v33; // x0
  __int64 v34; // x24
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _QWORD *v44; // x21
  __int64 v45; // [xsp+0h] [xbp-10h]
  unsigned __int64 StatusReg; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    v15 = "%s: psoc context is NULL";
LABEL_5:
    qdf_trace_msg(0x4Bu, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_mgmt_txrx_register_rx_cb", v45);
    return 4;
  }
  if ( a2 >= 0x36 )
  {
    v13 = "%s: Invalid component id %d passed";
    v14 = a2;
LABEL_8:
    qdf_trace_msg(0x4Bu, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "wlan_mgmt_txrx_register_rx_cb", v14);
    return 4;
  }
  v16 = a4;
  if ( (unsigned int)a4 - 139 <= 0xFFFFFF75 )
  {
    v13 = "%s: Invalid value for num_entries: %d passed";
    v14 = a4;
    goto LABEL_8;
  }
  if ( !a3 )
  {
LABEL_25:
    v15 = "%s: frame cb info pointer is NULL";
    goto LABEL_5;
  }
  v45 = a3;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 1);
  if ( comp_private_obj )
  {
    v27 = comp_private_obj;
    v28 = 0;
    v29 = comp_private_obj + 8;
    v30 = (__int64 *)(v45 + 8);
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v31 = *v30;
      v32 = *((unsigned int *)v30 - 2);
      v33 = _qdf_mem_malloc(0x18u, "wlan_mgmt_txrx_create_rx_handler", 711);
      if ( !v33 )
        break;
      v34 = v33;
      *(_DWORD *)v33 = a2;
      *(_QWORD *)(v33 + 8) = v31;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v27 + 1120);
        if ( (unsigned int)v32 >= 0x8B )
          goto LABEL_24;
      }
      else
      {
        raw_spin_lock_bh(v27 + 1120);
        *(_QWORD *)(v27 + 1128) |= 1uLL;
        if ( (unsigned int)v32 >= 0x8B )
        {
LABEL_24:
          __break(0x5512u);
          goto LABEL_25;
        }
      }
      *(_QWORD *)(v34 + 16) = *(_QWORD *)(v29 + 8 * v32);
      *(_QWORD *)(v29 + 8 * v32) = v34;
      v35 = *(_QWORD *)(v27 + 1128);
      if ( (v35 & 1) != 0 )
      {
        *(_QWORD *)(v27 + 1128) = v35 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v27 + 1120);
      }
      else
      {
        raw_spin_unlock(v27 + 1120);
      }
      qdf_trace_msg(
        0x4Bu,
        8u,
        "%s: Callback registered for comp_id: %d, frm_type: %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "wlan_mgmt_txrx_create_rx_handler",
        a2,
        (unsigned int)v32,
        v45);
      ++v28;
      result = 0;
      v30 += 2;
      if ( v16 == v28 )
        return result;
    }
    if ( v28 )
    {
      v44 = (_QWORD *)(v45 + 8);
      do
      {
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))wlan_mgmt_txrx_delete_rx_handler)(
          v27,
          *v44,
          a2,
          *((unsigned int *)v44 - 2));
        --v28;
        v44 += 2;
        result = 2;
      }
      while ( v28 );
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Bu,
      2u,
      "%s: mgmt txrx context is NULL",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_mgmt_txrx_register_rx_cb");
    return 16;
  }
  return result;
}
