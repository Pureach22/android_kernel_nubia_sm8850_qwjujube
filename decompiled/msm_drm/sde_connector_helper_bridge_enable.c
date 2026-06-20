__int64 __fastcall sde_connector_helper_bridge_enable(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x21
  _QWORD *v4; // x8
  _QWORD *v5; // x20
  __int64 v6; // x22
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x19
  __int64 v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  void *v12; // x0

  if ( !result || !*(_QWORD *)result || (v1 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v12 = &unk_242658;
LABEL_23:
    printk(v12, "sde_connector_get_kms");
    return printk(&unk_234896, "sde_connector_helper_bridge_enable");
  }
  v2 = *(_QWORD *)(v1 + 8);
  if ( !v2 )
  {
    v12 = &unk_234896;
    goto LABEL_23;
  }
  if ( *(_DWORD *)(result + 2736) == 16 )
  {
    v3 = result + 4096;
    v4 = (_QWORD *)(result + 2760);
    if ( *(_BYTE *)(result + 5128) == 1 )
      v4 = (_QWORD *)*v4;
    v5 = (_QWORD *)*v4;
    if ( *v4 )
    {
      if ( !*(_DWORD *)(v5[33] + 1476LL) )
      {
        v6 = result;
        sde_encoder_wait_for_event(*(_QWORD *)(result + 2744), 1u);
        result = v6;
      }
      *(_BYTE *)(v3 + 444) = 1;
      v7 = *(_QWORD *)(v2 + 152);
      if ( !v7 || (*(_BYTE *)(v7 + 20120) & 1) == 0 )
      {
        v8 = *(_QWORD *)(result + 4360);
        if ( v8 )
        {
          if ( (*((_BYTE *)v5 + 1217) & 1) == 0 )
          {
            *(_DWORD *)(v8 + 8) = 0;
            *(_DWORD *)(*(_QWORD *)(result + 4360) + 16LL) &= ~2u;
            v9 = *(_QWORD *)(result + 4360);
            mutex_lock(v9 + 24);
            v10 = *(_QWORD *)(v9 + 120);
            if ( v10 )
            {
              v11 = *(void (__fastcall **)(_QWORD))(v10 + 8);
              if ( v11 )
              {
                if ( *((_DWORD *)v11 - 1) != 1345616862 )
                  __break(0x8228u);
                v11(v9);
              }
            }
            return mutex_unlock(v9 + 24);
          }
        }
      }
    }
  }
  return result;
}
