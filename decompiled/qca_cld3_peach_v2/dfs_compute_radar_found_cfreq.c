__int64 __fastcall dfs_compute_radar_found_cfreq(
        __int64 result,
        _DWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w8
  int v12; // w8
  int v13; // w10
  __int64 v14; // x19
  int v15; // w10
  __int64 v16; // x11
  __int64 v17; // x10
  _DWORD *v18; // x20

  if ( *(_BYTE *)(result + 14956) == 1 )
  {
    v11 = a2[8];
LABEL_3:
    *a3 = v11;
    return result;
  }
  if ( a2[4] == 3 )
  {
    v12 = *(unsigned __int16 *)(result + 14952);
    *a3 = v12;
    v13 = *(_DWORD *)(result + 14880);
    if ( v13 == 4 )
    {
      if ( *(_WORD *)(result + 14952) == 5730 )
      {
        if ( a2[5] )
        {
          v11 = v12 + 45;
          goto LABEL_3;
        }
        goto LABEL_29;
      }
    }
    else if ( v13 == 3 )
    {
      if ( a2[5] )
      {
        v11 = v12 + 40;
        goto LABEL_3;
      }
LABEL_29:
      v11 = v12 - 40;
      goto LABEL_3;
    }
  }
  else
  {
    v14 = *(_QWORD *)(result + 14888);
    if ( a2[5] )
    {
      v15 = *(unsigned __int16 *)(v14 + 24);
      *a3 = v15;
      v16 = *(_QWORD *)(v14 + 8);
      if ( (~v16 & 0x11000000000LL) == 0
        || (v16 & 0x10000000100LL) == 0x10000000100LL
        || (v16 & 0x1400000000LL) == 0x1400000000LL
        || (*(_QWORD *)(v14 + 8) & 0x4000100LL) == 0x4000100
        || (v16 & 0x400000100LL) == 0x400000100LL )
      {
        if ( *(unsigned __int16 *)(v14 + 24) >= (unsigned int)*(unsigned __int16 *)(v14 + 22) )
          v11 = v15 + 40;
        else
          v11 = v15 - 40;
        goto LABEL_3;
      }
    }
    else
    {
      *a3 = *(unsigned __int16 *)(v14 + 22);
      v17 = *(_QWORD *)(v14 + 8);
      if ( (~v17 & 0x21000000000LL) == 0
        || (v17 & 0x20000000100LL) == 0x20000000100LL
        || (v17 & 0x11000000000LL) == 0x11000000000LL
        || (v17 & 0x10000000100LL) == 0x10000000100LL
        || (v17 & 0x1400000000LL) == 0x1400000000LL
        || (*(_QWORD *)(v14 + 8) & 0x4000100LL) == 0x4000100
        || (v17 & 0x400000100LL) == 0x400000100LL )
      {
        v18 = a3;
        result = qdf_trace_msg(
                   0x27u,
                   8u,
                   "WLAN_DEBUG_DFS_ALWAYS : %s: center freq %d override to %d",
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   "dfs_radar_detect_center_freq_adjust");
        v11 = *(unsigned __int16 *)(v14 + 24);
        a3 = v18;
        goto LABEL_3;
      }
    }
  }
  return result;
}
