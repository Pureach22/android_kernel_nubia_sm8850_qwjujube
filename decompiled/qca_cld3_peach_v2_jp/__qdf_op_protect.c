__int64 _qdf_op_protect()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))_on_op_protect;
  if ( !_on_op_protect )
    return 0;
  if ( *((_DWORD *)_on_op_protect - 1) != -458604850 )
    __break(0x8228u);
  return v0();
}
