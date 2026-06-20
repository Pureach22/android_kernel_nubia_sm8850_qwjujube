unsigned __int64 __fastcall sde_devcoredump_read(void *dest, __int64 a2, unsigned __int64 a3)
{
  __int64 v6; // x8
  unsigned int v7; // w8
  bool v8; // cc
  size_t v9; // x8
  size_t v10; // x2
  unsigned __int64 result; // x0
  _QWORD v12[6]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v13[2]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v14; // [xsp+48h] [xbp-18h]
  __int64 v15; // [xsp+50h] [xbp-10h]
  __int64 v16; // [xsp+58h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = qword_2945E0;
  if ( qword_2945E0 )
  {
    if ( (byte_2945E8 & 1) != 0 )
    {
      v7 = sde_devcoredump_read_read_size;
      goto LABEL_7;
    }
  }
  else
  {
    v6 = _kvmalloc_node_noprof(2883584, 0, 3520, 0xFFFFFFFFLL);
    qword_2945E0 = v6;
    if ( !v6 )
    {
      result = -12;
      goto LABEL_16;
    }
    byte_2945E8 = 0;
  }
  v13[0] = v6;
  v13[1] = 0;
  v12[0] = &_drm_printfn_coredump;
  v12[1] = &_drm_puts_coredump;
  v14 = 2883584;
  v15 = 0;
  v12[2] = v13;
  memset(&v12[3], 0, 24);
  drm_printf(v12, "---\n");
  drm_printf(v12, "module: msm_drm\n");
  drm_printf(v12, "sde devcoredump\n");
  qword_2945A8 = (__int64)v12;
  HIBYTE(word_294380) = 1;
  sde_dump_array(0, (__int64)"devcoredump", byte_2945A0, qword_294598);
  byte_2945E8 = 1;
  v7 = 2883584 - v14;
  sde_devcoredump_read_read_size = 2883584 - v14;
LABEL_7:
  v8 = v7 <= a2;
  v9 = v7 - a2;
  if ( v8 )
  {
    result = 0;
  }
  else
  {
    if ( v9 >= a3 )
      v10 = a3;
    else
      v10 = v9;
    memcpy(dest, (const void *)(qword_2945E0 + a2), v10);
    if ( (unsigned __int64)(unsigned int)sde_devcoredump_read_read_size - a2 >= a3 )
      result = a3;
    else
      result = (unsigned int)sde_devcoredump_read_read_size - a2;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
