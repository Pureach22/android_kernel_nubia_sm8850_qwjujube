__int64 __fastcall msm_v4l2_op_g_volatile_ctrl(__int64 a1)
{
  __int64 inst_ref; // x0
  __int64 v3; // x19
  unsigned int control; // w21

  if ( !a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_87383, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_op_g_volatile_ctrl");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  inst_ref = get_inst_ref(g_core, *(_QWORD *)(a1 + 32) - 1424LL);
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_92D51, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_op_g_volatile_ctrl");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v3 = inst_ref;
  client_lock(inst_ref, "msm_v4l2_op_g_volatile_ctrl");
  inst_lock(v3, "msm_v4l2_op_g_volatile_ctrl");
  control = msm_vidc_get_control(v3, a1);
  if ( control )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_80FD2, "err ", v3 + 340, "msm_v4l2_op_g_volatile_ctrl", *(_QWORD *)(a1 + 80));
  }
  else if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_84CB8, "high", v3 + 340, "msm_v4l2_op_g_volatile_ctrl", *(_QWORD *)(a1 + 80));
  }
  inst_unlock(v3, "msm_v4l2_op_g_volatile_ctrl");
  client_unlock(v3, "msm_v4l2_op_g_volatile_ctrl");
  put_inst(v3);
  return control;
}
