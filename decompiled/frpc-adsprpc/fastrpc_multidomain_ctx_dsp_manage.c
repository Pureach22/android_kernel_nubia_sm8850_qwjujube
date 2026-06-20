__int64 __fastcall fastrpc_multidomain_ctx_dsp_manage(__int64 a1, int a2, __int64 a3, _QWORD *a4, unsigned int a5)
{
  int v6; // w22
  unsigned int v7; // w28
  _DWORD *v8; // x8
  unsigned int v9; // w26
  int v10; // w19
  __int64 i; // x8
  int *v12; // x9
  __int64 v13; // x8
  __int64 *v14; // x21
  __int64 v15; // x25
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x21
  int v23; // w8
  __int64 v24; // x1
  unsigned int v30; // w8
  __int64 v32; // [xsp+8h] [xbp-158h]
  __int64 v34; // [xsp+18h] [xbp-148h]
  __int64 v38; // [xsp+38h] [xbp-128h] BYREF
  __int64 v39; // [xsp+40h] [xbp-120h]
  unsigned __int64 v40; // [xsp+48h] [xbp-118h]
  __int64 v41; // [xsp+50h] [xbp-110h]
  __int64 v42; // [xsp+58h] [xbp-108h]
  __int64 *v43; // [xsp+60h] [xbp-100h] BYREF
  __int64 v44; // [xsp+68h] [xbp-F8h]
  __int64 v45; // [xsp+70h] [xbp-F0h]
  __int64 v46; // [xsp+78h] [xbp-E8h]
  __int64 v47; // [xsp+80h] [xbp-E0h]
  __int64 v48; // [xsp+88h] [xbp-D8h]
  __int64 v49; // [xsp+90h] [xbp-D0h]
  __int64 v50; // [xsp+98h] [xbp-C8h]
  __int64 v51; // [xsp+A0h] [xbp-C0h]
  __int64 v52; // [xsp+A8h] [xbp-B8h]
  __int64 v53; // [xsp+B0h] [xbp-B0h]
  __int64 v54; // [xsp+B8h] [xbp-A8h]
  __int64 v55; // [xsp+C0h] [xbp-A0h]
  __int64 v56; // [xsp+C8h] [xbp-98h]
  __int64 v57; // [xsp+D0h] [xbp-90h]
  _QWORD v58[17]; // [xsp+D8h] [xbp-88h] BYREF

  v58[15] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a5 )
  {
    v7 = 0;
    goto LABEL_42;
  }
  v6 = 0;
  v7 = 0;
  v34 = 4LL * a5;
  v32 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL);
  while ( 2 )
  {
    v8 = (_DWORD *)a4[2];
    v9 = v8[v6];
    if ( v6 < 1 || v9 != *v8 )
    {
      v10 = v8[v6];
      if ( v9 <= 4 )
      {
        mutex_lock(&unk_26CD8);
        for ( i = 0; i != 256; ++i )
        {
          v12 = &g_frpc[2 * i + 26];
          while ( 1 )
          {
            v12 = *(int **)v12;
            if ( !v12 )
              break;
            if ( v12[18] == v9 )
            {
              v10 = v12[4];
              mutex_unlock(&unk_26CD8);
              v7 = 0;
              goto LABEL_15;
            }
          }
        }
        mutex_unlock(&unk_26CD8);
        v7 = -22;
        dev_err(
          v32,
          "Error %d: %s: failed to get logical id for domain %u",
          -22,
          "fastrpc_multidomain_ctx_dsp_manage",
          v9);
        break;
      }
LABEL_15:
      mutex_lock(&unk_26CD8);
      v13 = 0;
      while ( 1 )
      {
        v14 = *(__int64 **)&g_frpc[2 * v13 + 26];
        if ( v14 )
          break;
LABEL_16:
        if ( ++v13 == 256 )
        {
          mutex_unlock(&unk_26CD8);
          goto LABEL_4;
        }
      }
      while ( *((_DWORD *)v14 + 4) != v10 )
      {
        v14 = (__int64 *)*v14;
        if ( !v14 )
          goto LABEL_16;
      }
      mutex_unlock(&unk_26CD8);
      v15 = v14[22];
      if ( v15 )
      {
        _X0 = (unsigned int *)(v15 + 51664);
        memset(&v58[2], 0, 104);
        v56 = 0;
        v57 = 0;
        v54 = 0;
        v55 = 0;
        v52 = 0;
        v53 = 0;
        v50 = 0;
        v51 = 0;
        v48 = 0;
        v49 = 0;
        v46 = 0;
        v47 = 0;
        v44 = 0;
        v45 = 0;
        v42 = 0;
        v43 = nullptr;
        v40 = 0;
        v41 = 0;
        v38 = 0;
        v39 = 0;
        __asm { PRFM            #0x11, [X0] }
        do
          v30 = __ldxr(_X0);
        while ( __stxr(v30 + 1, _X0) );
        if ( v30 )
        {
          if ( (((v30 + 1) | v30) & 0x80000000) == 0 )
            goto LABEL_24;
          v24 = 1;
        }
        else
        {
          v24 = 2;
        }
        refcount_warn_saturate(_X0, v24);
LABEL_24:
        if ( *(_DWORD *)(v15 + 64136) )
        {
          v7 = -32;
        }
        else
        {
          v17 = raw_spin_lock_irqsave(v15 + 51600);
          ++*(_DWORD *)(v15 + 64180);
          raw_spin_unlock_irqrestore(v15 + 51600, v17);
          v40 = __PAIR64__(a5, v6);
          LODWORD(v38) = a2;
          LODWORD(v41) = a5;
          HIDWORD(v41) = a5;
          LODWORD(v45) = -1;
          v39 = a3;
          v43 = &v38;
          v44 = 40;
          v19 = a4[3];
          v18 = a4[4];
          LODWORD(v48) = -1;
          LODWORD(v51) = -1;
          v46 = v18;
          v47 = v34;
          v20 = a4[6];
          v49 = v19;
          v50 = v34;
          v52 = v20;
          v53 = v34;
          LODWORD(v54) = -1;
          v21 = *(_QWORD *)(v15 + 64248);
          v58[0] = 0xC05000000000001LL;
          v58[1] = &v43;
          v7 = fastrpc_internal_invoke(v21, 1, v58);
          v22 = raw_spin_lock_irqsave(v15 + 51600);
          v23 = *(_DWORD *)(v15 + 64180) - 1;
          *(_DWORD *)(v15 + 64180) = v23;
          if ( !v23 )
            _wake_up(v15 + 64216, 1, 1, 0);
          raw_spin_unlock_irqrestore(v15 + 51600, v22);
        }
        fastrpc_channel_ctx_put(v15);
        if ( a2 != 1 && v7 )
        {
          dev_err(
            v32,
            "Error 0x%x: %s: failed to register ctx on domain[%d of %d] %u",
            v7,
            "fastrpc_multidomain_ctx_dsp_manage",
            v6 + 1,
            a5,
            v9);
          break;
        }
        goto LABEL_5;
      }
LABEL_4:
      if ( a2 != 1 )
      {
        v7 = -32;
        dev_err(
          v32,
          "Error %d: %s: remote channel is down for domain[%d of %d] %u",
          -32,
          "fastrpc_multidomain_ctx_dsp_manage",
          v6 + 1,
          a5,
          v9);
        break;
      }
LABEL_5:
      if ( ++v6 != a5 )
        continue;
      v6 = a5;
    }
    break;
  }
  if ( !a2 && v7 )
    fastrpc_multidomain_ctx_dsp_manage(a1, 1, a3, a4, (unsigned int)v6);
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v7;
}
