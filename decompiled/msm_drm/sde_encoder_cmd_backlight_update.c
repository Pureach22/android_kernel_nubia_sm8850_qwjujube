__int64 __fastcall sde_encoder_cmd_backlight_update(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 result; // x0
  void *v9; // x0
  void *v10; // x0

  if ( a1 == 1184 || (v1 = a1 - 856, !*(_QWORD *)(a1 - 856)) )
  {
    v9 = &unk_268E21;
    return printk(v9, "sde_encoder_cmd_backlight_update");
  }
  v2 = *(_QWORD *)(a1 - 1184);
  if ( !v2 )
  {
    v10 = &unk_26FCAB;
    goto LABEL_18;
  }
  v3 = *(_QWORD *)(v2 + 56);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v10 = &unk_234896;
LABEL_18:
    printk(v10, "sde_encoder_get_kms");
    v9 = &unk_26C6E1;
    return printk(v9, "sde_encoder_cmd_backlight_update");
  }
  v5 = *(_QWORD *)(v4 + 6384);
  if ( !v5 )
    goto LABEL_12;
  mutex_lock(v5);
  v6 = *(_QWORD *)(v4 + 6384);
  if ( !v6 )
    goto LABEL_12;
  v7 = *(__int64 (__fastcall **)(_QWORD))(v6 + 88);
  if ( !v7 )
    goto LABEL_12;
  if ( *((_DWORD *)v7 - 1) != 1370937740 )
    __break(0x8228u);
  if ( (v7(v4) & 1) != 0 )
LABEL_12:
    sde_connector_trigger_cmd_backlight_update(*(_QWORD *)(*(_QWORD *)v1 + 8LL));
  result = *(_QWORD *)(v4 + 6384);
  if ( result )
    return mutex_unlock(result);
  return result;
}
