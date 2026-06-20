__int64 __fastcall sde_hw_uidle_init(int a1, const void *a2, unsigned __int64 a3, int *a4)
{
  __int64 v8; // x0
  int v9; // w5
  int v10; // w6
  int v11; // w7
  char v12; // w8
  unsigned __int64 v13; // x22
  __int64 v14; // x24
  int v15; // w10
  __int64 (__fastcall *v16)(); // x9
  __int64 v17; // x10
  __int64 v18; // x10
  unsigned int v19; // w2
  int v20; // w11
  __int64 v21; // x19
  __int64 v23; // x21

  v8 = _kmalloc_cache_noprof(msleep, 3520, 288);
  if ( !v8 )
    return -12;
  if ( a4[5476] != a1 || (v9 = a4[5477], v10 = a4[5478], (unsigned int)(v10 + v9) >= a3) )
  {
    v23 = v8;
    printk(&unk_23240A, "_top_offset");
    printk(&unk_232454, "_top_offset");
    v8 = v23;
    a4[5494] = 0;
LABEL_16:
    kfree(v8);
    return -22;
  }
  v11 = *a4;
  v12 = _drm_debug;
  v13 = (unsigned __int64)(a4 + 5472);
  *(_QWORD *)v8 = a2;
  *(_DWORD *)(v8 + 8) = v9;
  *(_DWORD *)(v8 + 12) = v10;
  *(_DWORD *)(v8 + 20) = v11;
  *(_DWORD *)(v8 + 24) = 0x8000;
  if ( (v12 & 4) != 0 )
  {
    v14 = v8;
    _drm_dev_dbg(0, 0, 0, "base:0x%p blk_off:0x%x length:%d hw_rev:0x%x\n", a2, v9, v10, v11);
    v8 = v14;
  }
  if ( v13 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_16;
  v15 = a4[5494];
  v16 = sde_hw_uidle_active_override;
  *(_DWORD *)(v8 + 280) = a1;
  *(_QWORD *)(v8 + 32) = v13;
  if ( v15 )
  {
    v17 = *((_QWORD *)a4 + 2740);
    *(_QWORD *)(v8 + 40) = sde_hw_uidle_setup_ctl;
    *(_QWORD *)(v8 + 64) = sde_hw_uidle_setup_wd_timer;
    *(_QWORD *)(v8 + 88) = sde_hw_uidle_setup_cntr;
    *(_QWORD *)(v8 + 112) = sde_hw_uidle_get_cntr;
    *(_QWORD *)(v8 + 136) = sde_hw_uidle_get_status;
    if ( (v17 & 8) != 0 )
      *(_QWORD *)(v8 + 160) = sde_hw_uidle_get_status_ext1;
    if ( (v17 & 2) != 0 )
      *(_QWORD *)(v8 + 184) = sde_hw_uidle_active_override;
    v16 = sde_hw_uidle_fal10_override;
    v18 = 168;
  }
  else
  {
    v18 = 144;
  }
  v19 = *(_DWORD *)(v8 + 8);
  v20 = *(_DWORD *)(v8 + 12);
  *(_QWORD *)(v8 + 40 + v18) = v16;
  v21 = v8;
  sde_dbg_reg_register_dump_range((__int64)"sde", "uidle", v19, v20 + v19, 0);
  return v21;
}
