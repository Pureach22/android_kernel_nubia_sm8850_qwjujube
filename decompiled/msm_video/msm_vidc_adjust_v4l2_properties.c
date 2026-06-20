__int64 __fastcall msm_vidc_adjust_v4l2_properties(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *v6; // x28
  __int64 v7; // x26
  __int64 *v8; // x20
  unsigned int v9; // w23
  unsigned int *v10; // x8
  _DWORD *v11; // x8
  __int64 result; // x0
  unsigned int v13; // w23
  unsigned int v14; // w20
  __int64 v15; // x0

  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vidc_adjust_v4l2_properties", a5);
  v6 = *(__int64 **)(a1 + 4024);
  if ( v6 == (__int64 *)(a1 + 4024) )
    return 0;
  v7 = a1 + 4320;
  while ( 1 )
  {
    v8 = (__int64 *)*v6;
    if ( a1 && (msm_vidc_debug & 4) != 0 )
    {
      v13 = *((_DWORD *)v6 + 4);
      cap_name(v13);
      printk(&unk_89AE3, "low ", a1 + 340, "msm_vidc_adjust_v4l2_properties", v13);
    }
    v9 = *((_DWORD *)v6 + 4);
    if ( v9 - 1 <= 0xC3 )
    {
      v10 = (unsigned int *)(v7 + 168LL * v9);
      if ( *v10 - 197 >= 0xFFFFFF3C )
      {
        if ( *(_DWORD *)(v7 + 168LL * *v10) )
        {
          v11 = *((_DWORD **)v10 + 19);
          if ( v11 )
          {
            if ( *(v11 - 1) != -611583898 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, _QWORD))v11)(a1, 0);
            if ( (_DWORD)result )
              break;
          }
        }
      }
    }
    v6 = v8;
    if ( v8 == (__int64 *)(a1 + 4024) )
      return 0;
  }
  if ( a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v14 = result;
      v15 = cap_name(v9);
      printk(&unk_8EFCA, "err ", a1 + 340, "msm_vidc_adjust_v4l2_properties", v15);
      return v14;
    }
  }
  return result;
}
