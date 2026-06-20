__int64 __fastcall p2p_rand_mac_tx(__int64 result, __int64 a2)
{
  __int64 *v2; // x8
  __int64 v3; // x20
  _QWORD *vdev_by_id_from_pdev; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  int is_up; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int is_sta_vdev_usage_allowed_for_p2p_dev; // w0
  __int64 v25; // x8
  int v26; // w22
  __int64 v27; // x0
  unsigned int v28; // w24

  if ( a2 )
  {
    v2 = *(__int64 **)(a2 + 16);
    if ( v2 )
    {
      v3 = *v2;
      if ( *v2 )
      {
        vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(result, *(_DWORD *)(a2 + 24), 0xFu);
        if ( vdev_by_id_from_pdev )
        {
          v14 = (__int64)vdev_by_id_from_pdev;
          is_up = wlan_vdev_is_up();
          if ( *(_DWORD *)(a2 + 264) == 7 )
          {
            is_sta_vdev_usage_allowed_for_p2p_dev = p2p_is_sta_vdev_usage_allowed_for_p2p_dev(v3);
            v25 = a2;
            v26 = is_sta_vdev_usage_allowed_for_p2p_dev;
          }
          else
          {
            v25 = a2;
            v26 = 0;
          }
          if ( *(_BYTE *)(v25 + 62) != 1 || (v26 & 1) != 0 )
          {
            if ( *(_DWORD *)(v25 + 44) )
            {
              if ( *(int *)(v25 + 56) >= 25 )
              {
                v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                        v3,
                        *(unsigned int *)(v25 + 24),
                        15);
                if ( v27 )
                {
                  v28 = *(_DWORD *)(v27 + 16);
                  wlan_objmgr_vdev_release_ref(v27, 0xFu, (unsigned int *)v25, v16, v17, v18, v19, v20, v21, v22, v23);
                  if ( v28 <= 0x10 && ((1 << v28) & 0x10085) != 0 )
                  {
                    v25 = (unsigned int)p2p_is_random_mac(v3, *(unsigned int *)(a2 + 24), *(_QWORD *)(a2 + 48) + 10LL)
                        | v26;
                    if ( (v25 & 1) != 0 || is_up )
                    {
                      v25 = (unsigned int)p2p_request_random_mac(
                                            v3,
                                            *(_DWORD *)(a2 + 24),
                                            (unsigned __int8 *)(*(_QWORD *)(a2 + 48) + 10LL),
                                            *(_DWORD *)(a2 + 44),
                                            *(int *)(a2 + 40),
                                            v16,
                                            v17,
                                            v18,
                                            v19,
                                            v20,
                                            v21,
                                            v22,
                                            v23) == 0;
                      *(_BYTE *)(a2 + 63) = v25;
                    }
                  }
                }
              }
            }
          }
          return wlan_objmgr_vdev_release_ref(v14, 0xFu, (unsigned int *)v25, v16, v17, v18, v19, v20, v21, v22, v23);
        }
        else
        {
          return qdf_trace_msg(
                   0x4Eu,
                   2u,
                   "%s: vdev is null id:%d",
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   "p2p_rand_mac_tx",
                   *(unsigned int *)(a2 + 24));
        }
      }
    }
  }
  return result;
}
