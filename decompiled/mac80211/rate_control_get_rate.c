__int64 __fastcall rate_control_get_rate(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x22
  _QWORD *v7; // x25
  __int64 v8; // x0
  __int64 v10; // x20
  __int64 result; // x0
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w10
  bool v17; // vf
  int v18; // w10
  __int64 v19; // x24
  __int64 v20; // x0
  void (__fastcall *v21)(__int64, __int64, __int64, __int64); // x8
  int v22; // w8
  unsigned int v23; // w9

  v3 = *(_QWORD *)(a3 + 24);
  v4 = a2 + 2688;
  v7 = *(_QWORD **)(*(_QWORD *)(a1 + 1616) + 2536LL);
  if ( a2 )
    v8 = a2 + 2688;
  else
    v8 = 0;
  *(_BYTE *)(v3 + 48) = -1;
  v10 = v3 + 48;
  *(_WORD *)(v10 + 1) = 0;
  *(_BYTE *)(v10 + 3) = -1;
  *(_WORD *)(v10 + 4) = 0;
  *(_BYTE *)(v10 + 6) = -1;
  *(_WORD *)(v10 + 7) = 0;
  *(_BYTE *)(v10 + 9) = -1;
  *(_WORD *)(v10 + 10) = 0;
  result = ((__int64 (__fastcall *)(__int64, __int64))rate_control_send_low)(v8, a3);
  if ( (result & 1) == 0 && (*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 96LL) & 1) == 0 )
  {
    if ( a2 && (*(_QWORD *)(a2 + 216) & 0x200000) != 0 )
    {
      v19 = *(_QWORD *)(a2 + 136);
      raw_spin_lock_bh(a2 + 144);
      v20 = v7[1];
      v21 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*v7 + 88LL);
      if ( *((_DWORD *)v21 - 1) != -1612646352 )
        __break(0x8228u);
      v21(v20, v4, v19, a3);
      result = raw_spin_unlock_bh(a2 + 144);
    }
    else
    {
      v12 = *(_QWORD *)(a3 + 8);
      v13 = *(_QWORD *)(a3 + 24);
      result = ((__int64 (__fastcall *)(_QWORD, __int64, _QWORD, __int64, _QWORD))_rate_control_send_low)(
                 *(_QWORD *)a3,
                 v12,
                 0,
                 v13 + 40,
                 *(unsigned int *)(a3 + 40));
      v4 = 0;
      if ( *(_BYTE *)(a3 + 56) == 1 )
      {
        v14 = *(unsigned int *)(v12 + 16);
        if ( (unsigned int)v14 >= 6 )
        {
          __break(0x5512u);
          JUMPOUT(0x6BC64);
        }
        v15 = *(_QWORD *)(a3 + 16);
        v16 = *(_DWORD *)(v15 + 4 * v14 + 88);
        v17 = __OFSUB__(v16, 1);
        v18 = v16 - 1;
        if ( v18 < 0 != v17 )
        {
          if ( (_DWORD)v14 == 4 )
          {
            LOBYTE(v22) = 0;
            *(_WORD *)(v13 + 49) |= 0x2000u;
LABEL_20:
            v4 = 0;
            *(_BYTE *)(v13 + 48) = v22;
          }
          else
          {
            v23 = *(_DWORD *)(v15 + 72);
            if ( v23 )
            {
              v22 = *(char *)(v13 + 48);
              if ( (v22 & 0x80000000) == 0 && ((v23 >> v22) & 1) == 0 )
              {
                while ( 1 )
                {
                  LOBYTE(v22) = v22 + 1;
                  if ( *(_DWORD *)(v12 + 24) < (int)(unsigned __int8)v22 )
                    break;
                  if ( ((v23 >> v22) & 1) != 0 )
                    goto LABEL_20;
                }
              }
            }
            v4 = 0;
          }
        }
        else
        {
          v4 = 0;
          *(_BYTE *)(v13 + 48) = v18;
        }
      }
    }
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 96LL) & 0x400000) == 0 )
      return ieee80211_get_tx_rates(a1 + 4720, v4, *(_QWORD *)(a3 + 24), (char *)v10, 4);
  }
  return result;
}
