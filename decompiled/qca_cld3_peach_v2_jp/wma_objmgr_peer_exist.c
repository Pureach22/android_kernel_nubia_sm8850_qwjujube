_QWORD *__fastcall wma_objmgr_peer_exist(__int64 a1, __int64 a2, _BYTE *a3)
{
  _QWORD *result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  _ReadStatusReg(SP_EL0);
  if ( a2 && *(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4) )
  {
    result = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), (_BYTE *)a2, 8u);
    if ( result )
    {
      if ( a3 )
        *a3 = *(_BYTE *)(result[11] + 104LL);
      wlan_objmgr_peer_release_ref((__int64)result, 8u, v5, v6, v7, v8, v9, v10, v11, v12);
      result = &off_0 + 1;
    }
  }
  else
  {
    result = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
