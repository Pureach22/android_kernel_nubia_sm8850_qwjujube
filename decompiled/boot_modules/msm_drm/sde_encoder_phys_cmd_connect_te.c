__int64 *__fastcall sde_encoder_phys_cmd_connect_te(__int64 *result, char a2)
{
  __int64 *v2; // x20
  unsigned int disp_op; // w0
  _DWORD *v5; // x9
  __int64 v6; // x0
  int v7; // w7
  __int64 v8; // x8
  void (*v9)(void); // x8
  int v10; // w4
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !result )
    return result;
  v2 = result;
  if ( !result[62] || !result[53] )
    return result;
  disp_op = sde_encoder_get_disp_op(*result);
  if ( *((_BYTE *)v2 + 2288) != 1 )
  {
    if ( disp_op <= 2 )
      goto LABEL_11;
LABEL_20:
    __break(0x5512u);
    JUMPOUT(0xFCDE4);
  }
  if ( disp_op >= 3 )
    goto LABEL_20;
  v5 = *(_DWORD **)(v2[53] + 8LL * disp_op + 536);
  if ( !v5 )
  {
LABEL_11:
    v8 = disp_op;
    result = (__int64 *)v2[62];
    v9 = (void (*)(void))result[v8 + 17];
    if ( !v9 )
      return result;
    if ( *((_DWORD *)v9 - 1) != 683511807 )
      __break(0x8228u);
    v9();
    goto LABEL_15;
  }
  v6 = v2[53];
  if ( *(v5 - 1) != 467537577 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, _QWORD))v5)(v6, a2 & 1);
LABEL_15:
  if ( *v2 )
    v10 = *(_DWORD *)(*v2 + 24);
  else
    v10 = -1;
  return (__int64 *)sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "sde_encoder_phys_cmd_connect_te",
                      1757,
                      -1,
                      v10,
                      a2 & 1,
                      -1059143953,
                      v7,
                      vars0);
}
