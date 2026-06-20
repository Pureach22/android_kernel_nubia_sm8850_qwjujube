__int64 __fastcall msm_v4l2_subscribe_event(__int64 a1, unsigned int *a2)
{
  __int64 *inst_ref; // x0
  __int64 v4; // x19
  __int64 v5; // x4
  unsigned int v6; // w20
  void *v7; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4

  if ( !a2 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v7 = &unk_83321;
LABEL_14:
    printk(v7, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_subscribe_event");
    return 4294967274LL;
  }
  inst_ref = get_inst_ref(g_core, (__int64 *)(a1 - 1648));
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v7 = &unk_961DD;
    goto LABEL_14;
  }
  v4 = (__int64)inst_ref;
  client_lock((__int64)inst_ref);
  inst_lock(v4);
  if ( *(_DWORD *)(v4 + 160) == 5 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94D1A, "err ", v4 + 340, "msm_v4l2_subscribe_event", v5);
    v6 = -16;
  }
  else
  {
    v6 = msm_vidc_subscribe_event(v4, a2);
  }
  inst_unlock(v4);
  client_unlock(v4);
  put_inst(v4, v9, v10, v11, v12);
  return v6;
}
