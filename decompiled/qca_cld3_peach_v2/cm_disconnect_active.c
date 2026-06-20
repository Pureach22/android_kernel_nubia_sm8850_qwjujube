__int64 __fastcall cm_disconnect_active(_DWORD *a1, _DWORD *a2)
{
  __int64 v3; // x1
  __int64 req_by_cm_id_fl; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x19
  __int64 result; // x0
  int v12; // w8

  v3 = (unsigned int)*a2;
  a1[22] = v3;
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, v3, "cm_disconnect_active", 415);
  if ( !req_by_cm_id_fl )
  {
    cm_remove_cmd_from_serialization(a1, (unsigned int)*a2);
    return 4;
  }
  v6 = req_by_cm_id_fl;
  v7 = *(_QWORD *)a1;
  if ( !*(_DWORD *)(*(_QWORD *)a1 + 16LL) )
  {
    v12 = *(_DWORD *)(v6 + 32);
    if ( v12 != 16 )
    {
      if ( v12 != 18 )
        goto LABEL_10;
      if ( (mlo_is_link_recfg_in_progress() & 1) == 0 )
      {
        v7 = *(_QWORD *)a1;
LABEL_10:
        result = mlme_cm_rso_stop_req(v7);
        if ( (_DWORD)result != 11 )
          return result;
      }
    }
  }
  v8 = _qdf_mem_malloc(0x18u, "cm_disconnect_active", 439);
  if ( !v8 )
    return 2;
  *(_DWORD *)v8 = *a2;
  *(_BYTE *)(v8 + 4) = *(_BYTE *)(*(_QWORD *)a1 + 168LL);
  *(_DWORD *)(v8 + 8) = *(_DWORD *)(v6 + 32);
  *(_DWORD *)(v8 + 12) = *(_DWORD *)(v6 + 36);
  *(_BYTE *)(v8 + 22) = *(_BYTE *)(v6 + 46);
  v9 = *(_QWORD *)a1;
  v10 = v8;
  cm_disconnect_continue_after_rso_stop(v9, v8);
  _qdf_mem_free(v10);
  return 11;
}
