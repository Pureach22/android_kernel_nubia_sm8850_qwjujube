__int64 __fastcall sde_encoder_complete_commit(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w4
  _DWORD *v4; // x8
  __int64 result; // x0
  char v6; // [xsp+0h] [xbp-30h]
  _BYTE v7[4]; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v8[4]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h] BYREF
  __int64 v10; // [xsp+18h] [xbp-18h]
  int v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 328);
  v11 = 0;
  v9 = 0;
  v10 = 0;
  v8[0] = 0;
  v7[0] = 0;
  if ( a1 )
  {
    v3 = *(_DWORD *)(a1 + 24);
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    v3 = -1;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_complete_commit",
    5120,
    -1,
    v3,
    *(unsigned __int8 *)(a1 + 4969),
    4369,
    -1059143953,
    v6);
  if ( *(_QWORD *)(a1 + 4960) )
  {
    if ( *(_BYTE *)(a1 + 4969) == 1 )
    {
      v4 = *(_DWORD **)(v2 + 336);
      if ( v4 )
      {
        if ( *(v4 - 1) != -732523917 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64 *, _BYTE *, _BYTE *))v4)(v2, &v9, v8, v7);
        sde_cesta_force_db_update(*(_QWORD *)(a1 + 4960), BYTE3(v10), v11);
        *(_BYTE *)(a1 + 4969) = 0;
      }
    }
  }
  *(_DWORD *)(a1 + 4952) = 0;
  result = sde_encoder_cesta_update(a1, 2u);
  _ReadStatusReg(SP_EL0);
  return result;
}
