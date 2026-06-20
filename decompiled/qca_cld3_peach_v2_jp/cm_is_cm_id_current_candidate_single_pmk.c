__int64 __fastcall cm_is_cm_id_current_candidate_single_pmk(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x21
  _QWORD *v15; // x1
  char v16; // w20
  __int64 v18; // x8
  _QWORD *v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v19 = nullptr;
  v20[0] = 0;
  v13 = *(_QWORD *)(v12 + 152);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find psoc",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_is_cm_id_current_candidate_single_pmk",
      *(unsigned __int8 *)(v12 + 104),
      a2);
LABEL_10:
    v16 = 0;
    goto LABEL_11;
  }
  if ( (a2 & 0xF000000) != 0xC000000 || (wlan_crypto_get_param(v12, 7u) & 0x8000400) == 0 )
    goto LABEL_10;
  qdf_mutex_acquire((__int64)(a1 + 15));
  qdf_list_peek_front(a1 + 12, v20);
  v15 = (_QWORD *)v20[0];
  if ( !v20[0] )
    goto LABEL_14;
  while ( 1 )
  {
    qdf_list_peek_next(a1 + 12, v15, &v19);
    if ( *(_DWORD *)(v20[0] + 16LL) == a2 )
      break;
    v15 = v19;
    v19 = nullptr;
    v20[0] = v15;
    if ( !v15 )
      goto LABEL_14;
  }
  v18 = *(_QWORD *)(v20[0] + 864LL);
  if ( v18 )
    v16 = util_scan_entry_single_pmk(v14, *(_QWORD *)(v18 + 24));
  else
LABEL_14:
    v16 = 0;
  qdf_mutex_release((__int64)(a1 + 15));
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v16 & 1;
}
