__int64 hdcp2_deinit()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))off_BC88;
  if ( *((_DWORD *)off_BC88 - 1) != 251140989 )
    __break(0x8228u);
  return v0();
}
