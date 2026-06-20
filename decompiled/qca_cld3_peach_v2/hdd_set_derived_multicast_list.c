__int64 __fastcall hdd_set_derived_multicast_list(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 v7; // x24
  __int64 result; // x0
  unsigned int v9; // w8
  unsigned __int8 v10; // w25
  unsigned __int8 v11; // w26
  __int64 v12; // x27
  __int64 v13; // x28
  __int64 v14; // x7
  __int64 v15; // x5
  __int64 v16; // x6
  int v17; // w8
  __int64 v18; // x9
  __int64 v19; // x10
  unsigned int v21; // w22
  unsigned __int8 *v22; // x23
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // [xsp+0h] [xbp-30h]
  unsigned int v32; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v33[3]; // [xsp+18h] [xbp-18h] BYREF

  v33[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)a4;
  v33[0] = 0;
  v32 = 0;
  cfg_nan_get_ndp_max_sessions(a1, &v32);
  result = ucfg_nan_get_peer_mc_list(*(_QWORD *)(*(_QWORD *)(a2 + 52832) + 32LL), v33);
  v9 = v32;
  if ( v32 )
  {
    v10 = 0;
    v11 = 0;
    v12 = a3 + 16;
    v13 = 6 * v7;
    do
    {
      if ( !(_DWORD)v7 )
        goto LABEL_17;
      v18 = v33[0] + 6LL * v11;
      v19 = 0;
      while ( *(_DWORD *)v18 | *(unsigned __int16 *)(v18 + 4) )
      {
        if ( v19 == 198 )
          __break(0x5512u);
        if ( *(_DWORD *)(v12 + v19) == *(_DWORD *)v18
          && *(unsigned __int16 *)(v12 + v19 + 4) == *(unsigned __int16 *)(v18 + 4) )
        {
          break;
        }
        v19 += 6;
        if ( v13 == v19 )
          goto LABEL_17;
      }
      if ( (_DWORD)v13 == (_DWORD)v19 )
      {
LABEL_17:
        v21 = v7 + v10;
        if ( v21 <= 0x1F )
        {
          v22 = (unsigned __int8 *)(v12 + 6LL * v21);
          qdf_mem_copy(v22, (const void *)(v33[0] + 6LL * v11), 6u);
          if ( v22 )
          {
            v15 = *v22;
            v16 = v22[1];
            v14 = v22[2];
            v17 = v22[5];
          }
          else
          {
            v14 = 0;
            v15 = 0;
            v16 = 0;
            v17 = 0;
          }
          LODWORD(v31) = v17;
          result = qdf_trace_msg(
                     0x33u,
                     8u,
                     "%s: mlist[%d] = %02x:%02x:%02x:**:**:%02x",
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     "hdd_set_derived_multicast_list",
                     v21,
                     v15,
                     v16,
                     v14,
                     v31);
          v9 = v32;
          ++v10;
        }
      }
      ++v11;
    }
    while ( v9 > v11 );
    v9 = v10;
  }
  *a4 += v9;
  _ReadStatusReg(SP_EL0);
  return result;
}
