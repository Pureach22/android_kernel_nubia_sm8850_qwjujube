unsigned int *__fastcall put_inst(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int *result; // x0
  int v7; // w8
  __int64 v8; // x4
  int v14; // w8

  result = (unsigned int *)(a1 + 328);
  __asm { PRFM            #0x11, [X0] }
  do
    v14 = __ldxr(result);
  while ( __stlxr(v14 - 1, result) );
  if ( v14 == 1 )
  {
    __dmb(9u);
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_9602D, "high", a1 + 340, "msm_vidc_close_helper", a5);
    msm_vidc_debugfs_deinit_inst(a1);
    msm_vidc_fence_deinit(a1);
    v7 = *(_DWORD *)(a1 + 308);
    if ( v7 == 1 )
    {
      msm_venc_inst_deinit(a1);
    }
    else if ( v7 == 2 )
    {
      msm_vdec_inst_deinit(a1);
    }
    mutex_lock(a1 + 16);
    msm_vidc_vb2_queue_deinit(a1);
    if ( *(_QWORD *)(a1 + 1664) )
    {
      v4l2_fh_del(a1 + 1648);
      *(_QWORD *)(a1 + 1672) = 0;
      v4l2_fh_exit(a1 + 1648);
    }
    else if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_8CBB8, "high", a1 + 340, "msm_vidc_v4l2_fh_deinit", v8);
    }
    mutex_unlock(a1 + 16);
    destroy_workqueue(*(_QWORD *)(a1 + 3968));
    msm_vidc_destroy_buffers(a1);
    msm_vidc_remove_session(a1);
    msm_vidc_remove_dangling_session(a1);
    return (unsigned int *)vfree(a1);
  }
  else if ( v14 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate();
  }
  return result;
}
