// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sde_kms_info_add_keyint(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x18
  __int64 v4; // x3
  unsigned int *v5; // x19
  __int64 v6; // x8
  unsigned int v7; // w8
  __int64 v8; // x8
  _QWORD *i; // x9
  int v10; // w4
  __int64 v11; // x19
  __int64 v12; // x10
  __int64 v13; // x20
  __int64 v14; // x21
  __int64 v15; // x8
  unsigned int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x8
  void (__fastcall *v19)(__int64, __int64, __int64, __int64); // x9
  __int64 v20; // x19
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x19
  _QWORD *v24; // x20
  _QWORD *j; // x21
  __int64 v26; // x0
  void (*v27)(void); // x8
  __int64 v28; // x20
  __int64 v29; // x21

  if ( result )
  {
    v4 = a2;
    if ( a2 )
    {
      v5 = (unsigned int *)(result + 0x4000);
      v6 = *(unsigned int *)(result + 0x4000);
      if ( (unsigned int)v6 <= 0x4000 )
      {
        result = snprintf((char *)(result + v6), (unsigned int)(0x4000 - v6), "%s=%lld\n", (const char *)a2, a3);
        v7 = *v5 + result;
        if ( !(v7 >> 14) )
          *v5 = v7;
        return result;
      }
      __break(0x5512u);
      if ( (v3 & 0x2000000000LL) == 0 )
        JUMPOUT(0x10C308);
      v8 = *(unsigned int *)(v6 + 860);
      if ( (int)v8 < 1 )
        return 0;
      for ( i = (_QWORD *)(*(_QWORD *)(a2 + 32) + 16LL); ; i += 7 )
      {
        v11 = *(i - 2);
        if ( !v11 )
          goto LABEL_13;
        v12 = i[1];
        if ( (*(_BYTE *)(v12 + 9) & 1) != 0 )
        {
          if ( !v12 )
            goto LABEL_13;
        }
        else if ( !v12 || (*(_BYTE *)(*i + 9LL) & 1) == 0 )
        {
          goto LABEL_13;
        }
        v10 = *(_DWORD *)(v12 + 1568);
        if ( v10 )
        {
          if ( (_drm_debug & 4) != 0 )
          {
            v13 = result;
            v14 = a2;
            _drm_dev_dbg(0, 0, 0, "valid vm request:%d found on crtc-%d\n", v10, *(_DWORD *)(v11 + 112));
            a2 = v14;
            result = v13;
          }
          v15 = *(_QWORD *)(*(_QWORD *)(result + 136) + 56LL);
          if ( v15 )
          {
            v16 = *(_DWORD *)(v15 + 5912);
          }
          else
          {
            v28 = result;
            v29 = a2;
            printk(&unk_25E374, "sde_kms_get_disp_op");
            a2 = v29;
            result = v28;
            v16 = 0;
          }
          v17 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 56LL * *(unsigned int *)(v11 + 160) + 24);
          if ( v17 && *(_DWORD *)(v17 + 1568) == 2 )
          {
            v18 = *(_QWORD *)(result + 1896);
            if ( v18 )
            {
              if ( v16 > 2 )
              {
                __break(0x5512u);
                JUMPOUT(0x10F994);
              }
              v19 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v18 + 8LL * v16 + 104);
              if ( v19 )
              {
                v20 = result;
                v21 = *(_QWORD *)(result + 1896);
                if ( *((_DWORD *)v19 - 1) != 1946677504 )
                  __break(0x8229u);
                v19(v21, a2, a3, v4);
                result = v20;
              }
            }
            v22 = *(_QWORD *)(result + 136);
            v23 = result;
            v24 = *(_QWORD **)(v22 + 840);
            for ( j = (_QWORD *)(v22 + 840); v24 != j; v24 = (_QWORD *)*v24 )
              ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))sde_plane_set_sid)(v24 - 1, 1, a3, v4);
            v26 = *(_QWORD *)(v23 + 3552);
            if ( v26 )
            {
              v27 = *(void (**)(void))(v26 + 32);
              if ( v27 )
              {
                if ( *((_DWORD *)v27 - 1) != 34661390 )
                  __break(0x8228u);
                v27();
              }
            }
            ((void (__fastcall *)(__int64, __int64, __int64, __int64))sde_dbg_set_hw_ownership_status)(1, a2, a3, v4);
          }
          return 0;
        }
LABEL_13:
        if ( !--v8 )
          return 0;
      }
    }
  }
  return result;
}
