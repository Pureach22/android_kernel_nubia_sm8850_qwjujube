__int64 __fastcall nl80211_tx_control_port(__int64 a1, _QWORD *a2)
{
  _QWORD *v3; // x11
  __int64 v4; // x1
  _BYTE *v5; // x20
  __int64 v6; // x19
  __int64 v7; // x10
  __int16 *v8; // x2
  __int64 v9; // x9
  __int64 v10; // x12
  unsigned int v11; // w13
  __int64 result; // x0
  _QWORD *v13; // x20
  _WORD *v14; // x2
  __int16 v15; // t1
  __int64 v16; // x13
  unsigned int v17; // w12
  unsigned __int16 v18; // w10
  __int64 v19; // x7
  _QWORD *v20; // x21
  __int64 v21; // x11
  _QWORD *v22; // x8
  __int64 v23; // x5
  _BOOL8 v24; // x6
  _DWORD *v25; // x11
  __int64 v26; // x8
  __int64 v27; // x9
  _QWORD v28[2]; // [xsp+50h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = (_QWORD *)a2[4];
  v5 = (_BYTE *)a2[6];
  v4 = a2[7];
  v6 = v3[142];
  v28[0] = 0;
  v7 = *(_QWORD *)(v4 + 992);
  if ( (v5[1107] & 4) == 0 || !*(_QWORD *)(*(_QWORD *)v5 + 864LL) )
  {
    result = 4294967201LL;
    goto LABEL_15;
  }
  v8 = (__int16 *)v3[51];
  if ( v8 && (v9 = v3[6]) != 0 && (v10 = v3[102]) != 0 )
  {
    v11 = *(_DWORD *)(v7 + 8);
    result = 4294967201LL;
    if ( v11 <= 9 )
    {
      if ( ((1 << v11) & 0x288) == 0 )
      {
        if ( ((1 << v11) & 0x104) != 0 )
        {
          if ( (*(_BYTE *)(v7 + 164) & 1) == 0 )
          {
LABEL_10:
            result = 4294967189LL;
            goto LABEL_15;
          }
        }
        else
        {
          if ( v11 != 1 )
            goto LABEL_15;
          if ( !*(_QWORD *)(v7 + 280) )
            goto LABEL_10;
        }
      }
      v15 = *v8;
      v14 = v8 + 2;
      v16 = v3[313];
      v17 = *(unsigned __int16 *)(v10 + 4);
      v18 = v15 - 4;
      if ( v16 )
        v19 = *(unsigned __int8 *)(v16 + 4);
      else
        v19 = 0xFFFFFFFFLL;
      v20 = a2;
      v21 = v3[103];
      v22 = v28;
      v23 = __rev16(v17);
      if ( v6 )
        v22 = nullptr;
      v24 = v21 != 0;
      v25 = *(_DWORD **)(*(_QWORD *)v5 + 864LL);
      if ( *(v25 - 1) != 921741517 )
        __break(0x822Bu);
      result = ((__int64 (__fastcall *)(_BYTE *, __int64, _WORD *, _QWORD, __int64, __int64, _BOOL8, __int64, _QWORD *))v25)(
                 v5 + 992,
                 v4,
                 v14,
                 v18,
                 v9 + 4,
                 v23,
                 v24,
                 v19,
                 v22);
      if ( !v6 && !(_DWORD)result )
      {
        v26 = v20[8];
        if ( v26 )
        {
          v27 = v28[0];
          result = 0;
          *(_BYTE *)(v26 + 54) = 8;
          *(_QWORD *)(v26 + 34) = v27;
        }
        else
        {
          result = 0;
        }
      }
    }
  }
  else
  {
    v13 = (_QWORD *)a2[8];
    do_trace_netlink_extack("Frame, MAC or ethertype missing");
    if ( v13 )
      *v13 = "Frame, MAC or ethertype missing";
    result = 4294967274LL;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
