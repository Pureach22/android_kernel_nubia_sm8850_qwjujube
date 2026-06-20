__int64 __fastcall msm_v4l2_try_fmt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 *v4; // x1
  __int64 *inst_ref; // x0
  __int64 v7; // x19
  __int64 v8; // x4
  unsigned int v9; // w20
  void *v10; // x0
  _DWORD *v12; // x8
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4

  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 32);
    if ( v3 )
      v4 = (__int64 *)(v3 - 1648);
    else
      v4 = nullptr;
  }
  else
  {
    v4 = nullptr;
  }
  if ( !a3 )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v10 = &unk_83321;
LABEL_21:
    printk(v10, "err ", 0xFFFFFFFFLL, "codec", "msm_v4l2_try_fmt");
    return 4294967274LL;
  }
  inst_ref = get_inst_ref(g_core, v4);
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      return 4294967274LL;
    v10 = &unk_961DD;
    goto LABEL_21;
  }
  v7 = (__int64)inst_ref;
  client_lock((__int64)inst_ref);
  inst_lock(v7);
  if ( *(_DWORD *)(v7 + 160) == 5 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_94D1A, "err ", v7 + 340, "msm_v4l2_try_fmt", v8);
    v9 = -16;
  }
  else
  {
    v12 = *(_DWORD **)(v7 + 168);
    if ( *(v12 - 1) != -249828064 )
      __break(0x8228u);
    v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v12)(v7, 0, a3);
  }
  inst_unlock(v7);
  client_unlock(v7);
  put_inst(v7, v13, v14, v15, v16);
  return v9;
}
