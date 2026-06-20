__int64 __fastcall sde_encoder_get_avr_status(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int disp_op; // w0
  __int64 v6; // x9
  unsigned int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned int (__fastcall *v10)(_QWORD); // x9
  void *v12; // x0

  if ( !a1 )
    return (unsigned int)-22;
  if ( !*(_QWORD *)a1 )
  {
    v12 = &unk_26FCAB;
    goto LABEL_23;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v12 = &unk_234896;
LABEL_23:
    printk(v12, "sde_encoder_get_kms");
    disp_op = 0;
    goto LABEL_6;
  }
  disp_op = sde_kms_get_disp_op(v4, a2);
LABEL_6:
  v6 = *(_QWORD *)(a1 + 328);
  v7 = -61;
  if ( !v6 || *(_DWORD *)(a1 + 648) != 1 )
    return v7;
  v8 = *(_QWORD *)(v6 + 8);
  if ( !v8 || !*(_DWORD *)(v8 + 4676) )
    return (unsigned int)-61;
  if ( disp_op < 3 )
  {
    v9 = *(_QWORD *)(v6 + 424);
    v10 = *(unsigned int (__fastcall **)(_QWORD))(v9 + 8LL * disp_op + 824);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 1550245701 )
        __break(0x8229u);
      return v10(v9);
    }
    else if ( disp_op == 1 )
    {
      return 0;
    }
    else
    {
      return (unsigned int)-95;
    }
  }
  __break(0x5512u);
  return sde_encoder_update_periph_flush();
}
