__int64 __fastcall scm_disable_obss_pdev_scan(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned __int64 StatusReg; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  unsigned __int16 v22; // w26
  __int64 comp_private_obj; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x27
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _QWORD v50[2]; // [xsp+0h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
  if ( result )
  {
    if ( *(_BYTE *)(result + 18741) == 1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a2 + 1248);
      }
      else
      {
        raw_spin_lock_bh(a2 + 1248);
        *(_QWORD *)(a2 + 1256) |= 1uLL;
      }
      v50[0] = 0;
      if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a2 + 48), v50) )
      {
        v21 = v50[0];
        if ( v50[0] )
        {
          v22 = 0;
          do
          {
            qdf_trace_msg(
              0x15u,
              8u,
              "%s: wlan_vdev_list[%d]: %pK",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "scm_disable_obss_pdev_scan",
              v22,
              v21);
            comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v21, 3u);
            if ( comp_private_obj )
            {
              if ( (*(_BYTE *)(comp_private_obj + 24) & 1) != 0 )
              {
                v32 = comp_private_obj;
                if ( (unsigned int)tgt_scan_obss_disable(v21) )
                  qdf_trace_msg(
                    0x15u,
                    2u,
                    "%s: disable obss scan failed",
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    "scm_disable_obss_pdev_scan");
                *(_BYTE *)(v32 + 24) = 0;
              }
              else
              {
                qdf_trace_msg(
                  0x15u,
                  8u,
                  "OBSS scan is not enabled for vdev id: %d",
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  (unsigned __int8)byte_A8[v21]);
              }
            }
            else
            {
              qdf_trace_msg(
                0x15u,
                2u,
                "%s: null scan_vdev_obj",
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                "scm_disable_obss_pdev_scan");
            }
            v50[0] = 0;
            if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a2 + 48), (_QWORD *)v21, v50) )
              break;
            v21 = v50[0];
            ++v22;
          }
          while ( v50[0] );
        }
      }
      v41 = *(_QWORD *)(a2 + 1256);
      if ( (v41 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 1256) = v41 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a2 + 1248);
      }
      else
      {
        result = raw_spin_unlock(a2 + 1248);
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_psoc_get_scan_obj_fl",
      "scm_disable_obss_pdev_scan",
      2017);
    result = qdf_trace_msg(
               0x15u,
               2u,
               "%s: scan object null",
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               "scm_disable_obss_pdev_scan");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
