__int64 __fastcall sde_connector_atomic_set_property(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v9; // w22
  int v10; // w9
  unsigned int v11; // w0
  unsigned int v12; // w19
  void *v13; // x0
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  unsigned int v15; // w0
  unsigned int v16; // w0
  _DWORD *v17; // x8
  __int64 v18; // x4
  __int64 v19; // x8
  unsigned int v20; // w21
  __int64 v21; // x22

  if ( a1 && a2 && a3 )
  {
    result = msm_property_atomic_set(a1 + 3312, a2 + 448, a3, a4);
    if ( !(_DWORD)result )
    {
      v9 = msm_property_index(a1 + 3312, a3);
      switch ( v9 )
      {
        case 6u:
          v11 = sde_connector_set_ext_hdr_info(a1, a2, a4);
          if ( !v11 )
            goto LABEL_33;
          v12 = v11;
          v13 = &unk_23F9FC;
          goto LABEL_29;
        case 8u:
          result = sde_connector_update_dimming_bl_lut(a1, a2);
          goto LABEL_32;
        case 0xBu:
          result = sde_connector_set_prop_out_fb(a1, a2, a4);
          goto LABEL_32;
        case 0xCu:
          if ( !a4 )
            goto LABEL_43;
          result = sde_connector_set_prop_retire_fence(a1, a2, a4);
LABEL_32:
          if ( !(_DWORD)result )
            goto LABEL_33;
          return result;
        case 0x12u:
          v16 = sde_connector_set_roi_v1(a1, a2, a4);
          if ( !v16 )
            goto LABEL_33;
          v12 = v16;
          v13 = &unk_21DFF1;
          goto LABEL_29;
        case 0x13u:
          *(_DWORD *)(a1 + 4528) = a4;
          goto LABEL_19;
        case 0x14u:
          *(_DWORD *)(a1 + 4532) = a4;
          goto LABEL_19;
        case 0x16u:
          v14 = *(__int64 (__fastcall **)(__int64, __int64))(a1 + 3176);
          if ( !v14 )
            goto LABEL_33;
          if ( *((_DWORD *)v14 - 1) != 641266555 )
            __break(0x8228u);
          v15 = v14(a1, a4);
          if ( !v15 )
            goto LABEL_33;
          v12 = v15;
          v13 = &unk_212CCD;
LABEL_29:
          printk(v13, "sde_connector_atomic_set_property");
          result = v12;
          break;
        case 0x17u:
          result = sde_connector_update_dimming_ctrl(a1, a4);
          goto LABEL_32;
        case 0x18u:
          result = sde_connector_update_dimming_min_bl(a1, a4);
          goto LABEL_32;
        case 0x1Au:
          sde_connector_set_prop_dyn_transfer_time(a1, a4);
          goto LABEL_33;
        case 0x1Bu:
        case 0x21u:
        case 0x24u:
        case 0x26u:
        case 0x2Fu:
        case 0x30u:
          msm_property_set_dirty(a1 + 3312, a2 + 448, v9);
          goto LABEL_33;
        case 0x1Fu:
          if ( a4 != 5 )
            goto LABEL_33;
          v10 = *(_DWORD *)(a1 + 4532);
          *(_QWORD *)(a1 + 5112) = 0;
          *(_QWORD *)(a1 + 5104) = 0;
          *(_QWORD *)(a1 + 5096) = 0;
          *(_QWORD *)(a1 + 5088) = 0;
          *(_QWORD *)(a1 + 5080) = 0;
          *(_QWORD *)(a1 + 5072) = 0;
          *(_QWORD *)(a1 + 5064) = 0;
          *(_QWORD *)(a1 + 5056) = 0;
          *(_QWORD *)(a1 + 5048) = 0;
          *(_QWORD *)(a1 + 5040) = 0;
          *(_QWORD *)(a1 + 5032) = 0;
          *(_QWORD *)(a1 + 5024) = 0;
          if ( v10 == 0xFFFF )
            goto LABEL_33;
          *(_DWORD *)(a1 + 4532) = 0xFFFF;
LABEL_19:
          *(_BYTE *)(a1 + 4524) = 1;
LABEL_33:
          v17 = *(_DWORD **)(a1 + 2928);
          if ( v17 )
          {
            v18 = *(_QWORD *)(a1 + 2760);
            if ( *(v17 - 1) != -789604110 )
              __break(0x8228u);
            result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v17)(a1, a2, v9, a4, v18);
            if ( v9 == 11 && (_DWORD)result )
            {
              v19 = *(_QWORD *)(a2 + 440);
              v20 = result;
              if ( v19 )
              {
                drm_mode_object_put(v19 + 24);
                *(_QWORD *)(a2 + 440) = 0;
                mutex_lock(a1 + 3392);
                v21 = 0;
                if ( *(_DWORD *)(a1 + 3344) >= 0xCu )
                  v21 = *(_QWORD *)(*(_QWORD *)(a1 + 3336) + 176LL);
                mutex_unlock(a1 + 3392);
                *(_QWORD *)(a2 + 832) = v21;
              }
              else
              {
                printk(&unk_23FA57, "_sde_connector_destroy_fb");
              }
              result = v20;
            }
          }
          else
          {
LABEL_43:
            result = 0;
          }
          break;
        case 0x23u:
          if ( a4 == 2 )
          {
            *(_DWORD *)(a1 + 4520) = 2;
          }
          else if ( a4 == 1 )
          {
            *(_DWORD *)(a1 + 4520) = 1;
          }
          goto LABEL_33;
        default:
          goto LABEL_33;
      }
    }
  }
  else
  {
    printk(&unk_23C2E6, "sde_connector_atomic_set_property");
    return 4294967274LL;
  }
  return result;
}
