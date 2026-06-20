__int64 __fastcall hdcp1_set_enc(__int64 a1, unsigned int a2)
{
  __int64 (__fastcall *v4)(__int64, _QWORD); // x8
  unsigned int v5; // w19

  mutex_lock(&hdcp1_mutex_g);
  v4 = (__int64 (__fastcall *)(__int64, _QWORD))off_BC60;
  if ( *((_DWORD *)off_BC60 - 1) != -1297827279 )
    __break(0x8228u);
  v5 = v4(a1, a2);
  mutex_unlock(&hdcp1_mutex_g);
  return v5;
}
