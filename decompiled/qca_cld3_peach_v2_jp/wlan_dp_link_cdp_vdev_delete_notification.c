__int64 __fastcall wlan_dp_link_cdp_vdev_delete_notification(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x5
  __int64 v13; // x20
  unsigned __int64 StatusReg; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *v23; // x22
  _QWORD *v24; // x8
  _QWORD *v25; // x9
  _QWORD *v26; // x8
  __int64 v27; // x8
  __int64 v29; // x8
  _QWORD *v30; // x9
  _QWORD *v31; // x8
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  int v35; // w8
  int v36; // w9
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // [xsp+0h] [xbp-10h]
  __int64 v40; // [xsp+8h] [xbp-8h]

  if ( !a1 )
  {
    v11 = 3735936685LL;
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: dp_link %pK magic 0x%llx",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_dp_link_cdp_vdev_delete_notification",
             a1,
             v11);
  }
  v11 = *(_QWORD *)(a1 + 16);
  if ( v11 != 0x5F44505F4C494E4BLL )
    return qdf_trace_msg(
             0x45u,
             5u,
             "%s: dp_link %pK magic 0x%llx",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_dp_link_cdp_vdev_delete_notification",
             a1,
             v11);
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: dp_link %pK id %d mac (%02x:%02x:%02x:**:**:%02x)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_dp_link_cdp_vdev_delete_notification",
    a1,
    *(unsigned __int8 *)(a1 + 24),
    *(unsigned __int8 *)(a1 + 25),
    *(unsigned __int8 *)(a1 + 26),
    *(unsigned __int8 *)(a1 + 27),
    *(unsigned __int8 *)(a1 + 30));
  v13 = gp_dp_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v13 + 1536);
  }
  else
  {
    raw_spin_lock_bh(v13 + 1536);
    *(_QWORD *)(v13 + 1544) |= 1uLL;
  }
  v23 = (_QWORD *)(a1 + 112);
  v24 = (_QWORD *)(a1 + 112);
  do
    v24 = (_QWORD *)*v24;
  while ( v24 != a2 && v24 );
  if ( v24 )
  {
    v25 = (_QWORD *)a2[1];
    if ( *a2 )
      v26 = (_QWORD *)(*a2 + 8LL);
    else
      v26 = (_QWORD *)(a1 + 120);
    *v26 = v25;
    *v25 = *a2;
    *a2 = 0;
    a2[1] = 0;
    if ( !*v23 )
    {
LABEL_15:
      if ( *(_BYTE *)(a1 + 88) )
      {
        v27 = *(_QWORD *)(v13 + 1520);
        if ( v27 )
        {
          while ( v27 != a1 )
          {
            v27 = *(_QWORD *)(v27 + 96);
            if ( !v27 )
              goto LABEL_19;
          }
          v29 = *(_QWORD *)(a1 + 96);
          v30 = *(_QWORD **)(a1 + 104);
          if ( v29 )
            v31 = (_QWORD *)(v29 + 104);
          else
            v31 = (_QWORD *)(v13 + 1528);
          *v31 = v30;
          *v30 = *(_QWORD *)(a1 + 96);
          v32 = *(unsigned __int8 *)(a1 + 24);
          v33 = *(unsigned __int8 *)(a1 + 25);
          v34 = *(unsigned __int8 *)(a1 + 26);
          v35 = *(unsigned __int8 *)(a1 + 27);
          v36 = *(unsigned __int8 *)(a1 + 30);
          *(_QWORD *)(a1 + 96) = 0;
          *(_QWORD *)(a1 + 104) = 0;
          LODWORD(v40) = v36;
          LODWORD(v39) = v35;
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Free dp_link %pK id %d (%02x:%02x:%02x:**:**:%02x)",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "wlan_dp_link_cdp_vdev_delete_notification",
            a1,
            v32,
            v33,
            v34,
            v39,
            v40);
          *(_QWORD *)(a1 + 16) = 0;
          _qdf_mem_free(a1);
        }
        else
        {
LABEL_19:
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: dp_link %pK release skipped",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "wlan_dp_link_cdp_vdev_delete_notification",
            a1);
        }
      }
    }
  }
  else
  {
    v37 = printk(
            &unk_9BB309,
            "0",
            "wlan_dp_link_cdp_vdev_delete_notification",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/components/dp/core/src/wlan_dp_main.c");
    dump_stack(v37);
    if ( !*v23 )
      goto LABEL_15;
  }
  v38 = *(_QWORD *)(v13 + 1544);
  if ( (v38 & 1) == 0 )
    return raw_spin_unlock(v13 + 1536);
  *(_QWORD *)(v13 + 1544) = v38 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v13 + 1536);
}
