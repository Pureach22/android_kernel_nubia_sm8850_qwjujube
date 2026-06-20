__int64 __fastcall cm_update_scan_mlme_on_roam(
        __int64 a1,
        int *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  __int64 active_channel; // x0
  unsigned __int16 *v16; // x22
  __int64 cmpt_obj; // x0
  size_t v18; // x2
  int v19; // w8
  __int16 v20; // w9
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  const char *v30; // x2
  _QWORD v31[2]; // [xsp+8h] [xbp-58h] BYREF
  __int64 v32; // [xsp+18h] [xbp-48h]
  __int64 v33; // [xsp+20h] [xbp-40h]
  _QWORD v34[7]; // [xsp+28h] [xbp-38h] BYREF

  v34[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 216);
  v33 = 0;
  memset(v34, 0, 44);
  v31[1] = 0;
  v32 = 0;
  v31[0] = 0;
  if ( !v11 )
  {
    v30 = "%s: failed to find pdev";
LABEL_9:
    result = qdf_trace_msg(0x68u, 2u, v30, a4, a5, a6, a7, a8, a9, a10, a11, "cm_update_scan_mlme_on_roam");
    goto LABEL_10;
  }
  active_channel = wlan_vdev_get_active_channel(a1);
  if ( !active_channel )
  {
    v30 = "%s: failed to get active channel";
    goto LABEL_9;
  }
  v16 = (unsigned __int16 *)active_channel;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cmpt_obj || (v18 = *(unsigned __int8 *)(cmpt_obj + 178), !*(_BYTE *)(cmpt_obj + 178)) )
  {
    v30 = "%s: failed to get ssid";
    goto LABEL_9;
  }
  BYTE4(v34[0]) = *(_BYTE *)(cmpt_obj + 178);
  qdf_mem_copy((char *)v34 + 5, (const void *)(cmpt_obj + 145), v18);
  v19 = *a2;
  v20 = *((_WORD *)a2 + 2);
  HIDWORD(v32) = a3;
  *(_DWORD *)((char *)&v34[4] + 5) = v19;
  *(_WORD *)((char *)&v34[5] + 1) = v20;
  LODWORD(v34[0]) = *v16;
  result = scm_scan_update_mlme_by_bssinfo(v11, (__int64)v34, v31, v21, v22, v23, v24, v25, v26, v27, v28);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
