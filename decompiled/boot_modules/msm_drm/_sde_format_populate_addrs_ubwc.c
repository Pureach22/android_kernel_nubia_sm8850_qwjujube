__int64 __fastcall sde_format_populate_addrs_ubwc(__int64 a1, __int64 a2, _DWORD *a3)
{
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w8
  int v8; // w10
  int v9; // w11
  unsigned int v10; // w8

  if ( a1 )
  {
    v4 = msm_framebuffer_iova(a2, a1, 0);
    if ( v4 )
      goto LABEL_3;
LABEL_8:
    _drm_err("failed to retrieve base addr\n");
    return (unsigned int)-14;
  }
  v4 = ((__int64 (__fastcall *)(__int64, _QWORD))msm_framebuffer_phys)(a2, 0);
  if ( !v4 )
    goto LABEL_8;
LABEL_3:
  v5 = *(_QWORD *)a3;
  if ( *(_DWORD *)(*(_QWORD *)a3 + 28LL) == 2 )
  {
    v6 = (*(_QWORD *)(v5 + 32) >> 2) & 1LL;
    if ( (*(_QWORD *)(v5 + 32) & 1) != 0 )
      goto LABEL_5;
  }
  else
  {
    LODWORD(v6) = 0;
    if ( (*(_QWORD *)(v5 + 32) & 1) != 0 )
    {
LABEL_5:
      v7 = a3[12] + v4;
      v8 = v7 + a3[10];
      v9 = v8 + a3[13];
      a3[6] = v7;
      a3[7] = v9;
      v10 = 0;
      if ( (_DWORD)v6 )
      {
        a3[8] = v4;
        a3[9] = v8;
      }
      return v10;
    }
  }
  v10 = 0;
  *((_QWORD *)a3 + 3) = (unsigned int)(a3[12] + v4);
  if ( (_DWORD)v6 )
  {
    v10 = 0;
    a3[8] = v4;
    a3[9] = 0;
  }
  return v10;
}
