__int64 __fastcall msm_vidc_adjust_layer_count(__int64 a1, __int64 a2)
{
  int v3; // w20
  __int64 v4; // x3
  __int64 v5; // x4
  int v6; // w8
  void *v7; // x0
  int v9; // w8
  __int64 v10; // x8
  int v11; // w9
  int v12; // w9
  bool v13; // cc
  int v14; // w8

  if ( a2 )
    v3 = *(_DWORD *)(a2 + 196);
  else
    v3 = *(_DWORD *)(a1 + 15272);
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          65,
          119,
          "msm_vidc_adjust_layer_count")
      & 1) == 0 )
    return 4294967274LL;
  if ( (*(_WORD *)(*(_QWORD *)(a1 + 1848) + 320LL) & 1) == 0 )
  {
    if ( !v3 )
    {
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_19;
      v7 = &unk_91EA2;
LABEL_47:
      printk(v7, "high", a1 + 340, v4, v5);
      goto LABEL_19;
    }
    v6 = *(_DWORD *)(a1 + 1828);
    if ( v6 == 2 )
    {
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_19;
      v7 = &unk_80D7C;
      goto LABEL_47;
    }
    v11 = *(_DWORD *)(a1 + 312);
    if ( v11 == 2 )
    {
      if ( *(_QWORD *)(a1 + 27704) )
      {
        v12 = 1;
LABEL_35:
        *(_DWORD *)(a1 + 1832) = v12;
        if ( v6 )
        {
          v13 = v3 < 3;
          v14 = 3;
        }
        else
        {
          v13 = v3 < 5;
          v14 = 5;
        }
        goto LABEL_44;
      }
    }
    else
    {
      if ( v11 != 1 )
      {
        *(_DWORD *)(a1 + 1832) = 1;
        goto LABEL_20;
      }
      if ( !*(_QWORD *)(a1 + 27872) )
      {
LABEL_19:
        v3 = 0;
LABEL_20:
        ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
          a1,
          65,
          v3,
          "msm_vidc_adjust_static_layer_count_and_type");
        *(_QWORD *)(a1 + 15256) = v3;
        return 0;
      }
      if ( *(_QWORD *)(a1 + 27704) )
      {
        if ( v6 )
          v12 = 1;
        else
          v12 = 2;
        goto LABEL_35;
      }
    }
    if ( v6 )
    {
      if ( a1 && (msm_vidc_debug & 2) != 0 )
        printk(&unk_830BD, "high", a1 + 340, "msm_vidc_adjust_static_layer_count_and_type", v5);
      goto LABEL_19;
    }
    v14 = 3;
    v13 = v3 < 3;
    *(_DWORD *)(a1 + 1832) = 3;
LABEL_44:
    if ( !v13 )
      v3 = v14;
    goto LABEL_20;
  }
  v9 = *(_DWORD *)(a1 + 1828);
  if ( v9 == 4 || v9 == 1 )
  {
    if ( a1 && (msm_vidc_debug & 2) != 0 )
      printk(&unk_95DD5, "high", a1 + 340, "msm_vidc_adjust_layer_count", v5);
  }
  else if ( (unsigned int)(*(_DWORD *)(a1 + 1832) - 1) <= 1 )
  {
    v10 = *(_QWORD *)(a1 + 15256);
    if ( v10 >= v3 )
      LODWORD(v10) = v3;
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      65,
      (int)v10,
      "msm_vidc_adjust_layer_count");
  }
  return 0;
}
