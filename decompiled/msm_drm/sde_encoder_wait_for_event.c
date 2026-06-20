__int64 __fastcall sde_encoder_wait_for_event(__int64 a1, unsigned int a2)
{
  __int64 v4; // x8
  unsigned int disp_op; // w0
  _DWORD *v6; // x8
  __int64 result; // x0
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x21
  __int64 v10; // x24
  __int64 (__fastcall *v11)(_QWORD); // x28
  unsigned int v12; // w0
  void *v13; // x0
  unsigned int v14; // w22
  char s[8]; // [xsp+18h] [xbp-28h] BYREF
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  *(_QWORD *)s = 0;
  v16 = 0;
  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_wait_for_event");
    result = 4294967274LL;
    goto LABEL_13;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d \n", *(_DWORD *)(a1 + 24));
  if ( *(_QWORD *)a1 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v4 && *(_QWORD *)(v4 + 8) )
    {
      disp_op = sde_kms_get_disp_op();
      if ( disp_op >= 3 )
LABEL_32:
        __break(0x5512u);
      goto LABEL_8;
    }
    v13 = &unk_234896;
  }
  else
  {
    v13 = &unk_26FCAB;
  }
  printk(v13, "sde_encoder_get_kms");
  disp_op = 0;
LABEL_8:
  v6 = *(_DWORD **)(a1 + 8LL * disp_op + 5248);
  if ( v6 )
  {
    if ( *(v6 - 1) != -326503038 )
      __break(0x8228u);
    if ( ((int (__fastcall *)(__int64, _QWORD))v6)(a1, a2) <= 0 )
    {
      printk(&unk_2197DF, "sde_encoder_wait_for_event");
      result = 4294967186LL;
      goto LABEL_13;
    }
  }
  else
  {
    v8 = *(unsigned int *)(a1 + 196);
    if ( (_DWORD)v8 )
    {
      v9 = 0;
      _ReadStatusReg(SP_EL0);
      do
      {
        if ( v9 == 4 )
          goto LABEL_32;
        if ( a2 >= 4 )
        {
          printk(&unk_22ACA3, "sde_encoder_wait_for_event");
          result = 4294967274LL;
          goto LABEL_13;
        }
        v10 = *(_QWORD *)(a1 + 200 + 8 * v9);
        if ( v10 )
        {
          v11 = *(__int64 (__fastcall **)(_QWORD))((char *)*(&off_29D320 + a2) + v10);
          if ( v11 )
          {
            snprintf(s, 0x20u, "wait_completion_event_%d", a2);
            if ( *((_DWORD *)v11 - 1) != -451714968 )
              __break(0x823Cu);
            v12 = v11(v10);
            if ( v12 )
            {
              v14 = v12;
              printk(&unk_26C84C, "sde_encoder_wait_for_event");
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "sde_encoder_wait_for_event",
                8660,
                -1,
                *(_DWORD *)(a1 + 24),
                *(_DWORD *)(a1 + 640),
                a2,
                v9,
                v14);
              result = v14;
              goto LABEL_13;
            }
            v8 = *(unsigned int *)(a1 + 196);
          }
        }
        ++v9;
      }
      while ( v9 < v8 );
    }
  }
  result = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
