__int64 __fastcall policy_mgr_restore_no_force(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w0
  __int64 result; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // [xsp+20h] [xbp-20h] BYREF
  __int64 v54; // [xsp+28h] [xbp-18h]
  __int16 v55; // [xsp+30h] [xbp-10h]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v53 = 0;
  v54 = 0;
  if ( (_BYTE)a2 )
  {
    v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a3, 24);
    if ( v16 )
    {
      v25 = v16;
      ml_nlink_get_curr_force_state(a1, v16, &v53);
      if ( (a4 & 1) == 0 || (v34 = (unsigned int *)(unsigned __int16)v53, (_WORD)v53) )
      {
        v43 = (ml_is_nlink_service_supported(a1) & 1) != 0
            ? policy_mgr_mlo_sta_set_nlink(a1, *a3, 2u, 5u, 0, 0, 0, 0)
            : policy_mgr_mlo_sta_set_link_ext(a1, 2u, 5u, a2, a3, 0, 0, v35, v36, v37, v38, v39, v40, v41, v42);
        v34 = (unsigned int *)(unsigned __int16)v53;
        if ( (_WORD)v53 )
        {
          if ( (a4 & 1) != 0 )
          {
            if ( v43 == 24 )
              policy_mgr_wait_for_set_link_update(a1);
            else
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: status %d",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "policy_mgr_restore_no_force");
            ml_nlink_get_curr_force_state(a1, v25, &v53);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "policy_mgr_restore_no_force",
              WORD1(v53),
              (unsigned __int16)v53,
              (unsigned __int8)v54,
              WORD1(v54),
              BYTE4(v53),
              HIWORD(v53),
              WORD2(v54));
          }
        }
      }
      result = wlan_objmgr_vdev_release_ref(v25, 0x18u, v34, v26, v27, v28, v29, v30, v31, v32, v33);
    }
    else
    {
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: invalid vdev for id %d",
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 "policy_mgr_restore_no_force",
                 *a3);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: invalid num_mlo %d",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "policy_mgr_restore_no_force",
               0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
