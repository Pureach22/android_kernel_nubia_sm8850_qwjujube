__int64 __fastcall hdcp2_init(unsigned int a1)
{
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x19

  mutex_lock(&hdcp2_mutex_g);
  v2 = (__int64 (__fastcall *)(_QWORD))off_BC80;
  if ( *((_DWORD *)off_BC80 - 1) != -1029165163 )
    __break(0x8228u);
  v3 = v2(a1);
  mutex_unlock(&hdcp2_mutex_g);
  return v3;
}
