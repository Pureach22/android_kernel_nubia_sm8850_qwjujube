__int64 hdcp1_init()
{
  __int64 v0; // x0
  __int64 (__fastcall *v1)(__int64); // x8
  __int64 v2; // x20

  v0 = mutex_lock(&hdcp1_mutex_g);
  v1 = (__int64 (__fastcall *)(__int64))ta_interface;
  if ( *((_DWORD *)ta_interface - 1) != 2098066512 )
    __break(0x8228u);
  v2 = v1(v0);
  mutex_unlock(&hdcp1_mutex_g);
  return v2;
}
