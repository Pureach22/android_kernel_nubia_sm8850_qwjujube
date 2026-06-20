__int64 __fastcall hdcp2_open_stream(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  void *v8; // x8
  unsigned int v9; // w19

  mutex_lock(&hdcp2_mutex_g);
  v8 = off_BCD8;
  if ( *((_DWORD *)off_BCD8 - 1) != -1149626502 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v8)(a1, a2, a3, a4);
  mutex_unlock(&hdcp2_mutex_g);
  return v9;
}
