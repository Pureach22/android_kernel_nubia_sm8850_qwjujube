__int64 __fastcall sysstats_pre_doit(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w8
  void *v4; // x3
  _DWORD *v5; // x8

  v3 = *(unsigned __int8 *)(a1 + 36);
  if ( v3 == 5 )
  {
LABEL_4:
    v4 = &sysstats_cmd_get_policy;
    goto LABEL_6;
  }
  if ( v3 != 3 )
  {
    if ( v3 != 1 )
      return 4294967274LL;
    goto LABEL_4;
  }
  v4 = nullptr;
LABEL_6:
  v5 = *(_DWORD **)(a3 + 16);
  if ( *v5 < 0x14u )
    return 4294967274LL;
  return _nla_validate(v5 + 5, (unsigned int)(*v5 - 20), 3, v4, 0, *(_QWORD *)(a3 + 64));
}
