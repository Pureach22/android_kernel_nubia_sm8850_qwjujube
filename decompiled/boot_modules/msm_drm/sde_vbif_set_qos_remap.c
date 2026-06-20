void __fastcall sde_vbif_set_qos_remap(__int64 a1, int *a2)
{
  __int64 v4; // x8
  unsigned int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x19
  int v8; // w3
  unsigned int v9; // w9
  __int64 v10; // x8
  unsigned __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x12
  int v14; // w22
  __int64 v15; // x3
  __int64 v16; // x26
  __int64 v17; // x26
  int v18; // t1
  __int64 v19; // x0
  __int64 v20; // x8
  void (*v21)(void); // x8

  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 3528) )
  {
    printk(&unk_26FEB0, "sde_vbif_set_qos_remap");
    goto LABEL_50;
  }
  v4 = *(_QWORD *)(a1 + 152);
  if ( (*(_QWORD *)(v4 + 22008) & 0x100000000LL) != 0 && v4 )
  {
    mutex_lock(a1 + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 152) + 22008LL) & 0x400000000LL) != 0
      && *(_DWORD *)(a1 + 3664) == 1
      && (v5 = *(_DWORD *)(a1 + 3656), v5 <= 6)
      && ((1 << v5) & 0x64) != 0
      || (v6 = *(_DWORD *)(a1 + 3656), v6 <= 4) && ((1 << v6) & 0x1A) != 0 )
    {
      mutex_unlock(a1 + 3696);
      if ( (_drm_debug & 4) != 0 )
        goto LABEL_49;
LABEL_50:
      JUMPOUT(0x13E4A0);
    }
    mutex_unlock(a1 + 3696);
  }
  v7 = *(_QWORD *)(a1 + 3512);
  v8 = *a2;
  if ( (!v7 || *(_DWORD *)(v7 + 32) != v8) && ((v7 = *(_QWORD *)(a1 + 3520)) == 0 || *(_DWORD *)(v7 + 32) != v8)
    || !*(_QWORD *)(v7 + 40) )
  {
    printk(&unk_2696C5, "sde_vbif_set_qos_remap");
    goto LABEL_50;
  }
  v9 = *(_DWORD *)(v7 + 28);
  if ( v9 > 2 )
LABEL_51:
    JUMPOUT(0x13E6FC);
  if ( !*(_QWORD *)(v7 + 192 + 8LL * v9) )
    goto LABEL_47;
  v10 = (unsigned int)a2[2];
  if ( (unsigned int)(v10 - 1) > 0x12 )
    goto LABEL_47;
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 22008LL) & 0x8000000000LL;
  if ( v11 )
  {
    if ( !*(_QWORD *)(a1 + 32 * v10 + 2888) )
    {
LABEL_27:
      if ( (_drm_debug & 4) == 0 )
        goto LABEL_47;
      v14 = 0;
LABEL_32:
      _drm_dev_dbg(0, 0, 0, "split_vbif:%d type:%s supported:%d\n", v11 >> 39, sde_clk_ctrl_type_s[v10], v14);
      if ( (v14 & 1) != 0 )
        goto LABEL_33;
      v9 = *(_DWORD *)(v7 + 28);
LABEL_47:
      if ( v9 || (_drm_debug & 4) == 0 )
        goto LABEL_50;
      goto LABEL_49;
    }
  }
  else
  {
    v12 = *(_QWORD *)(a1 + 3528);
    v13 = *(unsigned int *)(v12 + 28);
    if ( (unsigned int)v13 > 2 )
      goto LABEL_51;
    if ( !*(_QWORD *)(v12 + 8 * v13 + 152) )
      goto LABEL_27;
  }
  if ( (_drm_debug & 4) == 0 )
  {
LABEL_33:
    v15 = (unsigned int)a2[4];
    if ( (unsigned int)v15 >= 8 )
      JUMPOUT(0x13E698);
    v16 = *(_QWORD *)(v7 + 40) + 16 * v15;
    v18 = *(_DWORD *)(v16 + 96);
    v17 = v16 + 96;
    if ( v18 && *(_QWORD *)(v17 + 8) )
    {
      mutex_lock(v7 + 288);
      if ( (unsigned int)a2[2] < 0x14 )
      {
        if ( (*(_QWORD *)(*(_QWORD *)(a1 + 152) + 22008LL) & 0x8000000000LL) != 0 )
          JUMPOUT(0x13E4C4);
        v19 = *(_QWORD *)(a1 + 3528);
        v20 = *(unsigned int *)(v19 + 28);
        if ( (unsigned int)v20 <= 2 )
        {
          v21 = *(void (**)(void))(v19 + 8 * v20 + 152);
          if ( v21 )
          {
            if ( *((_DWORD *)v21 - 1) != -6776909 )
              __break(0x8228u);
            v21();
            JUMPOUT(0x13E500);
          }
          JUMPOUT(0x13E4F8);
        }
      }
      goto LABEL_51;
    }
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_50;
LABEL_49:
    JUMPOUT(0x13E490);
  }
  v14 = 1;
  goto LABEL_32;
}
