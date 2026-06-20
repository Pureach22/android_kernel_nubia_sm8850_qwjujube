__int64 __fastcall ieee80211_process_addba_request(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  unsigned int v5; // w23
  unsigned __int8 v6; // w20
  unsigned __int16 v7; // w21
  unsigned int v8; // w24
  unsigned int v9; // w19
  __int64 v10; // x0
  _BYTE *v11; // x8
  __int64 v12; // x25
  __int64 result; // x0
  _QWORD v14[3]; // [xsp+18h] [xbp-48h] BYREF
  char v15; // [xsp+30h] [xbp-30h]
  __int64 v16; // [xsp+31h] [xbp-2Fh]
  __int64 v17; // [xsp+39h] [xbp-27h]
  _BYTE v18[31]; // [xsp+41h] [xbp-1Fh]

  *(_QWORD *)&v18[23] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned __int16 *)(a3 + 27);
  v6 = *(_BYTE *)(a3 + 26);
  v7 = *(_WORD *)(a3 + 29);
  v8 = *(unsigned __int16 *)(a3 + 31);
  v9 = v5 >> 6;
  if ( a4 == 33 )
  {
    v12 = 0;
    v11 = nullptr;
LABEL_9:
    _ieee80211_start_rx_ba_session(a2, v6, v7, v8 >> 4, (v5 >> 1) & 1, (v5 >> 2) & 0xF, v9, 1, 0, v11);
    v10 = v12;
    goto LABEL_10;
  }
  v14[0] = 5;
  v14[1] = a3 + 33;
  v14[2] = a4 - 33;
  v15 = 1;
  v16 = 0;
  v17 = 0;
  *(_QWORD *)v18 = 0;
  *(_QWORD *)&v18[7] = 0;
  *(_QWORD *)&v18[15] = 0xFFFFFFFFLL;
  v10 = ieee802_11_parse_elems_full(v14);
  if ( v10 && !*(_BYTE *)(v10 + 760) )
  {
    v11 = *(_BYTE **)(v10 + 392);
    if ( *(_BYTE *)(a2 + 3021) == 1 && v11 )
    {
      v12 = v10;
      v9 = v9 & 0xFFFFE3FF | ((((unsigned __int8)*v11 >> 5) & 7) << 10);
    }
    else
    {
      v12 = v10;
    }
    goto LABEL_9;
  }
LABEL_10:
  result = kfree(v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
