__int64 __fastcall msm_vidc_debugfs_deinit_inst(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v3; // x19

  v1 = *(_QWORD *)(result + 4112);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 48);
    v3 = result;
    if ( v2 )
    {
      if ( result )
      {
        if ( (msm_vidc_debug & 4) != 0 )
        {
          printk(&unk_92308, "low ", result + 340, "msm_vidc_debugfs_deinit_inst", *(_QWORD *)(v2 + 696));
          v2 = *(_QWORD *)(v1 + 48);
        }
      }
      vfree(*(_QWORD *)(v2 + 696));
      *(_QWORD *)(*(_QWORD *)(v1 + 48) + 696LL) = 0;
    }
    result = debugfs_remove(v1);
    *(_QWORD *)(v3 + 4112) = 0;
  }
  return result;
}
