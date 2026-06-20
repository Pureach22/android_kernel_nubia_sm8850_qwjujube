__int64 __fastcall wlan_cm_set_force_20mhz_in_24ghz(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w21
  int v23; // w20
  unsigned int vdev_dot11_mode; // w0

  if ( result )
  {
    v2 = *(_QWORD *)(result + 152);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 80);
      if ( v3 )
      {
        v4 = result;
        result = mlme_get_psoc_ext_obj_fl(v3);
        if ( result )
        {
          if ( *(_BYTE *)(result + 2604) == 1 )
          {
            result = wlan_vdev_mlme_get_ext_hdl(v4, v6, v7, v8, v9, v10, v11, v12, v13);
            if ( result )
            {
              v22 = *(unsigned __int8 *)(result + 24268);
              v23 = (a2 & 1) == 0;
              *(_BYTE *)(result + 24268) = v23;
              result = cm_is_vdev_connected(v4, v14, v15, v16, v17, v18, v19, v20, v21);
              if ( v22 != v23 && (result & 1) != 0 )
              {
                vdev_dot11_mode = cm_csr_get_vdev_dot11_mode(*(unsigned __int8 *)(v4 + 104));
                return cm_send_ies_for_roam_invoke(v4, vdev_dot11_mode);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
