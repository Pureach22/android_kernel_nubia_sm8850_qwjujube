__int64 __fastcall sde_cp_crtc_destroy_properties(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  _QWORD *v8; // x20
  _QWORD *v10; // x21
  __int64 v11; // x0
  unsigned __int64 v12; // x8
  __int64 v13; // x20
  __int64 v14; // x21
  _QWORD *v15; // x22
  __int64 v16; // x0
  _QWORD *v17; // x8
  _QWORD *v18; // x9
  __int64 v19; // x10
  _QWORD *v20; // x9
  _QWORD *v21; // x8
  __int64 v22; // x10
  _QWORD *v23; // x8
  __int64 v24; // x9
  __int64 v25; // x0
  __int64 v26; // x9
  int v27; // w4
  int v28; // w0
  __int64 result; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return _drm_err("invalid crtc %pK\n", nullptr);
  v8 = *(_QWORD **)(a1 + 4520);
  v10 = (_QWORD *)(a1 + 4520);
  if ( v8 != (_QWORD *)(a1 + 4520) )
  {
    do
    {
      v15 = (_QWORD *)*v8;
      if ( (*((_BYTE *)v8 - 36) & 0x10) != 0 )
      {
        v16 = *(v8 - 3);
        if ( v16 )
          drm_property_blob_put(v16);
      }
      v17 = (_QWORD *)v8[3];
      v18 = v8 + 2;
      if ( (_QWORD *)*v17 == v8 + 2 && (v19 = *v18, *(_QWORD **)(*v18 + 8LL) == v18) )
      {
        *(_QWORD *)(v19 + 8) = v17;
        *v17 = v19;
      }
      else
      {
        _list_del_entry_valid_or_report(v8 + 2);
      }
      v8[2] = v8 + 2;
      v8[3] = v18;
      v20 = v8 + 4;
      v21 = (_QWORD *)v8[5];
      if ( (_QWORD *)*v21 == v8 + 4 && (v22 = *v20, *(_QWORD **)(*v20 + 8LL) == v20) )
      {
        *(_QWORD *)(v22 + 8) = v21;
        *v21 = v22;
      }
      else
      {
        _list_del_entry_valid_or_report(v8 + 4);
      }
      v8[4] = v8 + 4;
      v8[5] = v20;
      v23 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v23 == v8 && (v24 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
      {
        *(_QWORD *)(v24 + 8) = v23;
        *v23 = v24;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *v8 = v8;
      v8[1] = v8;
      if ( (*((_BYTE *)v8 - 36) & 0x10) == 0 )
      {
        v25 = *(v8 - 3);
        if ( v25 )
          drm_property_blob_put(v25);
      }
      kfree(v8 - 5);
      v8 = v15;
    }
    while ( v15 != v10 );
  }
  v11 = *(_QWORD *)(a1 + 7576);
  if ( v11 )
    v11 = drm_property_blob_put(v11);
  v12 = *(unsigned int *)(a1 + 7592);
  if ( (_DWORD)v12 )
  {
    v13 = 0;
    v14 = a1 + 7600;
    while ( v13 != 5 )
    {
      v26 = *(_QWORD *)(v14 + 8 * v13);
      if ( v26 )
      {
        msm_gem_put_vaddr(*(_QWORD *)(v26 + 8));
        drm_mode_object_put(**(_QWORD **)(v14 + 8 * v13) + 24LL);
        msm_gem_put_iova(*(_QWORD *)(*(_QWORD *)(v14 + 8 * v13) + 8LL), *(_QWORD *)(*(_QWORD *)(v14 + 8 * v13) + 16LL));
        v11 = kfree(*(_QWORD *)(v14 + 8 * v13));
        *(_QWORD *)(v14 + 8 * v13) = 0;
        v12 = *(unsigned int *)(a1 + 7592);
      }
      if ( ++v13 >= v12 )
        goto LABEL_30;
    }
    __break(0x5512u);
    return list_del_init(v11);
  }
  else
  {
LABEL_30:
    *(_WORD *)(a1 + 7672) = 0;
    v27 = *(_DWORD *)(a1 + 112);
    v28 = sde_dbg_base_evtlog;
    *(_DWORD *)(a1 + 7592) = 0;
    result = sde_evtlog_log(v28, "sde_cp_crtc_destroy_properties", 2823, -1, v27, 0, -1059143953, a8, vars0);
    *(_DWORD *)(a1 + 7760) = -1;
    *(_QWORD *)(a1 + 4536) = a1 + 4536;
    *(_QWORD *)(a1 + 4544) = a1 + 4536;
    *(_QWORD *)(a1 + 4552) = a1 + 4552;
    *(_QWORD *)(a1 + 4560) = a1 + 4552;
    *(_QWORD *)(a1 + 4568) = a1 + 4568;
    *(_QWORD *)(a1 + 4576) = a1 + 4568;
    *(_QWORD *)(a1 + 4584) = a1 + 4584;
    *(_QWORD *)(a1 + 4592) = a1 + 4584;
    *(_QWORD *)(a1 + 7640) = a1 + 7640;
    *(_QWORD *)(a1 + 7648) = a1 + 7640;
    *(_QWORD *)(a1 + 7656) = a1 + 7656;
    *(_QWORD *)(a1 + 7664) = a1 + 7656;
  }
  return result;
}
