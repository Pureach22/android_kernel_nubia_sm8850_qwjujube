__int64 __fastcall _switch_gdsc_to_swmode(__int64 result, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 (*v3)(void); // x8
  void *v4; // x0
  const char *v5; // x1

  v2 = *(_QWORD *)(result + 6544);
  if ( v2 && (v3 = *(__int64 (**)(void))(v2 + 64)) != nullptr )
  {
    if ( result )
    {
      if ( *((_DWORD *)v3 - 1) != -254569353 )
        __break(0x8228u);
      result = v3();
      if ( (result & 0x80000000) != 0 )
      {
LABEL_7:
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v4 = &unk_8D093;
          v5 = "err ";
          return printk(v4, v5, 0xFFFFFFFFLL, "codec", "__switch_gdsc_to_swmode");
        }
        return result;
      }
    }
  }
  else
  {
    result = dev_pm_genpd_set_hwmode(*a2, 0);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_7;
  }
  if ( (msm_vidc_debug & 2) != 0 )
  {
    v4 = &unk_90251;
    v5 = "high";
    return printk(v4, v5, 0xFFFFFFFFLL, "codec", "__switch_gdsc_to_swmode");
  }
  return result;
}
