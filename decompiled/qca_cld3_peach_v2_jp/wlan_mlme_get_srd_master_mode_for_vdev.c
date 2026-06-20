__int64 __fastcall wlan_mlme_get_srd_master_mode_for_vdev(__int64 a1, unsigned int a2, bool *a3)
{
  __int64 psoc_ext_obj_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v14 = psoc_ext_obj_fl;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: opmode %d, INI 0x%x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_mlme_get_srd_master_mode_for_vdev",
      a2,
      *(unsigned __int8 *)(psoc_ext_obj_fl + 5760));
    if ( a2 == 16 )
    {
      *a3 = (*(_BYTE *)(v14 + 5760) & 4) != 0;
      return 0;
    }
    else if ( a2 == 3 )
    {
      *a3 = (*(_BYTE *)(v14 + 5760) & 2) != 0;
      return 0;
    }
    else
    {
      if ( a2 == 1 )
      {
        *a3 = *(_BYTE *)(v14 + 5760) & 1;
      }
      else
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: Unexpected opmode %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_mlme_get_srd_master_mode_for_vdev",
          a2);
        *a3 = 0;
      }
      return 0;
    }
  }
  else
  {
    *a3 = 0;
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Failed to get MLME Obj",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_mlme_get_srd_master_mode_for_vdev");
    return 4;
  }
}
