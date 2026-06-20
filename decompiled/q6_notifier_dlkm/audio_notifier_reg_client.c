__int64 __fastcall audio_notifier_reg_client(__int64 a1)
{
  __int64 v1; // x24
  int v2; // w8
  unsigned int v3; // w19
  __int64 result; // x0
  char *v6; // x25
  __int64 v8; // x9
  int v9; // w9
  __int64 v10; // x22
  __int64 v11; // x28
  char *v12; // x23
  char *v13; // x26
  __int64 v14; // x1
  _DWORD **v15; // x0
  __int64 v16; // x1
  _DWORD *v17; // x8
  __int64 v18; // x25
  __int64 v19; // x8
  unsigned __int64 v20; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(unsigned int *)(a1 + 48);
  if ( (_DWORD)v1 == 1 )
    v2 = 0;
  else
    v2 = -2;
  if ( (_DWORD)v1 )
    v3 = v2;
  else
    v3 = 1;
  if ( (v3 & 0x80000000) != 0 )
  {
    if ( (unsigned int)__ratelimit(&audio_notifier_reg_client__rs, "audio_notifier_reg_client") )
      printk(&unk_844F, "audio_notifier_reg_client");
    goto LABEL_47;
  }
  result = 0;
  v6 = service_data;
  while ( 1 )
  {
    if ( (v3 | (unsigned int)v1) >= 2 )
      goto LABEL_50;
    v8 = 1152LL * v3;
    if ( ((v8 + 576 * v1) | 0x18uLL) > 0x900 )
      goto LABEL_49;
    v9 = *(_DWORD *)&v6[576 * (unsigned int)v1 + 24 + v8];
    if ( v9 == -1 )
      break;
    if ( (v9 & 0x80000000) == 0 && *(_DWORD *)(a1 + 44) == -2 )
    {
      v10 = *(unsigned int *)(a1 + 48);
      if ( (unsigned int)v10 > 1 )
        goto LABEL_50;
      v11 = 576LL * (unsigned int)v10 + 1152LL * v3;
      if ( (v11 | 0x30uLL) > 0x900 )
      {
LABEL_49:
        __break(1u);
LABEL_50:
        __break(0x5512u);
      }
      v12 = &v6[v11];
      v13 = v6;
      if ( !*(_DWORD *)&v6[v11 + 48] )
      {
        v18 = adsp_private;
        v19 = *(_QWORD *)(adsp_private + 168);
        if ( v19 )
        {
          if ( (v3 & 1) != 0 )
          {
            v6 = v13;
            v20 = audio_pdr_service_register(
                    *(unsigned int *)&v13[576 * (unsigned int)v10 + 1172],
                    *(_QWORD *)&v13[576 * (unsigned int)v10 + 1192]);
            if ( !v20 )
              goto LABEL_33;
          }
          else
          {
            if ( ((576 * v10) | 0x28uLL) > 0x900 )
              goto LABEL_49;
            v6 = v13;
            v20 = audio_ssr_register(*(_QWORD *)(*(_QWORD *)v19 + 24LL), *(_QWORD *)&v13[576 * (unsigned int)v10 + 40]);
            if ( !v20 )
            {
LABEL_33:
              if ( (unsigned int)__ratelimit(&audio_notifier_reg_service__rs_34, "audio_notifier_reg_service") )
                printk(&unk_82EB, "audio_notifier_reg_service");
              if ( (unsigned int)__ratelimit(
                                   &audio_notifier_reg_client_service__rs_31,
                                   "audio_notifier_reg_client_service") )
                printk(&unk_81B3, "audio_notifier_reg_client_service");
              if ( (unsigned int)__ratelimit(&audio_notifier_reg_client__rs_28, "audio_notifier_reg_client") )
                printk(&unk_8007, "audio_notifier_reg_client");
              result = 4294967274LL;
              goto LABEL_10;
            }
          }
          if ( v20 >= 0xFFFFFFFFFFFFF001LL )
            goto LABEL_33;
          if ( (v11 | 0x18uLL) > 0x900 )
            goto LABEL_49;
          *((_DWORD *)v12 + 6) = 0;
          if ( (v11 | 0x20uLL) > 0x900 )
            goto LABEL_49;
          *((_QWORD *)v12 + 4) = v20;
          printk(&unk_83B3, "audio_notifier_reg_service");
        }
        else if ( (unsigned int)__ratelimit(&audio_notifier_reg_service__rs, "audio_notifier_reg_service") )
        {
          dev_err(v18 + 16, " %s: Private data get failed\n", "audio_notifier_reg_service");
        }
      }
      v14 = *(_QWORD *)(a1 + 16);
      *(_DWORD *)(a1 + 44) = v3;
      srcu_notifier_chain_register(v12 + 56, v14);
      ++*((_DWORD *)v12 + 12);
      if ( *(_DWORD *)(a1 + 44) == 1 )
      {
        if ( (v11 | 0x18uLL) > 0x900 )
          goto LABEL_49;
        v15 = *(_DWORD ***)(a1 + 16);
        v16 = *((int *)v12 + 6);
        v17 = *v15;
        if ( *(*v15 - 1) != -720209349 )
          __break(0x8228u);
        ((void (__fastcall *)(_DWORD **, __int64))v17)(v15, v16);
      }
      result = 0;
      v6 = v13;
    }
LABEL_10:
    if ( (int)v3-- <= 0 )
      goto LABEL_48;
  }
  if ( (unsigned int)__ratelimit(&audio_notifier_reg_client__rs_26, "audio_notifier_reg_client") )
    printk(&unk_80C0, "audio_notifier_reg_client");
LABEL_47:
  result = 4294967274LL;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
