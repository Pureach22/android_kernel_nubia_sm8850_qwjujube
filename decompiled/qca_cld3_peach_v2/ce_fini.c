__int64 __fastcall ce_fini(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  int v3; // w24
  __int64 v4; // x23
  void (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x2
  _DWORD *v8; // x8
  void (__fastcall *v9)(_QWORD); // x8
  void (__fastcall *v10)(__int64, __int64 *, __int64); // x8
  unsigned int v11; // w8
  __int64 v12; // x8
  __int64 v13; // x0
  void (__fastcall *v14)(_QWORD); // x8
  void (__fastcall *v15)(__int64, __int64 *, __int64); // x8
  __int64 result; // x0
  _QWORD v17[6]; // [xsp+0h] [xbp-B0h] BYREF
  __int16 v18; // [xsp+30h] [xbp-80h]
  char v19[8]; // [xsp+38h] [xbp-78h] BYREF
  __int64 v20; // [xsp+40h] [xbp-70h]
  __int64 v21; // [xsp+48h] [xbp-68h]
  __int64 v22; // [xsp+50h] [xbp-60h]
  __int64 v23; // [xsp+58h] [xbp-58h]
  __int64 v24; // [xsp+60h] [xbp-50h]
  __int16 v25; // [xsp+68h] [xbp-48h]
  char s[8]; // [xsp+70h] [xbp-40h] BYREF
  __int64 v27; // [xsp+78h] [xbp-38h]
  __int64 v28; // [xsp+80h] [xbp-30h]
  __int64 v29; // [xsp+88h] [xbp-28h]
  __int64 v30; // [xsp+90h] [xbp-20h]
  __int64 v31; // [xsp+98h] [xbp-18h]
  __int16 v32; // [xsp+A0h] [xbp-10h]
  __int64 v33; // [xsp+A8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *((unsigned int *)a1 + 2);
  v2 = *a1;
  v3 = *((unsigned __int8 *)a1 + 212);
  *((_DWORD *)a1 + 5) = 0;
  if ( (unsigned int)v1 >= 0xC )
    __break(0x5512u);
  v4 = v2 + 8 * v1;
  *(_QWORD *)(v4 + 480) = 0;
  if ( a1 && (*((_BYTE *)a1 + 12) & 0x10) != 0 )
    *((_BYTE *)a1 + 212) = 0;
  v32 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  *(_QWORD *)s = 0;
  v27 = 0;
  v25 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  *(_QWORD *)v19 = 0;
  v20 = 0;
  v18 = 0;
  memset(v17, 0, sizeof(v17));
  snprintf(s, 0x32u, "%s%d", "ce_", v1);
  qdf_ssr_driver_dump_unregister_region(s);
  if ( a1[19] )
  {
    snprintf(v19, 0x32u, "%s%s", s, "_status_ring");
    snprintf((char *)v17, 0x32u, "%s%s", v19, "_ctx");
    qdf_ssr_driver_dump_unregister_region(v19);
    qdf_ssr_driver_dump_unregister_region(v17);
  }
  if ( a1[18] )
  {
    snprintf(v19, 0x32u, "%s%s", s, "_dest_ring");
    snprintf((char *)v17, 0x32u, "%s%s", v19, "_ctx");
    qdf_ssr_driver_dump_unregister_region(v19);
    qdf_ssr_driver_dump_unregister_region(v17);
  }
  if ( a1[17] )
  {
    snprintf(v19, 0x32u, "%s%s", s, "_src_ring");
    snprintf((char *)v17, 0x32u, "%s%s", v19, "_ctx");
    qdf_ssr_driver_dump_unregister_region(v19);
    qdf_ssr_driver_dump_unregister_region(v17);
    if ( a1[17] )
    {
      v6 = **(void (__fastcall ***)(_QWORD))(v2 + 30696);
      if ( *((_DWORD *)v6 - 1) != -2597194 )
        __break(0x8228u);
      v6(0);
      v7 = a1[17];
      if ( *(_QWORD *)(v7 + 56) )
      {
        _qdf_mem_free(*(_QWORD *)(v7 + 56));
        v7 = a1[17];
      }
      if ( *(_QWORD *)(v7 + 24) )
        ce_free_desc_ring(v2, *((unsigned int *)a1 + 2));
      v8 = *(_DWORD **)(*(_QWORD *)(v2 + 30696) + 16LL);
      if ( v8 )
      {
        if ( *(v8 - 1) != 918029631 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64 *, _QWORD))v8)(v2, a1, 0);
      }
      _qdf_mem_free(a1[17]);
    }
  }
  if ( a1[18] )
  {
    v9 = **(void (__fastcall ***)(_QWORD))(v2 + 30696);
    if ( *((_DWORD *)v9 - 1) != -2597194 )
      __break(0x8228u);
    v9(1);
    if ( *(_QWORD *)(a1[18] + 24) )
      ce_free_desc_ring(v2, *((unsigned int *)a1 + 2));
    v10 = *(void (__fastcall **)(__int64, __int64 *, __int64))(*(_QWORD *)(v2 + 30696) + 16LL);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 918029631 )
        __break(0x8228u);
      v10(v2, a1, 1);
    }
    _qdf_mem_free(a1[18]);
    if ( v3 )
      timer_delete_sync(a1 + 27);
  }
  v11 = *(_DWORD *)(hif_get_target_info_handle(*a1) + 4);
  if ( v11 <= 0x2B && ((1LL << v11) & 0xFBFFFB00000LL) != 0 )
  {
    v12 = a1[19];
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 56);
      if ( v13 )
        _qdf_mem_free(v13);
      v14 = **(void (__fastcall ***)(_QWORD))(v2 + 30696);
      if ( *((_DWORD *)v14 - 1) != -2597194 )
        __break(0x8228u);
      v14(2);
      if ( *(_QWORD *)(a1[19] + 24) )
        ce_free_desc_ring(v2, *((unsigned int *)a1 + 2));
      v15 = *(void (__fastcall **)(__int64, __int64 *, __int64))(*(_QWORD *)(v2 + 30696) + 16LL);
      if ( v15 )
      {
        if ( *((_DWORD *)v15 - 1) != 918029631 )
          __break(0x8228u);
        v15(v2, a1, 2);
      }
      _qdf_mem_free(a1[19]);
    }
  }
  if ( *(_BYTE *)(v2 + 2812 + v1) == 1 )
  {
    *(_BYTE *)(v2 + 2812 + v1) = 0;
    if ( *(_BYTE *)(v2 + 2824 + v1) == 1 )
      *(_BYTE *)(v2 + 2824 + v1) = 0;
    *(_QWORD *)(v4 + 3616) = 0;
  }
  *(_QWORD *)(v2 + 3608) = 0;
  ((void (__fastcall *)(__int64, _QWORD))ce_deinit_ce_desc_event_log)(v2, (unsigned int)v1);
  result = _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
