__int64 __fastcall wlan_cm_init(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x9
  int v4; // w8
  __int64 v5; // x20
  __int64 result; // x0
  _QWORD *v7; // x0
  unsigned int v8; // w8
  __int64 v9; // x0
  unsigned int v10; // w20
  unsigned int v11; // w0
  __int64 v12; // x8
  _QWORD *v13; // x8

  v1 = *(_QWORD *)(a1 + 504);
  v3 = *(_QWORD *)(v1 + 152);
  v4 = *(_DWORD *)(v1 + 16);
  if ( v3 )
  {
    v5 = *(_QWORD *)(v3 + 80);
    if ( (v4 & 0xFFFFFFFD) != 0 )
      return 0;
  }
  else
  {
    v5 = 0;
    if ( (v4 & 0xFFFFFFFD) != 0 )
      return 0;
  }
  v7 = (_QWORD *)_qdf_mem_malloc(0x100u, "wlan_cm_init", 80);
  *(_QWORD *)(a1 + 496) = v7;
  if ( !v7 )
    return 2;
  *v7 = v1;
  v8 = mlme_cm_ext_hdl_create(v1, *(_QWORD *)(a1 + 496) + 248LL);
  v9 = *(_QWORD *)(a1 + 496);
  if ( !v8 )
  {
    v11 = cm_sm_create(v9);
    v12 = *(_QWORD *)(a1 + 496);
    if ( v11 )
    {
      v10 = v11;
      mlme_cm_ext_hdl_destroy(v1, *(_QWORD *)(v12 + 248));
      *(_QWORD *)(*(_QWORD *)(a1 + 496) + 248LL) = 0;
      v9 = *(_QWORD *)(a1 + 496);
      goto LABEL_12;
    }
    *(_BYTE *)(v12 + 192) = 10;
    *(_DWORD *)(*(_QWORD *)(a1 + 496) + 196LL) = 15000;
    v13 = *(_QWORD **)(a1 + 496);
    v13[12] = v13 + 12;
    v13[13] = v13 + 12;
    v13[14] = 0x500000000LL;
    qdf_mutex_create(*(_QWORD *)(a1 + 496) + 120LL);
    *(_WORD *)(*(_QWORD *)(a1 + 496) + 200LL) = wlan_scan_register_requester(
                                                  v5,
                                                  "CM",
                                                  wlan_cm_scan_cb,
                                                  *(_QWORD *)(a1 + 496));
    qdf_event_create((_DWORD *)(*(_QWORD *)(a1 + 496) + 208LL));
    return 0;
  }
  v10 = v8;
LABEL_12:
  _qdf_mem_free(v9);
  result = v10;
  *(_QWORD *)(a1 + 496) = 0;
  return result;
}
