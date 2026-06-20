__int64 qdf_is_recovering()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))is_recovering_cb;
  if ( !is_recovering_cb )
    return 0;
  if ( *((_DWORD *)is_recovering_cb - 1) != 799902358 )
    __break(0x8228u);
  return v0() & 1;
}
