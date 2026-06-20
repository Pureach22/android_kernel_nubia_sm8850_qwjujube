__int64 __fastcall syna_tcm_v1_check_max_rw_size(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w8
  unsigned int v5; // w10
  unsigned int v6; // w8
  void *v8; // x0

  if ( !a1 )
  {
    v8 = &unk_3365A;
LABEL_18:
    printk(v8, "syna_tcm_v1_check_max_rw_size", a3);
    return 4294967055LL;
  }
  if ( *(_BYTE *)(a1 + 128) != 1 )
  {
    v8 = &unk_36BFC;
    goto LABEL_18;
  }
  v3 = *(unsigned __int16 *)(a1 + 150);
  if ( !*(_WORD *)(a1 + 150) )
  {
    v8 = &unk_371CB;
    goto LABEL_18;
  }
  v4 = *(_DWORD *)(a1 + 64);
  if ( v3 >= v4 )
    v5 = *(_DWORD *)(a1 + 64);
  else
    v5 = *(unsigned __int16 *)(a1 + 150);
  if ( v4 )
    v3 = v5;
  if ( *(_DWORD *)(a1 + 56) != v3 )
    *(_DWORD *)(a1 + 56) = v3;
  if ( v4 )
  {
    v6 = *(_DWORD *)(a1 + 68);
    if ( *(_DWORD *)(a1 + 60) > v6 )
      *(_DWORD *)(a1 + 60) = v6;
  }
  return 0;
}
