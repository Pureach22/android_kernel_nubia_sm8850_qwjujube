__int64 __fastcall sde_encoder_phys_cmd_config_autorefresh(__int64 a1, int a2)
{
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x24
  __int64 result; // x0
  unsigned int v8; // w22
  int v9; // w24
  int v10; // w4
  int v11; // w4
  int v12; // w10
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x1
  __int64 v15; // x0

  _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(a1 + 496);
  v5 = *(_QWORD *)(a1 + 424);
  v6 = *(_QWORD *)(a1 + 8);
  result = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( !v6 || !*(_QWORD *)(v6 + 2512) || !v4 || !v5 )
    goto LABEL_25;
  v8 = result;
  v9 = a2 != 0;
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)a1 )
      v10 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
    else
      v10 = -1;
    _drm_dev_dbg(
      0,
      0,
      0,
      "enc%d intf%d autorefresh state %d->%d framecount %d\n",
      v10,
      *(_DWORD *)(a1 + 672) - 1,
      *(unsigned __int8 *)(a1 + 2688),
      a2 != 0,
      a2);
  }
  v11 = *(_QWORD *)a1 ? *(_DWORD *)(*(_QWORD *)a1 + 24LL) : -1;
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "_sde_encoder_phys_cmd_config_autorefresh",
             117,
             -1,
             v11,
             *(_DWORD *)(v4 + 32),
             *(_DWORD *)(v5 + 32),
             *(unsigned __int8 *)(a1 + 2688),
             a2 != 0);
  if ( *(unsigned __int8 *)(a1 + 2688) == v9 )
    goto LABEL_25;
  v12 = *(unsigned __int8 *)(a1 + 2288);
  *(_BYTE *)(a1 + 2688) = v9;
  *(_BYTE *)(a1 + 2691) = 0;
  *(_WORD *)(a1 + 2689) = 0;
  *(_DWORD *)(a1 + 2692) = a2;
  if ( v12 == 1 )
  {
    if ( v8 < 3 )
    {
      v13 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 8LL * v8 + 584);
      if ( v13 )
      {
        v14 = a1 + 2688;
        v15 = v5;
        if ( *((_DWORD *)v13 - 1) != 1676198544 )
          __break(0x8228u);
        goto LABEL_24;
      }
LABEL_21:
      v13 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 8LL * v8 + 184);
      if ( !v13 )
      {
LABEL_25:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v14 = a1 + 2688;
      v15 = v4;
      if ( *((_DWORD *)v13 - 1) != 1894309192 )
        __break(0x8228u);
LABEL_24:
      result = v13(v15, v14);
      goto LABEL_25;
    }
  }
  else if ( v8 <= 2 )
  {
    goto LABEL_21;
  }
  __break(0x5512u);
  return sde_encoder_phys_cmd_pingpong_config(result);
}
