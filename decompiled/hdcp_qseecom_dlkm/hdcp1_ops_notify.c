__int64 hdcp1_ops_notify()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))off_BC68;
  if ( *((_DWORD *)off_BC68 - 1) != -1432668597 )
    __break(0x8228u);
  return v0();
}
