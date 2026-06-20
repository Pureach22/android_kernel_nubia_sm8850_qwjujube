__int64 __fastcall cm_cont_connect_for_event(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v6; // x19
  __int64 cm_ctx_fl; // x0
  unsigned int *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 *v17; // x20
  unsigned int v18; // w21
  __int64 v19; // x0
  __int64 v20; // x22
  char v21; // w8
  unsigned int v22; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = a3;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( result )
  {
    v6 = result;
    cm_ctx_fl = cm_get_cm_ctx_fl(result, "cm_cont_connect_for_event", 364);
    if ( cm_ctx_fl )
    {
      v17 = (__int64 *)cm_ctx_fl;
      if ( (unsigned int)cm_sm_deliver_event(v6, a4, 4, &v22) )
      {
        v18 = v22;
        v19 = _qdf_mem_malloc(0xA0u, "cm_connect_handle_event_post_fail", 304);
        if ( v19 )
        {
          *(_DWORD *)(v19 + 4) = v18;
          *(_DWORD *)(v19 + 52) = 16;
          v20 = v19;
          v21 = *(_BYTE *)(*v17 + 104);
          *(_DWORD *)(v19 + 56) = 2;
          *(_BYTE *)v19 = v21;
          cm_fill_bss_info_in_connect_rsp_by_cm_id(v17, v18, v19);
          cm_connect_complete(v17, v20);
          _qdf_mem_free(v20);
        }
      }
    }
    result = wlan_objmgr_vdev_release_ref(v6, 0x4Du, v8, v9, v10, v11, v12, v13, v14, v15, v16);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
