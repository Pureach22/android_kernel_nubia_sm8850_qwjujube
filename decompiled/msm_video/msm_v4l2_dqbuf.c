__int64 __fastcall msm_v4l2_dqbuf(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 *v5; // x1
  __int64 *inst_ref; // x0
  __int64 v7; // x21
  unsigned int v8; // w19
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  void *v14; // x0

  if ( !a1 )
  {
    v5 = nullptr;
    if ( a3 )
      goto LABEL_6;
LABEL_9:
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v14 = &unk_83321;
LABEL_15:
    printk(v14, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_dqbuf");
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
    v5 = (__int64 *)(v4 - 1648);
  else
    v5 = nullptr;
  if ( !a3 )
    goto LABEL_9;
LABEL_6:
  inst_ref = get_inst_ref(g_core, v5);
  if ( inst_ref )
  {
    v7 = (__int64)inst_ref;
    client_lock((__int64)inst_ref);
    inst_lock(v7);
    v8 = msm_vidc_dqbuf(v7, a3);
    inst_unlock(v7);
    client_unlock(v7);
    put_inst(v7, v9, v10, v11, v12);
    return v8;
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v14 = &unk_961DD;
    goto LABEL_15;
  }
  return 4294967274LL;
}
