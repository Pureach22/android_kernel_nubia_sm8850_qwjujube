__int64 qdf_is_driver_state_module_stop()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))is_driver_state_module_stop_cb;
  if ( !is_driver_state_module_stop_cb )
    return 0;
  if ( *((_DWORD *)is_driver_state_module_stop_cb - 1) != 799902358 )
    __break(0x8228u);
  return v0() & 1;
}
