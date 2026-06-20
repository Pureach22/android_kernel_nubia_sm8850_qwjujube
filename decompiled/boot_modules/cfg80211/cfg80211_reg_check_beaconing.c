__int64 __fastcall cfg80211_reg_check_beaconing(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  unsigned int v5; // w21
  unsigned int v6; // w22
  __int64 *v7; // x29
  char v8; // w8
  char v9; // w0
  int v10; // w22
  int v11; // w9
  unsigned int v12; // w26
  int v13; // w8
  int v14; // w9
  unsigned int v15; // w23
  char v16; // w24
  __int64 v17; // x28
  int v18; // w10
  int v19; // w9
  int v20; // w8
  int v21; // w10
  __int64 channel_khz; // x0
  int v23; // w8
  int v24; // w8
  int v25; // w8
  int v26; // w9
  int v27; // w9
  int v28; // w8
  int v29; // w9
  char v30; // w8
  __int64 v31; // x2
  unsigned __int64 StatusReg; // x23
  __int64 can_beacon; // x0
  __int64 v35; // x1
  __int64 v36; // x2
  __int64 v37; // x8
  __int64 vars0; // [xsp+10h] [xbp+0h] BYREF

  if ( a1 )
  {
    v7 = &vars0;
    v6 = *a3;
    v3 = a1;
    v4 = a2;
    v5 = (a3[1] == 3) << 25;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      can_beacon = _traceiter_cfg80211_reg_can_beacon(0, v3, v4, v6, 2, v5);
      v37 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v37;
      if ( !v37 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(can_beacon, v35, v36);
    }
  }
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))cfg80211_chandef_usable)(v3, v4, 1, 0);
  v9 = 0;
  if ( (v8 & 1) == 0 )
    return v9 & 1;
  v10 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))cfg80211_chandef_dfs_required)(v3, v4, v6);
  if ( v10 < 1 )
  {
LABEL_75:
    if ( !v10 )
      goto LABEL_77;
    goto LABEL_76;
  }
  if ( (cfg80211_chandef_valid((__int64 *)v4) & 1) == 0 || (v11 = *(_DWORD *)(v4 + 8), (unsigned int)v11 >= 0xE) )
  {
    __break(0x800u);
LABEL_76:
    v30 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))cfg80211_chandef_usable)(v3, v4, 8, 0);
    v9 = 0;
    if ( (v30 & 1) == 0 )
      return v9 & 1;
LABEL_77:
    v31 = 2;
    goto LABEL_79;
  }
  v12 = *(unsigned __int16 *)(v4 + 30);
  *((_DWORD *)v7 - 1) = *(unsigned __int8 *)(v3 + 115);
  v13 = *(_DWORD *)(v4 + 12);
  if ( v11 <= 4 )
  {
    if ( (unsigned int)v11 >= 2 )
    {
      if ( (unsigned int)(v11 - 3) >= 2 )
        v14 = -20000;
      else
        v14 = -40000;
      goto LABEL_18;
    }
LABEL_15:
    v15 = 1000 * v13;
    goto LABEL_19;
  }
  if ( (unsigned int)(v11 - 6) < 7 )
    goto LABEL_15;
  if ( v11 == 5 )
    v14 = -80000;
  else
    v14 = -160000;
LABEL_18:
  v15 = v14 + 1000 * v13 + 10000;
LABEL_19:
  v16 = 1;
LABEL_20:
  if ( (v16 & 1) != 0 )
    v17 = 12;
  else
    v17 = 16;
  while ( 1 )
  {
    v19 = *(_DWORD *)(v4 + 8);
    v20 = *(_DWORD *)(v4 + v17);
    if ( v19 > 4 )
      break;
    if ( (unsigned int)v19 >= 2 )
    {
      if ( (unsigned int)(v19 - 3) < 2 )
      {
        v21 = 40000;
        goto LABEL_42;
      }
      if ( v19 == 2 )
      {
        v21 = 20000;
        goto LABEL_42;
      }
      goto LABEL_41;
    }
LABEL_37:
    if ( v15 > 1000 * v20 )
      goto LABEL_78;
LABEL_43:
    if ( (v12 & 1) == 0 )
    {
      channel_khz = ieee80211_get_channel_khz(v3, v15);
      if ( !channel_khz )
        goto LABEL_75;
      v23 = *(_DWORD *)(channel_khz + 12);
      if ( (v23 & 1) != 0 )
        goto LABEL_75;
      if ( (v23 & 8) != 0 )
      {
        v24 = *(_DWORD *)(channel_khz + 44);
        if ( v24 != 2 && (v24 || (*((_DWORD *)v7 - 1) & 2) == 0) )
          goto LABEL_75;
      }
    }
    v15 += 20000;
    if ( (v16 & 1) == 0 || !*(_DWORD *)(v4 + 16) )
      goto LABEL_60;
    v26 = *(_DWORD *)(v4 + 8);
    v25 = *(_DWORD *)(v4 + 12);
    if ( v26 <= 4 )
    {
      if ( (unsigned int)v26 < 2 )
      {
LABEL_24:
        if ( v15 > 1000 * v25 )
          goto LABEL_61;
        goto LABEL_60;
      }
      if ( (unsigned int)(v26 - 3) < 2 )
      {
        v18 = 40000;
        goto LABEL_59;
      }
      if ( v26 == 2 )
      {
        v18 = 20000;
        goto LABEL_59;
      }
LABEL_58:
      __break(0x800u);
      v18 = 2147483148;
      goto LABEL_59;
    }
    if ( (unsigned int)(v26 - 6) < 7 )
      goto LABEL_24;
    v18 = 80000;
    if ( v26 != 5 )
    {
      v18 = 160000;
      if ( v26 != 13 )
        goto LABEL_58;
    }
LABEL_59:
    if ( v15 > v18 + 1000 * v25 - 10000 )
    {
LABEL_61:
      v27 = *(_DWORD *)(v4 + 8);
      v28 = *(_DWORD *)(v4 + 16);
      if ( v27 > 4 )
      {
        if ( (unsigned int)(v27 - 6) >= 7 )
        {
          if ( v27 == 5 )
          {
            v29 = -80000;
          }
          else
          {
            if ( v27 == 13 )
            {
              v29 = -160000;
              goto LABEL_74;
            }
LABEL_72:
            __break(0x800u);
            v29 = -2147483148;
          }
          goto LABEL_74;
        }
LABEL_69:
        v15 = 1000 * v28;
        v12 = 0;
        v16 = 0;
        goto LABEL_20;
      }
      if ( (unsigned int)v27 < 2 )
        goto LABEL_69;
      if ( (unsigned int)(v27 - 3) >= 2 )
      {
        if ( v27 != 2 )
          goto LABEL_72;
        v29 = -20000;
      }
      else
      {
        v29 = -40000;
      }
LABEL_74:
      v12 = 0;
      v16 = 0;
      v15 = v29 + 1000 * v28 + 10000;
      goto LABEL_20;
    }
LABEL_60:
    v12 >>= 1;
  }
  if ( (unsigned int)(v19 - 6) < 7 )
    goto LABEL_37;
  v21 = 80000;
  if ( v19 != 5 )
  {
    v21 = 160000;
    if ( v19 != 13 )
    {
LABEL_41:
      __break(0x800u);
      v21 = 2147483148;
    }
  }
LABEL_42:
  if ( v15 <= v21 + 1000 * v20 - 10000 )
    goto LABEL_43;
LABEL_78:
  v31 = 0;
LABEL_79:
  v9 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))cfg80211_chandef_usable)(v3, v4, v31, v5);
  return v9 & 1;
}
