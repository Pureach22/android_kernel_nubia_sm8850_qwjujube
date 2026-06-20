__int64 __fastcall sde_encoder_smooth_dimming_in_progress(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  __int64 v9; // x19
  char v11; // w8
  char v13; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    LOBYTE(v8) = 0;
    return v8 & 1;
  }
  v8 = *(_QWORD *)(a1 + 328);
  if ( !v8 )
    return v8 & 1;
  v9 = *(_QWORD *)(v8 + 8);
  if ( v9
    && (sde_evtlog_log(
          sde_dbg_base_evtlog,
          "sde_encoder_smooth_dimming_in_progress",
          550,
          -1,
          *(unsigned __int8 *)(a1 + 749),
          *(unsigned __int8 *)(v9 + 4572),
          -1059143953,
          a8,
          v13),
        *(_BYTE *)(a1 + 749) == 1) )
  {
    v11 = *(_BYTE *)(v9 + 4572);
  }
  else
  {
    v11 = 0;
  }
  return v11 & 1;
}
