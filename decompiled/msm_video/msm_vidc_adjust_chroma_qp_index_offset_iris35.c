__int64 __fastcall msm_vidc_adjust_chroma_qp_index_offset_iris35(_DWORD *a1, __int64 a2)
{
  int v2; // w8
  int v3; // w9
  int v4; // w10
  unsigned int v5; // w11
  char v6; // w8
  unsigned int v7; // w10
  char v8; // w19
  char v9; // w8
  int v10; // w20
  _DWORD *v12; // x21
  __int64 v13; // x4

  if ( a2 )
    v2 = *(_DWORD *)(a2 + 196);
  else
    v2 = a1[7808];
  if ( v2 > 0 )
  {
    v3 = (char)v2;
    v4 = (__int16)v2 >> 8;
    v5 = (unsigned int)v2 >> 8;
    v6 = v2 + 12;
    v7 = v4 - 1;
    if ( (unsigned int)(v3 - 1) >= 0xFFFFFFF3 )
      v8 = v6;
    else
      v8 = 12;
    v9 = v5 + 12;
    if ( v7 < 0xFFFFFFF3 )
      v9 = 12;
    if ( v8 != v9 && a1[78] == 1 && a1[3776] != 4 )
    {
      v10 = v9;
      if ( a1 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
        {
          v12 = a1;
          printk(&unk_80B90, "high", a1 + 85, (unsigned int)v8, (unsigned int)v9);
          if ( v8 >= v10 )
            v8 = v10;
          if ( (msm_vidc_debug & 2) != 0 )
            printk(&unk_91D97, "high", v12 + 85, (unsigned int)v8, v13);
          a1 = v12;
        }
      }
    }
  }
  ((void (__fastcall *)(_DWORD *, __int64))msm_vidc_update_cap_value)(a1, 160);
  return 0;
}
