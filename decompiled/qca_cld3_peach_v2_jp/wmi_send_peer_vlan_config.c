__int64 __fastcall wmi_send_peer_vlan_config(__int64 a1, const void *a2, __int64 a3)
{
  __int64 (__fastcall *v4)(__int64, int *, __int64 *); // x8
  __int64 result; // x0
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  int v7; // [xsp+10h] [xbp-10h] BYREF
  __int16 v8; // [xsp+14h] [xbp-Ch]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a3;
  v8 = 0;
  v7 = 0;
  qdf_mem_copy(&v7, a2, 6u);
  v4 = *(__int64 (__fastcall **)(__int64, int *, __int64 *))(*(_QWORD *)(a1 + 728) + 1992LL);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != 819016010 )
      __break(0x8228u);
    result = v4(a1, &v7, &v6);
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
