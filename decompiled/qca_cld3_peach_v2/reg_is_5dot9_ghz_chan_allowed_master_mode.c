__int64 __fastcall reg_is_5dot9_ghz_chan_allowed_master_mode(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_obj; // x0
  char v10; // w19
  const char *v11; // x2

  if ( !a1 )
  {
    v11 = "%s: pdev is NULL";
LABEL_6:
    v10 = 1;
    qdf_trace_msg(0x51u, 1u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "reg_is_5dot9_ghz_chan_allowed_master_mode");
    return v10 & 1;
  }
  psoc_obj = reg_get_psoc_obj(*(_QWORD *)(a1 + 80), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !psoc_obj )
  {
    v11 = "%s: psoc reg component is NULL";
    goto LABEL_6;
  }
  v10 = *(_BYTE *)(psoc_obj + 93235);
  return v10 & 1;
}
