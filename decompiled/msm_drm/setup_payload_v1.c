__int64 __fastcall setup_payload_v1(unsigned int *a1)
{
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x8
  unsigned int v6; // w1
  unsigned int v7; // w8
  __int64 result; // x0
  unsigned __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 v11; // x8
  __int64 (__fastcall *v12)(); // x8

  if ( !a1 )
  {
    v4 = 0;
    LODWORD(v3) = 7;
LABEL_11:
    _drm_err("invalid param cfg %pK ops %d dma_buf %pK\n", a1, v3, (const void *)v4);
    return 4294967274LL;
  }
  v3 = *a1;
  v4 = *((_QWORD *)a1 + 3);
  if ( (unsigned int)v3 > 6 || !v4 )
    goto LABEL_11;
  v5 = a1[2];
  if ( (unsigned int)v5 > 0x18 || (v1_supported[v5] & a1[1]) == 0 )
  {
    _drm_err("check support failed rc %d supported %d\n", 0, 0);
    return 4294967274LL;
  }
  v7 = *(_DWORD *)(v4 + 16);
  v6 = *(_DWORD *)(v4 + 20);
  if ( v6 >= v7 || (v6 & 3) != 0 )
  {
    _drm_err("Buf Overflow index %d max size %d align %x\n", v6, v7, v6 & 3);
    return 4294967274LL;
  }
  if ( (unsigned __int8)*(_QWORD *)(v4 + 24) || !*(_QWORD *)(v4 + 32) )
  {
    _drm_err("iova not aligned to %zx iova %llx kva %pK", 0x100u, *(_QWORD *)(v4 + 24), *(const void **)(v4 + 32));
    return 4294967274LL;
  }
  v9 = *(unsigned int *)(v4 + 40);
  if ( ((v9 >> v3) & 1) == 0 )
  {
    _drm_err("invalid op %x allowed %x\n", (unsigned int)v3, (unsigned int)v9);
    return 4294967274LL;
  }
  v10 = validate_dma_op_params[v3];
  if ( *((_DWORD *)v10 - 1) != -1839634494 )
    __break(0x8228u);
  result = v10();
  if ( !(_DWORD)result )
  {
    v11 = *a1;
    if ( (unsigned int)v11 > 6 )
    {
      __break(0x5512u);
      __asm { STGP            X17, X3, [X27,#-0xF0]! }
      return kick_off_v1();
    }
    else
    {
      v12 = write_dma_op_params[v11];
      if ( *((_DWORD *)v12 - 1) != -1839634494 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(unsigned int *))v12)(a1);
    }
  }
  return result;
}
