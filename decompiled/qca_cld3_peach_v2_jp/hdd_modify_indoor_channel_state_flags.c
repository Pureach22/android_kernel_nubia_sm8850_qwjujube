__int64 __fastcall hdd_modify_indoor_channel_state_flags(
        __int64 *a1,
        __int64 a2,
        unsigned int *a3,
        __int64 a4,
        __int64 a5,
        char a6)
{
  __int64 v9; // x0
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w8
  int v20; // w9
  unsigned int v21; // w11
  int v22; // w8
  __int64 v23; // x4
  bool v24; // zf
  int v25; // w5
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v26[0] = 0;
  result = ucfg_mlme_get_indoor_channel_support(v9, v26);
  v19 = *(_DWORD *)(a2 + 12);
  if ( (a6 & 1) != 0 )
  {
    if ( (v19 & 0x200) != 0 )
    {
      *(_DWORD *)(a2 + 12) = v19 | 1;
      result = qdf_trace_msg(
                 0x33u,
                 4u,
                 "%s: Mark indoor channel %d as disable",
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 "hdd_modify_indoor_channel_state_flags",
                 *a3);
      a3[2] = 0;
    }
  }
  else if ( (v19 & 0x200) != 0 )
  {
    v20 = v26[0];
    v21 = v19 & 0xFFFFFFFE;
    v22 = *(_DWORD *)(a2 + 12) & 0xA;
    *(_DWORD *)(a2 + 12) = v21;
    v23 = *((unsigned __int8 *)a3 + 4);
    if ( v20 )
      v24 = v22 == 0;
    else
      v24 = 0;
    if ( v24 )
      v25 = 3;
    else
      v25 = 2;
    a3[2] = v25;
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Mark indoor channel %d as cds_chan state %d",
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "hdd_modify_indoor_channel_state_flags",
               v23);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
