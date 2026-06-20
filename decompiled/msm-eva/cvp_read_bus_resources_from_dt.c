__int64 __fastcall cvp_read_bus_resources_from_dt(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x22
  __int64 v4; // x23
  unsigned __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x24
  bool v9; // cf
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x20
  __int64 result; // x0
  unsigned __int64 v14; // x8
  unsigned int v15; // w19
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x25
  __int64 v20; // x2
  __int64 v21; // x3
  bool v22; // cc
  const char *v23; // x0
  int v24; // w8
  int v25; // w9
  unsigned __int64 StatusReg; // x20
  __int64 v27; // x24
  unsigned __int64 v28; // x8
  _QWORD v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 112);
    v3 = a1 + 16;
    if ( v1 )
    {
      v4 = *(_QWORD *)(v1 + 152);
      if ( v4 )
      {
        v29[0] = 0;
        v5 = 120LL * (unsigned int)(*(_DWORD *)(v4 + 912) + 1);
        v6 = krealloc_noprof(*(_QWORD *)(v4 + 904), v5, 3264);
        if ( v6 )
        {
          while ( 1 )
          {
            v7 = *(unsigned int *)(v4 + 912);
            *(_QWORD *)(v4 + 904) = v6;
            v8 = 120 * v7;
            v9 = v5 >= 120 * v7;
            v10 = v5 - 120 * v7;
            v11 = v9 ? v10 : 0LL;
            if ( v11 > 0x77 )
              break;
            _fortify_panic(15);
            StatusReg = _ReadStatusReg(SP_EL0);
            v27 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &msm_cvp_populate_bus__alloc_tag;
            v5 = 120LL * (unsigned int)(*(_DWORD *)(v4 + 912) + 1);
            v6 = krealloc_noprof(*(_QWORD *)(v4 + 904), v5, 3264);
            *(_QWORD *)(StatusReg + 80) = v27;
            if ( !v6 )
              goto LABEL_51;
          }
          v12 = v6 + v8;
          *(_QWORD *)(v12 + 104) = 0;
          *(_QWORD *)(v12 + 112) = 0;
          *(_QWORD *)(v12 + 88) = 0;
          *(_QWORD *)(v12 + 96) = 0;
          *(_QWORD *)(v12 + 72) = 0;
          *(_QWORD *)(v12 + 80) = 0;
          *(_QWORD *)(v12 + 56) = 0;
          *(_QWORD *)(v12 + 64) = 0;
          *(_QWORD *)(v12 + 40) = 0;
          *(_QWORD *)(v12 + 48) = 0;
          *(_QWORD *)(v12 + 24) = 0;
          *(_QWORD *)(v12 + 32) = 0;
          *(_QWORD *)(v12 + 8) = 0;
          *(_QWORD *)(v12 + 16) = 0;
          *(_QWORD *)v12 = 0;
          result = of_property_read_string(*(_QWORD *)(a1 + 760), "interconnect-names", v6 + v8);
          if ( (_DWORD)result )
          {
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v14 = _ReadStatusReg(SP_EL0);
              v15 = result;
              printk(&unk_96A60, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
              result = v15;
            }
            goto LABEL_54;
          }
          v19 = v8 + 16;
          if ( !(unsigned int)of_property_read_string(*(_QWORD *)(a1 + 760), "qcom,bus-governor", v12 + 16) )
          {
            if ( v5 <= v19 )
              goto LABEL_48;
            v23 = *(const char **)(v12 + 16);
LABEL_31:
            if ( !strcmp(v23, "performance") )
            {
              if ( v5 <= v8 + 112 )
                goto LABEL_48;
              *(_BYTE *)(v12 + 112) = 1;
            }
            if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,bus-range-kbps", v29, 2, 0)
                & 0x80000000) == 0 )
            {
              v25 = v29[0];
              v24 = HIDWORD(v29[0]);
              goto LABEL_39;
            }
            if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
              goto LABEL_38;
            goto LABEL_49;
          }
          if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
          {
            printk(&unk_95FAC, "core", v20, v21);
            v22 = v5 > v19;
            if ( v5 <= v19 )
              goto LABEL_48;
            goto LABEL_26;
          }
          v22 = v5 > v19;
          if ( v5 > v19 )
          {
LABEL_26:
            if ( !v22 )
              goto LABEL_48;
            v23 = "performance";
            *(_QWORD *)(v12 + 16) = "performance";
            goto LABEL_31;
          }
          while ( 1 )
          {
            while ( 1 )
            {
LABEL_48:
              __break(1u);
LABEL_49:
              printk(&unk_8AEDA, "core", v20, v21);
LABEL_38:
              v25 = 0;
              v29[0] = 0x7FFFFFFF00000000LL;
              v24 = 0x7FFFFFFF;
LABEL_39:
              if ( v5 > v8 + 8 )
              {
                *(_DWORD *)(v12 + 8) = v25;
                if ( v5 >= v8 + 12 )
                {
                  *(_DWORD *)(v12 + 12) = v24;
                  ++*(_DWORD *)(v4 + 912);
                  if ( v5 > v8 + 24 )
                    break;
                }
              }
            }
            *(_QWORD *)(v12 + 24) = v3;
            result = 0;
            if ( (msm_cvp_debug & 0x100) == 0 || msm_cvp_debug_out )
              break;
            if ( v5 > v8 && v5 > v19 )
            {
              printk(&unk_95FFC, "core", *(_QWORD *)v12, *(_QWORD *)(v12 + 16));
              result = 0;
              break;
            }
          }
        }
        else
        {
LABEL_51:
          result = 4294967284LL;
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v28 = _ReadStatusReg(SP_EL0);
            printk(&unk_88808, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), &unk_8E7CE);
            result = 4294967284LL;
          }
        }
      }
      else
      {
        result = 4294967274LL;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v18 = _ReadStatusReg(SP_EL0);
          printk(&unk_8D745, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
          result = 4294967274LL;
        }
      }
    }
    else
    {
      result = 4294967277LL;
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v17 = _ReadStatusReg(SP_EL0);
        printk(&unk_849F0, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
        result = 4294967277LL;
      }
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v16 = _ReadStatusReg(SP_EL0);
      printk(&unk_8D714, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
