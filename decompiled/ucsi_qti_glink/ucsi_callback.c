__int64 __fastcall ucsi_callback(__int64 a1, _DWORD *a2, size_t a3)
{
  __int64 (*v6)(void); // x8
  __int64 v7; // x0
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x6
  int v10; // w7
  __int64 v11; // x3
  __int64 v12; // x2
  unsigned int v13; // w8
  unsigned __int64 v15; // x3
  __int64 v16; // x2
  __int64 v17; // x3
  int v18; // w20
  __int64 v19; // x0
  unsigned int v20; // w1
  __int64 v21; // x8
  __int64 v22; // x8
  void *v23; // x0
  const char *v24; // x1
  void *v25; // x0
  int v27; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a1 + 1452) == 1 )
  {
    v6 = (__int64 (*)(void))arch_timer_read_counter;
    if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
      __break(0x8228u);
    v7 = v6();
    v8 = 1000 * v7 / 0x47868C000uLL;
    v9 = (1221679587 * (unsigned __int64)(unsigned int)v8) >> 42;
    v10 = ((unsigned int)((1145324613 * (unsigned __int64)(unsigned int)v8) >> 32) >> 4) - 60 * v9;
    ipc_log_string(
      ucsi_ipc_log,
      "owner: %u type: %u opcode: %u len:%zu (%02u:%02u:%02u.%06u)\n",
      *a2,
      a2[1],
      a2[2],
      a3,
      v9,
      v10,
      v8 - 3600 * v9 - 60 * v10,
      1000 * v7 / 0x4B00uLL - 1000000 * v8);
  }
  else
  {
    ipc_log_string(ucsi_ipc_log, "owner: %u type: %u opcode: %u len:%zu\n", *a2, a2[1], a2[2], a3);
  }
  v12 = (unsigned int)a2[2];
  if ( (_DWORD)v12 == 19 )
  {
    if ( a3 != 24 )
    {
      printk(&unk_75A9, "handle_ucsi_notify", a3, 24);
      goto LABEL_44;
    }
    mutex_lock(a1 + 224);
    if ( *(_DWORD *)(a1 + 1448) )
    {
      if ( *(_QWORD *)(a1 + 8) )
      {
        v18 = a2[3];
        v27 = v18;
        ucsi_log(a1, "notify:", 4, &v27, 4);
        if ( (*(_QWORD *)(a1 + 1368) & 2) != 0 && (v18 & 0xA0000000) != 0 )
          complete(a1 + 96);
        if ( (unsigned __int8)v18 >= 2u )
        {
          v19 = *(_QWORD *)(a1 + 8);
          v20 = (unsigned __int8)v18 >> 1;
          if ( v20 <= *(unsigned __int8 *)(v19 + 36) )
          {
            v21 = *(_QWORD *)(v19 + 48);
            if ( v21 )
            {
              v22 = v21 + 1256LL * (v20 - 1);
              if ( v22 )
              {
                if ( *(_QWORD *)(v22 + 8) )
                  ucsi_connector_change();
              }
            }
          }
        }
        goto LABEL_43;
      }
      v25 = &unk_744D;
    }
    else
    {
      v25 = &unk_7535;
    }
    printk(v25, "handle_ucsi_notify", v16, v17);
LABEL_43:
    mutex_unlock(a1 + 224);
    goto LABEL_44;
  }
  if ( (_DWORD)v12 == 18 )
  {
    if ( a3 != 16 )
    {
      printk(&unk_75A9, "handle_ucsi_write_ack", a3, 16);
      goto LABEL_44;
    }
    v12 = (unsigned int)a2[3];
    if ( !(_DWORD)v12 )
    {
      complete(a1 + 64);
      goto LABEL_44;
    }
    v23 = &unk_7246;
    v24 = "handle_ucsi_write_ack";
LABEL_40:
    printk(v23, v24, v12, v11);
    goto LABEL_44;
  }
  if ( (_DWORD)v12 != 17 )
  {
    v23 = &unk_747C;
    v24 = "ucsi_callback";
    goto LABEL_40;
  }
  v13 = *(unsigned __int16 *)(a1 + 1360);
  if ( v13 - 289 < 0xF0 || v13 == 0 )
    v15 = 544;
  else
    v15 = (unsigned __int64)(v13 < 0x121) << 6;
  if ( v15 < a3 )
  {
    printk(&unk_75A9, "handle_ucsi_read_ack", a3, v15);
    *(_DWORD *)(a1 + 1376) = 0;
    goto LABEL_44;
  }
  memset((void *)(a1 + 272), 0, 0x220u);
  memcpy((void *)(a1 + 272), a2, a3);
  v12 = *(unsigned int *)(a1 + 812);
  if ( (_DWORD)v12 )
  {
    v23 = &unk_7246;
    v24 = "handle_ucsi_read_ack";
    goto LABEL_40;
  }
  *(_DWORD *)(a1 + 1376) = 1;
  complete(a1 + 32);
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return 0;
}
