__int64 _os_mc_timer_shim()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))scheduler_timer_callback;
  if ( *((_DWORD *)scheduler_timer_callback - 1) != 1902359720 )
    __break(0x8228u);
  return v0();
}
