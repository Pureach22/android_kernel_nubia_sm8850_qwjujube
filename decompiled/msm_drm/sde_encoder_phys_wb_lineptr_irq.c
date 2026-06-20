size_t __fastcall sde_encoder_phys_wb_lineptr_irq(size_t result)
{
  size_t v1; // x19
  size_t disp_op; // x0
  __int64 (*v3)(void); // x8
  unsigned int v4; // w22
  unsigned int v11; // w10
  __int64 (__fastcall *v12)(__int64, size_t, __int64); // x8
  __int64 v13; // x0
  int v14; // w21
  int v15; // w4
  __int64 v16; // x9
  int v17; // w5

  if ( result )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 2944) )
    {
      _ReadStatusReg(SP_EL0);
      disp_op = sde_encoder_get_disp_op(*(_QWORD *)result);
      v3 = *(__int64 (**)(void))(v1 + 392);
      v4 = disp_op;
      if ( v3 )
      {
        LODWORD(v3) = *(_DWORD *)(v1 + 880);
        while ( (_DWORD)v3 )
        {
          _X12 = (unsigned int *)(v1 + 880);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v11 = __ldxr(_X12);
            if ( v11 != (unsigned int)v3 )
              break;
            if ( !__stlxr((_DWORD)v3 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v11 == (_DWORD)v3;
          LODWORD(v3) = v11;
          if ( _ZF )
          {
            v12 = *(__int64 (__fastcall **)(__int64, size_t, __int64))(v1 + 392);
            v13 = *(_QWORD *)v1;
            v14 = 16;
            if ( *((_DWORD *)v12 - 1) != -570463643 )
              __break(0x8228u);
            disp_op = v12(v13, v1, 16);
            if ( v4 >= 3 )
              goto LABEL_24;
            goto LABEL_16;
          }
        }
      }
      v14 = 0;
      if ( (unsigned int)disp_op < 3 )
      {
LABEL_16:
        v3 = *(__int64 (**)(void))(*(_QWORD *)(v1 + 2680) + 8LL * v4 + 472);
        if ( v3 )
        {
          if ( *((_DWORD *)v3 - 1) != -403367322 )
            __break(0x8228u);
          LOBYTE(v3) = v3();
        }
        disp_op = sde_dbg_base_evtlog;
        if ( *(_QWORD *)v1 )
        {
          v15 = *(_DWORD *)(*(_QWORD *)v1 + 24LL);
          v16 = *(_QWORD *)(v1 + 2864);
          if ( !v16 )
          {
LABEL_26:
            v17 = -1;
            return sde_evtlog_log(
                     disp_op,
                     "sde_encoder_phys_wb_lineptr_irq",
                     2132,
                     2,
                     v15,
                     v17,
                     v14,
                     *(_DWORD *)(v1 + 2944),
                     (char)v3);
          }
LABEL_22:
          v17 = *(_DWORD *)(v16 + 12) - 1;
          return sde_evtlog_log(
                   disp_op,
                   "sde_encoder_phys_wb_lineptr_irq",
                   2132,
                   2,
                   v15,
                   v17,
                   v14,
                   *(_DWORD *)(v1 + 2944),
                   (char)v3);
        }
      }
      else
      {
LABEL_24:
        __break(0x5512u);
      }
      v15 = -1;
      v16 = *(_QWORD *)(v1 + 2864);
      if ( !v16 )
        goto LABEL_26;
      goto LABEL_22;
    }
  }
  return result;
}
