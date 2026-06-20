__int64 __fastcall wlan_green_ap_stop(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x19
  unsigned __int64 StatusReg; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
    if ( comp_private_obj )
    {
      v18 = comp_private_obj;
      qdf_trace_msg(
        0x5Du,
        8u,
        "%s: Green AP stop received",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_green_ap_stop");
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v18 + 88);
      }
      else
      {
        raw_spin_lock_bh(v18 + 88);
        *(_QWORD *)(v18 + 96) |= 1uLL;
      }
      if ( wlan_is_egap_enabled(v18, v20, v21, v22, v23, v24, v25, v26, v27) )
      {
        v28 = *(_QWORD *)(v18 + 96);
        if ( (v28 & 1) != 0 )
        {
          *(_QWORD *)(v18 + 96) = v28 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v18 + 88);
        }
        else
        {
          raw_spin_unlock(v18 + 88);
        }
        qdf_trace_msg(
          0x5Du,
          8u,
          "%s: enhanced green ap support is enabled",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_green_ap_stop");
        return 0;
      }
      else
      {
        timer_delete((timer_t)(v18 + 32));
        v38 = *(_QWORD *)(v18 + 96);
        *(_BYTE *)(v18 + 8) = 0;
        if ( (v38 & 1) != 0 )
        {
          *(_QWORD *)(v18 + 96) = v38 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v18 + 88);
        }
        else
        {
          raw_spin_unlock(v18 + 88);
        }
        return wlan_green_ap_state_mc((__int64 *)v18, 2u, v39, v40, v41, v42, v43, v44, v45, v46);
      }
    }
    else
    {
      qdf_trace_msg(
        0x5Du,
        2u,
        "%s: green ap context obtained is NULL",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_green_ap_stop");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x5Du, 2u, "%s: pdev context passed is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_green_ap_stop");
    return 4;
  }
}
