__int64 __fastcall sde_hw_cdm_init(int a1, __int64 a2, int *a3, __int64 a4, unsigned int a5)
{
  __int64 v10; // x0
  int v11; // w8
  __int64 v12; // x8
  unsigned __int64 v13; // x1
  unsigned int v14; // w2
  int v15; // w8
  int v16; // w9
  __int64 v17; // x9
  int v18; // w4
  __int64 v19; // x22
  __int64 v21; // x8
  unsigned __int64 StatusReg; // x24
  __int64 v23; // x25
  __int64 (__fastcall *v24)(_QWORD, _QWORD, _QWORD); // x0

  v10 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, 176);
  if ( !v10 )
    return -12;
  while ( 1 )
  {
    v11 = a3[2962];
    if ( !v11 )
      goto LABEL_14;
    if ( a3[2968] == a1 )
    {
      v12 = 2964;
LABEL_5:
      v13 = (unsigned __int64)&a3[v12];
      goto LABEL_6;
    }
    if ( v11 == 1 )
      goto LABEL_14;
    if ( a3[2984] == a1 )
    {
      v12 = 2980;
      goto LABEL_5;
    }
    if ( v11 == 2 )
      goto LABEL_14;
    if ( a3[3000] == a1 )
    {
      v12 = 2996;
      goto LABEL_5;
    }
    if ( v11 == 3 )
      goto LABEL_14;
    if ( a3[3016] == a1 )
    {
      v12 = 3012;
      goto LABEL_5;
    }
    if ( v11 == 4 )
      goto LABEL_14;
    if ( a3[3032] == a1 )
    {
      v12 = 3028;
      goto LABEL_5;
    }
    if ( v11 == 5 )
      goto LABEL_14;
    if ( a3[3048] == a1 )
    {
      v12 = 3044;
      goto LABEL_5;
    }
    if ( v11 == 6 )
      goto LABEL_14;
    if ( a3[3064] == a1 )
    {
      v12 = 3060;
      goto LABEL_5;
    }
    if ( v11 == 7 )
      goto LABEL_14;
    if ( a3[3080] == a1 )
      break;
    if ( v11 == 8 )
      goto LABEL_14;
    if ( a3[3096] == a1 )
    {
      v21 = 3092;
      goto LABEL_35;
    }
    if ( v11 == 9 )
      goto LABEL_14;
    if ( a3[3112] == a1 )
    {
      v21 = 3108;
      goto LABEL_35;
    }
    if ( v11 == 10 )
      goto LABEL_14;
    if ( a3[3128] == a1 )
    {
      v21 = 3124;
      goto LABEL_35;
    }
    if ( v11 == 11 )
      goto LABEL_14;
    if ( a3[3144] == a1 )
    {
      v21 = 3140;
      goto LABEL_35;
    }
    if ( v11 == 12 )
      goto LABEL_14;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v23 = *(_QWORD *)(StatusReg + 80);
    v24 = _init_waitqueue_head;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_cdm_init__alloc_tag;
    v10 = _kmalloc_cache_noprof(v24, 3520, 176);
    *(_QWORD *)(StatusReg + 80) = v23;
    if ( !v10 )
      return -12;
  }
  v21 = 3076;
LABEL_35:
  v13 = (unsigned __int64)&a3[v21];
LABEL_6:
  v14 = *(_DWORD *)(v13 + 20);
  v15 = *(_DWORD *)(v13 + 24);
  v16 = *a3;
  *(_QWORD *)v10 = a2;
  *(_DWORD *)(v10 + 8) = v14;
  *(_DWORD *)(v10 + 12) = v15;
  *(_DWORD *)(v10 + 20) = v16;
  *(_DWORD *)(v10 + 24) = 2;
  if ( !v13 || v13 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_14:
    kfree(v10);
    return -22;
  }
  v17 = *(_QWORD *)(v13 + 32);
  *(_QWORD *)(v10 + 56) = sde_hw_cdm_setup_csc_10bit;
  *(_QWORD *)(v10 + 80) = sde_hw_cdm_setup_cdwn;
  *(_QWORD *)(v10 + 104) = &sde_hw_cdm_enable;
  *(_DWORD *)(v10 + 40) = a1;
  *(_QWORD *)(v10 + 32) = v13;
  *(_QWORD *)(v10 + 128) = &sde_hw_cdm_disable;
  if ( (v17 & 2) != 0 )
    *(_QWORD *)(v10 + 152) = sde_hw_cdm_bind_pingpong_blk;
  v18 = *(_DWORD *)(v10 + 16);
  v19 = v10;
  *(_QWORD *)(v10 + 48) = a4;
  sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v13, v14, v15 + v14, v18);
  if ( (a3[5030] & 1) == 0 )
    sde_hw_csc_setup(v19, 4, &rgb2yuv_cfg, 1, a5);
  return v19;
}
