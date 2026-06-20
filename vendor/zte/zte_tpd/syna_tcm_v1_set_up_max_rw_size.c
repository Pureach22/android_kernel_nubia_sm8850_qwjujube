__int64 __fastcall syna_tcm_v1_set_up_max_rw_size(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w8
  unsigned int v5; // w8
  void *v6; // x0

  if ( !a1 )
  {
    v6 = unk_3365A;
LABEL_19:
    printk(v6, "syna_tcm_v1_set_up_max_rw_size", a3);
    return (unsigned int)-241;
  }
  if ( *(_BYTE *)(a1 + 128) != 1 )
  {
    v6 = unk_36BFC;
    goto LABEL_19;
  }
  v3 = *(unsigned __int16 *)(a1 + 150);
  v4 = *(_DWORD *)(a1 + 64);
  if ( v3 >= a2 )
  {
    if ( v3 >= v4 )
      v3 = *(_DWORD *)(a1 + 64);
    if ( v3 >= a2 )
      v3 = a2;
    if ( !v4 )
      v3 = a2;
    if ( *(_DWORD *)(a1 + 56) != v3 )
      *(_DWORD *)(a1 + 56) = v3;
  }
  if ( v4 && *(_DWORD *)(a1 + 68) < (unsigned int)a3 )
    LODWORD(a3) = *(_DWORD *)(a1 + 68);
  v5 = 0;
  if ( *(_DWORD *)(a1 + 60) != (_DWORD)a3 )
    *(_DWORD *)(a1 + 60) = a3;
  return v5;
}
