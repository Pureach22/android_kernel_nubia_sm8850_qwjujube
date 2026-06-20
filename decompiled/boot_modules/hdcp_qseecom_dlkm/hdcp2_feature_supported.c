__int64 __fastcall hdcp2_feature_supported(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64); // x8
  char v3; // w19

  mutex_lock(&hdcp2_mutex_g);
  v2 = (__int64 (__fastcall *)(__int64))off_BCC8;
  if ( *((_DWORD *)off_BCC8 - 1) != -2091637267 )
    __break(0x8228u);
  v3 = v2(a1);
  mutex_unlock(&hdcp2_mutex_g);
  return v3 & 1;
}
