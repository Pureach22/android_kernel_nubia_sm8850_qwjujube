__int64 __fastcall ieee80211_get_tx_rates(__int64 result, __int64 a2, __int64 a3, char *a4, int a5)
{
  __int64 v9; // x23
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x12
  __int16 v14; // w14
  char *v15; // x16
  char *v16; // x14
  __int16 v17; // w15
  char v18; // w16
  __int16 v19; // w15
  __int16 v20; // w15
  bool v21; // zf
  __int64 v22; // x20
  unsigned int v23; // w25
  unsigned int v24; // w26
  __int64 v25; // x28
  char *v26; // x27
  __int64 v27; // x4
  unsigned __int64 v28; // x8
  __int64 v29; // x10
  char v30; // w9
  __int64 v31; // x11
  __int64 v32; // x15
  unsigned __int16 *v33; // x13
  unsigned int v34; // w16
  char v35; // w12
  __int64 v36; // x8
  _WORD *v37; // x9
  unsigned int v38; // w13
  unsigned int v39; // w12
  char v40; // w14
  _BYTE *v41; // x12
  _QWORD *v42; // [xsp+8h] [xbp-38h]
  __int16 v43[2]; // [xsp+10h] [xbp-30h] BYREF
  unsigned int v44; // [xsp+14h] [xbp-2Ch] BYREF
  _QWORD v45[2]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v46; // [xsp+28h] [xbp-18h] BYREF
  __int16 v47; // [xsp+30h] [xbp-10h]
  __int64 v48; // [xsp+38h] [xbp-8h]

  v9 = result;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || (*(_BYTE *)(a3 + 61) & 8) != 0 )
  {
    v10 = 0;
    if ( a5 < 1 )
      goto LABEL_27;
  }
  else
  {
    v10 = *(_QWORD *)(a2 + 16);
    if ( a5 < 1 )
      goto LABEL_27;
  }
  v11 = 0;
  if ( (unsigned int)a5 >= 4 )
    v12 = 4;
  else
    v12 = (unsigned int)a5;
  v13 = 16;
  do
  {
    if ( *(char *)(a3 + v11 + 48) < 0 || (*(_WORD *)(a3 + v11 + 49) & 0x1F) == 0 )
    {
      if ( v10 )
      {
        v16 = &a4[v11];
        *v16 = *(_BYTE *)(v10 + v13);
        v17 = 32 * *(_WORD *)(v10 + 2 * v11 + 20);
        *(_WORD *)(v16 + 1) = v17 | *(_WORD *)&a4[v11 + 1] & 0x1F;
        if ( (*(_BYTE *)(a3 + 61) & 1) != 0 )
        {
          v18 = *(_BYTE *)(v10 + v13 + 3);
        }
        else if ( (*(_BYTE *)(a3 + 61) & 2) != 0 )
        {
          v18 = *(_BYTE *)(v10 + v13 + 2);
        }
        else
        {
          v18 = *(_BYTE *)(v10 + v13 + 1);
        }
        v20 = v17 | v18 & 0x1F;
      }
      else
      {
        v16 = &a4[v11];
        v19 = *(_WORD *)&a4[v11 + 1];
        a4[v11] = -1;
        v20 = v19 & 0xFFE0;
      }
      *(_WORD *)(v16 + 1) = v20;
    }
    else if ( (char *)(a3 + 48) != a4 )
    {
      v14 = *(_WORD *)(a3 + v11 + 48);
      v15 = &a4[v11];
      v15[2] = *(_BYTE *)(a3 + v11 + 50);
      *(_WORD *)v15 = v14;
    }
    if ( a4[v11] < 0 )
      break;
    if ( (*(_WORD *)&a4[v11 + 1] & 0x1F) == 0 )
      break;
    v21 = v12 + 2LL * (unsigned int)v12 - 3 == v11;
    v11 += 3;
    v13 += 6;
  }
  while ( !v21 );
LABEL_27:
  if ( !result )
    goto LABEL_85;
  if ( (*(_DWORD *)(a3 + 44) & 7u) >= 6 )
    goto LABEL_86;
  v42 = (_QWORD *)(result - 3104);
  v22 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result - 3104) + 72LL) + 8LL * (*(_DWORD *)(a3 + 44) & 7) + 328);
  if ( (*(_BYTE *)(a3 + 41) & 0x40) != 0 || (**(_WORD **)(a3 + 224) & 0xC) == 8 )
  {
    v47 = 0;
    v46 = 0;
    v44 = 0;
    v45[0] = 0;
    v45[1] = 0;
    result = rate_control_cap_mask(result - 4720, v22, a2, &v44, &v46, v45);
    if ( (result & 1) != 0 && a5 >= 1 )
    {
      v23 = *(_DWORD *)(v9 + 232);
      v24 = v44;
      v25 = (unsigned int)a5;
      v26 = a4;
      do
      {
        if ( *v26 < 0 )
          break;
        v43[0] = *(_WORD *)(v26 + 1) >> 5;
        result = rate_idx_match_mask(v26, v43, v22, v23, v24, &v46, v45);
        --v25;
        *(_WORD *)(v26 + 1) = *(_WORD *)(v26 + 1) & 0x1F | (32 * v43[0]);
        v26 += 3;
      }
      while ( v25 );
    }
  }
  if ( (*(_BYTE *)(a3 + 81) & 4) == 0 )
  {
    if ( (*(_DWORD *)(a3 + 44) & 7u) <= 5 )
    {
      v27 = *(unsigned int *)(v9 + 4LL * (*(_DWORD *)(a3 + 44) & 7) - 2680);
      if ( *a4 < 0 )
        goto LABEL_41;
      goto LABEL_42;
    }
LABEL_86:
    __break(0x5512u);
    JUMPOUT(0x6B8D8);
  }
  v27 = 0xFFFFFFFFLL;
  if ( *a4 < 0 )
LABEL_41:
    result = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64, __int64))_rate_control_send_low)(
               *v42,
               v22,
               a2,
               a3 + 40,
               v27);
LABEL_42:
  if ( a2 )
  {
    if ( (*(_WORD *)(a4 + 1) & 0x2100) == 0 )
    {
      v28 = *(unsigned int *)(v9 + 160);
      v29 = *(unsigned int *)(v22 + 24);
      v30 = __clz(__rbit32(v28));
      if ( !*(_DWORD *)(v9 + 160) )
        v30 = 0;
      if ( (int)v29 >= 1 )
      {
        v31 = *(_QWORD *)(v22 + 8);
        v32 = 0;
        v33 = (unsigned __int16 *)(v31 + 4);
        do
        {
          if ( ((v28 >> v32) & 1) != 0 )
          {
            v34 = *v33;
            if ( v34 <= *(unsigned __int16 *)(v31 + 4 + 12LL * *a4) && *(unsigned __int16 *)(v31 + 12LL * v30 + 4) < v34 )
              v30 = v32;
          }
          ++v32;
          v33 += 6;
        }
        while ( v29 != v32 );
      }
      *(_BYTE *)(a3 + 60) = v30;
    }
    if ( a5 >= 1 )
    {
      v35 = 0;
      v36 = (unsigned int)a5;
      v37 = a4 + 1;
      do
      {
        if ( (v35 & 1) != 0 )
        {
          *((_BYTE *)v37 - 1) = -1;
LABEL_70:
          v35 = 1;
          goto LABEL_59;
        }
        if ( *((char *)v37 - 1) < 0 )
          goto LABEL_70;
        v38 = (unsigned __int16)*v37;
        v39 = *((unsigned __int8 *)v37 - 1);
        if ( ((v38 >> 5) & 8) == 0 )
        {
          if ( ((v38 >> 5) & 0x100) != 0 )
          {
            if ( (v39 & 0xE) >= 0xA )
            {
              v35 = 0;
              __break(0x800u);
              goto LABEL_59;
            }
          }
          else
          {
            v40 = *(_BYTE *)(a3 + 61);
            if ( (v40 & 1) != 0 )
            {
              *v37 = v38 | 0x20;
              v40 = *(_BYTE *)(a3 + 61) & 0xFD;
              *(_BYTE *)(a3 + 61) = v40;
              LOBYTE(v39) = *((_BYTE *)v37 - 1);
            }
            if ( *(_DWORD *)(v22 + 24) <= (char)v39 )
            {
              v35 = 0;
              __break(0x800u);
              *((_BYTE *)v37 - 1) = -1;
              goto LABEL_59;
            }
            v41 = (_BYTE *)(*(_QWORD *)(v22 + 8) + 12LL * (char)v39);
            if ( (v40 & 4) != 0 )
            {
              LOWORD(v38) = *v37;
              if ( (*v41 & 1) != 0 )
              {
                LOWORD(v38) = v38 | 0x80;
                *v37 = v38;
              }
            }
            else
            {
              LOWORD(v38) = *v37;
            }
            if ( (v38 & 0x20) == 0 && (*(_BYTE *)(a3 + 61) & 2) != 0 && (*v41 & 0x10) != 0 )
            {
LABEL_74:
              v35 = 0;
              *v37 = v38 | 0x40;
              goto LABEL_59;
            }
          }
          goto LABEL_58;
        }
        if ( v39 >= 0x4D )
        {
          __break(0x800u);
          LOWORD(v38) = *v37;
          if ( (*v37 & 0x20) == 0 )
          {
LABEL_73:
            if ( (*(_BYTE *)(a3 + 61) & 2) != 0 )
              goto LABEL_74;
          }
        }
        else if ( (v38 & 0x20) == 0 )
        {
          goto LABEL_73;
        }
LABEL_58:
        v35 = 0;
LABEL_59:
        --v36;
        v37 = (_WORD *)((char *)v37 + 3);
      }
      while ( v36 );
    }
  }
LABEL_85:
  _ReadStatusReg(SP_EL0);
  return result;
}
