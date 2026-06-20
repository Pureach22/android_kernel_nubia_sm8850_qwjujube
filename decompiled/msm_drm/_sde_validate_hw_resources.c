__int64 __fastcall sde_validate_hw_resources(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // w20
  int v7; // w9
  unsigned __int64 v8; // x19
  _QWORD *v9; // x21
  char v13; // [xsp+0h] [xbp-20h]

  v6 = *(_DWORD *)(a1 + 2192);
  if ( !v6 )
    goto LABEL_18;
  v7 = *(unsigned __int8 *)(a2 + 6921);
  if ( v7 == 1 )
    v6 = *(_DWORD *)(a2 + 7084);
  if ( !v6 || v6 > 8 )
  {
LABEL_18:
    printk(&unk_2429AB, "_sde_validate_hw_resources");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "_sde_validate_hw_resources",
      3046,
      -1,
      *(_DWORD *)(a1 + 112),
      v6,
      60333,
      -1059143953,
      v13);
    return 4294967274LL;
  }
  if ( v6 >= 1 )
  {
    v8 = 0;
    v9 = (_QWORD *)(a1 + 2224);
    do
    {
      if ( (v7 & 1) == 0 && (*(_BYTE *)(a2 + 6922) & 1) == 0 )
      {
        if ( v8 >= 8 )
        {
          __break(0x5512u);
          return sde_crtc_check_dest_scaler_validate_ds(a1, a2, a3, a4, a5, a6);
        }
        if ( !*(v9 - 3) || !*(v9 - 2) || !*v9 )
        {
          printk(&unk_25A927, "_sde_validate_hw_resources");
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_validate_hw_resources",
            3066,
            -1,
            *(_DWORD *)(a1 + 112),
            *(_DWORD *)(a1 + 2192),
            v8,
            *(v9 - 3),
            *(v9 - 2));
          return 4294967274LL;
        }
      }
      ++v8;
      v9 += 6;
    }
    while ( v6 != v8 );
  }
  return 0;
}
