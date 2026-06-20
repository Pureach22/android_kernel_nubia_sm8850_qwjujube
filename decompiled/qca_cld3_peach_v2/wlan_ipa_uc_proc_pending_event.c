__int64 __fastcall wlan_ipa_uc_proc_pending_event(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 v22; // x8
  int v23; // w20
  __int64 v24; // x21
  unsigned int *v25; // x8
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(a1 + 4032);
  v36[0] = 0;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: Pending Event Count %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_ipa_uc_proc_pending_event",
    v12);
  if ( v12 )
  {
    result = qdf_list_remove_front((_DWORD *)(a1 + 4016), v36);
    v22 = v36[0];
    if ( v36[0] )
    {
      v23 = a2 & 1;
      do
      {
        v26 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                *(_QWORD *)a1,
                *(unsigned __int8 *)(v22 + 33),
                37);
        v25 = (unsigned int *)v36[0];
        if ( *(unsigned __int8 *)(v36[0] + 40LL) != v23 || v26 == 0 )
        {
          if ( !v26 )
            goto LABEL_5;
        }
        else
        {
          v24 = v26;
          _wlan_ipa_wlan_evt(
            *(_QWORD *)(v36[0] + 24LL),
            *(unsigned __int8 *)(v36[0] + 32LL),
            *(unsigned __int8 *)(v36[0] + 33LL),
            *(_DWORD *)(v36[0] + 16LL),
            (unsigned __int8 *)(v36[0] + 34LL),
            *(_BYTE *)(v36[0] + 41LL),
            a1,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34);
          v26 = v24;
        }
        wlan_objmgr_vdev_release_ref(v26, 0x25u, v25, v27, v28, v29, v30, v31, v32, v33, v34);
        v25 = (unsigned int *)v36[0];
LABEL_5:
        _qdf_mem_free((__int64)v25);
        v36[0] = 0;
        result = qdf_list_remove_front((_DWORD *)(a1 + 4016), v36);
        v22 = v36[0];
      }
      while ( v36[0] );
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x61u,
               8u,
               "%s: No Pending Event",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "wlan_ipa_uc_proc_pending_event");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
