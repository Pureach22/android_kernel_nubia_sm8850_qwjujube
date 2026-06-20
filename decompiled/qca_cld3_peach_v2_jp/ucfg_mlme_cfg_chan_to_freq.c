__int64 __fastcall ucfg_mlme_cfg_chan_to_freq(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x19
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x1
  __int64 v16; // x2
  const char *v17; // x2

  result = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 80));
  if ( result )
  {
    v3 = *(unsigned int *)(result + 3968);
    v4 = *(_QWORD *)(result + 3976);
    v5 = result;
    *(_QWORD *)(result + 3552) = 128;
    v6 = ucfg_mlme_convert_power_cfg_chan_to_freq(a1, v3, v4, result + 3984, result + 3568);
    if ( v6 )
    {
      v15 = *(unsigned int *)(v5 + 4112);
      v16 = *(_QWORD *)(v5 + 4120);
      *(_QWORD *)(v5 + 3560) = v6;
      *(_QWORD *)(v5 + 3696) = 256;
      result = ucfg_mlme_convert_power_cfg_chan_to_freq(a1, v15, v16, v5 + 4128, v5 + 3712);
      if ( (_DWORD)result )
      {
        *(_QWORD *)(v5 + 3704) = (unsigned int)result;
        return result;
      }
      v17 = "%s: mlme cfg power 5 data chan number to freq failed";
    }
    else
    {
      v17 = "%s: mlme cfg power 2_4 data chan number to freq failed";
    }
    return qdf_trace_msg(0x1Fu, 2u, v17, v7, v8, v9, v10, v11, v12, v13, v14, "ucfg_mlme_cfg_chan_to_freq");
  }
  return result;
}
