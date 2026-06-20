__int64 __fastcall qmp_sdca_dmic_hw_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  _QWORD *v4; // x19
  __int64 v5; // x7
  __int64 v6; // x22
  int v7; // w20
  __int64 v9; // x8
  __int64 result; // x0
  unsigned int v11; // w20
  int v12; // w8
  __int64 v13; // x1
  unsigned int v14; // w21
  __int64 v15; // x8
  unsigned int v16; // w23
  const char *v17; // x3

  v3 = *(_QWORD *)(a3 + 96);
  v4 = *(_QWORD **)(*(_QWORD *)(v3 + 24) + 152LL);
  v5 = v4[2];
  if ( !v5 )
    return 4294967274LL;
  v6 = *(unsigned int *)(a3 + 8);
  if ( (((unsigned __int64)*((int *)v4 + 50) >> v6) & 1) == 0 )
    return 0;
  if ( (unsigned int)v6 >= 3 )
  {
    __break(0x5512u);
    return qmp_sdca_dmic_hw_free();
  }
  else
  {
    v7 = *((unsigned __int8 *)v4 + v6 + 204);
    if ( (_DWORD)v6 == 1 )
      v9 = 23;
    else
      v9 = 22;
    result = stream_agg_add_channel(
               a1,
               *(unsigned int *)(a2 + 284),
               LODWORD(v4[v9]),
               *((unsigned __int8 *)v4 + v6 + 204),
               (_DWORD)v6 == 1,
               *(unsigned __int8 *)(v5 + 64),
               *(_QWORD *)(*(_QWORD *)(v3 + 24) + 152LL));
    if ( (_DWORD)result )
    {
      v16 = result;
      v17 = "SWRM_TX1_CH1";
      switch ( v7 )
      {
        case 0:
          v17 = "ZERO";
          break;
        case 45:
          v17 = "TX_PCM_OUT";
          break;
        case 46:
          break;
        case 47:
          v17 = "SWRM_TX1_CH2";
          break;
        case 48:
          v17 = "SWRM_TX1_CH3";
          break;
        case 49:
          v17 = "SWRM_TX1_CH4";
          break;
        case 50:
          v17 = "SWRM_TX2_CH1";
          break;
        case 51:
          v17 = "SWRM_TX2_CH2";
          break;
        case 52:
          v17 = "SWRM_TX2_CH3";
          break;
        case 53:
          v17 = "SWRM_TX2_CH4";
          break;
        case 54:
          v17 = "SWRM_TX3_CH1";
          break;
        case 55:
          v17 = "SWRM_TX3_CH2";
          break;
        case 56:
          v17 = "SWRM_TX3_CH3";
          break;
        case 57:
          v17 = "SWRM_TX3_CH4";
          break;
        case 58:
          v17 = "TX_PCM_IN";
          break;
        default:
          v17 = "UNDEFINED";
          break;
      }
      dev_err(v4[1], "dai_name:%s, add channel %s failed\n", *(const char **)a3, v17);
      result = v16;
    }
    if ( (_DWORD)v6 == 1 )
      v11 = 2;
    else
      v11 = 1;
    v12 = *((_DWORD *)v4 + 42) + 1;
    *((_DWORD *)v4 + 42) = v12;
    if ( v12 <= 1 )
    {
      v13 = *((unsigned int *)v4 + 76);
      if ( (_DWORD)v13 )
      {
        if ( (unsigned int)regmap_write(*v4, v13, *((unsigned int *)v4 + 77)) )
          dev_err(*(_QWORD *)(v3 + 24), "failed to set QMP usage mode\n");
        v14 = v11 << 22;
        v4[38] = 0;
      }
      else
      {
        v15 = 160;
        if ( (_DWORD)v6 == 1 )
          v15 = 164;
        v14 = v11 << 22;
        regmap_write(*v4, (v11 << 22) | 0x400000A0, *(unsigned int *)((char *)v4 + v15));
      }
      regmap_write(*v4, v14 + 1073742088, 0);
      if ( (unsigned int)wait_for_pde_state(v4, 0, v11) )
        return 4294967274LL;
      else
        return 0;
    }
  }
  return result;
}
