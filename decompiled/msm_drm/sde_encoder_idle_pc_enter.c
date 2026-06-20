__int64 __fastcall sde_encoder_idle_pc_enter(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v3; // x0
  void (*v4)(void); // x9
  __int64 v5; // x0
  void (*v6)(void); // x9
  __int64 v7; // x0
  void (*v8)(void); // x9
  __int64 v9; // x0
  void (*v10)(void); // x8
  __int64 result; // x0
  __int64 (*v12)(void); // x8

  if ( !a1 )
    return printk(&unk_26FCAB, "sde_encoder_idle_pc_enter");
  v1 = *(_DWORD *)(a1 + 196);
  if ( v1 )
  {
    v3 = *(_QWORD *)(a1 + 200);
    if ( v3 )
    {
      v4 = *(void (**)(void))(v3 + 248);
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 1595431362 )
          __break(0x8229u);
        v4();
        v1 = *(_DWORD *)(a1 + 196);
      }
    }
    if ( v1 >= 2 )
    {
      v5 = *(_QWORD *)(a1 + 208);
      if ( v5 )
      {
        v6 = *(void (**)(void))(v5 + 248);
        if ( v6 )
        {
          if ( *((_DWORD *)v6 - 1) != 1595431362 )
            __break(0x8229u);
          v6();
          v1 = *(_DWORD *)(a1 + 196);
        }
      }
      if ( v1 >= 3 )
      {
        v7 = *(_QWORD *)(a1 + 216);
        if ( v7 )
        {
          v8 = *(void (**)(void))(v7 + 248);
          if ( v8 )
          {
            if ( *((_DWORD *)v8 - 1) != 1595431362 )
              __break(0x8229u);
            v8();
            v1 = *(_DWORD *)(a1 + 196);
          }
        }
        if ( v1 >= 4 )
        {
          v9 = *(_QWORD *)(a1 + 224);
          if ( v9 )
          {
            v10 = *(void (**)(void))(v9 + 248);
            if ( v10 )
            {
              if ( *((_DWORD *)v10 - 1) != 1595431362 )
                __break(0x8228u);
              v10();
            }
          }
        }
      }
    }
  }
  result = *(_QWORD *)(a1 + 328);
  if ( result )
  {
    v12 = *(__int64 (**)(void))(result + 328);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -511414616 )
        __break(0x8228u);
      return v12();
    }
  }
  return result;
}
