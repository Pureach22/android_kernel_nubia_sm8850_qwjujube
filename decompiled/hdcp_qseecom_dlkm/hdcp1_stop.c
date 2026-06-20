__int64 __fastcall hdcp1_stop(__int64 a1)
{
  void (__fastcall *v2)(__int64); // x8

  mutex_lock(&hdcp1_mutex_g);
  v2 = (void (__fastcall *)(__int64))off_BC78;
  if ( *((_DWORD *)off_BC78 - 1) != 251140989 )
    __break(0x8228u);
  v2(a1);
  return mutex_unlock(&hdcp1_mutex_g);
}
