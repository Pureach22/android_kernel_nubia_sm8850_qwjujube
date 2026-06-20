__int64 __fastcall ml_nlink_get_standby_link_info(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        _BYTE *a7,
        _DWORD *a8)
{
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x24
  unsigned int v25; // w28
  unsigned int v26; // w4
  char v27; // w9
  const char *v29; // x2
  __int64 v30; // [xsp+0h] [xbp-20h]
  __int64 v31; // [xsp+8h] [xbp-18h]
  __int64 v32; // [xsp+10h] [xbp-10h]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = mlo_mgr_get_ap_link(a1);
  if ( result )
  {
    v24 = result;
    v25 = 0;
    do
    {
      WORD2(v32) = 0;
      LODWORD(v32) = 0;
      if ( !(*(_DWORD *)(v24 + 24) | *(unsigned __int16 *)(v24 + 28)) )
        break;
      if ( *(unsigned __int8 *)(v24 + 12) == 255 )
      {
        if ( (unsigned __int8)*a7 >= (unsigned int)a3 )
        {
          v29 = "%s: link lst overflow";
LABEL_25:
          result = qdf_trace_msg(
                     0x8Fu,
                     8u,
                     v29,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     "ml_nlink_get_standby_link_info");
          break;
        }
        if ( !**(_WORD **)(v24 + 32) )
        {
          v29 = "%s: link freq 0!";
          goto LABEL_25;
        }
        v26 = *(unsigned __int8 *)(v24 + 6);
        if ( ((*a8 >> v26) & 1) != 0 )
        {
          v29 = "%s: unexpected standby linkid %d";
          goto LABEL_25;
        }
        if ( v26 >= 0xF )
        {
          v29 = "%s: invalid standby link id %d";
          goto LABEL_25;
        }
        if ( (a2 & 1) != 0 && (*(_QWORD *)(v24 + 16) & 1) != 0 )
        {
          result = qdf_trace_msg(
                     0x8Fu,
                     8u,
                     "%s: standby link %d is removed",
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     "ml_nlink_get_standby_link_info");
          continue;
        }
        if ( (a2 & 2) != 0 && (*(_QWORD *)(v24 + 16) & 1) == 0 )
          continue;
        *(_DWORD *)(a4 + 4LL * (unsigned __int8)*a7) = **(unsigned __int16 **)(v24 + 32);
        *(_BYTE *)(a5 + (unsigned __int8)*a7) = -1;
        v27 = *(_BYTE *)(v24 + 6);
        *(_BYTE *)(a6 + (unsigned __int8)*a7) = v27;
        *a8 |= 1 << v27;
        if ( (a2 & 0x10) != 0 )
        {
          LODWORD(v30) = a2;
          result = qdf_trace_msg(
                     0x8Fu,
                     8u,
                     "%s: vdev %d link %d freq %d bitmap 0x%x flag 0x%x",
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     "ml_nlink_get_standby_link_info",
                     *(unsigned __int8 *)(a5 + (unsigned __int8)*a7),
                     *(unsigned __int8 *)(a6 + (unsigned __int8)*a7),
                     *(unsigned int *)(a4 + 4LL * (unsigned __int8)*a7),
                     v30,
                     v31,
                     v32,
                     v33);
        }
        ++*a7;
      }
      v24 += 48;
    }
    while ( v25++ < 2 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
