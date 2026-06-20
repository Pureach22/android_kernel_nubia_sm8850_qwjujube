void __fastcall wlan_get_connected_vdev_handler(__int64 a1, __int64 a2, __int64 a3)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v14; // [xsp+0h] [xbp-10h] BYREF
  __int16 v15; // [xsp+4h] [xbp-Ch]
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a3 + 6) & 1) == 0 && (*(_DWORD *)(a2 + 16) & 0xFFFFFFFD) == 0 )
  {
    v15 = 0;
    v14 = 0;
    if ( (wlan_cm_is_vdev_disconnected(a2) & 1) == 0
      && !(unsigned int)wlan_vdev_get_bss_peer_mac(a2, &v14, v5, v6, v7, v8, v9, v10, v11, v12)
      && v14 == *(_DWORD *)a3
      && v15 == *(_WORD *)(a3 + 4) )
    {
      *(_BYTE *)(a3 + 6) = 1;
      *(_BYTE *)(a3 + 7) = *(_BYTE *)(a2 + 168);
    }
  }
  _ReadStatusReg(SP_EL0);
}
