__int64 __fastcall msm_vidc_vb2_queue_deinit(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  if ( a1[226] )
  {
    v4l2_m2m_ctx_release(a1[227]);
    v6 = a1[226];
    a1[227] = 0;
    a1[230] = 0;
    a1[231] = 0;
    v4l2_m2m_release(v6);
    v7 = a1[233];
    a1[226] = 0;
    vb2_queue_release(v7);
    vfree(a1[233]);
    v8 = a1[232];
    a1[233] = 0;
    vb2_queue_release(v8);
    vfree(a1[232]);
    a1[232] = 0;
  }
  else if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_94939, "high", (char *)a1 + 340, "msm_vidc_vb2_queue_deinit", a5);
  }
  return 0;
}
