__int64 __fastcall hdcp1_start(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  unsigned int v7; // w19

  mutex_lock(&hdcp1_mutex_g);
  v6 = (__int64 (__fastcall *)(__int64, __int64, __int64))off_BC70;
  if ( *((_DWORD *)off_BC70 - 1) != -1226576822 )
    __break(0x8228u);
  v7 = v6(a1, a2, a3);
  mutex_unlock(&hdcp1_mutex_g);
  return v7;
}
