__int64 __fastcall tpg_hw_stop(unsigned int *a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  _DWORD *v4; // x8
  unsigned int v5; // w0
  __int64 v6; // x6
  const char *v7; // x5
  __int64 v8; // x4
  unsigned int v9; // w20
  __int64 v11; // x0
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 v14; // x0
  unsigned int *v15; // x9
  unsigned int *v16; // x1
  unsigned int *v17; // x26
  unsigned int **v18; // x8
  unsigned int *v19; // x10
  unsigned int *v20; // x10
  unsigned int *v21; // x9
  unsigned int *v22; // x1
  unsigned int *v23; // x26
  unsigned int **v24; // x8
  unsigned int *v25; // x10
  unsigned int *v26; // x10
  unsigned int *v27; // [xsp+0h] [xbp-10h]
  unsigned int *v28; // [xsp+0h] [xbp-10h]
  unsigned int *v29; // [xsp+8h] [xbp-8h]
  unsigned int *v30; // [xsp+8h] [xbp-8h]

  if ( !a1 )
    return 4294967274LL;
  v1 = *((_QWORD *)a1 + 4);
  if ( !v1 || !*(_QWORD *)(v1 + 16) )
    return 4294967274LL;
  mutex_lock(a1 + 12);
  v3 = *((_QWORD *)a1 + 4);
  if ( (unsigned int)(*(_DWORD *)v3 - 0x10000000) > 5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_stop",
      825,
      "TPG[%d] Unsupported HW Version",
      *a1);
    v9 = -22;
  }
  else
  {
    v4 = *(_DWORD **)(*(_QWORD *)(v3 + 16) + 16LL);
    if ( !v4 )
      goto LABEL_13;
    if ( *(v4 - 1) != 731976422 )
      __break(0x8228u);
    v5 = ((__int64 (__fastcall *)(unsigned int *, _QWORD))v4)(a1, 0);
    if ( v5 )
    {
      v6 = *a1;
      v7 = "TPG[%d] hw stop failed %d";
      v8 = 809;
      v9 = v5;
    }
    else
    {
LABEL_13:
      v11 = *((_QWORD *)a1 + 5);
      if ( v11 )
      {
        v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
                v11,
                0xFFFFFFFFLL,
                1,
                1);
        if ( v12 )
        {
          v9 = v12;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            0x200000000LL,
            1,
            "tpg_hw_soc_disable",
            376,
            "TPG[%d] Disable platform failed %d",
            *a1);
        }
        else
        {
          v13 = cam_cpas_stop(a1[3]);
          if ( !v13 )
          {
            v14 = raw_spin_lock_irqsave(a1 + 24);
            a1[2] = 0;
            raw_spin_unlock_irqrestore(a1 + 24, v14);
            v15 = *((unsigned int **)a1 + 26);
            if ( v15 != a1 + 52 )
            {
              do
              {
                v16 = v15 - 26;
                v17 = *(unsigned int **)v15;
                if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
                {
                  v27 = v15;
                  v29 = v15 - 26;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x200000000LL,
                    4,
                    "tpg_hw_free_waiting_requests_locked",
                    330,
                    "TPG[%d] freeing waiting_request[%lld] ",
                    *a1,
                    *(_QWORD *)v16);
                  v15 = v27;
                  v16 = v29;
                }
                v18 = *((unsigned int ***)v15 + 1);
                if ( *v18 == v15 && (v19 = *(unsigned int **)v15, *(unsigned int **)(*(_QWORD *)v15 + 8LL) == v15) )
                {
                  *((_QWORD *)v19 + 1) = v18;
                  *v18 = v19;
                }
                else
                {
                  _list_del_entry_valid_or_report(v15);
                  v16 = v20;
                }
                *(_QWORD *)v15 = 0xDEAD000000000100LL;
                *((_QWORD *)v15 + 1) = 0xDEAD000000000122LL;
                --a1[61];
                tpg_hw_release_vc_slots_locked(a1, v16);
                v15 = v17;
              }
              while ( v17 != a1 + 52 );
            }
            v21 = *((unsigned int **)a1 + 28);
            if ( v21 != a1 + 56 )
            {
              do
              {
                v22 = v21 - 26;
                v23 = *(unsigned int **)v21;
                if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
                {
                  v28 = v21;
                  v30 = v21 - 26;
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x200000000LL,
                    4,
                    "tpg_hw_free_active_requests_locked",
                    353,
                    "TPG[%d] freeing active_request[%lld] ",
                    *a1,
                    *(_QWORD *)v22);
                  v21 = v28;
                  v22 = v30;
                }
                v24 = *((unsigned int ***)v21 + 1);
                if ( *v24 == v21 && (v25 = *(unsigned int **)v21, *(unsigned int **)(*(_QWORD *)v21 + 8LL) == v21) )
                {
                  *((_QWORD *)v25 + 1) = v24;
                  *v24 = v25;
                }
                else
                {
                  _list_del_entry_valid_or_report(v21);
                  v22 = v26;
                }
                *(_QWORD *)v21 = 0xDEAD000000000100LL;
                *((_QWORD *)v21 + 1) = 0xDEAD000000000122LL;
                --a1[60];
                tpg_hw_release_vc_slots_locked(a1, v22);
                v21 = v23;
              }
              while ( v23 != a1 + 56 );
            }
            v9 = 0;
            *((_QWORD *)a1 + 32) = -1;
            goto LABEL_21;
          }
          v9 = v13;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x200000000LL,
            1,
            "tpg_hw_soc_disable",
            381,
            "TPG[%d] CPAS stop failed",
            *a1);
        }
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "tpg_hw_soc_disable",
          367,
          "Error Invalid params");
        v9 = -22;
      }
      v6 = *a1;
      v7 = "TPG[%d] hw soc disable failed %d";
      v8 = 816;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_stop",
      v8,
      v7,
      v6);
  }
LABEL_21:
  mutex_unlock(a1 + 12);
  return v9;
}
