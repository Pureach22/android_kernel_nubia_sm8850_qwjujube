__int64 __fastcall cm_update_scan_mlme_on_disconnect(
        __int64 result,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  __int64 v11; // x19
  __int64 v13; // x20
  __int64 active_channel; // x0
  unsigned __int16 *v15; // x21
  __int64 cmpt_obj; // x0
  size_t v17; // x2
  unsigned int v18; // w8
  __int16 v19; // w9
  int v20; // w10
  __int64 v21; // x4
  __int64 v22; // x5
  const char *v23; // x2
  __int64 v24; // [xsp+0h] [xbp-80h] BYREF
  __int64 v25; // [xsp+8h] [xbp-78h]
  __int64 v26; // [xsp+10h] [xbp-70h]
  __int64 v27; // [xsp+18h] [xbp-68h]
  _OWORD v28[2]; // [xsp+20h] [xbp-60h] BYREF
  char v29; // [xsp+40h] [xbp-40h]
  _DWORD v30[12]; // [xsp+48h] [xbp-38h] BYREF
  __int64 v31; // [xsp+78h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2[2];
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  if ( v10 != 18 )
  {
    v11 = *(_QWORD *)(result + 216);
    memset(v30, 0, 44);
    if ( v11 )
    {
      v13 = result;
      active_channel = wlan_vdev_get_active_channel(result);
      if ( active_channel )
      {
        v15 = (unsigned __int16 *)active_channel;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v13);
        if ( cmpt_obj )
        {
          v17 = *(unsigned __int8 *)(cmpt_obj + 178);
          if ( *(_BYTE *)(cmpt_obj + 178) )
          {
            LOBYTE(v30[1]) = *(_BYTE *)(cmpt_obj + 178);
            qdf_mem_copy((char *)&v30[1] + 1, (const void *)(cmpt_obj + 145), v17);
            v18 = a2[4];
            v19 = *((_WORD *)a2 + 10);
            HIDWORD(v26) = 0;
            *(_DWORD *)((char *)&v30[9] + 1) = v18;
            *(_WORD *)((char *)&v30[10] + 1) = v19;
            v20 = *v15;
            v28[1] = *(_OWORD *)&v30[5];
            v30[0] = v20;
            v29 = v30[9];
            v28[0] = *(_OWORD *)&v30[1];
            cm_standby_link_update_mlme_by_bssid(v13, 0, v28);
            result = scm_scan_update_mlme_by_bssinfo(v11, v30, &v24);
            goto LABEL_11;
          }
        }
        v21 = *((unsigned __int8 *)a2 + 4);
        v22 = *a2;
        v23 = "%s: vdev %d cm_id 0x%x: failed to get ssid";
      }
      else
      {
        v21 = *((unsigned __int8 *)a2 + 4);
        v22 = *a2;
        v23 = "%s: vdev %d cm_id 0x%x: failed to get active channel";
      }
    }
    else
    {
      v21 = *((unsigned __int8 *)a2 + 4);
      v22 = *a2;
      v23 = "%s: vdev %d cm_id 0x%x: failed to find pdev";
    }
    result = qdf_trace_msg(
               0x68u,
               2u,
               v23,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "cm_update_scan_mlme_on_disconnect",
               v21,
               v22,
               v24,
               v25,
               v26,
               v27);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
