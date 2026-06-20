__int64 __fastcall hdcp2_force_encryption(__int64 a1, unsigned int a2)
{
  __int64 (__fastcall *v4)(__int64, _QWORD); // x8
  unsigned int v5; // w19

  mutex_lock(&hdcp2_mutex_g);
  v4 = (__int64 (__fastcall *)(__int64, _QWORD))off_BCD0;
  if ( *((_DWORD *)off_BCD0 - 1) != 19073560 )
    __break(0x8228u);
  v5 = v4(a1, a2);
  mutex_unlock(&hdcp2_mutex_g);
  return v5;
}
