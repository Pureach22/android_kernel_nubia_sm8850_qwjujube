__int64 __fastcall msm_ioctl_display_early_ept(__int64 a1, __int64 *a2)
{
  __int64 v4; // x21
  void (__fastcall *v5)(__int64, __int64, __int64, __int64); // x8
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x1

  if ( a2 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 8LL);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "msm_ioctl_display_early_ept",
      1963,
      -1,
      *((_DWORD *)a2 + 4),
      a2[1],
      HIDWORD(*a2),
      *a2,
      239);
    if ( v4 )
    {
      if ( *(_QWORD *)v4 )
      {
        v5 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v4 + 200LL);
        if ( v5 )
        {
          v7 = *a2;
          v6 = a2[1];
          v8 = *((unsigned int *)a2 + 4);
          if ( *((_DWORD *)v5 - 1) != 1279543550 )
            __break(0x8228u);
          v5(a1, v8, v6, v7);
        }
      }
    }
    return 0;
  }
  else
  {
    _drm_err("invalid early ept ioctl data\n");
    return 4294967274LL;
  }
}
