__int64 __fastcall drv_cmd_country(__int64 *a1, __int64 a2, const char *a3)
{
  __int64 v6; // x8
  __int64 result; // x0
  size_t v8; // x0
  _BYTE *v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // w9
  int v19; // t1
  _BYTE *v20; // x21
  __int64 v21; // x1
  unsigned int v22; // w19
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  _BOOL4 v24; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 24);
  v23 = 0;
  result = _osif_psoc_sync_op_start(*(_QWORD *)(v6 + 488), &v23, "drv_cmd_country");
  if ( !(_DWORD)result )
  {
    v8 = strlen(a3);
    v9 = (_BYTE *)strnchr(a3, v8, 32);
    if ( !v9 || *v9 != 32 )
      goto LABEL_10;
    do
    {
      v19 = (unsigned __int8)*++v9;
      v18 = v19;
    }
    while ( v19 == 32 );
    if ( v18 && v9[1] )
    {
      v20 = v9;
      if ( v18 == 80 && (v9[1] & 0xFE) == 0x30 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: drv_cmd_country country_code as opm %s .",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "__drv_cmd_country",
          v9);
        v21 = *a1;
        v24 = v20[1] != 48;
        hdd_set_power_config(a2, v21, &v24);
        v22 = 0;
      }
      else
      {
        v22 = hdd_reg_set_country(a2, v9);
      }
    }
    else
    {
LABEL_10:
      v22 = -22;
    }
    _osif_psoc_sync_op_stop(v23, "drv_cmd_country");
    result = v22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
