__int64 __fastcall msm_v4l2_enum_framesizes(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v4; // x8
  __int64 *v5; // x1
  __int64 *inst_ref; // x0
  __int64 v7; // x19
  __int64 v8; // x4
  unsigned int v9; // w20
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4

  if ( !a1 )
  {
    v5 = nullptr;
    if ( a3 )
      goto LABEL_6;
LABEL_12:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_enum_framesizes");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
    v5 = (__int64 *)(v4 - 1648);
  else
    v5 = nullptr;
  if ( !a3 )
    goto LABEL_12;
LABEL_6:
  inst_ref = get_inst_ref(g_core, v5);
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_92803, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_enum_framesizes");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = (__int64)inst_ref;
  client_lock((__int64)inst_ref);
  inst_lock(v7);
  if ( *(_DWORD *)(v7 + 160) == 5 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94D1A, "err ", v7 + 340, "msm_v4l2_enum_framesizes", v8);
    v9 = -16;
  }
  else
  {
    v9 = msm_vidc_enum_framesizes((_QWORD *)v7, a3);
  }
  inst_unlock(v7);
  client_unlock(v7);
  put_inst(v7, v11, v12, v13, v14);
  return v9;
}
