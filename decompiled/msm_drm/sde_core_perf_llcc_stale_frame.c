__int64 __fastcall sde_core_perf_llcc_stale_frame(__int64 result, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x8
  void *v5; // x0
  void *v6; // x0

  if ( !result )
  {
    v6 = &unk_25E167;
    return printk(v6, "sde_core_perf_llcc_stale_frame");
  }
  if ( !*(_QWORD *)result || (v2 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v5 = &unk_231B33;
LABEL_13:
    printk(v5, "_sde_crtc_get_kms");
    goto LABEL_14;
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v5 = &unk_234896;
    goto LABEL_13;
  }
  v4 = *(_QWORD *)(v3 + 152);
  if ( !v4 )
  {
LABEL_14:
    v6 = &unk_234896;
    return printk(v6, "sde_core_perf_llcc_stale_frame");
  }
  if ( (*(_QWORD *)(v4 + 22008) & 0x40000000000LL) != 0 )
  {
    if ( a2 >= 3 )
    {
      __break(0x5512u);
      return sde_core_perf_crtc_update_llcc(result);
    }
    else if ( *(_BYTE *)(v3 + a2 + 2094) == 1 )
    {
      return llcc_notif_staling_inc_counter(*(_QWORD *)(v4 + 24LL * a2 + 21624));
    }
  }
  return result;
}
