__int64 __fastcall sde_encoder_get_frame_count(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned int disp_op; // w0
  __int64 v6; // x17
  __int128 v7; // q4
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 v10; // x8
  void *v11; // x0

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_get_frame_count");
    return 0;
  }
  if ( !*(_QWORD *)a1 )
  {
    v11 = &unk_26FCAB;
    goto LABEL_19;
  }
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 8)) == 0 )
  {
    v11 = &unk_234896;
LABEL_19:
    printk(v11, "sde_encoder_get_kms");
    disp_op = 0;
    goto LABEL_6;
  }
  disp_op = sde_kms_get_disp_op(v4, a2);
  if ( disp_op >= 3 )
  {
    __break(0x5512u);
    *(_OWORD *)(v6 + 21536) = v7;
    JUMPOUT(0xE914C);
  }
LABEL_6:
  v8 = *(__int64 (__fastcall **)(_QWORD))(a1 + 8LL * disp_op + 5368);
  if ( !v8 )
  {
    if ( *(_BYTE *)(a1 + 748) != 1 )
      return *(unsigned int *)(a1 + 804);
    v10 = *(_QWORD *)(a1 + 328);
    if ( v10 )
      return *(unsigned int *)(v10 + 988);
    return 0;
  }
  if ( *((_DWORD *)v8 - 1) != -1990503887 )
    __break(0x8228u);
  return v8(a1);
}
