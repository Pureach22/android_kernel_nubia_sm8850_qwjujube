__int64 *__fastcall sde_encoder_phys_vid_esync_emsync_irq(
        __int64 *result,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x20
  __int64 v11; // x0
  int v12; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v8 = (void (__fastcall *)(__int64, __int64))result[47];
    v9 = (__int64)result;
    if ( v8 )
    {
      v11 = *result;
      if ( *((_DWORD *)v8 - 1) != 468003652 )
        __break(0x8228u);
      v8(v11, v9);
    }
    if ( *(_QWORD *)v9 )
      v12 = *(_DWORD *)(*(_QWORD *)v9 + 24LL);
    else
      v12 = -1;
    return (__int64 *)sde_evtlog_log(
                        sde_dbg_base_evtlog,
                        "sde_encoder_phys_vid_esync_emsync_irq",
                        1335,
                        2,
                        v12,
                        a2,
                        -1059143953,
                        a8,
                        vars0);
  }
  return result;
}
