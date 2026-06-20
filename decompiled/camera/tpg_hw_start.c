__int64 __fastcall tpg_hw_start(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  __int64 v4; // x20
  int v5; // w21
  _DWORD *v6; // x8
  void (__fastcall *v7)(__int64, __int64, __int64); // x8
  _DWORD *v9; // x8
  char *v10; // x24
  char *v11; // x21
  char *v12; // x20
  char **v13; // x8
  __int64 v14; // x9
  unsigned int v15; // w20
  __int64 v16; // x2
  char *v17; // x1

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 || !*(_QWORD *)(v1 + 16) )
    return 4294967274LL;
  mutex_lock(a1 + 48);
  v3 = *(_QWORD *)(a1 + 32);
  if ( (unsigned int)(*(_DWORD *)v3 - 268435458) < 4 )
  {
    v4 = *(_QWORD *)(a1 + 192);
    v5 = *(_DWORD *)(a1 + 168);
    v6 = *(_DWORD **)(*(_QWORD *)(v3 + 16) + 8LL);
    if ( v6 )
    {
      if ( *(v6 - 1) != 731976422 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v6)(a1, 0);
    }
    if ( v5 )
    {
      v7 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 16LL) + 64LL);
      if ( *((_DWORD *)v7 - 1) != 1918520948 )
        __break(0x8228u);
      v7(a1, a1 + 144, v4);
    }
    else
    {
      v10 = *(char **)(a1 + 208);
      if ( v10 != (char *)(a1 + 208) )
      {
        v11 = nullptr;
        do
        {
          v12 = v10;
          v10 = *(char **)v10;
          tpg_hw_apply_settings_to_hw_locked(a1, v12 - 104);
          v13 = *((char ***)v12 + 1);
          if ( *v13 == v12 && (v14 = *(_QWORD *)v12, *(char **)(*(_QWORD *)v12 + 8LL) == v12) )
          {
            *(_QWORD *)(v14 + 8) = v13;
            *v13 = (char *)v14;
          }
          else
          {
            _list_del_entry_valid_or_report(v12);
          }
          *(_QWORD *)v12 = 0xDEAD000000000100LL;
          *((_QWORD *)v12 + 1) = 0xDEAD000000000122LL;
          --*(_DWORD *)(a1 + 244);
          if ( v11 )
            tpg_hw_release_vc_slots_locked(a1, v11);
          v11 = v12 - 104;
        }
        while ( v10 != (char *)(a1 + 208) );
        if ( v12 != &byte_68 )
        {
          v16 = a1 + 224;
          v17 = *(char **)(a1 + 232);
          if ( v12 == (char *)(a1 + 224) || v17 == v12 || *(_QWORD *)v17 != v16 )
          {
            _list_add_valid_or_report(v12);
          }
          else
          {
            *(_QWORD *)(a1 + 232) = v12;
            *(_QWORD *)v12 = v16;
            *((_QWORD *)v12 + 1) = v17;
            *(_QWORD *)v17 = v12;
          }
          v15 = 0;
          ++*(_DWORD *)(a1 + 240);
          goto LABEL_37;
        }
      }
    }
    goto LABEL_36;
  }
  if ( (unsigned int)(*(_DWORD *)v3 - 0x10000000) <= 1 )
  {
    v9 = *(_DWORD **)(*(_QWORD *)(v3 + 16) + 8LL);
    if ( v9 )
    {
      if ( *(v9 - 1) != 731976422 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v9)(a1, 0);
    }
LABEL_36:
    v15 = 0;
    goto LABEL_37;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x200000000LL,
    1,
    "tpg_hw_start",
    783,
    "TPG[%d] Unsupported HW Version",
    *(_DWORD *)a1);
  v15 = -22;
LABEL_37:
  mutex_unlock(a1 + 48);
  return v15;
}
