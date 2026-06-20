__int64 __fastcall rmnet_perf_udp_track_node_update(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x8
  int v3; // w9
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x10
  unsigned int v7; // w8
  __int64 v8; // x19
  __int64 v9; // x5
  __int64 v10; // x20
  __int64 v11; // x10
  __int64 v12; // x19
  unsigned int v14; // w11
  unsigned int v15; // w19
  unsigned int v21; // w12
  __int64 v22; // x11
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v2 = *(_QWORD *)(result + 72);
  *(_QWORD *)(result + 80) = jiffies;
  if ( v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    *(_BYTE *)(a2 + 42) = 1;
    return result;
  }
  if ( !v2 )
  {
    v3 = *(unsigned __int8 *)(result + 68);
    v4 = result;
    v5 = *(_QWORD *)(*(_QWORD *)(a2 + 16) + 280LL);
    if ( v3 == 4 )
    {
      v6 = v4;
      v7 = *(_DWORD *)(v4 + 32);
      v8 = v6;
      if ( (*(_QWORD *)(a2 + 88) & 0xFFFFFFFFFFFFFFFELL) == 0
        || (v9 = *(unsigned int *)((*(_QWORD *)(a2 + 88) & 0xFFFFFFFFFFFFFFFELL) + 148), !(_DWORD)v9) )
      {
        v9 = *(unsigned int *)(a2 + 148);
      }
      v10 = a2;
      result = _udp4_lib_lookup(
                 v5,
                 v7,
                 *(unsigned __int16 *)(v6 + 64),
                 *(unsigned int *)(v6 + 48),
                 *(unsigned __int16 *)(v6 + 66),
                 v9,
                 0,
                 &udp_table,
                 0);
      v11 = v8;
      if ( !result )
        goto LABEL_24;
    }
    else
    {
      v10 = a2;
      v12 = v4;
      result = _udp6_lib_lookup(
                 v5,
                 v4 + 32,
                 *(unsigned __int16 *)(v4 + 64),
                 v4 + 48,
                 *(unsigned __int16 *)(v4 + 66),
                 *(unsigned int *)(a2 + 40),
                 0,
                 &udp_table,
                 0);
      v11 = v12;
      if ( !result )
        goto LABEL_24;
    }
    _X8 = (unsigned int *)(result + 128);
    v14 = *(_DWORD *)(result + 128);
    if ( v14 )
    {
      do
      {
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( v21 == v14 && __stxr(v14 + 1, _X8) );
        v15 = v14;
        if ( v21 == v14 )
          break;
        v15 = 0;
        v14 = v21;
      }
      while ( v21 );
    }
    else
    {
      v15 = 0;
    }
    if ( (((v15 + 1) | v15) & 0x80000000) != 0 )
    {
      v24 = result;
      v23 = v11;
      refcount_warn_saturate(result + 128, 0);
      result = v24;
      v11 = v23;
      if ( v15 )
        goto LABEL_22;
    }
    else if ( v15 )
    {
LABEL_22:
      *(_QWORD *)(v11 + 72) = result;
      return result;
    }
LABEL_24:
    v22 = qword_EAC0;
    *(_QWORD *)(v11 + 72) = -22;
    qword_EAC0 = v22 + 1;
    *(_BYTE *)(v10 + 42) = 1;
  }
  return result;
}
