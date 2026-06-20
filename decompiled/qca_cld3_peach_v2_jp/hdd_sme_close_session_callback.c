__int64 __fastcall hdd_sme_close_session_callback(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  _DWORD **link_info_by_vdev; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _DWORD *v20; // x20
  _DWORD **v21; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x8
  __int64 v24; // x1
  unsigned __int64 v32; // x10

  context = _cds_get_context(51, (__int64)"hdd_sme_close_session_callback", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  link_info_by_vdev = (_DWORD **)hdd_get_link_info_by_vdev((__int64)context, a1);
  if ( link_info_by_vdev )
  {
    v20 = *link_info_by_vdev;
    v21 = link_info_by_vdev;
    if ( **link_info_by_vdev == 1885692259 )
    {
      _X8 = (unsigned __int64 *)(link_info_by_vdev + 552);
      __asm { PRFM            #0x11, [X8] }
      do
        v32 = __ldxr(_X8);
      while ( __stxr(v32 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(link_info_by_vdev + 2);
        v23 = (__int64)v21[3];
      }
      else
      {
        raw_spin_lock_bh(link_info_by_vdev + 2);
        v23 = (unsigned __int64)v21[3] | 1;
        v21[3] = (_DWORD *)v23;
      }
      *((_BYTE *)v21 + 8) = -1;
      if ( (v23 & 1) != 0 )
      {
        v21[3] = (_DWORD *)(v23 & 0xFFFFFFFFFFFFFFFELL);
        raw_spin_unlock_bh(v21 + 2);
      }
      else
      {
        raw_spin_unlock(v21 + 2);
      }
      if ( *v20 == 1885692259 )
        complete(v21 + 5, v24);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid magic",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_sme_close_session_callback");
      return 28;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid vdev %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_sme_close_session_callback",
      a1);
    return 4;
  }
}
