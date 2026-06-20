__int64 __fastcall dsi_panel_get_host_cfg_for_mode(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x11
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v17; // x10
  _QWORD *v18; // x8

  if ( a1 && a2 && a3 )
  {
    mutex_lock(a1 + 1040);
    *(_DWORD *)a3 = *(_DWORD *)(a1 + 1352);
    v6 = *(_QWORD *)(a1 + 1240);
    v7 = *(_QWORD *)(a1 + 1224);
    v8 = *(_QWORD *)(a1 + 1232);
    *(_QWORD *)(a3 + 28) = *(_QWORD *)(a1 + 1248);
    *(_QWORD *)(a3 + 20) = v6;
    *(_QWORD *)(a3 + 12) = v8;
    *(_QWORD *)(a3 + 4) = v7;
    v9 = *(_QWORD *)(a1 + 1272);
    v10 = *(_QWORD *)(a1 + 1256);
    v11 = *(_QWORD *)(a1 + 1264);
    *(_QWORD *)(a3 + 60) = *(_QWORD *)(a1 + 1280);
    *(_QWORD *)(a3 + 52) = v9;
    *(_QWORD *)(a3 + 44) = v11;
    *(_QWORD *)(a3 + 36) = v10;
    v12 = *(_QWORD *)(a1 + 1304);
    v13 = *(_QWORD *)(a1 + 1288);
    v14 = *(_QWORD *)(a1 + 1296);
    *(_DWORD *)(a3 + 92) = *(_DWORD *)(a1 + 1312);
    *(_QWORD *)(a3 + 84) = v12;
    *(_QWORD *)(a3 + 76) = v14;
    *(_QWORD *)(a3 + 68) = v13;
    if ( *(_DWORD *)(a1 + 1352) == 1 )
    {
      v15 = *(_QWORD *)(a1 + 1316);
      *(_QWORD *)(a3 + 104) = *(_QWORD *)(a1 + 1324);
    }
    else
    {
      v15 = *(_QWORD *)(a1 + 1332);
      v17 = *(_QWORD *)(a1 + 1340);
      *(_DWORD *)(a3 + 112) = *(_DWORD *)(a1 + 1348);
      *(_QWORD *)(a3 + 104) = v17;
    }
    *(_QWORD *)(a3 + 96) = v15;
    memcpy((void *)(a3 + 152), a2, 0x98u);
    *(_DWORD *)(a3 + 216) = *(_DWORD *)(a2[23] + 2384LL);
    *(_BYTE *)(a3 + 224) = *(_BYTE *)(a2[23] + 3400LL);
    *(_QWORD *)(a3 + 232) = a2[23] + 2496LL;
    *(_BYTE *)(a3 + 225) = *(_BYTE *)(a2[23] + 3401LL);
    *(_QWORD *)(a3 + 240) = a2[23] + 2712LL;
    *(_BYTE *)(a3 + 144) = *(_BYTE *)(a1 + 2024);
    if ( *(_BYTE *)(a1 + 1392) == 1 )
      v18 = a2 + 6;
    else
      v18 = (_QWORD *)(a2[23] + 2408LL);
    *(_QWORD *)(a3 + 136) = *v18;
    *(_QWORD *)(a3 + 120) = 19200000;
    mutex_unlock(a1 + 1040);
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
}
