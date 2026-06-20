__int64 __fastcall audio_prm_set_lpass_clk_cfg(int *a1, char a2)
{
  __int64 v3; // x0
  int v4; // w13
  int v5; // w10
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w11
  unsigned __int64 v9; // t2
  int v10; // w11
  int v11; // w8
  __int64 v12; // x20
  unsigned int v13; // w19

  if ( a2 )
  {
    v3 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 76);
    if ( v3 )
    {
      *(_DWORD *)v3 = 19552;
      *(_WORD *)(v3 + 4) = 770;
      v4 = dword_6D64;
      v5 = a1[2];
      v6 = *a1;
      v7 = a1[1];
      *(_QWORD *)(v3 + 8) = 0x200000007LL;
      *(_QWORD *)(v3 + 16) = 0x100100F00000000LL;
      if ( v4 && (HIDWORD(v9) = v6 - 780, LODWORD(v9) = v6 - 780, v8 = v9 >> 1, v8 < 6) && ((0x39u >> v8) & 1) != 0 )
        v10 = 2;
      else
        v10 = a1[3];
      *(_DWORD *)(v3 + 64) = v7;
      *(_DWORD *)(v3 + 68) = v5;
      *(_QWORD *)(v3 + 24) = 0;
      *(_QWORD *)(v3 + 32) = 0x2400000000LL;
      *(_DWORD *)(v3 + 72) = v10;
      *(_QWORD *)(v3 + 40) = 0x800102C00000002LL;
      *(_QWORD *)(v3 + 48) = 20;
      *(_DWORD *)(v3 + 56) = 1;
      *(_DWORD *)(v3 + 60) = v6;
      goto LABEL_11;
    }
    return (unsigned int)-12;
  }
  v3 = _kmalloc_cache_noprof(init_wait_entry, 3520, 64);
  if ( !v3 )
    return (unsigned int)-12;
  *(_DWORD *)v3 = 16480;
  *(_WORD *)(v3 + 4) = 770;
  *(_QWORD *)(v3 + 8) = 0x200000007LL;
  *(_DWORD *)(v3 + 16) = 0;
  *(_DWORD *)(v3 + 20) = 16781328;
  *(_QWORD *)(v3 + 24) = 0;
  *(_QWORD *)(v3 + 32) = 0x1800000000LL;
  *(_QWORD *)(v3 + 40) = 0x800102C00000002LL;
  *(_QWORD *)(v3 + 48) = 8;
  v11 = *a1;
  *(_DWORD *)(v3 + 56) = 1;
  *(_DWORD *)(v3 + 60) = v11;
LABEL_11:
  v12 = v3;
  v13 = prm_gpr_send_pkt(v3);
  kfree(v12);
  return v13;
}
