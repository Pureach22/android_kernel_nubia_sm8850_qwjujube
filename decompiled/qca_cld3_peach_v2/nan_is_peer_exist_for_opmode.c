_QWORD *__fastcall nan_is_peer_exist_for_opmode(__int64 a1, __int64 a2, int a3)
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
  __int64 v13; // x20
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int *v23; // x8
  _BOOL4 v24; // w21

  _ReadStatusReg(SP_EL0);
  if ( a2 && *(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4) )
  {
    result = wlan_objmgr_get_peer_by_mac(a1, (_BYTE *)a2, 0x14u);
    if ( result )
    {
      v13 = result[12];
      v14 = (__int64)result;
      wlan_objmgr_vdev_get_ref(v13, 0x14u, v5, v6, v7, v8, v9, v10, v11, v12);
      if ( v13 )
      {
        v23 = (unsigned int *)*(unsigned int *)(v13 + 16);
        v24 = (_DWORD)v23 == a3;
        wlan_objmgr_vdev_release_ref(v13, 0x14u, v23, v15, v16, v17, v18, v19, v20, v21, v22);
      }
      else
      {
        v24 = 0;
      }
      wlan_objmgr_peer_release_ref(v14, 0x14u, v15, v16, v17, v18, v19, v20, v21, v22);
      result = (_QWORD *)v24;
    }
  }
  else
  {
    result = nullptr;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
