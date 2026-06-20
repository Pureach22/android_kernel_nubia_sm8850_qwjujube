__int64 __fastcall ucfg_nan_disable_concurrency(
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
  __int64 v11; // x20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int discovery_state; // w0
  __int64 v23; // x8
  const char *v24; // x2
  const char *v25; // x3
  unsigned int v26; // w1
  __int64 v27; // x8
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  __int64 v29; // [xsp+8h] [xbp-18h]
  __int64 v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  if ( !a1 )
  {
    v24 = "%s: psoc object is NULL, no action will be taken";
LABEL_15:
    v25 = "ucfg_nan_disable_concurrency";
LABEL_16:
    v26 = 2;
LABEL_17:
    result = qdf_trace_msg(0x53u, v26, v24, a2, a3, a4, a5, a6, a7, a8, a9, v25, v28, v29, v30, v31);
    goto LABEL_18;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
    v24 = "%s: nan psoc priv object is NULL";
    goto LABEL_15;
  }
  v11 = comp_private_obj;
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !result )
  {
    v24 = "%s: nan psoc priv object is NULL";
    v25 = "ucfg_is_nan_conc_control_supported";
    goto LABEL_16;
  }
  if ( (*(_WORD *)(result + 232) & 1) == 0 )
    goto LABEL_18;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v11);
  }
  else
  {
    raw_spin_lock_bh(v11);
    *(_QWORD *)(v11 + 8) |= 1uLL;
  }
  discovery_state = nan_get_discovery_state(a1, v14, v15, v16, v17, v18, v19, v20, v21);
  if ( discovery_state != 3 && discovery_state )
  {
    v27 = *(_QWORD *)(v11 + 8);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 8) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v11);
    }
    else
    {
      raw_spin_unlock(v11);
    }
    v28 = a1;
    LOWORD(v29) = 257;
    if ( (unsigned int)nan_cache_disable_req_info(a1, 2) )
    {
      v24 = "%s: Unable to set disable req flag";
    }
    else
    {
      if ( !(unsigned int)ucfg_nan_discovery_req(&v28, 2u, a2, a3, a4, a5, a6, a7, a8, a9) )
      {
        v24 = "%s: NAN Disabled successfully";
        v25 = "ucfg_nan_disable_concurrency";
        v26 = 8;
        goto LABEL_17;
      }
      v24 = "%s: Unable to disable NAN Discovery";
    }
    goto LABEL_15;
  }
  v23 = *(_QWORD *)(v11 + 8);
  if ( (v23 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 8) = v23 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(v11);
  }
  else
  {
    result = raw_spin_unlock(v11);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
