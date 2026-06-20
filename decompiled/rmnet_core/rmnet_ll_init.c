__int64 rmnet_ll_init()
{
  __int64 (*v0)(void); // x8

  v0 = off_66B0[0];
  if ( *((_DWORD *)off_66B0[0] - 1) != 1874538549 )
    __break(0x8228u);
  return v0();
}
