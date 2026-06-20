__int64 __fastcall dp_mst_display_hpd_irq(_QWORD *a1)
{
  __int64 v1; // x22
  char v2; // w8
  int v4; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  int v7; // w2
  int v8; // w0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  int v15; // w6
  int v16; // w7
  int v17; // w20
  __int64 v18; // x0
  __int64 result; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  _BYTE v22[4]; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v23[4]; // [xsp+Ch] [xbp-24h] BYREF
  unsigned __int8 v24[16]; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v25[2]; // [xsp+20h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[5];
  v25[0] = 0;
  v2 = *(_BYTE *)(v1 + 4236);
  memset(v24, 0, 14);
  v22[0] = 0;
  if ( (v2 & 1) != 0 )
  {
    v4 = drm_dp_dpcd_read(*(_QWORD *)(v1 + 24), 8194, v24, 14);
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = *(_DWORD *)(StatusReg + 1800);
    if ( v4 == 14 )
    {
      ipc_log_string(ipc_log_context, "[d][%-4d]mst irq: esi1[0x%x] esi2[0x%x] esi3[%x]\n", v7, v24[1], v24[2], v24[3]);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]mst irq: esi1[0x%x] esi2[0x%x] esi3[%x]\n",
          *(_DWORD *)(StatusReg + 1800),
          v24[1],
          v24[2],
          v24[3]);
      v8 = drm_dp_mst_hpd_irq_handle_event(v1 + 32, v24, v25, v22);
      if ( v22[0] == 1 )
      {
        v9 = *(_QWORD *)(v1 + 24);
        v23[0] = BYTE1(v25[0]);
        v17 = drm_dp_dpcd_write(v9, 8195, v23, 1);
        if ( (v25[0] & 0x2000LL) != 0 )
          dp_mst_clear_edid_cache(a1, v10, v11, v12, v13, v14, v15, v16);
        if ( v17 != 1 )
        {
          v21 = get_ipc_log_context();
          ipc_log_string(v21, "[e][%-4d]dpcd esi_res failed. rc=%d\n", *(_DWORD *)(StatusReg + 1800), v17);
          printk(&unk_273228, "dp_mst_display_hpd_irq");
        }
        drm_dp_mst_hpd_irq_send_new_request(v1 + 32);
      }
      else
      {
        v17 = v8;
      }
      v18 = get_ipc_log_context();
      result = ipc_log_string(
                 v18,
                 "[d][%-4d]mst display hpd_irq handled:%d rc:%d\n",
                 *(_DWORD *)(StatusReg + 1800),
                 v22[0],
                 v17);
      if ( (_drm_debug & 4) != 0 )
        result = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]mst display hpd_irq handled:%d rc:%d\n",
                   *(_DWORD *)(StatusReg + 1800),
                   v22[0],
                   v17);
    }
    else
    {
      ipc_log_string(ipc_log_context, "[e][%-4d]dpcd sink status read failed, rlen=%d\n", v7, v4);
      result = printk(&unk_220423, "dp_mst_display_hpd_irq");
    }
  }
  else
  {
    v20 = get_ipc_log_context();
    ipc_log_string(
      v20,
      "[e][%-4d]mst_hpd_irq received before mst session start\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    result = printk(&unk_226D9B, "dp_mst_display_hpd_irq");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
