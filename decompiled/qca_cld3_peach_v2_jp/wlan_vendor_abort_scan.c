__int64 __fastcall wlan_vendor_abort_scan(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v6; // x20
  const char *v7; // x2
  __int64 result; // x0
  unsigned int v9; // w21
  __int64 v10; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v11[7]; // [xsp+10h] [xbp-90h] BYREF
  __int64 v12; // [xsp+48h] [xbp-58h]
  __int64 v13; // [xsp+50h] [xbp-50h]
  __int64 v14; // [xsp+58h] [xbp-48h]
  __int64 v15; // [xsp+60h] [xbp-40h]
  __int64 v16; // [xsp+68h] [xbp-38h]
  __int64 v17; // [xsp+70h] [xbp-30h]
  __int64 v18; // [xsp+78h] [xbp-28h]
  __int64 v19; // [xsp+80h] [xbp-20h]
  __int64 v20; // [xsp+88h] [xbp-18h]
  __int64 v21; // [xsp+90h] [xbp-10h]
  __int64 v22; // [xsp+98h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  memset(v11, 0, sizeof(v11));
  if ( (unsigned int)_nla_parse(v11, 16, a2, a3, &cfg80211_scan_policy, 31, 0) )
  {
    qdf_trace_msg(72, 2, "%s: Invalid ATTR", "wlan_vendor_abort_scan");
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( !v12 )
  {
LABEL_17:
    result = 0;
    goto LABEL_10;
  }
  v10 = 0;
  nla_memcpy(&v10, v12, 8);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = v10;
  v10 = 0;
  if ( !v4 )
  {
    v7 = "%s: Failed to retrieve osif context";
    goto LABEL_8;
  }
  v6 = *(_QWORD *)(v4 + 16);
  qdf_mutex_acquire(v6 + 24);
  if ( (qdf_list_empty(v6) & 1) != 0 )
  {
    qdf_mutex_release(v6 + 24);
    v7 = "%s: Failed to retrieve scan id";
LABEL_8:
    qdf_trace_msg(72, 2, v7, "wlan_get_scanid");
    goto LABEL_9;
  }
  if ( (unsigned int)qdf_list_peek_front(v6, &v10) )
  {
LABEL_12:
    qdf_mutex_release(v6 + 24);
    result = 4294967274LL;
    goto LABEL_10;
  }
  while ( v5 != *(_QWORD *)(v10 + 16) )
  {
    if ( (unsigned int)qdf_list_peek_next(v6, v10, &v10) )
      goto LABEL_12;
  }
  v9 = *(_DWORD *)(v10 + 24);
  qdf_mutex_release(v6 + 24);
  result = ucfg_scan_get_pdev_status(a1);
  if ( (_DWORD)result )
  {
    wlan_abort_scan(a1, -1, 0xFFFFFFFF, v9, 1);
    goto LABEL_17;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
