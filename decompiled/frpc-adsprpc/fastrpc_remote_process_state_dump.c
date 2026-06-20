__int64 __fastcall fastrpc_remote_process_state_dump(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x8
  unsigned int v5; // w22
  unsigned int v6; // w23
  unsigned int v7; // w24
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 *v10; // x9
  __int64 v11; // x8
  int *v12; // x9
  unsigned int frpc_tgid; // w0
  unsigned int v14; // w25
  unsigned int v15; // w9
  __int64 v16; // x20
  __int64 v17; // x9
  __int64 v18; // x10
  const char *v20; // x1
  __int64 v21; // x0
  __int64 v22; // x4
  int v28; // w8
  unsigned __int64 v30; // [xsp+10h] [xbp-E0h] BYREF
  int v31; // [xsp+18h] [xbp-D8h]
  __int64 v32; // [xsp+20h] [xbp-D0h] BYREF
  __int64 v33; // [xsp+28h] [xbp-C8h]
  __int64 v34; // [xsp+30h] [xbp-C0h] BYREF
  int v35; // [xsp+3Ch] [xbp-B4h] BYREF
  unsigned __int64 *v36; // [xsp+40h] [xbp-B0h] BYREF
  __int64 v37; // [xsp+48h] [xbp-A8h]
  __int64 v38; // [xsp+50h] [xbp-A0h]
  __int64 *v39; // [xsp+58h] [xbp-98h]
  __int64 v40; // [xsp+60h] [xbp-90h]
  __int64 v41; // [xsp+68h] [xbp-88h]
  __int64 v42; // [xsp+70h] [xbp-80h] BYREF
  unsigned __int64 **v43; // [xsp+78h] [xbp-78h]
  __int64 v44; // [xsp+80h] [xbp-70h]
  __int64 v45; // [xsp+88h] [xbp-68h]
  __int64 v46; // [xsp+90h] [xbp-60h]
  __int64 v47; // [xsp+98h] [xbp-58h]
  __int64 v48; // [xsp+A0h] [xbp-50h]
  __int64 v49; // [xsp+A8h] [xbp-48h]
  __int64 v50; // [xsp+B0h] [xbp-40h]
  __int64 v51; // [xsp+B8h] [xbp-38h]
  __int64 v52; // [xsp+C0h] [xbp-30h]
  __int64 v53; // [xsp+C8h] [xbp-28h]
  __int64 v54; // [xsp+D0h] [xbp-20h]
  __int64 v55; // [xsp+D8h] [xbp-18h]
  __int64 v56; // [xsp+E0h] [xbp-10h]
  __int64 v57; // [xsp+E8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 128);
  v5 = a2[3];
  v35 = -1;
  v6 = *a2;
  v7 = a2[1];
  v8 = *(_QWORD *)(v4 + 168);
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = nullptr;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = nullptr;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v36 = nullptr;
  v33 = 0;
  v34 = 0;
  v32 = 0;
  v31 = 0;
  v30 = 0;
  mutex_lock(&unk_26CD8);
  v9 = 0;
  while ( 1 )
  {
    v10 = *(__int64 **)&g_frpc[2 * v9 + 26];
    if ( v10 )
      break;
LABEL_2:
    if ( ++v9 == 256 )
    {
      mutex_unlock(&unk_26CD8);
      if ( v6 > 4 )
      {
        v20 = "Error %d: %s: %u is not a valid logical domain id";
      }
      else
      {
        mutex_lock(&unk_26CD8);
        v11 = 0;
        while ( 2 )
        {
          v12 = &g_frpc[2 * v11 + 26];
          while ( 1 )
          {
            v12 = *(int **)v12;
            if ( !v12 )
              break;
            if ( v12[18] == v6 )
            {
              v6 = v12[4];
              goto LABEL_14;
            }
          }
          if ( ++v11 != 256 )
            continue;
          break;
        }
        mutex_unlock(&unk_26CD8);
        v20 = "Error %d: %s: no domain found for legacy domain id %u";
      }
      v21 = v8;
      v22 = v6;
      goto LABEL_21;
    }
  }
  while ( *((_DWORD *)v10 + 4) != v6 )
  {
    v10 = (__int64 *)*v10;
    if ( !v10 )
      goto LABEL_2;
  }
LABEL_14:
  mutex_unlock(&unk_26CD8);
  if ( v7 >= 4 )
  {
    v20 = "Error %d: %s: session %u is invalid";
    v21 = v8;
    v22 = v7;
LABEL_21:
    v14 = -53;
    dev_err(v21, v20, 4294967243LL, "fastrpc_remote_process_state_dump", v22);
    goto LABEL_32;
  }
  frpc_tgid = fastrpc_get_frpc_tgid(v6, v7, &v35);
  if ( frpc_tgid )
  {
    v14 = frpc_tgid;
    dev_err(
      v8,
      "Error %d: %s: failed to get frpc tgid for domain %u, session %u",
      frpc_tgid,
      "fastrpc_remote_process_state_dump",
      v6,
      v7);
  }
  else
  {
    mutex_lock(a1 + 328);
    v14 = fastrpc_map_create(a1, v5, 0, 0, a2[4], 0, 0, &v34, 1u);
    mutex_unlock(a1 + 328);
    if ( v14 )
    {
      dev_err(
        v8,
        "Error %d: %s: smmu map failed for log-buf fd %d, size %u",
        v14,
        "fastrpc_remote_process_state_dump",
        v5,
        a2[4]);
    }
    else
    {
      v15 = a2[2];
      v16 = v34;
      v31 = 1;
      v30 = __PAIR64__(v15, v35);
      v36 = &v30;
      v37 = 12;
      v17 = *(_QWORD *)(v34 + 64);
      v18 = *(_QWORD *)(v34 + 72);
      LODWORD(v38) = -1;
      v32 = v17;
      v33 = v18;
      LODWORD(v41) = -1;
      v39 = &v32;
      v40 = 16;
      v42 = 0xD02000000000001LL;
      v43 = &v36;
      v14 = fastrpc_internal_invoke(a1, 1u, (int *)&v42);
      if ( v16 )
      {
        mutex_lock(a1 + 328);
        _X0 = (unsigned int *)(v16 + 112);
        __asm { PRFM            #0x11, [X0] }
        do
          v28 = __ldxr(_X0);
        while ( __stlxr(v28 - 1, _X0) );
        if ( v28 == 1 )
        {
          __dmb(9u);
          _fastrpc_free_map(v16);
        }
        else if ( v28 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
        mutex_unlock(a1 + 328);
      }
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v14;
}
