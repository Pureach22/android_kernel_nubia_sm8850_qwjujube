__int64 __fastcall cam_mem_mgr_cache_ops(_DWORD *a1)
{
  unsigned __int64 v1; // x19
  char *v3; // x20

  if ( !cam_mem_mgr_state )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_mgr_cache_ops",
      1285,
      "failed. mem_mgr not initialized");
    return 4294967274LL;
  }
  if ( !a1 )
    return 4294967274LL;
  v1 = *a1 & 0x7FFF;
  if ( (*a1 & 0x7FFFu) - 2048 < 0xFFFFF801 )
    return 4294967274LL;
  mutex_lock(&tbl);
  if ( ((*(_QWORD *)(qword_2FDB90 + ((v1 >> 3) & 0xFF8)) >> v1) & 1) != 0 )
  {
    mutex_unlock(&tbl);
    v3 = (char *)&tbl + 296 * (unsigned int)v1;
    mutex_lock(v3 + 72);
    if ( (unsigned int)v1 <= 0x800 )
    {
      if ( *a1 == *((_DWORD *)v3 + 34) )
      {
        if ( (debug_mdl & 0x400000) == 0 || debug_priority )
        {
          if ( (unsigned int)dma_buf_begin_cpu_access(*((_QWORD *)v3 + 8), a1[1] != 3) )
            JUMPOUT(0x105544);
          JUMPOUT(0x105510);
        }
        JUMPOUT(0x105578);
      }
      JUMPOUT(0x10554C);
    }
    __break(1u);
    JUMPOUT(0x1055A8);
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x400000,
    1,
    "cam_mem_mgr_cache_ops",
    1299,
    "Buffer at idx=%d is already unmapped,",
    v1);
  mutex_unlock(&tbl);
  return 4294967274LL;
}
