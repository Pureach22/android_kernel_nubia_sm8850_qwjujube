__int64 __fastcall dsi_ctrl_collect_misr(__int64 a1)
{
  __int64 v1; // x8
  __int64 (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x1
  __int64 v5; // x0
  unsigned int v6; // w0
  __int64 v7; // x4
  unsigned int v8; // w19

  if ( !a1 )
    return 0;
  v1 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v1 < 3 )
  {
    v2 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 8 * v1 + 1128);
    if ( v2 )
    {
      v3 = *(unsigned int *)(a1 + 2440);
      v5 = a1 + 96;
      if ( *((_DWORD *)v2 - 1) != -1986690900 )
        __break(0x8228u);
      v6 = v2(v5, v3);
      v7 = *(_QWORD *)(a1 + 16);
      if ( v6 )
        v8 = v6;
      else
        v8 = *(_DWORD *)(a1 + 2868);
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: cached misr = %x, final = %x\n", v7);
      return v8;
    }
    return 0;
  }
  __break(0x5512u);
  return dsi_ctrl_irq_update();
}
