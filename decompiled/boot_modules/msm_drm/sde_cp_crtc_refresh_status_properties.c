__int64 __fastcall sde_cp_crtc_refresh_status_properties(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int disp_op; // w0
  unsigned int v4; // w22
  unsigned __int64 v5; // x23
  __int64 v6; // x21
  __int64 v7; // x24
  _QWORD *v8; // x25
  void (*v9)(void); // x8

  _ReadStatusReg(SP_EL0);
  if ( result )
  {
    v1 = result;
    v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)result + 56LL) + 5224LL) + 320LL);
    if ( v2 )
    {
      disp_op = sde_crtc_get_disp_op(result);
      if ( *(_DWORD *)(v1 + 2192) )
      {
        v4 = disp_op;
        v5 = 0;
        v6 = 0;
        v7 = disp_op;
        v8 = (_QWORD *)(v1 + 2216);
        while ( v5 != 8 )
        {
          if ( *v8 )
          {
            if ( v4 > 2 )
              break;
            v9 = *(void (**)(void))(*v8 + 8 * v7 + 1096);
            if ( v9 )
            {
              if ( *((_DWORD *)v9 - 1) != 1035535036 )
                __break(0x8228u);
              v9();
              v6 |= 1uLL;
            }
          }
          ++v5;
          v8 += 6;
          if ( v5 >= *(unsigned int *)(v1 + 2192) )
            goto LABEL_16;
        }
        __break(0x5512u);
      }
      v6 = 0;
LABEL_16:
      result = drm_object_property_set_value(v1 + 112, v2, v6);
    }
  }
  else
  {
    result = _drm_err("invalid crtc %pKn", nullptr);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
