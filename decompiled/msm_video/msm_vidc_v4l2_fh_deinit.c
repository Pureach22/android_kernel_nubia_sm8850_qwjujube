__int64 __fastcall msm_vidc_v4l2_fh_deinit(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( *(_QWORD *)(a1 + 1664) )
  {
    v4l2_fh_del(a1 + 1648);
    *(_QWORD *)(a1 + 1672) = 0;
    v4l2_fh_exit(a1 + 1648);
  }
  else if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_8CBB8, "high", a1 + 340, "msm_vidc_v4l2_fh_deinit", a5);
  }
  return 0;
}
