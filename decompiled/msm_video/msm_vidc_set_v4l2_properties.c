__int64 __fastcall msm_vidc_set_v4l2_properties(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 *v6; // x22
  __int64 v7; // x23
  unsigned int v8; // w20
  unsigned int *v9; // x8
  _DWORD *v10; // x8
  __int64 result; // x0
  unsigned int v12; // w21
  __int64 v13; // x0

  if ( a1 && (msm_vidc_debug & 2) != 0 )
    printk(&unk_9602D, "high", a1 + 340, "msm_vidc_set_v4l2_properties", a5);
  v6 = *(__int64 **)(a1 + 4024);
  if ( v6 == (__int64 *)(a1 + 4024) )
    return 0;
  v7 = a1 + 4320;
  while ( 1 )
  {
    v8 = *((_DWORD *)v6 + 4);
    v6 = (__int64 *)*v6;
    if ( v8 - 1 <= 0xC3 )
    {
      v9 = (unsigned int *)(v7 + 168LL * v8);
      if ( *v9 - 197 >= 0xFFFFFF3C )
      {
        if ( *(_DWORD *)(v7 + 168LL * *v9) )
        {
          v10 = *((_DWORD **)v9 + 20);
          if ( v10 )
          {
            if ( *(v10 - 1) != 1301911631 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, _QWORD))v10)(a1, v8);
            if ( (_DWORD)result )
              break;
          }
        }
      }
    }
    if ( v6 == (__int64 *)(a1 + 4024) )
      return 0;
  }
  if ( a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v12 = result;
      v13 = cap_name(v8);
      printk(&unk_946BA, "err ", a1 + 340, "msm_vidc_set_v4l2_properties", v13);
      return v12;
    }
  }
  return result;
}
