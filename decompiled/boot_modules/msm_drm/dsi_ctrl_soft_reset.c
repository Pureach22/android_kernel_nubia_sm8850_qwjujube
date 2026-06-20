__int64 __fastcall dsi_ctrl_soft_reset(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v6; // x0

  if ( !a1 )
    return 4294967274LL;
  v2 = mutex_lock(a1 + 32);
  v3 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v3 >= 3 )
  {
    __break(0x5512u);
    v6 = MEMORY[0xFFFFFFFFFD3A5334](v2);
    return dsi_ctrl_reset(v6);
  }
  else
  {
    v4 = *(void (__fastcall **)(_QWORD))(a1 + 8 * v3 + 432);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1133867105 )
        __break(0x8228u);
      v4(a1 + 96);
    }
    mutex_unlock(a1 + 32);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Soft reset complete\n", *(const char **)(a1 + 16));
    return 0;
  }
}
