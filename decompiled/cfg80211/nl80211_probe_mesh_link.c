__int64 __fastcall nl80211_probe_mesh_link(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x23
  __int64 v6; // x8
  __int64 v7; // x22
  unsigned __int16 *v8; // x8
  unsigned __int16 *v9; // x21
  unsigned int v10; // w23
  __int64 result; // x0
  _QWORD *v12; // x20
  _QWORD v13[34]; // [xsp+0h] [xbp-110h] BYREF

  v13[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2[6];
  v3 = a2[7];
  v5 = *(_QWORD *)(v3 + 992);
  memset(v13, 0, 0x108u);
  if ( !*(_QWORD *)(*(_QWORD *)v4 + 904LL) || !*(_QWORD *)(*(_QWORD *)v4 + 160LL) )
    goto LABEL_11;
  v6 = a2[4];
  v7 = *(_QWORD *)(v6 + 48);
  if ( !v7 || (v8 = *(unsigned __int16 **)(v6 + 408)) == nullptr )
  {
    v12 = (_QWORD *)a2[8];
    do_trace_netlink_extack("Frame or MAC missing");
    if ( v12 )
    {
      *v12 = "Frame or MAC missing";
      result = 4294967274LL;
      goto LABEL_12;
    }
LABEL_15:
    result = 4294967274LL;
    goto LABEL_12;
  }
  if ( *(_DWORD *)(v5 + 8) != 7 )
  {
LABEL_11:
    result = 4294967201LL;
    goto LABEL_12;
  }
  v9 = v8 + 2;
  v10 = *v8 - 4;
  if ( v10 < 0xE
    || *(_DWORD *)(v7 + 4) ^ *((_DWORD *)v8 + 1) | *((_DWORD *)v8 + 1) & 1 | *(unsigned __int16 *)(v7 + 8) ^ v8[4]
    || **(_DWORD **)(v3 + 1008) ^ *(_DWORD *)(v8 + 5) | *(unsigned __int16 *)(*(_QWORD *)(v3 + 1008) + 4LL) ^ v8[7] )
  {
    goto LABEL_15;
  }
  result = rdev_get_station(v4, v3, v7 + 4, v13);
  if ( !(_DWORD)result )
  {
    kfree(v13[25]);
    result = rdev_probe_mesh_link(v4, v3, v7 + 4, v9, (unsigned __int16)v10);
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
