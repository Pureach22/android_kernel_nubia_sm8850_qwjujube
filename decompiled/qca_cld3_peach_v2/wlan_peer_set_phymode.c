__int64 __fastcall wlan_peer_set_phymode(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v4; // x8
  __int64 (__fastcall *v5)(__int64, __int64); // x9
  __int64 v6; // x1

  v2 = result;
  v3 = -432;
  v4 = g_umac_glb_obj;
  *(_DWORD *)(result + 72) = a2;
  do
  {
    v5 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + v3 + 11280);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v4 + v3 + 11712);
      if ( *((_DWORD *)v5 - 1) != 1498857910 )
        __break(0x8229u);
      result = v5(v2, v6);
      v4 = g_umac_glb_obj;
    }
    v3 += 8;
  }
  while ( v3 );
  return result;
}
