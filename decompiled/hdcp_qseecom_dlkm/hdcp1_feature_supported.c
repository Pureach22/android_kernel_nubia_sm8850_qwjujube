__int64 __fastcall hdcp1_feature_supported(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64); // x8
  char v3; // w19

  mutex_lock(&hdcp1_mutex_g);
  v2 = (__int64 (__fastcall *)(__int64))off_BC58;
  if ( *((_DWORD *)off_BC58 - 1) != -2091637267 )
    __break(0x8228u);
  v3 = v2(a1);
  mutex_unlock(&hdcp1_mutex_g);
  return v3 & 1;
}
