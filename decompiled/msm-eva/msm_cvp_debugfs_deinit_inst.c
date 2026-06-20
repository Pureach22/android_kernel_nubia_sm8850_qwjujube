__int64 __fastcall msm_cvp_debugfs_deinit_inst(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v5; // x19
  __int64 v6; // x8

  if ( result )
  {
    v4 = *(_QWORD *)(result + 13576);
    v5 = result;
    if ( v4 )
    {
      v6 = *(_QWORD *)(v4 + 48);
      if ( v6 )
      {
        if ( (msm_cvp_debug & 4) != 0 && !msm_cvp_debug_out )
        {
          printk(&unk_88FF2, "info", *(_QWORD *)(v6 + 696), a4);
          v6 = *(_QWORD *)(v4 + 48);
        }
        kfree(*(_QWORD *)(v6 + 696));
        *(_QWORD *)(*(_QWORD *)(v4 + 48) + 696LL) = 0;
      }
      result = debugfs_remove(v4);
      *(_QWORD *)(v5 + 13576) = 0;
    }
  }
  return result;
}
