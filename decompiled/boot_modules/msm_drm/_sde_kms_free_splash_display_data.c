__int64 __fastcall sde_kms_free_splash_display_data(__int64 result, _QWORD *a2)
{
  __int64 v3; // x20
  char v4; // w9
  int v5; // w4

  if ( result && a2 && *(_DWORD *)(result + 2544) )
  {
    if ( *(_DWORD *)(result + 2540) )
    {
      v3 = result;
      ((void (*)(void))sde_kms_splash_mem_put)();
      result = v3;
      if ( a2[3] )
      {
        sde_kms_splash_mem_put(v3);
        result = v3;
      }
    }
    v4 = _drm_debug;
    v5 = *(_DWORD *)(result + 2544) - 1;
    *(_DWORD *)(result + 2544) = v5;
    if ( (v4 & 4) != 0 )
      result = _drm_dev_dbg(0, 0, 0, "cont_splash handoff done, remaining:%d\n", v5);
    a2[8] = 0;
    a2[9] = 0;
    a2[6] = 0;
    a2[7] = 0;
    a2[4] = 0;
    a2[5] = 0;
    a2[2] = 0;
    a2[3] = 0;
    *a2 = 0;
    a2[1] = 0;
  }
  return result;
}
