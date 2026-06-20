__int64 __fastcall nl80211_set_tid_config(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x8
  unsigned __int8 *v4; // x25
  _WORD *v5; // x9
  int v6; // w8
  __int64 v7; // x19
  unsigned __int16 *v8; // x9
  unsigned int v9; // w10
  __int64 v10; // x10
  __int64 result; // x0
  unsigned __int64 v12; // x23
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  _WORD *v16; // x8
  int v17; // w26
  unsigned __int16 *v18; // x28
  int v19; // w27
  unsigned int v20; // w9
  int v21; // w0
  __int64 v22; // x8
  __int64 v23; // x21
  _QWORD *v24; // x22
  __int64 v25; // x24
  __int64 (__fastcall *v26)(unsigned __int8 *, __int64, __int64); // x8
  unsigned int v27; // w8
  unsigned int v28; // w8
  int v29; // w8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x8
  __int64 (__fastcall *v34)(unsigned __int8 *, __int64, __int64 *); // x8
  unsigned int v35; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v37; // x22
  __int64 v38; // [xsp+18h] [xbp-98h]
  __int64 v39; // [xsp+20h] [xbp-90h]
  __int64 *v40; // [xsp+28h] [xbp-88h]
  _QWORD v41[4]; // [xsp+30h] [xbp-80h] BYREF
  __int64 v42; // [xsp+50h] [xbp-60h]
  __int64 v43; // [xsp+58h] [xbp-58h]
  __int64 v44; // [xsp+60h] [xbp-50h]
  __int64 v45; // [xsp+68h] [xbp-48h]
  __int64 v46; // [xsp+70h] [xbp-40h]
  __int64 v47; // [xsp+78h] [xbp-38h]
  __int64 v48; // [xsp+80h] [xbp-30h]
  __int64 v49; // [xsp+88h] [xbp-28h]
  __int64 v50; // [xsp+90h] [xbp-20h]
  __int64 v51; // [xsp+98h] [xbp-18h]
  __int64 v52; // [xsp+A0h] [xbp-10h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a2[4];
  v50 = 0;
  v51 = 0;
  v4 = (unsigned __int8 *)a2[6];
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  memset(v41, 0, sizeof(v41));
  if ( *(_QWORD *)(v3 + 2504) )
  {
    v5 = *(_WORD **)(v3 + 2280);
    if ( v5 )
      goto LABEL_3;
LABEL_11:
    result = 4294967274LL;
    goto LABEL_97;
  }
  v5 = *(_WORD **)(v3 + 2280);
  if ( !v5 )
    goto LABEL_11;
LABEL_3:
  if ( *(_QWORD *)(*(_QWORD *)v4 + 912LL) )
  {
    v6 = (unsigned __int16)(*v5 - 4);
    if ( (unsigned int)v6 < 4 )
    {
      LODWORD(v7) = 0;
    }
    else
    {
      LODWORD(v7) = 0;
      v8 = v5 + 2;
      do
      {
        v9 = *v8;
        if ( v9 < 4 )
          break;
        if ( v6 < v9 )
          break;
        LODWORD(v7) = v7 + 1;
        v10 = (v9 + 3) & 0x1FFFC;
        v6 -= v10;
        v8 = (unsigned __int16 *)((char *)v8 + v10);
      }
      while ( v6 > 3 );
    }
    v39 = a2[7];
    v12 = 400LL * (unsigned int)v7 + 16;
    v13 = _kmalloc_noprof(v12, 3520);
    if ( v13 )
    {
LABEL_15:
      v14 = a2[4];
      *(_DWORD *)(v13 + 8) = v7;
      v40 = (__int64 *)v13;
      v15 = *(_QWORD *)(v14 + 48);
      if ( v15 )
      {
        v14 = a2[4];
        *(_QWORD *)v13 = v15 + 4;
      }
      v16 = *(_WORD **)(v14 + 2280);
      v17 = (unsigned __int16)(*v16 - 4);
      if ( (unsigned int)v17 >= 4 )
      {
        v18 = v16 + 2;
        v19 = 0;
        v38 = v13 + 16;
        _ReadStatusReg(SP_EL0);
        do
        {
          v20 = *v18;
          if ( v20 < 4 || v17 < v20 )
            break;
          if ( ((__int16)v18[1] & 0x80000000) == 0 )
          {
            do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_90:
            v21 = -22;
            goto LABEL_91;
          }
          v21 = _nla_parse(v41, 13, v18 + 2, (unsigned __int16)(v20 - 4), 0, 31, 0);
          if ( v21 )
            goto LABEL_91;
          if ( !v43 )
            goto LABEL_90;
          v7 = 400LL * v19;
          if ( v12 <= v7 + 16 )
            goto LABEL_95;
          v22 = v42;
          v23 = v38 + 400LL * v19;
          v24 = (_QWORD *)a2[8];
          v25 = *v40;
          *(_BYTE *)v23 = v42 != 0;
          if ( v12 <= v7 + 17 )
            goto LABEL_95;
          *(_BYTE *)(v23 + 1) = *(_WORD *)(v43 + 4);
          if ( v22 )
          {
            if ( !*(_QWORD *)(*(_QWORD *)v4 + 920LL) )
              goto LABEL_90;
            v26 = *(__int64 (__fastcall **)(unsigned __int8 *, __int64, __int64))(*(_QWORD *)v4 + 920LL);
            if ( *((_DWORD *)v26 - 1) != 2016414089 )
              __break(0x8228u);
            v21 = v26(v4 + 992, v39, v25);
            if ( v21 )
              goto LABEL_91;
          }
          if ( v44 )
          {
            if ( v12 < v7 + 24 )
              goto LABEL_95;
            if ( v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            *(_QWORD *)(v23 + 8) |= 0x40uLL;
            if ( v12 < v7 + 32 || v12 - (v7 + 32) < 4 )
              goto LABEL_95;
            *(_DWORD *)(v23 + 16) = *(unsigned __int8 *)(v44 + 4);
          }
          if ( v45 )
          {
            if ( v12 < v7 + 24 )
              goto LABEL_95;
            if ( v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            *(_QWORD *)(v23 + 8) |= 0x80uLL;
            if ( v12 <= v7 + 37 )
              goto LABEL_95;
            v27 = *(unsigned __int8 *)(v45 + 4);
            *(_BYTE *)(v23 + 21) = v27;
            if ( v27 > v4[2456] )
              goto LABEL_90;
          }
          if ( v46 )
          {
            if ( v12 < v7 + 24 )
              goto LABEL_95;
            if ( v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            *(_QWORD *)(v23 + 8) |= 0x100uLL;
            if ( v12 <= v7 + 36 )
              goto LABEL_95;
            v28 = *(unsigned __int8 *)(v46 + 4);
            *(_BYTE *)(v23 + 20) = v28;
            if ( v28 > v4[2456] )
              goto LABEL_90;
          }
          if ( v47 )
          {
            if ( v12 < v7 + 24 )
              goto LABEL_95;
            if ( v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            *(_QWORD *)(v23 + 8) |= 0x200uLL;
            if ( v12 < v7 + 40 || v12 - (v7 + 40) < 4 )
              goto LABEL_95;
            *(_DWORD *)(v23 + 24) = *(unsigned __int8 *)(v47 + 4);
          }
          if ( v48 )
          {
            if ( v12 < v7 + 24 )
              goto LABEL_95;
            if ( v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            *(_QWORD *)(v23 + 8) |= 0x400uLL;
            if ( v12 < v7 + 44 || v12 - (v7 + 44) < 4 )
              goto LABEL_95;
            *(_DWORD *)(v23 + 28) = *(unsigned __int8 *)(v48 + 4);
          }
          if ( v49 )
          {
            if ( v12 < v7 + 24 )
              goto LABEL_95;
            if ( v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            *(_QWORD *)(v23 + 8) |= 0x800uLL;
            if ( v12 < v7 + 48 || v12 - (v7 + 48) < 4 )
              goto LABEL_95;
            *(_DWORD *)(v23 + 32) = *(unsigned __int8 *)(v49 + 4);
          }
          if ( v50 )
          {
            if ( v12 < v7 + 52 || v12 - (v7 + 52) < 4 )
              goto LABEL_95;
            v29 = *(unsigned __int8 *)(v50 + 4);
            *(_DWORD *)(v23 + 36) = v29;
            if ( v29 )
            {
              v21 = nl80211_parse_tx_bitrate_mask((int)a2, (int)v41, 13, (void *)(v23 + 40));
              if ( v21 )
                goto LABEL_91;
              if ( v12 < v7 + 24 || v12 - (v7 + 24) < 8 )
              {
LABEL_95:
                __break(1u);
                StatusReg = _ReadStatusReg(SP_EL0);
                v37 = *(_QWORD *)(StatusReg + 80);
                *(_QWORD *)(StatusReg + 80) = &nl80211_set_tid_config__alloc_tag;
                v12 = 400LL * (unsigned int)v7 + 16;
                v13 = _kmalloc_noprof(v12, 3520);
                *(_QWORD *)(StatusReg + 80) = v37;
                if ( v13 )
                  goto LABEL_15;
                goto LABEL_96;
              }
              v30 = *(_QWORD *)(v23 + 8) | 0x2000LL;
            }
            else
            {
              if ( v12 < v7 + 24 || v12 - (v7 + 24) < 8 )
                goto LABEL_95;
              v30 = *(_QWORD *)(v23 + 8);
            }
            if ( v12 < v7 + 24 || v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            v31 = v30 | 0x1000;
            *(_QWORD *)(v23 + 8) = v31;
          }
          else
          {
            if ( v12 < v7 + 24 || v12 - (v7 + 24) < 8 )
              goto LABEL_95;
            v31 = *(_QWORD *)(v23 + 8);
          }
          v32 = 2432;
          if ( !v25 )
            v32 = 2440;
          if ( (v31 & ~*(_QWORD *)&v4[v32]) != 0 )
          {
            do_trace_netlink_extack("unsupported TID configuration");
            if ( v24 )
              *v24 = "unsupported TID configuration";
            v21 = -95;
            goto LABEL_91;
          }
          ++v19;
          v33 = (*v18 + 3) & 0x1FFFC;
          v17 -= v33;
          v18 = (unsigned __int16 *)((char *)v18 + v33);
        }
        while ( v17 > 3 );
      }
      v34 = *(__int64 (__fastcall **)(unsigned __int8 *, __int64, __int64 *))(*(_QWORD *)v4 + 912LL);
      if ( *((_DWORD *)v34 - 1) != 226879218 )
        __break(0x8228u);
      v21 = v34(v4 + 992, v39, v40);
LABEL_91:
      v35 = v21;
      kfree(v40);
      result = v35;
    }
    else
    {
LABEL_96:
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967201LL;
  }
LABEL_97:
  _ReadStatusReg(SP_EL0);
  return result;
}
