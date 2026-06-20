__int64 __fastcall if_mgr_is_beacon_interval_valid(__int64 a1, char a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int *v15; // x8
  int v16; // w9
  __int16 v17; // w10
  _BYTE v18[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v19; // [xsp+10h] [xbp-20h] BYREF
  __int64 v20; // [xsp+18h] [xbp-18h]
  __int64 v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = *(_QWORD *)(a1 + 80);
  if ( result )
  {
    v20 = 0;
    v21 = 0;
    v19 = 0;
    v18[0] = 0;
    wlan_mlme_get_mcc_feature(result, v18);
    if ( v18[0] )
    {
      result = (__int64)wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Eu);
      if ( result )
      {
        v15 = (unsigned int *)*(unsigned int *)(result + 16);
        v16 = *(_DWORD *)(a3 + 8);
        v17 = *(_WORD *)(a3 + 12);
        LOBYTE(v19) = a2;
        HIDWORD(v19) = (_DWORD)v15;
        LODWORD(v20) = v16;
        WORD2(v20) = v17;
        BYTE4(v21) = 0;
        wlan_objmgr_vdev_release_ref(result, 0x4Eu, v15, v7, v8, v9, v10, v11, v12, v13, v14);
        wlan_objmgr_pdev_iterate_obj_list(
          a1,
          2,
          (void (__fastcall *)(__int64, __int64, __int64))if_mgr_validate_beacon_interval,
          (__int64)&v19,
          0,
          0x4Eu);
        result = BYTE4(v21) != 1 || (_DWORD)v21 == 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
