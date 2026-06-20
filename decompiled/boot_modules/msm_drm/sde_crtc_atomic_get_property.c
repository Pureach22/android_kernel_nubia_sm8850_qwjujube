__int64 __fastcall sde_crtc_atomic_get_property(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  unsigned int v9; // w19

  if ( a1 && a2 )
  {
    if ( (unsigned int)msm_property_index(a1 + 2600, a3) == 6 )
    {
      *a4 = -1;
      return 0;
    }
    else
    {
      result = msm_property_atomic_get(a1 + 2600, a2 + 768, a3, a4);
      if ( (_DWORD)result )
      {
        result = sde_cp_crtc_get_property(a1, a3, a4);
        if ( (_DWORD)result )
        {
          v9 = result;
          _drm_err("get property failed\n");
          return v9;
        }
      }
    }
  }
  else
  {
    printk(&unk_253460, "sde_crtc_atomic_get_property");
    return 4294967274LL;
  }
  return result;
}
