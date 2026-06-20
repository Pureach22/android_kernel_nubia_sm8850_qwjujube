__int64 __fastcall set_lm_gc_feature(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int disp_op; // w0
  void (__fastcall *v5)(__int64, __int64); // x9
  __int64 v6; // x0
  __int64 v8; // x0

  disp_op = sde_crtc_get_disp_op(a3);
  if ( disp_op >= 3 )
  {
    __break(0x5512u);
    v8 = MEMORY[0x25256A0]();
    return set_ltm_init_feature(v8);
  }
  else
  {
    v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a2 + 32) + 8LL * disp_op + 160);
    if ( v5 )
    {
      v6 = *(_QWORD *)(a2 + 32);
      if ( *((_DWORD *)v5 - 1) != -1821694127 )
        __break(0x8229u);
      v5(v6, a2);
      return 0;
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
}
