__int64 __fastcall cm_disconnect_active(_DWORD *a1, _DWORD *a2)
{
  __int64 v3; // x1
  __int64 req_by_cm_id_fl; // x0
  __int64 v6; // x21
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x19

  v3 = (unsigned int)*a2;
  a1[22] = v3;
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, v3, "cm_disconnect_active", 415);
  if ( req_by_cm_id_fl )
  {
    v6 = req_by_cm_id_fl;
    if ( *(_DWORD *)(*(_QWORD *)a1 + 16LL)
      || *(_DWORD *)(req_by_cm_id_fl + 32) == 16
      || (result = mlme_cm_rso_stop_req(), (_DWORD)result == 11) )
    {
      v8 = _qdf_mem_malloc(0x18u, "cm_disconnect_active", 439);
      if ( v8 )
      {
        *(_DWORD *)v8 = *a2;
        *(_BYTE *)(v8 + 4) = *(_BYTE *)(*(_QWORD *)a1 + 104LL);
        *(_DWORD *)(v8 + 8) = *(_DWORD *)(v6 + 32);
        *(_DWORD *)(v8 + 12) = *(_DWORD *)(v6 + 36);
        *(_BYTE *)(v8 + 22) = *(_BYTE *)(v6 + 46);
        v9 = *(_QWORD *)a1;
        v10 = v8;
        cm_disconnect_continue_after_rso_stop(v9, v8);
        _qdf_mem_free(v10);
        return 11;
      }
      else
      {
        return 2;
      }
    }
  }
  else
  {
    cm_remove_cmd_from_serialization(a1, (unsigned int)*a2);
    return 4;
  }
  return result;
}
