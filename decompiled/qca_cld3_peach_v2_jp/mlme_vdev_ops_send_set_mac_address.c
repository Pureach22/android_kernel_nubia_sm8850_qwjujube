__int64 __fastcall mlme_vdev_ops_send_set_mac_address(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x0
  __int64 v4; // x1

  if ( !glbl_ops )
    return 16;
  v2 = *(__int64 (__fastcall **)(__int64, __int64))(glbl_ops + 256);
  if ( !v2 )
    return 16;
  v3 = a1 & 0xFFFFFFFFFFFFLL;
  v4 = a2 & 0xFFFFFFFFFFFFLL;
  if ( *((_DWORD *)v2 - 1) != -817933966 )
    __break(0x8228u);
  return v2(v3, v4);
}
