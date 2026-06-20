__int64 __fastcall wlan_indicate_quota_vdev_handler(__int64 result, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v4)(_QWORD); // x8

  if ( *(_DWORD *)(a2 + 16) <= 3u )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a3 + 16) + 280LL);
    if ( *((_DWORD *)v4 - 1) != -1994039160 )
      __break(0x8228u);
    result = v4(result);
    if ( !(_DWORD)result )
      *(_BYTE *)a3 = 1;
  }
  return result;
}
