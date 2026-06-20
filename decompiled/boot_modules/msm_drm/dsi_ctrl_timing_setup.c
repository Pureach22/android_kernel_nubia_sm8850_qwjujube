__int64 __fastcall dsi_ctrl_timing_setup(__int64 a1)
{
  __int64 v2; // x8
  void (__fastcall *v3)(__int64, __int64, __int64); // x9
  _DWORD *v4; // x9
  void (__fastcall *v5)(__int64, __int64); // x8
  void (__fastcall *v7)(__int64, __int64, __int64); // x9
  void (__fastcall *v8)(__int64, __int64); // x9

  if ( a1 )
  {
    mutex_lock(a1 + 32);
    v2 = *(unsigned int *)(a1 + 1608);
    if ( *(_DWORD *)(a1 + 2440) == 2 )
    {
      if ( (unsigned int)v2 < 3 )
      {
        v3 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 8 * v2 + 288);
        if ( !v3 )
          goto LABEL_8;
        if ( *((_DWORD *)v3 - 1) != 1675679774 )
          __break(0x8229u);
        v3(a1 + 96, a1 + 2444, a1 + 2536);
        LODWORD(v2) = *(_DWORD *)(a1 + 1608);
        if ( (unsigned int)v2 <= 2 )
        {
LABEL_8:
          v4 = *(_DWORD **)(a1 + 8LL * (unsigned int)v2 + 312);
          if ( !v4 )
            goto LABEL_12;
          if ( *(v4 - 1) != 1379136512 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))v4)(
            a1 + 96,
            a1 + 2592,
            a1 + 2444,
            0,
            a1 + 2760);
          LODWORD(v2) = *(_DWORD *)(a1 + 1608);
          if ( (unsigned int)v2 <= 2 )
          {
LABEL_12:
            v5 = *(void (__fastcall **)(__int64, __int64))(a1 + 8LL * (unsigned int)v2 + 360);
            if ( v5 )
            {
LABEL_13:
              if ( *((_DWORD *)v5 - 1) != 1642962683 )
                __break(0x8228u);
              v5(a1 + 96, 1);
            }
LABEL_16:
            mutex_unlock(a1 + 32);
            return 0;
          }
        }
      }
    }
    else if ( (unsigned int)v2 <= 2 )
    {
      v7 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 8 * v2 + 240);
      if ( !v7 )
        goto LABEL_23;
      if ( *((_DWORD *)v7 - 1) != 1838921532 )
        __break(0x8229u);
      v7(a1 + 96, a1 + 2444, a1 + 2536);
      LODWORD(v2) = *(_DWORD *)(a1 + 1608);
      if ( (unsigned int)v2 <= 2 )
      {
LABEL_23:
        v8 = *(void (__fastcall **)(__int64, __int64))(a1 + 8LL * (unsigned int)v2 + 264);
        if ( !v8 )
          goto LABEL_27;
        if ( *((_DWORD *)v8 - 1) != -1866437525 )
          __break(0x8229u);
        v8(a1 + 96, a1 + 2440);
        LODWORD(v2) = *(_DWORD *)(a1 + 1608);
        if ( (unsigned int)v2 <= 2 )
        {
LABEL_27:
          v5 = *(void (__fastcall **)(__int64, __int64))(a1 + 8LL * (unsigned int)v2 + 192);
          if ( v5 )
            goto LABEL_13;
          goto LABEL_16;
        }
      }
    }
    __break(0x5512u);
    JUMPOUT(0x1D21DC);
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
  return 4294967274LL;
}
