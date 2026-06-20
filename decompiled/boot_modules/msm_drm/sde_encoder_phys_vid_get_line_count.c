__int64 __fastcall sde_encoder_phys_vid_get_line_count(__int64 a1)
{
  unsigned int disp_op; // w0
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x9
  __int64 v5; // x0

  if ( !a1 )
    return 4294967274LL;
  disp_op = sde_encoder_get_disp_op(*(_QWORD *)a1);
  if ( *(_DWORD *)(a1 + 664) == 3 )
    return 4294967274LL;
  v3 = *(_QWORD *)(a1 + 424);
  if ( !v3 )
    return 4294967274LL;
  if ( disp_op >= 3 )
  {
    __break(0x5512u);
    JUMPOUT(0xF9570);
  }
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8LL * disp_op + 272);
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 424);
    if ( *((_DWORD *)v4 - 1) != 1550245701 )
      __break(0x8229u);
    return v4(v5);
  }
  else if ( disp_op == 1 )
  {
    return 0;
  }
  else
  {
    return 4294967274LL;
  }
}
