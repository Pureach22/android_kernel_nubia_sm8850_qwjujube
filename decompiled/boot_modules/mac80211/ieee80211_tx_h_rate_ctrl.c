__int64 __fastcall ieee80211_tx_h_rate_ctrl(__int64 *a1)
{
  __int64 v1; // x20
  unsigned int v2; // w9
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v5; // x14
  __int64 v6; // x15
  int v8; // w16
  __int64 v9; // x13
  unsigned int v10; // w0
  __int64 v11; // x11
  int v12; // w12
  unsigned int v13; // w15
  unsigned int v14; // w13
  unsigned int v15; // w14
  unsigned __int64 v16; // t2
  bool v17; // cf
  unsigned int v18; // w14
  char v19; // w16
  char v20; // w13
  char v21; // w13
  char v22; // w13
  __int64 v23; // x14
  __int64 v24; // x1
  __int64 v25; // x12
  unsigned __int64 v26; // x12
  __int64 v27; // x11
  unsigned __int64 v28; // x11
  __int64 v29; // x14
  unsigned __int64 v30; // x13
  unsigned __int64 v31; // x15
  __int64 v32; // x8
  __int64 v33; // x9
  int v34; // w10
  char v35; // w11
  __int16 v36; // w12
  __int16 v37; // w11
  char v38; // w11
  char v39; // w13
  __int16 v40; // w10
  __int16 v41; // w8
  __int64 result; // x0
  int v43; // w9
  int v44; // w3
  __int16 v45; // w8
  _QWORD v46[4]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  __int64 v50; // [xsp+40h] [xbp-10h]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  v2 = *(_DWORD *)(*a1 + 40);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v3 = *(_DWORD *)(v1 + 44) & 7;
  v4 = *(_QWORD *)(v1 + 224);
  if ( (*(_DWORD *)(v1 + 44) & 7u) >= 6 )
    goto LABEL_64;
  v6 = a1[4];
  v5 = a1[5];
  v8 = *(_DWORD *)(v1 + 112);
  v9 = *(_QWORD *)(v6 + 72);
  v10 = *(_DWORD *)(v9 + 200);
  v11 = *(_QWORD *)(v9 + 8 * v3 + 328);
  LOBYTE(v47) = -1;
  v12 = *(_DWORD *)(v1 + 80);
  v46[0] = v6;
  v46[1] = v11;
  v13 = v8 + 4;
  v46[2] = v5 + 4808;
  v46[3] = v1;
  if ( v8 + 4 >= v10 )
    v13 = v10;
  if ( (v12 & 0x400) != 0 )
  {
    LODWORD(v48) = -1;
  }
  else
  {
    LODWORD(v48) = *(_DWORD *)(v5 + 4 * v3 + 2040);
    if ( *(_BYTE *)(v5 + v3 + 2064) == 1 )
      v49 = v5 + 10LL * (unsigned int)v3 + 2070;
  }
  v14 = *(_DWORD *)(v9 + 204);
  HIDWORD(v16) = *(_DWORD *)(v5 + 4720) - 1;
  LODWORD(v16) = HIDWORD(v16);
  v15 = v16 >> 1;
  v17 = v15 >= 6;
  v18 = 0x2Bu >> v15;
  v19 = !v17;
  LOBYTE(v50) = v19 & v18;
  if ( v13 <= v14 )
  {
    v20 = 0;
  }
  else
  {
    v20 = 1;
    BYTE3(v47) = 1;
  }
  v21 = *(_BYTE *)(v1 + 61) & 0xFE | v20;
  *(_BYTE *)(v1 + 61) = v21;
  v22 = v21 & 0xFD | (2 * *(_BYTE *)(a1[5] + 4853));
  *(_BYTE *)(v1 + 61) = v22;
  if ( *(_BYTE *)(a1[5] + 4854) != 1 )
    goto LABEL_18;
  if ( (*(_BYTE *)(*a1 + 41) & 0x40) != 0 || (**(_WORD **)(*a1 + 224) & 0xC) == 8 )
    goto LABEL_19;
  v23 = a1[6];
  if ( !v23 )
    goto LABEL_20;
  if ( (*(_QWORD *)(v23 + 216) & 0x10) != 0 )
  {
LABEL_19:
    BYTE4(v47) = 1;
    LOBYTE(v23) = 4;
  }
  else
  {
LABEL_18:
    LOBYTE(v23) = 0;
  }
LABEL_20:
  *(_BYTE *)(v1 + 61) = v22 & 0xFB | v23;
  if ( (v12 & 4) != 0 )
    goto LABEL_53;
  v24 = a1[6];
  if ( v24 )
    v25 = (*(_QWORD *)(v24 + 216) >> 1) & 1LL;
  else
    LODWORD(v25) = 0;
  if ( (*(_QWORD *)(a1[4] + 4696) & 1) == 0 || !(_DWORD)v25 )
  {
LABEL_34:
    rate_control_get_rate(a1[5], v24, (__int64)v46);
    v32 = a1[6];
    if ( !v32 || (*(_BYTE *)(v1 + 61) & 8) != 0 )
    {
      v33 = 0;
      if ( *(char *)(v1 + 48) < 0 )
      {
LABEL_37:
        if ( !v33 || (v34 = *(char *)(v33 + 16), v34 < 0) )
        {
          result = 1;
          goto LABEL_54;
        }
        v35 = *(_BYTE *)(v33 + 17);
        v36 = *(_WORD *)(v33 + 20);
        *((_BYTE *)a1 + 64) = v34;
        *(_WORD *)((char *)a1 + 65) = v35 & 0x1F | (32 * v36);
LABEL_42:
        if ( (char)v47 < 0 )
        {
          v39 = *((_BYTE *)a1 + 66);
          LOWORD(v47) = *((_WORD *)a1 + 32);
          BYTE2(v47) = v39;
          if ( v32 && ((*(_BYTE *)(*a1 + 41) & 0x40) != 0 || (**(_WORD **)(*a1 + 224) & 0xC) == 8) )
          {
            v40 = *((_WORD *)a1 + 32);
            *(_BYTE *)(v32 + 2394) = *((_BYTE *)a1 + 66);
            *(_WORD *)(v32 + 2392) = v40;
          }
        }
        else if ( v32 )
        {
          v38 = BYTE2(v47);
          *(_WORD *)(v32 + 2392) = v47;
          *(_BYTE *)(v32 + 2394) = v38;
        }
        if ( !v33 )
        {
          v41 = *(_WORD *)(v1 + 49);
          if ( (v41 & 0x1F) != 0 )
          {
            if ( (v41 & 0x1E) != 0 )
              goto LABEL_52;
          }
          else
          {
            v45 = v41 | 1;
            *(_WORD *)(v1 + 49) = v45;
            if ( (v45 & 0x1E) != 0 )
            {
LABEL_52:
              if ( (*(_BYTE *)(v1 + 40) & 4) != 0 )
              {
                __break(0x800u);
                result = 0;
                *(_WORD *)(v1 + 49) = *(_WORD *)(v1 + 49) & 0xFFE0 | 1;
                goto LABEL_54;
              }
            }
          }
        }
LABEL_53:
        result = 0;
        goto LABEL_54;
      }
    }
    else
    {
      v33 = *(_QWORD *)(v32 + 2704);
      if ( *(char *)(v1 + 48) < 0 )
        goto LABEL_37;
    }
    v37 = *(_WORD *)(v1 + 48);
    *((_BYTE *)a1 + 66) = *(_BYTE *)(v1 + 50);
    *((_WORD *)a1 + 32) = v37;
    goto LABEL_42;
  }
  v26 = *(unsigned int *)(v11 + 24);
  if ( (_DWORD)v26 )
  {
    if ( v24 == -2688 )
      goto LABEL_34;
    v27 = *(unsigned int *)(v11 + 16);
    if ( (unsigned int)v27 <= 5 )
    {
      v28 = *(unsigned int *)(v24 + 2900 + 4 * v27);
      if ( (v28 & 1) != 0 )
        goto LABEL_34;
      v29 = 1;
      do
      {
        v30 = v29;
        if ( v26 == v29 )
          break;
        v31 = v28 >> ((unsigned __int8)v29++ - 1);
      }
      while ( (v31 & 2) == 0 );
      if ( v30 < v26 )
        goto LABEL_34;
      goto LABEL_55;
    }
LABEL_64:
    __break(0x5512u);
  }
LABEL_55:
  v43 = ~(v2 >> 12);
  if ( (_DWORD)v3 )
    v44 = 5;
  else
    v44 = 2;
  _warn_printk(
    "%s: Dropped data frame as no usable bitrate found while scanning and associated. Target station: %pM on %d GHz band\n",
    (const char *)(a1[5] + 1640),
    (const void *)(v4 + (v43 & 4)),
    v44);
  __break(0x800u);
  result = 1;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
