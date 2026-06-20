__int64 __fastcall sde_cp_notify_ad_event(__int64 result)
{
  int v1; // w9
  __int64 *v2; // x19
  int v3; // w8
  __int64 *v4; // x9
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v7; // x8
  __int64 v8; // x20
  int v9; // w0
  __int64 v10; // x8
  _DWORD *v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w9
  unsigned int v20; // w11
  int v21; // w20
  int v22; // w7
  char v23[12]; // [xsp+0h] [xbp-20h] BYREF
  unsigned int v24; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v25; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v26; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(result + 2192);
  v26 = 0;
  v25 = 0;
  if ( !v1 )
    goto LABEL_64;
  *(_QWORD *)v23 = 0x480000001LL;
  if ( (unsigned int)(v1 - 9) < 0xFFFFFFF8 )
    goto LABEL_65;
  v2 = (__int64 *)result;
  v3 = *(_QWORD *)(result + 2216) != 0;
  if ( v1 != 1 )
  {
    if ( *(_QWORD *)(result + 2264) )
      ++v3;
    if ( v1 != 2 )
    {
      if ( *(_QWORD *)(result + 2312) )
        ++v3;
      if ( v1 != 3 )
      {
        if ( *(_QWORD *)(result + 2360) )
          ++v3;
        if ( v1 != 4 )
        {
          if ( *(_QWORD *)(result + 2408) )
            ++v3;
          if ( v1 != 5 )
          {
            if ( *(_QWORD *)(result + 2456) )
              ++v3;
            if ( v1 != 6 )
            {
              if ( *(_QWORD *)(result + 2504) )
                ++v3;
              if ( v1 != 7 && *(_QWORD *)(result + 2552) )
                ++v3;
            }
          }
        }
      }
    }
  }
  if ( !v3 )
    goto LABEL_64;
  v4 = (__int64 *)(result + 2216);
  if ( v3 != 1 && (*(_BYTE *)(*(_QWORD *)(result + 2200) + 384LL) & 1) != 0 )
  {
    v4 = (__int64 *)(result + 2264);
    if ( v3 != 2 && (*(_BYTE *)(*(_QWORD *)(result + 2248) + 384LL) & 1) != 0 )
    {
      v4 = (__int64 *)(result + 2312);
      if ( v3 != 3 && (*(_BYTE *)(*(_QWORD *)(result + 2296) + 384LL) & 1) != 0 )
      {
        v4 = (__int64 *)(result + 2360);
        if ( v3 != 4 && (*(_BYTE *)(*(_QWORD *)(result + 2344) + 384LL) & 1) != 0 )
        {
          v4 = (__int64 *)(result + 2408);
          if ( v3 != 5 && (*(_BYTE *)(*(_QWORD *)(result + 2392) + 384LL) & 1) != 0 )
          {
            v4 = (__int64 *)(result + 2456);
            if ( v3 != 6 && (*(_BYTE *)(*(_QWORD *)(result + 2440) + 384LL) & 1) != 0 )
            {
              v4 = (__int64 *)(result + 2504);
              if ( v3 != 7 && (*(_BYTE *)(*(_QWORD *)(result + 2488) + 384LL) & 1) != 0 )
              {
                v4 = (__int64 *)(result + 2552);
                if ( v3 != 8 && (*(_BYTE *)(*(_QWORD *)(result + 2536) + 384LL) & 1) != 0 )
                  goto LABEL_65;
              }
            }
          }
        }
      }
    }
  }
  v5 = *v4;
  if ( !*v4 )
  {
LABEL_64:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 56LL) + 8LL);
  if ( !v6 || (v7 = *(_QWORD *)(v6 + 136)) == 0 )
  {
    result = printk(&unk_249CCB, "_sde_cp_notify_ad_event");
    goto LABEL_64;
  }
  v8 = *(_QWORD *)(v7 + 8);
  v9 = _pm_runtime_resume(v8, 4);
  if ( v9 < 0 )
  {
    v13 = *(_DWORD *)(v8 + 480);
    do
    {
      if ( !v13 )
        break;
      _X13 = (unsigned int *)(v8 + 480);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v20 = __ldxr(_X13);
        if ( v20 != v13 )
          break;
        if ( !__stlxr(v13 - 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v13;
      v13 = v20;
    }
    while ( !_ZF );
    v21 = v9;
    printk(&unk_24C43E, "_sde_cp_notify_ad_event");
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "_sde_cp_notify_ad_event",
               3739,
               -1,
               v21,
               60333,
               -1059143953,
               v22,
               v23[0]);
    goto LABEL_64;
  }
  v10 = *(unsigned int *)(v5 + 28);
  if ( (unsigned int)v10 <= 2 )
  {
    v11 = *(_DWORD **)(v5 + 8 * v10 + 544);
    if ( v11 )
    {
      if ( *(v11 - 1) != 59847453 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, unsigned int *, unsigned int *))v11)(v5, 0, &v26, &v25);
    }
    result = _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(v6 + 136) + 8LL), 4);
    if ( v26 )
    {
      if ( v26 >= v25 )
      {
        v12 = *v2;
        v24 = 0xFFFF * v25 / v26;
        result = msm_mode_object_event_notify(v2 + 14, v12, v23, &v24);
      }
    }
    goto LABEL_64;
  }
LABEL_65:
  __break(0x5512u);
  return sde_cp_notify_hist_event();
}
