__int64 __fastcall gh_panic_notifier_notify(__int64 a1)
{
  _BYTE *v1; // x21
  __int64 v3; // x0
  __int64 v4; // x0
  int v5; // w0
  int v6; // w22
  __int64 v7; // x0
  unsigned int v8; // w19
  _QWORD *v9; // x24
  __int64 v10; // x20
  __int64 v11; // x8
  __int64 v12; // x9
  _DWORD *v13; // x9
  __int64 v14; // x25
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x9
  __int64 (*v18)(void); // x9
  int v19; // w0
  void (__fastcall *v20)(_QWORD); // x9
  void (__fastcall *v21)(_QWORD); // x9
  void (__fastcall *v22)(_QWORD); // x9
  int v23; // w0
  unsigned __int16 v25; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_BYTE **)(a1 - 104);
  if ( v1 )
  {
    v3 = *(unsigned int *)(a1 - 84);
    v25 = 0;
    if ( !(unsigned int)ghd_rm_get_vmid(v3, &v25) )
    {
      v4 = *(_QWORD *)(a1 - 72);
      v26[0] = 1;
      v5 = gh_dbl_send(v4, v26, 0x100000000LL);
      if ( v5 )
      {
        printk_deferred("failed to raise virq to the sender %d\n", v5);
      }
      else
      {
        v6 = 20;
        while ( 1 )
        {
          LOBYTE(v26[0]) = 0;
          v7 = irq_to_desc(0);
          if ( nr_irqs )
          {
            v8 = 0;
            do
            {
              if ( v7 )
              {
                v9 = *(_QWORD **)(v7 + 72);
                if ( v9 )
                {
                  v10 = v7 + 48;
                  v11 = v7 + 48;
                  while ( 1 )
                  {
                    v12 = *(_QWORD *)(v11 + 24);
                    if ( !v12 )
                    {
                      __break(0x800u);
                      goto LABEL_8;
                    }
                    v13 = *(_DWORD **)(v12 + 200);
                    if ( v13 )
                      break;
                    v11 = *(_QWORD *)(v11 + 40);
                    if ( !v11 )
                      goto LABEL_8;
                  }
                  if ( v11 )
                  {
                    v14 = v7;
                    if ( *(v13 - 1) != 1890384367 )
                      __break(0x8229u);
                    if ( !((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD *))v13)(v11, 0, v26)
                      && LOBYTE(v26[0]) == 1 )
                    {
                      v15 = v14;
                      v16 = v10;
                      while ( 1 )
                      {
                        v17 = *(_QWORD *)(v16 + 24);
                        if ( !v17 )
                        {
                          __break(0x800u);
LABEL_30:
                          if ( (*(_BYTE *)(*(_QWORD *)(v15 + 64) + 2LL) & 4) != 0 )
                          {
                            v20 = (void (__fastcall *)(_QWORD))v9[9];
                            if ( v20 )
                            {
                              if ( *((_DWORD *)v20 - 1) != 270158662 )
                                __break(0x8229u);
                              v20(v10);
                              v15 = v14;
                            }
                          }
                          goto LABEL_35;
                        }
                        v18 = *(__int64 (**)(void))(v17 + 208);
                        if ( v18 )
                          break;
                        v16 = *(_QWORD *)(v16 + 40);
                        if ( !v16 )
                          goto LABEL_30;
                      }
                      if ( !v16 )
                        goto LABEL_30;
                      if ( *((_DWORD *)v18 - 1) != 835493110 )
                        __break(0x8229u);
                      v19 = v18();
                      v15 = v14;
                      if ( v19 )
                        goto LABEL_30;
LABEL_35:
                      v21 = (void (__fastcall *)(_QWORD))v9[6];
                      if ( v21 )
                      {
                        if ( *((_DWORD *)v21 - 1) != 270158662 )
                          __break(0x8229u);
                        v21(v10);
                        v15 = v14;
                      }
                      v22 = (void (__fastcall *)(_QWORD))v9[4];
                      if ( v22 && (*(_BYTE *)(*(_QWORD *)(v15 + 64) + 2LL) & 1) == 0 )
                      {
                        if ( *((_DWORD *)v22 - 1) != 270158662 )
                          __break(0x8229u);
                        v22(v10);
                      }
                    }
                  }
                }
              }
LABEL_8:
              v7 = irq_to_desc(++v8);
            }
            while ( v8 < nr_irqs );
          }
          v23 = gh_poll_vcpu_run(v25);
          if ( v23 )
            break;
          if ( (*v1 & 1) == 0 )
          {
            if ( --v6 )
              continue;
          }
          if ( (*v1 & 1) != 0 )
            goto LABEL_49;
          goto LABEL_52;
        }
        printk_deferred("Failed poll vcpu run %d\n", v23);
        if ( (*v1 & 1) != 0 )
          goto LABEL_49;
LABEL_52:
        printk_deferred("Notify the panic to VM fail\n");
      }
    }
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return 0;
}
