__int64 __fastcall sde_encoder_virt_restore(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned int v4; // w20
  _QWORD *v5; // x8
  unsigned int v6; // w8
  __int64 v7; // x21
  void (*v8)(void); // x8
  void (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x21
  void (*v11)(void); // x8
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x21
  void (*v14)(void); // x8
  void (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x21
  void (*v17)(void); // x8
  void (__fastcall *v18)(_QWORD); // x8
  void (*v19)(void); // x8
  unsigned int v20; // w8
  __int64 (*v21)(void); // x9
  __int64 (*v22)(void); // x9
  __int64 (*v23)(void); // x9
  __int64 (*v24)(void); // x8
  void *v25; // x0

  if ( !a1 )
    return printk(&unk_26FCAB, "sde_encoder_virt_restore");
  if ( *(_QWORD *)a1 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v2 && *(_QWORD *)(v2 + 8) )
    {
      result = sde_kms_get_disp_op();
      v4 = result;
      v5 = *(_QWORD **)(a1 + 328);
      if ( v5 )
        goto LABEL_6;
      goto LABEL_95;
    }
    v25 = &unk_234896;
  }
  else
  {
    v25 = &unk_26FCAB;
  }
  result = printk(v25, "sde_encoder_get_kms");
  v4 = 0;
  v5 = *(_QWORD **)(a1 + 328);
  if ( v5 )
  {
LABEL_6:
    v5[99] = 0;
    v5[98] = 0;
    v5[97] = 0;
    v5[96] = 0;
    v5[95] = 0;
    v5[94] = 0;
    v5[93] = 0;
    v5[92] = 0;
    v5[91] = 0;
    v5[90] = 0;
    v5[89] = 0;
    v5[88] = 0;
    v5[87] = 0;
    v6 = *(_DWORD *)(a1 + 196);
    *(_BYTE *)(a1 + 1313) = 1;
    if ( v6 )
    {
      v7 = *(_QWORD *)(a1 + 200);
      if ( v7 )
      {
        result = *(_QWORD *)(v7 + 416);
        if ( result )
        {
          if ( v4 > 2 )
            goto LABEL_98;
          v8 = *(void (**)(void))(result + 8LL * v4 + 688);
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 1) != 1800103338 )
              __break(0x8228u);
            v8();
          }
        }
        if ( v7 != *(_QWORD *)(a1 + 328) )
        {
          v9 = *(void (__fastcall **)(_QWORD))(v7 + 256);
          if ( v9 )
          {
            if ( *((_DWORD *)v9 - 1) != -511414616 )
              __break(0x8228u);
            v9(v7);
          }
        }
        result = sde_encoder_setup_dither(v7);
        v6 = *(_DWORD *)(a1 + 196);
      }
      if ( v6 >= 2 )
      {
        v10 = *(_QWORD *)(a1 + 208);
        if ( v10 )
        {
          result = *(_QWORD *)(v10 + 416);
          if ( result )
          {
            if ( v4 > 2 )
              goto LABEL_98;
            v11 = *(void (**)(void))(result + 8LL * v4 + 688);
            if ( v11 )
            {
              if ( *((_DWORD *)v11 - 1) != 1800103338 )
                __break(0x8228u);
              v11();
            }
          }
          if ( v10 != *(_QWORD *)(a1 + 328) )
          {
            v12 = *(void (__fastcall **)(_QWORD))(v10 + 256);
            if ( v12 )
            {
              if ( *((_DWORD *)v12 - 1) != -511414616 )
                __break(0x8228u);
              v12(v10);
            }
          }
          result = sde_encoder_setup_dither(v10);
          v6 = *(_DWORD *)(a1 + 196);
        }
        if ( v6 >= 3 )
        {
          v13 = *(_QWORD *)(a1 + 216);
          if ( v13 )
          {
            result = *(_QWORD *)(v13 + 416);
            if ( result )
            {
              if ( v4 > 2 )
                goto LABEL_98;
              v14 = *(void (**)(void))(result + 8LL * v4 + 688);
              if ( v14 )
              {
                if ( *((_DWORD *)v14 - 1) != 1800103338 )
                  __break(0x8228u);
                v14();
              }
            }
            if ( v13 != *(_QWORD *)(a1 + 328) )
            {
              v15 = *(void (__fastcall **)(_QWORD))(v13 + 256);
              if ( v15 )
              {
                if ( *((_DWORD *)v15 - 1) != -511414616 )
                  __break(0x8228u);
                v15(v13);
              }
            }
            result = sde_encoder_setup_dither(v13);
            v6 = *(_DWORD *)(a1 + 196);
          }
          if ( v6 >= 4 )
          {
            v16 = *(_QWORD *)(a1 + 224);
            if ( v16 )
            {
              result = *(_QWORD *)(v16 + 416);
              if ( result )
              {
                if ( v4 > 2 )
                  goto LABEL_98;
                v17 = *(void (**)(void))(result + 8LL * v4 + 688);
                if ( v17 )
                {
                  if ( *((_DWORD *)v17 - 1) != 1800103338 )
                    __break(0x8228u);
                  v17();
                }
              }
              if ( v16 != *(_QWORD *)(a1 + 328) )
              {
                v18 = *(void (__fastcall **)(_QWORD))(v16 + 256);
                if ( v18 )
                {
                  if ( *((_DWORD *)v18 - 1) != -511414616 )
                    __break(0x8228u);
                  v18(v16);
                }
              }
              result = sde_encoder_setup_dither(v16);
              v6 = *(_DWORD *)(a1 + 196);
            }
            if ( v6 <= 4 )
              goto LABEL_63;
LABEL_98:
            __break(0x5512u);
            return sde_encoder_setup_dither(result);
          }
        }
      }
    }
LABEL_63:
    v19 = *(void (**)(void))(*(_QWORD *)(a1 + 328) + 256LL);
    if ( v19 )
    {
      if ( *((_DWORD *)v19 - 1) != -511414616 )
        __break(0x8228u);
      v19();
    }
    result = sde_encoder_virt_enable_helper(a1);
    v20 = *(_DWORD *)(a1 + 196);
    if ( v20 )
    {
      result = *(_QWORD *)(a1 + 200);
      if ( result )
      {
        v21 = *(__int64 (**)(void))(result + 248);
        if ( v21 )
        {
          if ( *((_DWORD *)v21 - 1) != 1595431362 )
            __break(0x8229u);
          result = v21();
          v20 = *(_DWORD *)(a1 + 196);
        }
      }
      if ( v20 >= 2 )
      {
        result = *(_QWORD *)(a1 + 208);
        if ( result )
        {
          v22 = *(__int64 (**)(void))(result + 248);
          if ( v22 )
          {
            if ( *((_DWORD *)v22 - 1) != 1595431362 )
              __break(0x8229u);
            result = v22();
            v20 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v20 >= 3 )
        {
          result = *(_QWORD *)(a1 + 216);
          if ( result )
          {
            v23 = *(__int64 (**)(void))(result + 248);
            if ( v23 )
            {
              if ( *((_DWORD *)v23 - 1) != 1595431362 )
                __break(0x8229u);
              result = v23();
              v20 = *(_DWORD *)(a1 + 196);
            }
          }
          if ( v20 >= 4 )
          {
            result = *(_QWORD *)(a1 + 224);
            if ( result )
            {
              v24 = *(__int64 (**)(void))(result + 248);
              if ( v24 )
              {
                if ( *((_DWORD *)v24 - 1) != 1595431362 )
                  __break(0x8228u);
                return v24();
              }
            }
          }
        }
      }
    }
    return result;
  }
LABEL_95:
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "virt encoder has no master\n");
  return result;
}
