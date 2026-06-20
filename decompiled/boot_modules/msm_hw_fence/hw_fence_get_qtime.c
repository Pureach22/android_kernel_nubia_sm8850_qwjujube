__int64 hw_fence_get_qtime()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))arch_timer_read_counter;
  if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
    __break(0x8228u);
  return v0();
}
