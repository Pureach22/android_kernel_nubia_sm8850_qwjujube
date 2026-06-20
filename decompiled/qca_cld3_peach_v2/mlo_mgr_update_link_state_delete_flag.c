__int64 __fastcall mlo_mgr_update_link_state_delete_flag(
        __int64 a1,
        unsigned __int8 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v11; // x8
  const char *v13; // x5
  unsigned __int64 v20; // x10
  unsigned __int64 v23; // x11

  if ( !a1 || a2 > 0xEu )
    goto LABEL_13;
  v11 = *(unsigned __int8 **)(a1 + 3880);
  if ( v11[6] == a2 )
    goto LABEL_6;
  if ( v11[54] == a2 )
  {
    v11 += 48;
LABEL_6:
    if ( v11 )
      goto LABEL_7;
    goto LABEL_13;
  }
  if ( v11[102] == a2 )
  {
    v11 += 96;
    if ( v11 )
    {
LABEL_7:
      if ( (a3 & 1) != 0 )
      {
        _X9 = (unsigned __int64 *)(v11 + 16);
        __asm { PRFM            #0x11, [X9] }
        do
          v20 = __ldxr(_X9);
        while ( __stxr(v20 | 1, _X9) );
      }
      else
      {
        _X9 = (unsigned __int64 *)(v11 + 16);
        __asm { PRFM            #0x11, [X9] }
        do
          v23 = __ldxr(_X9);
        while ( __stxr(v23 & 0xFFFFFFFFFFFFFFFELL, _X9) );
      }
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: link %d updated link state 0x%x for %s",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "mlo_mgr_update_link_state_delete_flag");
      return 1;
    }
  }
LABEL_13:
  if ( (a3 & 1) != 0 )
    v13 = "delete";
  else
    v13 = "clear";
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: no found link info for id %d for %s",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "mlo_mgr_update_link_state_delete_flag",
    a2,
    v13);
  return 0;
}
