__int64 __fastcall msm_v4l2_unsubscribe_event(__int64 a1, unsigned int *a2)
{
  __int64 *inst_ref; // x0
  __int64 v4; // x21
  unsigned int v5; // w19
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x4
  void *v11; // x0

  if ( !a2 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v11 = &unk_83321;
LABEL_10:
    printk(v11, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_unsubscribe_event");
    return 4294967274LL;
  }
  inst_ref = get_inst_ref(g_core, (__int64 *)(a1 - 1648));
  if ( inst_ref )
  {
    v4 = (__int64)inst_ref;
    client_lock((__int64)inst_ref);
    inst_lock(v4);
    v5 = msm_vidc_unsubscribe_event(v4, a2);
    inst_unlock(v4);
    client_unlock(v4);
    put_inst(v4, v6, v7, v8, v9);
    return v5;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v11 = &unk_961DD;
    goto LABEL_10;
  }
  return 4294967274LL;
}
