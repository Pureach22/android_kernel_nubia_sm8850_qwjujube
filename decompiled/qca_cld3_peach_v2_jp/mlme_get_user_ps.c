__int64 __fastcall mlme_get_user_ps(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 ext_hdl; // x0
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  char v22; // w20

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v2 )
  {
    v11 = v2;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v2, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( ext_hdl )
    {
      v13 = (_DWORD *)&unk_5F89;
      v22 = *(_BYTE *)(ext_hdl + 24457);
    }
    else
    {
      v22 = 0;
    }
    wlan_objmgr_vdev_release_ref(v11, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  else
  {
    v22 = 0;
  }
  return v22 & 1;
}
