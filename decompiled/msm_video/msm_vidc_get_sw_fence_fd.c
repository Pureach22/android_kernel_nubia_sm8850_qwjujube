__int64 __fastcall msm_vidc_get_sw_fence_fd(__int64 a1, __int64 a2)
{
  unsigned int unused_fd_flags; // w0
  __int64 v5; // x0
  __int64 v6; // x4
  const char *v7; // x6

  unused_fd_flags = get_unused_fd_flags(0);
  *(_DWORD *)(a2 + 152) = unused_fd_flags;
  if ( (unused_fd_flags & 0x80000000) != 0 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_9582B, "err ", a1 + 340, "msm_vidc_get_sw_fence_fd", unused_fd_flags);
    return 4294967274LL;
  }
  else
  {
    v5 = sync_file_create(a2 + 184);
    *(_QWORD *)(a2 + 256) = v5;
    if ( v5 )
    {
      if ( *(_QWORD *)(a2 + 176) )
        v7 = (const char *)&unk_88630;
      else
        v7 = "sw";
      snprintf(
        (char *)(a2 + 16),
        0x80u,
        "%s%sfence: %s: %s: fd %3d id %10llu mid %5llu f.no %5llu",
        (const char *)&unk_84D69,
        (const char *)&unk_84D69,
        *(const char **)(a2 + 272),
        v7,
        *(_DWORD *)(a2 + 152),
        *(_QWORD *)(a2 + 160),
        *(_QWORD *)(a2 + 160) & 0x7FFFFFFFLL,
        *(_QWORD *)(a2 + 168));
      return 0;
    }
    else
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8924F, "err ", a1 + 340, "msm_vidc_get_sw_fence_fd", v6);
      put_unused_fd(*(unsigned int *)(a2 + 152));
      *(_DWORD *)(a2 + 152) = -1;
      return 4294967274LL;
    }
  }
}
