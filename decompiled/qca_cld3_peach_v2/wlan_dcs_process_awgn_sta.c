unsigned __int16 *__fastcall wlan_dcs_process_awgn_sta(unsigned __int16 *result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  unsigned int v15; // w20
  unsigned int v16; // w23
  char max_no_intf_bw; // w0
  unsigned int v18; // w21
  const char *v19; // x2
  __int64 v20; // x8
  _DWORD *v21; // x9
  unsigned int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 8;
  if ( result )
  {
    if ( a2 )
    {
      if ( !*(_DWORD *)(a2 + 16) )
      {
        v3 = *(unsigned __int8 *)(a2 + 168);
        result = (unsigned __int16 *)wlan_vdev_mlme_is_active(a2);
        if ( !(_DWORD)result )
        {
          result = (unsigned __int16 *)wlan_vdev_get_active_channel(a2);
          if ( result )
          {
            v14 = a3;
            v15 = *result;
            if ( *(_DWORD *)(v14 + 4) != v15 )
            {
              v19 = "%s: STA-%d: freq not match";
              goto LABEL_12;
            }
            v16 = *((_DWORD *)result + 6);
            max_no_intf_bw = wlan_dcs_get_max_no_intf_bw(v14, &v22);
            v18 = v22;
            if ( (max_no_intf_bw & 1) != 0 )
            {
              if ( v16 <= v22 )
              {
                v19 = "%s: STA-%d: freq and bw are unchanged";
LABEL_12:
                result = (unsigned __int16 *)qdf_trace_msg(
                                               0x74u,
                                               8u,
                                               v19,
                                               v6,
                                               v7,
                                               v8,
                                               v9,
                                               v10,
                                               v11,
                                               v12,
                                               v13,
                                               "wlan_dcs_process_awgn_sta",
                                               v3);
                goto LABEL_5;
              }
            }
            else
            {
              v15 = 0;
            }
            result = (unsigned __int16 *)qdf_trace_msg(
                                           0x74u,
                                           8u,
                                           "%s: STA-%d: target freq %u width %u",
                                           v6,
                                           v7,
                                           v8,
                                           v9,
                                           v10,
                                           v11,
                                           v12,
                                           v13,
                                           "wlan_dcs_process_awgn_sta",
                                           v3,
                                           v15,
                                           v22);
            v20 = *(_QWORD *)(a2 + 216);
            if ( v20 )
            {
              result = *(unsigned __int16 **)(v20 + 80);
              if ( result )
              {
                result = (unsigned __int16 *)wlan_objmgr_psoc_get_comp_private_obj((__int64)result, 0x24u);
                if ( result )
                {
                  v21 = *((_DWORD **)result + 146);
                  if ( v21 )
                  {
                    if ( *(v21 - 1) != 1670170395 )
                      __break(0x8229u);
                    result = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v21)(a2, v15, v18);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
