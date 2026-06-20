__int64 __fastcall msm_ioctl_power_ctrl(__int64 a1, int *a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v6; // x1
  int v7; // w23
  int v8; // w7
  unsigned int v9; // w20
  __int64 v10; // x21
  unsigned int v11; // w0
  unsigned int v12; // w8
  unsigned int v19; // w10
  int v20; // w4

  if ( !a2 )
  {
    _drm_err("invalid ioctl data\n");
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(a3 + 152);
  mutex_lock(v3 + 32);
  v7 = *(unsigned __int16 *)(v3 + 28);
  if ( *a2 )
  {
    *(_WORD *)(v3 + 28) = v7 + 1;
    if ( !v7 )
      goto LABEL_8;
  }
  else if ( *(_WORD *)(v3 + 28) )
  {
    *(_WORD *)(v3 + 28) = v7 - 1;
    if ( (_WORD)v7 == 1 )
    {
LABEL_8:
      v10 = *(_QWORD *)(a1 + 8);
      if ( *a2 )
      {
        v11 = _pm_runtime_resume(*(_QWORD *)(a1 + 8), 4);
        if ( (v11 & 0x80000000) != 0 )
        {
          v12 = *(_DWORD *)(v10 + 480);
          v9 = v11;
          do
          {
            if ( !v12 )
              break;
            _X12 = (unsigned int *)(v10 + 480);
            __asm { PRFM            #0x11, [X12] }
            while ( 1 )
            {
              v19 = __ldxr(_X12);
              if ( v19 != v12 )
                break;
              if ( !__stlxr(v12 - 1, _X12) )
              {
                __dmb(0xBu);
                break;
              }
            }
            _ZF = v19 == v12;
            v12 = v19;
          }
          while ( !_ZF );
          *(_WORD *)(v3 + 28) = v7;
        }
        else
        {
          v9 = 0;
        }
      }
      else
      {
        _pm_runtime_idle(*(_QWORD *)(a1 + 8), 4);
        v9 = 0;
      }
      v8 = 1;
      goto LABEL_23;
    }
  }
  else
  {
    printk(&unk_22CBA4, v6);
  }
  v8 = 0;
  v9 = 0;
LABEL_23:
  v20 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "msm_ioctl_power_ctrl",
    1882,
    -1,
    v20,
    *a2,
    *(unsigned __int16 *)(v3 + 28),
    v8,
    239);
  mutex_unlock(v3 + 32);
  return v9;
}
