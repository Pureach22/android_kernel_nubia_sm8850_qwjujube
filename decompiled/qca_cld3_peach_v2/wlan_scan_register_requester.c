__int64 __fastcall wlan_scan_register_requester(
        __int64 a1,
        _BYTE *a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  unsigned __int16 *v25; // x24
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  unsigned int v28; // w23
  _BYTE *v29; // x8
  int v30; // w9
  unsigned __int64 v31; // x11
  unsigned __int64 v32; // x12
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 3u);
    if ( comp_private_obj )
    {
      v24 = comp_private_obj;
      v25 = (unsigned __int16 *)(comp_private_obj + 1824);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 8);
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 8);
        *(_QWORD *)(v24 + 16) |= 1uLL;
      }
      v27 = 0;
      while ( *v25 )
      {
        --v27;
        v25 += 32;
        if ( v27 == -200 )
        {
          v28 = 0;
          goto LABEL_20;
        }
      }
      *v25 = -(__int16)v27 | 0xA000;
      v29 = v25 + 1;
      LOBYTE(v30) = *a2;
      if ( *a2 )
      {
        v31 = 0;
        do
        {
          v32 = v31 + 1;
          *v29++ = v30;
          if ( v31 > 0x25 )
            break;
          v30 = (unsigned __int8)a2[++v31];
        }
        while ( v30 );
      }
      else
      {
        v32 = 0;
      }
      *((_BYTE *)v25 + v32 + 2) = 0;
      v28 = *v25;
      *((_QWORD *)v25 + 6) = a3;
      *((_QWORD *)v25 + 7) = a4;
LABEL_20:
      v33 = *(_QWORD *)(v24 + 16);
      if ( (v33 & 1) != 0 )
      {
        *(_QWORD *)(v24 + 16) = v33 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v24 + 8);
      }
      else
      {
        raw_spin_unlock(v24 + 8);
      }
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: module: %s, event_cb: 0x%pK, arg: 0x%pK, reqid: %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "wlan_scan_register_requester",
        a2,
        a3,
        a4,
        v28);
    }
    else
    {
      qdf_trace_msg(
        0x15u,
        2u,
        "%s: %s:%u, Failed to get scan object",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_psoc_get_scan_obj_fl",
        "wlan_scan_register_requester",
        598);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: null psoc", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_scan_register_requester");
    return 0;
  }
  return v28;
}
