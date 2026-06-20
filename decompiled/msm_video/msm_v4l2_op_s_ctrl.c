__int64 __fastcall msm_v4l2_op_s_ctrl(__int64 a1)
{
  _BYTE *v1; // x8
  __int64 inst_ref; // x0
  __int64 v5; // x21
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  unsigned int v7; // w19
  void *v8; // x0

  if ( !a1 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v8 = &unk_87383;
LABEL_16:
    printk(v8, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_op_s_ctrl");
    return 4294967274LL;
  }
  v1 = *(_BYTE **)(a1 + 176);
  if ( v1 && *v1 == 1 )
  {
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_89AB2, "low ", 0xFFFFFFFFLL, "codec", "msm_v4l2_op_s_ctrl");
    return 0;
  }
  inst_ref = get_inst_ref(g_core, *(_QWORD *)(a1 + 32) - 1424LL);
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v8 = &unk_961DD;
    goto LABEL_16;
  }
  v5 = inst_ref;
  client_lock(inst_ref, "msm_v4l2_op_s_ctrl");
  inst_lock(v5, "msm_v4l2_op_s_ctrl");
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v5 + 168);
  if ( *((_DWORD *)v6 - 1) != -249828064 )
    __break(0x8228u);
  v7 = v6(v5, 3, a1);
  inst_unlock(v5, "msm_v4l2_op_s_ctrl");
  client_unlock(v5, "msm_v4l2_op_s_ctrl");
  put_inst(v5);
  return v7;
}
