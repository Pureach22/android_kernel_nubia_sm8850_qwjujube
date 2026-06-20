__int64 __fastcall handle_session_property(__int64 a1, __int64 a2)
{
  unsigned int *v4; // x21
  unsigned int v5; // w0
  __int64 result; // x0
  __int64 v7; // x4
  void *v8; // x0
  const char *v9; // x1
  const char *v10; // x3
  unsigned int v11; // w23
  __int64 v12; // x3
  _DWORD *v13; // x22
  unsigned int v14; // w8
  void *v15; // x0
  const char *v16; // x3
  __int64 v17; // x4
  void *v18; // x0
  unsigned int v19; // w21
  int v20; // w8
  unsigned int v21; // w9
  __int64 v22; // x10
  __int64 v23; // x10
  __int64 v24; // x10
  __int64 v25; // x10
  __int64 v26; // x10
  __int64 v27; // x10
  __int64 v28; // x10
  __int64 v29; // x10
  __int64 v30; // x8
  int v31; // w9

  if ( a1 )
  {
    if ( (msm_vidc_debug & 4) != 0 )
      printk(&unk_8A25F, "low ", a1 + 340, "handle_session_property", *(unsigned int *)(a2 + 4));
    v4 = (unsigned int *)(a2 + 16);
    v5 = vidc_port_from_hfi(a1, *(_DWORD *)(a2 + 16));
    if ( v5 > 4 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_9730A, "err ", a1 + 340, "handle_session_property", *(unsigned int *)(a2 + 16));
        return 4294967274LL;
      }
      return 4294967274LL;
    }
    if ( (*(_BYTE *)(a2 + 8) & 2) != 0 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v7 = *(unsigned int *)(a2 + 4);
        v8 = &unk_97DF2;
        v9 = "high";
        v10 = "handle_session_property";
LABEL_12:
        printk(v8, v9, a1 + 340, v10, v7);
        return 0;
      }
      return 0;
    }
  }
  else
  {
    v4 = (unsigned int *)(a2 + 16);
    v5 = vidc_port_from_hfi(0, *(_DWORD *)(a2 + 16));
    if ( v5 > 4 )
      return 4294967274LL;
    if ( (*(_BYTE *)(a2 + 8) & 2) != 0 )
      return 0;
  }
  v11 = v5;
  if ( (check_for_packet_payload(a1, a2, "handle_session_property") & 1) == 0 )
  {
    v7 = *(unsigned int *)(a2 + 4);
    if ( (_DWORD)v7 == 50332026 )
    {
LABEL_28:
      result = handle_dpb_list_property(a1, a2);
      if ( (_DWORD)result )
        return result;
      return 0;
    }
    if ( (_DWORD)v7 == 50332010 )
    {
      if ( v11 )
      {
        if ( a1 && (msm_vidc_debug & 1) != 0 )
          printk(&unk_9730A, "err ", a1 + 340, "handle_property_without_payload", *v4);
      }
      else
      {
        if ( a1 && (msm_vidc_debug & 2) != 0 )
          printk(&unk_8F883, "high", a1 + 340, v12, v7);
        *(_DWORD *)(a1 + 3556) = 1;
      }
      return 0;
    }
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v8 = &unk_83D3D;
      v9 = "err ";
      v10 = "handle_property_without_payload";
      goto LABEL_12;
    }
    return 0;
  }
  v13 = (_DWORD *)(a2 + 32);
  if ( a2 != -32 )
  {
    v7 = *(unsigned int *)(a2 + 4);
    v14 = v11;
    switch ( (int)v7 )
    {
      case 50331907:
        *(_DWORD *)(a1 + 56LL * v11 + 3272) = *v13;
        return 0;
      case 50331909:
        v30 = a1 + 56LL * v11;
        *(_DWORD *)(v30 + 3276) = *(_DWORD *)(a2 + 32);
        *(_DWORD *)(v30 + 3280) = *(_DWORD *)(a2 + 36);
        return 0;
      case 50331911:
        *(_DWORD *)(a1 + 56LL * v11 + 3304) = *v13;
        return 0;
      case 50331912:
        *(_DWORD *)(a1 + 56LL * v11 + 3308) = *v13;
        return 0;
      case 50331913:
        *(_DWORD *)(a1 + 56LL * v11 + 3312) = *v13;
        return 0;
      case 50331914:
        if ( !a1 )
          return 0;
        v17 = (unsigned int)*v13;
        if ( *(_QWORD *)(a1 + 11576) == v17 || (msm_vidc_debug & 1) == 0 )
          return 0;
        v18 = &unk_97346;
        goto LABEL_82;
      case 50331915:
        if ( !a1 )
          return 0;
        v17 = (unsigned int)*v13;
        if ( *(_QWORD *)(a1 + 31400) == v17 || (msm_vidc_debug & 1) == 0 )
          return 0;
        v18 = &unk_84808;
        goto LABEL_82;
      case 50331919:
        *(_DWORD *)(a1 + 56LL * v11 + 3284) = *v13;
        return 0;
      case 50331936:
        *(_DWORD *)(a1 + 56LL * v11 + 3288) = *v13;
        return 0;
      case 50331937:
        if ( *v13 == 1 )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
            a1,
            41,
            1,
            "handle_property_with_payload");
        else
          ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
            a1,
            41,
            0,
            "handle_property_with_payload");
        return 0;
      case 50331940:
        goto LABEL_63;
      case 50331943:
        *(_DWORD *)(a1 + 56LL * v11 + 3324) = *v13;
        return 0;
      case 50331944:
        *(_DWORD *)(a1 + 56LL * v11 + 3296) = *v13;
        return 0;
      case 50331976:
        if ( !a1 )
          return 0;
        v17 = (unsigned int)*v13;
        if ( *(_QWORD *)(a1 + 33248) == v17 || (msm_vidc_debug & 1) == 0 )
          return 0;
        v18 = &unk_7FEE3;
LABEL_82:
        printk(v18, "err ", a1 + 340, "handle_property_with_payload", v17);
        return 0;
      case 50331989:
        *(_DWORD *)(a1 + 56LL * v11 + 3300) = *v13;
        return 0;
      case 50332002:
        v31 = *v13;
        *(_DWORD *)(a1 + 3552) = *v13;
        if ( (v31 & 4) != 0 )
          *(_BYTE *)(a1 + 38704) = 1;
        *(_BYTE *)(a1 + 38712) = (v31 & 1) != 0;
        return 0;
      case 50332020:
        *(_DWORD *)(a1 + 3564) = *v13;
        return 0;
      case 50332021:
        *(_DWORD *)(a1 + 3568) = *v13;
        return 0;
      case 50332026:
        goto LABEL_28;
      case 50332032:
        *(_DWORD *)(a1 + 56LL * v11 + 3316) = *v13;
        return 0;
      case 50332033:
        *(_DWORD *)(a1 + 56LL * v11 + 3320) = *v13;
        return 0;
      case 50332035:
        if ( v11 )
        {
          if ( a1 && (msm_vidc_debug & 1) != 0 )
            printk(&unk_9730A, "err ", a1 + 340, "handle_property_with_payload", *v4);
        }
        else
        {
          *(_DWORD *)(a1 + 3560) = 1;
        }
        return 0;
      case 50332039:
        *(_DWORD *)(a1 + 3584) = *v13;
        return 0;
      case 50332043:
        if ( a1 && a2 )
        {
          v19 = *(_DWORD *)a2 - 32;
          if ( v19 < 0x51 )
          {
            if ( v19 < 8 )
              goto LABEL_106;
            v20 = *(_DWORD *)(a1 + 3672);
            *(_QWORD *)(a1 + 3592) = *(_QWORD *)v13;
            *(_DWORD *)(a1 + 3672) = v20 + 1;
            if ( v19 < 0x10 )
              goto LABEL_106;
          }
          else
          {
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_94091, "err ", a1 + 340, "handle_property_fence_array", v19);
            msm_vidc_change_state(a1, 5u, (__int64)"handle_property_fence_array");
            v20 = *(_DWORD *)(a1 + 3672);
            *(_QWORD *)(a1 + 3592) = *(_QWORD *)v13;
            *(_DWORD *)(a1 + 3672) = v20 + 1;
          }
          v21 = v19 >> 3;
          *(_QWORD *)(a1 + 3600) = *(_QWORD *)(a2 + 40);
          *(_DWORD *)(a1 + 3672) = v20 + 2;
          if ( v19 >> 3 != 2 )
          {
            v22 = *(_QWORD *)(a2 + 48);
            *(_DWORD *)(a1 + 3672) = v20 + 3;
            *(_QWORD *)(a1 + 3608) = v22;
            if ( v21 != 3 )
            {
              v23 = *(_QWORD *)(a2 + 56);
              *(_DWORD *)(a1 + 3672) = v20 + 4;
              *(_QWORD *)(a1 + 3616) = v23;
              if ( v21 != 4 )
              {
                v24 = *(_QWORD *)(a2 + 64);
                *(_DWORD *)(a1 + 3672) = v20 + 5;
                *(_QWORD *)(a1 + 3624) = v24;
                if ( v21 != 5 )
                {
                  v25 = *(_QWORD *)(a2 + 72);
                  *(_DWORD *)(a1 + 3672) = v20 + 6;
                  *(_QWORD *)(a1 + 3632) = v25;
                  if ( v21 != 6 )
                  {
                    v26 = *(_QWORD *)(a2 + 80);
                    *(_DWORD *)(a1 + 3672) = v20 + 7;
                    *(_QWORD *)(a1 + 3640) = v26;
                    if ( v21 != 7 )
                    {
                      v27 = *(_QWORD *)(a2 + 88);
                      *(_DWORD *)(a1 + 3672) = v20 + 8;
                      *(_QWORD *)(a1 + 3648) = v27;
                      if ( v21 != 8 )
                      {
                        v28 = *(_QWORD *)(a2 + 96);
                        *(_DWORD *)(a1 + 3672) = v20 + 9;
                        *(_QWORD *)(a1 + 3656) = v28;
                        if ( v21 != 9 )
                        {
                          v29 = *(_QWORD *)(a2 + 104);
                          v14 = v20 + 10;
                          *(_DWORD *)(a1 + 3672) = v14;
                          *(_QWORD *)(a1 + 3664) = v29;
                          if ( v21 != 10 )
                          {
                            __break(0x5512u);
LABEL_63:
                            *(_DWORD *)(a1 + 56LL * v14 + 3292) = *v13;
                            return 0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
LABEL_106:
          if ( (msm_vidc_debug & 4) != 0 )
            printk(&unk_8F84E, "low ", a1 + 340, "handle_property_fence_array", *(unsigned int *)(a1 + 3672));
          return 0;
        }
        if ( a1 && (msm_vidc_debug & 1) != 0 )
        {
          v15 = &unk_8BE9D;
          v16 = "handle_property_fence_array";
          goto LABEL_27;
        }
        break;
      case 50332055:
        if ( !*v13 )
          *(_BYTE *)(a1 + 3588) = 1;
        return 0;
      default:
        if ( !a1 || (msm_vidc_debug & 1) == 0 )
          return 0;
        v8 = &unk_83D3D;
        v9 = "err ";
        v10 = "handle_property_with_payload";
        goto LABEL_12;
    }
    return 4294967274LL;
  }
  if ( !a1 || (msm_vidc_debug & 1) == 0 )
    return 4294967274LL;
  v15 = &unk_97E3E;
  v16 = "handle_property_with_payload";
LABEL_27:
  printk(v15, "err ", a1 + 340, v16, v7);
  return 4294967274LL;
}
