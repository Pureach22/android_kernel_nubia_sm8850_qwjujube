__int64 __fastcall wlan_objmgr_vdev_peer_freed_notify(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x21
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x9

  v1 = result;
  v2 = 870;
  v3 = g_umac_glb_obj;
  do
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8 * v2);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1458356883 )
        __break(0x8229u);
      result = v4(v1);
      v3 = g_umac_glb_obj;
    }
    ++v2;
  }
  while ( v2 != 924 );
  return result;
}
