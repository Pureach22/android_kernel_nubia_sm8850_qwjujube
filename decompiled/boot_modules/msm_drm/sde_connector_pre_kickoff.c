__int64 __fastcall sde_connector_pre_kickoff(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned int updated; // w0
  int v6; // w6
  int v7; // w7
  unsigned int v8; // w21
  __int64 result; // x0
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x0
  int v12; // w4
  __int64 (__fastcall *v13)(__int64, __int64, __int64 *); // x8
  __int64 v14; // x1
  void *v15; // x0
  char v16; // [xsp+0h] [xbp-20h]
  __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  if ( !a1 )
  {
    v15 = &unk_215A31;
LABEL_32:
    printk(v15, "sde_connector_pre_kickoff");
    result = 4294967274LL;
    goto LABEL_33;
  }
  v1 = *(__int64 **)(a1 + 2760);
  if ( !v1 )
  {
    v15 = &unk_249B41;
    goto LABEL_32;
  }
  v3 = *(_QWORD *)(a1 + 2512);
  if ( *(_DWORD *)(a1 + 2736) == 16 )
  {
    if ( !*(_BYTE *)(a1 + 5128) )
      v1 = (__int64 *)(a1 + 2760);
    v4 = *v1;
    if ( !*v1 )
      goto LABEL_29;
    *(_BYTE *)(v4 + 1616) = 1;
  }
  else
  {
    v4 = 0;
  }
  updated = sde_connector_update_dirty_properties(a1);
  if ( updated )
  {
    v8 = updated;
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_connector_pre_kickoff",
      1588,
      -1,
      *(_DWORD *)(a1 + 64),
      60333,
      -1059143953,
      v7,
      v16);
    result = v8;
    if ( !v4 )
      goto LABEL_33;
    goto LABEL_27;
  }
  if ( *(_BYTE *)(a1 + 4713) == 1 && (unsigned int)sde_connector_check_update_vhm_cmd(a1) )
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_connector_pre_kickoff",
      1596,
      -1,
      *(_DWORD *)(a1 + 64),
      60333,
      -1059143953,
      v7,
      v16);
  if ( v3 != -3232 && (*(_BYTE *)(v3 + 3240) & 8) != 0 )
  {
    v10 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 3240);
    v11 = *(_QWORD *)(a1 + 2760);
    if ( *((_DWORD *)v10 - 1) != -1783020508 )
      __break(0x8228u);
    if ( (v10(v11, 40) & 1) != 0
      && (*(_BYTE *)(a1 + 4713) & 1) == 0
      && (unsigned int)sde_connector_update_cmd(a1, 0x10000000000LL, 1) )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "sde_connector_pre_kickoff",
        1605,
        -1,
        *(_DWORD *)(a1 + 64),
        60333,
        -1059143953,
        v7,
        v16);
    }
  }
  if ( !*(_QWORD *)(a1 + 3000) )
  {
LABEL_29:
    result = 0;
    goto LABEL_33;
  }
  v12 = *(_DWORD *)(a1 + 64);
  v17 = v3 + 2048;
  v18 = v3 + 3112;
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_connector_pre_kickoff", 1614, 4, v12, -1059143953, v6, v7, v16);
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(a1 + 3000);
  v14 = *(_QWORD *)(a1 + 2760);
  if ( *((_DWORD *)v13 - 1) != -342324774 )
    __break(0x8228u);
  result = v13(a1, v14, &v17);
  if ( v4 )
  {
LABEL_27:
    if ( *(_DWORD *)(a1 + 2736) == 16 )
      *(_BYTE *)(v4 + 1616) = 0;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
