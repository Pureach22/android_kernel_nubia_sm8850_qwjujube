__int64 __fastcall dp_mst_sim_transfer(__int64 a1, int *a2)
{
  unsigned int v2; // w8
  int v3; // w8
  int v4; // w8
  int *v6; // x20
  __int64 v7; // x0
  size_t v8; // x2
  int v9; // w9
  _QWORD *v10; // x19
  __int64 v11; // x1
  char v12; // w9
  int v13; // w8
  unsigned int v14; // w9
  int v15; // w9
  int *v16; // x19
  size_t v17; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v19; // x22
  __int64 (__fastcall *v20)(_QWORD); // x0
  __int64 v22; // [xsp+8h] [xbp-8h]

  v2 = -2;
  if ( !a1 || !a2 || !*(_DWORD *)(a1 + 32) )
    return v2;
  v3 = *((unsigned __int8 *)a2 + 4);
  if ( v3 == 9 )
  {
    v13 = *a2;
    v14 = *a2 & 0xFFFFFF00;
    if ( v14 == 5632 )
    {
      v15 = -5632;
    }
    else
    {
      if ( v14 != 5120 )
      {
        if ( (unsigned int)(v13 - 8194) <= 0xD )
        {
          dp_mst_sim_read_esi();
          return 0;
        }
        return (unsigned int)-22;
      }
      v15 = -5120;
    }
    v16 = a2;
    memcpy(*((void **)a2 + 1), (const void *)(a1 + (unsigned int)(v13 + v15) + 812), *((_QWORD *)a2 + 2));
    v2 = 0;
    *((_BYTE *)v16 + 5) = 0;
    return v2;
  }
  if ( v3 != 8 )
    return (unsigned int)-22;
  v4 = *a2;
  if ( (*a2 & 0xFFFFFF00) == 0x1200 )
    return 0;
  if ( (v4 & 0xFFFFFF00) != 0x1000 )
  {
    if ( (unsigned int)(v4 - 8194) <= 0xD )
    {
      dp_mst_sim_clear_esi();
      return 0;
    }
    if ( v4 == 273 )
      return (unsigned int)dp_mst_sim_reset();
    return (unsigned int)-22;
  }
  if ( *((_QWORD *)a2 + 2) <= 0xFFu && (v6 = a2, v7 = _kmalloc_cache_noprof(msleep, 3520, 312), a2 = v6, v7) )
  {
    while ( 1 )
    {
      v8 = *((_QWORD *)a2 + 2);
      v9 = *a2;
      *(_QWORD *)(v7 + 32) = a1;
      *(_DWORD *)(v7 + 40) = v9;
      *(_QWORD *)(v7 + 304) = v8;
      if ( v8 < 0x10D )
        break;
      _fortify_panic(17, 268, v8);
      StatusReg = _ReadStatusReg(SP_EL0);
      v19 = *(_QWORD *)(StatusReg + 80);
      v20 = msleep;
      *(_QWORD *)(StatusReg + 80) = &dp_mst_sim_down_req__alloc_tag;
      v7 = _kmalloc_cache_noprof(v20, 3520, 312);
      *(_QWORD *)(StatusReg + 80) = v19;
      a2 = v6;
      if ( !v7 )
        goto LABEL_29;
    }
    if ( v8 >= 0x101 && (dp_mst_sim_down_req___already_done & 1) == 0 )
    {
      v22 = v7;
      dp_mst_sim_down_req___already_done = 1;
      v17 = v8;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v8,
        "field \"work->buffer\" at ../vendor/qcom/opensource/display-drivers/msm/dp/dp_mst_sim_helper.c:885",
        0x100u);
      v7 = v22;
      v8 = v17;
      a2 = v6;
      __break(0x800u);
    }
    v10 = (_QWORD *)v7;
    memcpy((void *)(v7 + 44), *((const void **)a2 + 1), v8);
    *v10 = 0xFFFFFFFE00000LL;
    v10[1] = v10 + 1;
    v10[2] = v10 + 1;
    v11 = *(_QWORD *)(a1 + 768);
    v10[3] = dp_mst_sim_down_req_work;
    queue_work_on(32, v11, v10);
    a2 = v6;
    v12 = 0;
  }
  else
  {
LABEL_29:
    v12 = 1;
  }
  v2 = 0;
  *((_BYTE *)a2 + 5) = v12;
  return v2;
}
