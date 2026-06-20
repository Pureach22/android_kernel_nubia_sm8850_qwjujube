__int64 __fastcall os_if_nan_process_ndi_create(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x22
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  unsigned int v34; // w20
  const char *v35; // x2
  __int64 v36; // x22
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w19
  unsigned int (__fastcall *v47)(__int64); // x8
  __int64 (__fastcall *v48)(__int64, _QWORD); // x8
  __int64 v49; // [xsp+0h] [xbp-E0h] BYREF
  _QWORD v50[4]; // [xsp+8h] [xbp-D8h] BYREF
  unsigned int (__fastcall *v51)(__int64); // [xsp+28h] [xbp-B8h]
  __int64 (__fastcall *v52)(__int64, _QWORD); // [xsp+30h] [xbp-B0h]
  __int64 v53; // [xsp+38h] [xbp-A8h]
  __int64 v54; // [xsp+40h] [xbp-A0h]
  __int64 v55; // [xsp+48h] [xbp-98h]
  __int64 v56; // [xsp+50h] [xbp-90h]
  __int64 v57; // [xsp+58h] [xbp-88h]
  __int64 v58; // [xsp+60h] [xbp-80h]
  __int64 v59; // [xsp+68h] [xbp-78h]
  __int64 v60; // [xsp+70h] [xbp-70h]
  __int64 v61; // [xsp+78h] [xbp-68h]
  __int64 v62; // [xsp+80h] [xbp-60h]
  __int64 v63; // [xsp+88h] [xbp-58h]
  __int64 v64; // [xsp+90h] [xbp-50h]
  __int64 v65; // [xsp+98h] [xbp-48h]
  __int64 v66; // [xsp+A0h] [xbp-40h]
  __int64 v67; // [xsp+A8h] [xbp-38h]
  __int64 v68; // [xsp+B0h] [xbp-30h]
  __int64 v69; // [xsp+B8h] [xbp-28h]
  __int64 v70; // [xsp+C0h] [xbp-20h]
  __int64 v71; // [xsp+C8h] [xbp-18h] BYREF
  __int64 v72; // [xsp+D0h] [xbp-10h]
  __int64 v73; // [xsp+D8h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  qdf_trace_msg(0x48u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "os_if_nan_process_ndi_create");
  if ( a2 && (v14 = *(_QWORD *)(a2 + 48)) != 0 )
  {
    result = _osif_vdev_sync_trans_start(*(_QWORD *)(a3 + 32), (__int64)&v49, (__int64)"os_if_nan_process_ndi_create");
    if ( !(_DWORD)result )
    {
      v69 = 0;
      v70 = 0;
      v24 = v14 + 4;
      v67 = 0;
      v68 = 0;
      v65 = 0;
      v66 = 0;
      v63 = 0;
      v64 = 0;
      v61 = 0;
      v62 = 0;
      v59 = 0;
      v60 = 0;
      v57 = 0;
      v58 = 0;
      v55 = 0;
      v56 = 0;
      v53 = 0;
      v54 = 0;
      v51 = nullptr;
      v52 = nullptr;
      memset(v50, 0, sizeof(v50));
      qdf_trace_msg(0x48u, 8u, "%s: enter", v16, v17, v18, v19, v20, v21, v22, v23, "__os_if_nan_process_ndi_create");
      v71 = v14 + 4;
      v72 = 0;
      wlan_objmgr_iterate_obj_list(a1, 2, os_if_get_ndi_vdev_by_ifname_cb, (__int64)&v71, 0, 0x14u);
      if ( v72
        && !(unsigned int)wlan_objmgr_vdev_try_get_ref(v72, 0x14u, v25, v26, v27, v28, v29, v30, v31, v32)
        && (v36 = v72) != 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: NAN data interface %s is already present",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "__os_if_nan_process_ndi_create",
          v24);
        wlan_objmgr_vdev_release_ref(v36, 0x14u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
        v46 = -17;
      }
      else
      {
        v33 = *(_QWORD *)(a2 + 16);
        if ( v33 )
        {
          v34 = *(unsigned __int16 *)(v33 + 4);
          if ( (unsigned int)ucfg_nan_get_callbacks(a1, v50, v25, v26, v27, v28, v29, v30, v31, v32) )
          {
            v35 = "%s: Couldn't get callback object";
          }
          else
          {
            v47 = v51;
            if ( *((_DWORD *)v51 - 1) != 2097871991 )
              __break(0x8228u);
            if ( !v47(v24) )
            {
              v48 = v52;
              if ( *((_DWORD *)v52 - 1) != 325508325 )
                __break(0x8228u);
              v46 = v48(v24, v34);
              goto LABEL_19;
            }
            v35 = "%s: NDI set mode fails";
          }
        }
        else
        {
          v35 = "%s: transaction id is unavailable";
        }
        qdf_trace_msg(0x48u, 2u, v35, v25, v26, v27, v28, v29, v30, v31, v32, "__os_if_nan_process_ndi_create");
        v46 = -22;
      }
LABEL_19:
      osif_vdev_sync_trans_stop(v49);
      result = v46;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
