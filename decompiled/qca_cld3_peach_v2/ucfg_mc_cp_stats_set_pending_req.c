__int64 __fastcall ucfg_mc_cp_stats_set_pending_req(
        __int64 a1,
        unsigned int a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  __int64 v14; // x21
  unsigned __int64 StatusReg; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 v26; // x8
  int v27; // w9
  __int64 v28; // x8
  _QWORD *v29; // x8
  __int64 v30; // x9
  __int64 v31; // x9
  __int64 v32; // x11
  __int64 v33; // x12
  __int64 v34; // x8

  if ( a1
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu)) != 0
    && (v14 = *(_QWORD *)(comp_private_obj + 24)) != 0 )
  {
    if ( a2 < 7 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v14 + 16);
      }
      else
      {
        raw_spin_lock_bh(v14 + 16);
        *(_QWORD *)(v14 + 24) |= 1uLL;
      }
      v25 = *(_QWORD *)(v14 + 40);
      if ( *(_BYTE *)v25 == 1 )
      {
        qdf_trace_msg(
          0x62u,
          8u,
          "%s: cp stats is suspended try again after resume",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "ucfg_mc_cp_stats_set_pending_req");
        v26 = *(_QWORD *)(v14 + 24);
        if ( (v26 & 1) != 0 )
        {
          *(_QWORD *)(v14 + 24) = v26 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v14 + 16);
        }
        else
        {
          raw_spin_unlock(v14 + 16);
        }
        return 3;
      }
      else
      {
        v27 = *(_DWORD *)(v25 + 8);
        if ( (v27 & (1 << a2)) != 0 )
        {
          qdf_trace_msg(
            0x62u,
            2u,
            "%s: Stats request of type %d is in progress",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "ucfg_mc_cp_stats_set_pending_req",
            a2);
          v28 = *(_QWORD *)(v14 + 24);
          if ( (v28 & 1) != 0 )
          {
            *(_QWORD *)(v14 + 24) = v28 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v14 + 16);
          }
          else
          {
            raw_spin_unlock(v14 + 16);
          }
          return 4;
        }
        else
        {
          *(_DWORD *)(v25 + 8) = v27 | (1 << a2);
          v29 = (_QWORD *)(v25 + 48LL * a2);
          v30 = a3[1];
          v29[2] = *a3;
          v29[3] = v30;
          v31 = a3[5];
          v32 = a3[2];
          v33 = a3[3];
          v29[6] = a3[4];
          v29[7] = v31;
          v29[4] = v32;
          v29[5] = v33;
          v34 = *(_QWORD *)(v14 + 24);
          if ( (v34 & 1) != 0 )
          {
            *(_QWORD *)(v14 + 24) = v34 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v14 + 16);
          }
          else
          {
            raw_spin_unlock(v14 + 16);
          }
          return 0;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: Invalid type index: %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "ucfg_mc_cp_stats_set_pending_req",
        a2);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: psoc cp stats object is null",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "ucfg_mc_cp_stats_set_pending_req");
    return 29;
  }
}
