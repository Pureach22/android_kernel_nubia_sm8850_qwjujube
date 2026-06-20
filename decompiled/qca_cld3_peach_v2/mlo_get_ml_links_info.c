__int64 __fastcall mlo_get_ml_links_info(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned __int8 v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x9
  unsigned int v25; // w21
  unsigned int v26; // w10
  unsigned int v28; // w10
  unsigned int v29; // w9

  v4 = a2;
  _ReadStatusReg(SP_EL0);
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 90);
  if ( v5 )
  {
    v14 = v5;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v5, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0
      && (v24 = *(_QWORD *)(v14 + 1360)) != 0 )
    {
      v15 = *(_QWORD *)(v24 + 3880);
      if ( *(_DWORD *)(v15 + 24) | *(unsigned __int16 *)(v15 + 28) && *(_DWORD *)v15 | *(unsigned __int16 *)(v15 + 4) )
      {
        v25 = 1;
        v26 = *a3 & 0xFFFFFF00 | *(unsigned __int8 *)(v15 + 12);
        *a3 = v26;
        a3[1] = **(unsigned __int16 **)(v15 + 32);
        *a3 = v26 & 0xFFFF00FF | (*(unsigned __int8 *)(v15 + 6) << 8);
        a3 += 2;
        v15 = *(_QWORD *)(v24 + 3880);
      }
      else
      {
        v25 = 0;
      }
      if ( *(_DWORD *)(v15 + 72) | *(unsigned __int16 *)(v15 + 76)
        && *(_DWORD *)(v15 + 48) | *(unsigned __int16 *)(v15 + 52) )
      {
        ++v25;
        v28 = *a3 & 0xFFFFFF00 | *(unsigned __int8 *)(v15 + 60);
        *a3 = v28;
        a3[1] = **(unsigned __int16 **)(v15 + 80);
        *a3 = v28 & 0xFFFF00FF | (*(unsigned __int8 *)(v15 + 54) << 8);
        a3 += 2;
        v15 = *(_QWORD *)(v24 + 3880);
      }
      if ( *(_DWORD *)(v15 + 120) | *(unsigned __int16 *)(v15 + 124)
        && *(_DWORD *)(v15 + 96) | *(unsigned __int16 *)(v15 + 100) )
      {
        ++v25;
        v29 = *a3 & 0xFFFFFF00 | *(unsigned __int8 *)(v15 + 108);
        *a3 = v29;
        a3[1] = **(unsigned __int16 **)(v15 + 128);
        v15 = *(unsigned __int8 *)(v15 + 102);
        *a3 = v29 & 0xFFFF00FF | ((unsigned __int8)v15 << 8);
      }
    }
    else
    {
      v25 = 0;
    }
    wlan_objmgr_vdev_release_ref(v14, 0x5Au, (unsigned int *)v15, v16, v17, v18, v19, v20, v21, v22, v23);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid vdev for id %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "mlo_get_ml_links_info",
      v4);
    v25 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v25;
}
