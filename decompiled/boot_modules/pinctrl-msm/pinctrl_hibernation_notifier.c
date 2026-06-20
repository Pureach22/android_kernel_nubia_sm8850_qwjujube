__int64 __fastcall pinctrl_hibernation_notifier(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x0

  v2 = msm_pinctrl_data;
  if ( a2 == 2 )
  {
    kfree(*(_QWORD *)(msm_pinctrl_data + 1024));
    kfree(*(_QWORD *)(v2 + 1032));
    *(_BYTE *)(v2 + 1040) = 0;
    *(_QWORD *)(v2 + 1032) = 0;
    *(_QWORD *)(v2 + 1024) = 0;
    return 1;
  }
  else if ( a2 == 1 )
  {
    v3 = *(_QWORD *)(msm_pinctrl_data + 968);
    v4 = _kmalloc_noprof(16LL * *(unsigned int *)(v3 + 40), 3520);
    *(_QWORD *)(v2 + 1024) = v4;
    if ( v4 )
    {
      if ( !*(_DWORD *)(v3 + 64)
        || (v5 = _kmalloc_noprof(32LL * *(unsigned int *)(v3 + 64), 3520), (*(_QWORD *)(v2 + 1032) = v5) != 0) )
      {
        *(_BYTE *)(v2 + 1040) = 1;
        return 1;
      }
      kfree(*(_QWORD *)(v2 + 1024));
    }
    return 4294967284LL;
  }
  else
  {
    return 1;
  }
}
