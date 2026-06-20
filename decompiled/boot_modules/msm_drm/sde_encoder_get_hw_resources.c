void *__fastcall sde_encoder_get_hw_resources(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w8
  __int64 v7; // x0
  void (*v8)(void); // x9
  __int64 v9; // x0
  void (*v10)(void); // x9
  __int64 v11; // x0
  void (*v12)(void); // x9
  __int64 v13; // x0
  void (*v14)(void); // x9
  void *v15; // x0
  __int64 v16; // x9

  if ( !a1 || !a2 || !a3 || !*(_QWORD *)(a2 + 88) )
    return (void *)printk(&unk_238250, "sde_encoder_get_hw_resources");
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a1 + 188);
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a1 + 696);
  v6 = *(_DWORD *)(a1 + 196);
  if ( !v6 )
    goto LABEL_32;
  v7 = *(_QWORD *)(a1 + 200);
  if ( v7 )
  {
    v8 = *(void (**)(void))(v7 + 96);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != -1257398115 )
        __break(0x8229u);
      v8();
      v6 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v6 < 2 )
    goto LABEL_32;
  v9 = *(_QWORD *)(a1 + 208);
  if ( v9 )
  {
    v10 = *(void (**)(void))(v9 + 96);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -1257398115 )
        __break(0x8229u);
      v10();
      v6 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v6 < 3 )
    goto LABEL_32;
  v11 = *(_QWORD *)(a1 + 216);
  if ( v11 )
  {
    v12 = *(void (**)(void))(v11 + 96);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -1257398115 )
        __break(0x8229u);
      v12();
      v6 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v6 < 4 )
    goto LABEL_32;
  v13 = *(_QWORD *)(a1 + 224);
  if ( v13 )
  {
    v14 = *(void (**)(void))(v13 + 96);
    if ( v14 )
    {
      if ( *((_DWORD *)v14 - 1) != -1257398115 )
        __break(0x8229u);
      v14();
      v6 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v6 > 4 )
  {
    __break(0x5512u);
    return (void *)sde_encoder_destroy();
  }
  else
  {
LABEL_32:
    v15 = *(void **)(a2 + 88);
    v16 = *(_QWORD *)(a3 + 2252);
    *(_QWORD *)(a2 + 72) = *(_QWORD *)(a3 + 2244);
    *(_QWORD *)(a2 + 80) = v16;
    if ( v15 )
    {
      return memcpy(v15, (const void *)(a3 + 2264), 0x2B0u);
    }
    else
    {
      printk(&unk_26FEB0, "sde_connector_state_get_compression_info");
      return (void *)printk(&unk_25E69F, "sde_encoder_get_hw_resources");
    }
  }
}
