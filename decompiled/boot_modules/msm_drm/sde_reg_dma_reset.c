__int64 __fastcall sde_reg_dma_reset(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  unsigned int v8; // w1
  unsigned int v9; // w2
  char *v10; // x20
  __int64 v11; // x8
  char *v12; // x20
  __int64 v13; // t1
  int v14; // w4
  __int64 v15; // x19
  unsigned int (__fastcall *v16)(_QWORD); // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_DWORD *)(a1 + 1784);
  if ( v8 < 2 )
  {
    v10 = (char *)&reg_dma + 176 * v8;
    v9 = 0;
    v13 = *((_QWORD *)v10 + 3);
    v12 = v10 + 24;
    v11 = v13;
    if ( v12 && v11 )
    {
      if ( *((_QWORD *)v12 + 5) )
      {
        if ( a1 )
        {
          v14 = *(_DWORD *)(a1 + 64);
          v15 = a1;
        }
        else
        {
          v15 = 0;
          v14 = 255;
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "sde_reg_dma_reset", 105, -1, v14, 4369, -1059143953, a8, vars0);
        v16 = *((unsigned int (__fastcall **)(_QWORD))v12 + 5);
        if ( *((_DWORD *)v16 - 1) != 1800103338 )
          __break(0x8228u);
        return v16(v15);
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    _drm_err("invalid dpu idx %d\n", v8);
    return 0;
  }
  return v9;
}
