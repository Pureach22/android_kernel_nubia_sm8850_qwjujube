__int64 __fastcall dlm_dump_denylist_bssid(__int64 a1)
{
  __int64 pdev_obj; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 psoc_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  const char *v15; // x2
  __int64 result; // x0
  _QWORD *v17; // x1
  __int64 v18; // x22
  unsigned int v19; // w23
  int delta_of_bssid; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // [xsp+0h] [xbp-40h]
  __int64 v30; // [xsp+8h] [xbp-38h]
  __int64 v31; // [xsp+10h] [xbp-30h]
  __int64 v32; // [xsp+18h] [xbp-28h]
  _QWORD *v33; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v34[2]; // [xsp+30h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = nullptr;
  v34[0] = 0;
  pdev_obj = dlm_get_pdev_obj();
  v3 = *(_QWORD *)(a1 + 80);
  v4 = pdev_obj;
  psoc_obj = dlm_get_psoc_obj(v3);
  if ( !v4 || (v14 = psoc_obj) == 0 )
  {
    v15 = "%s: dlm_ctx or dlm_psoc_obj is NULL";
    goto LABEL_6;
  }
  if ( (unsigned int)qdf_mutex_acquire(v4) )
  {
    v15 = "%s: failed to acquire reject_ap_list_lock";
LABEL_6:
    result = qdf_trace_msg(0x6Du, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "dlm_dump_denylist_bssid");
    goto LABEL_7;
  }
  qdf_list_peek_front((_QWORD *)(v4 + 64), v34);
  v17 = (_QWORD *)v34[0];
  if ( v34[0] )
  {
    do
    {
      qdf_list_peek_next((_QWORD *)(v4 + 64), v17, &v33);
      v18 = v34[0];
      if ( (*(_BYTE *)(v34[0] + 136LL) & 4) != 0 )
      {
        v19 = 0;
      }
      else if ( (*(_BYTE *)(v34[0] + 136LL) & 1) != 0 )
      {
        v19 = 1;
      }
      else if ( (*(_BYTE *)(v34[0] + 136LL) & 8) != 0 )
      {
        v19 = 2;
      }
      else if ( (*(_BYTE *)(v34[0] + 136LL) & 2) != 0 )
      {
        v19 = 3;
      }
      else if ( (*(_BYTE *)(v34[0] + 136LL) & 0x10) != 0 )
      {
        v19 = 4;
      }
      else if ( (*(_BYTE *)(v34[0] + 136LL) & 0x20) != 0 )
      {
        v19 = 5;
      }
      else
      {
        v19 = 6;
      }
      delta_of_bssid = dlm_get_delta_of_bssid(v19, v34[0], v14 + 8);
      LODWORD(v31) = *(_DWORD *)(v18 + 140);
      LODWORD(v32) = *(_DWORD *)(v18 + 76);
      LODWORD(v30) = *(char *)(v18 + 60);
      LODWORD(v29) = delta_of_bssid;
      qdf_trace_msg(
        0x6Du,
        8u,
        "DENYLIST BSSID %02x:%02x:%02x:**:**:%02x type %s retry delay %dms expected RSSI %d reject reason %d rejection source %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32);
      v17 = v33;
      v33 = nullptr;
      v34[0] = v17;
    }
    while ( v17 );
  }
  result = qdf_mutex_release(v4);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
