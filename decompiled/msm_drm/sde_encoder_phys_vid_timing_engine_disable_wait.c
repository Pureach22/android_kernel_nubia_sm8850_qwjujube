__int64 __fastcall sde_encoder_phys_vid_timing_engine_disable_wait(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x20
  int v4; // w8
  __int64 v5; // x0
  void (*v6)(void); // x8
  __int64 v7; // x0
  void (*v8)(void); // x8
  void (*v9)(void); // x8
  int v10; // w4
  __int64 result; // x0
  char v12; // [xsp+0h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  LODWORD(v2) = sde_encoder_get_disp_op(*(_QWORD *)a1);
  v3 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 824));
  if ( !*(_QWORD *)a1 )
  {
LABEL_25:
    if ( (unsigned int)v2 <= 2 )
    {
      v2 = (unsigned int)v2;
      goto LABEL_27;
    }
LABEL_35:
    __break(0x5512u);
  }
  if ( a1 && (*(_BYTE *)(*(_QWORD *)a1 + 4936LL) & 1) != 0 )
  {
    v4 = *(_DWORD *)(a1 + 664);
    if ( v4 == 2 )
    {
      v7 = *(_QWORD *)(a1 + 416);
      if ( v7 )
      {
        if ( (unsigned int)v2 > 2 )
          goto LABEL_35;
        v6 = *(void (**)(void))(v7 + 8LL * (unsigned int)v2 + 1664);
        if ( v6 )
          goto LABEL_13;
      }
    }
    else if ( v4 == 1 )
    {
      v5 = *(_QWORD *)(a1 + 416);
      if ( v5 )
      {
        if ( (unsigned int)v2 >= 3 )
          goto LABEL_35;
        v6 = *(void (**)(void))(v5 + 8LL * (unsigned int)v2 + 1664);
        if ( v6 )
        {
LABEL_13:
          if ( *((_DWORD *)v6 - 1) != 128872864 )
            __break(0x8228u);
          v6();
        }
      }
    }
  }
  if ( !*(_QWORD *)a1 || !a1 || (*(_BYTE *)(*(_QWORD *)a1 + 4936LL) & 1) == 0 || *(_DWORD *)(a1 + 664) != 2 )
    goto LABEL_25;
  if ( (unsigned int)v2 > 2 )
    goto LABEL_35;
  v2 = (unsigned int)v2;
  v8 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8LL * (unsigned int)v2 + 1280);
  if ( v8 )
  {
    if ( *((_DWORD *)v8 - 1) != -1913620264 )
      __break(0x8228u);
    v8();
  }
LABEL_27:
  v9 = *(void (**)(void))(*(_QWORD *)(a1 + 424) + 8 * v2 + 200);
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != -2009615442 )
      __break(0x8228u);
    v9();
  }
  if ( *(_QWORD *)a1 )
    v10 = *(_DWORD *)(*(_QWORD *)a1 + 24LL);
  else
    v10 = -1;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_phys_vid_timing_engine_disable_wait",
    2351,
    -1,
    v10,
    13107,
    60333,
    -1059143953,
    v12);
  result = raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 824), v3);
  _ReadStatusReg(SP_EL0);
  return result;
}
