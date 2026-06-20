__int64 __fastcall sde_encoder_helper_switch_vsync(__int64 a1, char a2)
{
  unsigned int v2; // w8
  char v4; // w20
  __int64 v5; // x0
  void (*v6)(void); // x9
  __int64 v7; // x0
  void (*v8)(void); // x9
  __int64 v9; // x0
  void (*v10)(void); // x9
  __int64 v11; // x0
  void (*v12)(void); // x8
  unsigned int v13; // w8
  __int64 v14; // x0
  void (*v15)(void); // x9
  __int64 v16; // x0
  void (*v17)(void); // x9
  __int64 v18; // x0
  void (*v19)(void); // x9
  __int64 result; // x0
  void (*v21)(void); // x8
  _BYTE dest[160]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v23; // [xsp+A8h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(&unk_2122F8, "sde_encoder_helper_switch_vsync");
    result = 4294967274LL;
    goto LABEL_51;
  }
  v2 = *(_DWORD *)(a1 + 196);
  v4 = a2 & 1;
  if ( v2 )
  {
    v5 = *(_QWORD *)(a1 + 200);
    if ( v5 )
    {
      v6 = *(void (**)(void))(v5 + 248);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != 1595431362 )
          __break(0x8229u);
        v6();
        v2 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v2 >= 2 )
    {
      v7 = *(_QWORD *)(a1 + 208);
      if ( v7 )
      {
        v8 = *(void (**)(void))(v7 + 248);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != 1595431362 )
            __break(0x8229u);
          v8();
          v2 = *(_DWORD *)(a1 + 196);
        }
      }
      if ( v2 >= 3 )
      {
        v9 = *(_QWORD *)(a1 + 216);
        if ( v9 )
        {
          v10 = *(void (**)(void))(v9 + 248);
          if ( v10 )
          {
            if ( *((_DWORD *)v10 - 1) != 1595431362 )
              __break(0x8229u);
            v10();
            v2 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v2 >= 4 )
        {
          v11 = *(_QWORD *)(a1 + 224);
          if ( v11 )
          {
            v12 = *(void (**)(void))(v11 + 248);
            if ( v12 )
            {
              if ( *((_DWORD *)v12 - 1) != 1595431362 )
                __break(0x8228u);
              v12();
            }
          }
        }
      }
    }
  }
  memcpy(dest, (const void *)(a1 + 640), sizeof(dest));
  dest[60] = v4;
  sde_encoder_update_vsync_source(a1, dest);
  v13 = *(_DWORD *)(a1 + 196);
  if ( !v13 )
    goto LABEL_50;
  v14 = *(_QWORD *)(a1 + 200);
  if ( v14 )
  {
    v15 = *(void (**)(void))(v14 + 248);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != 1595431362 )
        __break(0x8229u);
      v15();
      v13 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v13 < 2 )
    goto LABEL_50;
  v16 = *(_QWORD *)(a1 + 208);
  if ( v16 )
  {
    v17 = *(void (**)(void))(v16 + 248);
    if ( v17 )
    {
      if ( *((_DWORD *)v17 - 1) != 1595431362 )
        __break(0x8229u);
      v17();
      v13 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v13 < 3 )
    goto LABEL_50;
  v18 = *(_QWORD *)(a1 + 216);
  if ( v18 )
  {
    v19 = *(void (**)(void))(v18 + 248);
    if ( v19 )
    {
      if ( *((_DWORD *)v19 - 1) != 1595431362 )
        __break(0x8229u);
      v19();
      v13 = *(_DWORD *)(a1 + 196);
    }
  }
  if ( v13 < 4 )
    goto LABEL_50;
  result = *(_QWORD *)(a1 + 224);
  if ( result )
  {
    v21 = *(void (**)(void))(result + 248);
    if ( v21 )
    {
      if ( *((_DWORD *)v21 - 1) != 1595431362 )
        __break(0x8228u);
      v21();
    }
LABEL_50:
    result = 0;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
