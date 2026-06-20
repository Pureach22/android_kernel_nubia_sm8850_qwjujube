void sub_1DC2E4()
{
  __int64 v0; // x19

  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v0 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v0 + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(v0 + 16);
    _traceiter_tracing_mark_write(0, 0x45u, v0, (__int64)"dsi_bridge_post_disable", 0);
    JUMPOUT(0x1DC32C);
  }
  JUMPOUT(0x1DC194);
}
