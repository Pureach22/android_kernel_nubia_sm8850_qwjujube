__int64 __usercall wlan_objmgr_vdev_release_ref@<X0>(
        __int64 result@<X0>,
        unsigned int a2@<W1>,
        unsigned int *_X8@<X8>,
        double a4@<D0>,
        double a5@<D1>,
        double a6@<D2>,
        double a7@<D3>,
        double a8@<D4>,
        double a9@<D5>,
        double a10@<D6>,
        double a11@<D7>)
{
  __int64 v11; // x19
  __int64 v12; // x4
  __int64 v13; // x8
  unsigned int v14; // w19
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 v35; // x21
  __int64 v36; // x22
  __int64 (__fastcall *v37)(__int64, __int64); // x9
  int v38; // w11
  __int64 v39; // x1
  int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v54; // w10
  unsigned int v57; // w8
  unsigned int v58; // w8

  if ( !result )
    return qdf_trace_msg(
             0x57u,
             2u,
             "%s: vdev obj is NULL for id:%d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_objmgr_vdev_release_ref",
             a2);
  if ( a2 >= 0x6E )
  {
    __break(0x5512u);
  }
  else
  {
    v11 = result + 244;
    v12 = *(unsigned __int8 *)(result + 168);
    _X8 = (unsigned int *)(result + 244 + 4LL * a2);
    if ( !*_X8 )
    {
      qdf_trace_msg(
        0x57u,
        1u,
        "%s: vdev (id:%d)ref cnt was not taken by %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_objmgr_vdev_release_ref",
        v12);
      return wlan_objmgr_print_ref_ids(v11, 1u, v26, v27, v28, v29, v30, v31, v32, v33);
    }
    if ( !*(_DWORD *)(result + 240) )
      return qdf_trace_msg(
               0x57u,
               1u,
               "%s: vdev ref cnt is 0",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_objmgr_vdev_release_ref",
               v12);
  }
  __asm { PRFM            #0x11, [X8] }
  do
    v54 = __ldxr(_X8);
  while ( __stxr(v54 - 1, _X8) );
  _X9 = (unsigned int *)(result + 240);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v57 = __ldxr(_X9);
    v58 = v57 - 1;
  }
  while ( __stlxr(v58, _X9) );
  __dmb(0xBu);
  if ( !v58 )
  {
    v13 = *(_QWORD *)(result + 216);
    if ( v13 && *(_QWORD *)(v13 + 80) )
    {
      v14 = *(unsigned __int8 *)(result + 168);
      v15 = result;
      qdf_trace_msg(
        0x57u,
        8u,
        "%s: Physically deleting vdev %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_objmgr_vdev_obj_destroy",
        *(unsigned __int8 *)(result + 168));
      if ( *(_DWORD *)(v15 + 1336) == 6 )
      {
        v24 = *(_QWORD *)(v15 + 216);
        if ( v24 )
          v25 = *(_QWORD *)(v24 + 80);
        else
          v25 = 0;
        wlan_minidump_remove(v15, 1424, v25, 56, "wlan_objmgr_vdev");
        v34 = v15;
        v35 = 1332;
        v36 = 6952;
        do
        {
          v37 = *(__int64 (__fastcall **)(__int64, __int64))(g_umac_glb_obj + v36 - 432);
          if ( v37 && ((v38 = *(_DWORD *)(v34 + v35), v39 = *(_QWORD *)(g_umac_glb_obj + v36), v38 == 40) || !v38) )
          {
            if ( *((_DWORD *)v37 - 1) != -1744405434 )
              __break(0x8229u);
            v40 = v37(v15, v39);
            v34 = v15;
            *(_DWORD *)(v15 + v35) = v40;
          }
          else
          {
            *(_DWORD *)(v34 + v35) = 39;
          }
          v35 -= 4;
          v36 -= 8;
        }
        while ( v35 != 1116 );
        result = wlan_objmgr_vdev_object_status(v34);
        if ( (_DWORD)result == 40 )
        {
          *(_DWORD *)(v15 + 1336) = 4;
        }
        else if ( (_DWORD)result == 16 )
        {
          return qdf_trace_msg(
                   0x57u,
                   2u,
                   "%s: VDEV object deletion failed: vdev-id: %d",
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47,
                   v48,
                   "wlan_objmgr_vdev_obj_destroy",
                   v14);
        }
        else
        {
          return wlan_objmgr_vdev_obj_free(v15);
        }
      }
      else
      {
        return qdf_trace_msg(
                 0x57u,
                 1u,
                 "%s: VDEV object delete is not invoked vdevid:%d objstate:%d",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "wlan_objmgr_vdev_obj_destroy",
                 *(unsigned __int8 *)(v15 + 168));
      }
    }
    else
    {
      return qdf_trace_msg(
               0x57u,
               2u,
               "%s: Failed to get psoc",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_objmgr_vdev_obj_destroy");
    }
  }
  return result;
}
