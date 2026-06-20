__int64 __fastcall _cam_req_mgr_disconnect_req_on_sync_link(__int64 result, __int64 a2)
{
  _DWORD *v3; // x20
  __int64 v4; // x25
  __int64 v5; // x26
  int *v6; // x23
  int *v7; // x24
  int *v8; // x8
  int v9; // w10
  int v10; // w9
  int v11; // w9
  unsigned int v12; // w24

  if ( *(int *)(a2 + 36) >= 1 )
  {
    v3 = (_DWORD *)result;
    v4 = 0;
    v5 = a2 + 40;
    while ( v4 != 3 )
    {
      result = cam_get_link_priv(*(unsigned int *)(v5 + 4 * v4), a2);
      if ( result )
      {
        v6 = *(int **)(result + 48);
        v7 = (int *)result;
        result = _cam_req_mgr_find_slot_for_req(v6, *(_QWORD *)(a2 + 16));
        if ( (result & 0x80000000) == 0 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          {
            v11 = *v7;
            v12 = result;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "__cam_req_mgr_disconnect_req_on_sync_link",
              871,
              "Req: %llu on link: 0x%x flushed, update sync_link: 0x%x at slot: %d",
              *(_QWORD *)(a2 + 16),
              *v3,
              v11,
              result);
            result = v12;
            if ( v12 > 0x30 )
              break;
          }
          else if ( (unsigned int)result > 0x30 )
          {
            break;
          }
          v8 = &v6[18 * (unsigned int)result];
          if ( v8[8] == 1 )
          {
            v8[8] = 0;
            v9 = v8[12];
            v8[11] = 0;
            v10 = *v3;
            if ( v9 == *v3 )
            {
              v8[12] = 0;
              v10 = *v3;
            }
            if ( v8[13] == v10 )
            {
              v8[13] = 0;
              v10 = *v3;
            }
            if ( v8[14] == v10 )
              v8[14] = 0;
          }
        }
      }
      if ( ++v4 >= *(int *)(a2 + 36) )
        return result;
    }
    __break(0x5512u);
  }
  return result;
}
