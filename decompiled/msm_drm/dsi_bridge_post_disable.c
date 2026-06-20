__int64 __fastcall dsi_bridge_post_disable(__int64 a1)
{
  __int64 v1; // x21
  __int64 StatusReg; // x19
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  int v8; // w0
  __int64 result; // x0
  __int64 v10; // x0
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8

  if ( !a1 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  v1 = *(_QWORD *)(a1 + 304);
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v4 = *(unsigned int *)(*(_QWORD *)(v1 + 168) + 1608LL);
    if ( (unsigned int)v4 < 3 )
      break;
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v13 = _traceiter_tracing_mark_write(0, 0x42u, StatusReg, (__int64)"dsi_bridge_post_disable", 0);
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v13);
    }
  }
  v5 = v1 + 8 * v4;
  v6 = *(_QWORD *)(a1 + 304);
  v7 = *(__int64 (__fastcall **)(_QWORD))(v5 + 1824);
  if ( *((_DWORD *)v7 - 1) != 2041732229 )
    __break(0x8228u);
  v8 = v7(v6);
  if ( v8 )
    return drm_dev_printk(
             0,
             &unk_248D72,
             "*ERROR* [msm-dsi-error]: [%d] DSI display disable failed, rc=%d\n",
             *(_DWORD *)(a1 + 296),
             v8);
  if ( v1 )
  {
    v10 = *(_QWORD *)(v1 + 16);
    if ( v10 )
      sde_connector_helper_bridge_post_disable(v10);
  }
  v11 = *(__int64 (__fastcall **)(_QWORD))(v5 + 1848);
  v12 = *(_QWORD *)(a1 + 304);
  if ( *((_DWORD *)v11 - 1) != 2041732229 )
    __break(0x8228u);
  result = v11(v12);
  if ( (_DWORD)result )
    return drm_dev_printk(
             0,
             &unk_248D72,
             "*ERROR* [msm-dsi-error]: [%d] DSI display unprepare failed, rc=%d\n",
             *(_DWORD *)(a1 + 296),
             result);
  return result;
}
