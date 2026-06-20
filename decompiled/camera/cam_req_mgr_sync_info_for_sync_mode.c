__int64 __fastcall cam_req_mgr_sync_info_for_sync_mode(__int64 slot_for_req, __int64 a2, __int64 a3, int a4)
{
  int v4; // w26
  __int64 v5; // x21
  __int64 v6; // x23
  __int64 v7; // x28
  __int64 v8; // x19
  __int64 v9; // x24
  __int64 v10; // x8
  unsigned int v11; // w25
  const char *v12; // x27
  __int64 v13; // x22
  __int64 v14; // x26
  __int64 v15; // x20
  char v16; // w23
  int v17; // w21
  __int64 v18; // x19
  unsigned int v19; // w27
  __int64 v20; // x10
  __int64 v21; // x22
  char v22; // w8
  int v23; // w9
  __int64 v24; // x20
  __int64 v25; // x19
  __int64 v26; // x9
  int v27; // w8
  __int64 v28; // x0
  unsigned int v30; // [xsp+8h] [xbp-28h]
  __int64 v33; // [xsp+18h] [xbp-18h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  if ( *(int *)(slot_for_req + 33248) < 1 )
  {
    return 0;
  }
  else
  {
    v4 = a4;
    v5 = slot_for_req;
    v6 = a2;
    v7 = 0;
    v8 = 0;
    v9 = slot_for_req + 33224;
    v30 = 0;
    v33 = slot_for_req;
    while ( v7 != 3 )
    {
      mutex_lock(*(_QWORD *)(v9 + 8 * v7) + 33056LL);
      slot_for_req = _cam_req_mgr_find_slot_for_req(*(_QWORD *)(*(_QWORD *)(v9 + 8 * v7) + 48LL), *(_QWORD *)(v6 + 8));
      if ( (slot_for_req & 0x80000000) != 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_sync_info_for_sync_mode",
          3374,
          "Req_id %lld not found in in_q for dev %s on link 0x%x",
          *(_QWORD *)(v6 + 8),
          (const char *)(*(_QWORD *)(v5 + 40) + 320 * v7 + 28),
          **(_DWORD **)(v9 + 8 * v7));
        v27 = -57;
LABEL_49:
        v30 = v27;
        mutex_unlock(*(_QWORD *)(v9 + 8 * v7) + 33056LL);
        return v30;
      }
      v10 = *(unsigned int *)(v5 + 4);
      v11 = slot_for_req;
      v35 = v8;
      if ( (int)v10 < 1 )
      {
LABEL_11:
        v12 = "Invalid dev_hdl";
      }
      else
      {
        v12 = (const char *)(*(_QWORD *)(v5 + 40) + 28LL);
        while ( *((_DWORD *)v12 - 7) != *(_DWORD *)(v6 + 4) )
        {
          --v10;
          v12 += 320;
          if ( !v10 )
            goto LABEL_11;
        }
      }
      v13 = *(_QWORD *)(v9 + 8 * v7);
      if ( *(int *)(v13 + 4) < 1 )
      {
        v19 = -22;
      }
      else
      {
        v14 = 0;
        v15 = 0;
        v16 = debug_mdl;
        v17 = debug_priority;
        while ( 1 )
        {
          v18 = *(_QWORD *)(v13 + 40);
          if ( (v16 & 0x10) != 0 && !v17 )
          {
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v16 & 0x10,
              4,
              "__cam_req_mgr_name_to_dev_handle",
              257,
              "dev name %s, iterate dev name %s",
              v12,
              (const char *)(v18 + v14 + 28));
            v16 = debug_mdl;
            v17 = debug_priority;
          }
          slot_for_req = strcmp(v12, (const char *)(v18 + v14 + 28));
          if ( !(_DWORD)slot_for_req )
            break;
          ++v15;
          v14 += 320;
          if ( v15 >= *(int *)(v13 + 4) )
          {
            v19 = -22;
            goto LABEL_22;
          }
        }
        v19 = *(_DWORD *)(v18 + v14);
LABEL_22:
        v6 = a2;
        v5 = v33;
        v4 = a4;
      }
      v20 = *(_QWORD *)(v9 + 8 * v7);
      if ( *(int *)(v20 + 4) < 1 )
      {
LABEL_30:
        v8 = v35;
        if ( !v35 )
          goto LABEL_45;
      }
      else
      {
        v21 = 0;
        v22 = debug_mdl;
        v23 = debug_priority;
        v24 = 0;
        while ( 1 )
        {
          v25 = *(_QWORD *)(v20 + 40);
          if ( (v22 & 0x10) != 0 && !v23 )
          {
            slot_for_req = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                             3,
                             v22 & 0x10,
                             4,
                             "cam_req_mgr_sync_info_for_sync_mode",
                             3389,
                             "Req %lld device hdl %x : sync link dev hdl %x",
                             *(_QWORD *)(v6 + 8),
                             *(_DWORD *)(v25 + v21),
                             v19);
            v22 = debug_mdl;
            v23 = debug_priority;
          }
          if ( *(_DWORD *)(v25 + v21) == v19 )
            break;
          v20 = *(_QWORD *)(v9 + 8 * v7);
          ++v24;
          v21 += 320;
          if ( v24 >= *(int *)(v20 + 4) )
            goto LABEL_30;
        }
        v8 = *(_QWORD *)(v25 + v21 + 16);
        if ( !v8 )
        {
LABEL_45:
          if ( (unsigned int)__ratelimit(
                               &cam_req_mgr_sync_info_for_sync_mode__rs,
                               "cam_req_mgr_sync_info_for_sync_mode") )
            v28 = 3;
          else
            v28 = 2;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            v28,
            16,
            1,
            "cam_req_mgr_sync_info_for_sync_mode",
            3398,
            "Sync link dev hdl %x not found",
            v19);
          v27 = -22;
          goto LABEL_49;
        }
      }
      if ( v11 > 0x30 )
        break;
      if ( v4 == 2 )
      {
        v26 = *(unsigned int *)(v8 + 48LL * v11 + 64);
        *(_BYTE *)(v8 + 48LL * v11 + 84) = *(_BYTE *)(a3 + 44);
        if ( (_DWORD)v26 == 4 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            2,
            "cam_req_mgr_sync_info_for_sync_mode",
            3418,
            "Sync link 0x%x slot:%d already has %d devices, can't add more",
            **(_DWORD **)(v9 + 8 * v7),
            v11,
            4);
        }
        else
        {
          *(_DWORD *)(v8 + 48LL * v11 + 64) = v26 + 1;
          if ( (unsigned int)v26 > 3 )
            break;
          *(_DWORD *)(v8 + 48LL * v11 + 40 + 4 * v26 + 28) = v19;
        }
      }
      else if ( v4 == 1 )
      {
        *(_DWORD *)(v8 + 48LL * v11 + 60) = *(_DWORD *)(a3 + 20);
      }
      else if ( v4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_sync_info_for_sync_mode",
          3423,
          "Invalid Sync type:%u",
          v4);
        v30 = -22;
      }
      else
      {
        *(_DWORD *)(v8 + 48LL * v11 + 56) = *(_DWORD *)(a3 + 16);
      }
      slot_for_req = mutex_unlock(*(_QWORD *)(v9 + 8 * v7++) + 33056LL);
      if ( v7 >= *(int *)(v5 + 33248) )
        return v30;
    }
    __break(0x5512u);
    return _cam_req_mgr_find_slot_for_req(slot_for_req, a2);
  }
}
