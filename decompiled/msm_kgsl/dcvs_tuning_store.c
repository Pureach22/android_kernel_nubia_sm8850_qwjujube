__int64 __fastcall dcvs_tuning_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x10
  void (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 v12; // x1
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  v7 = kstrtoll(a3, 0, v14);
  if ( v7 )
  {
    a4 = v7;
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return a4;
  }
  if ( (unsigned __int64)(v14[0] - 0x100000000LL) < 0xFFFFFFFEFFFFFFFFLL )
  {
    a4 = -34;
    goto LABEL_9;
  }
  v8 = rt_mutex_lock(a1 - 12480);
  v9 = *(unsigned int *)(a2 + 32);
  if ( (unsigned int)v9 < 0x11 )
  {
    v10 = *(_QWORD *)(a1 - 14816);
    *(_DWORD *)(a1 + 8 * v9 + 192) = v14[0];
    v11 = *(void (__fastcall **)(__int64, __int64, __int64))(v10 + 304);
    v12 = *(unsigned int *)(a2 + 32);
    if ( *((_DWORD *)v11 - 1) != -227291694 )
      __break(0x8228u);
    v11(a1 - 23568, v12, 6);
    rt_mutex_unlock(a1 - 12480);
    goto LABEL_9;
  }
  __break(0x5512u);
  return aggregated_max_gpuclk_show(v8);
}
