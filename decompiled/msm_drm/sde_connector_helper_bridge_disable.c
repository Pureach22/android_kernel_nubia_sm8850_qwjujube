__int64 __fastcall sde_connector_helper_bridge_disable(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x22
  _QWORD *v4; // x8
  _QWORD *v5; // x8
  char v6; // w20
  __int64 v7; // x8
  __int64 v8; // x8
  char v9; // w9
  __int64 v10; // x20
  __int64 v11; // x8
  void (__fastcall *v12)(_QWORD); // x8
  char v13; // w8
  void *v14; // x0
  int v15; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !result || (v1 = result, !*(_QWORD *)result) || (v2 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v14 = &unk_242658;
LABEL_31:
    printk(v14, "sde_connector_get_kms");
    return printk(&unk_234896, "sde_connector_helper_bridge_disable");
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v14 = &unk_234896;
    goto LABEL_31;
  }
  if ( *(_DWORD *)(result + 2736) != 16 )
    goto LABEL_11;
  v4 = (_QWORD *)(result + 2760);
  if ( *(_BYTE *)(result + 5128) == 1 )
    v4 = (_QWORD *)*v4;
  v5 = (_QWORD *)*v4;
  if ( v5 )
  {
    if ( (*((_BYTE *)v5 + 1217) & 1) != 0 )
    {
      v6 = 1;
LABEL_14:
      result = sde_connector_schedule_status_work(v1, 0);
      v7 = *(_QWORD *)(v3 + 152);
      if ( !v7 || (*(_BYTE *)(v7 + 20120) & 1) == 0 )
      {
        v8 = *(_QWORD *)(v1 + 4360);
        v9 = v8 ? v6 : 1;
        if ( (v9 & 1) == 0 )
        {
          *(_DWORD *)(v8 + 8) = 4;
          *(_DWORD *)(*(_QWORD *)(v1 + 4360) + 16LL) |= 2u;
          v10 = *(_QWORD *)(v1 + 4360);
          mutex_lock(v10 + 24);
          v11 = *(_QWORD *)(v10 + 120);
          if ( v11 )
          {
            v12 = *(void (__fastcall **)(_QWORD))(v11 + 8);
            if ( v12 )
            {
              if ( *((_DWORD *)v12 - 1) != 1345616862 )
                __break(0x8228u);
              v12(v10);
            }
          }
          result = mutex_unlock(v10 + 24);
        }
      }
      v13 = *(_BYTE *)(v1 + 4713);
      *(_BYTE *)(v1 + 4540) = 0;
      if ( (v13 & 1) != 0 || *(_BYTE *)(v1 + 4715) == 1 )
        *(_DWORD *)(v1 + 4676) = 0;
      return result;
    }
LABEL_11:
    if ( (unsigned int)sde_connector_update_dirty_properties(result) )
    {
      printk(&unk_235768, "sde_connector_helper_bridge_disable");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_connector_helper_bridge_disable",
        1846,
        -1,
        *(_DWORD *)(v1 + 64),
        60333,
        -1059143953,
        v15,
        vars0);
    }
    v6 = 0;
    goto LABEL_14;
  }
  return result;
}
