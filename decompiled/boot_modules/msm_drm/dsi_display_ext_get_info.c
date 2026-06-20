__int64 __fastcall dsi_display_ext_get_info(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w0
  int v7; // w1
  int v8; // w2
  void *v9; // x3
  int v10; // w8
  const char *v11; // x21
  int v12; // w8

  if ( !a2 || !a3 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a3 + 264) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display panel\n");
    return 4294967274LL;
  }
  v6 = mutex_lock(a3 + 72);
  *(_QWORD *)(a2 + 144) = 0;
  *(_QWORD *)(a2 + 152) = 0;
  *(_QWORD *)(a2 + 128) = 0;
  *(_QWORD *)(a2 + 136) = 0;
  *(_QWORD *)(a2 + 112) = 0;
  *(_QWORD *)(a2 + 120) = 0;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 32) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  *(_QWORD *)(a2 + 24) = 0;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_DWORD *)a2 = 16;
  v10 = *(_DWORD *)(a3 + 160);
  *(_DWORD *)(a2 + 12) = v10;
  if ( !v10
    || (*(_DWORD *)(a2 + 16) = *(_DWORD *)(*(_QWORD *)(a3 + 168) + 8LL), v10 == 1)
    || (*(_DWORD *)(a2 + 20) = *(_DWORD *)(*(_QWORD *)(a3 + 216) + 8LL), v10 == 2) )
  {
    *(_BYTE *)(a2 + 24) = *(_DWORD *)(a1 + 192) != 2;
    v11 = *(const char **)(a3 + 40);
    if ( !strcmp(v11, "primary") )
    {
      v12 = 1;
    }
    else
    {
      if ( strcmp(v11, "secondary") )
      {
LABEL_15:
        *(_QWORD *)(a2 + 4) = 0x10000000DLL;
        mutex_unlock(a3 + 72);
        return 0;
      }
      v12 = 2;
    }
    *(_DWORD *)(a2 + 56) = v12;
    goto LABEL_15;
  }
  __break(0x5512u);
  return dsi_display_ext_get_mode_info(v6, v7, v8, v9);
}
