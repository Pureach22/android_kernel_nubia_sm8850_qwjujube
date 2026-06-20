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
  __int64 v13; // x21
  __int64 active_channel; // x0
  unsigned __int16 *v15; // x20
  __int64 cmpt_obj; // x0
  size_t v17; // x2
  unsigned int v18; // w8
  __int16 v19; // w9
  __int64 v20; // x4
  __int64 v21; // x5
  const char *v22; // x2
  _QWORD v23[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v24; // [xsp+18h] [xbp-48h]
  __int64 v25; // [xsp+20h] [xbp-40h]
  _QWORD v26[7]; // [xsp+28h] [xbp-38h] BYREF

  v26[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a2[2];
  v24 = 0;
  v25 = 0;
  v23[0] = 0;
  v23[1] = 0;
  if ( v10 != 18 )
  {
    v11 = *(_QWORD *)(result + 152);
    memset(v26, 0, 44);
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
          v17 = *(unsigned __int8 *)(cmpt_obj + 162);
          if ( *(_BYTE *)(cmpt_obj + 162) )
          {
            BYTE4(v26[0]) = *(_BYTE *)(cmpt_obj + 162);
            qdf_mem_copy((char *)v26 + 5, (const void *)(cmpt_obj + 129), v17);
            v18 = a2[4];
            v19 = *((_WORD *)a2 + 10);
            HIDWORD(v24) = 0;
            *(_DWORD *)((char *)&v26[4] + 5) = v18;
            *(_WORD *)((char *)&v26[5] + 1) = v19;
            LODWORD(v26[0]) = *v15;
            result = scm_scan_update_mlme_by_bssinfo(v11, v26, v23);
            goto LABEL_11;
          }
        }
        v20 = *((unsigned __int8 *)a2 + 4);
        v21 = *a2;
        v22 = "%s: vdev %d cm_id 0x%x: failed to get ssid";
      }
      else
      {
        v20 = *((unsigned __int8 *)a2 + 4);
        v21 = *a2;
        v22 = "%s: vdev %d cm_id 0x%x: failed to get active channel";
      }
    }
    else
    {
      v20 = *((unsigned __int8 *)a2 + 4);
      v21 = *a2;
      v22 = "%s: vdev %d cm_id 0x%x: failed to find pdev";
    }
    result = qdf_trace_msg(
               0x68u,
               2u,
               v22,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "cm_update_scan_mlme_on_disconnect",
               v20,
               v21);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
