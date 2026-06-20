__int64 qdf_is_driver_unloading()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))is_driver_unloading_cb;
  if ( !is_driver_unloading_cb )
    return 0;
  if ( *((_DWORD *)is_driver_unloading_cb - 1) != 799902358 )
    __break(0x8228u);
  return v0() & 1;
}
