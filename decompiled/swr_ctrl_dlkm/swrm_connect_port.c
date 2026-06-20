__int64 __fastcall swrm_connect_port(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x20
  unsigned __int64 v5; // x8
  __int64 v6; // x25
  unsigned __int8 *v7; // x26
  __int64 v8; // x23
  unsigned __int8 *v9; // x28
  unsigned int master_port; // w0
  unsigned int v11; // w27
  __int64 *v12; // x22
  __int64 *v13; // x8
  __int64 v14; // x0
  unsigned __int8 v15; // w9
  unsigned __int8 v16; // w10
  int v17; // w11
  int v18; // w8
  int v19; // w8
  _QWORD *v20; // x2
  __int64 v21; // x8
  __int64 v22; // x8
  char v23; // w9
  char v24; // w10
  int v25; // w9
  int v26; // w8
  int v27; // w8
  __int64 v28; // x9
  unsigned int v29; // w22
  __int64 result; // x0
  unsigned __int64 v37; // x9
  char v38[4]; // [xsp+30h] [xbp-10h] BYREF
  char v39[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    if ( a2 )
    {
LABEL_52:
      if ( (unsigned int)__ratelimit(&swrm_connect_port__rs, "swrm_connect_port") )
        dev_err(a1, "%s: Invalid handle to swr controller\n", "swrm_connect_port");
    }
LABEL_55:
    result = 4294967274LL;
    goto LABEL_56;
  }
  v4 = *(_QWORD *)(a1 + 152);
  v39[0] = 0;
  v38[0] = 0;
  if ( !a2 )
    goto LABEL_55;
  if ( !v4 )
    goto LABEL_52;
  mutex_lock(v4 + 8784);
  mutex_lock(v4 + 8736);
  if ( (*(_BYTE *)(v4 + 15748) & 1) == 0 )
  {
    swr_port_response(a1, *a2);
    mutex_unlock(v4 + 8736);
    mutex_unlock(v4 + 8784);
    goto LABEL_55;
  }
  mutex_unlock(v4 + 8736);
  if ( !*(_BYTE *)(a1 + 8409) )
    _pm_runtime_resume(*(_QWORD *)(v4 + 8512), 4);
  LOBYTE(v5) = a2[2];
  if ( !(_BYTE)v5 )
  {
LABEL_60:
    *(_BYTE *)(a1 + 8409) += v5;
    _X8 = (unsigned __int64 *)(v4 + 15328);
    __asm { PRFM            #0x11, [X8] }
    do
      v37 = __ldxr(_X8);
    while ( __stxr(v37 | 1, _X8) );
    swr_port_response(a1, *a2);
    mutex_unlock(v4 + 8784);
    result = 0;
    goto LABEL_56;
  }
  v6 = 0;
  v7 = a2 + 3;
  v8 = v4 + 9152;
  v9 = a2 + 32;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( v6 == 14 )
LABEL_61:
      __break(0x5512u);
    master_port = swrm_get_master_port(v4, v39, v38, a2[v6 + 102]);
    if ( master_port )
      break;
    v11 = (unsigned __int8)v39[0];
    if ( (unsigned __int8)v39[0] > 0x9Au )
      goto LABEL_61;
    v12 = (__int64 *)(v8 + 40LL * (unsigned __int8)v39[0]);
    v13 = (__int64 *)*v12;
    if ( (__int64 *)*v12 == v12 )
      goto LABEL_20;
    while ( *((unsigned __int8 *)v13 - 6) != v7[v6] || *((unsigned __int8 *)v13 - 8) != a2[1] )
    {
      v13 = (__int64 *)*v13;
      if ( v13 == v12 )
        goto LABEL_20;
    }
    v14 = (__int64)(v13 - 1);
    if ( v13 == (__int64 *)&unk_8 )
    {
LABEL_20:
      v14 = _kmalloc_cache_noprof(_irq_resolve_mapping, 3520, 48);
      if ( !v14 )
      {
        v29 = -12;
        goto LABEL_59;
      }
      v15 = v7[v6];
      *(_BYTE *)v14 = a2[1];
      v16 = a2[v6 + 17];
      *(_BYTE *)(v14 + 2) = v15;
      v17 = *(_DWORD *)&a2[4 * v6 + 116];
      v18 = *(_DWORD *)&v9[4 * v6];
      *(_BYTE *)(v14 + 33) = v16;
      *(_DWORD *)(v14 + 36) = v18;
      *(_DWORD *)(v14 + 40) = v18;
      *(_BYTE *)(v14 + 29) = v17 - ((unsigned __int8)v17 != 0);
      if ( v18 > 176399 )
      {
        if ( v18 == 176400 )
        {
          v19 = 192000;
        }
        else
        {
          if ( v18 != 352800 )
            goto LABEL_31;
          v19 = 384000;
        }
      }
      else
      {
        if ( v18 != 44100 )
        {
          if ( v18 == 88200 )
          {
            v19 = 96000;
            goto LABEL_30;
          }
LABEL_31:
          *(_BYTE *)(v14 + 31) = 0;
          *(_BYTE *)(v14 + 24) = v11;
          v20 = (_QWORD *)*v12;
          v21 = v14 + 8;
          if ( *(__int64 **)(*v12 + 8) != v12 || (__int64 *)v21 == v12 || v20 == (_QWORD *)v21 )
          {
            _list_add_valid_or_report(v14 + 8, v8 + 40LL * v11);
            v11 = (unsigned __int8)v39[0];
            v14 = v28;
          }
          else
          {
            v20[1] = v21;
            *(_QWORD *)(v14 + 8) = v20;
            *(_QWORD *)(v14 + 16) = v12;
            *v12 = v21;
          }
          goto LABEL_35;
        }
        v19 = 48000;
      }
LABEL_30:
      *(_DWORD *)(v14 + 36) = v19;
      goto LABEL_31;
    }
LABEL_35:
    *(_BYTE *)(v14 + 32) |= a2[v6 + 88];
    if ( v11 > 0x9A )
      goto LABEL_61;
    v22 = v8 + 40LL * v11;
    v23 = v38[0];
    v24 = *(_BYTE *)(v22 + 18);
    *(_BYTE *)(v22 + 16) = 1;
    *(_BYTE *)(v22 + 18) = v24 | v23;
    *(_WORD *)(a1 + 8504) |= 1 << v11;
    if ( *(_DWORD *)(v4 + 15704) && *(_DWORD *)(v4 + 9060) )
    {
      *(_DWORD *)(v22 + 32) += *(_DWORD *)&v9[4 * v6];
      v25 = *(_DWORD *)(v4 + 9224)
          + *(_DWORD *)(v4 + 9184)
          + *(_DWORD *)(v4 + 9264)
          + *(_DWORD *)(v4 + 9304)
          + *(_DWORD *)(v4 + 9344)
          + *(_DWORD *)(v4 + 9384)
          + *(_DWORD *)(v4 + 9424)
          + *(_DWORD *)(v4 + 9464)
          + *(_DWORD *)(v4 + 9504)
          + *(_DWORD *)(v4 + 9544)
          + *(_DWORD *)(v4 + 9584)
          + *(_DWORD *)(v4 + 9624)
          + *(_DWORD *)(v4 + 9664);
      v26 = *(_DWORD *)(v4 + 9132);
      if ( v25 && v26 != 12288000 && v26 != 11289600 )
      {
        if ( v26 == 9600000 )
        {
          v26 = 600000;
          if ( v25 >= 600001 )
          {
            if ( (unsigned int)v25 <= 0x493E00 )
              v27 = 4800000;
            else
              v27 = 9600000;
            *(_DWORD *)(v4 + 9136) = v27;
            goto LABEL_10;
          }
        }
        else
        {
          v26 = *(_DWORD *)(v4 + 9224)
              + *(_DWORD *)(v4 + 9184)
              + *(_DWORD *)(v4 + 9264)
              + *(_DWORD *)(v4 + 9304)
              + *(_DWORD *)(v4 + 9344)
              + *(_DWORD *)(v4 + 9384)
              + *(_DWORD *)(v4 + 9424)
              + *(_DWORD *)(v4 + 9464)
              + *(_DWORD *)(v4 + 9504)
              + *(_DWORD *)(v4 + 9544)
              + *(_DWORD *)(v4 + 9584)
              + *(_DWORD *)(v4 + 9624)
              + *(_DWORD *)(v4 + 9664);
        }
      }
      *(_DWORD *)(v4 + 9136) = v26;
    }
    else
    {
      *(_DWORD *)(v22 + 32) = *(_DWORD *)&v9[4 * v6];
    }
LABEL_10:
    v5 = a2[2];
    if ( ++v6 >= v5 )
      goto LABEL_60;
  }
  v29 = master_port;
  if ( (unsigned int)__ratelimit(&swrm_connect_port__rs_153, "swrm_connect_port") )
    dev_err(a1, "%s: mstr portid for slv port %d not found\n", "swrm_connect_port", v7[v6]);
LABEL_59:
  swr_port_response(a1, *a2);
  swrm_cleanup_disabled_port_reqs(a1);
  mutex_unlock(v4 + 8784);
  result = v29;
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
