__int64 __fastcall sde_encoder_update_vsync_source(__int64 result, unsigned __int8 *a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  int v5; // w6
  int v6; // w21
  unsigned int v7; // w8
  __int64 (*v8)(void); // x9
  __int64 (*v9)(void); // x9
  __int64 (*v10)(void); // x9
  __int64 (*v11)(void); // x9
  void *v12; // x0
  char v13; // [xsp+0h] [xbp+0h]

  if ( !a2 )
    goto LABEL_37;
  v2 = result;
  if ( *(_DWORD *)(result + 196) >= 5u )
  {
    v12 = &unk_22AB93;
    return printk(v12, "_sde_encoder_update_vsync_source");
  }
  v4 = *(_QWORD *)(*(_QWORD *)(result + 200) + 8LL);
  if ( result )
  {
    if ( *(_DWORD *)(result + 648) == 2 || (a2[111] & 1) != 0 )
      goto LABEL_7;
  }
  else
  {
    result = printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    if ( (a2[111] & 1) != 0 )
      goto LABEL_7;
  }
  if ( a2[109] != 1 )
    return result;
LABEL_7:
  v5 = a2[60];
  if ( (v5 & 1) != 0 || *(_BYTE *)(v4 + 4516) == 1 )
    v6 = *(_DWORD *)(v2 + 192) + 11;
  else
    v6 = *(_DWORD *)(v2 + 192);
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "_sde_encoder_update_vsync_source",
             1687,
             -1,
             *(_DWORD *)(v2 + 24),
             v6,
             v5,
             -1059143953,
             v13);
  v7 = *(_DWORD *)(v2 + 196);
  if ( v7 )
  {
    result = *(_QWORD *)(v2 + 200);
    if ( result )
    {
      v8 = *(__int64 (**)(void))(result + 296);
      if ( v8 )
      {
        if ( *((_DWORD *)v8 - 1) != -465221367 )
          __break(0x8229u);
        result = v8();
        v7 = *(_DWORD *)(v2 + 196);
      }
    }
    if ( v7 >= 2 )
    {
      result = *(_QWORD *)(v2 + 208);
      if ( result )
      {
        v9 = *(__int64 (**)(void))(result + 296);
        if ( v9 )
        {
          if ( *((_DWORD *)v9 - 1) != -465221367 )
            __break(0x8229u);
          result = v9();
          v7 = *(_DWORD *)(v2 + 196);
        }
      }
      if ( v7 >= 3 )
      {
        result = *(_QWORD *)(v2 + 216);
        if ( result )
        {
          v10 = *(__int64 (**)(void))(result + 296);
          if ( v10 )
          {
            if ( *((_DWORD *)v10 - 1) != -465221367 )
              __break(0x8229u);
            result = v10();
            v7 = *(_DWORD *)(v2 + 196);
          }
        }
        if ( v7 >= 4 )
        {
          result = *(_QWORD *)(v2 + 224);
          if ( result )
          {
            v11 = *(__int64 (**)(void))(result + 296);
            if ( v11 )
            {
              if ( *((_DWORD *)v11 - 1) != -465221367 )
                __break(0x8229u);
              result = v11();
              v7 = *(_DWORD *)(v2 + 196);
            }
          }
          if ( v7 > 4 )
          {
            __break(0x5512u);
LABEL_37:
            v12 = &unk_25E6FB;
            return printk(v12, "_sde_encoder_update_vsync_source");
          }
        }
      }
    }
  }
  return result;
}
