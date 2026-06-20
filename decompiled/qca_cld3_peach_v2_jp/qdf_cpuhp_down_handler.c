__int64 qdf_cpuhp_down_handler()
{
  void (*v0)(void); // x8

  v0 = (void (*)(void))_qdf_cpuhp_on_down;
  if ( *((_DWORD *)_qdf_cpuhp_on_down - 1) != 274542313 )
    __break(0x8228u);
  v0();
  return 0;
}
