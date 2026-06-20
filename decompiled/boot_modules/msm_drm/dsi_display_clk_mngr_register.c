__int64 __fastcall dsi_display_clk_mngr_register(__int64 a1, int a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  unsigned int v6; // w8
  int v7; // w9
  __int64 v8; // x10
  __int64 v9; // x11
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x10
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x8
  __int64 v28; // x10
  __int64 v29; // x8
  __int64 v30; // x8

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return -22;
  }
  v4 = _kmalloc_cache_noprof(msleep, 3520, 456);
  v5 = v4;
  if ( !v4 )
  {
    v5 = -12;
    goto LABEL_13;
  }
  _mutex_init(v4 + 32, "&mngr->clk_mutex", &dsi_display_clk_mngr_register___key);
  v6 = *(_DWORD *)(a1 + 300);
  v7 = *(_DWORD *)(a1 + 296);
  *(_DWORD *)(v5 + 96) = v6;
  *(_DWORD *)(v5 + 100) = v7;
  if ( a2 != 1 )
  {
    *(_DWORD *)(v5 + 384) = a2;
    if ( v6 > 2 )
    {
      kfree(v5);
      return -22;
    }
    if ( v6 )
    {
      v8 = *(_QWORD *)(a1 + 72);
      v9 = *(_QWORD *)(a1 + 80);
      *(_QWORD *)(v5 + 136) = *(_QWORD *)(a1 + 64);
      *(_QWORD *)(v5 + 144) = v8;
      v10 = *(_QWORD *)(a1 + 32);
      v11 = *(_QWORD *)(a1 + 40);
      *(_QWORD *)(v5 + 152) = v9;
      *(_QWORD *)(v5 + 104) = v10;
      *(_QWORD *)(v5 + 112) = v11;
      v12 = *(_QWORD *)(a1 + 56);
      *(_QWORD *)(v5 + 120) = *(_QWORD *)(a1 + 48);
      *(_QWORD *)(v5 + 128) = v12;
      v13 = *(_QWORD *)(a1 + 168);
      v14 = *(_QWORD *)(a1 + 176);
      *(_QWORD *)(v5 + 216) = *(_QWORD *)(a1 + 160);
      *(_QWORD *)(v5 + 224) = v13;
      v15 = *(_QWORD *)(a1 + 144);
      v16 = *(_QWORD *)(a1 + 208);
      *(_QWORD *)(v5 + 232) = v14;
      *(_QWORD *)(v5 + 240) = v15;
      LODWORD(v14) = *(_DWORD *)(a1 + 232);
      *(_QWORD *)(v5 + 312) = v16;
      *(_DWORD *)(v5 + 360) = v14;
      if ( v6 == 2 )
      {
        v17 = *(_QWORD *)(a1 + 120);
        v18 = *(_QWORD *)(a1 + 128);
        *(_QWORD *)(v5 + 208) = *(_QWORD *)(a1 + 136);
        *(_QWORD *)(v5 + 192) = v17;
        *(_QWORD *)(v5 + 200) = v18;
        v19 = *(_QWORD *)(a1 + 96);
        *(_QWORD *)(v5 + 160) = *(_QWORD *)(a1 + 88);
        *(_QWORD *)(v5 + 168) = v19;
        v20 = *(_QWORD *)(a1 + 112);
        *(_QWORD *)(v5 + 176) = *(_QWORD *)(a1 + 104);
        *(_QWORD *)(v5 + 184) = v20;
        v21 = *(_QWORD *)(a1 + 192);
        v22 = *(_QWORD *)(a1 + 200);
        *(_QWORD *)(v5 + 264) = *(_QWORD *)(a1 + 184);
        *(_QWORD *)(v5 + 272) = v21;
        v23 = *(_QWORD *)(a1 + 152);
        v24 = *(_QWORD *)(a1 + 216);
        *(_QWORD *)(v5 + 280) = v22;
        *(_QWORD *)(v5 + 288) = v23;
        LODWORD(v22) = *(_DWORD *)(a1 + 236);
        *(_QWORD *)(v5 + 328) = v24;
        *(_DWORD *)(v5 + 364) = v22;
      }
    }
    *(_QWORD *)(v5 + 344) = *(_QWORD *)(a1 + 224);
    *(_QWORD *)(v5 + 80) = v5 + 80;
    *(_QWORD *)(v5 + 88) = v5 + 80;
    v25 = *(_QWORD *)(a1 + 264);
    *(_QWORD *)(v5 + 424) = *(_QWORD *)(a1 + 256);
    *(_QWORD *)(v5 + 432) = v25;
    v26 = *(_QWORD *)(a1 + 248);
    *(_QWORD *)(v5 + 408) = *(_QWORD *)(a1 + 240);
    *(_QWORD *)(v5 + 416) = v26;
    v27 = *(_QWORD *)(a1 + 280);
    v28 = *(_QWORD *)(a1 + 288);
    *(_QWORD *)(v5 + 392) = *(_QWORD *)(a1 + 272);
    *(_QWORD *)(v5 + 400) = v27;
    LOBYTE(v27) = *(_BYTE *)(a1 + 304);
    *(_QWORD *)(v5 + 448) = v28;
    *(_BYTE *)(v5 + 441) = v27;
    v29 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)v5 = *(_QWORD *)a1;
    *(_QWORD *)(v5 + 8) = v29;
    v30 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(v5 + 16) = *(_QWORD *)(a1 + 16);
    *(_QWORD *)(v5 + 24) = v30;
LABEL_13:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: EXIT, rc = %ld\n", v5);
    return v5;
  }
  *(_DWORD *)(v5 + 384) = 1;
  return v5;
}
