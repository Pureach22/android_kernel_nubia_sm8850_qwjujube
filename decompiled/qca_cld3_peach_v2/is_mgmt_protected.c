__int64 __fastcall is_mgmt_protected(
        unsigned int a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x21
  __int64 session_by_vdev_id; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int16 v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  result = (__int64)_cds_get_context(53, (__int64)"is_mgmt_protected", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v13 = result;
    session_by_vdev_id = pe_find_session_by_vdev_id(result, a1);
    if ( session_by_vdev_id )
    {
      result = dph_lookup_hash_entry(v15, v16, v17, v18, v19, v20, v21, v22, v13, a2, &v23, session_by_vdev_id + 360);
      if ( result )
        result = (*(_WORD *)result & 0x400) != 0 && *(_BYTE *)(result + 657) != 0;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session not found for vdev_id: %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "is_mgmt_protected",
        a1);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
